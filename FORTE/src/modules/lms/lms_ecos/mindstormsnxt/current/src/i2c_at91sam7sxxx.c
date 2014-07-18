//==========================================================================
//
//      i2c_at91sam7sxxx.c
//
//      I2C driver for LPC2xxx
//
//==========================================================================
// ####ECOSGPLCOPYRIGHTBEGIN####                                            
// -------------------------------------------                              
// This file is part of eCos, the Embedded Configurable Operating System.   
// Copyright (C) 2008 Free Software Foundation, Inc.                        
//
// eCos is free software; you can redistribute it and/or modify it under    
// the terms of the GNU General Public License as published by the Free     
// Software Foundation; either version 2 or (at your option) any later      
// version.                                                                 
//
// eCos is distributed in the hope that it will be useful, but WITHOUT      
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or    
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    
// for more details.                                                        
//
// You should have received a copy of the GNU General Public License        
// along with eCos; if not, write to the Free Software Foundation, Inc.,    
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.            
//
// As a special exception, if other files instantiate templates or use      
// macros or inline functions from this file, or you compile this file      
// and link it with other works to produce a work based on this file,       
// this file does not by itself cause the resulting work to be covered by   
// the GNU General Public License. However the source code for this file    
// must still be made available in accordance with section (3) of the GNU   
// General Public License v2.                                               
//
// This exception does not invalidate any other reasons why a work based    
// on this file might be covered by the GNU General Public License.         
// -------------------------------------------                              
// ####ECOSGPLCOPYRIGHTEND####                                              
//==========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):    Hans Rosenfeld <rosenfeld@grumpf.hope-2000.org>
// Contributors: Uwe Kindler <uwe_kindler@web.de>
// Date:         2007-07-12
// Purpose:      
// Description:  
//              
//####DESCRIPTIONEND####
//
//==========================================================================


//==========================================================================
//                                 INCLUDES
//==========================================================================



#include <pkgconf/system.h>
#include <cyg/hal/devs_i2c_arm_at91sam7sxxx.h>
#include <cyg/hal/i2c_at91sam7sxxx.h>

//#ifdef CYGHWR_HAL_ARM_AT91SAAM7SXXX_I2C_SUPP

#include <cyg/infra/cyg_type.h>
#include <cyg/infra/cyg_ass.h>

#include <cyg/hal/hal_arch.h>
#include <cyg/hal/hal_io.h>
#include <cyg/hal/hal_intr.h>
#include <cyg/hal/drv_api.h>

#include <stdio.h>


//
// According to the Users Manual the LPC2xxx I2C module is very
// similar to the I2C module of the Philips 8xC552/556 controllers. I
// guess it is used in other Philips/NXP controllers, too. Using these
// macros should make it easier to split off the common parts of the
// driver once it's necessary.
//
// Optimize for the case of a single bus device, while still allowing
// multiple devices.
//
//#ifndef CYGHWR_DEVS_I2C_ARM_AT91SAM7SXXX_MULTIPLE_BUSES

# define    I2C_BASE(_extra_)       (cyg_uint32*)AT91_TWI //(cyg_uint8*)AT91_TWI
# define    I2C_ISRVEC(_extra_)     CYGNUM_HAL_INTERRUPT_TWI 	
# define    I2C_ISRPRI(_extra_)     CYGNUM_HAL_ARM_AT91SAM7SXXX_I2C_INT_PRIO
# define    I2C_CLK(_extra_)        CYGNUM_HAL_ARM_AT91_CLOCK_SPEED		//cpu_clk
# define    I2C_BUS_FREQ(_extra_)   CYGNUM_HAL_ARM_AT91SAM7SXXX_I2C_BUS_FREQ


//only for mastermode...
#define I2C_CR(_extra_) (I2C_BASE(_extra_) + 0x0000)	//Control Register
#define I2C_MMR(_extra_) (I2C_BASE(_extra_) + 0x0004/4)	//Master Mode Register
#define I2C_IADR(_extra_) (I2C_BASE(_extra_) + 0x000C/4)	//Internal Adress Register
#define I2C_CWGR(_extra_) (I2C_BASE(_extra_) + 0x0010/4)	//Clock Waveform Generator Register
#define I2C_SR(_extra_) (I2C_BASE(_extra_) + 0x0020/4)	//Status Register
#define I2C_IER(_extra_) (I2C_BASE(_extra_) + 0x0024/4)	//Interrupt Enable Register
#define I2C_IDR(_extra_) (I2C_BASE(_extra_) + 0x0028/4)	//Interrupt Disable Register
#define I2C_IMR(_extra_) (I2C_BASE(_extra_) + 0x002C/4)	//Interrupt Mask Register
#define I2C_RHR(_extra_) (I2C_BASE(_extra_) + 0x0030/4)	//Receive Holding Register
#define I2C_THR(_extra_)(I2C_BASE(_extra_) + 0x0034/4)	//Transmit Holding Register

#define I2C_R8(r, x)    HAL_READ_UINT8  ((r), (x))
#define I2C_W8(r, x)    HAL_WRITE_UINT8 ((r), (x))
#define I2C_R16(r, x)   HAL_READ_UINT16 ((r), (x))
#define I2C_W16(r, x)   HAL_WRITE_UINT16 ((r), (x))
#define I2C_R32(r, x)		HAL_READ_UINT32  ((r), (x))
#define I2C_W32(r, x)		HAL_WRITE_UINT32 ((r), (x))

#define CR_START (1<<0)
#define CR_STOP (1<<1)
#define CR_MSEN (1<<2)
#define CR_MSDIS (1<<3)
#define CR_SWRST (1<<7)

#define MMR_MREAD (1<<12)
#define MMR_MWRITE (0<<12)

// the following defines are for SR,IER,IDR,IMR
#define MASK_TXCOMP (1<<0)
#define MASK_RXRDY (1<<1)
#define MASK_TXRDY (1<<2)
#define MASK_NACK (1<<8)


#define I2C_FLAG_FINISH  1       // transfer finished                       
#define I2C_FLAG_ACT     2       // bus still active, no STOP condition send
#define I2C_FLAG_NAK	 4	 // nak

#define I2C_FLAG_ERROR  (1<<31)  // one of the following errors occured:    
#define I2C_FLAG_ADDR   (1<<30)  // - address was not ACKed                 
#define I2C_FLAG_DATA   (1<<29)  // - data was not ACKed                    
#define I2C_FLAG_LOST   (1<<28)  // - bus arbitration was lost              
#define I2C_FLAG_BUF    (1<<27)  // - no buffer for reading or writing      
#define I2C_FLAG_UNK    (1<<26)  // - unknown I2C status                   
#define I2C_FLAG_BUS    (1<<25)  // - bus error


//==========================================================================
// The ISR does the actual work. It is not that much work to justify
// putting it in the DSR, and it is also not clear whether this would
// even work.  If an error occurs we try to leave the bus in the same
// state as we would if there was no error.
//==========================================================================
static cyg_uint32 at91sam7sxxx_i2c_isr(cyg_vector_t vec, cyg_addrword_t data)
{
	
    volatile cyg_at91sam7sxxx_i2c_extra* extra = (cyg_at91sam7sxxx_i2c_extra*)data;
    cyg_uint32 status;
    cyg_uint32 returnvalue = 0;

    I2C_R16(I2C_SR(extra), status);
    extra->i2c_status = status;

    if (status & MASK_NACK) {
	    extra->i2c_nack_count++;

      extra->i2c_flag = I2C_FLAG_ERROR | I2C_FLAG_NAK;

      cyg_drv_interrupt_mask_intunsafe(vec);
           cyg_drv_interrupt_acknowledge(vec);
           return CYG_ISR_HANDLED | CYG_ISR_CALL_DSR;

    }

    if (status & MASK_TXRDY) {
      if(extra->i2c_count > 0) {

        I2C_W8(I2C_THR(extra), *extra->i2c_txbuf);
        extra->i2c_txbuf++;
        extra->i2c_count--;
        extra->i2c_flag = I2C_FLAG_ACT;
        returnvalue = CYG_ISR_HANDLED;
      }
      else {
        extra->i2c_flag = I2C_FLAG_FINISH;
        returnvalue = CYG_ISR_HANDLED | CYG_ISR_CALL_DSR;
        cyg_drv_interrupt_mask_intunsafe(vec); 	// diesen interrupt deaktivieren
      }
	
    cyg_drv_interrupt_acknowledge(vec);
    return returnvalue;

    }
    
    if (status & MASK_TXCOMP) {

       extra->i2c_flag = I2C_FLAG_FINISH;

       cyg_drv_interrupt_mask_intunsafe(vec);
       cyg_drv_interrupt_acknowledge(vec);
       return CYG_ISR_HANDLED | CYG_ISR_CALL_DSR;
    }
        
    if (status & MASK_RXRDY) {
      if(extra->i2c_rxbuf == NULL) {

        extra->i2c_flag = I2C_FLAG_ERROR | I2C_FLAG_BUF;
        cyg_drv_interrupt_mask_intunsafe(vec);
        cyg_drv_interrupt_acknowledge(vec);
        returnvalue = CYG_ISR_HANDLED | CYG_ISR_CALL_DSR;
      }
      
      if(extra->i2c_count > 0) {
        I2C_R8(I2C_RHR(extra), *extra->i2c_rxbuf);
        extra->i2c_rxbuf++;
        extra->i2c_count--;
        returnvalue = CYG_ISR_HANDLED;
      }
	
      if(extra->i2c_count == 1) {
        I2C_W8(I2C_CR(extra), CR_STOP);
      }

      if(extra->i2c_count <= 0) {
        extra->i2c_flag = I2C_FLAG_FINISH;
        cyg_drv_interrupt_mask_intunsafe(vec);
        cyg_drv_interrupt_acknowledge(vec);
        returnvalue = CYG_ISR_HANDLED | CYG_ISR_CALL_DSR;
      }
	    
      cyg_drv_interrupt_acknowledge(vec);
      return returnvalue;
    }    
    
    cyg_drv_interrupt_acknowledge(vec);
    
    //
    // We need to call the DSR only if there is really something to signal,
    // that means only if extra->i2c_flag != 0
    //
    if (extra->i2c_flag) {
        return CYG_ISR_HANDLED | CYG_ISR_CALL_DSR;
    }
    else {
        return CYG_ISR_HANDLED; 
    }
}


//==========================================================================
// DSR signals data
//==========================================================================
static void
at91sam7sxxx_i2c_dsr(cyg_vector_t vec, cyg_ucount32 count, cyg_addrword_t data)
{
    cyg_at91sam7sxxx_i2c_extra* extra = (cyg_at91sam7sxxx_i2c_extra*)data;
    if(extra->i2c_flag) {
        cyg_drv_cond_signal(&extra->i2c_wait);
    }
}


//==========================================================================
// Initialize driver & hardware state
//==========================================================================
void cyg_at91sam7sxxx_i2c_init(cyg_at91sam7sxxx_i2c_extra* extra)
{

     cyg_uint32             divider;

    I2C_W8(I2C_CR(extra), CR_MSDIS | CR_SWRST);		//Master disable and reset

    divider = (((I2C_CLK(extra) / (I2C_BUS_FREQ(extra))) / 2) - 3) & 0xFFFF;
    
    I2C_W32(I2C_CWGR(extra), (divider<<8) | divider);

    I2C_W32(I2C_MMR(extra), 0x0); 		//DADR=0
    
    I2C_W8(I2C_CR(extra), CR_MSEN);		//Master enable

    I2C_W16(I2C_IDR(extra), MASK_TXRDY | MASK_RXRDY | MASK_TXCOMP | MASK_NACK);

    cyg_drv_mutex_init(&extra->i2c_lock);
    cyg_drv_cond_init(&extra->i2c_wait, &extra->i2c_lock);
    cyg_drv_interrupt_create(I2C_ISRVEC(extra),
                             I2C_ISRPRI(extra),
                             (cyg_addrword_t) extra,
                             &at91sam7sxxx_i2c_isr,
                             &at91sam7sxxx_i2c_dsr,
                             &(extra->i2c_interrupt_handle),
                             &(extra->i2c_interrupt_data));
    cyg_drv_interrupt_attach(extra->i2c_interrupt_handle);

}


//==========================================================================
// transmit a buffer to a device
//==========================================================================
cyg_uint32 cyg_at91sam7sxxx_i2c_tx(const cyg_at91sam7sxxx_i2c_device *dev, 
                              const cyg_uint8      *tx_data, 
                              cyg_uint32            count)
{
    cyg_at91sam7sxxx_i2c_extra* extra = 
                           (cyg_at91sam7sxxx_i2c_extra*)dev->i2c_extra;
    extra->i2c_addr  = dev->i2c_address;
    extra->i2c_count = count;
    extra->i2c_txlength = count;
    extra->i2c_txbuf = tx_data;
    extra->i2c_nack_count=0;
    
    I2C_W16(I2C_IER(extra), MASK_TXRDY); //MASK_TXCOMP noch nicht enablen

    I2C_W32(I2C_MMR(extra), ((dev->i2c_address &0x7F) << 16));
 
    // the isr will do most of the work, and the dsr will signal when an
    // error occured or the transfer finished

    I2C_W8(I2C_THR(extra), *(extra->i2c_txbuf));
    extra->i2c_txbuf++;
    extra->i2c_count--;

    extra->i2c_flag  = 0;

    cyg_drv_mutex_lock(&extra->i2c_lock);
    cyg_drv_dsr_lock();
    cyg_drv_interrupt_unmask(I2C_ISRVEC(extra));

    while(!(extra->i2c_flag & (I2C_FLAG_FINISH | I2C_FLAG_ERROR))) {
      cyg_drv_cond_wait(&extra->i2c_wait);
    }

    cyg_drv_interrupt_mask(I2C_ISRVEC(extra));
    cyg_drv_dsr_unlock();
    cyg_drv_mutex_unlock(&extra->i2c_lock);

    // too bad we have no way to tell the caller
    if(extra->i2c_flag & I2C_FLAG_ERROR) {
       extra->i2c_flag = 0;
    }

    count -= extra->i2c_count;

    extra->i2c_addr  = 0;
    extra->i2c_count = 0;
    extra->i2c_txbuf = NULL;
    extra->i2c_mask=0;
    
    I2C_W16(I2C_IDR(extra), MASK_TXRDY | MASK_TXCOMP | MASK_NACK);

    return extra->i2c_nack_count;
}

 
//==========================================================================
// receive into a buffer from a device
//==========================================================================
cyg_uint32 cyg_at91sam7sxxx_i2c_rx(const cyg_at91sam7sxxx_i2c_device *dev,
                              cyg_uint8            *rx_data,
                              cyg_uint32            count)
{
    cyg_at91sam7sxxx_i2c_extra* extra = 
                           (cyg_at91sam7sxxx_i2c_extra*)dev->i2c_extra;
    extra->i2c_addr  = dev->i2c_address;
    extra->i2c_count = count+1;
    extra->i2c_rxbuf = rx_data;
    extra->i2c_nack_count = 0; 
    
    I2C_W16(I2C_IER(extra), MASK_RXRDY);
    
    I2C_W32(I2C_MMR(extra), ((dev->i2c_address &0x7F) << 16) | MMR_MREAD);
    
    if ( count==1 ) {
	    I2C_W8(I2C_CR(extra), CR_START | CR_STOP);
    }
    else {
	    I2C_W8(I2C_CR(extra), CR_START);
    }
    
    extra->i2c_flag  = 0;
  
    //
    // the isr will do most of the work, and the dsr will signal when an
    // error occurred or the transfer finished
    //
    cyg_drv_mutex_lock(&extra->i2c_lock);
    cyg_drv_dsr_lock();
    cyg_drv_interrupt_unmask(I2C_ISRVEC(extra));

    while(!(extra->i2c_flag & (I2C_FLAG_FINISH | I2C_FLAG_ERROR))) {
        cyg_drv_cond_wait(&extra->i2c_wait);
    }

    cyg_drv_interrupt_mask(I2C_ISRVEC(extra));
    cyg_drv_dsr_unlock();
    cyg_drv_mutex_unlock(&extra->i2c_lock);
  
    if (extra->i2c_flag & I2C_FLAG_ERROR) {
      extra->i2c_flag = 0;
    }

    count -= extra->i2c_count;
  
    extra->i2c_flag = 0;    
    extra->i2c_addr  = 0;
    extra->i2c_count = 0;
    extra->i2c_mask=0;

    I2C_W16(I2C_IDR(extra), MASK_RXRDY | MASK_NACK);

    return extra->i2c_nack_count; 
}

//#endif
//---------------------------------------------------------------------------
// eof i2c_at91sam7sxxx.c

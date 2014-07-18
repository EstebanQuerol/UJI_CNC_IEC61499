//==========================================================================
//
//      platform_i2c.c
//
//      Optional I2C support for Lego Mindstorms NXT
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
// Author(s):    Uwe Kindler <uwe_kindler@web.de>
// Contributors: 
// Date:         2008-09-11
// Purpose:      
// Description:  
//              
//####DESCRIPTIONEND####
//
//==========================================================================


//=============================================================================
//                               INCLUDES
//=============================================================================
#include <pkgconf/system.h>
#include <cyg/infra/cyg_type.h>
#include <cyg/hal/hal_io.h>

#include <cyg/infra/cyg_ass.h>
#include <cyg/hal/hal_endian.h>
#include <cyg/hal/devs_i2c_arm_at91sam7sxxx.h>
#include <string.h>

//#ifdef CYGHWR_HAL_ARM_AT91SAM7SXXX_I2C_SUPP

#include <cyg/hal/i2c_at91sam7sxxx.h>
#include <cyg/hal/plf_io.h>
#include <cyg/hal/platform_i2c.h>


#define CYGHWR_HAL_ARM_I2C_PIN_TWD 	(1<<AT91_GPIO_PA3)
#define CYGHWR_HAL_ARM_I2C_PIN_TWCK 	(1<<AT91_GPIO_PA4)
// TODO evtl im ecos config

// p.17 HW dev.kit: ARM7 must send this string to AVR
//   or AVR will turn the ARM7 off  = "brainwashing string"
const char arm7ACKtoAvr[] =
	"\xCC" "Let's samba nxt arm in arm, (c)LEGO System A/S";


CYG_AT91SAM7SXXX_I2C_DEVICE(i2c_atmega48_coprocessor, 		//name
			1, 					//adress
			0, 					//flags
			CYG_AT91SAM7SXXX_I2C_DEFAULT_DELAY);	//delay
  
//=============================================================================
// Setup I2C "bus"
//=============================================================================
void at91sam7sxxx_i2c_init(void)
{  
  cyg_uint32 pinstate=0;
  cyg_uint32 cycles=9;

  HAL_WRITE_UINT32(AT91_PMC+AT91_PMC_PCER, AT91_PMC_PCER_TWI | AT91_PMC_PCER_PIOA); // enable twi-controller clock

  HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_MDER, CYGHWR_HAL_ARM_I2C_PIN_TWD | CYGHWR_HAL_ARM_I2C_PIN_TWCK); // Multi drive enable (open drain)

  HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_PER, CYGHWR_HAL_ARM_I2C_PIN_TWD | CYGHWR_HAL_ARM_I2C_PIN_TWCK); // PIO enable, peripheral controller disable

  HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_ODR, CYGHWR_HAL_ARM_I2C_PIN_TWD); // TWD as input
  HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_OER, CYGHWR_HAL_ARM_I2C_PIN_TWCK); // TWCK as output


  HAL_READ_UINT32(AT91_PIOA+AT91_PIO_PDSR, pinstate);
  //shift old data out
  while (cycles > 0 && !(pinstate & CYGHWR_HAL_ARM_I2C_PIN_TWD)) {

    HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_CODR, CYGHWR_HAL_ARM_I2C_PIN_TWCK);
    cyg_thread_delay(1);
    HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_SODR, CYGHWR_HAL_ARM_I2C_PIN_TWCK);
    cyg_thread_delay(1);
    HAL_READ_UINT32(AT91_PIOA+AT91_PIO_PDSR, pinstate);
    cycles--;

  }

  HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_PDR, CYGHWR_HAL_ARM_I2C_PIN_TWD | CYGHWR_HAL_ARM_I2C_PIN_TWCK); // PIO disable, peripheral controller enable
  HAL_WRITE_UINT32(AT91_PIOA+AT91_PIO_ASR, CYGHWR_HAL_ARM_I2C_PIN_TWD | CYGHWR_HAL_ARM_I2C_PIN_TWCK); // select peripheral A


  cyg_at91sam7sxxx_i2c_init( (cyg_at91sam7sxxx_i2c_extra *) i2c_atmega48_coprocessor.i2c_extra); //I2C init
}


//===========================================================================
// Sending the handshake-string to the coprocessor avr
//===========================================================================
cyg_uint32 atmega48_link_init(void)
{

  return cyg_at91sam7sxxx_i2c_tx(&i2c_atmega48_coprocessor, (const cyg_uint8 *) arm7ACKtoAvr, strlen(arm7ACKtoAvr));

}

//===========================================================================
// Sending data-structure to the coprocessor avr
//===========================================================================
cyg_uint32 atmega48_send(cyg_uint8* data, cyg_uint32 count)
{

  return cyg_at91sam7sxxx_i2c_tx(&i2c_atmega48_coprocessor, (cyg_uint8 *) (data), count);

}

//===========================================================================
// Receiving data-structure from the coprocessor avr
//===========================================================================
void atmega48_receive(cyg_uint8* data, cyg_uint32 count)
{

  cyg_at91sam7sxxx_i2c_rx(&i2c_atmega48_coprocessor,(cyg_uint8 *) (data), count);

}


//-----------------------------------------------------------------------------
// EOF platform_i2c.c


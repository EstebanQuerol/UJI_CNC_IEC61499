#ifndef CYGONCE_I2C_AT91SAM7SXXX_H
#define CYGONCE_I2C_AT91SAM7SXXX_H
//==========================================================================
//
//      devs/i2c/arm/at91sam7sxxx/current/src/i2c_at91sam7sxxx.h
//
//      I2C driver for NXP LPC2xxx ARM processors
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
// Author(s):     Hans Rosenfeld <rosenfeld@grumpf.hope-2000.org>
// Contributors:  Uwe Kindler <uwe_kindler@web.de>
// Date:          2008-09-11
// Description:   I2C driver for LPC2xxx
//####DESCRIPTIONEND####
//==========================================================================


//==========================================================================
//                               INCLUDES
//==========================================================================
#include "devs_i2c_arm_at91sam7sxxx.h"
#include <cyg/infra/cyg_type.h>
#include <cyg/hal/drv_api.h>


//==========================================================================
// Single I2C bus sepecififc data
//==========================================================================


typedef struct cyg_at91sam7sxxx_i2c_extra {

    cyg_uint32        	i2c_addr;
    volatile cyg_int32 i2c_count;

    const cyg_uint8* 	i2c_txbuf;
    cyg_uint8*       	i2c_rxbuf;
    cyg_bool         	i2c_rxnak;

    cyg_uint32		    i2c_mask;
    cyg_uint32       	i2c_flag;
    cyg_uint32       	i2c_delay;
    cyg_uint32		    i2c_status;
    cyg_uint32		    i2c_nack_count;

    cyg_uint32		    i2c_txlength;
    
    cyg_drv_mutex_t  	i2c_lock; // For synchronizing between DSR and foreground
    cyg_drv_cond_t   	i2c_wait;
    cyg_handle_t     	i2c_interrupt_handle;// For initializing the interrupt
    cyg_interrupt    	i2c_interrupt_data;
} cyg_at91sam7sxxx_i2c_extra;

typedef struct cyg_at91sam7sxxx_i2c_device {
	volatile struct cyg_at91sam7sxxx_i2c_extra* i2c_extra;
	cyg_uint32          i2c_address;
	cyg_uint32          i2c_flags;
	cyg_uint32          i2c_delay;
} cyg_at91sam7sxxx_i2c_device;


//==========================================================================
// I2C driver interface
//==========================================================================
externC void        cyg_at91sam7sxxx_i2c_init(cyg_at91sam7sxxx_i2c_extra* extra);
externC cyg_uint32  cyg_at91sam7sxxx_i2c_tx(const cyg_at91sam7sxxx_i2c_device*, 
                                      	const cyg_uint8*, cyg_uint32);
externC cyg_uint32  cyg_at91sam7sxxx_i2c_rx(const cyg_at91sam7sxxx_i2c_device*, 
                                       	cyg_uint8*, cyg_uint32);

//==========================================================================
// I2C bus declaration macros
//=========================================================================

#define CYG_AT91SAM7SXXX_I2C_DEFAULT_DELAY   10000

#define CYG_AT91SAM7SXXX_I2C_DEVICE(_name_, _address_, _flags_, _delay_)  \
  static volatile cyg_at91sam7sxxx_i2c_extra _name_ ## _extra = {                \
  i2c_count    :  0,                                                    \
  i2c_txbuf    :  NULL,                                                 \
  i2c_rxbuf    :  NULL,                                                 \
  i2c_flag     :  0							\
  } ;                                                                   \
 	cyg_at91sam7sxxx_i2c_device _name_ = {				\
		.i2c_address    = _address_,                      	\
		.i2c_flags      = _flags_,                              \
		.i2c_delay      = _delay_,  				\
		.i2c_extra	= (void*) & (_name_ ## _extra )		\
	};

//-----------------------------------------------------------------------------
#endif // #endif CYGONCE_I2C_AT91SAM7SXXX_H

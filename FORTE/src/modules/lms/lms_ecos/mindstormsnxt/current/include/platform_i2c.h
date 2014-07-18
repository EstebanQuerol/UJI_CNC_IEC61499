#ifndef __PLATFORM_I2C_H__
# define __PLATFORM_I2C_H__



cyg_uint32 atmega48_link_init(void);
void at91sam7sxxx_i2c_init(void);
cyg_uint32 atmega48_send(cyg_uint8* data, cyg_uint32 count);
void atmega48_receive(cyg_uint8* data, cyg_uint32 count);

#endif

/*
 *            Copyright (c) 1998-2003 by NETsilicon Inc.
 *
 *  This software is copyrighted by and is the sole property of 
 *  NETsilicon.  All rights, title, ownership, or other interests
 *  in the software remain the property of NETsilicon.  This
 *  software may only be used in accordance with the corresponding
 *  license agreement.  Any unauthorized use, duplication, transmission,  
 *  distribution, or disclosure of this software is expressly forbidden.
 *
 *  This Copyright notice may not be removed or modified without prior
 *  written consent of NETsilicon.
 *
 *  NETsilicon, reserves the right to modify this software
 *  without notice.
 *
 *  NETsilicon
 *  411 Waverley Oaks Road                  USA 781.647.1234
 *  Suite 304                               http://www.netsilicon.com
 *  Waltham, MA 02452                       AmericaSales@netsilicon.com
 *
 *************************************************************************
 *
 *  Description
 *  ====================================================================
 *  This file is one of two files, bsp.h and appconf.h, that contain configuration
 *  settings.  The file bsp.h contains configuration settings that are usually
 *  platform specific.  This file contains configuration settings that may be
 *  different from application to application, even if the applications run on
 *  the same platform.
 *
 */


#ifndef appconf_h

#define appconf_h

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>

/*ad*
 * Set to run POST at start up.
 *
 * Set APP_POST to TRUE if you want the BSP to run the Power On Self Test
 * at startup.  Set APP_POST to FALSE to skip the POST.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration
 * @since 1.0
*ad*/
extern const int APP_POST;


/*ad*
 * Set to initialize the C++ runtime environment at start up.
 *
 * APP_CPP determines whether or not the application is a C++ based application.  If the
 * application is C++ based, set APP_CPP to TRUE, otherwise set to FALSE or leave undefined.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration
 * @since 1.0
*ad*/
#define APP_CPP                 TRUE


/*ad*
 * APP_ERROR_HANDLER defines the user error handler for fatal errors.  It should either be set
 * to NULL, or set to the name of a routine that should be called if a fatal error occurs.  The
 * routine should be of the form:
 *
 *      void error_handler (char *errorDescription, int errorCode, int errorSubcode)
 *
 * If APP_ERROR_HANDLER is NULL, then the default error handler will be used.  This error handler
 * blinks the LEDs on the development board in an infinite loop.  The LEDs are blinked in a pattern
 * that indicates the errorType.  
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration
 * @since 1.0
 * @deprecated  6.0
*ad*/
#define APP_ERROR_HANDLER           NULL


/*ad*
 * APP_ROOT_STACK_SIZE sets the size of the root thread's stack.  The root thread is the
 * thread that calls applicationStart.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 1.0
*ad*/
//#define APP_ROOT_STACK_SIZE         131072
#define APP_ROOT_STACK_SIZE         331072

/*ad*
 * APP_ROOT_PRIORITY sets the priority level for the root thread.  The root thread is the
 * thread that calls applicationStart.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 1.0
*ad*/
#define APP_ROOT_PRIORITY           16


/*ad*
 * APP_DEFAULT_API_PRIORITY determines the priority level that threads internal to the
 * NET+Works APIs will use.  The global variable bsp_default_api_priority is
 * loaded with this value.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 1.0
*ad*/
#define APP_DEFAULT_API_PRIORITY    (NATranslatePriorityLevel(naDefaultPriority))


/*ad*
 * APP_FILE_SYSTEM_SIZE determines the numbers of files the Advanced Web server(AWS)
 * will allocate for the file system. The default value is 9, the number of connections 
 * allocated by the AWS. Increasing APP_FILE_SYSTEM_SIZE will reduce available memory. 
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 3.0
*ad*/
#define APP_FILE_SYSTEM_SIZE          9


/*ad*
 * APP_DIALOG_PORT determines whether or not the initialization code will prompt for configuration
 * parameters.  It should be set to a string that contains the serial port to prompt with.  If it
 * is not set, or if it contains an invalid port, then the initialization code will not prompt for
 * configuration parameters.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 1.0
*ad*/
#define APP_DIALOG_PORT             "/com/0"

/*ad*
 * APP_DIALOG_APP_NAME determines the name of the current application program.  This name
 * is displayed at the top of the configuration dialog.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 1.0
*ad*/
#define APP_DIALOG_APP_NAME         "FORTE"


/*ad*
 * APP_ROOT_PASSWORD determines the root account password.  This account has all privileges and
 * can be used for any service requiring a login (i.e. FTP, telnet).  The password set here is
 * a default value that is used if the rootPassword field in NVRAM is empty.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 5.0
*ad*/
#define APP_ROOT_PASSWORD           "Netsilicon"


/*ad*
 * APP_ADMINISTRATORS_ACCOUNT is a username used for a secure gateway account.  This account has 
 * privileges only for a gateway (so it can not be used for insecure applications like FTP or
 * Telnet).  This initial password is also APP_ADMINISTRATORS_ACCOUNT, but can be changed on
 * the dialog console, and is persistent via NVRAM.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 5.0
*ad*/
#define APP_ADMINISTRATORS_ACCOUNT  "admin"

#if defined(HAVE_SECURITY_API) 

/*ad*
 * APP_FIXED_GATEWAY_KEY is the fixed key used for the secure gateway.  This Key can be used  
 * at the remote side when using Fixed Key distribution.
 *
 * This feature cannot be used unless you have purchased the security API.  You must leave this
 * value commented out to avoid build errors unless you have installed the security API.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 5.0
*ad*/
#define APP_FIXED_GATEWAY_KEY       "TESTKEY"

/*ad*
 * APP_USE_KERBEROS enables access to the Kerberos parameters: username, password, realmname 
 * and KDC IP address.
 *
 * This feature cannot be used unless you have purchased the security API.  You must leave this
 * value commented out to avoid build errors unless you have installed the security API.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 5.0
*ad*/
#define APP_USE_KERBEROS

#endif /* defined(HAVE_SECURITY_API) */

#if defined(AUTODOC_VERSION)
/*ad*
 * APP_USE_NETWORK_TIME_PROTOCOL uses the NVRAM configuration to store Network Time Protocol
 * Servers used for the NET+OS SNTP Client on a NAstartSntp() call.  If this constant is
 * set, then the BSP will start the SNTP client.  The C Library time() functions can be
 * used to read the time.
 *
 * @note    The BSP will call @link customizeErrorHandler  if @link APP_USE_NETWORK_TIME_PROTOCOL  is
 *          defined, but no SNTP server address has been set.
 *
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 5.0
*ad*/
#define APP_USE_NETWORK_TIME_PROTOCOL
#endif
/* #define APP_USE_NETWORK_TIME_PROTOCOL */



/*ad*
 * APP_STDIO_PORT determines which serial port stdin, stdout, and stderr should be redirected to.
 * It should be set to the device name of the port or NULL.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 1.0
*ad*/
#define APP_STDIO_PORT              "/com/0"


/*ad*
 * If APP_USE_NVRAM is set to a nonzero value, then the initialization code will attempt
 * to read the configuration values from NVRAM.  If the read is successful, then these
 * values will be used.  If not, then the values defined in this file will be used.  If
 * the configuration dialog is enabled, then the user will be prompted to change these
 * values.  If he does, then the new configuration values will be saved to NVRAM.
 *
 * When APP_USE_NVRAM is set to zero, the values, defined in this file, will be used, but will not
 * be written to NVRAM. The actual NVRAM driver is based on the define of BSP_NVRAM_DRIVER in bsp.h
 * in the platform directory. If you don't want to build NVRAM driver, you must define BSP_NVRAM_DRIVER 
 * as BSP_NVRAM_NONE. If your application runs directly from flash using rom.bin, you must NOT 
 * define BSP_NVRAM_DRIVER as BSP_NVRAM_LAST_FLASH_SECTOR.
 *
 * See <root>/h/narmsrln.h for configuration structure devBoardParamsType.  If this structure
 * needs extensions, applications should add fields to the end of this data structure.  To 
 * protect legacy structures, fields should not be deleted.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 1.0
*ad*/
#define APP_USE_NVRAM               0


/*ad*
 * Defines the total memory (in bytes) allocated for the TCP/IP stack heap
 *
 * This memory is used exclusively for the NET+OS TCP/IP stack, which uses it 
 * for all dynamic allocations, including memory for network packets. 
 * The TCP/IP heap is by default a byte pool.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 1.0
 *
 * @see @link APP_NET_HEAP_BLOCK_POOLS
*ad*/
//#define APP_NET_HEAP_SIZE	        0x80000
#define APP_NET_HEAP_SIZE           0x240000


/*ad*
 * Use these definitions to allocate portions of the network heap as a block pool and 
 * adjust them as needed
 *
 * The network heap can be split into a byte pool and seven block pools of size 16, 32,
 * 64, 128, 256, 540, and 1836. These block sizes were chosen based on needs of the
 * TCP/IP stack. When a block pool runs out, a block from the next highest pool is used.
 * When the pools run out, or when the size exceeds the largest block, memory is taken
 * from the byte pool.
 *
 * @note Any of these constants can be defined to 0 or left undefined.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 6.2
 * @name APP_NET_HEAP_BLOCK_POOLS "TCP/IP heap block pools"
 *
 * @param  APP_TCPIP_16BYTE_BLOCK_COUNT     60      
 * @param  APP_TCPIP_32BYTE_BLOCK_COUNT     60
 * @param  APP_TCPIP_64BYTE_BLOCK_COUNT     100
 * @param  APP_TCPIP_128BYTE_BLOCK_COUNT    20
 * @param  APP_TCPIP_256BYTE_BLOCK_COUNT    10
 * @param  APP_TCPIP_540BYTE_BLOCK_COUNT    100
 * @param  APP_TCPIP_1836BYTE_BLOCK_COUNT   100
 *
 * @see @link APP_NET_HEAP_SIZE
*ad*/
#define APP_TCPIP_16BYTE_BLOCK_COUNT        60 
#define APP_TCPIP_32BYTE_BLOCK_COUNT        60
#define APP_TCPIP_64BYTE_BLOCK_COUNT        100
#define APP_TCPIP_128BYTE_BLOCK_COUNT       20
#define APP_TCPIP_256BYTE_BLOCK_COUNT       10
#define APP_TCPIP_540BYTE_BLOCK_COUNT       50
#define APP_TCPIP_1836BYTE_BLOCK_COUNT      100

#define APP_TCPIP_BLOCK_HEAP_SIZE   (16*APP_TCPIP_16BYTE_BLOCK_COUNT   +  32*APP_TCPIP_32BYTE_BLOCK_COUNT  + \
                                     64*APP_TCPIP_64BYTE_BLOCK_COUNT   + 128*APP_TCPIP_256BYTE_BLOCK_COUNT + \
                                    256*APP_TCPIP_256BYTE_BLOCK_COUNT  + 540*APP_TCPIP_540BYTE_BLOCK_COUNT + \
                                   1836*APP_TCPIP_1836BYTE_BLOCK_COUNT)

#if ((APP_NET_HEAP_SIZE - APP_TCPIP_BLOCK_HEAP_SIZE) < (APP_NET_HEAP_SIZE * 35 / 100))
#error  Not enough memory left for TCP/IP Byte Heap 
#endif


/*ad*
 * PPP is enabled on COM1 when APP_ENABLE_PPP1 is nonzero.
 * Note when this is defined APP_DIALOG_PORT and APP_STDIO_PORT must not use
 * COM1 ("/com/0")
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 3.0
*ad*/
#define APP_ENABLE_PPP1           0

/*ad*
 * APP_PPP1_ADDRESS will be used as the default IP address for PPP interface one if 
 * APP_USE_NVRAM is set to 0, or if NVRAM has not been initialized.
 *
 * All values should be specified in dotted notation as strings.  
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 6.0
*ad*/


#define APP_PPP1_ADDRESS              "0.0.0.0"

/*ad*
 * APP_PPP1_PEER_ADDRESS will be used as the default IP address PPP interface one will assign to a
 * remote client if APP_USE_NVRAM is set to 0, or if NVRAM has not been initialized.
 *
 * All values should be specified in dotted notation as strings.  
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 6.0
*ad*/
#define APP_PPP1_PEER_ADDRESS              "0.0.0.0"


/*ad*
 * PPP is enabled on COM2 when APP_ENABLE_PPP2 is nonzero.
 * Note when this is defined APP_DIALOG_PORT and APP_STDIO_PORT must not use
 * COM2 ("/com/1")
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 3.0
*ad*/
#define APP_ENABLE_PPP2          0

/*ad*
 * APP_PPP2_ADDRESS will be used as the default IP address for PPP interface two if 
 * APP_USE_NVRAM is set to 0, or if NVRAM has not been initialized.
 *
 * All values should be specified in dotted notation as strings.  
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 6.0
*ad*/


#define APP_PPP2_ADDRESS              "0.0.0.0"

/*ad*
 * APP_PPP2_PEER_ADDRESS will be used as the default IP address PPP interface two will assign to a
 * remote client if APP_USE_NVRAM is set to 0, or if NVRAM has not been initialized.
 *
 * All values should be specified in dotted notation as strings.  
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 6.0
*ad*/
#define APP_PPP2_PEER_ADDRESS              "0.0.0.0"


/*ad*
 * APP_IP_ADDRESS will be used as the default IP address if APP_USE_NVRAM is set to 0, or if
 * NVRAM has not been initialized.
 *
 * All values should be specified in dotted notation as strings.  
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 3.0
*ad*/

// values used by ACIN/smr
#define APP_IP_ADDRESS              "128.130.200.165"
// values used by PROFACTOR
//#define APP_IP_ADDRESS              "192.168.20.58"


/*ad*
 * APP_IP_SUBNET_MASK will be used as the default subnet mask if APP_USE_NVRAM is set to 0, or if
 * NVRAM has not been initialized.
 *
 * All values should be specified in dotted notation as strings.  
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 3.0
*ad*/

// values used by ACIN/smr
#define APP_IP_SUBNET_MASK          "255.255.255.128"
// values used by PROFACTOR
//#define APP_IP_SUBNET_MASK          "255.255.255.0"

/*ad*
 * APP_IP_GATEWAY will be used as the default gateway if APP_USE_NVRAM is set to 0, or if
 * NVRAM has not been initialized.  If there is no gateway, then set APP_IP_GATEWAY to "0.0.0.0".
 *
 * All values should be specified in dotted notation as strings.  
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 3.0
*ad*/

// values used by ACIN/smr
#define APP_IP_GATEWAY              "128.130.200.129"
// values used by PROFACTOR
//#define APP_IP_GATEWAY              "192.168.20.1"


/*ad*
 * APP_SNTP_PRIMARY determine the unit's default primary 
 * SNTP server.  All values should be specified in dotted notation as strings.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 5.0
*ad*/
#define APP_SNTP_PRIMARY            "0.0.0.0"


/*ad*
 * APP_SNTP_SECONDARY determine the unit's default secondary
 * SNTP server.  All values should be specified in dotted notation as strings.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 5.0
*ad*/
#define APP_SNTP_SECONDARY          "0.0.0.0"

/*ad*
 * APP_KERBEROS_KDC determines the unit's default Kerberos KDC IP Address, and must be specified 
 * in dotted notation as a string.  You must define APP_USE_KERBEROS to enable these settings.
 * You must install the security API, which is an extra cost option, before you can use it.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 5.0
*ad*/
#define APP_KERBEROS_KDC            "7.93.124.220"

/*ad*
 * APP_KERBEROS_USERNAME is the username used at this KDC. 
 * Must define APP_USE_KERBEROS to enable these settings.
 * You must install the security API, which is an extra cost option, before you can use it.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 5.0
*ad*/
#define APP_KERBEROS_USERNAME       "joetestuser"

/*ad*
 * APP_KERBEROS_PASSWORD is the password used at this KDC.  
 * Must define APP_USE_KERBEROS to enable these settings.
 * You must install the security API, which is an extra cost option, before you can use it.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 5.0
*ad*/
#define APP_KERBEROS_PASSWORD       "password"

/*ad*
 * APP_KERBEROS_REALMNAME is the realm in which this
 * account is used.  Must define APP_USE_KERBEROS to enable these settings.
 * You must install the security API, which is an extra cost option, before you can use it.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 5.0
*ad*/
#define APP_KERBEROS_REALMNAME      "NETSILICON.COM"



/*ad*
 * APP_BSP_SERIAL_NUM determines the default serial number to use if APP_USE_NVRAM is 0,
 * or if NVRAM is uninitialized.  The serial number should consist of 1 alpha character
 * followed by 8 digits.  
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 1.0
*ad*/
#define APP_BSP_SERIAL_NUM	        "N99999999"


/*ad*
 * APP_BSP_MAC_ADDRESS determines the default Ethernet MAC address to use if 
 * APP_USE_NVRAM is 0, or if NVRAM is uninitialized.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 6.0
*ad*/
#define APP_BSP_MAC_ADDRESS         "00:40:9d:43:35:97"


/*ad*
 * APP_BSP_DELAY determines the amount of time the configuration dialog will
 * wait for user input before continuing the BSP startup.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 1.0
*ad*/
#define APP_BSP_DELAY		        5


/*ad*
 * APP_BSP_BAUD_RATE determines the baud rate that will be used for the configuration
 * dialog if APP_USE_NVRAM is 0, or if NVRAM is uninitialized.
 *
 * Simple serial uses this baudrate. Bootloader serial recovery uses simple serial to
 * read the flash data with the default baudrate of 115200. So in bsp/bootloader/appconf.h, 
 * this value is set to 115200. This is required to increase the flash download time. 
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 1.0
*ad*/
#define APP_BSP_BAUD_RATE	        38400


/*ad*
 * APP_USE_STATIC_IP is used to create a default configuration for ACE.  This value
 * only has effect if there is no valid configuration stored in NVRAM, or if APP_USE_NVRAM
 * is not set.  It determines whether or not the IP stack should use the static IP
 * parameters specified in APP_IP_ADDRESS, APP_IP_SUBNET_MASK, and APP_IP_GATEWAY, or
 * get an IP address from the network using DHCP, BOOTP, RARP, or Ping-ARP.  
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration 
 * @since 6.0
*ad*/
#define APP_USE_STATIC_IP            TRUE


/*ad*
 * APP_DEFAULT_ETHERNET_DUPLEX determines the default Ethernet duplex setting.  Normally,
 * the PHY will negotiate the duplex setting with the hub or switch.  However, some hubs
 * do not support autonegotiation, or allow the end user to disable it.  In this case,
 * there is no way for the PHY to determine what duplex setting should be used.  It will
 * use the value stored in NVRAM.  The value of APP_DEFAULT_ETHERNET_DUPLEX will be
 * written to the NVRAM field when it is first initialized.
 *
 * Legal values are bpHalfDuplex, bpFullDuplex, and bpDefaultDuplex.  The recommended 
 * setting is bpDefaultDuplex.  This uses the default duplex setting supported by the
 * Ethernet PHY.  Most PHYs will default to half duplex.
 *
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration
 * @since 6.0
 * @see @link bpDuplexLevelType
*ad*/
#define APP_DEFAULT_ETHERNET_DUPLEX  bpDefaultDuplex


/*ad*
 * This constant determines whether Auto-IP will be enabled by default.  The constant is used
 * when NVRAM is first initialized, and when APP_USE_NVRAM is set to 0.  If APP_ENABLE_AUTO_IP
 * is TRUE, the default ACE configuration will be to setup the secondary network 
 * interface "eth0:0" to acquire an IP address using Auto-IP.  Note that this may cause problems
 * with some applications.  This is because Auto-IP addresses are not routable, and because
 * Auto-IP can usually assign an address very quickly, before other methods like DHCP can.  So,
 * if APP_ENABLE_AUTO_IP is set to TRUE, it is very likely that applicationStart() will be
 * called before TCP/IP has a routable TCP/IP address (DHCP et. al. will not have had time
 * to get an IP address yet).  This may cause unexpected errors with applications that 
 * immediately try to communicate over IP.  If APP_ENABLE_AUTO_IP is set to FALSE, then the
 * default ACE configuration will leave Auto-IP disabled.  This constant only effects
 * the default configuration.  It will not have any effect if a valid ACE configuration is
 * already stored in NVRAM.
 *  
 * @external
 * @include     "appconf.h"
 * @category ApplicationConfiguration
 * @since 6.0
*ad*/
#define APP_ENABLE_AUTO_IP  FALSE


#ifdef __cplusplus
}
#endif

#endif



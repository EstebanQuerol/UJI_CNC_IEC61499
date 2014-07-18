/*
 *            Copyright (c) 1998-2002 by NETsilicon Inc.
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
 *  Suite 227                               http://www.netsilicon.com
 *  Waltham, MA 02452                       AmericaSales@netsilicon.com
 *
 *************************************************************************
 *
 *     Module Name: appconf_api.c
 *         Version: 1.00
 *   Original Date: 08/15/02
 *	    	Author: Dale Lee
 *        Language: Ansi C
 * Compile Options:
 * Compile defines:
 *       Libraries:
 *    Link Options:
 *
 *    Entry Points:
 *					NAGetAppErrorHandler ()
 *					NAGetAppRootStackSize
 *					NAGetAppRootPriority ()
 *					NAGetDefaultAPIPriorty ()
 *					NAGetAppFileSystemSize ()
 *					NAGetAppDialogPort ()
 *					NAGetAppDialogAppName ()
 *					NAGetAppAngelBootRom ()
 *					NAGetAppRootPassword ()
 *					NAGetAppAdministratorsAccount ()
 *					NAGetAppFixedGatewayKey ()
 *					NAGetAppUseNetworkTimeProtocol ()
 *					NAGetAppPost ()
 *					NAGetAppBurnInTest ()
 *					NAGetAppStdioPort ()
 *					NAGetAppUseNvram ()
 *					NAGetAppNetHeapSize ()
 *					NAGetAppStartupMode ()
 *					NAGetAppEnablePPP1 ()
 *					NAGetAppPPP1Address ()
 *					NAGetAppPPP1PeerAddress ()
 *					NAGetAppEnablePPP2 ()
 *					NAGetAppPPP2Address ()
 *					NAGetAppPPP2PeerAddress ()
 *					NAGetAppIpAddress ()
 *					NAGetAppIpSubnetMask ()
 *					NAGetAppIpGateway ()
 *					NAGetAppSntpPrimary ()
 *					NAGetAppSntpSecondary ()
 *					NAGetAppBspSerialNum ()
 *					NAGetAppBspDelay ()
 *					NAGetAppBspBaudRate ()
 *					NAGetAppUseStaticIP()
 *					NAGetEnableHdlc ()
 *					NAGetAppDisableRouterAds
 *
 *
 * Description.
 * =======================================================================
 * This file contains the functions that wraps around the application
 * configuration values in appconf.h. The application will no longer
 * need to directly link in any files which requires appconf.h
 *
 *
 * Edit Date/Ver   Edit Description
 * ==============  =======================================================
 * LZ   10/21/02   Removed checkAppUseNvram().
 * JZW  01/09/04   Added NAGetAppDisableRouterAds
 * JZW  05/15/05   Removed kerberos references. No longer suported
 */

/*ad*
 *
 * The Application Configuration API consists of a group of functions that wrap around the application
 * configuration values defined in appconf.h.
 *
 * @external
 * @overview Application Configuration
 * @include "appconf_api.h"
 * @platform all
 * @library bsp
 * @category ApplicationConfiguration
 * @since 6.0
*ad*/

#include "appconf.h"
#include <stdio.h>
#include <string.h>
#include <Npttypes.h>
#include <netoserr.h>
#include <bsp_api.h>
#include <boardParams.h>
#include <natcpipheap.h>
#include <appconf_api.h>

/*ad*
 * Returns the value of @link APP_ENABLE_AUTO_IP  as defined in appconf.h
 *
 * The value determines whether Auto-IP will be enabled on the "eth0:0"
 * network interface.
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return TRUE             Auto-IP should be enabled
 * @return FALSE            Auto-IP should not be enabled
*ad*/
BOOLEAN NAGetEnableAutoIp(void)
{
    BOOLEAN result = FALSE;

    #ifdef APP_ENABLE_AUTO_IP
        NA_ASSERT((APP_ENABLE_AUTO_IP == TRUE) || (APP_ENABLE_AUTO_IP == FALSE));

        result = APP_ENABLE_AUTO_IP;
    #endif

    return result;
}



/*ad*
 * Returns the value of @link APP_DEFAULT_ETHERNET_DUPLEX  as defined in appconf.h
 *
 * The value determines what Ethernet duplex setting should be used if the
 * Ethernet hub or switch we are connected to does not support autonegotiation.
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return bpFullDuplex     Default is full duplex Ethernet
 * @return bpHalfDuplex     Default is half duplex Ethernet
 * @return bpDefaultDuplex  Use PHY's default setting
*ad*/
bpDuplexLevelType NAGetDefaultEthernetDuplex(void)
{
    bpDuplexLevelType result = bpDefaultDuplex;

#ifdef APP_DEFAULT_ETHERNET_DUPLEX
    result = APP_DEFAULT_ETHERNET_DUPLEX;
#endif
    return result;
}


/*ad*
 * Returns the value of @link APP_ERROR_HANDLER  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return NULL             no user error handler is defined
 * @return otherwise        pointer to user defined error handler
*ad*/
userErrorHandlerType NAGetAppErrorHandler(void)
{
	#ifdef APP_ERROR_HANDLER
		return (APP_ERROR_HANDLER);
	#else
		return (NULL);
	#endif
}



/*ad*
 * Returns the value of @link APP_ROOT_STACK_SIZE  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return stack-size       Stack size for root thread.
*ad*/
int NAGetAppRootStackSize(void)
{
	#if APP_ROOT_STACK_SIZE
		return (APP_ROOT_STACK_SIZE);
	#else
		Error: Must be defined with a value
	#endif
}

/*ad*
 * Returns the value of @link APP_ROOT_PRIORITY  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return priority-level    Priority level root thread will run at.
*ad*/
int NAGetAppRootPriority(void)
{
	#if APP_ROOT_PRIORITY
		return (APP_ROOT_PRIORITY);
	#else
		Error: Must be defined with a value
	#endif
}

/*ad*
 * Returns the value of @link APP_DEFAULT_API_PRIORITY  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return priority-level     Suggested default priority level for application threads.
*ad*/
int NAGetAppDefaultAPIPriority(void)
{
	#ifdef APP_DEFAULT_API_PRIORITY
		return (APP_DEFAULT_API_PRIORITY);
	#else
		Error: Must be defined with a value
	#endif
}


/*ad*
 * Returns the value of @link APP_FILE_SYSTEM_SIZE  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return positive-value     Number of files AWS will support.
 * @return 0                  AWS file interface is disabled.
*ad*/
int NAGetAppFileSystemSize(void)
{
	#ifdef APP_FILE_SYSTEM_SIZE
		return (APP_FILE_SYSTEM_SIZE);
	#else
		return (0);
	#endif
}

/*ad*
 * Returns the value of @link APP_DIALOG_PORT  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return dialog-port     Port to use for configuration dialog.
 * @return NULL				APP_DIALOG_PORT is undefined.
*ad*/
char * NAGetAppDialogPort(void)
{
	#ifdef APP_DIALOG_PORT
		return (APP_DIALOG_PORT);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_DIALOG_APP_NAME  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return name  Application name to display in dialog.
 * @return NULL	 APP_DIALOG_APP_NAME is not defined.
*ad*/
char * NAGetAppDialogAppName(void)
{
	#ifdef APP_DIALOG_APP_NAME
		return (APP_DIALOG_APP_NAME);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_ROOT_PASSWORD  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return password     Default password for 'root' user.
 * @return NULL     	APP_ROOT_PASSWORD is not defined.
*ad*/
char * NAGetAppRootPassword(void)
{
	#ifdef APP_ROOT_PASSWORD
		return (APP_ROOT_PASSWORD);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_ADMINISTRATORS_ACCOUNT  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return username   Username for secure gateway account.
 * @return NULL       No user name has been set.
*ad*/
char * NAGetAppAdministratorsAccount(void)
{
	#ifdef APP_ADMINISTRATORS_ACCOUNT
		return (APP_ADMINISTRATORS_ACCOUNT);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_FIXED_GATEWAY_KEY  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return NULL     No key has been setup for gateway.
 * @return key      Pointer to key for gateway.
*ad*/
char * NAGetAppFixedGatewayKey(void)
{
	#ifdef APP_FIXED_GATEWAY_KEY
		return (APP_FIXED_GATEWAY_KEY);
	#else
		return (NULL);
	#endif
}


/*ad*
 * Returns the value of @link APP_USE_NETWORK_TIME_PROTOCOL  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return TRUE     BSP will setup SNTP client.
 * @return FALSE    BSP will not setup SNTP client.
*ad*/
int NAGetAppUseNetworkTimeProtocol(void)
{
	#ifdef APP_USE_NETWORK_TIME_PROTOCOL
		return (TRUE);
	#else
		return (FALSE);
	#endif
}



/*ad*
 * Returns the value of @link APP_POST  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return TRUE     POST will be run at start up.
 * @return FALSE    POST will not be run at start up.
*ad*/
int NAGetAppPost(void)
{
	#if APP_POST
		return (TRUE);
	#else
		return (FALSE);
	#endif
}


/*ad*
 * Returns the value of @link APP_STDIO_PORT  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return pointer  Nul terminated string with name of port to direct stdio to.
 * @return NULL     Writes to stdio will be discarded.
*ad*/
char * NAGetAppStdioPort(void)
{
	#ifdef APP_STDIO_PORT
		return (APP_STDIO_PORT);
	#else
		return (NULL);
	#endif
}


/*ad*
 * Returns the value of @link APP_USE_NVRAM  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return TRUE     Read and write configuration values to NVRAM.
 * @return FALSE    Use hard coded default configuration values.
*ad*/
int NAGetAppUseNvram(void)
{

	#if APP_USE_NVRAM
		return (TRUE);
	#else
		return (FALSE);
	#endif
}


/*ad*
 * Returns the value of @link APP_NET_HEAP_SIZE  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return heap-size    Size of TCP/IP buffer pool.
*ad*/
int NAGetAppNetHeapSize(void)
{
	#if  APP_NET_HEAP_SIZE
		return (APP_NET_HEAP_SIZE);
	#else
		Error: Must be defined with a value
	#endif
}

/*ad*
 * Returns the value of @link APP_ENABLE_PPP1  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return TRUE     PPP is enabled on /com/0.
 * @return FALSE    PPP is disabled on /com/0.
*ad*/
int NAGetAppEnablePPP1(void)
{
	#if APP_ENABLE_PPP1
		return (TRUE);
	#else
		return (FALSE);
	#endif
}

/*ad*
 * Returns the value of @link APP_PPP1_ADDRESS  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return address      IP address for PPP interface one.
 * @return NULL         PPP interface 1 is not configured.
*ad*/
char * NAGetAppPPP1Address(void)
{
	#ifdef APP_PPP1_ADDRESS
		return (APP_PPP1_ADDRESS);
	#else
		return (NULL);
	#endif
}


/*ad*
 * Returns the value of @link APP_PPP1_PEER_ADDRESS  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return address  IP address to assign to remote client.
 * @return NULL     PPP interface 1 is not configured.
*ad*/
char * NAGetAppPPP1PeerAddress(void)
{
	#ifdef APP_PPP1_PEER_ADDRESS
    return (APP_PPP1_PEER_ADDRESS);
	#else
		return (NULL);
	#endif
}


/*ad*
 * Returns the value of @link APP_ENABLE_PPP2  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return TRUE     PPP interface 2 is enabled on /com/1.
 * @return FALSE    PPP interface 2 is disabled.
*ad*/
int NAGetAppEnablePPP2(void)
{
	#if APP_ENABLE_PPP2
		return (TRUE);
	#else
		return (FALSE);
	#endif
}


/*ad*
 * Returns the value of @link APP_PPP2_ADDRESS   as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return address      IP address for PPP interface 2.
 * @return NULL         PPP interface 2 is not configured.
*ad*/
char * NAGetAppPPP2Address(void)
{
	#ifdef APP_PPP2_ADDRESS
		return (APP_PPP2_ADDRESS);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_PPP2_PEER_ADDRESS   as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return address      Address PPP interface 2 will assign to remote client.
 * @return NULL         PPP interface 2 is not configured.
*ad*/
char * NAGetAppPPP2PeerAddress(void)
{
	#ifdef APP_PPP2_PEER_ADDRESS
		return (APP_PPP2_PEER_ADDRESS);
	#else
		return (NULL);
	#endif
}


/*ad*
 * Returns the value of @link APP_IP_ADDRESS  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return IP-Address   Default IP address.
 * @return NULL			APP_IP_ADDRESS is not defined.
*ad*/
char * NAGetAppIpAddress(void)
{
	#ifdef APP_IP_ADDRESS
		return (APP_IP_ADDRESS);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_IP_SUBNET_MASK  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return subnet-mask  Default IP subnet mask.
 * @return NULL			APP_IP_SUBNET_MASK is not defined.
*ad*/
char * NAGetAppIpSubnetMask(void)
{
	#ifdef APP_IP_SUBNET_MASK
		return (APP_IP_SUBNET_MASK);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_IP_GATEWAY  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return gateway-address      Default gateway address.
 * @return NULL					APP_IP_GATEWAY is not defined.
*ad*/
char * NAGetAppIpGateway(void)
{
	#ifdef APP_IP_GATEWAY
		return (APP_IP_GATEWAY);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_SNTP_PRIMARY  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return IP-Address       IP Address of primary SNTP server.
 * @return NULL				APP_SNTP_PRIMARY is not defined.
*ad*/
char * NAGetAppSntpPrimary(void)
{
	#ifdef APP_SNTP_PRIMARY
		return (APP_SNTP_PRIMARY);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_SNTP_SECONDARY  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return IP-Address       IP Address of secondary SNTP server.
 * @return NULL				APP_SNTP_SECONDARY is not defined.
*ad*/
char * NAGetAppSntpSecondary(void)
{
	#ifdef APP_SNTP_SECONDARY
		return (APP_SNTP_SECONDARY);
	#else
		return (NULL);
	#endif
}


/*ad*
 * Returns the value of @link APP_BSP_SERIAL_NUM  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return serial-number    Default serial number to use if NVRAM is not initialized.
 * @return NULL				APP_BSP_SERIAL_NUM is not defined.
*ad*/
char * NAGetAppBspSerialNum(void)
{
	#ifdef APP_BSP_SERIAL_NUM
		return (APP_BSP_SERIAL_NUM);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the MAC Address set in @link APP_BSP_MAC_ADDRESS  in appconf.h.
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @see @link APP_BSP_MAC_ADDRESS
 *
 * @return APP_BSP_MAC_ADDRESS  default Ethernet MAC address set in appconf.h
 * @return NULL					APP_BSP_MAC_ADDRESS is not defined.
*ad*/

char * NAGetAppBspMacAddress(void)
{
	#ifdef APP_BSP_MAC_ADDRESS
		return (APP_BSP_MAC_ADDRESS);
	#else
		return (NULL);
	#endif
}


/*ad*
 * Returns the value of @link APP_BSP_DELAY  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return APP_BSP_DELAY        Default delay for configuration dialog.
*ad*/
int NAGetAppBspDelay(void)
{
	#ifdef APP_BSP_DELAY
		return (APP_BSP_DELAY);
	#else
		Error: Must be defined with a value
	#endif
}

/*ad*
 * Returns the value of @link APP_BSP_BAUD_RATE  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return APP_BSP_BAUD_RATE    Baud rate for configuration dialog.
*ad*/
int NAGetAppBspBaudRate(void)
{
	#ifdef APP_BSP_BAUD_RATE
		return (APP_BSP_BAUD_RATE);
	#else
		Error: Must be defined with a value
	#endif
}

/*ad*
 * Returns the value of APP_BSP_DL_BAUD_RATE if defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return APP_BSP_DL_BAUD_RATE    Baud rate for image download via the serial port
*ad*/
int NAGetAppBspDlBaudRate(void)
{
	#ifdef APP_BSP_DL_BAUD_RATE
		return (APP_BSP_DL_BAUD_RATE);
	#else
        return (APP_BSP_BAUD_RATE);
	#endif
}

/*ad*
 * Returns the value of @link APP_USE_STATIC_IP  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return TRUE     Use a static IP address.
 * @return FALSE    Get an IP address from the network with ACE.
*ad*/
int NAGetAppUseStaticIP(void)
{
    int result = FALSE;

    #ifdef APP_USE_STATIC_IP
    	#if APP_USE_STATIC_IP
    		result = TRUE;
    	#else
    		result = FALSE;
    	#endif
	#endif

	return result;
}


/*ad*
 * Returns the value of @link APP_CPP  as defined in appconf.h
 *
 * The routine calls _main() under Green Hills, if APP_CPP is defined to
 * non-zero value
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return TRUE     BSP will Initialize the C++ runtime environment.
 * @return FALSE    BSP will not initialize the C++ runtime environment.
*ad*/
int NAGetAppCpp(void)
{
#ifndef APP_CPP
#define APP_CPP     0
#endif

#if APP_CPP
#ifndef NETOS_GNU_TOOLS
	_main();                                    /* Call C++ static constructors */
#else
	/* Some arm/elf targets use the .init and .fini sections
	   to create constructors and destructors, and for these
	   targets we need to call the _init function and arrange
	   for _fini to be called at program exit.  */
	/* ThIS IS ESSENTIAL for NETOS CPP APPLICATION'S IOSTREAM*/

	atexit(_fini);
 	_init();
#endif
#endif

    return APP_CPP;
}

/*ad*
 * Returns the value of APP_DISABLE_ROUTER_ADS if defined in appconf.h
 *
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return APP_DISABLE_ROUTER_ADS Current Value of APP_DISABLE_ROUTER_ADS if defined.
 * @return 1 	Default if undefined. Router ads disabled.
*ad*/
int NAGetAppDisableRouterAds(void)
{
#ifdef APP_DISABLE_ROUTER_ADS
    return (APP_DISABLE_ROUTER_ADS);
#else
      return (1);    /* default is disabled */
#endif
}

/* Return an application-defined block count for the specified block size */
int NAInitializeTcpipBlockPool(int size, int *count)
{

#ifndef APP_TCPIP_16BYTE_BLOCK_COUNT
#define APP_TCPIP_16BYTE_BLOCK_COUNT  0
#endif

#ifndef APP_TCPIP_32BYTE_BLOCK_COUNT
#define APP_TCPIP_32BYTE_BLOCK_COUNT  0
#endif

#ifndef APP_TCPIP_64BYTE_BLOCK_COUNT
#define APP_TCPIP_64BYTE_BLOCK_COUNT  0
#endif

#ifndef APP_TCPIP_128BYTE_BLOCK_COUNT
#define APP_TCPIP_128BYTE_BLOCK_COUNT  0
#endif

#ifndef APP_TCPIP_256BYTE_BLOCK_COUNT
#define APP_TCPIP_256BYTE_BLOCK_COUNT  0
#endif

#ifndef APP_TCPIP_540BYTE_BLOCK_COUNT
#define APP_TCPIP_540BYTE_BLOCK_COUNT  0
#endif

#ifndef APP_TCPIP_1836BYTE_BLOCK_COUNT
#define APP_TCPIP_1836BYTE_BLOCK_COUNT  0
#endif

    int result = FALSE;

    if (count)
    {
        *count = 0;
        result = TRUE;

        switch(size)
        {
        case NA_TCPIP_BLOCK_SIZE_16:
            *count = APP_TCPIP_16BYTE_BLOCK_COUNT;
            break;

        case NA_TCPIP_BLOCK_SIZE_32:
            *count = APP_TCPIP_32BYTE_BLOCK_COUNT;
            break;

        case NA_TCPIP_BLOCK_SIZE_64:
            *count = APP_TCPIP_64BYTE_BLOCK_COUNT;
            break;

        case NA_TCPIP_BLOCK_SIZE_128:
            *count = APP_TCPIP_128BYTE_BLOCK_COUNT;
            break;

        case NA_TCPIP_BLOCK_SIZE_256:
            *count = APP_TCPIP_256BYTE_BLOCK_COUNT;
            break;

        case NA_TCPIP_BLOCK_SIZE_540:
            *count = APP_TCPIP_540BYTE_BLOCK_COUNT;
            break;

        case NA_TCPIP_BLOCK_SIZE_1836:
            *count = APP_TCPIP_1836BYTE_BLOCK_COUNT;
            break;

        default:
            result = FALSE;
         }
    }
    return result;
}

/*ad*
 * Returns the value of APP_WLN_IP_ADDRESS  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return APP_WLN_IP_ADDRESS   Default IP address for wireless device.
 * @return NULL					APP_WLN_IP_ADDRESS is not defined.
*ad*/
char * NAGetAppWlnIpAddress(void)
{
    #ifdef APP_WLN_IP_ADDRESS
		return (APP_WLN_IP_ADDRESS);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of APP_WLN_IP_SUBNET_MASK as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return subnet-mask  Default IP subnet mask for wireless device.
 * @return NULL			APP_WLN_IP_SUBNET_MASK is not defined.
*ad*/
char * NAGetAppWlnIpSubnetMask(void)
{
    #ifdef APP_WLN_IP_SUBNET_MASK
		return (APP_WLN_IP_SUBNET_MASK);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of APP_WLN_IP_GATEWAY  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return gateway-address      Default gateway address for wireless device.
 * @return NULL					AAPP_WLN_IP_GATEWAY is not defined.
*ad*/
char * NAGetAppWlnIpGateway(void)
{
    #ifdef APP_WLN_IP_GATEWAY
		return (APP_WLN_IP_GATEWAY);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of APP_USE_WLN_STATIC_IP  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category ApplicationConfiguration
 * @since 6.0
 *
 * @return TRUE     Use a static IP address for wireless device.
 * @return FALSE    Get an IP address from the network with ACE.
*ad*/
int NAGetAppWlnUseStaticIP(void)
{
    int result = FALSE;

    #ifdef APP_USE_WLN_STATIC_IP
    	#if APP_USE_WLN_STATIC_IP
    		result = TRUE;
    	#else
    		result = FALSE;
    	#endif
	#endif

	return result;
}


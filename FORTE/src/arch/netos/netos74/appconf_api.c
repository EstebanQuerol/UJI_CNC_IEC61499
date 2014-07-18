/*
 *  Copyright (c) 1996-2007 Digi International Inc., All Rights Reserved
 *
 *  This software contains proprietary and confidential information of Digi
 *  International Inc.  By accepting transfer of this copy, Recipient agrees
 *  to retain this software in confidence, to prevent disclosure to others,
 *  and to make no use of this software other than that for which it was
 *  delivered.  This is an unpublished copyrighted work of Digi International
 *  Inc.  Except as permitted by federal law, 17 USC 117, copying is strictly
 *  prohibited.
 *
 *  Restricted Rights Legend
 *
 *  Use, duplication, or disclosure by the Government is subject to
 *  restrictions set forth in sub-paragraph (c)(1)(ii) of The Rights in
 *  Technical Data and Computer Software clause at DFARS 252.227-7031 or
 *  subparagraphs (c)(1) and (2) of the Commercial Computer Software -
 *  Restricted Rights at 48 CFR 52.227-19, as applicable.
 *
 *  Digi International Inc. 11001 Bren Road East, Minnetonka, MN 55343
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
 * JZW  05/23/05   remove kerberos references. no longer supported
 * JZW  12/05/05   Added APP_EMAIL_WITHOUT_AWS and 3 web-associated
 *                 structures. These will be used when a customer
 *                 wants to use email APIs but whose application
 *                 does not support web access
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
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
*ad*/

#include <stdio.h>
#include <string.h>
#ifdef	__GNUC__
#include <malloc.h>
#endif
#include <Npttypes.h>
#include <appconf.h>
#include <netoserr.h>
#include "bsp_api.h"
#include "boardParams.h"
//#include "wln_api.h"
#include "appconf_api.h"

#ifdef DOTNETMF
/*
 * This is called when exception happens.
   exceptionType: indicates the type of exception handler
   exceptionType = 1: Undefined_Handler:
   exceptionType = 2: SWI_Handler:
   exceptionType = 3: Prefetch_Handler:
   exceptionType = 4: Abort_Handler:
   exceptionType = 5: Address_Error_Handler:
   exceptionType = 6: FIQ_Handler:
  *
  */
void DIGI_AbortHandler(int exceptionType)
{

}
#endif

/**
 * Returns the value of @link APP_ERROR_HANDLER  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return NULL             no user error handler is defined
 * @return otherwise        pointer to user defined error handler
**/
userErrorHandlerType NAGetAppErrorHandler(void)
{
	#ifdef APP_ERROR_HANDLER
		return (APP_ERROR_HANDLER);
	#else
		return (NULL);
	#endif
}


/*ad*
 * This routine returns the date and time the application was built on.
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.3
 *
 * @return time-date-stamp      time and date when the application was built
*ad*/
char * NAGetAppTimeStamp(void)
{
    char * result = __DATE__ " " __TIME__;

    return result;
}


/*ad*
 * Returns the value of the application @link APP_ENABLE_AUTO_IP, which determines whether
 * Auto-IP will be enabled on any network interface.  See @link APP_Interface_Values for the
 * legal range for @link APP_ENABLE_AUTO_IP.
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 * @see @link APP_ENABLE_AUTO_IP
 * @see @link APP_Interface_Values
 *
 * @return FALSE    AUTO-IP not used on any interface.
 * @return TRUE     AUTO-IP is used on at least one network interface
*ad*/
BOOLEAN NAGetEnableAutoIp(void)
{
    BOOLEAN result = APP_ON_NO_INTERFACE;

    #ifdef APP_ENABLE_AUTO_IP
        switch(APP_ENABLE_AUTO_IP)
        {
            case APP_ON_ETHERNET_INTERFACE:
            case APP_ON_WIRELESS_INTERFACE:
            case APP_ON_ALL_INTERFACES:
                result = APP_ENABLE_AUTO_IP;
                break;
            default:
                result = APP_ON_NO_INTERFACE;
                break;
        }
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * Returns the value of @link APP_ROOT_STACK_SIZE  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * Returns the value of @link BSP_DIALOG_PORT  as defined in bsp_sys.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return dialog-port     Port to use for configuration dialog.
 * @return NULL				BSP_DIALOG_PORT is undefined.
*ad*/
char * NAGetAppDialogPort(void)
{
    #ifdef APP_DIALOG_PORT
    #ifdef BSP_DIALOG_PORT
        #warning BSP_DIALOG_PORT and APP_DIALOG_PORT both defined, remove APP_DIALOG_PORT from appconf.h
    #endif
    #endif

    /* Allow the application to override the BSP define */
	#ifdef APP_DIALOG_PORT
		return (APP_DIALOG_PORT);
	#else
		return NABspGetDialogPort();
	#endif
}

/*ad*
 * Returns the value of @link APP_DIALOG_APP_NAME  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * Returns the value of @link APP_USE_NETWORK_TIME_PROTOCOL  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
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



/*
 * Returns the value of *link APP_POST  as defined in appconf.h
 *
 * *external
 * *include     "appconf_api.h"
 * *category SystemSWServices:ApplicationConfiguration
 * *since 6.0
 * *
 * *return TRUE     POST will be run at start up.
 * *return FALSE    POST will not be run at start up.
 */
int NAGetAppPost(void)
{
	#if APP_POST
		return (TRUE);
	#else
		return (FALSE);
	#endif
}


/*ad*
 * Returns the value of @link BSP_STDIO_PORT  as defined in bsp_sys.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return pointer  Null terminated string with name of port to direct stdio to.
 * @return NULL     Writes to stdio will be discarded.
*ad*/
char * NAGetAppStdioPort(void)
{
    #ifdef APP_STDIO_PORT
    #ifdef BSP_STDIO_PORT
        #warning BSP_STDIO_PORT and APP_STDIO_PORT both defined, remove APP_STDIO_PORT from appconf.h
    #endif
    #endif

    /* Allow the application to override the BSP define */
	#ifdef APP_STDIO_PORT
		return (APP_STDIO_PORT);
	#else
		return NABspGetStdioPort();
	#endif
}


/*ad*
 * Returns the value of @link APP_USE_NVRAM  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 * @see APP_USE_NVRAM_Values
 *
 * @return APP_DO_NOT_USE_NVRAM         All configuration values are to be read from appconf.h.
 * @return APP_FOR_ALL_PARAMETERS       All configuration values are to be read from NVRAM.
 * @return APP_FOR_MAC_ADDRESS_ONLY     The MAC address is to be read from NVRAM, everything else
 *                                      from appconf.h.
*ad*/
int NAGetAppUseNvram(void)
{

	#ifdef APP_USE_NVRAM
		return APP_USE_NVRAM;
	#else
		return APP_FOR_MAC_ADDRESS_ONLY;
	#endif
}


/*ad*
 * Returns the value of @link APP_NET_HEAP_SIZE  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return TRUE     PPP interface 1 is enabled.
 * @return FALSE    PPP interface 1 is disabled.
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
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return address      IP address for PPP interface 1.
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
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return address  IP address that PPP interface 1 assigns to the remote PPP peer.
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
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return TRUE     PPP interface 2 is enabled.
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return address      IP address PPP interface 2 assigns to the remote PPP peer.
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
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return IP-Address   Default IPv4 address.
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * Returns the MAC Address set in @link APP_BSP_MAC_ADDRESS in appconf.h.
 * On devices with both Ethernet and wireless interfaces, APP_BSP_MAC_ADDRESS
 * determines the Ethernet MAC address.
 *
 * Use the @link NAGetApp2ndInterfaceMacAddress function to return the
 * MAC address of the second interface on those devices with two interfaces.
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @see @link APP_BSP_MAC_ADDRESS
 * @see @link NAGetApp2ndInterfaceMacAddress
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
 * Returns the MAC Address set in @link APP_2ND_INTERFACE_MAC_ADDRESS in appconf.h.
 * APP_2ND_INTERFACE_MAC_ADDRESS is used only if the board two network interfaces.
 * For example, the connectcorewi9c_a has both an Ethernet and a wireless interface.
 * In this case, the wireless interface is the second interface.
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @see @link APP_2ND_INTERFACE_MAC_ADDRESS
 * @see @link NAGetAppBspMacAddress
 *
 * @return APP_2ND_INTERFACE_MAC_ADDRESS    default MAC address set in appconf.h
 * @return NULL					            APP_2ND_INTERFACE_MAC_ADDRESS is not defined.
*ad*/

char * NAGetApp2ndInterfaceMacAddress(void)
{
	#ifdef APP_2ND_INTERFACE_MAC_ADDRESS
		return (APP_2ND_INTERFACE_MAC_ADDRESS);
	#else
		return (NULL);
	#endif
}


/*ad*
 * Returns the value of @link APP_2ND_INTERFACE_IP_ADDRESS as defined in appconf.h.
 * This refers to the second network on those boards which have two.  For example,
 * the connectcorewi9c_a has both an Ethernet and a wireless interface.  On boards
 * like the connectcorewi9c_a with one Ethernet and one wireless interface, the
 * second interface is the wireless interface.
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return IP-Address   Default IPv4 address for second network interface.
 * @return NULL			APP_2ND_INTERFACE_IP_ADDRESS is not defined.
*ad*/
char * NAGetApp2ndInterfaceIpAddress(void)
{
	#ifdef APP_2ND_INTERFACE_IP_ADDRESS
		return (APP_2ND_INTERFACE_IP_ADDRESS);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_2ND_INTERFACE_IP_SUBNET_MASK as defined in appconf.h
 * This refers to the second network on those boards which have two.  For example,
 * the connectcorewi9c_a has both an Ethernet and a wireless interface.  On boards
 * like the connectcorewi9c_a with one Ethernet and one wireless interface, the
 * second interface is the wireless interface.
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return subnet-mask  Default IP subnet mask for second network interface.
 * @return NULL			APP_2ND_INTERFACE_IP_SUBNET_MASK is not defined.
*ad*/
char * NAGetApp2ndInterfaceIpSubnetMask(void)
{
	#ifdef APP_2ND_INTERFACE_IP_SUBNET_MASK
		return (APP_2ND_INTERFACE_IP_SUBNET_MASK);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_2ND_INTERFACE_IP_GATEWAY as defined in appconf.h
 * This refers to the second network on those boards which have two.  For example,
 * the connectcorewi9c_a has both an Ethernet and a wireless interface.  On boards
 * like the connectcorewi9c_a with one Ethernet and one wireless interface, the
 * second interface is the wireless interface.
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return gateway-address      Default gateway address for second network interface.
 * @return NULL					APP_2ND_INTERFACE_IP_GATEWAY is not defined.
*ad*/
char * NAGetApp2ndInterfaceIpGateway(void)
{
	#ifdef APP_2ND_INTERFACE_IP_GATEWAY
		return (APP_2ND_INTERFACE_IP_GATEWAY);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_IPV6_ADDRESS  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.5
 *
 * @return IPv6-Address   Default IP address.
 * @return NULL			  APP_IPV6_ADDRESS is not defined.
*ad*/
char * NAGetAppIpv6Address(void)
{
	#ifdef APP_IPV6_ADDRESS
		return (APP_IPV6_ADDRESS);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link NAGetAppIpv6PrefixLen  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.5
 *
 * @return Prefix length   Network prefix length for default IPv6 address.
 * @return 64			   APP_IPV6_PREFIX_LEN is not defined.
*ad*/
WORD8 NAGetAppIpv6PrefixLen(void)
{
	#ifdef APP_IPV6_PREFIX_LEN
		return (APP_IPV6_PREFIX_LEN);
	#else
		return (64);
	#endif
}

/*ad*
 * Returns the value of @link APP_2ND_INTERFACE_IPV6_ADDRESS as defined in appconf.h.
 * This refers to the second network on those boards which have two.  For example,
 * the connectcorewi9c_a has both an Ethernet and a wireless interface.  On boards
 * like the connectcorewi9c_a with one Ethernet and one wireless interface, the
 * second interface is the wireless interface.
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.5
 *
 * @return IPv6-Address   Default IPv6 address for second network interface.
 * @return NULL			  APP_2ND_INTERFACE_IPV6_ADDRESS is not defined.
*ad*/
char * NAGetApp2ndInterfaceIpv6Address(void)
{
	#ifdef APP_2ND_INTERFACE_IPV6_ADDRESS
		return (APP_2ND_INTERFACE_IPV6_ADDRESS);
	#else
		return (NULL);
	#endif
}

/*ad*
 * Returns the value of @link APP_2ND_INTERFACE_IPV6_PREFIX_LEN as defined in appconf.h.
 * This refers to the second network on those boards which have two.  For example,
 * the connectcorewi9c_a has both an Ethernet and a wireless interface.  On boards
 * like the connectcorewi9c_a with one Ethernet and one wireless interface, the
 * second interface is the wireless interface.
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.5
 *
 * @return Prefix length	Network prefix length for default IPv6 address for
 *							second network interface.
 * @return 64				APP_2ND_INTERFACE_IPV6_PREFIX_LEN is not defined.
*ad*/
int NAGetApp2ndInterfaceIpv6PrefixLen(void)
{
	#ifdef APP_2ND_INTERFACE_IPV6_PREFIX_LEN
		return (APP_2ND_INTERFACE_IPV6_PREFIX_LEN);
	#else
		return (64);
	#endif
}

/*ad*
 * Returns the value of @link APP_USE_STATIC_IPV6  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.5
 *
 * @return APP_ON_NO_INTERFACE           Do not use on any interface.
 * @return APP_ON_ETHERNET_INTERFACE     Use on Ethernet interface
 * @return APP_ON_WIRELESS_INTERFACE     Use on wireless interface
 * @return APP_ON_ALL_INTERFACES         Use on both Ethernet and wireless interfaces.
*ad*/
int NAGetAppUseStaticIPv6(void)
{
    int result = APP_ON_NO_INTERFACE;

    #ifdef APP_USE_STATIC_IPV6
        switch (APP_USE_STATIC_IP)
        {
            case APP_ON_NO_INTERFACE:
            case APP_ON_ETHERNET_INTERFACE:
            case APP_ON_WIRELESS_INTERFACE:
            case APP_ON_ALL_INTERFACES:
                result = APP_USE_STATIC_IP;
                break;
            default:
                result = APP_ON_NO_INTERFACE;
                break;
        }
	#endif

	return result;
}

/*ad*
 * Returns the value of @link APP_USE_DHCPV6  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.5
 *
 * @return APP_ON_NO_INTERFACE           Do not use on any interface.
 * @return APP_ON_ETHERNET_INTERFACE     Use on Ethernet interface
 * @return APP_ON_WIRELESS_INTERFACE     Use on wireless interface
 * @return APP_ON_ALL_INTERFACES         Use on both Ethernet and wireless interfaces.
*ad*/
int NAGetAppUseDhcpV6(void)
{
    int result = APP_ON_NO_INTERFACE;

    #ifdef APP_USE_DHCPV6
        switch (APP_USE_DHCPV6)
        {
            case APP_ON_NO_INTERFACE:
            case APP_ON_ETHERNET_INTERFACE:
            case APP_ON_WIRELESS_INTERFACE:
            case APP_ON_ALL_INTERFACES:
                result = APP_USE_DHCPV6;
                break;
            default:
                result = APP_ON_NO_INTERFACE;
                break;
        }
	#endif

	return result;
}

/*ad*
 * Returns the value of @link APP_BSP_DELAY  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
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
 * Returns the value of @link BSP_BAUD_RATE  as defined in bsp_sys.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return BSP_BAUD_RATE    Baud rate for configuration dialog.
*ad*/
int NAGetAppBspBaudRate(void)
{
    #ifdef APP_BSP_BAUD_RATE
    #ifdef BSP_BAUD_RATE
        #warning BSP_BAUD_RATE and APP_BSP_BAUD_RATE both defined, remove APP_BSP_BAUD_RATE from appconf.h
    #endif
    #endif

    /* Allow the application to override the BSP define */
	#ifdef APP_BSP_BAUD_RATE
		return (APP_BSP_BAUD_RATE);
	#else
		return NABspGetBaudRate();
	#endif
}


/*ad*
 * Returns the value of @link APP_USE_STATIC_IP  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 *
 * @return APP_ON_NO_INTERFACE           Do not use on any interface.
 * @return APP_ON_ETHERNET_INTERFACE     Use on Ethernet interface
 * @return APP_ON_WIRELESS_INTERFACE     Use on wireless interface
 * @return APP_ON_ALL_INTERFACES         Use on both Ethernet and wireless interfaces.
*ad*/
int NAGetAppUseStaticIP(void)
{
    int result = APP_ON_NO_INTERFACE;

    #ifdef APP_USE_STATIC_IP
        switch (APP_USE_STATIC_IP)
        {
            case APP_ON_NO_INTERFACE:
            case APP_ON_ETHERNET_INTERFACE:
            case APP_ON_WIRELESS_INTERFACE:
            case APP_ON_ALL_INTERFACES:
                result = APP_USE_STATIC_IP;
                break;
            default:
                result = APP_ON_NO_INTERFACE;
                break;
        }
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
 * @category SystemSWServices:ApplicationConfiguration
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
 * @category SystemSWServices:ApplicationConfiguration
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

/**
 * Returns the value of APP_WLN_IP_ADDRESS  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 * @deprecated 7.0
 *
 * @return APP_WLN_IP_ADDRESS   Default IP address for wireless device.
 * @return NULL					APP_WLN_IP_ADDRESS is not defined.
**/
char * NAGetAppWlnIpAddress(void)
{
    #ifdef APP_WLN_IP_ADDRESS
		return (APP_WLN_IP_ADDRESS);
	#else
		return (NULL);
	#endif
}

/**
 * Returns the value of APP_WLN_IP_SUBNET_MASK as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 * @deprecated 7.0
 *
 *
 * @return subnet-mask  Default IP subnet mask for wireless device.
 * @return NULL			APP_WLN_IP_SUBNET_MASK is not defined.
**/
char * NAGetAppWlnIpSubnetMask(void)
{
    #ifdef APP_WLN_IP_SUBNET_MASK
		return (APP_WLN_IP_SUBNET_MASK);
	#else
		return (NULL);
	#endif
}

/**
 * Returns the value of APP_WLN_IP_GATEWAY  as defined in appconf.h
 *
 * @external
 * @include     "appconf_api.h"
 * @category SystemSWServices:ApplicationConfiguration
 * @since 6.0
 * @deprecated 7.0
 *
 *
 * @return gateway-address      Default gateway address for wireless device.
 * @return NULL					AAPP_WLN_IP_GATEWAY is not defined.
**/
char * NAGetAppWlnIpGateway(void)
{
    #ifdef APP_WLN_IP_GATEWAY
		return (APP_WLN_IP_GATEWAY);
	#else
		return (NULL);
	#endif
}



#ifdef APP_EMAIL_WITHOUT_AWS
/*
 * File RpEmailStubs.c
 * Author: Jeffrey Z. Wolf
 * Date: 12/1/05
 * Purpose: Facilitates the creation of email applications that do not rely on
 * The web server for I/O. Since email uses the AWS engine for the
 * lower level email processes, some accomodations must be made. This
 * file makes those accomodations. This file should not be used if
 * your application uses both email and the AWS.
 *
 */
 char *gUserPhrasesEnglish[] = {
     ""
};

int ** gRpMasterObjectList[] = {
	(int) 0
};

void RpHSInitSecurityTable(void *serverdata)
{
    NA_UNUSED_PARAM(serverdata);  // for gnu compiler
};

#endif


/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_BSS_TYPE defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 * @see @link BSP:Device_Drivers:wireless:APP_WLN_BSS_Values
 *
 * @return APP_WLN_BSS_TYPE     Value of APP_WLN_BSS_TYPE set in appconf.h
*ad*/
wln_bss NAGetAppWlnBssType(void)
{
    #if defined(APP_WLN_BSS_TYPE) && (APP_WLN_BSS_TYPE >= APP_WLN_BSS_ESS) && (APP_WLN_BSS_TYPE <= APP_WLN_BSS_NONE)
        return (wln_bss) APP_WLN_BSS_TYPE;
    #else
        return (wln_bss) APP_WLN_BSS_ESS;
    #endif
}



/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_SSID defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 *
 * @return APP_WLN_SSID     Value of APP_WLN_SSID set in appconf.h as a nul terminated string
*ad*/
char * NAGetAppWlnSsid(void)
{
    #ifdef APP_WLN_SSID
        return APP_WLN_SSID;
    #else
        return "";
    #endif
}


/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_CHANNEL defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 *
 * @return APP_WLN_CHANNEL  Value of APP_WLN_CHANNEL set in appconf.h
*ad*/
unsigned NAGetAppWlnChannel(void)
{
    #if defined(APP_WLN_CHANNEL) && (APP_WLN_CHANNEL >= SCAN) && (APP_WLN_CHANNEL <= A165)
        return APP_WLN_CHANNEL;
    #else
        return SCAN;
    #endif
}

/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_80211_OPTIONS defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.4
 *
 * @return APP_WLN_80211_OPTIONS  Value of APP_WLN_80211_OPTIONS set in appconf.h
*ad*/
unsigned NAGetWln80211Options(void)
{
    #if defined(APP_WLN_80211_OPTIONS) && (APP_WLN_80211_OPTIONS >= APP_WLN_80211_OPTION_NONE) && (APP_WLN_80211_OPTION <= APP_WLN_80211_OPTION_SPECTRUM_MANAGEMENT)
        return APP_WLN_80211_OPTIONS;
    #else
        return APP_WLN_80211_OPTION_NONE;
    #endif
}


/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_80211_BAND defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.4
 *
 * @return APP_WLN_80211_BAND  Value of APP_WLN_80211_BAND set in appconf.h
*ad*/
unsigned NAGetWln80211Band(void)
{
    #if defined(APP_WLN_80211_BAND) && (APP_WLN_80211_BAND >= WLN_BAND_ALL) && (APP_WLN_80211_BAND < WLN_BAND_MAX)
        return APP_WLN_80211_BAND;
    #else
        return APP_WLN_80211_BAND_DEFAULT;
    #endif
}



/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_AUTHENTICATION_TYPE defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 *
 * @return APP_WLN_AUTHENTICATION_TYPE      Value of APP_WLN_AUTHENTICATION_TYPE set in appconf.h
*ad*/
unsigned NAGetAppWlnAuthenticationType(void)
{
    #if defined(APP_WLN_AUTHENTICATION_TYPE)
        return APP_WLN_AUTHENTICATION_TYPE;
    #else
        return WLN_AUTH_OPEN;
    #endif
}



/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_ENCRYPTION_TYPE defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 *
 * @return APP_WLN_ENCRYPTION_TYPE      Value of APP_WLN_ENCRYPTION_TYPE set in appconf.h
*ad*/
unsigned NAGetAppWlnEncryptionType(void)
{
    #if defined(APP_WLN_ENCRYPTION_TYPE)
        return APP_WLN_ENCRYPTION_TYPE;
    #else
        return WLN_ENCR_OPEN;
    #endif
}





/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_KEY_ID defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 *
 * @return APP_WLN_KEY_ID       Value of APP_WLN_KEY_ID set in appconf.h
*ad*/
unsigned NAGetAppWlnKeyId(void)
{
    #if defined(APP_WLN_KEY_ID) && (APP_WLN_KEY_ID >= 0) && (APP_WLN_KEY_ID < 4)
        return APP_WLN_KEY_ID;
    #else
        return 0;
    #endif
}



/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_KEY_0 to
 * @link SystemSWServices:ApplicationConfiguration:APP_WLN_KEY_3 defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 *
 * @param   keyIndex        a value between 0 and 3, which indicates which key to return.
 *
 * @return APP_WLN_KEY_X    Value of APP_WLN_KEY_0, APP_WLN_KEY_1, APP_WLN_KEY_2, or APP_WLN_KEY_3 as
 *                          a nul terminated string.
 * @return emptyString      An empty string is returned if the constant is not defined.
*ad*/
char * NAGetAppWlnKey(unsigned keyIndex)
{
    char *result = "";

    switch (keyIndex)
    {
        case 0:
            #if defined(APP_WLN_KEY_0)
                result = APP_WLN_KEY_0;
            #endif
            break;
        case 1:
            #if defined(APP_WLN_KEY_1)
                result = APP_WLN_KEY_1;
            #endif
            break;
        case 2:
            #if defined(APP_WLN_KEY_2)
                result = APP_WLN_KEY_2;
            #endif
            break;
        case 3:
            #if defined(APP_WLN_KEY_3)
                result = APP_WLN_KEY_3;
            #endif
            break;
        default:
            break;
    }

    return result;
}



/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_PASSPHRASE defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 *
 * @return APP_WLN_PASSPHRASE   nul terminated string which is value of APP_WLN_PASSPHRASE set in appconf.h
 * @return NULL                 APP_WLN_PASSPHRASE is undefined or set to NULL in appconf.h
*ad*/
char * NAGetAppWlnPassphrase(void)
{
    #if defined(APP_WLN_PASSPHRASE)
        return APP_WLN_PASSPHRASE;
    #else
        return NULL;
    #endif
}


/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_PSK defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 *
 * @return APP_WLN_PSK          nul terminated string which is value of APP_WLN_PASSPHRASE set in appconf.h
 * @return NULL                 APP_WLN_PASSPHRASE is undefined or set to NULL in appconf.h
*ad*/
char * NAGetAppWlnPsk(void)
{
    #if defined(APP_WLN_PSK)
        return APP_WLN_PSK;
    #else
        return NULL;
    #endif
}



/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_EAP_METHODS defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 *
 * @return APP_WLN_EAP_METHODS  Value of APP_WLN_EAP_METHODS set in appconf.h
*ad*/
unsigned NAGetAppWlnEapMethods(void)
{
    #if defined(APP_WLN_EAP_METHODS)
        return APP_WLN_EAP_METHODS;
    #else
        return WLN_EAP_ANY;
    #endif
}



/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_IDENTITY defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 *
 * @return APP_WLN_IDENTITY     nul terminated string which is value of APP_WLN_IDENTITY set in appconf.h
*ad*/
char * NAGetAppWlnIdentity(void)
{
    #if defined(APP_WLN_IDENTITY)
        return APP_WLN_IDENTITY;
    #else
        return "";
    #endif
}



/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_PASSWORD defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.0
 *
 * @return APP_WLN_PASSWORD     nul terminated string which is value of APP_WLN_PASSWORD set in appconf.h
*ad*/
char * NAGetAppWlnPassword(void)
{
    #if defined(APP_WLN_PASSWORD)
        return APP_WLN_PASSWORD;
    #else
        return "";
    #endif
}


/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_MANUFACTURER defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.4
 *
 * @return APP_MANUFACTURER  manufacturer name defined in appconf.h
*ad*/
char * NAGetAppManufacturer(void)
{
    #if defined(APP_MANUFACTURER)
    return APP_MANUFACTURER;
    #else
    return NULL;
    #endif

}

/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_MODEL_NAME defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.4
 *
 * @return APP_MODEL_NAME  Model name defined in appconf.h
*ad*/
char * NAGetAppModelName(void)
{
    #if defined(APP_MODEL_NAME)
    return APP_MODEL_NAME;
    #else
    return NULL;
    #endif

}

/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_MODEL_NUMBER defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.4
 *
 * @return APP_MODEL_NUMBER  Model number defined in appconf.h
*ad*/
char * NAGetAppModelNumber(void)
{
    #if defined(APP_MODEL_NUMBER)
    return APP_MODEL_NUMBER;
    #else
    return NULL;
    #endif
}

/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_DEVICE_NAME defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.4
 *
 * @return APP_DEVICE_NAME  Device name defined in appconf.h
*ad*/
char * NAGetAppDeviceName(void)
{
    #if defined(APP_DEVICE_NAME)
    return APP_DEVICE_NAME;
    #else
    return NULL;
    #endif
}

/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_DEVICE_TYPE defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.4
 *
 * @return APP_DEVICE_TYPE  Device type defined in appconf.h
*ad*/
unsigned NAGetAppDeviceType(void)
{
    #if defined(APP_DEVICE_TYPE)
    return APP_DEVICE_TYPE;
    #else
    return 0;
    #endif
}

/*ad*
 * Returns the value of @link SystemSWServices:ApplicationConfiguration:APP_WLN_COUNTRY_CODE defined in appconf.h.
 *
 * @external
 * @category SystemSWServices:ApplicationConfiguration
 * @since 7.2
 *
 * @return APP_WLN_COUNTRY_CODE     Default country code value set in appconf.h
*ad*/
unsigned long NAGetAppWlnCountryCode(void)
{
    #if defined(APP_WLN_COUNTRY_CODE)
        return APP_WLN_COUNTRY_CODE;
    #else
        return COUNTRY_UNITED_STATES;
    #endif
}


#ifndef	BOOT_LOADER
/*ad*
 * This function returns a filled-in structure with current
 * statistics on heap allocations.
 * The underlying structure and prototypes are in malloc.h
 * This is supported only in the GNU environment.
 *
 * @external
 * @include "appconf_api.h"
 * @category SystemSWServices:general_purpose
 * @since 7.4
 *
 * @param  pMS		pointer to structure to fill in
 * @return rc       0 for success, non-zero for failure
 *
 * @see @link SystemSWServices:general_purpose:NABspMallocStats
 *
*ad*/
int NABspGetHeapSnapshot(NABspMallocStats * pMS)
{
#ifdef	__GNUC__
	extern char end asm ("__end__");
	extern char  heap_limit[];
	extern unsigned long heap_adjustment;
	struct mallinfo Info;
	int rc = 0;

	Info = mallinfo();

	pMS->system = heap_limit - &end + heap_adjustment,
	pMS->arena = Info.arena;
   	pMS->ordblks = Info.ordblks;
   	pMS->hblks = Info.hblks;
	pMS->hblkhd = Info.hblkhd;
   	pMS->uordblks = Info.uordblks;
	pMS->fordblks = Info.fordblks;
   	pMS->keepcost = Info.keepcost;
#else
	int rc = 0;
#endif
	return rc;
}
#endif




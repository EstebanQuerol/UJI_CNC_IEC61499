

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Wed May 08 18:34:10 2013
 */
/* Compiler settings for .\api8070.odl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __api8070_i_h__
#define __api8070_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFCVar8070_FWD_DEFINED__
#define __IFCVar8070_FWD_DEFINED__
typedef interface IFCVar8070 IFCVar8070;
#endif 	/* __IFCVar8070_FWD_DEFINED__ */


#ifndef __IFCDualVar8070_FWD_DEFINED__
#define __IFCDualVar8070_FWD_DEFINED__
typedef interface IFCDualVar8070 IFCDualVar8070;
#endif 	/* __IFCDualVar8070_FWD_DEFINED__ */


#ifndef __IEventReport_FWD_DEFINED__
#define __IEventReport_FWD_DEFINED__
typedef interface IEventReport IEventReport;
#endif 	/* __IEventReport_FWD_DEFINED__ */


#ifndef __CNC8070_Variables_FWD_DEFINED__
#define __CNC8070_Variables_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_Variables CNC8070_Variables;
#else
typedef struct CNC8070_Variables CNC8070_Variables;
#endif /* __cplusplus */

#endif 	/* __CNC8070_Variables_FWD_DEFINED__ */


#ifndef __IFCUtil8070_FWD_DEFINED__
#define __IFCUtil8070_FWD_DEFINED__
typedef interface IFCUtil8070 IFCUtil8070;
#endif 	/* __IFCUtil8070_FWD_DEFINED__ */


#ifndef __IFCDualUtil8070_FWD_DEFINED__
#define __IFCDualUtil8070_FWD_DEFINED__
typedef interface IFCDualUtil8070 IFCDualUtil8070;
#endif 	/* __IFCDualUtil8070_FWD_DEFINED__ */


#ifndef __CNC8070_Utilities_FWD_DEFINED__
#define __CNC8070_Utilities_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_Utilities CNC8070_Utilities;
#else
typedef struct CNC8070_Utilities CNC8070_Utilities;
#endif /* __cplusplus */

#endif 	/* __CNC8070_Utilities_FWD_DEFINED__ */


#ifndef __IFCError_FWD_DEFINED__
#define __IFCError_FWD_DEFINED__
typedef interface IFCError IFCError;
#endif 	/* __IFCError_FWD_DEFINED__ */


#ifndef __IFCDualError_FWD_DEFINED__
#define __IFCDualError_FWD_DEFINED__
typedef interface IFCDualError IFCDualError;
#endif 	/* __IFCDualError_FWD_DEFINED__ */


#ifndef __CNC8070_Error_FWD_DEFINED__
#define __CNC8070_Error_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_Error CNC8070_Error;
#else
typedef struct CNC8070_Error CNC8070_Error;
#endif /* __cplusplus */

#endif 	/* __CNC8070_Error_FWD_DEFINED__ */


#ifndef __IFCKernel8070_FWD_DEFINED__
#define __IFCKernel8070_FWD_DEFINED__
typedef interface IFCKernel8070 IFCKernel8070;
#endif 	/* __IFCKernel8070_FWD_DEFINED__ */


#ifndef __IInitKernelReport_FWD_DEFINED__
#define __IInitKernelReport_FWD_DEFINED__
typedef interface IInitKernelReport IInitKernelReport;
#endif 	/* __IInitKernelReport_FWD_DEFINED__ */


#ifndef __IFCDualKernel8070_FWD_DEFINED__
#define __IFCDualKernel8070_FWD_DEFINED__
typedef interface IFCDualKernel8070 IFCDualKernel8070;
#endif 	/* __IFCDualKernel8070_FWD_DEFINED__ */


#ifndef __CNC8070_Kernel_FWD_DEFINED__
#define __CNC8070_Kernel_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_Kernel CNC8070_Kernel;
#else
typedef struct CNC8070_Kernel CNC8070_Kernel;
#endif /* __cplusplus */

#endif 	/* __CNC8070_Kernel_FWD_DEFINED__ */


#ifndef __IFCAxes8070_FWD_DEFINED__
#define __IFCAxes8070_FWD_DEFINED__
typedef interface IFCAxes8070 IFCAxes8070;
#endif 	/* __IFCAxes8070_FWD_DEFINED__ */


#ifndef __IFCDualAxes8070_FWD_DEFINED__
#define __IFCDualAxes8070_FWD_DEFINED__
typedef interface IFCDualAxes8070 IFCDualAxes8070;
#endif 	/* __IFCDualAxes8070_FWD_DEFINED__ */


#ifndef __IEventAxesReport_FWD_DEFINED__
#define __IEventAxesReport_FWD_DEFINED__
typedef interface IEventAxesReport IEventAxesReport;
#endif 	/* __IEventAxesReport_FWD_DEFINED__ */


#ifndef __CNC8070_Axes_FWD_DEFINED__
#define __CNC8070_Axes_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_Axes CNC8070_Axes;
#else
typedef struct CNC8070_Axes CNC8070_Axes;
#endif /* __cplusplus */

#endif 	/* __CNC8070_Axes_FWD_DEFINED__ */


#ifndef __IFCProcessExpression_FWD_DEFINED__
#define __IFCProcessExpression_FWD_DEFINED__
typedef interface IFCProcessExpression IFCProcessExpression;
#endif 	/* __IFCProcessExpression_FWD_DEFINED__ */


#ifndef __IFCDualProcessExpression_FWD_DEFINED__
#define __IFCDualProcessExpression_FWD_DEFINED__
typedef interface IFCDualProcessExpression IFCDualProcessExpression;
#endif 	/* __IFCDualProcessExpression_FWD_DEFINED__ */


#ifndef __IEventProcessExpressionReport_FWD_DEFINED__
#define __IEventProcessExpressionReport_FWD_DEFINED__
typedef interface IEventProcessExpressionReport IEventProcessExpressionReport;
#endif 	/* __IEventProcessExpressionReport_FWD_DEFINED__ */


#ifndef __FCProcessExpression_FWD_DEFINED__
#define __FCProcessExpression_FWD_DEFINED__

#ifdef __cplusplus
typedef class FCProcessExpression FCProcessExpression;
#else
typedef struct FCProcessExpression FCProcessExpression;
#endif /* __cplusplus */

#endif 	/* __FCProcessExpression_FWD_DEFINED__ */


#ifndef __IFCReport_FWD_DEFINED__
#define __IFCReport_FWD_DEFINED__
typedef interface IFCReport IFCReport;
#endif 	/* __IFCReport_FWD_DEFINED__ */


#ifndef __FCReport_FWD_DEFINED__
#define __FCReport_FWD_DEFINED__

#ifdef __cplusplus
typedef class FCReport FCReport;
#else
typedef struct FCReport FCReport;
#endif /* __cplusplus */

#endif 	/* __FCReport_FWD_DEFINED__ */


#ifndef __IFCGrafData_FWD_DEFINED__
#define __IFCGrafData_FWD_DEFINED__
typedef interface IFCGrafData IFCGrafData;
#endif 	/* __IFCGrafData_FWD_DEFINED__ */


#ifndef __IFCDualGrafData_FWD_DEFINED__
#define __IFCDualGrafData_FWD_DEFINED__
typedef interface IFCDualGrafData IFCDualGrafData;
#endif 	/* __IFCDualGrafData_FWD_DEFINED__ */


#ifndef __CNC8070_GrafData_FWD_DEFINED__
#define __CNC8070_GrafData_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_GrafData CNC8070_GrafData;
#else
typedef struct CNC8070_GrafData CNC8070_GrafData;
#endif /* __cplusplus */

#endif 	/* __CNC8070_GrafData_FWD_DEFINED__ */


#ifndef __IFCPlc_FWD_DEFINED__
#define __IFCPlc_FWD_DEFINED__
typedef interface IFCPlc IFCPlc;
#endif 	/* __IFCPlc_FWD_DEFINED__ */


#ifndef __ICYStartReport_FWD_DEFINED__
#define __ICYStartReport_FWD_DEFINED__
typedef interface ICYStartReport ICYStartReport;
#endif 	/* __ICYStartReport_FWD_DEFINED__ */


#ifndef __IFCDualPlc_FWD_DEFINED__
#define __IFCDualPlc_FWD_DEFINED__
typedef interface IFCDualPlc IFCDualPlc;
#endif 	/* __IFCDualPlc_FWD_DEFINED__ */


#ifndef __CNC8070_Plc_FWD_DEFINED__
#define __CNC8070_Plc_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_Plc CNC8070_Plc;
#else
typedef struct CNC8070_Plc CNC8070_Plc;
#endif /* __cplusplus */

#endif 	/* __CNC8070_Plc_FWD_DEFINED__ */


#ifndef __IFCApiFixtureTable_FWD_DEFINED__
#define __IFCApiFixtureTable_FWD_DEFINED__
typedef interface IFCApiFixtureTable IFCApiFixtureTable;
#endif 	/* __IFCApiFixtureTable_FWD_DEFINED__ */


#ifndef __IFCDualApiFixtureTable_FWD_DEFINED__
#define __IFCDualApiFixtureTable_FWD_DEFINED__
typedef interface IFCDualApiFixtureTable IFCDualApiFixtureTable;
#endif 	/* __IFCDualApiFixtureTable_FWD_DEFINED__ */


#ifndef __IFixtureReport_FWD_DEFINED__
#define __IFixtureReport_FWD_DEFINED__
typedef interface IFixtureReport IFixtureReport;
#endif 	/* __IFixtureReport_FWD_DEFINED__ */


#ifndef __CNC8070_FixtureTable_FWD_DEFINED__
#define __CNC8070_FixtureTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_FixtureTable CNC8070_FixtureTable;
#else
typedef struct CNC8070_FixtureTable CNC8070_FixtureTable;
#endif /* __cplusplus */

#endif 	/* __CNC8070_FixtureTable_FWD_DEFINED__ */


#ifndef __IFCApiOriginTable_FWD_DEFINED__
#define __IFCApiOriginTable_FWD_DEFINED__
typedef interface IFCApiOriginTable IFCApiOriginTable;
#endif 	/* __IFCApiOriginTable_FWD_DEFINED__ */


#ifndef __IFCDualApiOriginTable_FWD_DEFINED__
#define __IFCDualApiOriginTable_FWD_DEFINED__
typedef interface IFCDualApiOriginTable IFCDualApiOriginTable;
#endif 	/* __IFCDualApiOriginTable_FWD_DEFINED__ */


#ifndef __IOriginReport_FWD_DEFINED__
#define __IOriginReport_FWD_DEFINED__
typedef interface IOriginReport IOriginReport;
#endif 	/* __IOriginReport_FWD_DEFINED__ */


#ifndef __CNC8070_OriginTable_FWD_DEFINED__
#define __CNC8070_OriginTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_OriginTable CNC8070_OriginTable;
#else
typedef struct CNC8070_OriginTable CNC8070_OriginTable;
#endif /* __cplusplus */

#endif 	/* __CNC8070_OriginTable_FWD_DEFINED__ */


#ifndef __IFCApiPParamTable_FWD_DEFINED__
#define __IFCApiPParamTable_FWD_DEFINED__
typedef interface IFCApiPParamTable IFCApiPParamTable;
#endif 	/* __IFCApiPParamTable_FWD_DEFINED__ */


#ifndef __IFCDualApiPParamTable_FWD_DEFINED__
#define __IFCDualApiPParamTable_FWD_DEFINED__
typedef interface IFCDualApiPParamTable IFCDualApiPParamTable;
#endif 	/* __IFCDualApiPParamTable_FWD_DEFINED__ */


#ifndef __IPParamReport_FWD_DEFINED__
#define __IPParamReport_FWD_DEFINED__
typedef interface IPParamReport IPParamReport;
#endif 	/* __IPParamReport_FWD_DEFINED__ */


#ifndef __CNC8070_PParamTable_FWD_DEFINED__
#define __CNC8070_PParamTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_PParamTable CNC8070_PParamTable;
#else
typedef struct CNC8070_PParamTable CNC8070_PParamTable;
#endif /* __cplusplus */

#endif 	/* __CNC8070_PParamTable_FWD_DEFINED__ */


#ifndef __IFCDualITool_FWD_DEFINED__
#define __IFCDualITool_FWD_DEFINED__
typedef interface IFCDualITool IFCDualITool;
#endif 	/* __IFCDualITool_FWD_DEFINED__ */


#ifndef __IFCDualIEdge_FWD_DEFINED__
#define __IFCDualIEdge_FWD_DEFINED__
typedef interface IFCDualIEdge IFCDualIEdge;
#endif 	/* __IFCDualIEdge_FWD_DEFINED__ */


#ifndef __IFCTTable_FWD_DEFINED__
#define __IFCTTable_FWD_DEFINED__
typedef interface IFCTTable IFCTTable;
#endif 	/* __IFCTTable_FWD_DEFINED__ */


#ifndef __IFCDualTTable_FWD_DEFINED__
#define __IFCDualTTable_FWD_DEFINED__
typedef interface IFCDualTTable IFCDualTTable;
#endif 	/* __IFCDualTTable_FWD_DEFINED__ */


#ifndef __IToolReport_FWD_DEFINED__
#define __IToolReport_FWD_DEFINED__
typedef interface IToolReport IToolReport;
#endif 	/* __IToolReport_FWD_DEFINED__ */


#ifndef __CNC8070_TTable_FWD_DEFINED__
#define __CNC8070_TTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_TTable CNC8070_TTable;
#else
typedef struct CNC8070_TTable CNC8070_TTable;
#endif /* __cplusplus */

#endif 	/* __CNC8070_TTable_FWD_DEFINED__ */


#ifndef __IFCITool_FWD_DEFINED__
#define __IFCITool_FWD_DEFINED__
typedef interface IFCITool IFCITool;
#endif 	/* __IFCITool_FWD_DEFINED__ */


#ifndef __CNC8070_Tool_FWD_DEFINED__
#define __CNC8070_Tool_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_Tool CNC8070_Tool;
#else
typedef struct CNC8070_Tool CNC8070_Tool;
#endif /* __cplusplus */

#endif 	/* __CNC8070_Tool_FWD_DEFINED__ */


#ifndef __IFCIEdge_FWD_DEFINED__
#define __IFCIEdge_FWD_DEFINED__
typedef interface IFCIEdge IFCIEdge;
#endif 	/* __IFCIEdge_FWD_DEFINED__ */


#ifndef __CNC8070_Edge_FWD_DEFINED__
#define __CNC8070_Edge_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_Edge CNC8070_Edge;
#else
typedef struct CNC8070_Edge CNC8070_Edge;
#endif /* __cplusplus */

#endif 	/* __CNC8070_Edge_FWD_DEFINED__ */


#ifndef __IFCDualIPlaceStorage_FWD_DEFINED__
#define __IFCDualIPlaceStorage_FWD_DEFINED__
typedef interface IFCDualIPlaceStorage IFCDualIPlaceStorage;
#endif 	/* __IFCDualIPlaceStorage_FWD_DEFINED__ */


#ifndef __IDualIMzInfor_FWD_DEFINED__
#define __IDualIMzInfor_FWD_DEFINED__
typedef interface IDualIMzInfor IDualIMzInfor;
#endif 	/* __IDualIMzInfor_FWD_DEFINED__ */


#ifndef __IFCTMagazine_FWD_DEFINED__
#define __IFCTMagazine_FWD_DEFINED__
typedef interface IFCTMagazine IFCTMagazine;
#endif 	/* __IFCTMagazine_FWD_DEFINED__ */


#ifndef __IFCDualTMagazine_FWD_DEFINED__
#define __IFCDualTMagazine_FWD_DEFINED__
typedef interface IFCDualTMagazine IFCDualTMagazine;
#endif 	/* __IFCDualTMagazine_FWD_DEFINED__ */


#ifndef __IMagazineReport_FWD_DEFINED__
#define __IMagazineReport_FWD_DEFINED__
typedef interface IMagazineReport IMagazineReport;
#endif 	/* __IMagazineReport_FWD_DEFINED__ */


#ifndef __CNC8070_MagazineTable_FWD_DEFINED__
#define __CNC8070_MagazineTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_MagazineTable CNC8070_MagazineTable;
#else
typedef struct CNC8070_MagazineTable CNC8070_MagazineTable;
#endif /* __cplusplus */

#endif 	/* __CNC8070_MagazineTable_FWD_DEFINED__ */


#ifndef __IFCIPlaceStorage_FWD_DEFINED__
#define __IFCIPlaceStorage_FWD_DEFINED__
typedef interface IFCIPlaceStorage IFCIPlaceStorage;
#endif 	/* __IFCIPlaceStorage_FWD_DEFINED__ */


#ifndef __CNC8070_PlaceStorage_FWD_DEFINED__
#define __CNC8070_PlaceStorage_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_PlaceStorage CNC8070_PlaceStorage;
#else
typedef struct CNC8070_PlaceStorage CNC8070_PlaceStorage;
#endif /* __cplusplus */

#endif 	/* __CNC8070_PlaceStorage_FWD_DEFINED__ */


#ifndef __IMzInfor_FWD_DEFINED__
#define __IMzInfor_FWD_DEFINED__
typedef interface IMzInfor IMzInfor;
#endif 	/* __IMzInfor_FWD_DEFINED__ */


#ifndef __CNC8070_MzInfor_FWD_DEFINED__
#define __CNC8070_MzInfor_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_MzInfor CNC8070_MzInfor;
#else
typedef struct CNC8070_MzInfor CNC8070_MzInfor;
#endif /* __cplusplus */

#endif 	/* __CNC8070_MzInfor_FWD_DEFINED__ */


#ifndef __IFCApiTables_FWD_DEFINED__
#define __IFCApiTables_FWD_DEFINED__
typedef interface IFCApiTables IFCApiTables;
#endif 	/* __IFCApiTables_FWD_DEFINED__ */


#ifndef __IDualApiTables_FWD_DEFINED__
#define __IDualApiTables_FWD_DEFINED__
typedef interface IDualApiTables IDualApiTables;
#endif 	/* __IDualApiTables_FWD_DEFINED__ */


#ifndef __CNC8070_ApiTables_FWD_DEFINED__
#define __CNC8070_ApiTables_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_ApiTables CNC8070_ApiTables;
#else
typedef struct CNC8070_ApiTables CNC8070_ApiTables;
#endif /* __cplusplus */

#endif 	/* __CNC8070_ApiTables_FWD_DEFINED__ */


#ifndef __IFCParameter_FWD_DEFINED__
#define __IFCParameter_FWD_DEFINED__
typedef interface IFCParameter IFCParameter;
#endif 	/* __IFCParameter_FWD_DEFINED__ */


#ifndef __IDualParameter_FWD_DEFINED__
#define __IDualParameter_FWD_DEFINED__
typedef interface IDualParameter IDualParameter;
#endif 	/* __IDualParameter_FWD_DEFINED__ */


#ifndef __CNC8070_Parameter_FWD_DEFINED__
#define __CNC8070_Parameter_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_Parameter CNC8070_Parameter;
#else
typedef struct CNC8070_Parameter CNC8070_Parameter;
#endif /* __cplusplus */

#endif 	/* __CNC8070_Parameter_FWD_DEFINED__ */


#ifndef __IFCParameterTable_FWD_DEFINED__
#define __IFCParameterTable_FWD_DEFINED__
typedef interface IFCParameterTable IFCParameterTable;
#endif 	/* __IFCParameterTable_FWD_DEFINED__ */


#ifndef __IDualParameterTable_FWD_DEFINED__
#define __IDualParameterTable_FWD_DEFINED__
typedef interface IDualParameterTable IDualParameterTable;
#endif 	/* __IDualParameterTable_FWD_DEFINED__ */


#ifndef __CNC8070_ParameterTable_FWD_DEFINED__
#define __CNC8070_ParameterTable_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_ParameterTable CNC8070_ParameterTable;
#else
typedef struct CNC8070_ParameterTable CNC8070_ParameterTable;
#endif /* __cplusplus */

#endif 	/* __CNC8070_ParameterTable_FWD_DEFINED__ */


#ifndef __IFCMachineParameters_FWD_DEFINED__
#define __IFCMachineParameters_FWD_DEFINED__
typedef interface IFCMachineParameters IFCMachineParameters;
#endif 	/* __IFCMachineParameters_FWD_DEFINED__ */


#ifndef __IFCDualMachineParameters_FWD_DEFINED__
#define __IFCDualMachineParameters_FWD_DEFINED__
typedef interface IFCDualMachineParameters IFCDualMachineParameters;
#endif 	/* __IFCDualMachineParameters_FWD_DEFINED__ */


#ifndef __CNC8070_MachineParameters_FWD_DEFINED__
#define __CNC8070_MachineParameters_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_MachineParameters CNC8070_MachineParameters;
#else
typedef struct CNC8070_MachineParameters CNC8070_MachineParameters;
#endif /* __cplusplus */

#endif 	/* __CNC8070_MachineParameters_FWD_DEFINED__ */


#ifndef __IFCJog_FWD_DEFINED__
#define __IFCJog_FWD_DEFINED__
typedef interface IFCJog IFCJog;
#endif 	/* __IFCJog_FWD_DEFINED__ */


#ifndef __IJogKeyReport_FWD_DEFINED__
#define __IJogKeyReport_FWD_DEFINED__
typedef interface IJogKeyReport IJogKeyReport;
#endif 	/* __IJogKeyReport_FWD_DEFINED__ */


#ifndef __IFCDualJog_FWD_DEFINED__
#define __IFCDualJog_FWD_DEFINED__
typedef interface IFCDualJog IFCDualJog;
#endif 	/* __IFCDualJog_FWD_DEFINED__ */


#ifndef __CNC8070_Jog_FWD_DEFINED__
#define __CNC8070_Jog_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_Jog CNC8070_Jog;
#else
typedef struct CNC8070_Jog CNC8070_Jog;
#endif /* __cplusplus */

#endif 	/* __CNC8070_Jog_FWD_DEFINED__ */


#ifndef __IFCKernelMParam_FWD_DEFINED__
#define __IFCKernelMParam_FWD_DEFINED__
typedef interface IFCKernelMParam IFCKernelMParam;
#endif 	/* __IFCKernelMParam_FWD_DEFINED__ */


#ifndef __IFCDualKernelMParam_FWD_DEFINED__
#define __IFCDualKernelMParam_FWD_DEFINED__
typedef interface IFCDualKernelMParam IFCDualKernelMParam;
#endif 	/* __IFCDualKernelMParam_FWD_DEFINED__ */


#ifndef __CNC8070_KernelMParam_FWD_DEFINED__
#define __CNC8070_KernelMParam_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_KernelMParam CNC8070_KernelMParam;
#else
typedef struct CNC8070_KernelMParam CNC8070_KernelMParam;
#endif /* __cplusplus */

#endif 	/* __CNC8070_KernelMParam_FWD_DEFINED__ */


#ifndef __IFCOpcServer_FWD_DEFINED__
#define __IFCOpcServer_FWD_DEFINED__
typedef interface IFCOpcServer IFCOpcServer;
#endif 	/* __IFCOpcServer_FWD_DEFINED__ */


#ifndef __IFCDualOpcServer_FWD_DEFINED__
#define __IFCDualOpcServer_FWD_DEFINED__
typedef interface IFCDualOpcServer IFCDualOpcServer;
#endif 	/* __IFCDualOpcServer_FWD_DEFINED__ */


#ifndef __CNC8070_OpcServer_FWD_DEFINED__
#define __CNC8070_OpcServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_OpcServer CNC8070_OpcServer;
#else
typedef struct CNC8070_OpcServer CNC8070_OpcServer;
#endif /* __cplusplus */

#endif 	/* __CNC8070_OpcServer_FWD_DEFINED__ */


#ifndef __IFCSintaxFun_FWD_DEFINED__
#define __IFCSintaxFun_FWD_DEFINED__
typedef interface IFCSintaxFun IFCSintaxFun;
#endif 	/* __IFCSintaxFun_FWD_DEFINED__ */


#ifndef __IFCDualSintaxFun_FWD_DEFINED__
#define __IFCDualSintaxFun_FWD_DEFINED__
typedef interface IFCDualSintaxFun IFCDualSintaxFun;
#endif 	/* __IFCDualSintaxFun_FWD_DEFINED__ */


#ifndef __CNC8070_SintaxFun_FWD_DEFINED__
#define __CNC8070_SintaxFun_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_SintaxFun CNC8070_SintaxFun;
#else
typedef struct CNC8070_SintaxFun CNC8070_SintaxFun;
#endif /* __cplusplus */

#endif 	/* __CNC8070_SintaxFun_FWD_DEFINED__ */


#ifndef __IFCOsc8070_FWD_DEFINED__
#define __IFCOsc8070_FWD_DEFINED__
typedef interface IFCOsc8070 IFCOsc8070;
#endif 	/* __IFCOsc8070_FWD_DEFINED__ */


#ifndef __IFCDualOsc8070_FWD_DEFINED__
#define __IFCDualOsc8070_FWD_DEFINED__
typedef interface IFCDualOsc8070 IFCDualOsc8070;
#endif 	/* __IFCDualOsc8070_FWD_DEFINED__ */


#ifndef __CNC8070_Oscilloscope_FWD_DEFINED__
#define __CNC8070_Oscilloscope_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_Oscilloscope CNC8070_Oscilloscope;
#else
typedef struct CNC8070_Oscilloscope CNC8070_Oscilloscope;
#endif /* __cplusplus */

#endif 	/* __CNC8070_Oscilloscope_FWD_DEFINED__ */


#ifndef __IFCRemoteVar8070_FWD_DEFINED__
#define __IFCRemoteVar8070_FWD_DEFINED__
typedef interface IFCRemoteVar8070 IFCRemoteVar8070;
#endif 	/* __IFCRemoteVar8070_FWD_DEFINED__ */


#ifndef __IFCDualRemoteVar8070_FWD_DEFINED__
#define __IFCDualRemoteVar8070_FWD_DEFINED__
typedef interface IFCDualRemoteVar8070 IFCDualRemoteVar8070;
#endif 	/* __IFCDualRemoteVar8070_FWD_DEFINED__ */


#ifndef __CNC8070_RemoteVariables_FWD_DEFINED__
#define __CNC8070_RemoteVariables_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_RemoteVariables CNC8070_RemoteVariables;
#else
typedef struct CNC8070_RemoteVariables CNC8070_RemoteVariables;
#endif /* __cplusplus */

#endif 	/* __CNC8070_RemoteVariables_FWD_DEFINED__ */


#ifndef __IFCHelpEditctrl_FWD_DEFINED__
#define __IFCHelpEditctrl_FWD_DEFINED__
typedef interface IFCHelpEditctrl IFCHelpEditctrl;
#endif 	/* __IFCHelpEditctrl_FWD_DEFINED__ */


#ifndef __IFCDualHelpEditctrl_FWD_DEFINED__
#define __IFCDualHelpEditctrl_FWD_DEFINED__
typedef interface IFCDualHelpEditctrl IFCDualHelpEditctrl;
#endif 	/* __IFCDualHelpEditctrl_FWD_DEFINED__ */


#ifndef __CNC8070_HelpEditctrl_FWD_DEFINED__
#define __CNC8070_HelpEditctrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_HelpEditctrl CNC8070_HelpEditctrl;
#else
typedef struct CNC8070_HelpEditctrl CNC8070_HelpEditctrl;
#endif /* __cplusplus */

#endif 	/* __CNC8070_HelpEditctrl_FWD_DEFINED__ */


#ifndef __IFCKeystrokeEngine_FWD_DEFINED__
#define __IFCKeystrokeEngine_FWD_DEFINED__
typedef interface IFCKeystrokeEngine IFCKeystrokeEngine;
#endif 	/* __IFCKeystrokeEngine_FWD_DEFINED__ */


#ifndef __IFCDualKeystrokeEngine_FWD_DEFINED__
#define __IFCDualKeystrokeEngine_FWD_DEFINED__
typedef interface IFCDualKeystrokeEngine IFCDualKeystrokeEngine;
#endif 	/* __IFCDualKeystrokeEngine_FWD_DEFINED__ */


#ifndef __CNC8070_KeystrokeEngine_FWD_DEFINED__
#define __CNC8070_KeystrokeEngine_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_KeystrokeEngine CNC8070_KeystrokeEngine;
#else
typedef struct CNC8070_KeystrokeEngine CNC8070_KeystrokeEngine;
#endif /* __cplusplus */

#endif 	/* __CNC8070_KeystrokeEngine_FWD_DEFINED__ */


#ifndef __IFCAutoAdjust_FWD_DEFINED__
#define __IFCAutoAdjust_FWD_DEFINED__
typedef interface IFCAutoAdjust IFCAutoAdjust;
#endif 	/* __IFCAutoAdjust_FWD_DEFINED__ */


#ifndef __IFCDualAutoAdjust_FWD_DEFINED__
#define __IFCDualAutoAdjust_FWD_DEFINED__
typedef interface IFCDualAutoAdjust IFCDualAutoAdjust;
#endif 	/* __IFCDualAutoAdjust_FWD_DEFINED__ */


#ifndef __IEventAutoAdjustReport_FWD_DEFINED__
#define __IEventAutoAdjustReport_FWD_DEFINED__
typedef interface IEventAutoAdjustReport IEventAutoAdjustReport;
#endif 	/* __IEventAutoAdjustReport_FWD_DEFINED__ */


#ifndef __CNC8070_FCAutoAdjust_FWD_DEFINED__
#define __CNC8070_FCAutoAdjust_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_FCAutoAdjust CNC8070_FCAutoAdjust;
#else
typedef struct CNC8070_FCAutoAdjust CNC8070_FCAutoAdjust;
#endif /* __cplusplus */

#endif 	/* __CNC8070_FCAutoAdjust_FWD_DEFINED__ */


#ifndef __IFCF3DGrafCtrlHandles_FWD_DEFINED__
#define __IFCF3DGrafCtrlHandles_FWD_DEFINED__
typedef interface IFCF3DGrafCtrlHandles IFCF3DGrafCtrlHandles;
#endif 	/* __IFCF3DGrafCtrlHandles_FWD_DEFINED__ */


#ifndef __IFCDualF3DGrafCtrlHandles_FWD_DEFINED__
#define __IFCDualF3DGrafCtrlHandles_FWD_DEFINED__
typedef interface IFCDualF3DGrafCtrlHandles IFCDualF3DGrafCtrlHandles;
#endif 	/* __IFCDualF3DGrafCtrlHandles_FWD_DEFINED__ */


#ifndef __CNC8070_FCF3DGrafCtrlHandles_FWD_DEFINED__
#define __CNC8070_FCF3DGrafCtrlHandles_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNC8070_FCF3DGrafCtrlHandles CNC8070_FCF3DGrafCtrlHandles;
#else
typedef struct CNC8070_FCF3DGrafCtrlHandles CNC8070_FCF3DGrafCtrlHandles;
#endif /* __cplusplus */

#endif 	/* __CNC8070_FCF3DGrafCtrlHandles_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __Api8070_LIBRARY_DEFINED__
#define __Api8070_LIBRARY_DEFINED__

/* library Api8070 */
/* [version][uuid] */ 


#define	MAX_SIZE_NAME_VAR	( 63 )

#define	NO_HVAR_INDEX	( -1 )

#define	NULL_BSTR	( 0 )

#define	INIT_ERROR_PHASE	( 0 )

#define	INIT_KERNEL_PHASE	( 1 )

#define	INIT_VARREPORT_PHASE	( 2 )

#define	INIT_PARAM_PHASE	( 3 )

#pragma once
typedef 
enum PPARAM_TABLE_TYPE_ST
    {	LOCAL	= 0,
	COMMON	= LOCAL + 1,
	GLOBAL	= COMMON + 1
    } 	PPARAM_TABLE_TYPE_T;

#pragma once				
#pragma once
typedef 
enum __MIDL___MIDL_itf_api8070_0000_0001
    {	FLANCO_SUBIDA_EXP	= 1,
	FLANCO_BAJADA_EXP	= 2
    } 	TIPOFLANCO_T;

typedef long HVAR;

#define	INVALID_HVAR	( -1 )

typedef 
enum JOGKEY_REPORT_ST
    {	JOG_USERKEY1	= 0,
	JOG_USERKEY2	= JOG_USERKEY1 + 1,
	JOG_USERKEY3	= JOG_USERKEY2 + 1,
	JOG_USERKEY4	= JOG_USERKEY3 + 1,
	JOG_USERKEY5	= JOG_USERKEY4 + 1,
	JOG_USERKEY6	= JOG_USERKEY5 + 1,
	JOG_USERKEY7	= JOG_USERKEY6 + 1,
	JOG_USERKEY8	= JOG_USERKEY7 + 1,
	JOG_USERKEY9	= JOG_USERKEY8 + 1,
	JOG_USERKEY10	= JOG_USERKEY9 + 1,
	JOG_USERKEY11	= JOG_USERKEY10 + 1,
	JOG_USERKEY12	= JOG_USERKEY11 + 1,
	JOG_USERKEY13	= JOG_USERKEY12 + 1,
	JOG_USERKEY14	= JOG_USERKEY13 + 1,
	JOG_USERKEY15	= JOG_USERKEY14 + 1,
	JOG_USERKEY16	= JOG_USERKEY15 + 1,
	JOG_MOVEKEY0	= JOG_USERKEY16 + 1,
	JOG_MOVEKEY1	= JOG_MOVEKEY0 + 1,
	JOG_MOVEKEY2	= JOG_MOVEKEY1 + 1,
	JOG_MOVEKEY3	= JOG_MOVEKEY2 + 1,
	JOG_MOVEKEY4	= JOG_MOVEKEY3 + 1,
	JOG_MOVEKEY5	= JOG_MOVEKEY4 + 1,
	JOG_MOVEKEY6	= JOG_MOVEKEY5 + 1,
	JOG_MOVEKEY7	= JOG_MOVEKEY6 + 1,
	JOG_MOVEKEY8	= JOG_MOVEKEY7 + 1,
	JOG_MOVEKEY9	= JOG_MOVEKEY8 + 1,
	JOG_MOVEKEY10	= JOG_MOVEKEY9 + 1,
	JOG_MOVEKEY11	= JOG_MOVEKEY10 + 1,
	JOG_MOVEKEY12	= JOG_MOVEKEY11 + 1,
	JOG_MOVEKEY13	= JOG_MOVEKEY12 + 1,
	JOG_MOVEKEY14	= JOG_MOVEKEY13 + 1,
	JOG_M3	= JOG_MOVEKEY14 + 1,
	JOG_SR_MINUS	= JOG_M3 + 1,
	JOG_M19	= JOG_SR_MINUS + 1,
	JOG_M5	= JOG_M19 + 1,
	JOG_SR_PLUS	= JOG_M5 + 1,
	JOG_M4	= JOG_SR_PLUS + 1,
	JOG_START	= JOG_M4 + 1,
	JOG_STOP	= JOG_START + 1,
	JOG_ZEROSEARCH	= JOG_STOP + 1,
	JOG_SBLOCK	= JOG_ZEROSEARCH + 1,
	JOG_RESET	= JOG_SBLOCK + 1,
	JOG_OVR_POS	= JOG_RESET + 1,
	JOG_MANUAL_MODE	= JOG_OVR_POS + 1,
	JOG_CSS	= JOG_MANUAL_MODE + 1
    } 	JOGKEY_REPORT_T;

#pragma once
typedef 
enum PATH8070_ST
    {	MAINPATH	= 0,
	TMPPATH	= MAINPATH + 1,
	BLACKBOXPATH	= TMPPATH + 1,
	DUMPPATH	= BLACKBOXPATH + 1,
	TRACEPATH	= DUMPPATH + 1,
	DRIVERSPATH	= TRACEPATH + 1,
	BACKUPPATH	= DRIVERSPATH + 1,
	FAGOR_MAINPATH	= 10,
	FAGOR_BINPATH	= FAGOR_MAINPATH + 1,
	FAGOR_CONFIGPATH	= FAGOR_BINPATH + 1,
	FAGOR_IMAGESPATH	= FAGOR_CONFIGPATH + 1,
	FAGOR_LANGMAINPATH	= FAGOR_IMAGESPATH + 1,
	FAGOR_LANGPATH	= FAGOR_LANGMAINPATH + 1,
	FAGOR_DATAPATH	= FAGOR_LANGPATH + 1,
	FAGOR_PLCPATH	= FAGOR_DATAPATH + 1,
	FAGOR_HELPPATH	= FAGOR_PLCPATH + 1,
	FAGOR_TUNING	= FAGOR_HELPPATH + 1,
	FAGOR_DRIVEPATH	= FAGOR_TUNING + 1,
	FAGOR_TEMPLATEPATH	= FAGOR_DRIVEPATH + 1,
	MTB_MAINPATH	= 50,
	MTB_BINPATH	= MTB_MAINPATH + 1,
	MTB_CONFIGPATH	= MTB_BINPATH + 1,
	MTB_IMAGESPATH	= MTB_CONFIGPATH + 1,
	MTB_PLCMSGPATH	= MTB_IMAGESPATH + 1,
	MTB_DATAPATH	= MTB_PLCMSGPATH + 1,
	MTB_PLCPATH	= MTB_DATAPATH + 1,
	MTB_HELPPATH	= MTB_PLCPATH + 1,
	MTB_SUBPATH	= MTB_HELPPATH + 1,
	MTB_DRIVEPATH	= MTB_SUBPATH + 1,
	MTB_BACKUPPATH	= MTB_DRIVEPATH + 1,
	MTB_LANGPATH	= MTB_BACKUPPATH + 1,
	MTB_DATALANGPATH	= MTB_LANGPATH + 1,
	MTB_TUNING	= MTB_DATALANGPATH + 1,
	MTB_SUBHELP	= MTB_TUNING + 1,
	MTB_PLCLANGPATH	= MTB_SUBHELP + 1,
	USER_MAINPATH	= 100,
	USER_PRGPATH	= USER_MAINPATH + 1,
	USER_PROFILEPATH	= USER_PRGPATH + 1,
	USER_POCKETPATH	= USER_PROFILEPATH + 1,
	USER_REPORTSPATH	= USER_POCKETPATH + 1,
	USER_CYCLEDATAPATH	= USER_REPORTSPATH + 1,
	USER_DATAPATH	= USER_CYCLEDATAPATH + 1,
	USER_HELPPATH	= USER_DATAPATH + 1,
	USER_CONFIGPATH	= USER_HELPPATH + 1,
	USER_MMCPATH	= USER_CONFIGPATH + 1,
	USER_SESSIONPATH	= USER_MMCPATH + 1,
	USER_TEMPLATEPATH	= USER_SESSIONPATH + 1,
	BINPATH	= 200,
	CONFIGPATH	= BINPATH + 1,
	IMAGESPATH	= CONFIGPATH + 1,
	LANGPATH	= IMAGESPATH + 1,
	DATAPATH	= LANGPATH + 1,
	PLCPATH	= DATAPATH + 1,
	PRGPATH	= PLCPATH + 1,
	CYCLEPATH	= PRGPATH + 1,
	PROFILEPATH	= CYCLEPATH + 1,
	POCKETPATH	= PROFILEPATH + 1,
	DRIVEPATH	= POCKETPATH + 1,
	OEMSUBPATH	= DRIVEPATH + 1,
	REPORTSPATH	= OEMSUBPATH + 1
    } 	PATH8070_T;

typedef 
enum DRIVE8070_ST
    {	API_D8070_UNKNOWN	= -1,
	API_D8070_MASTER	= API_D8070_UNKNOWN + 1,
	API_D8070_OEM	= API_D8070_MASTER + 1,
	API_D8070_USER	= API_D8070_OEM + 1
    } 	DRIVE8070_T;

typedef 
enum DRIVESTATUS8070_ST
    {	API_DS8070_UNKNOWN	= -1,
	API_DS8070_PROTECTED	= API_DS8070_UNKNOWN + 1,
	API_DS8070_UNPROTECTED	= API_DS8070_PROTECTED + 1
    } 	DRIVESTATUS8070_T;

#pragma once
typedef struct JOGKEYBOARD_ST
    {
    short userKey1;
    short userKey2;
    short userKey3;
    short userKey4;
    short userKey5;
    short userKey6;
    short userKey7;
    short userKey8;
    short userKey9;
    short userKey10;
    short userKey11;
    short userKey12;
    short userKey13;
    short userKey14;
    short userKey15;
    short userKey16;
    short moveKey0;
    short moveKey1;
    short moveKey2;
    short moveKey3;
    short moveKey4;
    short moveKey5;
    short moveKey6;
    short fast;
    short moveKey7;
    short moveKey8;
    short moveKey9;
    short moveKey10;
    short moveKey11;
    short moveKey12;
    short moveKey13;
    short dummy1;
    short sr_minus;
    short m3;
    short m19;
    short m5;
    short sr_plus;
    short m4;
    short start;
    short stop;
    short dummy2;
    short zero;
    short dummy3;
    short singleBlock;
    short dummy4;
    short reset;
    short ovr_pos;
    short dummy5;
    short manual_mode;
    short dummy6;
    } 	JOGKEYBOARD_T;

#pragma once
#pragma once
#pragma once
#pragma once
typedef signed char CHANNEL_T;

typedef unsigned char MZ_T;

typedef /* [helpstring][public] */ 
enum __MIDL___MIDL_itf_api8070_0000_0002
    {	NOMOVE	= 0,
	HANDWHEEL	= 1,
	JOGCONT	= 2,
	JOGINC	= 3,
	PREHANDWHEEL	= 4
    } 	MANUAL_MODE_T;

typedef /* [helpstring][public] */ 
enum __MIDL___MIDL_itf_api8070_0000_0003
    {	IS_NOT_READY	= 0,
	IS_READY	= 1,
	IS_EXECUTING	= 2,
	IS_INTERRUPTED	= 4,
	IS_INTERRUPTED_BY_ERROR	= 8
    } 	STATUS_T;

typedef /* [helpstring][public] */ 
enum __MIDL___MIDL_itf_api8070_0000_0004
    {	IN_RESET	= 0,
	IN_MANUAL	= 1,
	IN_MDI	= 2,
	IN_PROGRAM	= 3,
	STOPPED_M0	= 4,
	STOPPED_FHOLD	= 5,
	STOPPED_BLO_A_BLO	= 6,
	IN_MDI_INTERNAL	= 7,
	IN_EXECUTION_INTERNAL	= 8,
	IN_SYNCHK	= 9,
	IN_EXEC_DRY	= 10,
	IN_END_EXEC_DRY	= 11,
	IN_T_EXEC	= 12,
	IN_SOLLKON	= 13,
	IN_INSPECTION	= 14,
	IN_INSPECTION_AFTER_REPOS	= 15,
	IN_INSPECTION_AFTER_ERROR	= 16,
	IN_RESET_ESCAPE_ERROR	= 17
    } 	SUBSTATUS_T;

typedef /* [helpstring][public] */ 
enum __MIDL___MIDL_itf_api8070_0000_0005
    {	NOT_MANUAL_MODE	= 0,
	MANUAL_MODE	= 1
    } 	KERNEL_MODE_T;

#pragma once
#pragma warning (disable: 4115)
#pragma warning (disable: 4100)
#pragma once
#pragma once
#pragma once
typedef 
enum ToolSize_st
    {	TOOL_SMALL	= 0,
	TOOL_MEDIUM	= TOOL_SMALL + 1,
	TOOL_LARGE	= TOOL_MEDIUM + 1,
	TOOL_CUSTOM	= TOOL_LARGE + 1
    } 	ToolSize_t;

typedef 
enum EdgeMonitType_st
    {	MONIT_NONE	= 0,
	MONIT_TIME	= MONIT_NONE + 1,
	MONIT_OPERATIONS	= MONIT_TIME + 1
    } 	EdgeMonitType_t;

typedef 
enum EdgeType_st
    {	EDGENOTYPE	= 0,
	EDGE_FRESADO	= EDGENOTYPE + 1,
	EDGE_TALADRADO	= EDGE_FRESADO + 1,
	EDGE_PLANEADO	= EDGE_TALADRADO + 1,
	EDGE_ESCARIADO	= EDGE_PLANEADO + 1,
	EDGE_MANDRINADO	= EDGE_ESCARIADO + 1,
	EDGE_ROSCADO	= EDGE_MANDRINADO + 1,
	EDGE_RANURADO	= EDGE_ROSCADO + 1,
	EDGE_TORNEADO	= EDGE_RANURADO + 1,
	EDGE_OTROS	= EDGE_TORNEADO + 1,
	EDGE_SONDAMEDICION	= EDGE_OTROS + 1
    } 	EdgeType_t;

typedef 
enum EdgeSubType_st
    {	EDGENOSUBTYPE	= 0,
	EDGES_PLANO	= EDGENOSUBTYPE + 1,
	EDGES_ESFERICO	= EDGES_PLANO + 1,
	EDGES_TORICO	= EDGES_ESFERICO + 1,
	EDGES_MACHOROSCAR	= EDGES_TORICO + 1,
	EDGES_CUCHILLA	= EDGES_MACHOROSCAR + 1,
	EDGES_DISCOTRONZAR	= EDGES_CUCHILLA + 1,
	EDGES_BROCA	= EDGES_DISCOTRONZAR + 1,
	EDGES_FRESAPLANEAR	= EDGES_BROCA + 1,
	EDGES_ESCARIADOR	= EDGES_FRESAPLANEAR + 1,
	EDGES_MANDRINO	= EDGES_ESCARIADOR + 1,
	EDGES_PLACAROMBICA	= EDGES_MANDRINO + 1,
	EDGES_PLACACUADRADA	= EDGES_PLACAROMBICA + 1,
	EDGES_PLACAREDONDA	= EDGES_PLACACUADRADA + 1,
	EDGES_SONDAMED_M	= EDGES_PLACAREDONDA + 1,
	EDGES_SONDAMED_T	= EDGES_SONDAMED_M + 1
    } 	EdgeSubType_t;

typedef 
enum StatusPos_t
    {	PS_FREE	= 1,
	PS_DISABLED	= PS_FREE + 1,
	PS_LOADED	= PS_DISABLED + 1,
	PS_LOADED_RI	= PS_LOADED + 1,
	PS_LOADED_LE	= PS_LOADED_RI + 1,
	PS_LOADED_RI_LE	= PS_LOADED_LE + 1
    } 	StatusPos_t;

typedef 
enum GeomType_t
    {	NO_GEOM	= 0,
	GEOM_PLANAR	= NO_GEOM + 1,
	GEOM_LINEAL	= GEOM_PLANAR + 1
    } 	GeomType_t;

typedef 
enum MzType_t
    {	MZ_NONE	= 0,
	MZ_ASYNC	= MZ_NONE + 1,
	MZ_SYNC	= MZ_ASYNC + 1,
	MZ_TURRET	= MZ_SYNC + 1,
	MZ_SYNCB	= MZ_TURRET + 1,
	MZ_SYNC1B	= MZ_SYNCB + 1
    } 	MzType_t;

typedef 
enum MzMode_t
    {	MZMD_NORMAL	= 0,
	MZMD_LOADING	= MZMD_NORMAL + 1,
	MZMD_UNLOADING	= MZMD_LOADING + 1,
	MZMD_SETTING	= MZMD_UNLOADING + 1
    } 	MzMode_t;

typedef 
enum M6ALONE_E
    {	M6ALONE_NOTHING	= 0,
	M6ALONE_WARNING	= M6ALONE_NOTHING + 1,
	M6ALONE_ERROR	= M6ALONE_WARNING + 1
    } 	M6ALONE_E;

typedef 
enum MzActivity_t
    {	NO_ACTIVITY	= 0,
	ACTIVITY_T	= NO_ACTIVITY + 1,
	ACTIVITY_M6	= ACTIVITY_T + 1,
	ACTIVITY_TMINEM	= ACTIVITY_M6 + 1
    } 	MzActivity_t;

typedef 
enum FixOrientation_t
    {	FACE_AXIS_ORI	= 0,
	LONG_AXIS_ORI	= FACE_AXIS_ORI + 1
    } 	FixOrientation_t;

typedef 
enum MzTurnConfig_t
    {	TH_ZpXp	= 0,
	TH_ZpXm	= TH_ZpXp + 1,
	TH_ZmXp	= TH_ZpXm + 1,
	TH_ZmXm	= TH_ZmXp + 1,
	TV_XmZp	= TH_ZmXm + 1,
	TV_XpZp	= TV_XmZp + 1,
	TV_XmZm	= TV_XpZp + 1,
	TV_XpZm	= TV_XmZm + 1
    } 	MzTurnConfig_t;

#define	TOOL_AVAILABLE	( 0 )

#define	TOOL_REJECTED	( 0x1 )

#define	TOOL_WARN_OUT	( 0x2 )

#define	TOOL_WARNING	( 0x4 )

#define	POSCH1	( -1 )

#define	POSCH2	( -2 )

#define	POSACTIVE	( -3 )

#define	POSGROUND	( -4 )

#define	POSNONE	( -10 )

typedef struct FCOffset_st
    {
    TCHAR sEjeOffset[ 3 ];
    int iOffset;
    int iOffsetWear;
    } 	FCOffset_t;

#pragma once
typedef 
enum CMPNT8070_ST
    {	MCMPNT_FAIL	= -200,
	MCMPNT_CANT_CREATE	= -201,
	MCMPNT_CANT_ACTIVATE	= -202,
	MCMPNT_NOT_HANDLED	= -203,
	MCMPNT_SUCCESS	= 0,
	MCMPNT_DEFAULT	= 1,
	MCMPNT_HANDLED	= 2
    } 	CMPNT8070_T;

#pragma once				
typedef 
enum PLC_INTERFACE_ST
    {	API_PLC_COMMAND_RUN	= 5,
	API_PLC_COMMAND_STOP	= 6,
	API_PLC_COMMAND_CY1	= 7,
	API_PLC_COMMAND_CYCLE	= 8,
	API_PLC_COMMAND_CONTINUE	= 9,
	API_PLC_COMMAND_PERIOD	= 10,
	API_PLC_USERKEY1	= 11,
	API_PLC_USERKEY2	= 12,
	API_PLC_USERKEY3	= 13,
	API_PLC_USERKEY4	= 14,
	API_PLC_USERKEY5	= 15,
	API_PLC_USERKEY6	= 16,
	API_PLC_USERKEY7	= 17,
	API_PLC_USERKEY8	= 18,
	API_PLC_USERKEY9	= 19,
	API_PLC_USERKEY10	= 20,
	API_PLC_USERKEY11	= 21,
	API_PLC_USERKEY12	= 22,
	API_PLC_USERKEY13	= 23,
	API_PLC_USERKEY14	= 24,
	API_PLC_USERKEY15	= 25,
	API_PLC_USERKEY16	= 26,
	API_PLC_READ_NTIMERS	= 100,
	API_PLC_WRITE_TIMER	= 101,
	API_PLC_WRITE_COUNTER	= 102,
	API_PLC_COMPILE	= 105,
	API_PLC_STATISTICS	= 108
    } 	PLC_INTERFACE_T;

#pragma once	
#define	EDITCTRLFLAG_FILE_MUST_EXIST	( 0x1 )

#define	EDITCTRLFLAG_CAN_CHANGE_PROGSELECT	( 0x2 )

#define	EDITCTRLFLAG_COPYTOPROGRAM	( 0x4 )

#pragma once
#define	ALREADY_8070_HMIDEF__H_INCLUDED_	( TRUE )

#define	WPARAM_NONE	( 0 )

#define	WPARAM_NOPOWER	( 1 )

#define	WPARAM_FPGAS	( 2 )

typedef 
enum LTYPE_E
    {	TYPE_HXPZP	= 0,
	TYPE_HXNZP	= TYPE_HXPZP + 1,
	TYPE_VZPXP	= TYPE_HXNZP + 1,
	TYPE_VZPXN	= TYPE_VZPXP + 1,
	TYPE_HXPZN	= TYPE_VZPXN + 1,
	TYPE_HXNZN	= TYPE_HXPZN + 1,
	TYPE_VZNXP	= TYPE_HXNZN + 1,
	TYPE_VZNXN	= TYPE_VZNXP + 1
    } 	LTYPE_E;

typedef 
enum MTYPE_E
    {	TYPE_MILL	= 0,
	TYPE_MILL_W	= TYPE_MILL + 1,
	TYPE_BORING	= TYPE_MILL_W + 1,
	TYPE_BORING_W	= TYPE_BORING + 1
    } 	MTYPE_E;

#pragma once
#pragma once
typedef 
enum CheckRepos_st
    {	CHK_EJE_YA_REPOS	= 0,
	CHK_EJE_NO_REPOS	= 1,
	CHK_CABEZAL_M3	= 3,
	CHK_CABEZAL_M4	= 4,
	CHK_CABEZAL_M5	= 5,
	CHK_CABEZAL_M19	= 19,
	CHK_EJE_REPOSICIONANDO	= -1,
	CHK_CABEZAL_M3_REPOSICIONANDO	= -3,
	CHK_CABEZAL_M4_REPOSICIONANDO	= -4,
	CHK_CABEZAL_M5_REPOSICIONANDO	= -5,
	CHK_CABEZAL_M19_REPOSICIONANDO	= -19,
	CHK_ERROR_REPOS	= -2
    } 	CheckRepos_t;

typedef 
enum VAR_MAX_ST
    {	API_VAR_NAME_MAX	= 24,
	API_VAR_NAME_MAXTOT	= 26,
	API_VAR_SENTENCE_MAX	= 100,
	API_VAR_PREFIX_MAX	= 6
    } 	VAR_MAX_T;

typedef 
enum SETPARAM_ST
    {	NOT_OK	= -1,
	OK	= NOT_OK + 1,
	RELOADTABLE	= OK + 1
    } 	SETPARAM_T;

typedef 
enum PARAMTYPE_ST
    {	LIST	= 0,
	TABLE	= LIST + 1,
	SIMPLE	= TABLE + 1,
	ENUMERATION	= SIMPLE + 1,
	YESNO	= ENUMERATION + 1,
	PARAMTYPE_TEXT	= YESNO + 1
    } 	PARAMTYPE_T;

typedef 
enum ERROR_TYPE_ST
    {	WARNING_MODE	= 0,
	ERROR_MODE	= WARNING_MODE + 1,
	FATALERROR_MODE	= ERROR_MODE + 1
    } 	ERROR_TYPE_T;

typedef 
enum ERROR_SOURCE_ST
    {	PLC_ERROR	= 0,
	NC_ERROR	= PLC_ERROR + 1,
	MSG_ERROR	= NC_ERROR + 1,
	MACHINE_PARAMETER_ERROR	= MSG_ERROR + 1,
	MMI_ERROR	= MACHINE_PARAMETER_ERROR + 1
    } 	ERROR_SOURCE_T;

typedef 
enum HVAR_VALUES_ST
    {	API_RET_INVALID_HVAR	= INVALID_HVAR,
	API_RET_RPC_SERVER_UNAVAILABLE	= API_RET_INVALID_HVAR - 1
    } 	HVAR_VALUES_T;

typedef 
enum APIRETVALUES_ST
    {	API_RET_ERROR	= -69,
	API_CYSTART_NOT_ACTIVE	= API_RET_ERROR + 1,
	API_KERNEL_ALREADY_STARTED	= API_CYSTART_NOT_ACTIVE + 1,
	API_KERNEL_NOT_STARTED	= API_KERNEL_ALREADY_STARTED + 1,
	API_STATUS_NOT_READY	= API_KERNEL_NOT_STARTED + 1,
	API_INVALID_API_STATUS	= API_STATUS_NOT_READY + 1,
	API_KERNEL_NOT_READY	= API_INVALID_API_STATUS + 1,
	API_INVALID_KERNEL_MODE	= API_KERNEL_NOT_READY + 1,
	API_INVALID_KERNEL_STATUS	= API_INVALID_KERNEL_MODE + 1,
	API_INVALID_DATABASE	= API_INVALID_KERNEL_STATUS + 1,
	API_RET_OK	= 0
    } 	API_RETVALUES_T;

#define	NUM_CANALES	( 1 )

typedef 
enum API_STATUS_ST
    {	API_READY	= 0,
	API_ERROR	= API_READY + 1,
	API_NO_READY	= API_ERROR + 1,
	API_EXEC_BLOQ_REQUESTED	= API_NO_READY + 1,
	API_EXEC_BLOQ_PENDING	= API_EXEC_BLOQ_REQUESTED + 1,
	API_EXEC_BLOQ_EXECUTING	= API_EXEC_BLOQ_PENDING + 1,
	API_EXEC_BLOQ_INTERRUPTED	= API_EXEC_BLOQ_EXECUTING + 1,
	API_EXEC_BLOQ_ENDED	= API_EXEC_BLOQ_INTERRUPTED + 1,
	API_RESET_REQUESTED	= API_EXEC_BLOQ_ENDED + 1,
	API_RESET_ENDED	= API_RESET_REQUESTED + 1,
	API_EXEC_PROGRAM_REQUESTED	= API_RESET_ENDED + 1,
	API_EXEC_PROGRAM_EXECUTING	= API_EXEC_PROGRAM_REQUESTED + 1,
	API_EXEC_PROGRAM_ENDED	= API_EXEC_PROGRAM_EXECUTING + 1,
	API_EXEC_PROGRAM_INTERRUPTED	= API_EXEC_PROGRAM_ENDED + 1,
	API_START_PROGRAM_REQUESTED	= API_EXEC_PROGRAM_INTERRUPTED + 1,
	API_START_PROGRAM_EXECUTING	= API_START_PROGRAM_REQUESTED + 1,
	API_START_PROGRAM_ENDED	= API_START_PROGRAM_EXECUTING + 1,
	API_START_PROGRAM_INTERRUPTED	= API_START_PROGRAM_ENDED + 1,
	API_ACTIVATE_INSPECTION	= API_START_PROGRAM_INTERRUPTED + 1,
	API_ACTIVATE_INSPECTION_ENDED	= API_ACTIVATE_INSPECTION + 1,
	API_ACTIVATE_INSPECTION_EXECUTING	= API_ACTIVATE_INSPECTION_ENDED + 1,
	API_BLOCK_SEARCH_REQUESTED	= API_ACTIVATE_INSPECTION_EXECUTING + 1,
	API_BLOCK_SEARCH_EXECUTING	= API_BLOCK_SEARCH_REQUESTED + 1,
	API_BLOCK_SEARCH_END	= API_BLOCK_SEARCH_EXECUTING + 1
    } 	API_STATUS_T;

typedef 
enum CNC_MODE_ST
    {	EJECUTION_MODE	= 0,
	SIMULATION_MODE	= 0x1
    } 	CNC_MODE_T;

typedef 
enum SIMULATION_OPTIONS_ST
    {	NO_OPTIONS	= 0,
	NO_COMPENSATION	= 0x1,
	NO_TEST_OFFSETS	= 0x2,
	ASSUME_ZERO_OFFSETS	= 0x40000
    } 	SIMULATION_OPTIONS_T;

typedef 
enum PERCENT_ST
    {	PERCENT_INIT	= 1000,
	PERCENT_END	= 1001,
	PERCENT_ERROR_SOURCEFILE	= 1002,
	PERCENT_ERROR_GENERATEDFILE	= 1003
    } 	PERCENT_T;

typedef 
enum GRAPHTYPE_ST
    {	GTYPE_HORIZ_XUP_ZRIGTH	= TYPE_HXPZP,
	GTYPE_HORIZ_XDOWN_ZRIGHT	= TYPE_HXNZP,
	GTYPE_VERT_ZUP_XRIGHT	= TYPE_VZPXP,
	GTYPE_VERT_ZUP_XLEFT	= TYPE_VZPXN,
	GTYPE_HORIZ_XUP_ZLEFT	= TYPE_HXPZN,
	GTYPE_HORIZ_XDOWN_ZLEFT	= TYPE_HXNZN,
	GTYPE_VERT_ZDOWN_XRIGHT	= TYPE_VZNXP,
	GTYPE_VERT_ZDOWN_XLEFT	= TYPE_VZNXN
    } 	GRAPHTYPE_T;

typedef 
enum VARIABLETYPE_ST
    {	BYTETYPE	= 0,
	WORDTYPE	= BYTETYPE + 1,
	DWORDTYPE	= WORDTYPE + 1,
	FLOATTYPE	= DWORDTYPE + 1,
	DOUBLETYPE	= FLOATTYPE + 1,
	STRINGTYPE	= DOUBLETYPE + 1,
	BINARYTYPE	= STRINGTYPE + 1
    } 	VARIABLETYPE_T;

typedef 
enum GRIDCELLTYPE_ST
    {	GVC_NORMAL	= 0,
	GVC_CHECK	= GVC_NORMAL + 1,
	GVC_COMBO	= GVC_CHECK + 1,
	GVC_DATETIME	= GVC_COMBO + 1,
	GVC_NUMERIC	= GVC_DATETIME + 1,
	GVC_URLCell	= GVC_NUMERIC + 1
    } 	GRIDCELLTYPE_T;

typedef 
enum VSERCOS_ST
    {	VSERCOS_INVALID	= 0xffff,
	VSERCOS_STRING	= 0,
	VSERCOS_BYTE	= 1,
	VSERCOS_WORD	= 2,
	VSERCOS_LONG	= 4,
	VSERCOS_FALSE	= 0,
	VSERCOS_TRUE	= 1
    } 	VSERCOS_T;

typedef 
enum CYCLE_EDITORS_ST
    {	CE_MILLING	= 1,
	CE_TURNING	= 2,
	CE_MILL_PROBING	= 3,
	CE_LATHE_PROBING	= 4,
	CE_INCLINE_PLANES	= 6,
	CE_GEOM_HELP	= 7
    } 	CYCLE_EDITORS_T;

typedef 
enum FM_COMMS_ST
    {	API_FM_INCH_MM	= 0x400 + 0x407
    } 	FM_COMMS_T;

typedef 
enum MAX_KEYBOARDS_ST
    {	N_MAX_KEYBOARDS	= 8
    } 	MAX_KEYBOARDS_ST;

typedef 
enum CHECK_REPOS_ST
    {	REPOS_CHK_EJE_YA_REPOS	= 0,
	REPOS_CHK_EJE_NO_REPOS	= 1,
	REPOS_CHK_CABEZAL_M3	= 3,
	REPOS_CHK_CABEZAL_M4	= 4,
	REPOS_CHK_CABEZAL_M5	= 5,
	REPOS_CHK_CABEZAL_M19	= 19,
	REPOS_CHK_EJE_REPOSICIONANDO	= -1,
	REPOS_CHK_CABEZAL_M3_REPOSICIONANDO	= -3,
	REPOS_CHK_CABEZAL_M4_REPOSICIONANDO	= -4,
	REPOS_CHK_CABEZAL_M5_REPOSICIONANDO	= -5,
	REPOS_CHK_CABEZAL_M19_REPOSICIONANDO	= -19,
	REPOS_CHK_ERROR_REPOS	= -2
    } 	CHECK_REPOS_T;

typedef 
enum ACTIVATE_REPOS_ST
    {	ACTIVATE_REPOS_INTERRUPTION_POINT	= 0x10000,
	ACTIVATE_REPOS_INITIAL_BLOCK	= 0x20000
    } 	ACTIVATE_REPOS_T;

typedef 
enum COLORS_ST
    {	RGB_MSG_BACKGR	= ( COLORREF  )(( BYTE  )100 | ( WORD  )( BYTE  )128 << 8 | ( DWORD  )( BYTE  )44 << 16),
	RGB_MSG_FOREGR	= ( COLORREF  )(( BYTE  )0 | ( WORD  )( BYTE  )0 << 8 | ( DWORD  )( BYTE  )0 << 16)
    } 	;

typedef 
enum POSSIBLE_INSPECTION2_ST
    {	POSSIBLE_INSPECTION2_NO_INSPEC	= 0,
	POSSIBLE_INSPECTION2_OLD_INSPEC	= 1,
	POSSIBLE_INSPECTION2_NEW_INSPEC	= 2
    } 	POSSIBLE_INSPECTION2_T;

typedef 
enum MMCMODE_ST
    {	MMCMODE_MODE_AUTO	= 0,
	MMCMODE_MODE_MANUAL	= 1,
	MMCMODE_MODE_MDI	= 2
    } 	MMCMODE_T;

typedef 
enum JOGKEYDEF_ST
    {	API_JOGKEYDEF_UNDEFINED	= 0,
	API_JOGKEYDEF_RAPID	= 300,
	API_JOGKEYDEF_POSITIVE	= 301,
	API_JOGKEYDEF_NEGATIVE	= 302,
	API_JOGKEYDEF_AXIS	= 100,
	API_JOGKEYDEF_1ST_AXIS	= 100 + 1,
	API_JOGKEYDEF_LAST_AXIS	= 100 + 5,
	API_JOGKEYDEF_1ST_NEGATIVE	= -1,
	API_JOGKEYDEF_LAST_NEGATIVE	= -5,
	API_JOGKEYDEF_1ST_POSITIVE	= 1,
	API_JOGKEYDEF_LAST_POSITIVE	= 5
    } 	JOGKEYDEF_T;







DEFINE_GUID(LIBID_Api8070,0x714D710F,0x27B7,0x42BA,0xA5,0x88,0x91,0xAD,0xC7,0xFF,0x4B,0x47);

#ifndef __IFCVar8070_DISPINTERFACE_DEFINED__
#define __IFCVar8070_DISPINTERFACE_DEFINED__

/* dispinterface IFCVar8070 */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCVar8070,0x3CB73C62,0x66FE,0x49B7,0x9D,0xCA,0x23,0x5F,0x21,0x4B,0x8E,0x01);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3CB73C62-66FE-49B7-9DCA-235F214B8E01")
    IFCVar8070 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCVar8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCVar8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCVar8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCVar8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCVar8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCVar8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCVar8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCVar8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCVar8070Vtbl;

    interface IFCVar8070
    {
        CONST_VTBL struct IFCVar8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCVar8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCVar8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCVar8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCVar8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCVar8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCVar8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCVar8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCVar8070_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualVar8070_INTERFACE_DEFINED__
#define __IFCDualVar8070_INTERFACE_DEFINED__

/* interface IFCDualVar8070 */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualVar8070,0xAAA5D119,0x7C6D,0x4c6e,0xB4,0xC1,0x9A,0xF6,0xBD,0x5E,0x69,0xC1);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AAA5D119-7C6D-4c6e-B4C1-9AF6BD5E69C1")
    IFCDualVar8070 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenVariable( 
            /* [in] */ BSTR namevar,
            /* [retval][out] */ HVAR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseVariable( 
            /* [in] */ HVAR h_var) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadTxt( 
            /* [in] */ HVAR h_var,
            /* [defaultvalue][optional][in] */ long size,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenReport( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HandleReport( 
            /* [in] */ HVAR h_var,
            /* [in] */ long param1,
            /* [in] */ VARIANT param2,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GeneraReport( 
            /* [in] */ HVAR h_var) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseReport( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsReport( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsReportOpened( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNIntegers( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetNIntegers( 
            /* [in] */ HVAR h_var,
            /* [in] */ long nIntegers) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNDecimals( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetNDecimals( 
            /* [in] */ HVAR h_var,
            /* [in] */ long nDecimals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPad( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPad( 
            /* [in] */ HVAR h_var,
            BOOL bPad) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsWritable( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE SimulateRead( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE GetVariableCount( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE GetVariableList( 
            /* [retval][out] */ BSTR *pLista) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsValid( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteTxt( 
            /* [in] */ HVAR h_var,
            /* [in] */ BSTR value,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ long h_var,
            /* [in] */ BSTR namevar,
            /* [retval][out] */ long *out_h_var) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenReport2( 
            /* [in] */ HVAR h_var,
            /* [in] */ IDispatch *pSink) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadInt( 
            /* [in] */ HVAR h_var,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteInt( 
            /* [in] */ HVAR h_var,
            /* [in] */ long newval,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDouble( 
            /* [in] */ HVAR h_var,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ double *resul) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDouble( 
            /* [in] */ HVAR h_var,
            /* [in] */ double newval,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBin( 
            /* [in] */ HVAR h_var,
            /* [in] */ long size,
            /* [retval][out] */ VARIANT *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBin( 
            /* [in] */ HVAR h_var,
            /* [in] */ VARIANT orig,
            /* [in] */ long size,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE UpdateCache( 
            /* [in] */ HVAR hvar,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadTxtArray( 
            /* [in] */ long *pH_vars,
            /* [in] */ short numH_vars,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetHexView( 
            /* [in] */ HVAR hvar,
            /* [in] */ BOOL bHexView) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStatusByte( 
            /* [in] */ long lFullStatus,
            /* [retval][out] */ long *plStatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSubstatusByte( 
            /* [in] */ long lFullStatus,
            /* [retval][out] */ long *plSubstatus) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLastError( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE GetAllVariablesListForced( 
            /* [retval][out] */ BSTR *pLista) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE GetAllVariableCount( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadIntArray( 
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteIntArray( 
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadDoubleArray( 
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteDoubleArray( 
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DesconectarVariables( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenReport2S( 
            /* [in] */ HVAR h_var,
            /* [in] */ IDispatch *pSink) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenReportS( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetVariableType( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ VARIABLETYPE_T *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadVar( 
            /* [in] */ HVAR h_var,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ VARIANT *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteVar( 
            /* [in] */ HVAR h_var,
            /* [in] */ VARIANT newval,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadVarArray( 
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteVarArray( 
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AplicarTransfInches( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ForceWriteInt( 
            /* [in] */ HVAR h_var,
            /* [in] */ long newval,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFilterDelay( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFilterDelay( 
            /* [in] */ HVAR h_var,
            /* [in] */ long delay) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AplicarTransfInchesEx( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsReportOpened2( 
            /* [in] */ HVAR h_var,
            /* [in] */ IDispatch *pSink,
            /* [retval][out] */ BOOL *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualVar8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualVar8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualVar8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualVar8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualVar8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualVar8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualVar8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualVar8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenVariable )( 
            IFCDualVar8070 * This,
            /* [in] */ BSTR namevar,
            /* [retval][out] */ HVAR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseVariable )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadTxt )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [defaultvalue][optional][in] */ long size,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenReport )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HandleReport )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ long param1,
            /* [in] */ VARIANT param2,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GeneraReport )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseReport )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsReport )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsReportOpened )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNIntegers )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNIntegers )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ long nIntegers);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNDecimals )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNDecimals )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ long nDecimals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPad )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPad )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            BOOL bPad);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsWritable )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *SimulateRead )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BSTR *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *GetVariableCount )( 
            IFCDualVar8070 * This,
            /* [retval][out] */ long *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *GetVariableList )( 
            IFCDualVar8070 * This,
            /* [retval][out] */ BSTR *pLista);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsValid )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteTxt )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ BSTR value,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IFCDualVar8070 * This,
            /* [in] */ long h_var,
            /* [in] */ BSTR namevar,
            /* [retval][out] */ long *out_h_var);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenReport2 )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ IDispatch *pSink);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadInt )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteInt )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ long newval,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDouble )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ double *resul);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDouble )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ double newval,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadBin )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ long size,
            /* [retval][out] */ VARIANT *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteBin )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ VARIANT orig,
            /* [in] */ long size,
            /* [retval][out] */ long *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *UpdateCache )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR hvar,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadTxtArray )( 
            IFCDualVar8070 * This,
            /* [in] */ long *pH_vars,
            /* [in] */ short numH_vars,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetHexView )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR hvar,
            /* [in] */ BOOL bHexView);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStatusByte )( 
            IFCDualVar8070 * This,
            /* [in] */ long lFullStatus,
            /* [retval][out] */ long *plStatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSubstatusByte )( 
            IFCDualVar8070 * This,
            /* [in] */ long lFullStatus,
            /* [retval][out] */ long *plSubstatus);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLastError )( 
            IFCDualVar8070 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *GetAllVariablesListForced )( 
            IFCDualVar8070 * This,
            /* [retval][out] */ BSTR *pLista);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *GetAllVariableCount )( 
            IFCDualVar8070 * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadIntArray )( 
            IFCDualVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteIntArray )( 
            IFCDualVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadDoubleArray )( 
            IFCDualVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteDoubleArray )( 
            IFCDualVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DesconectarVariables )( 
            IFCDualVar8070 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenReport2S )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ IDispatch *pSink);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenReportS )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetVariableType )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ VARIABLETYPE_T *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadVar )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ VARIANT *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteVar )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ VARIANT newval,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadVarArray )( 
            IFCDualVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteVarArray )( 
            IFCDualVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AplicarTransfInches )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ForceWriteInt )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ long newval,
            /* [defaultvalue][optional][in] */ int index1,
            /* [defaultvalue][optional][in] */ int index2,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFilterDelay )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFilterDelay )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ long delay);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AplicarTransfInchesEx )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsReportOpened2 )( 
            IFCDualVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [in] */ IDispatch *pSink,
            /* [retval][out] */ BOOL *retval);
        
        END_INTERFACE
    } IFCDualVar8070Vtbl;

    interface IFCDualVar8070
    {
        CONST_VTBL struct IFCDualVar8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualVar8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualVar8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualVar8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualVar8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualVar8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualVar8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualVar8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualVar8070_OpenVariable(This,namevar,retval)	\
    (This)->lpVtbl -> OpenVariable(This,namevar,retval)

#define IFCDualVar8070_CloseVariable(This,h_var)	\
    (This)->lpVtbl -> CloseVariable(This,h_var)

#define IFCDualVar8070_ReadTxt(This,h_var,size,retval)	\
    (This)->lpVtbl -> ReadTxt(This,h_var,size,retval)

#define IFCDualVar8070_OpenReport(This,h_var,retval)	\
    (This)->lpVtbl -> OpenReport(This,h_var,retval)

#define IFCDualVar8070_HandleReport(This,h_var,param1,param2,retval)	\
    (This)->lpVtbl -> HandleReport(This,h_var,param1,param2,retval)

#define IFCDualVar8070_GeneraReport(This,h_var)	\
    (This)->lpVtbl -> GeneraReport(This,h_var)

#define IFCDualVar8070_CloseReport(This,h_var,retval)	\
    (This)->lpVtbl -> CloseReport(This,h_var,retval)

#define IFCDualVar8070_IsReport(This,h_var,retval)	\
    (This)->lpVtbl -> IsReport(This,h_var,retval)

#define IFCDualVar8070_IsReportOpened(This,h_var,retval)	\
    (This)->lpVtbl -> IsReportOpened(This,h_var,retval)

#define IFCDualVar8070_GetNIntegers(This,h_var,retval)	\
    (This)->lpVtbl -> GetNIntegers(This,h_var,retval)

#define IFCDualVar8070_SetNIntegers(This,h_var,nIntegers)	\
    (This)->lpVtbl -> SetNIntegers(This,h_var,nIntegers)

#define IFCDualVar8070_GetNDecimals(This,h_var,retval)	\
    (This)->lpVtbl -> GetNDecimals(This,h_var,retval)

#define IFCDualVar8070_SetNDecimals(This,h_var,nDecimals)	\
    (This)->lpVtbl -> SetNDecimals(This,h_var,nDecimals)

#define IFCDualVar8070_GetPad(This,h_var,retval)	\
    (This)->lpVtbl -> GetPad(This,h_var,retval)

#define IFCDualVar8070_SetPad(This,h_var,bPad)	\
    (This)->lpVtbl -> SetPad(This,h_var,bPad)

#define IFCDualVar8070_IsWritable(This,h_var,retval)	\
    (This)->lpVtbl -> IsWritable(This,h_var,retval)

#define IFCDualVar8070_SimulateRead(This,h_var,retval)	\
    (This)->lpVtbl -> SimulateRead(This,h_var,retval)

#define IFCDualVar8070_GetVariableCount(This,retval)	\
    (This)->lpVtbl -> GetVariableCount(This,retval)

#define IFCDualVar8070_GetVariableList(This,pLista)	\
    (This)->lpVtbl -> GetVariableList(This,pLista)

#define IFCDualVar8070_IsValid(This,h_var,retval)	\
    (This)->lpVtbl -> IsValid(This,h_var,retval)

#define IFCDualVar8070_WriteTxt(This,h_var,value,retval)	\
    (This)->lpVtbl -> WriteTxt(This,h_var,value,retval)

#define IFCDualVar8070_SetName(This,h_var,namevar,out_h_var)	\
    (This)->lpVtbl -> SetName(This,h_var,namevar,out_h_var)

#define IFCDualVar8070_OpenReport2(This,h_var,pSink)	\
    (This)->lpVtbl -> OpenReport2(This,h_var,pSink)

#define IFCDualVar8070_ReadInt(This,h_var,index1,index2,retval)	\
    (This)->lpVtbl -> ReadInt(This,h_var,index1,index2,retval)

#define IFCDualVar8070_WriteInt(This,h_var,newval,index1,index2,retval)	\
    (This)->lpVtbl -> WriteInt(This,h_var,newval,index1,index2,retval)

#define IFCDualVar8070_ReadDouble(This,h_var,index1,index2,resul)	\
    (This)->lpVtbl -> ReadDouble(This,h_var,index1,index2,resul)

#define IFCDualVar8070_WriteDouble(This,h_var,newval,index1,index2,retval)	\
    (This)->lpVtbl -> WriteDouble(This,h_var,newval,index1,index2,retval)

#define IFCDualVar8070_ReadBin(This,h_var,size,retval)	\
    (This)->lpVtbl -> ReadBin(This,h_var,size,retval)

#define IFCDualVar8070_WriteBin(This,h_var,orig,size,retval)	\
    (This)->lpVtbl -> WriteBin(This,h_var,orig,size,retval)

#define IFCDualVar8070_UpdateCache(This,hvar,retval)	\
    (This)->lpVtbl -> UpdateCache(This,hvar,retval)

#define IFCDualVar8070_ReadTxtArray(This,pH_vars,numH_vars,retval)	\
    (This)->lpVtbl -> ReadTxtArray(This,pH_vars,numH_vars,retval)

#define IFCDualVar8070_SetHexView(This,hvar,bHexView)	\
    (This)->lpVtbl -> SetHexView(This,hvar,bHexView)

#define IFCDualVar8070_GetStatusByte(This,lFullStatus,plStatus)	\
    (This)->lpVtbl -> GetStatusByte(This,lFullStatus,plStatus)

#define IFCDualVar8070_GetSubstatusByte(This,lFullStatus,plSubstatus)	\
    (This)->lpVtbl -> GetSubstatusByte(This,lFullStatus,plSubstatus)

#define IFCDualVar8070_GetLastError(This,retval)	\
    (This)->lpVtbl -> GetLastError(This,retval)

#define IFCDualVar8070_GetAllVariablesListForced(This,pLista)	\
    (This)->lpVtbl -> GetAllVariablesListForced(This,pLista)

#define IFCDualVar8070_GetAllVariableCount(This,retval)	\
    (This)->lpVtbl -> GetAllVariableCount(This,retval)

#define IFCDualVar8070_ReadIntArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> ReadIntArray(This,idArray,valueArray,retval)

#define IFCDualVar8070_WriteIntArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> WriteIntArray(This,idArray,valueArray,retval)

#define IFCDualVar8070_ReadDoubleArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> ReadDoubleArray(This,idArray,valueArray,retval)

#define IFCDualVar8070_WriteDoubleArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> WriteDoubleArray(This,idArray,valueArray,retval)

#define IFCDualVar8070_DesconectarVariables(This)	\
    (This)->lpVtbl -> DesconectarVariables(This)

#define IFCDualVar8070_OpenReport2S(This,h_var,pSink)	\
    (This)->lpVtbl -> OpenReport2S(This,h_var,pSink)

#define IFCDualVar8070_OpenReportS(This,h_var,retval)	\
    (This)->lpVtbl -> OpenReportS(This,h_var,retval)

#define IFCDualVar8070_GetVariableType(This,h_var,retval)	\
    (This)->lpVtbl -> GetVariableType(This,h_var,retval)

#define IFCDualVar8070_ReadVar(This,h_var,index1,index2,retval)	\
    (This)->lpVtbl -> ReadVar(This,h_var,index1,index2,retval)

#define IFCDualVar8070_WriteVar(This,h_var,newval,index1,index2,retval)	\
    (This)->lpVtbl -> WriteVar(This,h_var,newval,index1,index2,retval)

#define IFCDualVar8070_ReadVarArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> ReadVarArray(This,idArray,valueArray,retval)

#define IFCDualVar8070_WriteVarArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> WriteVarArray(This,idArray,valueArray,retval)

#define IFCDualVar8070_AplicarTransfInches(This,h_var,retval)	\
    (This)->lpVtbl -> AplicarTransfInches(This,h_var,retval)

#define IFCDualVar8070_ForceWriteInt(This,h_var,newval,index1,index2,retval)	\
    (This)->lpVtbl -> ForceWriteInt(This,h_var,newval,index1,index2,retval)

#define IFCDualVar8070_GetFilterDelay(This,h_var,retval)	\
    (This)->lpVtbl -> GetFilterDelay(This,h_var,retval)

#define IFCDualVar8070_SetFilterDelay(This,h_var,delay)	\
    (This)->lpVtbl -> SetFilterDelay(This,h_var,delay)

#define IFCDualVar8070_AplicarTransfInchesEx(This,h_var,retval)	\
    (This)->lpVtbl -> AplicarTransfInchesEx(This,h_var,retval)

#define IFCDualVar8070_IsReportOpened2(This,h_var,pSink,retval)	\
    (This)->lpVtbl -> IsReportOpened2(This,h_var,pSink,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_OpenVariable_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ BSTR namevar,
    /* [retval][out] */ HVAR *retval);


void __RPC_STUB IFCDualVar8070_OpenVariable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_CloseVariable_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var);


void __RPC_STUB IFCDualVar8070_CloseVariable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_ReadTxt_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [defaultvalue][optional][in] */ long size,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualVar8070_ReadTxt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_OpenReport_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_OpenReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_HandleReport_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ long param1,
    /* [in] */ VARIANT param2,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualVar8070_HandleReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GeneraReport_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var);


void __RPC_STUB IFCDualVar8070_GeneraReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_CloseReport_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_CloseReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_IsReport_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualVar8070_IsReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_IsReportOpened_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualVar8070_IsReportOpened_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetNIntegers_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_GetNIntegers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_SetNIntegers_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ long nIntegers);


void __RPC_STUB IFCDualVar8070_SetNIntegers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetNDecimals_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_GetNDecimals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_SetNDecimals_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ long nDecimals);


void __RPC_STUB IFCDualVar8070_SetNDecimals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetPad_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualVar8070_GetPad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_SetPad_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    BOOL bPad);


void __RPC_STUB IFCDualVar8070_SetPad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_IsWritable_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualVar8070_IsWritable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_SimulateRead_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualVar8070_SimulateRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetVariableCount_Proxy( 
    IFCDualVar8070 * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_GetVariableCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetVariableList_Proxy( 
    IFCDualVar8070 * This,
    /* [retval][out] */ BSTR *pLista);


void __RPC_STUB IFCDualVar8070_GetVariableList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_IsValid_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualVar8070_IsValid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_WriteTxt_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ BSTR value,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_WriteTxt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_SetName_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ long h_var,
    /* [in] */ BSTR namevar,
    /* [retval][out] */ long *out_h_var);


void __RPC_STUB IFCDualVar8070_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_OpenReport2_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ IDispatch *pSink);


void __RPC_STUB IFCDualVar8070_OpenReport2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_ReadInt_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [defaultvalue][optional][in] */ int index1,
    /* [defaultvalue][optional][in] */ int index2,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_ReadInt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_WriteInt_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ long newval,
    /* [defaultvalue][optional][in] */ int index1,
    /* [defaultvalue][optional][in] */ int index2,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_WriteInt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_ReadDouble_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [defaultvalue][optional][in] */ int index1,
    /* [defaultvalue][optional][in] */ int index2,
    /* [retval][out] */ double *resul);


void __RPC_STUB IFCDualVar8070_ReadDouble_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_WriteDouble_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ double newval,
    /* [defaultvalue][optional][in] */ int index1,
    /* [defaultvalue][optional][in] */ int index2,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_WriteDouble_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_ReadBin_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ long size,
    /* [retval][out] */ VARIANT *retval);


void __RPC_STUB IFCDualVar8070_ReadBin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_WriteBin_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ VARIANT orig,
    /* [in] */ long size,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_WriteBin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_UpdateCache_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR hvar,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualVar8070_UpdateCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_ReadTxtArray_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ long *pH_vars,
    /* [in] */ short numH_vars,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualVar8070_ReadTxtArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_SetHexView_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR hvar,
    /* [in] */ BOOL bHexView);


void __RPC_STUB IFCDualVar8070_SetHexView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetStatusByte_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ long lFullStatus,
    /* [retval][out] */ long *plStatus);


void __RPC_STUB IFCDualVar8070_GetStatusByte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetSubstatusByte_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ long lFullStatus,
    /* [retval][out] */ long *plSubstatus);


void __RPC_STUB IFCDualVar8070_GetSubstatusByte_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetLastError_Proxy( 
    IFCDualVar8070 * This,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualVar8070_GetLastError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetAllVariablesListForced_Proxy( 
    IFCDualVar8070 * This,
    /* [retval][out] */ BSTR *pLista);


void __RPC_STUB IFCDualVar8070_GetAllVariablesListForced_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetAllVariableCount_Proxy( 
    IFCDualVar8070 * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_GetAllVariableCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_ReadIntArray_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [out][in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_ReadIntArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_WriteIntArray_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_WriteIntArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_ReadDoubleArray_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [out][in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_ReadDoubleArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_WriteDoubleArray_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_WriteDoubleArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_DesconectarVariables_Proxy( 
    IFCDualVar8070 * This);


void __RPC_STUB IFCDualVar8070_DesconectarVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_OpenReport2S_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ IDispatch *pSink);


void __RPC_STUB IFCDualVar8070_OpenReport2S_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_OpenReportS_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_OpenReportS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetVariableType_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ VARIABLETYPE_T *retval);


void __RPC_STUB IFCDualVar8070_GetVariableType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_ReadVar_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [defaultvalue][optional][in] */ int index1,
    /* [defaultvalue][optional][in] */ int index2,
    /* [retval][out] */ VARIANT *retval);


void __RPC_STUB IFCDualVar8070_ReadVar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_WriteVar_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ VARIANT newval,
    /* [defaultvalue][optional][in] */ int index1,
    /* [defaultvalue][optional][in] */ int index2,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_WriteVar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_ReadVarArray_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [out][in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_ReadVarArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_WriteVarArray_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_WriteVarArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_AplicarTransfInches_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualVar8070_AplicarTransfInches_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_ForceWriteInt_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ long newval,
    /* [defaultvalue][optional][in] */ int index1,
    /* [defaultvalue][optional][in] */ int index2,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_ForceWriteInt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_GetFilterDelay_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualVar8070_GetFilterDelay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_SetFilterDelay_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ long delay);


void __RPC_STUB IFCDualVar8070_SetFilterDelay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_AplicarTransfInchesEx_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualVar8070_AplicarTransfInchesEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualVar8070_IsReportOpened2_Proxy( 
    IFCDualVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [in] */ IDispatch *pSink,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualVar8070_IsReportOpened2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualVar8070_INTERFACE_DEFINED__ */


#ifndef __IEventReport_DISPINTERFACE_DEFINED__
#define __IEventReport_DISPINTERFACE_DEFINED__

/* dispinterface IEventReport */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_IEventReport,0x35F0E437,0x057F,0x491c,0x9F,0x36,0x7D,0x6A,0x22,0x3A,0x32,0xE9);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("35F0E437-057F-491c-9F36-7D6A223A32E9")
    IEventReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IEventReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEventReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEventReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEventReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEventReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEventReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEventReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEventReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IEventReportVtbl;

    interface IEventReport
    {
        CONST_VTBL struct IEventReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEventReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEventReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEventReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEventReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEventReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEventReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEventReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IEventReport_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_Variables,0x1D56AF9F,0x8BAB,0x4BB5,0xA0,0x00,0xD9,0x70,0x55,0xAD,0x50,0xE6);

#ifdef __cplusplus

class DECLSPEC_UUID("1D56AF9F-8BAB-4BB5-A000-D97055AD50E6")
CNC8070_Variables;
#endif

#ifndef __IFCUtil8070_DISPINTERFACE_DEFINED__
#define __IFCUtil8070_DISPINTERFACE_DEFINED__

/* dispinterface IFCUtil8070 */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCUtil8070,0xFE2B1378,0xBB6B,0x4160,0x84,0xAF,0x97,0xC8,0x18,0xB5,0x7B,0x63);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FE2B1378-BB6B-4160-84AF-97C818B57B63")
    IFCUtil8070 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCUtil8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCUtil8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCUtil8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCUtil8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCUtil8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCUtil8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCUtil8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCUtil8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCUtil8070Vtbl;

    interface IFCUtil8070
    {
        CONST_VTBL struct IFCUtil8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCUtil8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCUtil8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCUtil8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCUtil8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCUtil8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCUtil8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCUtil8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCUtil8070_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualUtil8070_INTERFACE_DEFINED__
#define __IFCDualUtil8070_INTERFACE_DEFINED__

/* interface IFCDualUtil8070 */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualUtil8070,0xE11BFF0B,0xAC2D,0x4e5e,0xB3,0x54,0xBA,0xD1,0x7A,0x90,0x2D,0xFF);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E11BFF0B-AC2D-4e5e-B354-BAD17A902DFF")
    IFCDualUtil8070 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Get8070PathRemote( 
            /* [in] */ PATH8070_T path8070,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Get8070Path( 
            /* [in] */ PATH8070_T path8070,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE LoadTex( 
            /* [in] */ long id,
            BSTR szDllName,
            /* [defaultvalue][optional][in] */ BOOL bFreeDll,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE GetResourceHandle( 
            /* [in] */ BSTR szDllSname,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE IsVisualizationInInches( 
            /* [in] */ long numcanal,
            /* [in] */ CNC_MODE_T mode,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE PutVisualizationInInches( 
            /* [in] */ long numcanal,
            /* [in] */ CNC_MODE_T mode,
            /* [in] */ BOOL bModoInches) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE GetTuneServiceLevel( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE GetCNCVersion( 
            /* [out][in] */ short *pVersion,
            /* [out][in] */ short *pRevision,
            /* [out][in] */ short *pSubrevision,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE GetCNCDate( 
            /* [out][in] */ short *pDay,
            /* [out][in] */ short *pMonth,
            /* [out][in] */ short *pYear,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AreNewGraphicsActive( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE ReadIniFile( 
            /* [in] */ BSTR szNameIniFile,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE ReadStringIniFile( 
            /* [in] */ BSTR szIniName,
            /* [in] */ BSTR pSection,
            /* [in] */ BSTR pKey,
            /* [in] */ BSTR pDefault,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE WriteStringIniFile( 
            /* [in] */ BSTR szIniName,
            /* [in] */ BSTR pSection,
            /* [in] */ BSTR pKey,
            /* [in] */ BSTR pValue) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE CloseIniFile( 
            /* [in] */ BSTR szIniName) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE UTIL8070_DriveStatus( 
            /* [in] */ DRIVE8070_T drive,
            /* [retval][out] */ DRIVESTATUS8070_T *driveStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualUtil8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualUtil8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualUtil8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualUtil8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualUtil8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualUtil8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualUtil8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualUtil8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Get8070PathRemote )( 
            IFCDualUtil8070 * This,
            /* [in] */ PATH8070_T path8070,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Get8070Path )( 
            IFCDualUtil8070 * This,
            /* [in] */ PATH8070_T path8070,
            /* [retval][out] */ BSTR *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *LoadTex )( 
            IFCDualUtil8070 * This,
            /* [in] */ long id,
            BSTR szDllName,
            /* [defaultvalue][optional][in] */ BOOL bFreeDll,
            /* [retval][out] */ BSTR *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *GetResourceHandle )( 
            IFCDualUtil8070 * This,
            /* [in] */ BSTR szDllSname,
            /* [retval][out] */ long *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *IsVisualizationInInches )( 
            IFCDualUtil8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ CNC_MODE_T mode,
            /* [retval][out] */ BOOL *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *PutVisualizationInInches )( 
            IFCDualUtil8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ CNC_MODE_T mode,
            /* [in] */ BOOL bModoInches);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *GetTuneServiceLevel )( 
            IFCDualUtil8070 * This,
            /* [retval][out] */ long *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *GetCNCVersion )( 
            IFCDualUtil8070 * This,
            /* [out][in] */ short *pVersion,
            /* [out][in] */ short *pRevision,
            /* [out][in] */ short *pSubrevision,
            /* [retval][out] */ BOOL *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *GetCNCDate )( 
            IFCDualUtil8070 * This,
            /* [out][in] */ short *pDay,
            /* [out][in] */ short *pMonth,
            /* [out][in] */ short *pYear,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AreNewGraphicsActive )( 
            IFCDualUtil8070 * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *ReadIniFile )( 
            IFCDualUtil8070 * This,
            /* [in] */ BSTR szNameIniFile,
            /* [retval][out] */ long *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *ReadStringIniFile )( 
            IFCDualUtil8070 * This,
            /* [in] */ BSTR szIniName,
            /* [in] */ BSTR pSection,
            /* [in] */ BSTR pKey,
            /* [in] */ BSTR pDefault,
            /* [retval][out] */ BSTR *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *WriteStringIniFile )( 
            IFCDualUtil8070 * This,
            /* [in] */ BSTR szIniName,
            /* [in] */ BSTR pSection,
            /* [in] */ BSTR pKey,
            /* [in] */ BSTR pValue);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *CloseIniFile )( 
            IFCDualUtil8070 * This,
            /* [in] */ BSTR szIniName);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *UTIL8070_DriveStatus )( 
            IFCDualUtil8070 * This,
            /* [in] */ DRIVE8070_T drive,
            /* [retval][out] */ DRIVESTATUS8070_T *driveStatus);
        
        END_INTERFACE
    } IFCDualUtil8070Vtbl;

    interface IFCDualUtil8070
    {
        CONST_VTBL struct IFCDualUtil8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualUtil8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualUtil8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualUtil8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualUtil8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualUtil8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualUtil8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualUtil8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualUtil8070_Get8070PathRemote(This,path8070,retval)	\
    (This)->lpVtbl -> Get8070PathRemote(This,path8070,retval)

#define IFCDualUtil8070_Get8070Path(This,path8070,retval)	\
    (This)->lpVtbl -> Get8070Path(This,path8070,retval)

#define IFCDualUtil8070_LoadTex(This,id,szDllName,bFreeDll,retval)	\
    (This)->lpVtbl -> LoadTex(This,id,szDllName,bFreeDll,retval)

#define IFCDualUtil8070_GetResourceHandle(This,szDllSname,retval)	\
    (This)->lpVtbl -> GetResourceHandle(This,szDllSname,retval)

#define IFCDualUtil8070_IsVisualizationInInches(This,numcanal,mode,retval)	\
    (This)->lpVtbl -> IsVisualizationInInches(This,numcanal,mode,retval)

#define IFCDualUtil8070_PutVisualizationInInches(This,numcanal,mode,bModoInches)	\
    (This)->lpVtbl -> PutVisualizationInInches(This,numcanal,mode,bModoInches)

#define IFCDualUtil8070_GetTuneServiceLevel(This,retval)	\
    (This)->lpVtbl -> GetTuneServiceLevel(This,retval)

#define IFCDualUtil8070_GetCNCVersion(This,pVersion,pRevision,pSubrevision,retval)	\
    (This)->lpVtbl -> GetCNCVersion(This,pVersion,pRevision,pSubrevision,retval)

#define IFCDualUtil8070_GetCNCDate(This,pDay,pMonth,pYear,retval)	\
    (This)->lpVtbl -> GetCNCDate(This,pDay,pMonth,pYear,retval)

#define IFCDualUtil8070_AreNewGraphicsActive(This,retval)	\
    (This)->lpVtbl -> AreNewGraphicsActive(This,retval)

#define IFCDualUtil8070_ReadIniFile(This,szNameIniFile,retval)	\
    (This)->lpVtbl -> ReadIniFile(This,szNameIniFile,retval)

#define IFCDualUtil8070_ReadStringIniFile(This,szIniName,pSection,pKey,pDefault,retval)	\
    (This)->lpVtbl -> ReadStringIniFile(This,szIniName,pSection,pKey,pDefault,retval)

#define IFCDualUtil8070_WriteStringIniFile(This,szIniName,pSection,pKey,pValue)	\
    (This)->lpVtbl -> WriteStringIniFile(This,szIniName,pSection,pKey,pValue)

#define IFCDualUtil8070_CloseIniFile(This,szIniName)	\
    (This)->lpVtbl -> CloseIniFile(This,szIniName)

#define IFCDualUtil8070_UTIL8070_DriveStatus(This,drive,driveStatus)	\
    (This)->lpVtbl -> UTIL8070_DriveStatus(This,drive,driveStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_Get8070PathRemote_Proxy( 
    IFCDualUtil8070 * This,
    /* [in] */ PATH8070_T path8070,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualUtil8070_Get8070PathRemote_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_Get8070Path_Proxy( 
    IFCDualUtil8070 * This,
    /* [in] */ PATH8070_T path8070,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualUtil8070_Get8070Path_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_LoadTex_Proxy( 
    IFCDualUtil8070 * This,
    /* [in] */ long id,
    BSTR szDllName,
    /* [defaultvalue][optional][in] */ BOOL bFreeDll,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualUtil8070_LoadTex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_GetResourceHandle_Proxy( 
    IFCDualUtil8070 * This,
    /* [in] */ BSTR szDllSname,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualUtil8070_GetResourceHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_IsVisualizationInInches_Proxy( 
    IFCDualUtil8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ CNC_MODE_T mode,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualUtil8070_IsVisualizationInInches_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_PutVisualizationInInches_Proxy( 
    IFCDualUtil8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ CNC_MODE_T mode,
    /* [in] */ BOOL bModoInches);


void __RPC_STUB IFCDualUtil8070_PutVisualizationInInches_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_GetTuneServiceLevel_Proxy( 
    IFCDualUtil8070 * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualUtil8070_GetTuneServiceLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_GetCNCVersion_Proxy( 
    IFCDualUtil8070 * This,
    /* [out][in] */ short *pVersion,
    /* [out][in] */ short *pRevision,
    /* [out][in] */ short *pSubrevision,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualUtil8070_GetCNCVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_GetCNCDate_Proxy( 
    IFCDualUtil8070 * This,
    /* [out][in] */ short *pDay,
    /* [out][in] */ short *pMonth,
    /* [out][in] */ short *pYear,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualUtil8070_GetCNCDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_AreNewGraphicsActive_Proxy( 
    IFCDualUtil8070 * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualUtil8070_AreNewGraphicsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_ReadIniFile_Proxy( 
    IFCDualUtil8070 * This,
    /* [in] */ BSTR szNameIniFile,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualUtil8070_ReadIniFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_ReadStringIniFile_Proxy( 
    IFCDualUtil8070 * This,
    /* [in] */ BSTR szIniName,
    /* [in] */ BSTR pSection,
    /* [in] */ BSTR pKey,
    /* [in] */ BSTR pDefault,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualUtil8070_ReadStringIniFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_WriteStringIniFile_Proxy( 
    IFCDualUtil8070 * This,
    /* [in] */ BSTR szIniName,
    /* [in] */ BSTR pSection,
    /* [in] */ BSTR pKey,
    /* [in] */ BSTR pValue);


void __RPC_STUB IFCDualUtil8070_WriteStringIniFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_CloseIniFile_Proxy( 
    IFCDualUtil8070 * This,
    /* [in] */ BSTR szIniName);


void __RPC_STUB IFCDualUtil8070_CloseIniFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualUtil8070_UTIL8070_DriveStatus_Proxy( 
    IFCDualUtil8070 * This,
    /* [in] */ DRIVE8070_T drive,
    /* [retval][out] */ DRIVESTATUS8070_T *driveStatus);


void __RPC_STUB IFCDualUtil8070_UTIL8070_DriveStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualUtil8070_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_Utilities,0x34C31FE4,0x0A7D,0x4D2F,0xAF,0xC8,0xDE,0x42,0xF2,0xAA,0xBB,0x81);

#ifdef __cplusplus

class DECLSPEC_UUID("34C31FE4-0A7D-4D2F-AFC8-DE42F2AABB81")
CNC8070_Utilities;
#endif

#ifndef __IFCError_DISPINTERFACE_DEFINED__
#define __IFCError_DISPINTERFACE_DEFINED__

/* dispinterface IFCError */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCError,0xFC26BC6C,0x9B27,0x4678,0xAB,0xEE,0xEB,0xF3,0xE6,0x4B,0x91,0xAF);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FC26BC6C-9B27-4678-ABEE-EBF3E64B91AF")
    IFCError : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCErrorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCError * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCError * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCError * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCError * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCError * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCError * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCError * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCErrorVtbl;

    interface IFCError
    {
        CONST_VTBL struct IFCErrorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCError_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCError_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCError_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCError_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCError_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCError_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCError_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCError_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualError_INTERFACE_DEFINED__
#define __IFCDualError_INTERFACE_DEFINED__

/* interface IFCDualError */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualError,0x38DA9A85,0xB8AD,0x421c,0x93,0x58,0x90,0x7F,0xFA,0x09,0xA3,0x44);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38DA9A85-B8AD-421c-9358-907FFA09A344")
    IFCDualError : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetErrorSource( 
            /* [retval][out] */ ERROR_SOURCE_T *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetErrorID( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetErrorHeading( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetErrorDescription( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetErrorType( 
            /* [retval][out] */ ERROR_TYPE_T *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualErrorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualError * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualError * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualError * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualError * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualError * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualError * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualError * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetErrorSource )( 
            IFCDualError * This,
            /* [retval][out] */ ERROR_SOURCE_T *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetErrorID )( 
            IFCDualError * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetErrorHeading )( 
            IFCDualError * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetErrorDescription )( 
            IFCDualError * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetErrorType )( 
            IFCDualError * This,
            /* [retval][out] */ ERROR_TYPE_T *retval);
        
        END_INTERFACE
    } IFCDualErrorVtbl;

    interface IFCDualError
    {
        CONST_VTBL struct IFCDualErrorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualError_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualError_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualError_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualError_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualError_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualError_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualError_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualError_GetErrorSource(This,retval)	\
    (This)->lpVtbl -> GetErrorSource(This,retval)

#define IFCDualError_GetErrorID(This,retval)	\
    (This)->lpVtbl -> GetErrorID(This,retval)

#define IFCDualError_GetErrorHeading(This,retval)	\
    (This)->lpVtbl -> GetErrorHeading(This,retval)

#define IFCDualError_GetErrorDescription(This,retval)	\
    (This)->lpVtbl -> GetErrorDescription(This,retval)

#define IFCDualError_GetErrorType(This,retval)	\
    (This)->lpVtbl -> GetErrorType(This,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualError_GetErrorSource_Proxy( 
    IFCDualError * This,
    /* [retval][out] */ ERROR_SOURCE_T *retval);


void __RPC_STUB IFCDualError_GetErrorSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualError_GetErrorID_Proxy( 
    IFCDualError * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualError_GetErrorID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualError_GetErrorHeading_Proxy( 
    IFCDualError * This,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualError_GetErrorHeading_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualError_GetErrorDescription_Proxy( 
    IFCDualError * This,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualError_GetErrorDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualError_GetErrorType_Proxy( 
    IFCDualError * This,
    /* [retval][out] */ ERROR_TYPE_T *retval);


void __RPC_STUB IFCDualError_GetErrorType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualError_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_Error,0xEB0A741E,0xF051,0x43CD,0xB8,0x8E,0xC6,0x93,0xFB,0xFB,0xFE,0x08);

#ifdef __cplusplus

class DECLSPEC_UUID("EB0A741E-F051-43CD-B88E-C693FBFBFE08")
CNC8070_Error;
#endif

#ifndef __IFCKernel8070_DISPINTERFACE_DEFINED__
#define __IFCKernel8070_DISPINTERFACE_DEFINED__

/* dispinterface IFCKernel8070 */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCKernel8070,0x9C4C80C3,0xF0BA,0x40C2,0xB1,0xBF,0xCD,0xC1,0xC4,0x3E,0x72,0x89);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9C4C80C3-F0BA-40C2-B1BF-CDC1C43E7289")
    IFCKernel8070 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCKernel8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCKernel8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCKernel8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCKernel8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCKernel8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCKernel8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCKernel8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCKernel8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCKernel8070Vtbl;

    interface IFCKernel8070
    {
        CONST_VTBL struct IFCKernel8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCKernel8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCKernel8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCKernel8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCKernel8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCKernel8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCKernel8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCKernel8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCKernel8070_DISPINTERFACE_DEFINED__ */


#ifndef __IInitKernelReport_DISPINTERFACE_DEFINED__
#define __IInitKernelReport_DISPINTERFACE_DEFINED__

/* dispinterface IInitKernelReport */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_IInitKernelReport,0xFB3A28DD,0x6C41,0x47ee,0x94,0xF4,0x16,0x15,0xE3,0xB0,0xE4,0xB9);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FB3A28DD-6C41-47ee-94F4-1615E3B0E4B9")
    IInitKernelReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IInitKernelReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInitKernelReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInitKernelReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInitKernelReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInitKernelReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInitKernelReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInitKernelReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInitKernelReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IInitKernelReportVtbl;

    interface IInitKernelReport
    {
        CONST_VTBL struct IInitKernelReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInitKernelReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IInitKernelReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IInitKernelReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IInitKernelReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IInitKernelReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IInitKernelReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IInitKernelReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IInitKernelReport_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualKernel8070_INTERFACE_DEFINED__
#define __IFCDualKernel8070_INTERFACE_DEFINED__

/* interface IFCDualKernel8070 */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualKernel8070,0x01751AD4,0x743E,0x4578,0x9B,0x56,0x96,0x35,0x1D,0x18,0x6D,0x01);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("01751AD4-743E-4578-9B56-96351D186D01")
    IFCDualKernel8070 : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitKernel( 
            /* [in] */ BSTR szStartMode,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CloseKernel( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_OffsetStart( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_OffsetStart( 
            /* [in] */ long numcanal,
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_OffsetStartSim( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_OffsetStartSim( 
            /* [in] */ long numcanal,
            /* [in] */ long newValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NextSingleStep( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartAutomBlockSearch( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartBlockSearch( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetMode( 
            /* [in] */ long numcanal,
            /* [in] */ long mode,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearFeedhold( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExecBlock( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR str_block,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE KernelExist( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE KernelExistSim( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartProgram( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetFeedhold( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE KernelReset( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE KernelResetSim( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearFeedholdSim( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddLogOnInfo( 
            /* [in] */ BSTR info) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartKernel( 
            /* [in] */ long phase,
            /* [in] */ BOOL sbKernel,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartKernelSim( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE EndKernel( 
            /* [in] */ long phase,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE EndKernelSim( 
            /* [in] */ long phase,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetLogOnFile( 
            /* [in] */ BSTR file) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartRequest( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NextSingleStepSim( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartProgramSim( 
            /* [in] */ long numcanal,
            /* [in] */ SIMULATION_OPTIONS_T options,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetFeedholdSim( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartProgramSintaxCheck( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartProgramExecTime( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SkipBlock( 
            /* [in] */ long numcanal,
            /* [in] */ BOOL bActivate,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SimulateM01( 
            /* [in] */ long numcanal,
            /* [in] */ BOOL bActivate,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SWLimitsON( 
            /* [in] */ long numcanal,
            /* [in] */ BOOL bActivate,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadError( 
            /* [in] */ long nError,
            /* [retval][out] */ IFCDualError **iError) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadErrorSim( 
            /* [in] */ long nError,
            /* [retval][out] */ IFCDualError **iError) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ResetError( 
            /* [in] */ long nError,
            /* [in] */ ERROR_TYPE_T type,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ResetErrorSim( 
            /* [in] */ long nError,
            /* [in] */ ERROR_TYPE_T type,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SelectProgram( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExecProgram( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetKernelMode( 
            /* [in] */ long numcanal,
            /* [in] */ BOOL bManual,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GiveRepositionAxes( 
            /* [in] */ long numcanal,
            /* [out] */ VARIANT *ArrayAxes,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE EndInspection( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Reposition( 
            /* [in] */ long numcanal,
            /* [in] */ short *array_axes,
            /* [in] */ long tipoInspeccion,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ActivateInspection( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RepositionStrAxes( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR strAxes,
            /* [in] */ int tipoInspeccion,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RepositionAxes( 
            /* [in] */ long numcanal,
            /* [in] */ VARIANT *ArrayAxes,
            /* [in] */ long tipoInspeccion,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsPossibleAutomBlockSearch( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SelectProgramSim( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExecProgramSim( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog,
            /* [in] */ SIMULATION_OPTIONS_T options,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StopConditionInSubrut( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StopConditionInSubrut( 
            /* [in] */ long numcanal,
            /* [in] */ BOOL newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StopConditionFileOffset( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StopConditionFileOffset( 
            /* [in] */ long numcanal,
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StopConditionFileName( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StopConditionFileName( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StopConditionNumTimes( 
            /* [in] */ long numcanal,
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StopConditionNumTimes( 
            /* [in] */ long numcanal,
            /* [in] */ short newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockSearchStartFileOffset( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockSearchStartFileOffset( 
            /* [in] */ long numcanal,
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockSearchStartInSubr( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockSearchStartInSubr( 
            /* [in] */ long numcanal,
            /* [in] */ BOOL newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockSearchStartFileName( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockSearchStartFileName( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockSearchStartNumTimes( 
            /* [in] */ long numcanal,
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockSearchStartNumTimes( 
            /* [in] */ long numcanal,
            /* [in] */ short newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StopConditionInSubrutSim( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StopConditionInSubrutSim( 
            /* [in] */ long numcanal,
            /* [in] */ BOOL newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StopConditionFileOffsetSim( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StopConditionFileOffsetSim( 
            /* [in] */ long numcanal,
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StopConditionFileNameSim( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StopConditionFileNameSim( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StopConditionNumTimesSim( 
            /* [in] */ long numcanal,
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StopConditionNumTimesSim( 
            /* [in] */ long numcanal,
            /* [in] */ short newValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AreAxisRepositionated( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TEProdTime( 
            /* [in] */ long numcanal,
            /* [retval][out] */ double *dRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetProdTimeData( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TENumM( 
            /* [in] */ long numcanal,
            /* [retval][out] */ short *sRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TENumM6( 
            /* [in] */ long numcanal,
            /* [retval][out] */ short *sRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TENumT( 
            /* [in] */ long numcanal,
            /* [retval][out] */ short *sRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TETimeNumT( 
            /* [in] */ long numcanal,
            /* [in] */ long index,
            /* [retval][out] */ long *lRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TETimePosic( 
            /* [in] */ long numcanal,
            /* [in] */ long index,
            /* [retval][out] */ double *dRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TETimeMec( 
            /* [in] */ long numcanal,
            /* [in] */ long index,
            /* [retval][out] */ double *dRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE TELastPDU( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsPossibleInspection( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE LoadOffset( 
            /* [in] */ long numcanal,
            /* [in] */ short index,
            /* [in] */ VARIANT *arrayOffsets,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAxisChannel( 
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PreSelection( 
            /* [in] */ BSTR str_axis,
            /* [in] */ double value,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ZeroSearch( 
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNumChannels( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExecSimOtherProgram( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog,
            /* [in] */ SIMULATION_OPTIONS_T options,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetOpenedFilesList( 
            /* [in] */ short modoEjec,
            /* [in] */ long sizeDest,
            /* [retval][out] */ BSTR *pOpenedFilesList) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE Oscillation( 
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ChannelStartRequest( 
            /* [in] */ long channel) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExecBlockEx( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR str_block,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetDiagnosisOptions( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetPuntoDeInterrupcion( 
            /* [in] */ short modoEjec,
            /* [in] */ long sizeDest,
            /* [retval][out] */ BSTR *pPuntoDeInterrupcion) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReconfigPuntoDeInterrupcion( 
            /* [in] */ long numBlqAntesPtoInterrupcion,
            /* [in] */ long sizeDest,
            /* [retval][out] */ BSTR *pOffsetAnterior) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNumElemFifoOffAnterior( 
            /* [in] */ short dummy,
            /* [in] */ long sizeDest,
            /* [retval][out] */ BSTR *pData) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_fOptimizacionCad( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_fOptimizacionCad( 
            /* [in] */ long numcanal,
            /* [in] */ long newValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetStackElem( 
            /* [in] */ long index,
            /* [in] */ long nChannel,
            /* [in] */ long modo,
            /* [retval][out] */ BSTR *pElement) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAxisIndex( 
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCSOffsetData( 
            /* [in] */ double offset1,
            /* [in] */ double offset2,
            /* [in] */ double offset3) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCSRotationData( 
            /* [in] */ double rot1,
            /* [in] */ double rot2,
            /* [in] */ double rot3) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCSMode( 
            /* [in] */ short mode) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetCSAlignedAxis( 
            /* [in] */ short alignedAxis) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetProgrammedCS( 
            /* [out][in] */ double *x1,
            /* [out][in] */ double *y1,
            /* [out][in] */ double *z1,
            /* [out][in] */ double *x2,
            /* [out][in] */ double *y2,
            /* [out][in] */ double *z2,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetActiveCS( 
            /* [out][in] */ double *x1,
            /* [out][in] */ double *y1,
            /* [out][in] */ double *z1,
            /* [out][in] */ double *x2,
            /* [out][in] */ double *y2,
            /* [out][in] */ double *z2,
            /* [in] */ short bSimul,
            /* [in] */ short canal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCabezalPerpendicularCS( 
            /* [out][in] */ BSTR *pCab0Name,
            /* [out][in] */ double *pCab0Pos,
            /* [out][in] */ BSTR *pCab1Name,
            /* [out][in] */ double *pCab1Pos,
            /* [out][in] */ short *pSolValida,
            /* [in] */ short bSimul,
            /* [in] */ short canal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ProgCancel( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BlockSearchStartFileNameWithPath( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BlockSearchStartFileNameWithPath( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR newValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetDiagnosisVersion( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSyntaxCheckFileName( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BOffsetStartParaInspeccion( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BOffsetStartParaInspeccion( 
            /* [in] */ long numcanal,
            /* [in] */ long newValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAxisLog( 
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowWarningSimple( 
            /* [in] */ long nCanal,
            /* [in] */ long errorID,
            /* [in] */ long errorKlasse,
            /* [in] */ BSTR modul,
            /* [in] */ long line,
            /* [in] */ long modo,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GiveRepositionAxes2( 
            /* [in] */ long numcanal,
            /* [in] */ VARIANT *ArrayAxes,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ActivateReposition( 
            /* [in] */ long numcanal,
            /* [in] */ long modo_reposition,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAxisName( 
            /* [in] */ long index,
            /* [in] */ long nCanal,
            /* [out] */ BSTR *name,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FocusChannel( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConvertLogToIdx( 
            /* [in] */ long numLog,
            /* [out] */ long *index,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLogicNumber( 
            /* [in] */ long index,
            /* [in] */ long nCanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsNewInspecAllowed( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsSpindleForReposition( 
            /* [in] */ long nChannel,
            /* [in] */ BSTR sEje,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CheckVarsReposition2( 
            long nCanal,
            long nIndexAxisChannel,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReleaseKernelMem( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CancelReposition( 
            long nCanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExecProgramNoChangeProgSelect( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SelectProgramNoChangeProgSelect( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsPossibleInspection2( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetMdiInternalMode( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE EndMdiInternalMode( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE G0orG1withF( 
            /* [in] */ long numcanal,
            /* [in] */ BSTR pAxisName,
            /* [in] */ long *pFeedRate,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsResetPreInspecReady( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ResetInspec( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InspectionSaveIntPoint( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsInspecOnlyReposPtoIni( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CncModel( 
            /* [retval][out] */ long *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetDiagnosisOptions2( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsProgSelectInStack( 
            /* [in] */ BSTR *pProgSelect,
            /* [in] */ long size,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsChannelInInspecInterruption( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetPuntoDeCancelacion( 
            /* [in] */ short modoEjec,
            /* [in] */ long sizeDest,
            /* [retval][out] */ BSTR *pPuntoDeInterrupcion) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PosibleCancelContinue( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CancelContinue( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartTrasCancelContinue( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE EscCancelContinue( 
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CancelContinueInitialFileOffset( 
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_CancelContinueInitialFileOffset( 
            /* [in] */ long numcanal,
            /* [in] */ long newValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetIndexFromSpdlName( 
            /* [in] */ BSTR nameSpdl,
            /* [retval][out] */ long *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualKernel8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualKernel8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualKernel8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualKernel8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualKernel8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualKernel8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualKernel8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualKernel8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitKernel )( 
            IFCDualKernel8070 * This,
            /* [in] */ BSTR szStartMode,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CloseKernel )( 
            IFCDualKernel8070 * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OffsetStart )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OffsetStart )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_OffsetStartSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_OffsetStartSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long newValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *NextSingleStep )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartAutomBlockSearch )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartBlockSearch )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetMode )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long mode,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearFeedhold )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExecBlock )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR str_block,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *KernelExist )( 
            IFCDualKernel8070 * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *KernelExistSim )( 
            IFCDualKernel8070 * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartProgram )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetFeedhold )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *KernelReset )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *KernelResetSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ClearFeedholdSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddLogOnInfo )( 
            IFCDualKernel8070 * This,
            /* [in] */ BSTR info);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartKernel )( 
            IFCDualKernel8070 * This,
            /* [in] */ long phase,
            /* [in] */ BOOL sbKernel,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartKernelSim )( 
            IFCDualKernel8070 * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EndKernel )( 
            IFCDualKernel8070 * This,
            /* [in] */ long phase,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EndKernelSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long phase,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetLogOnFile )( 
            IFCDualKernel8070 * This,
            /* [in] */ BSTR file);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartRequest )( 
            IFCDualKernel8070 * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *NextSingleStepSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartProgramSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ SIMULATION_OPTIONS_T options,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetFeedholdSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartProgramSintaxCheck )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartProgramExecTime )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SkipBlock )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BOOL bActivate,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SimulateM01 )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BOOL bActivate,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SWLimitsON )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BOOL bActivate,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadError )( 
            IFCDualKernel8070 * This,
            /* [in] */ long nError,
            /* [retval][out] */ IFCDualError **iError);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadErrorSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long nError,
            /* [retval][out] */ IFCDualError **iError);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ResetError )( 
            IFCDualKernel8070 * This,
            /* [in] */ long nError,
            /* [in] */ ERROR_TYPE_T type,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ResetErrorSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long nError,
            /* [in] */ ERROR_TYPE_T type,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SelectProgram )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExecProgram )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetKernelMode )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BOOL bManual,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GiveRepositionAxes )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [out] */ VARIANT *ArrayAxes,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EndInspection )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Reposition )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ short *array_axes,
            /* [in] */ long tipoInspeccion,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ActivateInspection )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RepositionStrAxes )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR strAxes,
            /* [in] */ int tipoInspeccion,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RepositionAxes )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ VARIANT *ArrayAxes,
            /* [in] */ long tipoInspeccion,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsPossibleAutomBlockSearch )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SelectProgramSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExecProgramSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog,
            /* [in] */ SIMULATION_OPTIONS_T options,
            /* [retval][out] */ long *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StopConditionInSubrut )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StopConditionInSubrut )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BOOL newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StopConditionFileOffset )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StopConditionFileOffset )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StopConditionFileName )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StopConditionFileName )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StopConditionNumTimes )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ short *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StopConditionNumTimes )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ short newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockSearchStartFileOffset )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockSearchStartFileOffset )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockSearchStartInSubr )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockSearchStartInSubr )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BOOL newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockSearchStartFileName )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockSearchStartFileName )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockSearchStartNumTimes )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ short *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockSearchStartNumTimes )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ short newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StopConditionInSubrutSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StopConditionInSubrutSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BOOL newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StopConditionFileOffsetSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StopConditionFileOffsetSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StopConditionFileNameSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StopConditionFileNameSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StopConditionNumTimesSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ short *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StopConditionNumTimesSim )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ short newValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AreAxisRepositionated )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TEProdTime )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ double *dRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetProdTimeData )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TENumM )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ short *sRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TENumM6 )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ short *sRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TENumT )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ short *sRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TETimeNumT )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long index,
            /* [retval][out] */ long *lRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TETimePosic )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long index,
            /* [retval][out] */ double *dRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TETimeMec )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long index,
            /* [retval][out] */ double *dRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *TELastPDU )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsPossibleInspection )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *LoadOffset )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ short index,
            /* [in] */ VARIANT *arrayOffsets,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAxisChannel )( 
            IFCDualKernel8070 * This,
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PreSelection )( 
            IFCDualKernel8070 * This,
            /* [in] */ BSTR str_axis,
            /* [in] */ double value,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ZeroSearch )( 
            IFCDualKernel8070 * This,
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNumChannels )( 
            IFCDualKernel8070 * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExecSimOtherProgram )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog,
            /* [in] */ SIMULATION_OPTIONS_T options,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetOpenedFilesList )( 
            IFCDualKernel8070 * This,
            /* [in] */ short modoEjec,
            /* [in] */ long sizeDest,
            /* [retval][out] */ BSTR *pOpenedFilesList);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *Oscillation )( 
            IFCDualKernel8070 * This,
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ChannelStartRequest )( 
            IFCDualKernel8070 * This,
            /* [in] */ long channel);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExecBlockEx )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR str_block,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetDiagnosisOptions )( 
            IFCDualKernel8070 * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetPuntoDeInterrupcion )( 
            IFCDualKernel8070 * This,
            /* [in] */ short modoEjec,
            /* [in] */ long sizeDest,
            /* [retval][out] */ BSTR *pPuntoDeInterrupcion);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReconfigPuntoDeInterrupcion )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numBlqAntesPtoInterrupcion,
            /* [in] */ long sizeDest,
            /* [retval][out] */ BSTR *pOffsetAnterior);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNumElemFifoOffAnterior )( 
            IFCDualKernel8070 * This,
            /* [in] */ short dummy,
            /* [in] */ long sizeDest,
            /* [retval][out] */ BSTR *pData);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_fOptimizacionCad )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_fOptimizacionCad )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long newValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetStackElem )( 
            IFCDualKernel8070 * This,
            /* [in] */ long index,
            /* [in] */ long nChannel,
            /* [in] */ long modo,
            /* [retval][out] */ BSTR *pElement);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAxisIndex )( 
            IFCDualKernel8070 * This,
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCSOffsetData )( 
            IFCDualKernel8070 * This,
            /* [in] */ double offset1,
            /* [in] */ double offset2,
            /* [in] */ double offset3);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCSRotationData )( 
            IFCDualKernel8070 * This,
            /* [in] */ double rot1,
            /* [in] */ double rot2,
            /* [in] */ double rot3);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCSMode )( 
            IFCDualKernel8070 * This,
            /* [in] */ short mode);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetCSAlignedAxis )( 
            IFCDualKernel8070 * This,
            /* [in] */ short alignedAxis);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetProgrammedCS )( 
            IFCDualKernel8070 * This,
            /* [out][in] */ double *x1,
            /* [out][in] */ double *y1,
            /* [out][in] */ double *z1,
            /* [out][in] */ double *x2,
            /* [out][in] */ double *y2,
            /* [out][in] */ double *z2,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetActiveCS )( 
            IFCDualKernel8070 * This,
            /* [out][in] */ double *x1,
            /* [out][in] */ double *y1,
            /* [out][in] */ double *z1,
            /* [out][in] */ double *x2,
            /* [out][in] */ double *y2,
            /* [out][in] */ double *z2,
            /* [in] */ short bSimul,
            /* [in] */ short canal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCabezalPerpendicularCS )( 
            IFCDualKernel8070 * This,
            /* [out][in] */ BSTR *pCab0Name,
            /* [out][in] */ double *pCab0Pos,
            /* [out][in] */ BSTR *pCab1Name,
            /* [out][in] */ double *pCab1Pos,
            /* [out][in] */ short *pSolValida,
            /* [in] */ short bSimul,
            /* [in] */ short canal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ProgCancel )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BlockSearchStartFileNameWithPath )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BlockSearchStartFileNameWithPath )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR newValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetDiagnosisVersion )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetSyntaxCheckFileName )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BOffsetStartParaInspeccion )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BOffsetStartParaInspeccion )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long newValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAxisLog )( 
            IFCDualKernel8070 * This,
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ShowWarningSimple )( 
            IFCDualKernel8070 * This,
            /* [in] */ long nCanal,
            /* [in] */ long errorID,
            /* [in] */ long errorKlasse,
            /* [in] */ BSTR modul,
            /* [in] */ long line,
            /* [in] */ long modo,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GiveRepositionAxes2 )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ VARIANT *ArrayAxes,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ActivateReposition )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long modo_reposition,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAxisName )( 
            IFCDualKernel8070 * This,
            /* [in] */ long index,
            /* [in] */ long nCanal,
            /* [out] */ BSTR *name,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *FocusChannel )( 
            IFCDualKernel8070 * This,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConvertLogToIdx )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numLog,
            /* [out] */ long *index,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLogicNumber )( 
            IFCDualKernel8070 * This,
            /* [in] */ long index,
            /* [in] */ long nCanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsNewInspecAllowed )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsSpindleForReposition )( 
            IFCDualKernel8070 * This,
            /* [in] */ long nChannel,
            /* [in] */ BSTR sEje,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CheckVarsReposition2 )( 
            IFCDualKernel8070 * This,
            long nCanal,
            long nIndexAxisChannel,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseKernelMem )( 
            IFCDualKernel8070 * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CancelReposition )( 
            IFCDualKernel8070 * This,
            long nCanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExecProgramNoChangeProgSelect )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SelectProgramNoChangeProgSelect )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR sprog);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsPossibleInspection2 )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetMdiInternalMode )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EndMdiInternalMode )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *G0orG1withF )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ BSTR pAxisName,
            /* [in] */ long *pFeedRate,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsResetPreInspecReady )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ResetInspec )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InspectionSaveIntPoint )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsInspecOnlyReposPtoIni )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CncModel )( 
            IFCDualKernel8070 * This,
            /* [retval][out] */ long *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetDiagnosisOptions2 )( 
            IFCDualKernel8070 * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsProgSelectInStack )( 
            IFCDualKernel8070 * This,
            /* [in] */ BSTR *pProgSelect,
            /* [in] */ long size,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsChannelInInspecInterruption )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetPuntoDeCancelacion )( 
            IFCDualKernel8070 * This,
            /* [in] */ short modoEjec,
            /* [in] */ long sizeDest,
            /* [retval][out] */ BSTR *pPuntoDeInterrupcion);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PosibleCancelContinue )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CancelContinue )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartTrasCancelContinue )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EscCancelContinue )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ BOOL *bRet);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CancelContinueInitialFileOffset )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CancelContinueInitialFileOffset )( 
            IFCDualKernel8070 * This,
            /* [in] */ long numcanal,
            /* [in] */ long newValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetIndexFromSpdlName )( 
            IFCDualKernel8070 * This,
            /* [in] */ BSTR nameSpdl,
            /* [retval][out] */ long *retval);
        
        END_INTERFACE
    } IFCDualKernel8070Vtbl;

    interface IFCDualKernel8070
    {
        CONST_VTBL struct IFCDualKernel8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualKernel8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualKernel8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualKernel8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualKernel8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualKernel8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualKernel8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualKernel8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualKernel8070_InitKernel(This,szStartMode,retval)	\
    (This)->lpVtbl -> InitKernel(This,szStartMode,retval)

#define IFCDualKernel8070_CloseKernel(This,retval)	\
    (This)->lpVtbl -> CloseKernel(This,retval)

#define IFCDualKernel8070_get_OffsetStart(This,numcanal,retval)	\
    (This)->lpVtbl -> get_OffsetStart(This,numcanal,retval)

#define IFCDualKernel8070_put_OffsetStart(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_OffsetStart(This,numcanal,newValue)

#define IFCDualKernel8070_get_OffsetStartSim(This,numcanal,retval)	\
    (This)->lpVtbl -> get_OffsetStartSim(This,numcanal,retval)

#define IFCDualKernel8070_put_OffsetStartSim(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_OffsetStartSim(This,numcanal,newValue)

#define IFCDualKernel8070_NextSingleStep(This,numcanal,retval)	\
    (This)->lpVtbl -> NextSingleStep(This,numcanal,retval)

#define IFCDualKernel8070_StartAutomBlockSearch(This,numcanal,retval)	\
    (This)->lpVtbl -> StartAutomBlockSearch(This,numcanal,retval)

#define IFCDualKernel8070_StartBlockSearch(This,numcanal,retval)	\
    (This)->lpVtbl -> StartBlockSearch(This,numcanal,retval)

#define IFCDualKernel8070_SetMode(This,numcanal,mode,retval)	\
    (This)->lpVtbl -> SetMode(This,numcanal,mode,retval)

#define IFCDualKernel8070_ClearFeedhold(This,numcanal,retval)	\
    (This)->lpVtbl -> ClearFeedhold(This,numcanal,retval)

#define IFCDualKernel8070_ExecBlock(This,numcanal,str_block,retval)	\
    (This)->lpVtbl -> ExecBlock(This,numcanal,str_block,retval)

#define IFCDualKernel8070_KernelExist(This,retval)	\
    (This)->lpVtbl -> KernelExist(This,retval)

#define IFCDualKernel8070_KernelExistSim(This,retval)	\
    (This)->lpVtbl -> KernelExistSim(This,retval)

#define IFCDualKernel8070_StartProgram(This,numcanal,retval)	\
    (This)->lpVtbl -> StartProgram(This,numcanal,retval)

#define IFCDualKernel8070_SetFeedhold(This,numcanal,retval)	\
    (This)->lpVtbl -> SetFeedhold(This,numcanal,retval)

#define IFCDualKernel8070_KernelReset(This,numcanal,retval)	\
    (This)->lpVtbl -> KernelReset(This,numcanal,retval)

#define IFCDualKernel8070_KernelResetSim(This,numcanal,retval)	\
    (This)->lpVtbl -> KernelResetSim(This,numcanal,retval)

#define IFCDualKernel8070_ClearFeedholdSim(This,numcanal,retval)	\
    (This)->lpVtbl -> ClearFeedholdSim(This,numcanal,retval)

#define IFCDualKernel8070_AddLogOnInfo(This,info)	\
    (This)->lpVtbl -> AddLogOnInfo(This,info)

#define IFCDualKernel8070_StartKernel(This,phase,sbKernel,retval)	\
    (This)->lpVtbl -> StartKernel(This,phase,sbKernel,retval)

#define IFCDualKernel8070_StartKernelSim(This,retval)	\
    (This)->lpVtbl -> StartKernelSim(This,retval)

#define IFCDualKernel8070_EndKernel(This,phase,retval)	\
    (This)->lpVtbl -> EndKernel(This,phase,retval)

#define IFCDualKernel8070_EndKernelSim(This,phase,retval)	\
    (This)->lpVtbl -> EndKernelSim(This,phase,retval)

#define IFCDualKernel8070_SetLogOnFile(This,file)	\
    (This)->lpVtbl -> SetLogOnFile(This,file)

#define IFCDualKernel8070_StartRequest(This)	\
    (This)->lpVtbl -> StartRequest(This)

#define IFCDualKernel8070_NextSingleStepSim(This,numcanal,retval)	\
    (This)->lpVtbl -> NextSingleStepSim(This,numcanal,retval)

#define IFCDualKernel8070_StartProgramSim(This,numcanal,options,retval)	\
    (This)->lpVtbl -> StartProgramSim(This,numcanal,options,retval)

#define IFCDualKernel8070_SetFeedholdSim(This,numcanal,retval)	\
    (This)->lpVtbl -> SetFeedholdSim(This,numcanal,retval)

#define IFCDualKernel8070_StartProgramSintaxCheck(This,numcanal,retval)	\
    (This)->lpVtbl -> StartProgramSintaxCheck(This,numcanal,retval)

#define IFCDualKernel8070_StartProgramExecTime(This,numcanal,retval)	\
    (This)->lpVtbl -> StartProgramExecTime(This,numcanal,retval)

#define IFCDualKernel8070_SkipBlock(This,numcanal,bActivate,retval)	\
    (This)->lpVtbl -> SkipBlock(This,numcanal,bActivate,retval)

#define IFCDualKernel8070_SimulateM01(This,numcanal,bActivate,retval)	\
    (This)->lpVtbl -> SimulateM01(This,numcanal,bActivate,retval)

#define IFCDualKernel8070_SWLimitsON(This,numcanal,bActivate,retval)	\
    (This)->lpVtbl -> SWLimitsON(This,numcanal,bActivate,retval)

#define IFCDualKernel8070_ReadError(This,nError,iError)	\
    (This)->lpVtbl -> ReadError(This,nError,iError)

#define IFCDualKernel8070_ReadErrorSim(This,nError,iError)	\
    (This)->lpVtbl -> ReadErrorSim(This,nError,iError)

#define IFCDualKernel8070_ResetError(This,nError,type,retval)	\
    (This)->lpVtbl -> ResetError(This,nError,type,retval)

#define IFCDualKernel8070_ResetErrorSim(This,nError,type,retval)	\
    (This)->lpVtbl -> ResetErrorSim(This,nError,type,retval)

#define IFCDualKernel8070_SelectProgram(This,numcanal,sprog)	\
    (This)->lpVtbl -> SelectProgram(This,numcanal,sprog)

#define IFCDualKernel8070_ExecProgram(This,numcanal,sprog)	\
    (This)->lpVtbl -> ExecProgram(This,numcanal,sprog)

#define IFCDualKernel8070_SetKernelMode(This,numcanal,bManual,retval)	\
    (This)->lpVtbl -> SetKernelMode(This,numcanal,bManual,retval)

#define IFCDualKernel8070_GiveRepositionAxes(This,numcanal,ArrayAxes,retval)	\
    (This)->lpVtbl -> GiveRepositionAxes(This,numcanal,ArrayAxes,retval)

#define IFCDualKernel8070_EndInspection(This,numcanal,retval)	\
    (This)->lpVtbl -> EndInspection(This,numcanal,retval)

#define IFCDualKernel8070_Reposition(This,numcanal,array_axes,tipoInspeccion,retval)	\
    (This)->lpVtbl -> Reposition(This,numcanal,array_axes,tipoInspeccion,retval)

#define IFCDualKernel8070_ActivateInspection(This,numcanal,retval)	\
    (This)->lpVtbl -> ActivateInspection(This,numcanal,retval)

#define IFCDualKernel8070_RepositionStrAxes(This,numcanal,strAxes,tipoInspeccion,retval)	\
    (This)->lpVtbl -> RepositionStrAxes(This,numcanal,strAxes,tipoInspeccion,retval)

#define IFCDualKernel8070_RepositionAxes(This,numcanal,ArrayAxes,tipoInspeccion,retval)	\
    (This)->lpVtbl -> RepositionAxes(This,numcanal,ArrayAxes,tipoInspeccion,retval)

#define IFCDualKernel8070_IsPossibleAutomBlockSearch(This,numcanal,bRet)	\
    (This)->lpVtbl -> IsPossibleAutomBlockSearch(This,numcanal,bRet)

#define IFCDualKernel8070_SelectProgramSim(This,numcanal,sprog)	\
    (This)->lpVtbl -> SelectProgramSim(This,numcanal,sprog)

#define IFCDualKernel8070_ExecProgramSim(This,numcanal,sprog,options,retval)	\
    (This)->lpVtbl -> ExecProgramSim(This,numcanal,sprog,options,retval)

#define IFCDualKernel8070_get_StopConditionInSubrut(This,numcanal,retval)	\
    (This)->lpVtbl -> get_StopConditionInSubrut(This,numcanal,retval)

#define IFCDualKernel8070_put_StopConditionInSubrut(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_StopConditionInSubrut(This,numcanal,newValue)

#define IFCDualKernel8070_get_StopConditionFileOffset(This,numcanal,retval)	\
    (This)->lpVtbl -> get_StopConditionFileOffset(This,numcanal,retval)

#define IFCDualKernel8070_put_StopConditionFileOffset(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_StopConditionFileOffset(This,numcanal,newValue)

#define IFCDualKernel8070_get_StopConditionFileName(This,numcanal,retval)	\
    (This)->lpVtbl -> get_StopConditionFileName(This,numcanal,retval)

#define IFCDualKernel8070_put_StopConditionFileName(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_StopConditionFileName(This,numcanal,newValue)

#define IFCDualKernel8070_get_StopConditionNumTimes(This,numcanal,retval)	\
    (This)->lpVtbl -> get_StopConditionNumTimes(This,numcanal,retval)

#define IFCDualKernel8070_put_StopConditionNumTimes(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_StopConditionNumTimes(This,numcanal,newValue)

#define IFCDualKernel8070_get_BlockSearchStartFileOffset(This,numcanal,retval)	\
    (This)->lpVtbl -> get_BlockSearchStartFileOffset(This,numcanal,retval)

#define IFCDualKernel8070_put_BlockSearchStartFileOffset(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_BlockSearchStartFileOffset(This,numcanal,newValue)

#define IFCDualKernel8070_get_BlockSearchStartInSubr(This,numcanal,retval)	\
    (This)->lpVtbl -> get_BlockSearchStartInSubr(This,numcanal,retval)

#define IFCDualKernel8070_put_BlockSearchStartInSubr(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_BlockSearchStartInSubr(This,numcanal,newValue)

#define IFCDualKernel8070_get_BlockSearchStartFileName(This,numcanal,retval)	\
    (This)->lpVtbl -> get_BlockSearchStartFileName(This,numcanal,retval)

#define IFCDualKernel8070_put_BlockSearchStartFileName(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_BlockSearchStartFileName(This,numcanal,newValue)

#define IFCDualKernel8070_get_BlockSearchStartNumTimes(This,numcanal,retval)	\
    (This)->lpVtbl -> get_BlockSearchStartNumTimes(This,numcanal,retval)

#define IFCDualKernel8070_put_BlockSearchStartNumTimes(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_BlockSearchStartNumTimes(This,numcanal,newValue)

#define IFCDualKernel8070_get_StopConditionInSubrutSim(This,numcanal,retval)	\
    (This)->lpVtbl -> get_StopConditionInSubrutSim(This,numcanal,retval)

#define IFCDualKernel8070_put_StopConditionInSubrutSim(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_StopConditionInSubrutSim(This,numcanal,newValue)

#define IFCDualKernel8070_get_StopConditionFileOffsetSim(This,numcanal,retval)	\
    (This)->lpVtbl -> get_StopConditionFileOffsetSim(This,numcanal,retval)

#define IFCDualKernel8070_put_StopConditionFileOffsetSim(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_StopConditionFileOffsetSim(This,numcanal,newValue)

#define IFCDualKernel8070_get_StopConditionFileNameSim(This,numcanal,retval)	\
    (This)->lpVtbl -> get_StopConditionFileNameSim(This,numcanal,retval)

#define IFCDualKernel8070_put_StopConditionFileNameSim(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_StopConditionFileNameSim(This,numcanal,newValue)

#define IFCDualKernel8070_get_StopConditionNumTimesSim(This,numcanal,retval)	\
    (This)->lpVtbl -> get_StopConditionNumTimesSim(This,numcanal,retval)

#define IFCDualKernel8070_put_StopConditionNumTimesSim(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_StopConditionNumTimesSim(This,numcanal,newValue)

#define IFCDualKernel8070_AreAxisRepositionated(This,numcanal,bRet)	\
    (This)->lpVtbl -> AreAxisRepositionated(This,numcanal,bRet)

#define IFCDualKernel8070_TEProdTime(This,numcanal,dRet)	\
    (This)->lpVtbl -> TEProdTime(This,numcanal,dRet)

#define IFCDualKernel8070_GetProdTimeData(This,numcanal,bRet)	\
    (This)->lpVtbl -> GetProdTimeData(This,numcanal,bRet)

#define IFCDualKernel8070_TENumM(This,numcanal,sRet)	\
    (This)->lpVtbl -> TENumM(This,numcanal,sRet)

#define IFCDualKernel8070_TENumM6(This,numcanal,sRet)	\
    (This)->lpVtbl -> TENumM6(This,numcanal,sRet)

#define IFCDualKernel8070_TENumT(This,numcanal,sRet)	\
    (This)->lpVtbl -> TENumT(This,numcanal,sRet)

#define IFCDualKernel8070_TETimeNumT(This,numcanal,index,lRet)	\
    (This)->lpVtbl -> TETimeNumT(This,numcanal,index,lRet)

#define IFCDualKernel8070_TETimePosic(This,numcanal,index,dRet)	\
    (This)->lpVtbl -> TETimePosic(This,numcanal,index,dRet)

#define IFCDualKernel8070_TETimeMec(This,numcanal,index,dRet)	\
    (This)->lpVtbl -> TETimeMec(This,numcanal,index,dRet)

#define IFCDualKernel8070_TELastPDU(This,numcanal,bRet)	\
    (This)->lpVtbl -> TELastPDU(This,numcanal,bRet)

#define IFCDualKernel8070_IsPossibleInspection(This,numcanal,bRet)	\
    (This)->lpVtbl -> IsPossibleInspection(This,numcanal,bRet)

#define IFCDualKernel8070_LoadOffset(This,numcanal,index,arrayOffsets,retval)	\
    (This)->lpVtbl -> LoadOffset(This,numcanal,index,arrayOffsets,retval)

#define IFCDualKernel8070_GetAxisChannel(This,str_axis,retval)	\
    (This)->lpVtbl -> GetAxisChannel(This,str_axis,retval)

#define IFCDualKernel8070_PreSelection(This,str_axis,value,retval)	\
    (This)->lpVtbl -> PreSelection(This,str_axis,value,retval)

#define IFCDualKernel8070_ZeroSearch(This,str_axis,retval)	\
    (This)->lpVtbl -> ZeroSearch(This,str_axis,retval)

#define IFCDualKernel8070_GetNumChannels(This,retval)	\
    (This)->lpVtbl -> GetNumChannels(This,retval)

#define IFCDualKernel8070_ExecSimOtherProgram(This,numcanal,sprog,options,retval)	\
    (This)->lpVtbl -> ExecSimOtherProgram(This,numcanal,sprog,options,retval)

#define IFCDualKernel8070_GetOpenedFilesList(This,modoEjec,sizeDest,pOpenedFilesList)	\
    (This)->lpVtbl -> GetOpenedFilesList(This,modoEjec,sizeDest,pOpenedFilesList)

#define IFCDualKernel8070_Oscillation(This,str_axis,retval)	\
    (This)->lpVtbl -> Oscillation(This,str_axis,retval)

#define IFCDualKernel8070_ChannelStartRequest(This,channel)	\
    (This)->lpVtbl -> ChannelStartRequest(This,channel)

#define IFCDualKernel8070_ExecBlockEx(This,numcanal,str_block,retval)	\
    (This)->lpVtbl -> ExecBlockEx(This,numcanal,str_block,retval)

#define IFCDualKernel8070_GetDiagnosisOptions(This,retval)	\
    (This)->lpVtbl -> GetDiagnosisOptions(This,retval)

#define IFCDualKernel8070_GetPuntoDeInterrupcion(This,modoEjec,sizeDest,pPuntoDeInterrupcion)	\
    (This)->lpVtbl -> GetPuntoDeInterrupcion(This,modoEjec,sizeDest,pPuntoDeInterrupcion)

#define IFCDualKernel8070_ReconfigPuntoDeInterrupcion(This,numBlqAntesPtoInterrupcion,sizeDest,pOffsetAnterior)	\
    (This)->lpVtbl -> ReconfigPuntoDeInterrupcion(This,numBlqAntesPtoInterrupcion,sizeDest,pOffsetAnterior)

#define IFCDualKernel8070_GetNumElemFifoOffAnterior(This,dummy,sizeDest,pData)	\
    (This)->lpVtbl -> GetNumElemFifoOffAnterior(This,dummy,sizeDest,pData)

#define IFCDualKernel8070_get_fOptimizacionCad(This,numcanal,retval)	\
    (This)->lpVtbl -> get_fOptimizacionCad(This,numcanal,retval)

#define IFCDualKernel8070_put_fOptimizacionCad(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_fOptimizacionCad(This,numcanal,newValue)

#define IFCDualKernel8070_GetStackElem(This,index,nChannel,modo,pElement)	\
    (This)->lpVtbl -> GetStackElem(This,index,nChannel,modo,pElement)

#define IFCDualKernel8070_GetAxisIndex(This,str_axis,retval)	\
    (This)->lpVtbl -> GetAxisIndex(This,str_axis,retval)

#define IFCDualKernel8070_SetCSOffsetData(This,offset1,offset2,offset3)	\
    (This)->lpVtbl -> SetCSOffsetData(This,offset1,offset2,offset3)

#define IFCDualKernel8070_SetCSRotationData(This,rot1,rot2,rot3)	\
    (This)->lpVtbl -> SetCSRotationData(This,rot1,rot2,rot3)

#define IFCDualKernel8070_SetCSMode(This,mode)	\
    (This)->lpVtbl -> SetCSMode(This,mode)

#define IFCDualKernel8070_SetCSAlignedAxis(This,alignedAxis)	\
    (This)->lpVtbl -> SetCSAlignedAxis(This,alignedAxis)

#define IFCDualKernel8070_GetProgrammedCS(This,x1,y1,z1,x2,y2,z2,bRet)	\
    (This)->lpVtbl -> GetProgrammedCS(This,x1,y1,z1,x2,y2,z2,bRet)

#define IFCDualKernel8070_GetActiveCS(This,x1,y1,z1,x2,y2,z2,bSimul,canal,bRet)	\
    (This)->lpVtbl -> GetActiveCS(This,x1,y1,z1,x2,y2,z2,bSimul,canal,bRet)

#define IFCDualKernel8070_GetCabezalPerpendicularCS(This,pCab0Name,pCab0Pos,pCab1Name,pCab1Pos,pSolValida,bSimul,canal,bRet)	\
    (This)->lpVtbl -> GetCabezalPerpendicularCS(This,pCab0Name,pCab0Pos,pCab1Name,pCab1Pos,pSolValida,bSimul,canal,bRet)

#define IFCDualKernel8070_ProgCancel(This,numcanal,retval)	\
    (This)->lpVtbl -> ProgCancel(This,numcanal,retval)

#define IFCDualKernel8070_get_BlockSearchStartFileNameWithPath(This,numcanal,retval)	\
    (This)->lpVtbl -> get_BlockSearchStartFileNameWithPath(This,numcanal,retval)

#define IFCDualKernel8070_put_BlockSearchStartFileNameWithPath(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_BlockSearchStartFileNameWithPath(This,numcanal,newValue)

#define IFCDualKernel8070_GetDiagnosisVersion(This,numcanal,retval)	\
    (This)->lpVtbl -> GetDiagnosisVersion(This,numcanal,retval)

#define IFCDualKernel8070_GetSyntaxCheckFileName(This,numcanal,retval)	\
    (This)->lpVtbl -> GetSyntaxCheckFileName(This,numcanal,retval)

#define IFCDualKernel8070_get_BOffsetStartParaInspeccion(This,numcanal,retval)	\
    (This)->lpVtbl -> get_BOffsetStartParaInspeccion(This,numcanal,retval)

#define IFCDualKernel8070_put_BOffsetStartParaInspeccion(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_BOffsetStartParaInspeccion(This,numcanal,newValue)

#define IFCDualKernel8070_GetAxisLog(This,str_axis,retval)	\
    (This)->lpVtbl -> GetAxisLog(This,str_axis,retval)

#define IFCDualKernel8070_ShowWarningSimple(This,nCanal,errorID,errorKlasse,modul,line,modo,retval)	\
    (This)->lpVtbl -> ShowWarningSimple(This,nCanal,errorID,errorKlasse,modul,line,modo,retval)

#define IFCDualKernel8070_GiveRepositionAxes2(This,numcanal,ArrayAxes,retval)	\
    (This)->lpVtbl -> GiveRepositionAxes2(This,numcanal,ArrayAxes,retval)

#define IFCDualKernel8070_ActivateReposition(This,numcanal,modo_reposition,retval)	\
    (This)->lpVtbl -> ActivateReposition(This,numcanal,modo_reposition,retval)

#define IFCDualKernel8070_GetAxisName(This,index,nCanal,name,retval)	\
    (This)->lpVtbl -> GetAxisName(This,index,nCanal,name,retval)

#define IFCDualKernel8070_FocusChannel(This,retval)	\
    (This)->lpVtbl -> FocusChannel(This,retval)

#define IFCDualKernel8070_ConvertLogToIdx(This,numLog,index,retval)	\
    (This)->lpVtbl -> ConvertLogToIdx(This,numLog,index,retval)

#define IFCDualKernel8070_GetLogicNumber(This,index,nCanal,retval)	\
    (This)->lpVtbl -> GetLogicNumber(This,index,nCanal,retval)

#define IFCDualKernel8070_IsNewInspecAllowed(This,numcanal,bRet)	\
    (This)->lpVtbl -> IsNewInspecAllowed(This,numcanal,bRet)

#define IFCDualKernel8070_IsSpindleForReposition(This,nChannel,sEje,bRet)	\
    (This)->lpVtbl -> IsSpindleForReposition(This,nChannel,sEje,bRet)

#define IFCDualKernel8070_CheckVarsReposition2(This,nCanal,nIndexAxisChannel,retval)	\
    (This)->lpVtbl -> CheckVarsReposition2(This,nCanal,nIndexAxisChannel,retval)

#define IFCDualKernel8070_ReleaseKernelMem(This,retval)	\
    (This)->lpVtbl -> ReleaseKernelMem(This,retval)

#define IFCDualKernel8070_CancelReposition(This,nCanal,retval)	\
    (This)->lpVtbl -> CancelReposition(This,nCanal,retval)

#define IFCDualKernel8070_ExecProgramNoChangeProgSelect(This,numcanal,sprog)	\
    (This)->lpVtbl -> ExecProgramNoChangeProgSelect(This,numcanal,sprog)

#define IFCDualKernel8070_SelectProgramNoChangeProgSelect(This,numcanal,sprog)	\
    (This)->lpVtbl -> SelectProgramNoChangeProgSelect(This,numcanal,sprog)

#define IFCDualKernel8070_IsPossibleInspection2(This,numcanal,bRet)	\
    (This)->lpVtbl -> IsPossibleInspection2(This,numcanal,bRet)

#define IFCDualKernel8070_SetMdiInternalMode(This,numcanal,bRet)	\
    (This)->lpVtbl -> SetMdiInternalMode(This,numcanal,bRet)

#define IFCDualKernel8070_EndMdiInternalMode(This,numcanal,bRet)	\
    (This)->lpVtbl -> EndMdiInternalMode(This,numcanal,bRet)

#define IFCDualKernel8070_G0orG1withF(This,numcanal,pAxisName,pFeedRate,bRet)	\
    (This)->lpVtbl -> G0orG1withF(This,numcanal,pAxisName,pFeedRate,bRet)

#define IFCDualKernel8070_IsResetPreInspecReady(This,numcanal,bRet)	\
    (This)->lpVtbl -> IsResetPreInspecReady(This,numcanal,bRet)

#define IFCDualKernel8070_ResetInspec(This,numcanal,retval)	\
    (This)->lpVtbl -> ResetInspec(This,numcanal,retval)

#define IFCDualKernel8070_InspectionSaveIntPoint(This,numcanal,retval)	\
    (This)->lpVtbl -> InspectionSaveIntPoint(This,numcanal,retval)

#define IFCDualKernel8070_IsInspecOnlyReposPtoIni(This,numcanal,bRet)	\
    (This)->lpVtbl -> IsInspecOnlyReposPtoIni(This,numcanal,bRet)

#define IFCDualKernel8070_CncModel(This,bRet)	\
    (This)->lpVtbl -> CncModel(This,bRet)

#define IFCDualKernel8070_GetDiagnosisOptions2(This,retval)	\
    (This)->lpVtbl -> GetDiagnosisOptions2(This,retval)

#define IFCDualKernel8070_IsProgSelectInStack(This,pProgSelect,size,bRet)	\
    (This)->lpVtbl -> IsProgSelectInStack(This,pProgSelect,size,bRet)

#define IFCDualKernel8070_IsChannelInInspecInterruption(This,numcanal,bRet)	\
    (This)->lpVtbl -> IsChannelInInspecInterruption(This,numcanal,bRet)

#define IFCDualKernel8070_GetPuntoDeCancelacion(This,modoEjec,sizeDest,pPuntoDeInterrupcion)	\
    (This)->lpVtbl -> GetPuntoDeCancelacion(This,modoEjec,sizeDest,pPuntoDeInterrupcion)

#define IFCDualKernel8070_PosibleCancelContinue(This,numcanal,bRet)	\
    (This)->lpVtbl -> PosibleCancelContinue(This,numcanal,bRet)

#define IFCDualKernel8070_CancelContinue(This,numcanal,bRet)	\
    (This)->lpVtbl -> CancelContinue(This,numcanal,bRet)

#define IFCDualKernel8070_StartTrasCancelContinue(This,numcanal,bRet)	\
    (This)->lpVtbl -> StartTrasCancelContinue(This,numcanal,bRet)

#define IFCDualKernel8070_EscCancelContinue(This,numcanal,bRet)	\
    (This)->lpVtbl -> EscCancelContinue(This,numcanal,bRet)

#define IFCDualKernel8070_get_CancelContinueInitialFileOffset(This,numcanal,retval)	\
    (This)->lpVtbl -> get_CancelContinueInitialFileOffset(This,numcanal,retval)

#define IFCDualKernel8070_put_CancelContinueInitialFileOffset(This,numcanal,newValue)	\
    (This)->lpVtbl -> put_CancelContinueInitialFileOffset(This,numcanal,newValue)

#define IFCDualKernel8070_GetIndexFromSpdlName(This,nameSpdl,retval)	\
    (This)->lpVtbl -> GetIndexFromSpdlName(This,nameSpdl,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_InitKernel_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ BSTR szStartMode,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_InitKernel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_CloseKernel_Proxy( 
    IFCDualKernel8070 * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_CloseKernel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_OffsetStart_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_get_OffsetStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_OffsetStart_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualKernel8070_put_OffsetStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_OffsetStartSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_get_OffsetStartSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_OffsetStartSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualKernel8070_put_OffsetStartSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_NextSingleStep_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_NextSingleStep_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_StartAutomBlockSearch_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_StartAutomBlockSearch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_StartBlockSearch_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_StartBlockSearch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SetMode_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long mode,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_SetMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ClearFeedhold_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ClearFeedhold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ExecBlock_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR str_block,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ExecBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_KernelExist_Proxy( 
    IFCDualKernel8070 * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualKernel8070_KernelExist_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_KernelExistSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualKernel8070_KernelExistSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_StartProgram_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_StartProgram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SetFeedhold_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_SetFeedhold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_KernelReset_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_KernelReset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_KernelResetSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_KernelResetSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ClearFeedholdSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ClearFeedholdSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_AddLogOnInfo_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ BSTR info);


void __RPC_STUB IFCDualKernel8070_AddLogOnInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_StartKernel_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long phase,
    /* [in] */ BOOL sbKernel,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_StartKernel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_StartKernelSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_StartKernelSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_EndKernel_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long phase,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_EndKernel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_EndKernelSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long phase,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_EndKernelSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SetLogOnFile_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ BSTR file);


void __RPC_STUB IFCDualKernel8070_SetLogOnFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_StartRequest_Proxy( 
    IFCDualKernel8070 * This);


void __RPC_STUB IFCDualKernel8070_StartRequest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_NextSingleStepSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_NextSingleStepSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_StartProgramSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ SIMULATION_OPTIONS_T options,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_StartProgramSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SetFeedholdSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_SetFeedholdSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_StartProgramSintaxCheck_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_StartProgramSintaxCheck_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_StartProgramExecTime_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_StartProgramExecTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SkipBlock_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BOOL bActivate,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_SkipBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SimulateM01_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BOOL bActivate,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_SimulateM01_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SWLimitsON_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BOOL bActivate,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_SWLimitsON_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ReadError_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long nError,
    /* [retval][out] */ IFCDualError **iError);


void __RPC_STUB IFCDualKernel8070_ReadError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ReadErrorSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long nError,
    /* [retval][out] */ IFCDualError **iError);


void __RPC_STUB IFCDualKernel8070_ReadErrorSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ResetError_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long nError,
    /* [in] */ ERROR_TYPE_T type,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ResetError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ResetErrorSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long nError,
    /* [in] */ ERROR_TYPE_T type,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ResetErrorSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SelectProgram_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR sprog);


void __RPC_STUB IFCDualKernel8070_SelectProgram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ExecProgram_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR sprog);


void __RPC_STUB IFCDualKernel8070_ExecProgram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SetKernelMode_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BOOL bManual,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualKernel8070_SetKernelMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GiveRepositionAxes_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [out] */ VARIANT *ArrayAxes,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GiveRepositionAxes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_EndInspection_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_EndInspection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_Reposition_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ short *array_axes,
    /* [in] */ long tipoInspeccion,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_Reposition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ActivateInspection_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ActivateInspection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_RepositionStrAxes_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR strAxes,
    /* [in] */ int tipoInspeccion,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_RepositionStrAxes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_RepositionAxes_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ VARIANT *ArrayAxes,
    /* [in] */ long tipoInspeccion,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_RepositionAxes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_IsPossibleAutomBlockSearch_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_IsPossibleAutomBlockSearch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SelectProgramSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR sprog);


void __RPC_STUB IFCDualKernel8070_SelectProgramSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ExecProgramSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR sprog,
    /* [in] */ SIMULATION_OPTIONS_T options,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ExecProgramSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_StopConditionInSubrut_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualKernel8070_get_StopConditionInSubrut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_StopConditionInSubrut_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BOOL newValue);


void __RPC_STUB IFCDualKernel8070_put_StopConditionInSubrut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_StopConditionFileOffset_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_get_StopConditionFileOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_StopConditionFileOffset_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualKernel8070_put_StopConditionFileOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_StopConditionFileName_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualKernel8070_get_StopConditionFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_StopConditionFileName_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR newValue);


void __RPC_STUB IFCDualKernel8070_put_StopConditionFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_StopConditionNumTimes_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualKernel8070_get_StopConditionNumTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_StopConditionNumTimes_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ short newValue);


void __RPC_STUB IFCDualKernel8070_put_StopConditionNumTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_BlockSearchStartFileOffset_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_get_BlockSearchStartFileOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_BlockSearchStartFileOffset_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualKernel8070_put_BlockSearchStartFileOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_BlockSearchStartInSubr_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualKernel8070_get_BlockSearchStartInSubr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_BlockSearchStartInSubr_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BOOL newValue);


void __RPC_STUB IFCDualKernel8070_put_BlockSearchStartInSubr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_BlockSearchStartFileName_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualKernel8070_get_BlockSearchStartFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_BlockSearchStartFileName_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR newValue);


void __RPC_STUB IFCDualKernel8070_put_BlockSearchStartFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_BlockSearchStartNumTimes_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualKernel8070_get_BlockSearchStartNumTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_BlockSearchStartNumTimes_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ short newValue);


void __RPC_STUB IFCDualKernel8070_put_BlockSearchStartNumTimes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_StopConditionInSubrutSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualKernel8070_get_StopConditionInSubrutSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_StopConditionInSubrutSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BOOL newValue);


void __RPC_STUB IFCDualKernel8070_put_StopConditionInSubrutSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_StopConditionFileOffsetSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_get_StopConditionFileOffsetSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_StopConditionFileOffsetSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualKernel8070_put_StopConditionFileOffsetSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_StopConditionFileNameSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualKernel8070_get_StopConditionFileNameSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_StopConditionFileNameSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR newValue);


void __RPC_STUB IFCDualKernel8070_put_StopConditionFileNameSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_StopConditionNumTimesSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualKernel8070_get_StopConditionNumTimesSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_StopConditionNumTimesSim_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ short newValue);


void __RPC_STUB IFCDualKernel8070_put_StopConditionNumTimesSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_AreAxisRepositionated_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_AreAxisRepositionated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_TEProdTime_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ double *dRet);


void __RPC_STUB IFCDualKernel8070_TEProdTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetProdTimeData_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_GetProdTimeData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_TENumM_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ short *sRet);


void __RPC_STUB IFCDualKernel8070_TENumM_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_TENumM6_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ short *sRet);


void __RPC_STUB IFCDualKernel8070_TENumM6_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_TENumT_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ short *sRet);


void __RPC_STUB IFCDualKernel8070_TENumT_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_TETimeNumT_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long index,
    /* [retval][out] */ long *lRet);


void __RPC_STUB IFCDualKernel8070_TETimeNumT_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_TETimePosic_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long index,
    /* [retval][out] */ double *dRet);


void __RPC_STUB IFCDualKernel8070_TETimePosic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_TETimeMec_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long index,
    /* [retval][out] */ double *dRet);


void __RPC_STUB IFCDualKernel8070_TETimeMec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_TELastPDU_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_TELastPDU_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_IsPossibleInspection_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_IsPossibleInspection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_LoadOffset_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ short index,
    /* [in] */ VARIANT *arrayOffsets,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_LoadOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetAxisChannel_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ BSTR str_axis,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GetAxisChannel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_PreSelection_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ BSTR str_axis,
    /* [in] */ double value,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_PreSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ZeroSearch_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ BSTR str_axis,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ZeroSearch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetNumChannels_Proxy( 
    IFCDualKernel8070 * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GetNumChannels_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ExecSimOtherProgram_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR sprog,
    /* [in] */ SIMULATION_OPTIONS_T options,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ExecSimOtherProgram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetOpenedFilesList_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ short modoEjec,
    /* [in] */ long sizeDest,
    /* [retval][out] */ BSTR *pOpenedFilesList);


void __RPC_STUB IFCDualKernel8070_GetOpenedFilesList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_Oscillation_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ BSTR str_axis,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_Oscillation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ChannelStartRequest_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long channel);


void __RPC_STUB IFCDualKernel8070_ChannelStartRequest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ExecBlockEx_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR str_block,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ExecBlockEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetDiagnosisOptions_Proxy( 
    IFCDualKernel8070 * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GetDiagnosisOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetPuntoDeInterrupcion_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ short modoEjec,
    /* [in] */ long sizeDest,
    /* [retval][out] */ BSTR *pPuntoDeInterrupcion);


void __RPC_STUB IFCDualKernel8070_GetPuntoDeInterrupcion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ReconfigPuntoDeInterrupcion_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numBlqAntesPtoInterrupcion,
    /* [in] */ long sizeDest,
    /* [retval][out] */ BSTR *pOffsetAnterior);


void __RPC_STUB IFCDualKernel8070_ReconfigPuntoDeInterrupcion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetNumElemFifoOffAnterior_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ short dummy,
    /* [in] */ long sizeDest,
    /* [retval][out] */ BSTR *pData);


void __RPC_STUB IFCDualKernel8070_GetNumElemFifoOffAnterior_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_fOptimizacionCad_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_get_fOptimizacionCad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_fOptimizacionCad_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualKernel8070_put_fOptimizacionCad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetStackElem_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long index,
    /* [in] */ long nChannel,
    /* [in] */ long modo,
    /* [retval][out] */ BSTR *pElement);


void __RPC_STUB IFCDualKernel8070_GetStackElem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetAxisIndex_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ BSTR str_axis,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GetAxisIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SetCSOffsetData_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ double offset1,
    /* [in] */ double offset2,
    /* [in] */ double offset3);


void __RPC_STUB IFCDualKernel8070_SetCSOffsetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SetCSRotationData_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ double rot1,
    /* [in] */ double rot2,
    /* [in] */ double rot3);


void __RPC_STUB IFCDualKernel8070_SetCSRotationData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SetCSMode_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ short mode);


void __RPC_STUB IFCDualKernel8070_SetCSMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SetCSAlignedAxis_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ short alignedAxis);


void __RPC_STUB IFCDualKernel8070_SetCSAlignedAxis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetProgrammedCS_Proxy( 
    IFCDualKernel8070 * This,
    /* [out][in] */ double *x1,
    /* [out][in] */ double *y1,
    /* [out][in] */ double *z1,
    /* [out][in] */ double *x2,
    /* [out][in] */ double *y2,
    /* [out][in] */ double *z2,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_GetProgrammedCS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetActiveCS_Proxy( 
    IFCDualKernel8070 * This,
    /* [out][in] */ double *x1,
    /* [out][in] */ double *y1,
    /* [out][in] */ double *z1,
    /* [out][in] */ double *x2,
    /* [out][in] */ double *y2,
    /* [out][in] */ double *z2,
    /* [in] */ short bSimul,
    /* [in] */ short canal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_GetActiveCS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetCabezalPerpendicularCS_Proxy( 
    IFCDualKernel8070 * This,
    /* [out][in] */ BSTR *pCab0Name,
    /* [out][in] */ double *pCab0Pos,
    /* [out][in] */ BSTR *pCab1Name,
    /* [out][in] */ double *pCab1Pos,
    /* [out][in] */ short *pSolValida,
    /* [in] */ short bSimul,
    /* [in] */ short canal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_GetCabezalPerpendicularCS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ProgCancel_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ProgCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_BlockSearchStartFileNameWithPath_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualKernel8070_get_BlockSearchStartFileNameWithPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_BlockSearchStartFileNameWithPath_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR newValue);


void __RPC_STUB IFCDualKernel8070_put_BlockSearchStartFileNameWithPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetDiagnosisVersion_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GetDiagnosisVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetSyntaxCheckFileName_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualKernel8070_GetSyntaxCheckFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_BOffsetStartParaInspeccion_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_get_BOffsetStartParaInspeccion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_BOffsetStartParaInspeccion_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualKernel8070_put_BOffsetStartParaInspeccion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetAxisLog_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ BSTR str_axis,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GetAxisLog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ShowWarningSimple_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long nCanal,
    /* [in] */ long errorID,
    /* [in] */ long errorKlasse,
    /* [in] */ BSTR modul,
    /* [in] */ long line,
    /* [in] */ long modo,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ShowWarningSimple_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GiveRepositionAxes2_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ VARIANT *ArrayAxes,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GiveRepositionAxes2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ActivateReposition_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long modo_reposition,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ActivateReposition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetAxisName_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long index,
    /* [in] */ long nCanal,
    /* [out] */ BSTR *name,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GetAxisName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_FocusChannel_Proxy( 
    IFCDualKernel8070 * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_FocusChannel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ConvertLogToIdx_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numLog,
    /* [out] */ long *index,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ConvertLogToIdx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetLogicNumber_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long index,
    /* [in] */ long nCanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GetLogicNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_IsNewInspecAllowed_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_IsNewInspecAllowed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_IsSpindleForReposition_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long nChannel,
    /* [in] */ BSTR sEje,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_IsSpindleForReposition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_CheckVarsReposition2_Proxy( 
    IFCDualKernel8070 * This,
    long nCanal,
    long nIndexAxisChannel,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_CheckVarsReposition2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ReleaseKernelMem_Proxy( 
    IFCDualKernel8070 * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ReleaseKernelMem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_CancelReposition_Proxy( 
    IFCDualKernel8070 * This,
    long nCanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_CancelReposition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ExecProgramNoChangeProgSelect_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR sprog);


void __RPC_STUB IFCDualKernel8070_ExecProgramNoChangeProgSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SelectProgramNoChangeProgSelect_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR sprog);


void __RPC_STUB IFCDualKernel8070_SelectProgramNoChangeProgSelect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_IsPossibleInspection2_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *bRet);


void __RPC_STUB IFCDualKernel8070_IsPossibleInspection2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_SetMdiInternalMode_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_SetMdiInternalMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_EndMdiInternalMode_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_EndMdiInternalMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_G0orG1withF_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ BSTR pAxisName,
    /* [in] */ long *pFeedRate,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_G0orG1withF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_IsResetPreInspecReady_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_IsResetPreInspecReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_ResetInspec_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_ResetInspec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_InspectionSaveIntPoint_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_InspectionSaveIntPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_IsInspecOnlyReposPtoIni_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_IsInspecOnlyReposPtoIni_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_CncModel_Proxy( 
    IFCDualKernel8070 * This,
    /* [retval][out] */ long *bRet);


void __RPC_STUB IFCDualKernel8070_CncModel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetDiagnosisOptions2_Proxy( 
    IFCDualKernel8070 * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GetDiagnosisOptions2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_IsProgSelectInStack_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ BSTR *pProgSelect,
    /* [in] */ long size,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_IsProgSelectInStack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_IsChannelInInspecInterruption_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_IsChannelInInspecInterruption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetPuntoDeCancelacion_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ short modoEjec,
    /* [in] */ long sizeDest,
    /* [retval][out] */ BSTR *pPuntoDeInterrupcion);


void __RPC_STUB IFCDualKernel8070_GetPuntoDeCancelacion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_PosibleCancelContinue_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_PosibleCancelContinue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_CancelContinue_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_CancelContinue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_StartTrasCancelContinue_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_StartTrasCancelContinue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_EscCancelContinue_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ BOOL *bRet);


void __RPC_STUB IFCDualKernel8070_EscCancelContinue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_get_CancelContinueInitialFileOffset_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_get_CancelContinueInitialFileOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_put_CancelContinueInitialFileOffset_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ long numcanal,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualKernel8070_put_CancelContinueInitialFileOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernel8070_GetIndexFromSpdlName_Proxy( 
    IFCDualKernel8070 * This,
    /* [in] */ BSTR nameSpdl,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualKernel8070_GetIndexFromSpdlName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualKernel8070_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_Kernel,0xC75237CD,0x229E,0x46F9,0x89,0x6B,0xF5,0x71,0xD5,0x36,0x8F,0x7F);

#ifdef __cplusplus

class DECLSPEC_UUID("C75237CD-229E-46F9-896B-F571D5368F7F")
CNC8070_Kernel;
#endif

#ifndef __IFCAxes8070_DISPINTERFACE_DEFINED__
#define __IFCAxes8070_DISPINTERFACE_DEFINED__

/* dispinterface IFCAxes8070 */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCAxes8070,0x32A66392,0x8441,0x467E,0x99,0x07,0x88,0x5F,0xCE,0xEC,0x31,0xFB);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("32A66392-8441-467E-9907-885FCEEC31FB")
    IFCAxes8070 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCAxes8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCAxes8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCAxes8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCAxes8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCAxes8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCAxes8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCAxes8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCAxes8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCAxes8070Vtbl;

    interface IFCAxes8070
    {
        CONST_VTBL struct IFCAxes8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCAxes8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCAxes8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCAxes8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCAxes8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCAxes8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCAxes8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCAxes8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCAxes8070_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualAxes8070_INTERFACE_DEFINED__
#define __IFCDualAxes8070_INTERFACE_DEFINED__

/* interface IFCDualAxes8070 */
/* [helpstring][dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualAxes8070,0x3850531A,0x3E71,0x40c9,0x82,0xDA,0x7C,0x34,0x49,0x39,0xBC,0x98);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3850531A-3E71-40c9-82DA-7C344939BC98")
    IFCDualAxes8070 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SimulationAxes( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SimulationAxes( 
            /* [in] */ BOOL bNewValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConnectToChannel( 
            /* [in] */ short channel,
            /* [in] */ BSTR sAxesType,
            /* [defaultvalue][in] */ BSTR sHiddenAxes = L"",
            /* [retval][defaultvalue][out] */ short *retval = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisconnectAxes( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTxtValues( 
            /* [retval][out] */ VARIANT *pValues) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTxtValue( 
            /* [in] */ short numAxis,
            /* [retval][out] */ BSTR *pValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetNDecimals( 
            /* [in] */ long nDecimals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetNIntegers( 
            /* [in] */ long nIntegers) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetPad( 
            /* [in] */ BOOL bPad) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetValuesString( 
            /* [retval][out] */ BSTR *pValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenAxisNameReport( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseAxisNameReport( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenAxisEnableReport( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseAxisEnableReport( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetConnectedAxisNames( 
            /* [retval][out] */ BSTR *pValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenAxisInhibitReport( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseAxisInhibitReport( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenAxisGenMpgReport( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseAxisGenMpgReport( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFilterDelay( 
            /* [in] */ long delay) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualAxes8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualAxes8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualAxes8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualAxes8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualAxes8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualAxes8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualAxes8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualAxes8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SimulationAxes )( 
            IFCDualAxes8070 * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SimulationAxes )( 
            IFCDualAxes8070 * This,
            /* [in] */ BOOL bNewValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConnectToChannel )( 
            IFCDualAxes8070 * This,
            /* [in] */ short channel,
            /* [in] */ BSTR sAxesType,
            /* [defaultvalue][in] */ BSTR sHiddenAxes,
            /* [retval][defaultvalue][out] */ short *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisconnectAxes )( 
            IFCDualAxes8070 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTxtValues )( 
            IFCDualAxes8070 * This,
            /* [retval][out] */ VARIANT *pValues);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTxtValue )( 
            IFCDualAxes8070 * This,
            /* [in] */ short numAxis,
            /* [retval][out] */ BSTR *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNDecimals )( 
            IFCDualAxes8070 * This,
            /* [in] */ long nDecimals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNIntegers )( 
            IFCDualAxes8070 * This,
            /* [in] */ long nIntegers);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetPad )( 
            IFCDualAxes8070 * This,
            /* [in] */ BOOL bPad);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetValuesString )( 
            IFCDualAxes8070 * This,
            /* [retval][out] */ BSTR *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenAxisNameReport )( 
            IFCDualAxes8070 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseAxisNameReport )( 
            IFCDualAxes8070 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenAxisEnableReport )( 
            IFCDualAxes8070 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseAxisEnableReport )( 
            IFCDualAxes8070 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetConnectedAxisNames )( 
            IFCDualAxes8070 * This,
            /* [retval][out] */ BSTR *pValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenAxisInhibitReport )( 
            IFCDualAxes8070 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseAxisInhibitReport )( 
            IFCDualAxes8070 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenAxisGenMpgReport )( 
            IFCDualAxes8070 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseAxisGenMpgReport )( 
            IFCDualAxes8070 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFilterDelay )( 
            IFCDualAxes8070 * This,
            /* [in] */ long delay);
        
        END_INTERFACE
    } IFCDualAxes8070Vtbl;

    interface IFCDualAxes8070
    {
        CONST_VTBL struct IFCDualAxes8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualAxes8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualAxes8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualAxes8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualAxes8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualAxes8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualAxes8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualAxes8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualAxes8070_get_SimulationAxes(This,retval)	\
    (This)->lpVtbl -> get_SimulationAxes(This,retval)

#define IFCDualAxes8070_put_SimulationAxes(This,bNewValue)	\
    (This)->lpVtbl -> put_SimulationAxes(This,bNewValue)

#define IFCDualAxes8070_ConnectToChannel(This,channel,sAxesType,sHiddenAxes,retval)	\
    (This)->lpVtbl -> ConnectToChannel(This,channel,sAxesType,sHiddenAxes,retval)

#define IFCDualAxes8070_DisconnectAxes(This)	\
    (This)->lpVtbl -> DisconnectAxes(This)

#define IFCDualAxes8070_GetTxtValues(This,pValues)	\
    (This)->lpVtbl -> GetTxtValues(This,pValues)

#define IFCDualAxes8070_GetTxtValue(This,numAxis,pValue)	\
    (This)->lpVtbl -> GetTxtValue(This,numAxis,pValue)

#define IFCDualAxes8070_SetNDecimals(This,nDecimals)	\
    (This)->lpVtbl -> SetNDecimals(This,nDecimals)

#define IFCDualAxes8070_SetNIntegers(This,nIntegers)	\
    (This)->lpVtbl -> SetNIntegers(This,nIntegers)

#define IFCDualAxes8070_SetPad(This,bPad)	\
    (This)->lpVtbl -> SetPad(This,bPad)

#define IFCDualAxes8070_GetValuesString(This,pValue)	\
    (This)->lpVtbl -> GetValuesString(This,pValue)

#define IFCDualAxes8070_OpenAxisNameReport(This)	\
    (This)->lpVtbl -> OpenAxisNameReport(This)

#define IFCDualAxes8070_CloseAxisNameReport(This)	\
    (This)->lpVtbl -> CloseAxisNameReport(This)

#define IFCDualAxes8070_OpenAxisEnableReport(This)	\
    (This)->lpVtbl -> OpenAxisEnableReport(This)

#define IFCDualAxes8070_CloseAxisEnableReport(This)	\
    (This)->lpVtbl -> CloseAxisEnableReport(This)

#define IFCDualAxes8070_GetConnectedAxisNames(This,pValue)	\
    (This)->lpVtbl -> GetConnectedAxisNames(This,pValue)

#define IFCDualAxes8070_OpenAxisInhibitReport(This)	\
    (This)->lpVtbl -> OpenAxisInhibitReport(This)

#define IFCDualAxes8070_CloseAxisInhibitReport(This)	\
    (This)->lpVtbl -> CloseAxisInhibitReport(This)

#define IFCDualAxes8070_OpenAxisGenMpgReport(This)	\
    (This)->lpVtbl -> OpenAxisGenMpgReport(This)

#define IFCDualAxes8070_CloseAxisGenMpgReport(This)	\
    (This)->lpVtbl -> CloseAxisGenMpgReport(This)

#define IFCDualAxes8070_SetFilterDelay(This,delay)	\
    (This)->lpVtbl -> SetFilterDelay(This,delay)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_get_SimulationAxes_Proxy( 
    IFCDualAxes8070 * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualAxes8070_get_SimulationAxes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_put_SimulationAxes_Proxy( 
    IFCDualAxes8070 * This,
    /* [in] */ BOOL bNewValue);


void __RPC_STUB IFCDualAxes8070_put_SimulationAxes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_ConnectToChannel_Proxy( 
    IFCDualAxes8070 * This,
    /* [in] */ short channel,
    /* [in] */ BSTR sAxesType,
    /* [defaultvalue][in] */ BSTR sHiddenAxes,
    /* [retval][defaultvalue][out] */ short *retval);


void __RPC_STUB IFCDualAxes8070_ConnectToChannel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_DisconnectAxes_Proxy( 
    IFCDualAxes8070 * This);


void __RPC_STUB IFCDualAxes8070_DisconnectAxes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_GetTxtValues_Proxy( 
    IFCDualAxes8070 * This,
    /* [retval][out] */ VARIANT *pValues);


void __RPC_STUB IFCDualAxes8070_GetTxtValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_GetTxtValue_Proxy( 
    IFCDualAxes8070 * This,
    /* [in] */ short numAxis,
    /* [retval][out] */ BSTR *pValue);


void __RPC_STUB IFCDualAxes8070_GetTxtValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_SetNDecimals_Proxy( 
    IFCDualAxes8070 * This,
    /* [in] */ long nDecimals);


void __RPC_STUB IFCDualAxes8070_SetNDecimals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_SetNIntegers_Proxy( 
    IFCDualAxes8070 * This,
    /* [in] */ long nIntegers);


void __RPC_STUB IFCDualAxes8070_SetNIntegers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_SetPad_Proxy( 
    IFCDualAxes8070 * This,
    /* [in] */ BOOL bPad);


void __RPC_STUB IFCDualAxes8070_SetPad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_GetValuesString_Proxy( 
    IFCDualAxes8070 * This,
    /* [retval][out] */ BSTR *pValue);


void __RPC_STUB IFCDualAxes8070_GetValuesString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_OpenAxisNameReport_Proxy( 
    IFCDualAxes8070 * This);


void __RPC_STUB IFCDualAxes8070_OpenAxisNameReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_CloseAxisNameReport_Proxy( 
    IFCDualAxes8070 * This);


void __RPC_STUB IFCDualAxes8070_CloseAxisNameReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_OpenAxisEnableReport_Proxy( 
    IFCDualAxes8070 * This);


void __RPC_STUB IFCDualAxes8070_OpenAxisEnableReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_CloseAxisEnableReport_Proxy( 
    IFCDualAxes8070 * This);


void __RPC_STUB IFCDualAxes8070_CloseAxisEnableReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_GetConnectedAxisNames_Proxy( 
    IFCDualAxes8070 * This,
    /* [retval][out] */ BSTR *pValue);


void __RPC_STUB IFCDualAxes8070_GetConnectedAxisNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_OpenAxisInhibitReport_Proxy( 
    IFCDualAxes8070 * This);


void __RPC_STUB IFCDualAxes8070_OpenAxisInhibitReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_CloseAxisInhibitReport_Proxy( 
    IFCDualAxes8070 * This);


void __RPC_STUB IFCDualAxes8070_CloseAxisInhibitReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_OpenAxisGenMpgReport_Proxy( 
    IFCDualAxes8070 * This);


void __RPC_STUB IFCDualAxes8070_OpenAxisGenMpgReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_CloseAxisGenMpgReport_Proxy( 
    IFCDualAxes8070 * This);


void __RPC_STUB IFCDualAxes8070_CloseAxisGenMpgReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAxes8070_SetFilterDelay_Proxy( 
    IFCDualAxes8070 * This,
    /* [in] */ long delay);


void __RPC_STUB IFCDualAxes8070_SetFilterDelay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualAxes8070_INTERFACE_DEFINED__ */


#ifndef __IEventAxesReport_DISPINTERFACE_DEFINED__
#define __IEventAxesReport_DISPINTERFACE_DEFINED__

/* dispinterface IEventAxesReport */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_IEventAxesReport,0xAFDBEBD0,0x49AF,0x424e,0xB8,0xE7,0xF5,0x0A,0x28,0x39,0x4D,0x36);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AFDBEBD0-49AF-424e-B8E7-F50A28394D36")
    IEventAxesReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IEventAxesReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEventAxesReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEventAxesReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEventAxesReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEventAxesReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEventAxesReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEventAxesReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEventAxesReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IEventAxesReportVtbl;

    interface IEventAxesReport
    {
        CONST_VTBL struct IEventAxesReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEventAxesReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEventAxesReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEventAxesReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEventAxesReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEventAxesReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEventAxesReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEventAxesReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IEventAxesReport_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_Axes,0x82BBF142,0xC79E,0x4725,0x90,0x29,0x8B,0xDE,0x76,0xC1,0x28,0xEB);

#ifdef __cplusplus

class DECLSPEC_UUID("82BBF142-C79E-4725-9029-8BDE76C128EB")
CNC8070_Axes;
#endif

#ifndef __IFCProcessExpression_DISPINTERFACE_DEFINED__
#define __IFCProcessExpression_DISPINTERFACE_DEFINED__

/* dispinterface IFCProcessExpression */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCProcessExpression,0x55EB4406,0xB0E5,0x4A37,0xA0,0xE9,0x06,0xB5,0x9A,0x5B,0x26,0xB3);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("55EB4406-B0E5-4A37-A0E9-06B59A5B26B3")
    IFCProcessExpression : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCProcessExpressionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCProcessExpression * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCProcessExpression * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCProcessExpression * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCProcessExpression * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCProcessExpression * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCProcessExpression * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCProcessExpression * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCProcessExpressionVtbl;

    interface IFCProcessExpression
    {
        CONST_VTBL struct IFCProcessExpressionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCProcessExpression_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCProcessExpression_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCProcessExpression_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCProcessExpression_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCProcessExpression_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCProcessExpression_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCProcessExpression_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCProcessExpression_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualProcessExpression_INTERFACE_DEFINED__
#define __IFCDualProcessExpression_INTERFACE_DEFINED__

/* interface IFCDualProcessExpression */
/* [helpstring][dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualProcessExpression,0x2F7E8532,0xDE99,0x45b9,0x92,0xCB,0x1B,0xB0,0x67,0xAF,0x8F,0x38);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2F7E8532-DE99-45b9-92CB-1BB067AF8F38")
    IFCDualProcessExpression : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDualVar( 
            /* [in] */ IDispatch *pVar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Compile( 
            /* [in] */ IDispatch *pControl,
            /* [in] */ IDispatch *pReport,
            /* [in] */ BSTR szExpression,
            /* [out] */ BSTR *token,
            /* [out] */ BOOL *bAllReportVar,
            /* [out] */ VARIANT *ArrayHVar,
            /* [out] */ long *nCount,
            /* [retval][defaultvalue][out] */ long *retval = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ActivateControl( 
            /* [in] */ IDispatch *pControl,
            /* [in] */ BOOL bActivate) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Evaluate( 
            /* [in] */ IDispatch *pControl,
            /* [out] */ double *result,
            /* [retval][defaultvalue][out] */ long *retval = 0) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ForceOpenReportExpresion( 
            /* [in] */ IDispatch *pControl,
            /* [retval][defaultvalue][out] */ long *retval = 0) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_HexView( 
            /* [in] */ IDispatch *pControl,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_HexView( 
            /* [in] */ IDispatch *pControl,
            /* [in] */ BOOL newValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveControl( 
            /* [in] */ IDispatch *pControl,
            /* [retval][defaultvalue][out] */ BOOL *retval = 0) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualProcessExpressionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualProcessExpression * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualProcessExpression * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualProcessExpression * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualProcessExpression * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualProcessExpression * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualProcessExpression * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualProcessExpression * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDualVar )( 
            IFCDualProcessExpression * This,
            /* [in] */ IDispatch *pVar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Compile )( 
            IFCDualProcessExpression * This,
            /* [in] */ IDispatch *pControl,
            /* [in] */ IDispatch *pReport,
            /* [in] */ BSTR szExpression,
            /* [out] */ BSTR *token,
            /* [out] */ BOOL *bAllReportVar,
            /* [out] */ VARIANT *ArrayHVar,
            /* [out] */ long *nCount,
            /* [retval][defaultvalue][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ActivateControl )( 
            IFCDualProcessExpression * This,
            /* [in] */ IDispatch *pControl,
            /* [in] */ BOOL bActivate);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Evaluate )( 
            IFCDualProcessExpression * This,
            /* [in] */ IDispatch *pControl,
            /* [out] */ double *result,
            /* [retval][defaultvalue][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ForceOpenReportExpresion )( 
            IFCDualProcessExpression * This,
            /* [in] */ IDispatch *pControl,
            /* [retval][defaultvalue][out] */ long *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HexView )( 
            IFCDualProcessExpression * This,
            /* [in] */ IDispatch *pControl,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HexView )( 
            IFCDualProcessExpression * This,
            /* [in] */ IDispatch *pControl,
            /* [in] */ BOOL newValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveControl )( 
            IFCDualProcessExpression * This,
            /* [in] */ IDispatch *pControl,
            /* [retval][defaultvalue][out] */ BOOL *retval);
        
        END_INTERFACE
    } IFCDualProcessExpressionVtbl;

    interface IFCDualProcessExpression
    {
        CONST_VTBL struct IFCDualProcessExpressionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualProcessExpression_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualProcessExpression_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualProcessExpression_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualProcessExpression_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualProcessExpression_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualProcessExpression_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualProcessExpression_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualProcessExpression_SetDualVar(This,pVar)	\
    (This)->lpVtbl -> SetDualVar(This,pVar)

#define IFCDualProcessExpression_Compile(This,pControl,pReport,szExpression,token,bAllReportVar,ArrayHVar,nCount,retval)	\
    (This)->lpVtbl -> Compile(This,pControl,pReport,szExpression,token,bAllReportVar,ArrayHVar,nCount,retval)

#define IFCDualProcessExpression_ActivateControl(This,pControl,bActivate)	\
    (This)->lpVtbl -> ActivateControl(This,pControl,bActivate)

#define IFCDualProcessExpression_Evaluate(This,pControl,result,retval)	\
    (This)->lpVtbl -> Evaluate(This,pControl,result,retval)

#define IFCDualProcessExpression_ForceOpenReportExpresion(This,pControl,retval)	\
    (This)->lpVtbl -> ForceOpenReportExpresion(This,pControl,retval)

#define IFCDualProcessExpression_get_HexView(This,pControl,retval)	\
    (This)->lpVtbl -> get_HexView(This,pControl,retval)

#define IFCDualProcessExpression_put_HexView(This,pControl,newValue)	\
    (This)->lpVtbl -> put_HexView(This,pControl,newValue)

#define IFCDualProcessExpression_RemoveControl(This,pControl,retval)	\
    (This)->lpVtbl -> RemoveControl(This,pControl,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualProcessExpression_SetDualVar_Proxy( 
    IFCDualProcessExpression * This,
    /* [in] */ IDispatch *pVar);


void __RPC_STUB IFCDualProcessExpression_SetDualVar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualProcessExpression_Compile_Proxy( 
    IFCDualProcessExpression * This,
    /* [in] */ IDispatch *pControl,
    /* [in] */ IDispatch *pReport,
    /* [in] */ BSTR szExpression,
    /* [out] */ BSTR *token,
    /* [out] */ BOOL *bAllReportVar,
    /* [out] */ VARIANT *ArrayHVar,
    /* [out] */ long *nCount,
    /* [retval][defaultvalue][out] */ long *retval);


void __RPC_STUB IFCDualProcessExpression_Compile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualProcessExpression_ActivateControl_Proxy( 
    IFCDualProcessExpression * This,
    /* [in] */ IDispatch *pControl,
    /* [in] */ BOOL bActivate);


void __RPC_STUB IFCDualProcessExpression_ActivateControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualProcessExpression_Evaluate_Proxy( 
    IFCDualProcessExpression * This,
    /* [in] */ IDispatch *pControl,
    /* [out] */ double *result,
    /* [retval][defaultvalue][out] */ long *retval);


void __RPC_STUB IFCDualProcessExpression_Evaluate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualProcessExpression_ForceOpenReportExpresion_Proxy( 
    IFCDualProcessExpression * This,
    /* [in] */ IDispatch *pControl,
    /* [retval][defaultvalue][out] */ long *retval);


void __RPC_STUB IFCDualProcessExpression_ForceOpenReportExpresion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualProcessExpression_get_HexView_Proxy( 
    IFCDualProcessExpression * This,
    /* [in] */ IDispatch *pControl,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualProcessExpression_get_HexView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualProcessExpression_put_HexView_Proxy( 
    IFCDualProcessExpression * This,
    /* [in] */ IDispatch *pControl,
    /* [in] */ BOOL newValue);


void __RPC_STUB IFCDualProcessExpression_put_HexView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualProcessExpression_RemoveControl_Proxy( 
    IFCDualProcessExpression * This,
    /* [in] */ IDispatch *pControl,
    /* [retval][defaultvalue][out] */ BOOL *retval);


void __RPC_STUB IFCDualProcessExpression_RemoveControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualProcessExpression_INTERFACE_DEFINED__ */


#ifndef __IEventProcessExpressionReport_DISPINTERFACE_DEFINED__
#define __IEventProcessExpressionReport_DISPINTERFACE_DEFINED__

/* dispinterface IEventProcessExpressionReport */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_IEventProcessExpressionReport,0x174D6AD5,0x7F5C,0x4fc5,0xA9,0x41,0x28,0xEA,0x4B,0x8D,0x92,0xE1);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("174D6AD5-7F5C-4fc5-A941-28EA4B8D92E1")
    IEventProcessExpressionReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IEventProcessExpressionReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEventProcessExpressionReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEventProcessExpressionReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEventProcessExpressionReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEventProcessExpressionReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEventProcessExpressionReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEventProcessExpressionReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEventProcessExpressionReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IEventProcessExpressionReportVtbl;

    interface IEventProcessExpressionReport
    {
        CONST_VTBL struct IEventProcessExpressionReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEventProcessExpressionReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEventProcessExpressionReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEventProcessExpressionReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEventProcessExpressionReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEventProcessExpressionReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEventProcessExpressionReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEventProcessExpressionReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IEventProcessExpressionReport_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_FCProcessExpression,0x7186468B,0x2B6F,0x46BA,0x83,0xB4,0x02,0x14,0x50,0x24,0xBF,0x7B);

#ifdef __cplusplus

class DECLSPEC_UUID("7186468B-2B6F-46BA-83B4-02145024BF7B")
FCProcessExpression;
#endif

#ifndef __IFCReport_DISPINTERFACE_DEFINED__
#define __IFCReport_DISPINTERFACE_DEFINED__

/* dispinterface IFCReport */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCReport,0x247E7369,0xAE46,0x441F,0x92,0xEB,0x14,0xE4,0xC0,0x67,0x23,0xEE);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("247E7369-AE46-441F-92EB-14E4C06723EE")
    IFCReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCReportVtbl;

    interface IFCReport
    {
        CONST_VTBL struct IFCReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCReport_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_FCReport,0x75537A12,0xA3C4,0x407E,0x84,0x04,0xCF,0xD0,0x0A,0x4C,0x8F,0xD3);

#ifdef __cplusplus

class DECLSPEC_UUID("75537A12-A3C4-407E-8404-CFD00A4C8FD3")
FCReport;
#endif

#ifndef __IFCGrafData_DISPINTERFACE_DEFINED__
#define __IFCGrafData_DISPINTERFACE_DEFINED__

/* dispinterface IFCGrafData */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCGrafData,0x74BD760D,0x6D27,0x4F43,0xBC,0xEA,0x14,0x30,0x26,0x9B,0xC0,0x88);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("74BD760D-6D27-4F43-BCEA-1430269BC088")
    IFCGrafData : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCGrafDataVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCGrafData * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCGrafData * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCGrafData * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCGrafData * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCGrafData * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCGrafData * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCGrafData * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCGrafDataVtbl;

    interface IFCGrafData
    {
        CONST_VTBL struct IFCGrafDataVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCGrafData_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCGrafData_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCGrafData_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCGrafData_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCGrafData_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCGrafData_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCGrafData_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCGrafData_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualGrafData_INTERFACE_DEFINED__
#define __IFCDualGrafData_INTERFACE_DEFINED__

/* interface IFCDualGrafData */
/* [helpstring][dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualGrafData,0xB199418D,0x20BD,0x46e6,0x9F,0x53,0xF8,0xFA,0xCB,0x28,0xE2,0x10);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B199418D-20BD-46e6-9F53-F8FACB28E210")
    IFCDualGrafData : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AxisPlane1( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AxisPlane1( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AxisPlane2( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AxisPlane2( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolAxis( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolAxis( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CorrectorMode( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CorrectorMode( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PartMinX( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PartMinX( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PartMinY( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PartMinY( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PartMinZ( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PartMinZ( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PartMaxX( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PartMaxX( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PartMaxY( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PartMaxY( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PartMaxZ( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PartMaxZ( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PartZeroX( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PartZeroX( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PartZeroY( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PartZeroY( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PartZeroZ( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PartZeroZ( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolNumber( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolNumber( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolLength( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolLength( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolRadius( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolRadius( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolNosea( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolNosea( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolNosew( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolNosew( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolCuta( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolCuta( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Actualize( 
            /* [in] */ long channel,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [in] */ long channel,
            /* [in] */ CNC_MODE_T mode,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Disconnect( 
            /* [in] */ long channel,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsBlockEnd( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsBlockChange( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsFifoFull( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsCompensatedMov( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsCannedCycle( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsThreadTapping( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsZoneChange( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsPartZeroChange( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsToolChange( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsPlaneChange( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsG0( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsLinealMov( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AxisRealValue( 
            /* [in] */ short numAxis,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AxisRealValue( 
            /* [in] */ short numAxis,
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AxisTheoreticValue( 
            /* [in] */ short numAxis,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AxisTheoreticValue( 
            /* [in] */ short numAxis,
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolTipRadius( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolTipRadius( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsValidAxisData( 
            /* [in] */ short numAxis,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsBallbarActive( 
            /* [in] */ long channel,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ActivateBallbar( 
            /* [in] */ long channel) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeactivateBallbar( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ActualizeBallbar( 
            /* [in] */ long channel,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolLocationCode( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolLocationCode( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolLc( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolLc( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolFixori( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolFixori( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SpindlePosIncrement( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SpindlePosIncrement( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SpindlePosReal( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SpindlePosReal( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SpindlePosTheoretic( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SpindlePosTheoretic( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AxisPlane3( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AxisPlane3( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TipoGraf( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TipoGraf( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TornoXZ( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TornoXZ( 
            /* [in] */ BOOL nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolTyp( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolTyp( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolSubTyp( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolSubTyp( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AxisRealMachineValue( 
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AxisRealMachineValue( 
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AxisTheoreticMachineValue( 
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AxisTheoreticMachineValue( 
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_VelocidadGrafSimu( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_VelocidadGrafSimu( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsNuevaG33( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PasoG33( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PasoG33( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_EjeG33( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_EjeG33( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DisconnectNotify( 
            /* [in] */ long channel,
            /* [in] */ CNC_MODE_T mode,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AxisRealMachineBaseValue( 
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AxisRealMachineBaseValue( 
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AxisTheoreticMachineBaseValue( 
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AxisTheoreticMachineBaseValue( 
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsKinematicChange( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ActiveKinId( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ActiveKinId( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SpindleLogNumber( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SpindleLogNumber( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAxisLog( 
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PieceInDGWZ( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PieceInDGWZ( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsChannelInDGWZ( 
            /* [in] */ long channel,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLogAxis( 
            /* [in] */ short index,
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsNewInfo( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLazoCount( 
            /* [retval][out] */ unsigned long *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ToolType( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ToolType( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Actualize2( 
            /* [in] */ long channel,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsProgramStarted( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ActivateGraf( 
            /* [in] */ long channel,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ActivateGrafSimu( 
            /* [in] */ long channel,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeactivateGraf( 
            /* [in] */ long channel,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeactivateGrafSimu( 
            /* [in] */ long channel,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsSpdlStatusChange( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSpdlStatus( 
            /* [in] */ short index,
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSpdlSpeed( 
            /* [in] */ short index,
            /* [retval][out] */ double *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsStateChange( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsForcedOutput( 
            /* [retval][out] */ BOOL *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualGrafDataVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualGrafData * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualGrafData * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualGrafData * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualGrafData * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualGrafData * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualGrafData * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualGrafData * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxisPlane1 )( 
            IFCDualGrafData * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AxisPlane1 )( 
            IFCDualGrafData * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxisPlane2 )( 
            IFCDualGrafData * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AxisPlane2 )( 
            IFCDualGrafData * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolAxis )( 
            IFCDualGrafData * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolAxis )( 
            IFCDualGrafData * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CorrectorMode )( 
            IFCDualGrafData * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CorrectorMode )( 
            IFCDualGrafData * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PartMinX )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PartMinX )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PartMinY )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PartMinY )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PartMinZ )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PartMinZ )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PartMaxX )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PartMaxX )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PartMaxY )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PartMaxY )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PartMaxZ )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PartMaxZ )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PartZeroX )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PartZeroX )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PartZeroY )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PartZeroY )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PartZeroZ )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PartZeroZ )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolNumber )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolNumber )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolLength )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolLength )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolRadius )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolRadius )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolNosea )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolNosea )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolNosew )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolNosew )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolCuta )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolCuta )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Actualize )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [in] */ CNC_MODE_T mode,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsBlockEnd )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsBlockChange )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsFifoFull )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsCompensatedMov )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsCannedCycle )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsThreadTapping )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsZoneChange )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsPartZeroChange )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsToolChange )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsPlaneChange )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsG0 )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsLinealMov )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxisRealValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AxisRealValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxisTheoreticValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AxisTheoreticValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolTipRadius )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolTipRadius )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsValidAxisData )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsBallbarActive )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ActivateBallbar )( 
            IFCDualGrafData * This,
            /* [in] */ long channel);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeactivateBallbar )( 
            IFCDualGrafData * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ActualizeBallbar )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolLocationCode )( 
            IFCDualGrafData * This,
            /* [retval][out] */ short *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolLocationCode )( 
            IFCDualGrafData * This,
            /* [in] */ short nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolLc )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolLc )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolFixori )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolFixori )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpindlePosIncrement )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpindlePosIncrement )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpindlePosReal )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpindlePosReal )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpindlePosTheoretic )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpindlePosTheoretic )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxisPlane3 )( 
            IFCDualGrafData * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AxisPlane3 )( 
            IFCDualGrafData * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TipoGraf )( 
            IFCDualGrafData * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TipoGraf )( 
            IFCDualGrafData * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TornoXZ )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TornoXZ )( 
            IFCDualGrafData * This,
            /* [in] */ BOOL nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolTyp )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolTyp )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolSubTyp )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolSubTyp )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxisRealMachineValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AxisRealMachineValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxisTheoreticMachineValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AxisTheoreticMachineValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_VelocidadGrafSimu )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_VelocidadGrafSimu )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsNuevaG33 )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PasoG33 )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PasoG33 )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EjeG33 )( 
            IFCDualGrafData * This,
            /* [retval][out] */ short *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EjeG33 )( 
            IFCDualGrafData * This,
            /* [in] */ short nNewValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DisconnectNotify )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [in] */ CNC_MODE_T mode,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxisRealMachineBaseValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AxisRealMachineBaseValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxisTheoreticMachineBaseValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AxisTheoreticMachineBaseValue )( 
            IFCDualGrafData * This,
            /* [in] */ short numAxis,
            /* [in] */ long *numLog,
            /* [in] */ long nNewValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsKinematicChange )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveKinId )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActiveKinId )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SpindleLogNumber )( 
            IFCDualGrafData * This,
            /* [retval][out] */ short *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SpindleLogNumber )( 
            IFCDualGrafData * This,
            /* [in] */ short nNewValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAxisLog )( 
            IFCDualGrafData * This,
            /* [in] */ BSTR str_axis,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PieceInDGWZ )( 
            IFCDualGrafData * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PieceInDGWZ )( 
            IFCDualGrafData * This,
            /* [in] */ short nNewValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsChannelInDGWZ )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLogAxis )( 
            IFCDualGrafData * This,
            /* [in] */ short index,
            /* [retval][out] */ short *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsNewInfo )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLazoCount )( 
            IFCDualGrafData * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ToolType )( 
            IFCDualGrafData * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ToolType )( 
            IFCDualGrafData * This,
            /* [in] */ long nNewValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Actualize2 )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsProgramStarted )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ActivateGraf )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ActivateGrafSimu )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeactivateGraf )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeactivateGrafSimu )( 
            IFCDualGrafData * This,
            /* [in] */ long channel,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsSpdlStatusChange )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSpdlStatus )( 
            IFCDualGrafData * This,
            /* [in] */ short index,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSpdlSpeed )( 
            IFCDualGrafData * This,
            /* [in] */ short index,
            /* [retval][out] */ double *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsStateChange )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsForcedOutput )( 
            IFCDualGrafData * This,
            /* [retval][out] */ BOOL *retval);
        
        END_INTERFACE
    } IFCDualGrafDataVtbl;

    interface IFCDualGrafData
    {
        CONST_VTBL struct IFCDualGrafDataVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualGrafData_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualGrafData_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualGrafData_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualGrafData_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualGrafData_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualGrafData_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualGrafData_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualGrafData_get_AxisPlane1(This,retval)	\
    (This)->lpVtbl -> get_AxisPlane1(This,retval)

#define IFCDualGrafData_put_AxisPlane1(This,nNewValue)	\
    (This)->lpVtbl -> put_AxisPlane1(This,nNewValue)

#define IFCDualGrafData_get_AxisPlane2(This,retval)	\
    (This)->lpVtbl -> get_AxisPlane2(This,retval)

#define IFCDualGrafData_put_AxisPlane2(This,nNewValue)	\
    (This)->lpVtbl -> put_AxisPlane2(This,nNewValue)

#define IFCDualGrafData_get_ToolAxis(This,retval)	\
    (This)->lpVtbl -> get_ToolAxis(This,retval)

#define IFCDualGrafData_put_ToolAxis(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolAxis(This,nNewValue)

#define IFCDualGrafData_get_CorrectorMode(This,retval)	\
    (This)->lpVtbl -> get_CorrectorMode(This,retval)

#define IFCDualGrafData_put_CorrectorMode(This,nNewValue)	\
    (This)->lpVtbl -> put_CorrectorMode(This,nNewValue)

#define IFCDualGrafData_get_PartMinX(This,retval)	\
    (This)->lpVtbl -> get_PartMinX(This,retval)

#define IFCDualGrafData_put_PartMinX(This,nNewValue)	\
    (This)->lpVtbl -> put_PartMinX(This,nNewValue)

#define IFCDualGrafData_get_PartMinY(This,retval)	\
    (This)->lpVtbl -> get_PartMinY(This,retval)

#define IFCDualGrafData_put_PartMinY(This,nNewValue)	\
    (This)->lpVtbl -> put_PartMinY(This,nNewValue)

#define IFCDualGrafData_get_PartMinZ(This,retval)	\
    (This)->lpVtbl -> get_PartMinZ(This,retval)

#define IFCDualGrafData_put_PartMinZ(This,nNewValue)	\
    (This)->lpVtbl -> put_PartMinZ(This,nNewValue)

#define IFCDualGrafData_get_PartMaxX(This,retval)	\
    (This)->lpVtbl -> get_PartMaxX(This,retval)

#define IFCDualGrafData_put_PartMaxX(This,nNewValue)	\
    (This)->lpVtbl -> put_PartMaxX(This,nNewValue)

#define IFCDualGrafData_get_PartMaxY(This,retval)	\
    (This)->lpVtbl -> get_PartMaxY(This,retval)

#define IFCDualGrafData_put_PartMaxY(This,nNewValue)	\
    (This)->lpVtbl -> put_PartMaxY(This,nNewValue)

#define IFCDualGrafData_get_PartMaxZ(This,retval)	\
    (This)->lpVtbl -> get_PartMaxZ(This,retval)

#define IFCDualGrafData_put_PartMaxZ(This,nNewValue)	\
    (This)->lpVtbl -> put_PartMaxZ(This,nNewValue)

#define IFCDualGrafData_get_PartZeroX(This,retval)	\
    (This)->lpVtbl -> get_PartZeroX(This,retval)

#define IFCDualGrafData_put_PartZeroX(This,nNewValue)	\
    (This)->lpVtbl -> put_PartZeroX(This,nNewValue)

#define IFCDualGrafData_get_PartZeroY(This,retval)	\
    (This)->lpVtbl -> get_PartZeroY(This,retval)

#define IFCDualGrafData_put_PartZeroY(This,nNewValue)	\
    (This)->lpVtbl -> put_PartZeroY(This,nNewValue)

#define IFCDualGrafData_get_PartZeroZ(This,retval)	\
    (This)->lpVtbl -> get_PartZeroZ(This,retval)

#define IFCDualGrafData_put_PartZeroZ(This,nNewValue)	\
    (This)->lpVtbl -> put_PartZeroZ(This,nNewValue)

#define IFCDualGrafData_get_ToolNumber(This,retval)	\
    (This)->lpVtbl -> get_ToolNumber(This,retval)

#define IFCDualGrafData_put_ToolNumber(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolNumber(This,nNewValue)

#define IFCDualGrafData_get_ToolLength(This,retval)	\
    (This)->lpVtbl -> get_ToolLength(This,retval)

#define IFCDualGrafData_put_ToolLength(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolLength(This,nNewValue)

#define IFCDualGrafData_get_ToolRadius(This,retval)	\
    (This)->lpVtbl -> get_ToolRadius(This,retval)

#define IFCDualGrafData_put_ToolRadius(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolRadius(This,nNewValue)

#define IFCDualGrafData_get_ToolNosea(This,retval)	\
    (This)->lpVtbl -> get_ToolNosea(This,retval)

#define IFCDualGrafData_put_ToolNosea(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolNosea(This,nNewValue)

#define IFCDualGrafData_get_ToolNosew(This,retval)	\
    (This)->lpVtbl -> get_ToolNosew(This,retval)

#define IFCDualGrafData_put_ToolNosew(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolNosew(This,nNewValue)

#define IFCDualGrafData_get_ToolCuta(This,retval)	\
    (This)->lpVtbl -> get_ToolCuta(This,retval)

#define IFCDualGrafData_put_ToolCuta(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolCuta(This,nNewValue)

#define IFCDualGrafData_Actualize(This,channel,retval)	\
    (This)->lpVtbl -> Actualize(This,channel,retval)

#define IFCDualGrafData_Connect(This,channel,mode,retval)	\
    (This)->lpVtbl -> Connect(This,channel,mode,retval)

#define IFCDualGrafData_Disconnect(This,channel,retval)	\
    (This)->lpVtbl -> Disconnect(This,channel,retval)

#define IFCDualGrafData_IsBlockEnd(This,retval)	\
    (This)->lpVtbl -> IsBlockEnd(This,retval)

#define IFCDualGrafData_IsBlockChange(This,retval)	\
    (This)->lpVtbl -> IsBlockChange(This,retval)

#define IFCDualGrafData_IsFifoFull(This,retval)	\
    (This)->lpVtbl -> IsFifoFull(This,retval)

#define IFCDualGrafData_IsCompensatedMov(This,retval)	\
    (This)->lpVtbl -> IsCompensatedMov(This,retval)

#define IFCDualGrafData_IsCannedCycle(This,retval)	\
    (This)->lpVtbl -> IsCannedCycle(This,retval)

#define IFCDualGrafData_IsThreadTapping(This,retval)	\
    (This)->lpVtbl -> IsThreadTapping(This,retval)

#define IFCDualGrafData_IsZoneChange(This,retval)	\
    (This)->lpVtbl -> IsZoneChange(This,retval)

#define IFCDualGrafData_IsPartZeroChange(This,retval)	\
    (This)->lpVtbl -> IsPartZeroChange(This,retval)

#define IFCDualGrafData_IsToolChange(This,retval)	\
    (This)->lpVtbl -> IsToolChange(This,retval)

#define IFCDualGrafData_IsPlaneChange(This,retval)	\
    (This)->lpVtbl -> IsPlaneChange(This,retval)

#define IFCDualGrafData_IsG0(This,retval)	\
    (This)->lpVtbl -> IsG0(This,retval)

#define IFCDualGrafData_IsLinealMov(This,retval)	\
    (This)->lpVtbl -> IsLinealMov(This,retval)

#define IFCDualGrafData_get_AxisRealValue(This,numAxis,retval)	\
    (This)->lpVtbl -> get_AxisRealValue(This,numAxis,retval)

#define IFCDualGrafData_put_AxisRealValue(This,numAxis,nNewValue)	\
    (This)->lpVtbl -> put_AxisRealValue(This,numAxis,nNewValue)

#define IFCDualGrafData_get_AxisTheoreticValue(This,numAxis,retval)	\
    (This)->lpVtbl -> get_AxisTheoreticValue(This,numAxis,retval)

#define IFCDualGrafData_put_AxisTheoreticValue(This,numAxis,nNewValue)	\
    (This)->lpVtbl -> put_AxisTheoreticValue(This,numAxis,nNewValue)

#define IFCDualGrafData_get_ToolTipRadius(This,retval)	\
    (This)->lpVtbl -> get_ToolTipRadius(This,retval)

#define IFCDualGrafData_put_ToolTipRadius(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolTipRadius(This,nNewValue)

#define IFCDualGrafData_IsValidAxisData(This,numAxis,retval)	\
    (This)->lpVtbl -> IsValidAxisData(This,numAxis,retval)

#define IFCDualGrafData_IsBallbarActive(This,channel,retval)	\
    (This)->lpVtbl -> IsBallbarActive(This,channel,retval)

#define IFCDualGrafData_ActivateBallbar(This,channel)	\
    (This)->lpVtbl -> ActivateBallbar(This,channel)

#define IFCDualGrafData_DeactivateBallbar(This)	\
    (This)->lpVtbl -> DeactivateBallbar(This)

#define IFCDualGrafData_ActualizeBallbar(This,channel,retval)	\
    (This)->lpVtbl -> ActualizeBallbar(This,channel,retval)

#define IFCDualGrafData_get_ToolLocationCode(This,retval)	\
    (This)->lpVtbl -> get_ToolLocationCode(This,retval)

#define IFCDualGrafData_put_ToolLocationCode(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolLocationCode(This,nNewValue)

#define IFCDualGrafData_get_ToolLc(This,retval)	\
    (This)->lpVtbl -> get_ToolLc(This,retval)

#define IFCDualGrafData_put_ToolLc(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolLc(This,nNewValue)

#define IFCDualGrafData_get_ToolFixori(This,retval)	\
    (This)->lpVtbl -> get_ToolFixori(This,retval)

#define IFCDualGrafData_put_ToolFixori(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolFixori(This,nNewValue)

#define IFCDualGrafData_get_SpindlePosIncrement(This,retval)	\
    (This)->lpVtbl -> get_SpindlePosIncrement(This,retval)

#define IFCDualGrafData_put_SpindlePosIncrement(This,nNewValue)	\
    (This)->lpVtbl -> put_SpindlePosIncrement(This,nNewValue)

#define IFCDualGrafData_get_SpindlePosReal(This,retval)	\
    (This)->lpVtbl -> get_SpindlePosReal(This,retval)

#define IFCDualGrafData_put_SpindlePosReal(This,nNewValue)	\
    (This)->lpVtbl -> put_SpindlePosReal(This,nNewValue)

#define IFCDualGrafData_get_SpindlePosTheoretic(This,retval)	\
    (This)->lpVtbl -> get_SpindlePosTheoretic(This,retval)

#define IFCDualGrafData_put_SpindlePosTheoretic(This,nNewValue)	\
    (This)->lpVtbl -> put_SpindlePosTheoretic(This,nNewValue)

#define IFCDualGrafData_get_AxisPlane3(This,retval)	\
    (This)->lpVtbl -> get_AxisPlane3(This,retval)

#define IFCDualGrafData_put_AxisPlane3(This,nNewValue)	\
    (This)->lpVtbl -> put_AxisPlane3(This,nNewValue)

#define IFCDualGrafData_get_TipoGraf(This,retval)	\
    (This)->lpVtbl -> get_TipoGraf(This,retval)

#define IFCDualGrafData_put_TipoGraf(This,nNewValue)	\
    (This)->lpVtbl -> put_TipoGraf(This,nNewValue)

#define IFCDualGrafData_get_TornoXZ(This,retval)	\
    (This)->lpVtbl -> get_TornoXZ(This,retval)

#define IFCDualGrafData_put_TornoXZ(This,nNewValue)	\
    (This)->lpVtbl -> put_TornoXZ(This,nNewValue)

#define IFCDualGrafData_get_ToolTyp(This,retval)	\
    (This)->lpVtbl -> get_ToolTyp(This,retval)

#define IFCDualGrafData_put_ToolTyp(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolTyp(This,nNewValue)

#define IFCDualGrafData_get_ToolSubTyp(This,retval)	\
    (This)->lpVtbl -> get_ToolSubTyp(This,retval)

#define IFCDualGrafData_put_ToolSubTyp(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolSubTyp(This,nNewValue)

#define IFCDualGrafData_get_AxisRealMachineValue(This,numAxis,numLog,retval)	\
    (This)->lpVtbl -> get_AxisRealMachineValue(This,numAxis,numLog,retval)

#define IFCDualGrafData_put_AxisRealMachineValue(This,numAxis,numLog,nNewValue)	\
    (This)->lpVtbl -> put_AxisRealMachineValue(This,numAxis,numLog,nNewValue)

#define IFCDualGrafData_get_AxisTheoreticMachineValue(This,numAxis,numLog,retval)	\
    (This)->lpVtbl -> get_AxisTheoreticMachineValue(This,numAxis,numLog,retval)

#define IFCDualGrafData_put_AxisTheoreticMachineValue(This,numAxis,numLog,nNewValue)	\
    (This)->lpVtbl -> put_AxisTheoreticMachineValue(This,numAxis,numLog,nNewValue)

#define IFCDualGrafData_get_VelocidadGrafSimu(This,retval)	\
    (This)->lpVtbl -> get_VelocidadGrafSimu(This,retval)

#define IFCDualGrafData_put_VelocidadGrafSimu(This,nNewValue)	\
    (This)->lpVtbl -> put_VelocidadGrafSimu(This,nNewValue)

#define IFCDualGrafData_IsNuevaG33(This,retval)	\
    (This)->lpVtbl -> IsNuevaG33(This,retval)

#define IFCDualGrafData_get_PasoG33(This,retval)	\
    (This)->lpVtbl -> get_PasoG33(This,retval)

#define IFCDualGrafData_put_PasoG33(This,nNewValue)	\
    (This)->lpVtbl -> put_PasoG33(This,nNewValue)

#define IFCDualGrafData_get_EjeG33(This,retval)	\
    (This)->lpVtbl -> get_EjeG33(This,retval)

#define IFCDualGrafData_put_EjeG33(This,nNewValue)	\
    (This)->lpVtbl -> put_EjeG33(This,nNewValue)

#define IFCDualGrafData_DisconnectNotify(This,channel,mode,retval)	\
    (This)->lpVtbl -> DisconnectNotify(This,channel,mode,retval)

#define IFCDualGrafData_get_AxisRealMachineBaseValue(This,numAxis,numLog,retval)	\
    (This)->lpVtbl -> get_AxisRealMachineBaseValue(This,numAxis,numLog,retval)

#define IFCDualGrafData_put_AxisRealMachineBaseValue(This,numAxis,numLog,nNewValue)	\
    (This)->lpVtbl -> put_AxisRealMachineBaseValue(This,numAxis,numLog,nNewValue)

#define IFCDualGrafData_get_AxisTheoreticMachineBaseValue(This,numAxis,numLog,retval)	\
    (This)->lpVtbl -> get_AxisTheoreticMachineBaseValue(This,numAxis,numLog,retval)

#define IFCDualGrafData_put_AxisTheoreticMachineBaseValue(This,numAxis,numLog,nNewValue)	\
    (This)->lpVtbl -> put_AxisTheoreticMachineBaseValue(This,numAxis,numLog,nNewValue)

#define IFCDualGrafData_IsKinematicChange(This,retval)	\
    (This)->lpVtbl -> IsKinematicChange(This,retval)

#define IFCDualGrafData_get_ActiveKinId(This,retval)	\
    (This)->lpVtbl -> get_ActiveKinId(This,retval)

#define IFCDualGrafData_put_ActiveKinId(This,nNewValue)	\
    (This)->lpVtbl -> put_ActiveKinId(This,nNewValue)

#define IFCDualGrafData_get_SpindleLogNumber(This,retval)	\
    (This)->lpVtbl -> get_SpindleLogNumber(This,retval)

#define IFCDualGrafData_put_SpindleLogNumber(This,nNewValue)	\
    (This)->lpVtbl -> put_SpindleLogNumber(This,nNewValue)

#define IFCDualGrafData_GetAxisLog(This,str_axis,retval)	\
    (This)->lpVtbl -> GetAxisLog(This,str_axis,retval)

#define IFCDualGrafData_get_PieceInDGWZ(This,retval)	\
    (This)->lpVtbl -> get_PieceInDGWZ(This,retval)

#define IFCDualGrafData_put_PieceInDGWZ(This,nNewValue)	\
    (This)->lpVtbl -> put_PieceInDGWZ(This,nNewValue)

#define IFCDualGrafData_IsChannelInDGWZ(This,channel,retval)	\
    (This)->lpVtbl -> IsChannelInDGWZ(This,channel,retval)

#define IFCDualGrafData_GetLogAxis(This,index,retval)	\
    (This)->lpVtbl -> GetLogAxis(This,index,retval)

#define IFCDualGrafData_IsNewInfo(This,retval)	\
    (This)->lpVtbl -> IsNewInfo(This,retval)

#define IFCDualGrafData_GetLazoCount(This,retval)	\
    (This)->lpVtbl -> GetLazoCount(This,retval)

#define IFCDualGrafData_get_ToolType(This,retval)	\
    (This)->lpVtbl -> get_ToolType(This,retval)

#define IFCDualGrafData_put_ToolType(This,nNewValue)	\
    (This)->lpVtbl -> put_ToolType(This,nNewValue)

#define IFCDualGrafData_Actualize2(This,channel,retval)	\
    (This)->lpVtbl -> Actualize2(This,channel,retval)

#define IFCDualGrafData_IsProgramStarted(This,retval)	\
    (This)->lpVtbl -> IsProgramStarted(This,retval)

#define IFCDualGrafData_ActivateGraf(This,channel,retval)	\
    (This)->lpVtbl -> ActivateGraf(This,channel,retval)

#define IFCDualGrafData_ActivateGrafSimu(This,channel,retval)	\
    (This)->lpVtbl -> ActivateGrafSimu(This,channel,retval)

#define IFCDualGrafData_DeactivateGraf(This,channel,retval)	\
    (This)->lpVtbl -> DeactivateGraf(This,channel,retval)

#define IFCDualGrafData_DeactivateGrafSimu(This,channel,retval)	\
    (This)->lpVtbl -> DeactivateGrafSimu(This,channel,retval)

#define IFCDualGrafData_IsSpdlStatusChange(This,retval)	\
    (This)->lpVtbl -> IsSpdlStatusChange(This,retval)

#define IFCDualGrafData_GetSpdlStatus(This,index,retval)	\
    (This)->lpVtbl -> GetSpdlStatus(This,index,retval)

#define IFCDualGrafData_GetSpdlSpeed(This,index,retval)	\
    (This)->lpVtbl -> GetSpdlSpeed(This,index,retval)

#define IFCDualGrafData_IsStateChange(This,retval)	\
    (This)->lpVtbl -> IsStateChange(This,retval)

#define IFCDualGrafData_IsForcedOutput(This,retval)	\
    (This)->lpVtbl -> IsForcedOutput(This,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_AxisPlane1_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_get_AxisPlane1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_AxisPlane1_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualGrafData_put_AxisPlane1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_AxisPlane2_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_get_AxisPlane2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_AxisPlane2_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualGrafData_put_AxisPlane2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolAxis_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_get_ToolAxis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolAxis_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolAxis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_CorrectorMode_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_get_CorrectorMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_CorrectorMode_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualGrafData_put_CorrectorMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_PartMinX_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_PartMinX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_PartMinX_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_PartMinX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_PartMinY_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_PartMinY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_PartMinY_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_PartMinY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_PartMinZ_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_PartMinZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_PartMinZ_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_PartMinZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_PartMaxX_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_PartMaxX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_PartMaxX_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_PartMaxX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_PartMaxY_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_PartMaxY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_PartMaxY_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_PartMaxY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_PartMaxZ_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_PartMaxZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_PartMaxZ_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_PartMaxZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_PartZeroX_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_PartZeroX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_PartZeroX_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_PartZeroX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_PartZeroY_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_PartZeroY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_PartZeroY_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_PartZeroY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_PartZeroZ_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_PartZeroZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_PartZeroZ_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_PartZeroZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolNumber_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolNumber_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolLength_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolLength_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolRadius_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolRadius_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolRadius_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolRadius_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolNosea_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolNosea_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolNosea_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolNosea_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolNosew_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolNosew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolNosew_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolNosew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolCuta_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolCuta_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolCuta_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolCuta_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_Actualize_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_Actualize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_Connect_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [in] */ CNC_MODE_T mode,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_Disconnect_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsBlockEnd_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsBlockEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsBlockChange_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsBlockChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsFifoFull_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsFifoFull_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsCompensatedMov_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsCompensatedMov_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsCannedCycle_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsCannedCycle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsThreadTapping_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsThreadTapping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsZoneChange_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsZoneChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsPartZeroChange_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsPartZeroChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsToolChange_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsToolChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsPlaneChange_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsPlaneChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsG0_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsG0_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsLinealMov_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsLinealMov_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_AxisRealValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_AxisRealValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_AxisRealValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_AxisRealValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_AxisTheoreticValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_AxisTheoreticValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_AxisTheoreticValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_AxisTheoreticValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolTipRadius_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolTipRadius_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolTipRadius_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolTipRadius_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsValidAxisData_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsValidAxisData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsBallbarActive_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsBallbarActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_ActivateBallbar_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel);


void __RPC_STUB IFCDualGrafData_ActivateBallbar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_DeactivateBallbar_Proxy( 
    IFCDualGrafData * This);


void __RPC_STUB IFCDualGrafData_DeactivateBallbar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_ActualizeBallbar_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_ActualizeBallbar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolLocationCode_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_get_ToolLocationCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolLocationCode_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolLocationCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolLc_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolLc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolLc_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolLc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolFixori_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolFixori_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolFixori_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolFixori_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_SpindlePosIncrement_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_SpindlePosIncrement_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_SpindlePosIncrement_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_SpindlePosIncrement_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_SpindlePosReal_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_SpindlePosReal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_SpindlePosReal_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_SpindlePosReal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_SpindlePosTheoretic_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_SpindlePosTheoretic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_SpindlePosTheoretic_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_SpindlePosTheoretic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_AxisPlane3_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_get_AxisPlane3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_AxisPlane3_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualGrafData_put_AxisPlane3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_TipoGraf_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_get_TipoGraf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_TipoGraf_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualGrafData_put_TipoGraf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_TornoXZ_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_get_TornoXZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_TornoXZ_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ BOOL nNewValue);


void __RPC_STUB IFCDualGrafData_put_TornoXZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolTyp_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolTyp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolTyp_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolTyp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolSubTyp_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolSubTyp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolSubTyp_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolSubTyp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_AxisRealMachineValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [in] */ long *numLog,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_AxisRealMachineValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_AxisRealMachineValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [in] */ long *numLog,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_AxisRealMachineValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_AxisTheoreticMachineValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [in] */ long *numLog,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_AxisTheoreticMachineValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_AxisTheoreticMachineValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [in] */ long *numLog,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_AxisTheoreticMachineValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_VelocidadGrafSimu_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_VelocidadGrafSimu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_VelocidadGrafSimu_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_VelocidadGrafSimu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsNuevaG33_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsNuevaG33_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_PasoG33_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_PasoG33_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_PasoG33_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_PasoG33_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_EjeG33_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_get_EjeG33_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_EjeG33_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualGrafData_put_EjeG33_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_DisconnectNotify_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [in] */ CNC_MODE_T mode,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_DisconnectNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_AxisRealMachineBaseValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [in] */ long *numLog,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_AxisRealMachineBaseValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_AxisRealMachineBaseValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [in] */ long *numLog,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_AxisRealMachineBaseValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_AxisTheoreticMachineBaseValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [in] */ long *numLog,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_AxisTheoreticMachineBaseValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_AxisTheoreticMachineBaseValue_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short numAxis,
    /* [in] */ long *numLog,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_AxisTheoreticMachineBaseValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsKinematicChange_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsKinematicChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ActiveKinId_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ActiveKinId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ActiveKinId_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ActiveKinId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_SpindleLogNumber_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_get_SpindleLogNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_SpindleLogNumber_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualGrafData_put_SpindleLogNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_GetAxisLog_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ BSTR str_axis,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_GetAxisLog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_PieceInDGWZ_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_get_PieceInDGWZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_PieceInDGWZ_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualGrafData_put_PieceInDGWZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsChannelInDGWZ_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsChannelInDGWZ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_GetLogAxis_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short index,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_GetLogAxis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsNewInfo_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsNewInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_GetLazoCount_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ unsigned long *retval);


void __RPC_STUB IFCDualGrafData_GetLazoCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_get_ToolType_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_get_ToolType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_put_ToolType_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IFCDualGrafData_put_ToolType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_Actualize2_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_Actualize2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsProgramStarted_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsProgramStarted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_ActivateGraf_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_ActivateGraf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_ActivateGrafSimu_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_ActivateGrafSimu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_DeactivateGraf_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_DeactivateGraf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_DeactivateGrafSimu_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ long channel,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualGrafData_DeactivateGrafSimu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsSpdlStatusChange_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsSpdlStatusChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_GetSpdlStatus_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short index,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualGrafData_GetSpdlStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_GetSpdlSpeed_Proxy( 
    IFCDualGrafData * This,
    /* [in] */ short index,
    /* [retval][out] */ double *retval);


void __RPC_STUB IFCDualGrafData_GetSpdlSpeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsStateChange_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsStateChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualGrafData_IsForcedOutput_Proxy( 
    IFCDualGrafData * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualGrafData_IsForcedOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualGrafData_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_GrafData,0x0DF2C589,0xC3B4,0x4907,0xA4,0xE6,0x86,0xD3,0xE7,0x14,0xEC,0xFA);

#ifdef __cplusplus

class DECLSPEC_UUID("0DF2C589-C3B4-4907-A4E6-86D3E714ECFA")
CNC8070_GrafData;
#endif

#ifndef __IFCPlc_DISPINTERFACE_DEFINED__
#define __IFCPlc_DISPINTERFACE_DEFINED__

/* dispinterface IFCPlc */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCPlc,0xE19BF6BD,0x75F1,0x4CFF,0x9A,0x4A,0xC9,0xC0,0xF0,0xA9,0x22,0x75);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E19BF6BD-75F1-4CFF-9A4A-C9C0F0A92275")
    IFCPlc : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCPlcVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCPlc * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCPlc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCPlc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCPlc * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCPlc * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCPlc * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCPlc * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCPlcVtbl;

    interface IFCPlc
    {
        CONST_VTBL struct IFCPlcVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCPlc_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCPlc_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCPlc_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCPlc_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCPlc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCPlc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCPlc_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCPlc_DISPINTERFACE_DEFINED__ */


#ifndef __ICYStartReport_DISPINTERFACE_DEFINED__
#define __ICYStartReport_DISPINTERFACE_DEFINED__

/* dispinterface ICYStartReport */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_ICYStartReport,0xB433167B,0xC579,0x4a84,0x89,0x47,0x71,0x13,0x49,0xA0,0xA1,0x44);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B433167B-C579-4a84-8947-711349A0A144")
    ICYStartReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ICYStartReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICYStartReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICYStartReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICYStartReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICYStartReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICYStartReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICYStartReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICYStartReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ICYStartReportVtbl;

    interface ICYStartReport
    {
        CONST_VTBL struct ICYStartReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICYStartReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICYStartReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICYStartReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICYStartReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICYStartReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICYStartReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICYStartReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ICYStartReport_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualPlc_INTERFACE_DEFINED__
#define __IFCDualPlc_INTERFACE_DEFINED__

/* interface IFCDualPlc */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualPlc,0x37C78069,0xA5A4,0x40a4,0xB4,0x7F,0x0B,0x93,0x85,0xFD,0xEA,0x95);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37C78069-A5A4-40a4-B47F-0B9385FDEA95")
    IFCDualPlc : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PlcRequest( 
            /* [in] */ PLC_INTERFACE_T action,
            /* [in] */ long channel,
            /* [in] */ short key,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetPlcMsgList( 
            /* [out] */ VARIANT *idArray,
            /* [out] */ VARIANT *textArray,
            /* [out] */ VARIANT *prgArray,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetStartManager( 
            /* [in] */ BOOL bSetManager,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsAnyStartManager( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetStartManagerEx( 
            /* [in] */ long pfnFunc) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetPlcMsgList2( 
            /* [out] */ SAFEARRAY * *pArray,
            /* [out] */ SAFEARRAY * *textArray,
            /* [out] */ SAFEARRAY * *prgArray,
            /* [retval][out] */ BOOL *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualPlcVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualPlc * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualPlc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualPlc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualPlc * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualPlc * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualPlc * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualPlc * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PlcRequest )( 
            IFCDualPlc * This,
            /* [in] */ PLC_INTERFACE_T action,
            /* [in] */ long channel,
            /* [in] */ short key,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetPlcMsgList )( 
            IFCDualPlc * This,
            /* [out] */ VARIANT *idArray,
            /* [out] */ VARIANT *textArray,
            /* [out] */ VARIANT *prgArray,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetStartManager )( 
            IFCDualPlc * This,
            /* [in] */ BOOL bSetManager,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsAnyStartManager )( 
            IFCDualPlc * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetStartManagerEx )( 
            IFCDualPlc * This,
            /* [in] */ long pfnFunc);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetPlcMsgList2 )( 
            IFCDualPlc * This,
            /* [out] */ SAFEARRAY * *pArray,
            /* [out] */ SAFEARRAY * *textArray,
            /* [out] */ SAFEARRAY * *prgArray,
            /* [retval][out] */ BOOL *retval);
        
        END_INTERFACE
    } IFCDualPlcVtbl;

    interface IFCDualPlc
    {
        CONST_VTBL struct IFCDualPlcVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualPlc_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualPlc_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualPlc_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualPlc_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualPlc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualPlc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualPlc_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualPlc_PlcRequest(This,action,channel,key,retval)	\
    (This)->lpVtbl -> PlcRequest(This,action,channel,key,retval)

#define IFCDualPlc_GetPlcMsgList(This,idArray,textArray,prgArray,retval)	\
    (This)->lpVtbl -> GetPlcMsgList(This,idArray,textArray,prgArray,retval)

#define IFCDualPlc_SetStartManager(This,bSetManager,retval)	\
    (This)->lpVtbl -> SetStartManager(This,bSetManager,retval)

#define IFCDualPlc_IsAnyStartManager(This,retval)	\
    (This)->lpVtbl -> IsAnyStartManager(This,retval)

#define IFCDualPlc_SetStartManagerEx(This,pfnFunc)	\
    (This)->lpVtbl -> SetStartManagerEx(This,pfnFunc)

#define IFCDualPlc_GetPlcMsgList2(This,pArray,textArray,prgArray,retval)	\
    (This)->lpVtbl -> GetPlcMsgList2(This,pArray,textArray,prgArray,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualPlc_PlcRequest_Proxy( 
    IFCDualPlc * This,
    /* [in] */ PLC_INTERFACE_T action,
    /* [in] */ long channel,
    /* [in] */ short key,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualPlc_PlcRequest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualPlc_GetPlcMsgList_Proxy( 
    IFCDualPlc * This,
    /* [out] */ VARIANT *idArray,
    /* [out] */ VARIANT *textArray,
    /* [out] */ VARIANT *prgArray,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualPlc_GetPlcMsgList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualPlc_SetStartManager_Proxy( 
    IFCDualPlc * This,
    /* [in] */ BOOL bSetManager,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualPlc_SetStartManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualPlc_IsAnyStartManager_Proxy( 
    IFCDualPlc * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualPlc_IsAnyStartManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualPlc_SetStartManagerEx_Proxy( 
    IFCDualPlc * This,
    /* [in] */ long pfnFunc);


void __RPC_STUB IFCDualPlc_SetStartManagerEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualPlc_GetPlcMsgList2_Proxy( 
    IFCDualPlc * This,
    /* [out] */ SAFEARRAY * *pArray,
    /* [out] */ SAFEARRAY * *textArray,
    /* [out] */ SAFEARRAY * *prgArray,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualPlc_GetPlcMsgList2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualPlc_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_Plc,0x49163E87,0xD865,0x4A93,0xA7,0xCC,0x72,0xA0,0xA9,0x1B,0xE2,0x01);

#ifdef __cplusplus

class DECLSPEC_UUID("49163E87-D865-4A93-A7CC-72A0A91BE201")
CNC8070_Plc;
#endif

#ifndef __IFCApiFixtureTable_DISPINTERFACE_DEFINED__
#define __IFCApiFixtureTable_DISPINTERFACE_DEFINED__

/* dispinterface IFCApiFixtureTable */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCApiFixtureTable,0x87073454,0xA638,0x4B2B,0xBE,0xC5,0x19,0x3F,0xE7,0x93,0xF4,0xF3);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("87073454-A638-4B2B-BEC5-193FE793F4F3")
    IFCApiFixtureTable : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCApiFixtureTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCApiFixtureTable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCApiFixtureTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCApiFixtureTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCApiFixtureTable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCApiFixtureTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCApiFixtureTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCApiFixtureTable * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCApiFixtureTableVtbl;

    interface IFCApiFixtureTable
    {
        CONST_VTBL struct IFCApiFixtureTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCApiFixtureTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCApiFixtureTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCApiFixtureTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCApiFixtureTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCApiFixtureTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCApiFixtureTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCApiFixtureTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCApiFixtureTable_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualApiFixtureTable_INTERFACE_DEFINED__
#define __IFCDualApiFixtureTable_INTERFACE_DEFINED__

/* interface IFCDualApiFixtureTable */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualApiFixtureTable,0x58702A67,0xF465,0x4439,0xB7,0xEF,0xD7,0x0A,0xE8,0xE6,0xCF,0x4E);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("58702A67-F465-4439-B7EF-D70AE8E6CF4E")
    IFCDualApiFixtureTable : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenReport( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CloseReport( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetItemCount( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFixtureOffset( 
            /* [in] */ long numFixture,
            /* [in] */ long numAxis,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetFixtureOffset( 
            /* [in] */ long numFixture,
            /* [in] */ long numAxis,
            /* [in] */ long offset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualApiFixtureTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualApiFixtureTable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualApiFixtureTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualApiFixtureTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualApiFixtureTable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualApiFixtureTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualApiFixtureTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualApiFixtureTable * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenReport )( 
            IFCDualApiFixtureTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CloseReport )( 
            IFCDualApiFixtureTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetItemCount )( 
            IFCDualApiFixtureTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFixtureOffset )( 
            IFCDualApiFixtureTable * This,
            /* [in] */ long numFixture,
            /* [in] */ long numAxis,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetFixtureOffset )( 
            IFCDualApiFixtureTable * This,
            /* [in] */ long numFixture,
            /* [in] */ long numAxis,
            /* [in] */ long offset);
        
        END_INTERFACE
    } IFCDualApiFixtureTableVtbl;

    interface IFCDualApiFixtureTable
    {
        CONST_VTBL struct IFCDualApiFixtureTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualApiFixtureTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualApiFixtureTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualApiFixtureTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualApiFixtureTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualApiFixtureTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualApiFixtureTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualApiFixtureTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualApiFixtureTable_OpenReport(This,retval)	\
    (This)->lpVtbl -> OpenReport(This,retval)

#define IFCDualApiFixtureTable_CloseReport(This,retval)	\
    (This)->lpVtbl -> CloseReport(This,retval)

#define IFCDualApiFixtureTable_GetItemCount(This,retval)	\
    (This)->lpVtbl -> GetItemCount(This,retval)

#define IFCDualApiFixtureTable_GetFixtureOffset(This,numFixture,numAxis,retval)	\
    (This)->lpVtbl -> GetFixtureOffset(This,numFixture,numAxis,retval)

#define IFCDualApiFixtureTable_SetFixtureOffset(This,numFixture,numAxis,offset)	\
    (This)->lpVtbl -> SetFixtureOffset(This,numFixture,numAxis,offset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiFixtureTable_OpenReport_Proxy( 
    IFCDualApiFixtureTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiFixtureTable_OpenReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiFixtureTable_CloseReport_Proxy( 
    IFCDualApiFixtureTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiFixtureTable_CloseReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiFixtureTable_GetItemCount_Proxy( 
    IFCDualApiFixtureTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiFixtureTable_GetItemCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiFixtureTable_GetFixtureOffset_Proxy( 
    IFCDualApiFixtureTable * This,
    /* [in] */ long numFixture,
    /* [in] */ long numAxis,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiFixtureTable_GetFixtureOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiFixtureTable_SetFixtureOffset_Proxy( 
    IFCDualApiFixtureTable * This,
    /* [in] */ long numFixture,
    /* [in] */ long numAxis,
    /* [in] */ long offset);


void __RPC_STUB IFCDualApiFixtureTable_SetFixtureOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualApiFixtureTable_INTERFACE_DEFINED__ */


#ifndef __IFixtureReport_DISPINTERFACE_DEFINED__
#define __IFixtureReport_DISPINTERFACE_DEFINED__

/* dispinterface IFixtureReport */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_IFixtureReport,0xB3840F87,0xEFBF,0x43aa,0x99,0x7C,0xCF,0xAE,0xE2,0xD6,0xED,0x42);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B3840F87-EFBF-43aa-997C-CFAEE2D6ED42")
    IFixtureReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFixtureReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFixtureReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFixtureReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFixtureReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFixtureReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFixtureReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFixtureReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFixtureReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFixtureReportVtbl;

    interface IFixtureReport
    {
        CONST_VTBL struct IFixtureReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFixtureReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFixtureReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFixtureReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFixtureReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFixtureReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFixtureReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFixtureReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFixtureReport_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_FixtureTable,0x4F5DFDAC,0x02FF,0x4487,0x81,0xEA,0xD5,0x8D,0x45,0x66,0x7E,0x8D);

#ifdef __cplusplus

class DECLSPEC_UUID("4F5DFDAC-02FF-4487-81EA-D58D45667E8D")
CNC8070_FixtureTable;
#endif

#ifndef __IFCApiOriginTable_DISPINTERFACE_DEFINED__
#define __IFCApiOriginTable_DISPINTERFACE_DEFINED__

/* dispinterface IFCApiOriginTable */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCApiOriginTable,0xAEEE4A22,0x4BDA,0x44CD,0x88,0x02,0x62,0x9E,0x2D,0xF0,0x70,0x17);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AEEE4A22-4BDA-44CD-8802-629E2DF07017")
    IFCApiOriginTable : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCApiOriginTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCApiOriginTable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCApiOriginTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCApiOriginTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCApiOriginTable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCApiOriginTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCApiOriginTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCApiOriginTable * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCApiOriginTableVtbl;

    interface IFCApiOriginTable
    {
        CONST_VTBL struct IFCApiOriginTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCApiOriginTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCApiOriginTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCApiOriginTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCApiOriginTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCApiOriginTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCApiOriginTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCApiOriginTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCApiOriginTable_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualApiOriginTable_INTERFACE_DEFINED__
#define __IFCDualApiOriginTable_INTERFACE_DEFINED__

/* interface IFCDualApiOriginTable */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualApiOriginTable,0xD2FB68AF,0x1087,0x4d65,0x8D,0x24,0x5E,0xDC,0xAD,0x00,0xDE,0x61);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D2FB68AF-1087-4d65-8D24-5EDCAD00DE61")
    IFCDualApiOriginTable : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenReport( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CloseReport( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetItemCount( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetOriginOffset( 
            /* [in] */ long numOrigin,
            /* [in] */ long numAxis,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetOriginOffset( 
            /* [in] */ long numOrigin,
            /* [in] */ long numAxis,
            /* [in] */ long offset) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetOriginName( 
            /* [in] */ long numOrigin,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetOriginNames( 
            /* [out][in] */ VARIANT *valuesArray) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFineOffset( 
            /* [in] */ long numOrigin,
            /* [in] */ long numAxis,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetFineOffset( 
            /* [in] */ long numOrigin,
            /* [in] */ long numAxis,
            /* [in] */ long offset) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualApiOriginTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualApiOriginTable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualApiOriginTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualApiOriginTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualApiOriginTable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualApiOriginTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualApiOriginTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualApiOriginTable * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenReport )( 
            IFCDualApiOriginTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CloseReport )( 
            IFCDualApiOriginTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetItemCount )( 
            IFCDualApiOriginTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetOriginOffset )( 
            IFCDualApiOriginTable * This,
            /* [in] */ long numOrigin,
            /* [in] */ long numAxis,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetOriginOffset )( 
            IFCDualApiOriginTable * This,
            /* [in] */ long numOrigin,
            /* [in] */ long numAxis,
            /* [in] */ long offset);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetOriginName )( 
            IFCDualApiOriginTable * This,
            /* [in] */ long numOrigin,
            /* [retval][out] */ BSTR *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetOriginNames )( 
            IFCDualApiOriginTable * This,
            /* [out][in] */ VARIANT *valuesArray);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFineOffset )( 
            IFCDualApiOriginTable * This,
            /* [in] */ long numOrigin,
            /* [in] */ long numAxis,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetFineOffset )( 
            IFCDualApiOriginTable * This,
            /* [in] */ long numOrigin,
            /* [in] */ long numAxis,
            /* [in] */ long offset);
        
        END_INTERFACE
    } IFCDualApiOriginTableVtbl;

    interface IFCDualApiOriginTable
    {
        CONST_VTBL struct IFCDualApiOriginTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualApiOriginTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualApiOriginTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualApiOriginTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualApiOriginTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualApiOriginTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualApiOriginTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualApiOriginTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualApiOriginTable_OpenReport(This,retval)	\
    (This)->lpVtbl -> OpenReport(This,retval)

#define IFCDualApiOriginTable_CloseReport(This,retval)	\
    (This)->lpVtbl -> CloseReport(This,retval)

#define IFCDualApiOriginTable_GetItemCount(This,retval)	\
    (This)->lpVtbl -> GetItemCount(This,retval)

#define IFCDualApiOriginTable_GetOriginOffset(This,numOrigin,numAxis,retval)	\
    (This)->lpVtbl -> GetOriginOffset(This,numOrigin,numAxis,retval)

#define IFCDualApiOriginTable_SetOriginOffset(This,numOrigin,numAxis,offset)	\
    (This)->lpVtbl -> SetOriginOffset(This,numOrigin,numAxis,offset)

#define IFCDualApiOriginTable_GetOriginName(This,numOrigin,retval)	\
    (This)->lpVtbl -> GetOriginName(This,numOrigin,retval)

#define IFCDualApiOriginTable_GetOriginNames(This,valuesArray)	\
    (This)->lpVtbl -> GetOriginNames(This,valuesArray)

#define IFCDualApiOriginTable_GetFineOffset(This,numOrigin,numAxis,retval)	\
    (This)->lpVtbl -> GetFineOffset(This,numOrigin,numAxis,retval)

#define IFCDualApiOriginTable_SetFineOffset(This,numOrigin,numAxis,offset)	\
    (This)->lpVtbl -> SetFineOffset(This,numOrigin,numAxis,offset)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiOriginTable_OpenReport_Proxy( 
    IFCDualApiOriginTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiOriginTable_OpenReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiOriginTable_CloseReport_Proxy( 
    IFCDualApiOriginTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiOriginTable_CloseReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiOriginTable_GetItemCount_Proxy( 
    IFCDualApiOriginTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiOriginTable_GetItemCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiOriginTable_GetOriginOffset_Proxy( 
    IFCDualApiOriginTable * This,
    /* [in] */ long numOrigin,
    /* [in] */ long numAxis,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiOriginTable_GetOriginOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiOriginTable_SetOriginOffset_Proxy( 
    IFCDualApiOriginTable * This,
    /* [in] */ long numOrigin,
    /* [in] */ long numAxis,
    /* [in] */ long offset);


void __RPC_STUB IFCDualApiOriginTable_SetOriginOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiOriginTable_GetOriginName_Proxy( 
    IFCDualApiOriginTable * This,
    /* [in] */ long numOrigin,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualApiOriginTable_GetOriginName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiOriginTable_GetOriginNames_Proxy( 
    IFCDualApiOriginTable * This,
    /* [out][in] */ VARIANT *valuesArray);


void __RPC_STUB IFCDualApiOriginTable_GetOriginNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiOriginTable_GetFineOffset_Proxy( 
    IFCDualApiOriginTable * This,
    /* [in] */ long numOrigin,
    /* [in] */ long numAxis,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiOriginTable_GetFineOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiOriginTable_SetFineOffset_Proxy( 
    IFCDualApiOriginTable * This,
    /* [in] */ long numOrigin,
    /* [in] */ long numAxis,
    /* [in] */ long offset);


void __RPC_STUB IFCDualApiOriginTable_SetFineOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualApiOriginTable_INTERFACE_DEFINED__ */


#ifndef __IOriginReport_DISPINTERFACE_DEFINED__
#define __IOriginReport_DISPINTERFACE_DEFINED__

/* dispinterface IOriginReport */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_IOriginReport,0x1E670F81,0x1EE7,0x48d2,0x9B,0x1B,0xE0,0xC6,0xD5,0x88,0x15,0x7B);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1E670F81-1EE7-48d2-9B1B-E0C6D588157B")
    IOriginReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IOriginReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOriginReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOriginReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOriginReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOriginReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOriginReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOriginReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOriginReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IOriginReportVtbl;

    interface IOriginReport
    {
        CONST_VTBL struct IOriginReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOriginReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOriginReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOriginReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOriginReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOriginReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOriginReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOriginReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IOriginReport_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_OriginTable,0x342F53CD,0x78A7,0x45D8,0xA3,0x72,0x02,0x9D,0xF3,0x50,0xF4,0x9F);

#ifdef __cplusplus

class DECLSPEC_UUID("342F53CD-78A7-45D8-A372-029DF350F49F")
CNC8070_OriginTable;
#endif

#ifndef __IFCApiPParamTable_DISPINTERFACE_DEFINED__
#define __IFCApiPParamTable_DISPINTERFACE_DEFINED__

/* dispinterface IFCApiPParamTable */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCApiPParamTable,0xD9B79514,0x52A5,0x4126,0x9C,0x6E,0x8F,0x60,0xC8,0xD3,0xC3,0xB9);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D9B79514-52A5-4126-9C6E-8F60C8D3C3B9")
    IFCApiPParamTable : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCApiPParamTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCApiPParamTable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCApiPParamTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCApiPParamTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCApiPParamTable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCApiPParamTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCApiPParamTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCApiPParamTable * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCApiPParamTableVtbl;

    interface IFCApiPParamTable
    {
        CONST_VTBL struct IFCApiPParamTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCApiPParamTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCApiPParamTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCApiPParamTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCApiPParamTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCApiPParamTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCApiPParamTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCApiPParamTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCApiPParamTable_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualApiPParamTable_INTERFACE_DEFINED__
#define __IFCDualApiPParamTable_INTERFACE_DEFINED__

/* interface IFCDualApiPParamTable */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualApiPParamTable,0x3C0F3C59,0x2C8F,0x430a,0x82,0x6F,0x14,0xFD,0xDF,0xD5,0x2D,0x7E);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C0F3C59-2C8F-430a-826F-14FDDFD52D7E")
    IFCDualApiPParamTable : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetItemCount( 
            /* [in] */ PPARAM_TABLE_TYPE_T tableType,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFirstItem( 
            /* [in] */ PPARAM_TABLE_TYPE_T tableType,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenReport( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CloseReport( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadGlobalPParams( 
            /* [in] */ short channel,
            /* [retval][out] */ VARIANT *valuesArray) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadLocalPParams( 
            /* [in] */ short channel,
            /* [in] */ short level,
            /* [retval][out] */ VARIANT *valuesArray) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadGlobalPParam( 
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [retval][out] */ double *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadLocalPParam( 
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ short level,
            /* [retval][out] */ double *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteGlobalPParam( 
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ double value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteLocalPParam( 
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ short level,
            /* [in] */ double value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteGlobalPParams( 
            /* [in] */ short channel,
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteLocalPParams( 
            /* [in] */ short channel,
            /* [in] */ short level,
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTableCount( 
            /* [in] */ PPARAM_TABLE_TYPE_T tableType,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadCommonPParams( 
            /* [retval][out] */ VARIANT *valuesArray) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadCommonPParam( 
            /* [in] */ short index,
            /* [retval][out] */ double *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteCommonPParams( 
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteCommonPParam( 
            /* [in] */ short index,
            /* [in] */ double value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadGlobalPParamsSim( 
            /* [in] */ short channel,
            /* [retval][out] */ VARIANT *valuesArray) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadLocalPParamsSim( 
            /* [in] */ short channel,
            /* [in] */ short level,
            /* [retval][out] */ VARIANT *valuesArray) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadGlobalPParamSim( 
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [retval][out] */ double *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadLocalPParamSim( 
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ short level,
            /* [retval][out] */ double *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteGlobalPParamSim( 
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ double value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteLocalPParamSim( 
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ short level,
            /* [in] */ double value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteGlobalPParamsSim( 
            /* [in] */ short channel,
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteLocalPParamsSim( 
            /* [in] */ short channel,
            /* [in] */ short level,
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadCommonPParamsSim( 
            /* [retval][out] */ VARIANT *valuesArray) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadCommonPParamSim( 
            /* [in] */ short index,
            /* [retval][out] */ double *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteCommonPParamsSim( 
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteCommonPParamSim( 
            /* [in] */ short index,
            /* [in] */ double value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualApiPParamTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualApiPParamTable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualApiPParamTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualApiPParamTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualApiPParamTable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualApiPParamTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualApiPParamTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualApiPParamTable * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetItemCount )( 
            IFCDualApiPParamTable * This,
            /* [in] */ PPARAM_TABLE_TYPE_T tableType,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFirstItem )( 
            IFCDualApiPParamTable * This,
            /* [in] */ PPARAM_TABLE_TYPE_T tableType,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenReport )( 
            IFCDualApiPParamTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CloseReport )( 
            IFCDualApiPParamTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadGlobalPParams )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [retval][out] */ VARIANT *valuesArray);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadLocalPParams )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short level,
            /* [retval][out] */ VARIANT *valuesArray);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadGlobalPParam )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [retval][out] */ double *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadLocalPParam )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ short level,
            /* [retval][out] */ double *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteGlobalPParam )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ double value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteLocalPParam )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ short level,
            /* [in] */ double value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteGlobalPParams )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteLocalPParams )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short level,
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTableCount )( 
            IFCDualApiPParamTable * This,
            /* [in] */ PPARAM_TABLE_TYPE_T tableType,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadCommonPParams )( 
            IFCDualApiPParamTable * This,
            /* [retval][out] */ VARIANT *valuesArray);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadCommonPParam )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short index,
            /* [retval][out] */ double *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteCommonPParams )( 
            IFCDualApiPParamTable * This,
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteCommonPParam )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short index,
            /* [in] */ double value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadGlobalPParamsSim )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [retval][out] */ VARIANT *valuesArray);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadLocalPParamsSim )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short level,
            /* [retval][out] */ VARIANT *valuesArray);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadGlobalPParamSim )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [retval][out] */ double *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadLocalPParamSim )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ short level,
            /* [retval][out] */ double *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteGlobalPParamSim )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ double value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteLocalPParamSim )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short index,
            /* [in] */ short level,
            /* [in] */ double value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteGlobalPParamsSim )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteLocalPParamsSim )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short channel,
            /* [in] */ short level,
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadCommonPParamsSim )( 
            IFCDualApiPParamTable * This,
            /* [retval][out] */ VARIANT *valuesArray);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadCommonPParamSim )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short index,
            /* [retval][out] */ double *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteCommonPParamsSim )( 
            IFCDualApiPParamTable * This,
            /* [in] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteCommonPParamSim )( 
            IFCDualApiPParamTable * This,
            /* [in] */ short index,
            /* [in] */ double value);
        
        END_INTERFACE
    } IFCDualApiPParamTableVtbl;

    interface IFCDualApiPParamTable
    {
        CONST_VTBL struct IFCDualApiPParamTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualApiPParamTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualApiPParamTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualApiPParamTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualApiPParamTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualApiPParamTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualApiPParamTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualApiPParamTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualApiPParamTable_GetItemCount(This,tableType,retval)	\
    (This)->lpVtbl -> GetItemCount(This,tableType,retval)

#define IFCDualApiPParamTable_GetFirstItem(This,tableType,retval)	\
    (This)->lpVtbl -> GetFirstItem(This,tableType,retval)

#define IFCDualApiPParamTable_OpenReport(This,retval)	\
    (This)->lpVtbl -> OpenReport(This,retval)

#define IFCDualApiPParamTable_CloseReport(This,retval)	\
    (This)->lpVtbl -> CloseReport(This,retval)

#define IFCDualApiPParamTable_ReadGlobalPParams(This,channel,valuesArray)	\
    (This)->lpVtbl -> ReadGlobalPParams(This,channel,valuesArray)

#define IFCDualApiPParamTable_ReadLocalPParams(This,channel,level,valuesArray)	\
    (This)->lpVtbl -> ReadLocalPParams(This,channel,level,valuesArray)

#define IFCDualApiPParamTable_ReadGlobalPParam(This,channel,index,retval)	\
    (This)->lpVtbl -> ReadGlobalPParam(This,channel,index,retval)

#define IFCDualApiPParamTable_ReadLocalPParam(This,channel,index,level,retval)	\
    (This)->lpVtbl -> ReadLocalPParam(This,channel,index,level,retval)

#define IFCDualApiPParamTable_WriteGlobalPParam(This,channel,index,value)	\
    (This)->lpVtbl -> WriteGlobalPParam(This,channel,index,value)

#define IFCDualApiPParamTable_WriteLocalPParam(This,channel,index,level,value)	\
    (This)->lpVtbl -> WriteLocalPParam(This,channel,index,level,value)

#define IFCDualApiPParamTable_WriteGlobalPParams(This,channel,valuesArray,retval)	\
    (This)->lpVtbl -> WriteGlobalPParams(This,channel,valuesArray,retval)

#define IFCDualApiPParamTable_WriteLocalPParams(This,channel,level,valuesArray,retval)	\
    (This)->lpVtbl -> WriteLocalPParams(This,channel,level,valuesArray,retval)

#define IFCDualApiPParamTable_GetTableCount(This,tableType,retval)	\
    (This)->lpVtbl -> GetTableCount(This,tableType,retval)

#define IFCDualApiPParamTable_ReadCommonPParams(This,valuesArray)	\
    (This)->lpVtbl -> ReadCommonPParams(This,valuesArray)

#define IFCDualApiPParamTable_ReadCommonPParam(This,index,retval)	\
    (This)->lpVtbl -> ReadCommonPParam(This,index,retval)

#define IFCDualApiPParamTable_WriteCommonPParams(This,valuesArray,retval)	\
    (This)->lpVtbl -> WriteCommonPParams(This,valuesArray,retval)

#define IFCDualApiPParamTable_WriteCommonPParam(This,index,value)	\
    (This)->lpVtbl -> WriteCommonPParam(This,index,value)

#define IFCDualApiPParamTable_ReadGlobalPParamsSim(This,channel,valuesArray)	\
    (This)->lpVtbl -> ReadGlobalPParamsSim(This,channel,valuesArray)

#define IFCDualApiPParamTable_ReadLocalPParamsSim(This,channel,level,valuesArray)	\
    (This)->lpVtbl -> ReadLocalPParamsSim(This,channel,level,valuesArray)

#define IFCDualApiPParamTable_ReadGlobalPParamSim(This,channel,index,retval)	\
    (This)->lpVtbl -> ReadGlobalPParamSim(This,channel,index,retval)

#define IFCDualApiPParamTable_ReadLocalPParamSim(This,channel,index,level,retval)	\
    (This)->lpVtbl -> ReadLocalPParamSim(This,channel,index,level,retval)

#define IFCDualApiPParamTable_WriteGlobalPParamSim(This,channel,index,value)	\
    (This)->lpVtbl -> WriteGlobalPParamSim(This,channel,index,value)

#define IFCDualApiPParamTable_WriteLocalPParamSim(This,channel,index,level,value)	\
    (This)->lpVtbl -> WriteLocalPParamSim(This,channel,index,level,value)

#define IFCDualApiPParamTable_WriteGlobalPParamsSim(This,channel,valuesArray,retval)	\
    (This)->lpVtbl -> WriteGlobalPParamsSim(This,channel,valuesArray,retval)

#define IFCDualApiPParamTable_WriteLocalPParamsSim(This,channel,level,valuesArray,retval)	\
    (This)->lpVtbl -> WriteLocalPParamsSim(This,channel,level,valuesArray,retval)

#define IFCDualApiPParamTable_ReadCommonPParamsSim(This,valuesArray)	\
    (This)->lpVtbl -> ReadCommonPParamsSim(This,valuesArray)

#define IFCDualApiPParamTable_ReadCommonPParamSim(This,index,retval)	\
    (This)->lpVtbl -> ReadCommonPParamSim(This,index,retval)

#define IFCDualApiPParamTable_WriteCommonPParamsSim(This,valuesArray,retval)	\
    (This)->lpVtbl -> WriteCommonPParamsSim(This,valuesArray,retval)

#define IFCDualApiPParamTable_WriteCommonPParamSim(This,index,value)	\
    (This)->lpVtbl -> WriteCommonPParamSim(This,index,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_GetItemCount_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ PPARAM_TABLE_TYPE_T tableType,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiPParamTable_GetItemCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_GetFirstItem_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ PPARAM_TABLE_TYPE_T tableType,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiPParamTable_GetFirstItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_OpenReport_Proxy( 
    IFCDualApiPParamTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiPParamTable_OpenReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_CloseReport_Proxy( 
    IFCDualApiPParamTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiPParamTable_CloseReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadGlobalPParams_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [retval][out] */ VARIANT *valuesArray);


void __RPC_STUB IFCDualApiPParamTable_ReadGlobalPParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadLocalPParams_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short level,
    /* [retval][out] */ VARIANT *valuesArray);


void __RPC_STUB IFCDualApiPParamTable_ReadLocalPParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadGlobalPParam_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short index,
    /* [retval][out] */ double *retval);


void __RPC_STUB IFCDualApiPParamTable_ReadGlobalPParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadLocalPParam_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short index,
    /* [in] */ short level,
    /* [retval][out] */ double *retval);


void __RPC_STUB IFCDualApiPParamTable_ReadLocalPParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteGlobalPParam_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short index,
    /* [in] */ double value);


void __RPC_STUB IFCDualApiPParamTable_WriteGlobalPParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteLocalPParam_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short index,
    /* [in] */ short level,
    /* [in] */ double value);


void __RPC_STUB IFCDualApiPParamTable_WriteLocalPParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteGlobalPParams_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ SAFEARRAY * *valuesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiPParamTable_WriteGlobalPParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteLocalPParams_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short level,
    /* [in] */ SAFEARRAY * *valuesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiPParamTable_WriteLocalPParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_GetTableCount_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ PPARAM_TABLE_TYPE_T tableType,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiPParamTable_GetTableCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadCommonPParams_Proxy( 
    IFCDualApiPParamTable * This,
    /* [retval][out] */ VARIANT *valuesArray);


void __RPC_STUB IFCDualApiPParamTable_ReadCommonPParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadCommonPParam_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short index,
    /* [retval][out] */ double *retval);


void __RPC_STUB IFCDualApiPParamTable_ReadCommonPParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteCommonPParams_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ SAFEARRAY * *valuesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiPParamTable_WriteCommonPParams_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteCommonPParam_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short index,
    /* [in] */ double value);


void __RPC_STUB IFCDualApiPParamTable_WriteCommonPParam_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadGlobalPParamsSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [retval][out] */ VARIANT *valuesArray);


void __RPC_STUB IFCDualApiPParamTable_ReadGlobalPParamsSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadLocalPParamsSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short level,
    /* [retval][out] */ VARIANT *valuesArray);


void __RPC_STUB IFCDualApiPParamTable_ReadLocalPParamsSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadGlobalPParamSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short index,
    /* [retval][out] */ double *retval);


void __RPC_STUB IFCDualApiPParamTable_ReadGlobalPParamSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadLocalPParamSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short index,
    /* [in] */ short level,
    /* [retval][out] */ double *retval);


void __RPC_STUB IFCDualApiPParamTable_ReadLocalPParamSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteGlobalPParamSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short index,
    /* [in] */ double value);


void __RPC_STUB IFCDualApiPParamTable_WriteGlobalPParamSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteLocalPParamSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short index,
    /* [in] */ short level,
    /* [in] */ double value);


void __RPC_STUB IFCDualApiPParamTable_WriteLocalPParamSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteGlobalPParamsSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ SAFEARRAY * *valuesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiPParamTable_WriteGlobalPParamsSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteLocalPParamsSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short channel,
    /* [in] */ short level,
    /* [in] */ SAFEARRAY * *valuesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiPParamTable_WriteLocalPParamsSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadCommonPParamsSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [retval][out] */ VARIANT *valuesArray);


void __RPC_STUB IFCDualApiPParamTable_ReadCommonPParamsSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_ReadCommonPParamSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short index,
    /* [retval][out] */ double *retval);


void __RPC_STUB IFCDualApiPParamTable_ReadCommonPParamSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteCommonPParamsSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ SAFEARRAY * *valuesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualApiPParamTable_WriteCommonPParamsSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualApiPParamTable_WriteCommonPParamSim_Proxy( 
    IFCDualApiPParamTable * This,
    /* [in] */ short index,
    /* [in] */ double value);


void __RPC_STUB IFCDualApiPParamTable_WriteCommonPParamSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualApiPParamTable_INTERFACE_DEFINED__ */


#ifndef __IPParamReport_DISPINTERFACE_DEFINED__
#define __IPParamReport_DISPINTERFACE_DEFINED__

/* dispinterface IPParamReport */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_IPParamReport,0x5F6948A0,0x6DCB,0x4e25,0x99,0x28,0x2C,0x0C,0x55,0x7C,0xA8,0x50);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5F6948A0-6DCB-4e25-9928-2C0C557CA850")
    IPParamReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IPParamReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPParamReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPParamReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPParamReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPParamReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPParamReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPParamReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPParamReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IPParamReportVtbl;

    interface IPParamReport
    {
        CONST_VTBL struct IPParamReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPParamReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPParamReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPParamReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPParamReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IPParamReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IPParamReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IPParamReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IPParamReport_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_PParamTable,0xE6366E83,0x5090,0x4D06,0x99,0xE9,0x65,0x9F,0x34,0x4D,0x1B,0x76);

#ifdef __cplusplus

class DECLSPEC_UUID("E6366E83-5090-4D06-99E9-659F344D1B76")
CNC8070_PParamTable;
#endif

#ifndef __IFCDualITool_INTERFACE_DEFINED__
#define __IFCDualITool_INTERFACE_DEFINED__

/* interface IFCDualITool */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualITool,0x099472BF,0x8AF1,0x45f8,0x86,0xC2,0xC9,0x95,0x63,0x6A,0xF4,0x55);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("099472BF-8AF1-45f8-86C2-C995636AF455")
    IFCDualITool : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ID( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Comment( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Comment( 
            /* [in] */ BSTR newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Special( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Special( 
            /* [in] */ BOOL newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Size2( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Size2( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Family( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Family( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Custom1( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Custom1( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Custom2( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Custom2( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Custom3( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Custom3( 
            /* [in] */ short newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Custom4( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Custom4( 
            /* [in] */ short newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_NumberOfEdges( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_NumberOfEdges( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ long *toLeft,
            /* [out] */ long *toRight,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetSize( 
            /* [in] */ long size,
            /* [in] */ long toLeft,
            /* [in] */ long toRight) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetStatus( 
            /* [in] */ long bitsRemove,
            /* [in] */ long bitsAdd) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ToolCopy( 
            /* [out] */ long *pTool,
            /* [in] */ long iSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualIToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualITool * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualITool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualITool * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualITool * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualITool * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualITool * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualITool * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IFCDualITool * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ID )( 
            IFCDualITool * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IFCDualITool * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IFCDualITool * This,
            /* [in] */ BSTR newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Comment )( 
            IFCDualITool * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Comment )( 
            IFCDualITool * This,
            /* [in] */ BSTR newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Special )( 
            IFCDualITool * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Special )( 
            IFCDualITool * This,
            /* [in] */ BOOL newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Size2 )( 
            IFCDualITool * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Size2 )( 
            IFCDualITool * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Family )( 
            IFCDualITool * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Family )( 
            IFCDualITool * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Custom1 )( 
            IFCDualITool * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Custom1 )( 
            IFCDualITool * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Custom2 )( 
            IFCDualITool * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Custom2 )( 
            IFCDualITool * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Custom3 )( 
            IFCDualITool * This,
            /* [retval][out] */ short *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Custom3 )( 
            IFCDualITool * This,
            /* [in] */ short newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Custom4 )( 
            IFCDualITool * This,
            /* [retval][out] */ short *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Custom4 )( 
            IFCDualITool * This,
            /* [in] */ short newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NumberOfEdges )( 
            IFCDualITool * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NumberOfEdges )( 
            IFCDualITool * This,
            /* [in] */ long newValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            IFCDualITool * This,
            /* [out] */ long *toLeft,
            /* [out] */ long *toRight,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            IFCDualITool * This,
            /* [in] */ long size,
            /* [in] */ long toLeft,
            /* [in] */ long toRight);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            IFCDualITool * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetStatus )( 
            IFCDualITool * This,
            /* [in] */ long bitsRemove,
            /* [in] */ long bitsAdd);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ToolCopy )( 
            IFCDualITool * This,
            /* [out] */ long *pTool,
            /* [in] */ long iSize);
        
        END_INTERFACE
    } IFCDualIToolVtbl;

    interface IFCDualITool
    {
        CONST_VTBL struct IFCDualIToolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualITool_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualITool_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualITool_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualITool_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualITool_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualITool_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualITool_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualITool_get_ID(This,retval)	\
    (This)->lpVtbl -> get_ID(This,retval)

#define IFCDualITool_put_ID(This,newValue)	\
    (This)->lpVtbl -> put_ID(This,newValue)

#define IFCDualITool_get_Name(This,retval)	\
    (This)->lpVtbl -> get_Name(This,retval)

#define IFCDualITool_put_Name(This,newValue)	\
    (This)->lpVtbl -> put_Name(This,newValue)

#define IFCDualITool_get_Comment(This,retval)	\
    (This)->lpVtbl -> get_Comment(This,retval)

#define IFCDualITool_put_Comment(This,newValue)	\
    (This)->lpVtbl -> put_Comment(This,newValue)

#define IFCDualITool_get_Special(This,retval)	\
    (This)->lpVtbl -> get_Special(This,retval)

#define IFCDualITool_put_Special(This,newValue)	\
    (This)->lpVtbl -> put_Special(This,newValue)

#define IFCDualITool_get_Size2(This,retval)	\
    (This)->lpVtbl -> get_Size2(This,retval)

#define IFCDualITool_put_Size2(This,newValue)	\
    (This)->lpVtbl -> put_Size2(This,newValue)

#define IFCDualITool_get_Family(This,retval)	\
    (This)->lpVtbl -> get_Family(This,retval)

#define IFCDualITool_put_Family(This,newValue)	\
    (This)->lpVtbl -> put_Family(This,newValue)

#define IFCDualITool_get_Custom1(This,retval)	\
    (This)->lpVtbl -> get_Custom1(This,retval)

#define IFCDualITool_put_Custom1(This,newValue)	\
    (This)->lpVtbl -> put_Custom1(This,newValue)

#define IFCDualITool_get_Custom2(This,retval)	\
    (This)->lpVtbl -> get_Custom2(This,retval)

#define IFCDualITool_put_Custom2(This,newValue)	\
    (This)->lpVtbl -> put_Custom2(This,newValue)

#define IFCDualITool_get_Custom3(This,retval)	\
    (This)->lpVtbl -> get_Custom3(This,retval)

#define IFCDualITool_put_Custom3(This,newValue)	\
    (This)->lpVtbl -> put_Custom3(This,newValue)

#define IFCDualITool_get_Custom4(This,retval)	\
    (This)->lpVtbl -> get_Custom4(This,retval)

#define IFCDualITool_put_Custom4(This,newValue)	\
    (This)->lpVtbl -> put_Custom4(This,newValue)

#define IFCDualITool_get_NumberOfEdges(This,retval)	\
    (This)->lpVtbl -> get_NumberOfEdges(This,retval)

#define IFCDualITool_put_NumberOfEdges(This,newValue)	\
    (This)->lpVtbl -> put_NumberOfEdges(This,newValue)

#define IFCDualITool_GetSize(This,toLeft,toRight,retval)	\
    (This)->lpVtbl -> GetSize(This,toLeft,toRight,retval)

#define IFCDualITool_SetSize(This,size,toLeft,toRight)	\
    (This)->lpVtbl -> SetSize(This,size,toLeft,toRight)

#define IFCDualITool_GetStatus(This,retval)	\
    (This)->lpVtbl -> GetStatus(This,retval)

#define IFCDualITool_SetStatus(This,bitsRemove,bitsAdd)	\
    (This)->lpVtbl -> SetStatus(This,bitsRemove,bitsAdd)

#define IFCDualITool_ToolCopy(This,pTool,iSize)	\
    (This)->lpVtbl -> ToolCopy(This,pTool,iSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualITool_get_ID_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualITool_get_ID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualITool_put_ID_Proxy( 
    IFCDualITool * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualITool_put_ID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualITool_get_Name_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualITool_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualITool_put_Name_Proxy( 
    IFCDualITool * This,
    /* [in] */ BSTR newValue);


void __RPC_STUB IFCDualITool_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualITool_get_Comment_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IFCDualITool_get_Comment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualITool_put_Comment_Proxy( 
    IFCDualITool * This,
    /* [in] */ BSTR newValue);


void __RPC_STUB IFCDualITool_put_Comment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualITool_get_Special_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualITool_get_Special_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualITool_put_Special_Proxy( 
    IFCDualITool * This,
    /* [in] */ BOOL newValue);


void __RPC_STUB IFCDualITool_put_Special_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualITool_get_Size2_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualITool_get_Size2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualITool_put_Size2_Proxy( 
    IFCDualITool * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualITool_put_Size2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualITool_get_Family_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualITool_get_Family_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualITool_put_Family_Proxy( 
    IFCDualITool * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualITool_put_Family_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualITool_get_Custom1_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualITool_get_Custom1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualITool_put_Custom1_Proxy( 
    IFCDualITool * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualITool_put_Custom1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualITool_get_Custom2_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualITool_get_Custom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualITool_put_Custom2_Proxy( 
    IFCDualITool * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualITool_put_Custom2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualITool_get_Custom3_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualITool_get_Custom3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualITool_put_Custom3_Proxy( 
    IFCDualITool * This,
    /* [in] */ short newValue);


void __RPC_STUB IFCDualITool_put_Custom3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualITool_get_Custom4_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualITool_get_Custom4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualITool_put_Custom4_Proxy( 
    IFCDualITool * This,
    /* [in] */ short newValue);


void __RPC_STUB IFCDualITool_put_Custom4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualITool_get_NumberOfEdges_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualITool_get_NumberOfEdges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualITool_put_NumberOfEdges_Proxy( 
    IFCDualITool * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualITool_put_NumberOfEdges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualITool_GetSize_Proxy( 
    IFCDualITool * This,
    /* [out] */ long *toLeft,
    /* [out] */ long *toRight,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualITool_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualITool_SetSize_Proxy( 
    IFCDualITool * This,
    /* [in] */ long size,
    /* [in] */ long toLeft,
    /* [in] */ long toRight);


void __RPC_STUB IFCDualITool_SetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualITool_GetStatus_Proxy( 
    IFCDualITool * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualITool_GetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualITool_SetStatus_Proxy( 
    IFCDualITool * This,
    /* [in] */ long bitsRemove,
    /* [in] */ long bitsAdd);


void __RPC_STUB IFCDualITool_SetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualITool_ToolCopy_Proxy( 
    IFCDualITool * This,
    /* [out] */ long *pTool,
    /* [in] */ long iSize);


void __RPC_STUB IFCDualITool_ToolCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualITool_INTERFACE_DEFINED__ */


#ifndef __IFCDualIEdge_INTERFACE_DEFINED__
#define __IFCDualIEdge_INTERFACE_DEFINED__

/* interface IFCDualIEdge */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualIEdge,0x6ED87B0D,0xF661,0x4a65,0xB6,0x5C,0xFD,0x63,0xEE,0x12,0x95,0x40);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6ED87B0D-F661-4a65-B65C-FD63EE129540")
    IFCDualIEdge : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ID( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ID( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Length( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LengthWear( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_LengthWear( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Radius( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Radius( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RadiusWear( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RadiusWear( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_NoseRadius( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_NoseRadius( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_NoseRadiusWear( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_NoseRadiusWear( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CuttingLength( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_CuttingLength( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_EntryAngle( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_EntryAngle( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MonitType( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MonitType( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxLife( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxLife( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_WarningLife( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_WarningLife( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RealLife( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RealLife( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_EdgeType( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_EdgeType( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_EdgeSubType( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_EdgeSubType( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddOffset( 
            /* [in] */ BSTR sAxis,
            /* [in] */ long iOffset,
            /* [in] */ long iOffsetWear) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeleteOffset( 
            /* [in] */ BSTR sAxis) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE EdgeCopy( 
            /* [out] */ long *pEdge,
            /* [in] */ long iSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualIEdgeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualIEdge * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualIEdge * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualIEdge * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualIEdge * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualIEdge * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualIEdge * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualIEdge * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ID )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ID )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Length )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LengthWear )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LengthWear )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Radius )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Radius )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RadiusWear )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RadiusWear )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NoseRadius )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NoseRadius )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NoseRadiusWear )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NoseRadiusWear )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CuttingLength )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CuttingLength )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EntryAngle )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EntryAngle )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MonitType )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MonitType )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MaxLife )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MaxLife )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WarningLife )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_WarningLife )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RealLife )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RealLife )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EdgeType )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EdgeType )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EdgeSubType )( 
            IFCDualIEdge * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EdgeSubType )( 
            IFCDualIEdge * This,
            /* [in] */ long newValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddOffset )( 
            IFCDualIEdge * This,
            /* [in] */ BSTR sAxis,
            /* [in] */ long iOffset,
            /* [in] */ long iOffsetWear);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeleteOffset )( 
            IFCDualIEdge * This,
            /* [in] */ BSTR sAxis);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EdgeCopy )( 
            IFCDualIEdge * This,
            /* [out] */ long *pEdge,
            /* [in] */ long iSize);
        
        END_INTERFACE
    } IFCDualIEdgeVtbl;

    interface IFCDualIEdge
    {
        CONST_VTBL struct IFCDualIEdgeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualIEdge_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualIEdge_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualIEdge_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualIEdge_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualIEdge_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualIEdge_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualIEdge_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualIEdge_get_ID(This,retval)	\
    (This)->lpVtbl -> get_ID(This,retval)

#define IFCDualIEdge_put_ID(This,newValue)	\
    (This)->lpVtbl -> put_ID(This,newValue)

#define IFCDualIEdge_get_Length(This,retval)	\
    (This)->lpVtbl -> get_Length(This,retval)

#define IFCDualIEdge_put_Length(This,newValue)	\
    (This)->lpVtbl -> put_Length(This,newValue)

#define IFCDualIEdge_get_LengthWear(This,retval)	\
    (This)->lpVtbl -> get_LengthWear(This,retval)

#define IFCDualIEdge_put_LengthWear(This,newValue)	\
    (This)->lpVtbl -> put_LengthWear(This,newValue)

#define IFCDualIEdge_get_Radius(This,retval)	\
    (This)->lpVtbl -> get_Radius(This,retval)

#define IFCDualIEdge_put_Radius(This,newValue)	\
    (This)->lpVtbl -> put_Radius(This,newValue)

#define IFCDualIEdge_get_RadiusWear(This,retval)	\
    (This)->lpVtbl -> get_RadiusWear(This,retval)

#define IFCDualIEdge_put_RadiusWear(This,newValue)	\
    (This)->lpVtbl -> put_RadiusWear(This,newValue)

#define IFCDualIEdge_get_NoseRadius(This,retval)	\
    (This)->lpVtbl -> get_NoseRadius(This,retval)

#define IFCDualIEdge_put_NoseRadius(This,newValue)	\
    (This)->lpVtbl -> put_NoseRadius(This,newValue)

#define IFCDualIEdge_get_NoseRadiusWear(This,retval)	\
    (This)->lpVtbl -> get_NoseRadiusWear(This,retval)

#define IFCDualIEdge_put_NoseRadiusWear(This,newValue)	\
    (This)->lpVtbl -> put_NoseRadiusWear(This,newValue)

#define IFCDualIEdge_get_CuttingLength(This,retval)	\
    (This)->lpVtbl -> get_CuttingLength(This,retval)

#define IFCDualIEdge_put_CuttingLength(This,newValue)	\
    (This)->lpVtbl -> put_CuttingLength(This,newValue)

#define IFCDualIEdge_get_EntryAngle(This,retval)	\
    (This)->lpVtbl -> get_EntryAngle(This,retval)

#define IFCDualIEdge_put_EntryAngle(This,newValue)	\
    (This)->lpVtbl -> put_EntryAngle(This,newValue)

#define IFCDualIEdge_get_MonitType(This,retval)	\
    (This)->lpVtbl -> get_MonitType(This,retval)

#define IFCDualIEdge_put_MonitType(This,newValue)	\
    (This)->lpVtbl -> put_MonitType(This,newValue)

#define IFCDualIEdge_get_MaxLife(This,retval)	\
    (This)->lpVtbl -> get_MaxLife(This,retval)

#define IFCDualIEdge_put_MaxLife(This,newValue)	\
    (This)->lpVtbl -> put_MaxLife(This,newValue)

#define IFCDualIEdge_get_WarningLife(This,retval)	\
    (This)->lpVtbl -> get_WarningLife(This,retval)

#define IFCDualIEdge_put_WarningLife(This,newValue)	\
    (This)->lpVtbl -> put_WarningLife(This,newValue)

#define IFCDualIEdge_get_RealLife(This,retval)	\
    (This)->lpVtbl -> get_RealLife(This,retval)

#define IFCDualIEdge_put_RealLife(This,newValue)	\
    (This)->lpVtbl -> put_RealLife(This,newValue)

#define IFCDualIEdge_get_EdgeType(This,retval)	\
    (This)->lpVtbl -> get_EdgeType(This,retval)

#define IFCDualIEdge_put_EdgeType(This,newValue)	\
    (This)->lpVtbl -> put_EdgeType(This,newValue)

#define IFCDualIEdge_get_EdgeSubType(This,retval)	\
    (This)->lpVtbl -> get_EdgeSubType(This,retval)

#define IFCDualIEdge_put_EdgeSubType(This,newValue)	\
    (This)->lpVtbl -> put_EdgeSubType(This,newValue)

#define IFCDualIEdge_AddOffset(This,sAxis,iOffset,iOffsetWear)	\
    (This)->lpVtbl -> AddOffset(This,sAxis,iOffset,iOffsetWear)

#define IFCDualIEdge_DeleteOffset(This,sAxis)	\
    (This)->lpVtbl -> DeleteOffset(This,sAxis)

#define IFCDualIEdge_EdgeCopy(This,pEdge,iSize)	\
    (This)->lpVtbl -> EdgeCopy(This,pEdge,iSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_ID_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_ID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_ID_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_ID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_Length_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_Length_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_Length_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_Length_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_LengthWear_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_LengthWear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_LengthWear_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_LengthWear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_Radius_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_Radius_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_Radius_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_Radius_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_RadiusWear_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_RadiusWear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_RadiusWear_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_RadiusWear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_NoseRadius_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_NoseRadius_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_NoseRadius_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_NoseRadius_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_NoseRadiusWear_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_NoseRadiusWear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_NoseRadiusWear_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_NoseRadiusWear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_CuttingLength_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_CuttingLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_CuttingLength_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_CuttingLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_EntryAngle_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_EntryAngle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_EntryAngle_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_EntryAngle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_MonitType_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_MonitType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_MonitType_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_MonitType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_MaxLife_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_MaxLife_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_MaxLife_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_MaxLife_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_WarningLife_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_WarningLife_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_WarningLife_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_WarningLife_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_RealLife_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_RealLife_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_RealLife_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_RealLife_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_EdgeType_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_EdgeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_EdgeType_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_EdgeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_get_EdgeSubType_Proxy( 
    IFCDualIEdge * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIEdge_get_EdgeSubType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_put_EdgeSubType_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ long newValue);


void __RPC_STUB IFCDualIEdge_put_EdgeSubType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_AddOffset_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ BSTR sAxis,
    /* [in] */ long iOffset,
    /* [in] */ long iOffsetWear);


void __RPC_STUB IFCDualIEdge_AddOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_DeleteOffset_Proxy( 
    IFCDualIEdge * This,
    /* [in] */ BSTR sAxis);


void __RPC_STUB IFCDualIEdge_DeleteOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIEdge_EdgeCopy_Proxy( 
    IFCDualIEdge * This,
    /* [out] */ long *pEdge,
    /* [in] */ long iSize);


void __RPC_STUB IFCDualIEdge_EdgeCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualIEdge_INTERFACE_DEFINED__ */


#ifndef __IFCTTable_DISPINTERFACE_DEFINED__
#define __IFCTTable_DISPINTERFACE_DEFINED__

/* dispinterface IFCTTable */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCTTable,0x4A5B4980,0x6284,0x4E84,0x94,0x72,0xE6,0xEB,0x6B,0x77,0x02,0x70);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4A5B4980-6284-4E84-9472-E6EB6B770270")
    IFCTTable : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCTTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCTTable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCTTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCTTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCTTable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCTTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCTTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCTTable * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCTTableVtbl;

    interface IFCTTable
    {
        CONST_VTBL struct IFCTTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCTTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCTTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCTTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCTTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCTTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCTTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCTTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCTTable_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualTTable_INTERFACE_DEFINED__
#define __IFCDualTTable_INTERFACE_DEFINED__

/* interface IFCDualTTable */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualTTable,0x1743B041,0x4816,0x4c56,0xBD,0xC2,0x8B,0xB1,0xCC,0x7C,0x42,0x90);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1743B041-4816-4c56-BDC2-8BB1CC7C4290")
    IFCDualTTable : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenReport( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNofTools( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadTool( 
            /* [in] */ long ID,
            /* [out] */ IFCDualITool **iTool,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteTool( 
            /* [in] */ long ID,
            /* [in] */ IFCDualITool **iTool,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateTool( 
            /* [in] */ long idTool,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CreateTool2( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeleteTool( 
            /* [in] */ long idTool,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsATool( 
            /* [in] */ long idTool,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadAllToolIds( 
            /* [out] */ SAFEARRAY * *pArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddEdge( 
            /* [in] */ long ID,
            /* [in] */ IFCDualIEdge **iEdge,
            /* [in] */ long order,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeleteEdge( 
            /* [in] */ long ID,
            /* [in] */ long order,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadEdge( 
            /* [in] */ long ID,
            /* [in] */ long order,
            /* [out] */ IFCDualIEdge **iEdge,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteEdge( 
            /* [in] */ long ID,
            /* [in] */ long order,
            /* [in] */ IFCDualIEdge **iEdge,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadOffset( 
            /* [in] */ long ID,
            /* [in] */ long order,
            /* [in] */ BSTR sEje,
            /* [out] */ long *offset,
            /* [out] */ long *offsetwear,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteOffset( 
            /* [in] */ long ID,
            /* [in] */ long order,
            /* [in] */ BSTR sEje,
            /* [in] */ long offset,
            /* [in] */ long offsetwear,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CloseReport( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadTool2( 
            /* [in] */ long ID,
            /* [out] */ VARIANT *numMz,
            /* [retval][out] */ IFCDualITool **retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualTTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualTTable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualTTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualTTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualTTable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualTTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualTTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualTTable * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenReport )( 
            IFCDualTTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNofTools )( 
            IFCDualTTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadTool )( 
            IFCDualTTable * This,
            /* [in] */ long ID,
            /* [out] */ IFCDualITool **iTool,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteTool )( 
            IFCDualTTable * This,
            /* [in] */ long ID,
            /* [in] */ IFCDualITool **iTool,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateTool )( 
            IFCDualTTable * This,
            /* [in] */ long idTool,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CreateTool2 )( 
            IFCDualTTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeleteTool )( 
            IFCDualTTable * This,
            /* [in] */ long idTool,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsATool )( 
            IFCDualTTable * This,
            /* [in] */ long idTool,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadAllToolIds )( 
            IFCDualTTable * This,
            /* [out] */ SAFEARRAY * *pArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddEdge )( 
            IFCDualTTable * This,
            /* [in] */ long ID,
            /* [in] */ IFCDualIEdge **iEdge,
            /* [in] */ long order,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeleteEdge )( 
            IFCDualTTable * This,
            /* [in] */ long ID,
            /* [in] */ long order,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadEdge )( 
            IFCDualTTable * This,
            /* [in] */ long ID,
            /* [in] */ long order,
            /* [out] */ IFCDualIEdge **iEdge,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteEdge )( 
            IFCDualTTable * This,
            /* [in] */ long ID,
            /* [in] */ long order,
            /* [in] */ IFCDualIEdge **iEdge,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadOffset )( 
            IFCDualTTable * This,
            /* [in] */ long ID,
            /* [in] */ long order,
            /* [in] */ BSTR sEje,
            /* [out] */ long *offset,
            /* [out] */ long *offsetwear,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteOffset )( 
            IFCDualTTable * This,
            /* [in] */ long ID,
            /* [in] */ long order,
            /* [in] */ BSTR sEje,
            /* [in] */ long offset,
            /* [in] */ long offsetwear,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CloseReport )( 
            IFCDualTTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadTool2 )( 
            IFCDualTTable * This,
            /* [in] */ long ID,
            /* [out] */ VARIANT *numMz,
            /* [retval][out] */ IFCDualITool **retval);
        
        END_INTERFACE
    } IFCDualTTableVtbl;

    interface IFCDualTTable
    {
        CONST_VTBL struct IFCDualTTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualTTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualTTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualTTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualTTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualTTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualTTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualTTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualTTable_OpenReport(This,retval)	\
    (This)->lpVtbl -> OpenReport(This,retval)

#define IFCDualTTable_GetNofTools(This,retval)	\
    (This)->lpVtbl -> GetNofTools(This,retval)

#define IFCDualTTable_ReadTool(This,ID,iTool,retval)	\
    (This)->lpVtbl -> ReadTool(This,ID,iTool,retval)

#define IFCDualTTable_WriteTool(This,ID,iTool,retval)	\
    (This)->lpVtbl -> WriteTool(This,ID,iTool,retval)

#define IFCDualTTable_CreateTool(This,idTool,retval)	\
    (This)->lpVtbl -> CreateTool(This,idTool,retval)

#define IFCDualTTable_CreateTool2(This,retval)	\
    (This)->lpVtbl -> CreateTool2(This,retval)

#define IFCDualTTable_DeleteTool(This,idTool,retval)	\
    (This)->lpVtbl -> DeleteTool(This,idTool,retval)

#define IFCDualTTable_IsATool(This,idTool,retval)	\
    (This)->lpVtbl -> IsATool(This,idTool,retval)

#define IFCDualTTable_ReadAllToolIds(This,pArray,retval)	\
    (This)->lpVtbl -> ReadAllToolIds(This,pArray,retval)

#define IFCDualTTable_AddEdge(This,ID,iEdge,order,retval)	\
    (This)->lpVtbl -> AddEdge(This,ID,iEdge,order,retval)

#define IFCDualTTable_DeleteEdge(This,ID,order,retval)	\
    (This)->lpVtbl -> DeleteEdge(This,ID,order,retval)

#define IFCDualTTable_ReadEdge(This,ID,order,iEdge,retval)	\
    (This)->lpVtbl -> ReadEdge(This,ID,order,iEdge,retval)

#define IFCDualTTable_WriteEdge(This,ID,order,iEdge,retval)	\
    (This)->lpVtbl -> WriteEdge(This,ID,order,iEdge,retval)

#define IFCDualTTable_ReadOffset(This,ID,order,sEje,offset,offsetwear,retval)	\
    (This)->lpVtbl -> ReadOffset(This,ID,order,sEje,offset,offsetwear,retval)

#define IFCDualTTable_WriteOffset(This,ID,order,sEje,offset,offsetwear,retval)	\
    (This)->lpVtbl -> WriteOffset(This,ID,order,sEje,offset,offsetwear,retval)

#define IFCDualTTable_CloseReport(This,retval)	\
    (This)->lpVtbl -> CloseReport(This,retval)

#define IFCDualTTable_ReadTool2(This,ID,numMz,retval)	\
    (This)->lpVtbl -> ReadTool2(This,ID,numMz,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_OpenReport_Proxy( 
    IFCDualTTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTTable_OpenReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_GetNofTools_Proxy( 
    IFCDualTTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTTable_GetNofTools_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_ReadTool_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long ID,
    /* [out] */ IFCDualITool **iTool,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTTable_ReadTool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_WriteTool_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long ID,
    /* [in] */ IFCDualITool **iTool,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTTable_WriteTool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_CreateTool_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long idTool,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTTable_CreateTool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_CreateTool2_Proxy( 
    IFCDualTTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTTable_CreateTool2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_DeleteTool_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long idTool,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTTable_DeleteTool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_IsATool_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long idTool,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTTable_IsATool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_ReadAllToolIds_Proxy( 
    IFCDualTTable * This,
    /* [out] */ SAFEARRAY * *pArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTTable_ReadAllToolIds_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_AddEdge_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long ID,
    /* [in] */ IFCDualIEdge **iEdge,
    /* [in] */ long order,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTTable_AddEdge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_DeleteEdge_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long ID,
    /* [in] */ long order,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTTable_DeleteEdge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_ReadEdge_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long ID,
    /* [in] */ long order,
    /* [out] */ IFCDualIEdge **iEdge,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTTable_ReadEdge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_WriteEdge_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long ID,
    /* [in] */ long order,
    /* [in] */ IFCDualIEdge **iEdge,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTTable_WriteEdge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_ReadOffset_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long ID,
    /* [in] */ long order,
    /* [in] */ BSTR sEje,
    /* [out] */ long *offset,
    /* [out] */ long *offsetwear,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTTable_ReadOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_WriteOffset_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long ID,
    /* [in] */ long order,
    /* [in] */ BSTR sEje,
    /* [in] */ long offset,
    /* [in] */ long offsetwear,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTTable_WriteOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_CloseReport_Proxy( 
    IFCDualTTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTTable_CloseReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTTable_ReadTool2_Proxy( 
    IFCDualTTable * This,
    /* [in] */ long ID,
    /* [out] */ VARIANT *numMz,
    /* [retval][out] */ IFCDualITool **retval);


void __RPC_STUB IFCDualTTable_ReadTool2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualTTable_INTERFACE_DEFINED__ */


#ifndef __IToolReport_DISPINTERFACE_DEFINED__
#define __IToolReport_DISPINTERFACE_DEFINED__

/* dispinterface IToolReport */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_IToolReport,0xFABD7B2B,0x7191,0x459e,0x80,0xEC,0xC4,0x79,0xE3,0xDC,0x54,0x3C);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FABD7B2B-7191-459e-80EC-C479E3DC543C")
    IToolReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IToolReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IToolReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IToolReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IToolReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IToolReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IToolReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IToolReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IToolReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IToolReportVtbl;

    interface IToolReport
    {
        CONST_VTBL struct IToolReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IToolReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IToolReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IToolReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IToolReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IToolReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IToolReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IToolReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IToolReport_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_TTable,0x02AC8B91,0x3D03,0x46F6,0x8C,0x01,0x7C,0xA5,0x6D,0x79,0x3D,0xEA);

#ifdef __cplusplus

class DECLSPEC_UUID("02AC8B91-3D03-46F6-8C01-7CA56D793DEA")
CNC8070_TTable;
#endif

#ifndef __IFCITool_DISPINTERFACE_DEFINED__
#define __IFCITool_DISPINTERFACE_DEFINED__

/* dispinterface IFCITool */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCITool,0x28606FFB,0xC9E2,0x4C34,0x82,0x97,0x70,0x7D,0x1F,0x1A,0xB0,0xF8);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("28606FFB-C9E2-4C34-8297-707D1F1AB0F8")
    IFCITool : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCIToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCITool * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCITool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCITool * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCITool * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCITool * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCITool * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCITool * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCIToolVtbl;

    interface IFCITool
    {
        CONST_VTBL struct IFCIToolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCITool_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCITool_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCITool_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCITool_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCITool_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCITool_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCITool_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCITool_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_Tool,0x620D6E62,0x0084,0x4DDB,0xA0,0x2A,0x1E,0x64,0xEB,0xDB,0xAE,0xDD);

#ifdef __cplusplus

class DECLSPEC_UUID("620D6E62-0084-4DDB-A02A-1E64EBDBAEDD")
CNC8070_Tool;
#endif

#ifndef __IFCIEdge_DISPINTERFACE_DEFINED__
#define __IFCIEdge_DISPINTERFACE_DEFINED__

/* dispinterface IFCIEdge */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCIEdge,0x73C5F20D,0x4B7E,0x4FA1,0xB5,0x1B,0x30,0x5A,0x06,0xBB,0x3D,0x74);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("73C5F20D-4B7E-4FA1-B51B-305A06BB3D74")
    IFCIEdge : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCIEdgeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCIEdge * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCIEdge * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCIEdge * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCIEdge * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCIEdge * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCIEdge * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCIEdge * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCIEdgeVtbl;

    interface IFCIEdge
    {
        CONST_VTBL struct IFCIEdgeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCIEdge_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCIEdge_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCIEdge_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCIEdge_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCIEdge_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCIEdge_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCIEdge_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCIEdge_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_Edge,0xFE8A7A95,0xF8F8,0x460C,0xA3,0x15,0x60,0x61,0xA6,0x49,0x38,0x9B);

#ifdef __cplusplus

class DECLSPEC_UUID("FE8A7A95-F8F8-460C-A315-6061A649389B")
CNC8070_Edge;
#endif

#ifndef __IFCDualIPlaceStorage_INTERFACE_DEFINED__
#define __IFCDualIPlaceStorage_INTERFACE_DEFINED__

/* interface IFCDualIPlaceStorage */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualIPlaceStorage,0x272423BD,0x5DCB,0x4507,0x8D,0xBD,0xD3,0x45,0x32,0xA6,0x6D,0x84);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("272423BD-5DCB-4507-8DBD-D34532A66D84")
    IFCDualIPlaceStorage : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsFree( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsFreeLeft( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsFreeRight( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsLoaded( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsLoadedLeft( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsLoadedRight( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Enable( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Disable( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ long toolID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnLoad( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetRight( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE LoadRight( 
            /* [in] */ long toolID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnLoadRight( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLeft( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE LoadLeft( 
            /* [in] */ long toolID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnLoadLeft( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetToolID( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetToolID2( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [retval][out] */ long *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualIPlaceStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualIPlaceStorage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualIPlaceStorage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualIPlaceStorage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualIPlaceStorage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualIPlaceStorage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualIPlaceStorage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualIPlaceStorage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsFree )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsFreeLeft )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsFreeRight )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsLoaded )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsLoadedLeft )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsLoadedRight )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Enable )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Disable )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            IFCDualIPlaceStorage * This,
            /* [in] */ long toolID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnLoad )( 
            IFCDualIPlaceStorage * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetRight )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *LoadRight )( 
            IFCDualIPlaceStorage * This,
            /* [in] */ long toolID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnLoadRight )( 
            IFCDualIPlaceStorage * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLeft )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *LoadLeft )( 
            IFCDualIPlaceStorage * This,
            /* [in] */ long toolID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnLoadLeft )( 
            IFCDualIPlaceStorage * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetToolID )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetToolID2 )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            IFCDualIPlaceStorage * This,
            /* [retval][out] */ long *retval);
        
        END_INTERFACE
    } IFCDualIPlaceStorageVtbl;

    interface IFCDualIPlaceStorage
    {
        CONST_VTBL struct IFCDualIPlaceStorageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualIPlaceStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualIPlaceStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualIPlaceStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualIPlaceStorage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualIPlaceStorage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualIPlaceStorage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualIPlaceStorage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualIPlaceStorage_IsFree(This,retval)	\
    (This)->lpVtbl -> IsFree(This,retval)

#define IFCDualIPlaceStorage_IsFreeLeft(This,retval)	\
    (This)->lpVtbl -> IsFreeLeft(This,retval)

#define IFCDualIPlaceStorage_IsFreeRight(This,retval)	\
    (This)->lpVtbl -> IsFreeRight(This,retval)

#define IFCDualIPlaceStorage_IsLoaded(This,retval)	\
    (This)->lpVtbl -> IsLoaded(This,retval)

#define IFCDualIPlaceStorage_IsLoadedLeft(This,retval)	\
    (This)->lpVtbl -> IsLoadedLeft(This,retval)

#define IFCDualIPlaceStorage_IsLoadedRight(This,retval)	\
    (This)->lpVtbl -> IsLoadedRight(This,retval)

#define IFCDualIPlaceStorage_Enable(This,retval)	\
    (This)->lpVtbl -> Enable(This,retval)

#define IFCDualIPlaceStorage_Disable(This,retval)	\
    (This)->lpVtbl -> Disable(This,retval)

#define IFCDualIPlaceStorage_Load(This,toolID)	\
    (This)->lpVtbl -> Load(This,toolID)

#define IFCDualIPlaceStorage_UnLoad(This)	\
    (This)->lpVtbl -> UnLoad(This)

#define IFCDualIPlaceStorage_GetRight(This,retval)	\
    (This)->lpVtbl -> GetRight(This,retval)

#define IFCDualIPlaceStorage_LoadRight(This,toolID)	\
    (This)->lpVtbl -> LoadRight(This,toolID)

#define IFCDualIPlaceStorage_UnLoadRight(This)	\
    (This)->lpVtbl -> UnLoadRight(This)

#define IFCDualIPlaceStorage_GetLeft(This,retval)	\
    (This)->lpVtbl -> GetLeft(This,retval)

#define IFCDualIPlaceStorage_LoadLeft(This,toolID)	\
    (This)->lpVtbl -> LoadLeft(This,toolID)

#define IFCDualIPlaceStorage_UnLoadLeft(This)	\
    (This)->lpVtbl -> UnLoadLeft(This)

#define IFCDualIPlaceStorage_GetToolID(This,retval)	\
    (This)->lpVtbl -> GetToolID(This,retval)

#define IFCDualIPlaceStorage_GetToolID2(This,retval)	\
    (This)->lpVtbl -> GetToolID2(This,retval)

#define IFCDualIPlaceStorage_GetStatus(This,retval)	\
    (This)->lpVtbl -> GetStatus(This,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_IsFree_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualIPlaceStorage_IsFree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_IsFreeLeft_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualIPlaceStorage_IsFreeLeft_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_IsFreeRight_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualIPlaceStorage_IsFreeRight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_IsLoaded_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualIPlaceStorage_IsLoaded_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_IsLoadedLeft_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualIPlaceStorage_IsLoadedLeft_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_IsLoadedRight_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualIPlaceStorage_IsLoadedRight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_Enable_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualIPlaceStorage_Enable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_Disable_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualIPlaceStorage_Disable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_Load_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [in] */ long toolID);


void __RPC_STUB IFCDualIPlaceStorage_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_UnLoad_Proxy( 
    IFCDualIPlaceStorage * This);


void __RPC_STUB IFCDualIPlaceStorage_UnLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_GetRight_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIPlaceStorage_GetRight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_LoadRight_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [in] */ long toolID);


void __RPC_STUB IFCDualIPlaceStorage_LoadRight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_UnLoadRight_Proxy( 
    IFCDualIPlaceStorage * This);


void __RPC_STUB IFCDualIPlaceStorage_UnLoadRight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_GetLeft_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIPlaceStorage_GetLeft_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_LoadLeft_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [in] */ long toolID);


void __RPC_STUB IFCDualIPlaceStorage_LoadLeft_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_UnLoadLeft_Proxy( 
    IFCDualIPlaceStorage * This);


void __RPC_STUB IFCDualIPlaceStorage_UnLoadLeft_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_GetToolID_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIPlaceStorage_GetToolID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_GetToolID2_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIPlaceStorage_GetToolID2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualIPlaceStorage_GetStatus_Proxy( 
    IFCDualIPlaceStorage * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualIPlaceStorage_GetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualIPlaceStorage_INTERFACE_DEFINED__ */


#ifndef __IDualIMzInfor_INTERFACE_DEFINED__
#define __IDualIMzInfor_INTERFACE_DEFINED__

/* interface IDualIMzInfor */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IDualIMzInfor,0xCF2D0EEF,0xF361,0x45c5,0xB8,0xA5,0x91,0x12,0xB8,0x52,0x02,0x37);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF2D0EEF-F361-45c5-B8A5-9112B8520237")
    IDualIMzInfor : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_numpos( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_numpos( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_rows( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_rows( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_cols( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_cols( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_excessM6( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_excessM6( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_geomtype( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_geomtype( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_mztype( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_mztype( 
            /* [in] */ long newValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsRandom( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsCyclic( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsPosGround( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsRandomSizes( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsOptimized( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsAuto( 
            /* [retval][out] */ BOOL *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDualIMzInforVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDualIMzInfor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDualIMzInfor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDualIMzInfor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDualIMzInfor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDualIMzInfor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDualIMzInfor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDualIMzInfor * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_numpos )( 
            IDualIMzInfor * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_numpos )( 
            IDualIMzInfor * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_rows )( 
            IDualIMzInfor * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_rows )( 
            IDualIMzInfor * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_cols )( 
            IDualIMzInfor * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_cols )( 
            IDualIMzInfor * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_excessM6 )( 
            IDualIMzInfor * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_excessM6 )( 
            IDualIMzInfor * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_geomtype )( 
            IDualIMzInfor * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_geomtype )( 
            IDualIMzInfor * This,
            /* [in] */ long newValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_mztype )( 
            IDualIMzInfor * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_mztype )( 
            IDualIMzInfor * This,
            /* [in] */ long newValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsRandom )( 
            IDualIMzInfor * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsCyclic )( 
            IDualIMzInfor * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsPosGround )( 
            IDualIMzInfor * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsRandomSizes )( 
            IDualIMzInfor * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsOptimized )( 
            IDualIMzInfor * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsAuto )( 
            IDualIMzInfor * This,
            /* [retval][out] */ BOOL *retval);
        
        END_INTERFACE
    } IDualIMzInforVtbl;

    interface IDualIMzInfor
    {
        CONST_VTBL struct IDualIMzInforVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDualIMzInfor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDualIMzInfor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDualIMzInfor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDualIMzInfor_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDualIMzInfor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDualIMzInfor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDualIMzInfor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDualIMzInfor_get_numpos(This,retval)	\
    (This)->lpVtbl -> get_numpos(This,retval)

#define IDualIMzInfor_put_numpos(This,newValue)	\
    (This)->lpVtbl -> put_numpos(This,newValue)

#define IDualIMzInfor_get_rows(This,retval)	\
    (This)->lpVtbl -> get_rows(This,retval)

#define IDualIMzInfor_put_rows(This,newValue)	\
    (This)->lpVtbl -> put_rows(This,newValue)

#define IDualIMzInfor_get_cols(This,retval)	\
    (This)->lpVtbl -> get_cols(This,retval)

#define IDualIMzInfor_put_cols(This,newValue)	\
    (This)->lpVtbl -> put_cols(This,newValue)

#define IDualIMzInfor_get_excessM6(This,retval)	\
    (This)->lpVtbl -> get_excessM6(This,retval)

#define IDualIMzInfor_put_excessM6(This,newValue)	\
    (This)->lpVtbl -> put_excessM6(This,newValue)

#define IDualIMzInfor_get_geomtype(This,retval)	\
    (This)->lpVtbl -> get_geomtype(This,retval)

#define IDualIMzInfor_put_geomtype(This,newValue)	\
    (This)->lpVtbl -> put_geomtype(This,newValue)

#define IDualIMzInfor_get_mztype(This,retval)	\
    (This)->lpVtbl -> get_mztype(This,retval)

#define IDualIMzInfor_put_mztype(This,newValue)	\
    (This)->lpVtbl -> put_mztype(This,newValue)

#define IDualIMzInfor_IsRandom(This,retval)	\
    (This)->lpVtbl -> IsRandom(This,retval)

#define IDualIMzInfor_IsCyclic(This,retval)	\
    (This)->lpVtbl -> IsCyclic(This,retval)

#define IDualIMzInfor_IsPosGround(This,retval)	\
    (This)->lpVtbl -> IsPosGround(This,retval)

#define IDualIMzInfor_IsRandomSizes(This,retval)	\
    (This)->lpVtbl -> IsRandomSizes(This,retval)

#define IDualIMzInfor_IsOptimized(This,retval)	\
    (This)->lpVtbl -> IsOptimized(This,retval)

#define IDualIMzInfor_IsAuto(This,retval)	\
    (This)->lpVtbl -> IsAuto(This,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_get_numpos_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualIMzInfor_get_numpos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_put_numpos_Proxy( 
    IDualIMzInfor * This,
    /* [in] */ long newValue);


void __RPC_STUB IDualIMzInfor_put_numpos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_get_rows_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualIMzInfor_get_rows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_put_rows_Proxy( 
    IDualIMzInfor * This,
    /* [in] */ long newValue);


void __RPC_STUB IDualIMzInfor_put_rows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_get_cols_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualIMzInfor_get_cols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_put_cols_Proxy( 
    IDualIMzInfor * This,
    /* [in] */ long newValue);


void __RPC_STUB IDualIMzInfor_put_cols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_get_excessM6_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualIMzInfor_get_excessM6_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_put_excessM6_Proxy( 
    IDualIMzInfor * This,
    /* [in] */ long newValue);


void __RPC_STUB IDualIMzInfor_put_excessM6_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_get_geomtype_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualIMzInfor_get_geomtype_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_put_geomtype_Proxy( 
    IDualIMzInfor * This,
    /* [in] */ long newValue);


void __RPC_STUB IDualIMzInfor_put_geomtype_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_get_mztype_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualIMzInfor_get_mztype_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_put_mztype_Proxy( 
    IDualIMzInfor * This,
    /* [in] */ long newValue);


void __RPC_STUB IDualIMzInfor_put_mztype_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_IsRandom_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualIMzInfor_IsRandom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_IsCyclic_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualIMzInfor_IsCyclic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_IsPosGround_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualIMzInfor_IsPosGround_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_IsRandomSizes_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualIMzInfor_IsRandomSizes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_IsOptimized_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualIMzInfor_IsOptimized_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualIMzInfor_IsAuto_Proxy( 
    IDualIMzInfor * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualIMzInfor_IsAuto_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDualIMzInfor_INTERFACE_DEFINED__ */


#ifndef __IFCTMagazine_DISPINTERFACE_DEFINED__
#define __IFCTMagazine_DISPINTERFACE_DEFINED__

/* dispinterface IFCTMagazine */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCTMagazine,0xD64D2871,0xCB85,0x402A,0x88,0xDC,0xAE,0xEB,0x09,0xAF,0xAD,0x07);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D64D2871-CB85-402A-88DC-AEEB09AFAD07")
    IFCTMagazine : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCTMagazineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCTMagazine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCTMagazine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCTMagazine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCTMagazine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCTMagazine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCTMagazine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCTMagazine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCTMagazineVtbl;

    interface IFCTMagazine
    {
        CONST_VTBL struct IFCTMagazineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCTMagazine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCTMagazine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCTMagazine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCTMagazine_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCTMagazine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCTMagazine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCTMagazine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCTMagazine_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualTMagazine_INTERFACE_DEFINED__
#define __IFCDualTMagazine_INTERFACE_DEFINED__

/* interface IFCDualTMagazine */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualTMagazine,0x43292011,0x6B4F,0x4b23,0xBA,0xDE,0xE8,0xE3,0xB7,0xFF,0xA9,0xA0);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43292011-6B4F-4b23-BADE-E8E3B7FFA9A0")
    IFCDualTMagazine : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OpenReport( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetToolInfo( 
            /* [in] */ long numAlmacen,
            /* [in] */ long toolID,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualLoad( 
            /* [in] */ long numAlmacen,
            /* [in] */ long toolID,
            /* [in] */ long pos,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualUnload( 
            /* [in] */ long numAlmacen,
            /* [in] */ long toolID,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsBusy( 
            /* [in] */ long nChannel,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AutoTest( 
            /* [in] */ long nChannel,
            /* [in] */ BSTR testfile,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SaveState( 
            /* [in] */ BSTR savefile,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RestoreState( 
            /* [in] */ BSTR statefile,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetPlaceInfo( 
            /* [in] */ long numAlmacen,
            /* [in] */ long pos,
            /* [out] */ IFCDualIPlaceStorage **posAlmacen,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ToolPlaces( 
            /* [in] */ long numAlmacen,
            /* [in] */ long toolID,
            /* [out] */ long *toLeft,
            /* [out] */ long *toRight,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Enable( 
            /* [in] */ long numAlmacen,
            /* [in] */ long pos,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Disable( 
            /* [in] */ long numAlmacen,
            /* [in] */ long pos,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNumberOfTools( 
            /* [in] */ long numAlmacen,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNumberOfPlaces( 
            /* [in] */ long numAlmacen,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CheckPosition( 
            /* [in] */ long numAlmacen,
            /* [in] */ long pos,
            /* [in] */ long toLeft,
            /* [in] */ long toRight,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitializePlace( 
            /* [in] */ long numAlmacen,
            /* [in] */ long toolID,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetPositionToolInSpindle( 
            /* [in] */ long nChannel,
            /* [out] */ long *numAlmacen,
            /* [out] */ long *pos,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetMode( 
            /* [in] */ long nChannel,
            /* [in] */ long newMode,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetMzInformation( 
            /* [out] */ IDualIMzInfor **mzinfor,
            /* [in] */ long numAlmacen) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CloseReport( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DeleteToolSim( 
            /* [in] */ long ID,
            /* [retval][out] */ BOOL *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualTMagazineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualTMagazine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualTMagazine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualTMagazine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualTMagazine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualTMagazine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualTMagazine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualTMagazine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OpenReport )( 
            IFCDualTMagazine * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetToolInfo )( 
            IFCDualTMagazine * This,
            /* [in] */ long numAlmacen,
            /* [in] */ long toolID,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ManualLoad )( 
            IFCDualTMagazine * This,
            /* [in] */ long numAlmacen,
            /* [in] */ long toolID,
            /* [in] */ long pos,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ManualUnload )( 
            IFCDualTMagazine * This,
            /* [in] */ long numAlmacen,
            /* [in] */ long toolID,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *IsBusy )( 
            IFCDualTMagazine * This,
            /* [in] */ long nChannel,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AutoTest )( 
            IFCDualTMagazine * This,
            /* [in] */ long nChannel,
            /* [in] */ BSTR testfile,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SaveState )( 
            IFCDualTMagazine * This,
            /* [in] */ BSTR savefile,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RestoreState )( 
            IFCDualTMagazine * This,
            /* [in] */ BSTR statefile,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetPlaceInfo )( 
            IFCDualTMagazine * This,
            /* [in] */ long numAlmacen,
            /* [in] */ long pos,
            /* [out] */ IFCDualIPlaceStorage **posAlmacen,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ToolPlaces )( 
            IFCDualTMagazine * This,
            /* [in] */ long numAlmacen,
            /* [in] */ long toolID,
            /* [out] */ long *toLeft,
            /* [out] */ long *toRight,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Enable )( 
            IFCDualTMagazine * This,
            /* [in] */ long numAlmacen,
            /* [in] */ long pos,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Disable )( 
            IFCDualTMagazine * This,
            /* [in] */ long numAlmacen,
            /* [in] */ long pos,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNumberOfTools )( 
            IFCDualTMagazine * This,
            /* [in] */ long numAlmacen,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNumberOfPlaces )( 
            IFCDualTMagazine * This,
            /* [in] */ long numAlmacen,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CheckPosition )( 
            IFCDualTMagazine * This,
            /* [in] */ long numAlmacen,
            /* [in] */ long pos,
            /* [in] */ long toLeft,
            /* [in] */ long toRight,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitializePlace )( 
            IFCDualTMagazine * This,
            /* [in] */ long numAlmacen,
            /* [in] */ long toolID,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetPositionToolInSpindle )( 
            IFCDualTMagazine * This,
            /* [in] */ long nChannel,
            /* [out] */ long *numAlmacen,
            /* [out] */ long *pos,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetMode )( 
            IFCDualTMagazine * This,
            /* [in] */ long nChannel,
            /* [in] */ long newMode,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetMzInformation )( 
            IFCDualTMagazine * This,
            /* [out] */ IDualIMzInfor **mzinfor,
            /* [in] */ long numAlmacen);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CloseReport )( 
            IFCDualTMagazine * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DeleteToolSim )( 
            IFCDualTMagazine * This,
            /* [in] */ long ID,
            /* [retval][out] */ BOOL *retval);
        
        END_INTERFACE
    } IFCDualTMagazineVtbl;

    interface IFCDualTMagazine
    {
        CONST_VTBL struct IFCDualTMagazineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualTMagazine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualTMagazine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualTMagazine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualTMagazine_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualTMagazine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualTMagazine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualTMagazine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualTMagazine_OpenReport(This,retval)	\
    (This)->lpVtbl -> OpenReport(This,retval)

#define IFCDualTMagazine_GetToolInfo(This,numAlmacen,toolID,retval)	\
    (This)->lpVtbl -> GetToolInfo(This,numAlmacen,toolID,retval)

#define IFCDualTMagazine_ManualLoad(This,numAlmacen,toolID,pos,retval)	\
    (This)->lpVtbl -> ManualLoad(This,numAlmacen,toolID,pos,retval)

#define IFCDualTMagazine_ManualUnload(This,numAlmacen,toolID,retval)	\
    (This)->lpVtbl -> ManualUnload(This,numAlmacen,toolID,retval)

#define IFCDualTMagazine_IsBusy(This,nChannel,retval)	\
    (This)->lpVtbl -> IsBusy(This,nChannel,retval)

#define IFCDualTMagazine_AutoTest(This,nChannel,testfile,retval)	\
    (This)->lpVtbl -> AutoTest(This,nChannel,testfile,retval)

#define IFCDualTMagazine_SaveState(This,savefile,retval)	\
    (This)->lpVtbl -> SaveState(This,savefile,retval)

#define IFCDualTMagazine_RestoreState(This,statefile,retval)	\
    (This)->lpVtbl -> RestoreState(This,statefile,retval)

#define IFCDualTMagazine_GetPlaceInfo(This,numAlmacen,pos,posAlmacen,retval)	\
    (This)->lpVtbl -> GetPlaceInfo(This,numAlmacen,pos,posAlmacen,retval)

#define IFCDualTMagazine_ToolPlaces(This,numAlmacen,toolID,toLeft,toRight,retval)	\
    (This)->lpVtbl -> ToolPlaces(This,numAlmacen,toolID,toLeft,toRight,retval)

#define IFCDualTMagazine_Enable(This,numAlmacen,pos,retval)	\
    (This)->lpVtbl -> Enable(This,numAlmacen,pos,retval)

#define IFCDualTMagazine_Disable(This,numAlmacen,pos,retval)	\
    (This)->lpVtbl -> Disable(This,numAlmacen,pos,retval)

#define IFCDualTMagazine_GetNumberOfTools(This,numAlmacen,retval)	\
    (This)->lpVtbl -> GetNumberOfTools(This,numAlmacen,retval)

#define IFCDualTMagazine_GetNumberOfPlaces(This,numAlmacen,retval)	\
    (This)->lpVtbl -> GetNumberOfPlaces(This,numAlmacen,retval)

#define IFCDualTMagazine_CheckPosition(This,numAlmacen,pos,toLeft,toRight,retval)	\
    (This)->lpVtbl -> CheckPosition(This,numAlmacen,pos,toLeft,toRight,retval)

#define IFCDualTMagazine_InitializePlace(This,numAlmacen,toolID,retval)	\
    (This)->lpVtbl -> InitializePlace(This,numAlmacen,toolID,retval)

#define IFCDualTMagazine_GetPositionToolInSpindle(This,nChannel,numAlmacen,pos,retval)	\
    (This)->lpVtbl -> GetPositionToolInSpindle(This,nChannel,numAlmacen,pos,retval)

#define IFCDualTMagazine_SetMode(This,nChannel,newMode,retval)	\
    (This)->lpVtbl -> SetMode(This,nChannel,newMode,retval)

#define IFCDualTMagazine_GetMzInformation(This,mzinfor,numAlmacen)	\
    (This)->lpVtbl -> GetMzInformation(This,mzinfor,numAlmacen)

#define IFCDualTMagazine_CloseReport(This,retval)	\
    (This)->lpVtbl -> CloseReport(This,retval)

#define IFCDualTMagazine_DeleteToolSim(This,ID,retval)	\
    (This)->lpVtbl -> DeleteToolSim(This,ID,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_OpenReport_Proxy( 
    IFCDualTMagazine * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTMagazine_OpenReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_GetToolInfo_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long numAlmacen,
    /* [in] */ long toolID,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTMagazine_GetToolInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_ManualLoad_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long numAlmacen,
    /* [in] */ long toolID,
    /* [in] */ long pos,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTMagazine_ManualLoad_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_ManualUnload_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long numAlmacen,
    /* [in] */ long toolID,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTMagazine_ManualUnload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_IsBusy_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long nChannel,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTMagazine_IsBusy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_AutoTest_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long nChannel,
    /* [in] */ BSTR testfile,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTMagazine_AutoTest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_SaveState_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ BSTR savefile,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTMagazine_SaveState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_RestoreState_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ BSTR statefile,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTMagazine_RestoreState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_GetPlaceInfo_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long numAlmacen,
    /* [in] */ long pos,
    /* [out] */ IFCDualIPlaceStorage **posAlmacen,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTMagazine_GetPlaceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_ToolPlaces_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long numAlmacen,
    /* [in] */ long toolID,
    /* [out] */ long *toLeft,
    /* [out] */ long *toRight,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTMagazine_ToolPlaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_Enable_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long numAlmacen,
    /* [in] */ long pos,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTMagazine_Enable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_Disable_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long numAlmacen,
    /* [in] */ long pos,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTMagazine_Disable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_GetNumberOfTools_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long numAlmacen,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTMagazine_GetNumberOfTools_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_GetNumberOfPlaces_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long numAlmacen,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTMagazine_GetNumberOfPlaces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_CheckPosition_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long numAlmacen,
    /* [in] */ long pos,
    /* [in] */ long toLeft,
    /* [in] */ long toRight,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTMagazine_CheckPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_InitializePlace_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long numAlmacen,
    /* [in] */ long toolID,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTMagazine_InitializePlace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_GetPositionToolInSpindle_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long nChannel,
    /* [out] */ long *numAlmacen,
    /* [out] */ long *pos,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTMagazine_GetPositionToolInSpindle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_SetMode_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long nChannel,
    /* [in] */ long newMode,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTMagazine_SetMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_GetMzInformation_Proxy( 
    IFCDualTMagazine * This,
    /* [out] */ IDualIMzInfor **mzinfor,
    /* [in] */ long numAlmacen);


void __RPC_STUB IFCDualTMagazine_GetMzInformation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_CloseReport_Proxy( 
    IFCDualTMagazine * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualTMagazine_CloseReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualTMagazine_DeleteToolSim_Proxy( 
    IFCDualTMagazine * This,
    /* [in] */ long ID,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualTMagazine_DeleteToolSim_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualTMagazine_INTERFACE_DEFINED__ */


#ifndef __IMagazineReport_DISPINTERFACE_DEFINED__
#define __IMagazineReport_DISPINTERFACE_DEFINED__

/* dispinterface IMagazineReport */
/* [hidden][helpstring][uuid] */ 


DEFINE_GUID(DIID_IMagazineReport,0x99D889C9,0xD9E4,0x491b,0x95,0x5E,0x32,0x0A,0x92,0x57,0xDF,0xD0);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("99D889C9-D9E4-491b-955E-320A9257DFD0")
    IMagazineReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMagazineReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMagazineReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMagazineReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMagazineReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMagazineReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMagazineReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMagazineReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMagazineReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IMagazineReportVtbl;

    interface IMagazineReport
    {
        CONST_VTBL struct IMagazineReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMagazineReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMagazineReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMagazineReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMagazineReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMagazineReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMagazineReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMagazineReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMagazineReport_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_MagazineTable,0xEEBE94F7,0x7940,0x49BF,0x80,0x90,0x0F,0xB9,0xF2,0x0A,0x12,0x45);

#ifdef __cplusplus

class DECLSPEC_UUID("EEBE94F7-7940-49BF-8090-0FB9F20A1245")
CNC8070_MagazineTable;
#endif

#ifndef __IFCIPlaceStorage_DISPINTERFACE_DEFINED__
#define __IFCIPlaceStorage_DISPINTERFACE_DEFINED__

/* dispinterface IFCIPlaceStorage */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCIPlaceStorage,0xB3CD56F3,0xF73B,0x444F,0x98,0xAC,0x06,0xBE,0xE8,0x30,0x97,0x34);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B3CD56F3-F73B-444F-98AC-06BEE8309734")
    IFCIPlaceStorage : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCIPlaceStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCIPlaceStorage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCIPlaceStorage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCIPlaceStorage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCIPlaceStorage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCIPlaceStorage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCIPlaceStorage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCIPlaceStorage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCIPlaceStorageVtbl;

    interface IFCIPlaceStorage
    {
        CONST_VTBL struct IFCIPlaceStorageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCIPlaceStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCIPlaceStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCIPlaceStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCIPlaceStorage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCIPlaceStorage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCIPlaceStorage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCIPlaceStorage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCIPlaceStorage_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_PlaceStorage,0x1CB2B178,0xCBA6,0x489F,0x81,0xAC,0xA6,0x11,0xBB,0x78,0x5B,0x05);

#ifdef __cplusplus

class DECLSPEC_UUID("1CB2B178-CBA6-489F-81AC-A611BB785B05")
CNC8070_PlaceStorage;
#endif

#ifndef __IMzInfor_DISPINTERFACE_DEFINED__
#define __IMzInfor_DISPINTERFACE_DEFINED__

/* dispinterface IMzInfor */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IMzInfor,0x85BDDAAE,0x1149,0x4789,0xA7,0x3B,0x9D,0x49,0xEA,0x16,0xA2,0x7C);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("85BDDAAE-1149-4789-A73B-9D49EA16A27C")
    IMzInfor : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IMzInforVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMzInfor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMzInfor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMzInfor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMzInfor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMzInfor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMzInfor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMzInfor * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IMzInforVtbl;

    interface IMzInfor
    {
        CONST_VTBL struct IMzInforVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMzInfor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMzInfor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMzInfor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMzInfor_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IMzInfor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IMzInfor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IMzInfor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IMzInfor_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_MzInfor,0x4D44D755,0x89FC,0x4978,0x80,0x86,0x99,0xBE,0xC4,0x27,0x59,0xBD);

#ifdef __cplusplus

class DECLSPEC_UUID("4D44D755-89FC-4978-8086-99BEC42759BD")
CNC8070_MzInfor;
#endif

#ifndef __IFCApiTables_DISPINTERFACE_DEFINED__
#define __IFCApiTables_DISPINTERFACE_DEFINED__

/* dispinterface IFCApiTables */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCApiTables,0x4F1A922D,0x0721,0x4F6B,0xB9,0xF7,0x87,0x69,0xF7,0xFC,0xC3,0x21);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4F1A922D-0721-4F6B-B9F7-8769F7FCC321")
    IFCApiTables : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCApiTablesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCApiTables * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCApiTables * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCApiTables * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCApiTables * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCApiTables * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCApiTables * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCApiTables * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCApiTablesVtbl;

    interface IFCApiTables
    {
        CONST_VTBL struct IFCApiTablesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCApiTables_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCApiTables_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCApiTables_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCApiTables_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCApiTables_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCApiTables_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCApiTables_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCApiTables_DISPINTERFACE_DEFINED__ */


#ifndef __IDualApiTables_INTERFACE_DEFINED__
#define __IDualApiTables_INTERFACE_DEFINED__

/* interface IDualApiTables */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IDualApiTables,0x67F89564,0x5D7B,0x42bd,0xB5,0xB1,0x37,0x33,0xFF,0xAB,0x36,0xAD);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("67F89564-5D7B-42bd-B5B1-3733FFAB36AD")
    IDualApiTables : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFixtureTable( 
            /* [retval][out] */ IFCDualApiFixtureTable **iFixtureTable) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetOriginTable( 
            /* [retval][out] */ IFCDualApiOriginTable **iOriginTable) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetPParamTable( 
            /* [retval][out] */ IFCDualApiPParamTable **iPParamTable) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReleaseAllTables( 
            /* [retval][out] */ BOOL *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDualApiTablesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDualApiTables * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDualApiTables * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDualApiTables * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDualApiTables * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDualApiTables * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDualApiTables * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDualApiTables * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFixtureTable )( 
            IDualApiTables * This,
            /* [retval][out] */ IFCDualApiFixtureTable **iFixtureTable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetOriginTable )( 
            IDualApiTables * This,
            /* [retval][out] */ IFCDualApiOriginTable **iOriginTable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetPParamTable )( 
            IDualApiTables * This,
            /* [retval][out] */ IFCDualApiPParamTable **iPParamTable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseAllTables )( 
            IDualApiTables * This,
            /* [retval][out] */ BOOL *retval);
        
        END_INTERFACE
    } IDualApiTablesVtbl;

    interface IDualApiTables
    {
        CONST_VTBL struct IDualApiTablesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDualApiTables_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDualApiTables_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDualApiTables_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDualApiTables_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDualApiTables_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDualApiTables_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDualApiTables_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDualApiTables_GetFixtureTable(This,iFixtureTable)	\
    (This)->lpVtbl -> GetFixtureTable(This,iFixtureTable)

#define IDualApiTables_GetOriginTable(This,iOriginTable)	\
    (This)->lpVtbl -> GetOriginTable(This,iOriginTable)

#define IDualApiTables_GetPParamTable(This,iPParamTable)	\
    (This)->lpVtbl -> GetPParamTable(This,iPParamTable)

#define IDualApiTables_ReleaseAllTables(This,retval)	\
    (This)->lpVtbl -> ReleaseAllTables(This,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IDualApiTables_GetFixtureTable_Proxy( 
    IDualApiTables * This,
    /* [retval][out] */ IFCDualApiFixtureTable **iFixtureTable);


void __RPC_STUB IDualApiTables_GetFixtureTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualApiTables_GetOriginTable_Proxy( 
    IDualApiTables * This,
    /* [retval][out] */ IFCDualApiOriginTable **iOriginTable);


void __RPC_STUB IDualApiTables_GetOriginTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualApiTables_GetPParamTable_Proxy( 
    IDualApiTables * This,
    /* [retval][out] */ IFCDualApiPParamTable **iPParamTable);


void __RPC_STUB IDualApiTables_GetPParamTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualApiTables_ReleaseAllTables_Proxy( 
    IDualApiTables * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualApiTables_ReleaseAllTables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDualApiTables_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_ApiTables,0x583373B0,0x1B31,0x4D90,0x94,0x64,0x9D,0x78,0xF4,0xE5,0x0D,0xD7);

#ifdef __cplusplus

class DECLSPEC_UUID("583373B0-1B31-4D90-9464-9D78F4E50DD7")
CNC8070_ApiTables;
#endif

#ifndef __IFCParameter_DISPINTERFACE_DEFINED__
#define __IFCParameter_DISPINTERFACE_DEFINED__

/* dispinterface IFCParameter */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCParameter,0x19CC4ED4,0x69C3,0x46E4,0xBF,0xCD,0xF4,0xBA,0x92,0x35,0x7E,0xA4);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("19CC4ED4-69C3-46E4-BFCD-F4BA92357EA4")
    IFCParameter : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCParameterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCParameter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCParameter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCParameter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCParameter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCParameter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCParameter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCParameter * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCParameterVtbl;

    interface IFCParameter
    {
        CONST_VTBL struct IFCParameterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCParameter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCParameter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCParameter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCParameter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCParameter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCParameter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCParameter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCParameter_DISPINTERFACE_DEFINED__ */


#ifndef __IDualParameter_INTERFACE_DEFINED__
#define __IDualParameter_INTERFACE_DEFINED__

/* interface IDualParameter */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IDualParameter,0x790CBEBE,0x72F1,0x4e00,0x9A,0xA4,0x10,0xBB,0x05,0x92,0xA4,0x41);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("790CBEBE-72F1-4e00-9AA4-10BB0592A441")
    IDualParameter : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_mnemonic( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_mnemonic( 
            /* [in] */ BSTR nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_id( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_id( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_units( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_units( 
            /* [in] */ BSTR nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Visible( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Visible( 
            /* [in] */ BOOL nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Reboot( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Reboot( 
            /* [in] */ BOOL nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Format( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Format( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_MMInch( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_MMInch( 
            /* [in] */ BOOL nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ PARAMTYPE_T *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Type( 
            /* [in] */ PARAMTYPE_T nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_nFactor( 
            /* [retval][out] */ double *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_nFactor( 
            /* [in] */ double nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_dFactor( 
            /* [retval][out] */ double *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_dFactor( 
            /* [in] */ double nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_lLimit( 
            /* [retval][out] */ VARIANT *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_lLimit( 
            /* [in] */ VARIANT nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_uLimit( 
            /* [retval][out] */ VARIANT *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_uLimit( 
            /* [in] */ VARIANT nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_size( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_size( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultValue( 
            /* [retval][out] */ VARIANT *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultValue( 
            /* [in] */ VARIANT nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ VARIANT *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ VARIANT nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AxisName( 
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AxisName( 
            /* [in] */ BSTR nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_infoId( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_infoId( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_user( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_user( 
            /* [in] */ long nNewValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetArrayValue( 
            /* [in] */ short index,
            /* [retval][out] */ VARIANT *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetArrayValue( 
            /* [in] */ VARIANT value,
            /* [in] */ short index) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetArrayDefaultValue( 
            /* [in] */ short index,
            /* [retval][out] */ VARIANT *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ValueEx( 
            /* [retval][out] */ VARIANT *retval) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ValueEx( 
            /* [in] */ VARIANT nNewValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDualParameterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDualParameter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDualParameter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDualParameter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDualParameter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDualParameter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDualParameter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDualParameter * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_mnemonic )( 
            IDualParameter * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_mnemonic )( 
            IDualParameter * This,
            /* [in] */ BSTR nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_id )( 
            IDualParameter * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_id )( 
            IDualParameter * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_units )( 
            IDualParameter * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_units )( 
            IDualParameter * This,
            /* [in] */ BSTR nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Visible )( 
            IDualParameter * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Visible )( 
            IDualParameter * This,
            /* [in] */ BOOL nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Reboot )( 
            IDualParameter * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Reboot )( 
            IDualParameter * This,
            /* [in] */ BOOL nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Format )( 
            IDualParameter * This,
            /* [retval][out] */ short *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Format )( 
            IDualParameter * This,
            /* [in] */ short nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MMInch )( 
            IDualParameter * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MMInch )( 
            IDualParameter * This,
            /* [in] */ BOOL nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IDualParameter * This,
            /* [retval][out] */ PARAMTYPE_T *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Type )( 
            IDualParameter * This,
            /* [in] */ PARAMTYPE_T nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_nFactor )( 
            IDualParameter * This,
            /* [retval][out] */ double *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_nFactor )( 
            IDualParameter * This,
            /* [in] */ double nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_dFactor )( 
            IDualParameter * This,
            /* [retval][out] */ double *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_dFactor )( 
            IDualParameter * This,
            /* [in] */ double nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_lLimit )( 
            IDualParameter * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_lLimit )( 
            IDualParameter * This,
            /* [in] */ VARIANT nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_uLimit )( 
            IDualParameter * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_uLimit )( 
            IDualParameter * This,
            /* [in] */ VARIANT nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_size )( 
            IDualParameter * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_size )( 
            IDualParameter * This,
            /* [in] */ long nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultValue )( 
            IDualParameter * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultValue )( 
            IDualParameter * This,
            /* [in] */ VARIANT nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            IDualParameter * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            IDualParameter * This,
            /* [in] */ VARIANT nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AxisName )( 
            IDualParameter * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AxisName )( 
            IDualParameter * This,
            /* [in] */ BSTR nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_infoId )( 
            IDualParameter * This,
            /* [retval][out] */ short *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_infoId )( 
            IDualParameter * This,
            /* [in] */ short nNewValue);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_user )( 
            IDualParameter * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_user )( 
            IDualParameter * This,
            /* [in] */ long nNewValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetArrayValue )( 
            IDualParameter * This,
            /* [in] */ short index,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetArrayValue )( 
            IDualParameter * This,
            /* [in] */ VARIANT value,
            /* [in] */ short index);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetArrayDefaultValue )( 
            IDualParameter * This,
            /* [in] */ short index,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ValueEx )( 
            IDualParameter * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ValueEx )( 
            IDualParameter * This,
            /* [in] */ VARIANT nNewValue);
        
        END_INTERFACE
    } IDualParameterVtbl;

    interface IDualParameter
    {
        CONST_VTBL struct IDualParameterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDualParameter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDualParameter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDualParameter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDualParameter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDualParameter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDualParameter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDualParameter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDualParameter_get_mnemonic(This,retval)	\
    (This)->lpVtbl -> get_mnemonic(This,retval)

#define IDualParameter_put_mnemonic(This,nNewValue)	\
    (This)->lpVtbl -> put_mnemonic(This,nNewValue)

#define IDualParameter_get_id(This,retval)	\
    (This)->lpVtbl -> get_id(This,retval)

#define IDualParameter_put_id(This,nNewValue)	\
    (This)->lpVtbl -> put_id(This,nNewValue)

#define IDualParameter_get_units(This,retval)	\
    (This)->lpVtbl -> get_units(This,retval)

#define IDualParameter_put_units(This,nNewValue)	\
    (This)->lpVtbl -> put_units(This,nNewValue)

#define IDualParameter_get_Visible(This,retval)	\
    (This)->lpVtbl -> get_Visible(This,retval)

#define IDualParameter_put_Visible(This,nNewValue)	\
    (This)->lpVtbl -> put_Visible(This,nNewValue)

#define IDualParameter_get_Reboot(This,retval)	\
    (This)->lpVtbl -> get_Reboot(This,retval)

#define IDualParameter_put_Reboot(This,nNewValue)	\
    (This)->lpVtbl -> put_Reboot(This,nNewValue)

#define IDualParameter_get_Format(This,retval)	\
    (This)->lpVtbl -> get_Format(This,retval)

#define IDualParameter_put_Format(This,nNewValue)	\
    (This)->lpVtbl -> put_Format(This,nNewValue)

#define IDualParameter_get_MMInch(This,retval)	\
    (This)->lpVtbl -> get_MMInch(This,retval)

#define IDualParameter_put_MMInch(This,nNewValue)	\
    (This)->lpVtbl -> put_MMInch(This,nNewValue)

#define IDualParameter_get_Type(This,retval)	\
    (This)->lpVtbl -> get_Type(This,retval)

#define IDualParameter_put_Type(This,nNewValue)	\
    (This)->lpVtbl -> put_Type(This,nNewValue)

#define IDualParameter_get_nFactor(This,retval)	\
    (This)->lpVtbl -> get_nFactor(This,retval)

#define IDualParameter_put_nFactor(This,nNewValue)	\
    (This)->lpVtbl -> put_nFactor(This,nNewValue)

#define IDualParameter_get_dFactor(This,retval)	\
    (This)->lpVtbl -> get_dFactor(This,retval)

#define IDualParameter_put_dFactor(This,nNewValue)	\
    (This)->lpVtbl -> put_dFactor(This,nNewValue)

#define IDualParameter_get_lLimit(This,retval)	\
    (This)->lpVtbl -> get_lLimit(This,retval)

#define IDualParameter_put_lLimit(This,nNewValue)	\
    (This)->lpVtbl -> put_lLimit(This,nNewValue)

#define IDualParameter_get_uLimit(This,retval)	\
    (This)->lpVtbl -> get_uLimit(This,retval)

#define IDualParameter_put_uLimit(This,nNewValue)	\
    (This)->lpVtbl -> put_uLimit(This,nNewValue)

#define IDualParameter_get_size(This,retval)	\
    (This)->lpVtbl -> get_size(This,retval)

#define IDualParameter_put_size(This,nNewValue)	\
    (This)->lpVtbl -> put_size(This,nNewValue)

#define IDualParameter_get_DefaultValue(This,retval)	\
    (This)->lpVtbl -> get_DefaultValue(This,retval)

#define IDualParameter_put_DefaultValue(This,nNewValue)	\
    (This)->lpVtbl -> put_DefaultValue(This,nNewValue)

#define IDualParameter_get_Value(This,retval)	\
    (This)->lpVtbl -> get_Value(This,retval)

#define IDualParameter_put_Value(This,nNewValue)	\
    (This)->lpVtbl -> put_Value(This,nNewValue)

#define IDualParameter_get_AxisName(This,retval)	\
    (This)->lpVtbl -> get_AxisName(This,retval)

#define IDualParameter_put_AxisName(This,nNewValue)	\
    (This)->lpVtbl -> put_AxisName(This,nNewValue)

#define IDualParameter_get_infoId(This,retval)	\
    (This)->lpVtbl -> get_infoId(This,retval)

#define IDualParameter_put_infoId(This,nNewValue)	\
    (This)->lpVtbl -> put_infoId(This,nNewValue)

#define IDualParameter_get_user(This,retval)	\
    (This)->lpVtbl -> get_user(This,retval)

#define IDualParameter_put_user(This,nNewValue)	\
    (This)->lpVtbl -> put_user(This,nNewValue)

#define IDualParameter_GetArrayValue(This,index,retval)	\
    (This)->lpVtbl -> GetArrayValue(This,index,retval)

#define IDualParameter_SetArrayValue(This,value,index)	\
    (This)->lpVtbl -> SetArrayValue(This,value,index)

#define IDualParameter_GetArrayDefaultValue(This,index,retval)	\
    (This)->lpVtbl -> GetArrayDefaultValue(This,index,retval)

#define IDualParameter_get_ValueEx(This,retval)	\
    (This)->lpVtbl -> get_ValueEx(This,retval)

#define IDualParameter_put_ValueEx(This,nNewValue)	\
    (This)->lpVtbl -> put_ValueEx(This,nNewValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_mnemonic_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IDualParameter_get_mnemonic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_mnemonic_Proxy( 
    IDualParameter * This,
    /* [in] */ BSTR nNewValue);


void __RPC_STUB IDualParameter_put_mnemonic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_id_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameter_get_id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_id_Proxy( 
    IDualParameter * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IDualParameter_put_id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_units_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IDualParameter_get_units_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_units_Proxy( 
    IDualParameter * This,
    /* [in] */ BSTR nNewValue);


void __RPC_STUB IDualParameter_put_units_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_Visible_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualParameter_get_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_Visible_Proxy( 
    IDualParameter * This,
    /* [in] */ BOOL nNewValue);


void __RPC_STUB IDualParameter_put_Visible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_Reboot_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualParameter_get_Reboot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_Reboot_Proxy( 
    IDualParameter * This,
    /* [in] */ BOOL nNewValue);


void __RPC_STUB IDualParameter_put_Reboot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_Format_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IDualParameter_get_Format_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_Format_Proxy( 
    IDualParameter * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IDualParameter_put_Format_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_MMInch_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualParameter_get_MMInch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_MMInch_Proxy( 
    IDualParameter * This,
    /* [in] */ BOOL nNewValue);


void __RPC_STUB IDualParameter_put_MMInch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_Type_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ PARAMTYPE_T *retval);


void __RPC_STUB IDualParameter_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_Type_Proxy( 
    IDualParameter * This,
    /* [in] */ PARAMTYPE_T nNewValue);


void __RPC_STUB IDualParameter_put_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_nFactor_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ double *retval);


void __RPC_STUB IDualParameter_get_nFactor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_nFactor_Proxy( 
    IDualParameter * This,
    /* [in] */ double nNewValue);


void __RPC_STUB IDualParameter_put_nFactor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_dFactor_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ double *retval);


void __RPC_STUB IDualParameter_get_dFactor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_dFactor_Proxy( 
    IDualParameter * This,
    /* [in] */ double nNewValue);


void __RPC_STUB IDualParameter_put_dFactor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_lLimit_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ VARIANT *retval);


void __RPC_STUB IDualParameter_get_lLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_lLimit_Proxy( 
    IDualParameter * This,
    /* [in] */ VARIANT nNewValue);


void __RPC_STUB IDualParameter_put_lLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_uLimit_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ VARIANT *retval);


void __RPC_STUB IDualParameter_get_uLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_uLimit_Proxy( 
    IDualParameter * This,
    /* [in] */ VARIANT nNewValue);


void __RPC_STUB IDualParameter_put_uLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_size_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameter_get_size_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_size_Proxy( 
    IDualParameter * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IDualParameter_put_size_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_DefaultValue_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ VARIANT *retval);


void __RPC_STUB IDualParameter_get_DefaultValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_DefaultValue_Proxy( 
    IDualParameter * This,
    /* [in] */ VARIANT nNewValue);


void __RPC_STUB IDualParameter_put_DefaultValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_Value_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ VARIANT *retval);


void __RPC_STUB IDualParameter_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_Value_Proxy( 
    IDualParameter * This,
    /* [in] */ VARIANT nNewValue);


void __RPC_STUB IDualParameter_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_AxisName_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IDualParameter_get_AxisName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_AxisName_Proxy( 
    IDualParameter * This,
    /* [in] */ BSTR nNewValue);


void __RPC_STUB IDualParameter_put_AxisName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_infoId_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IDualParameter_get_infoId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_infoId_Proxy( 
    IDualParameter * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IDualParameter_put_infoId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_user_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameter_get_user_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_user_Proxy( 
    IDualParameter * This,
    /* [in] */ long nNewValue);


void __RPC_STUB IDualParameter_put_user_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameter_GetArrayValue_Proxy( 
    IDualParameter * This,
    /* [in] */ short index,
    /* [retval][out] */ VARIANT *retval);


void __RPC_STUB IDualParameter_GetArrayValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameter_SetArrayValue_Proxy( 
    IDualParameter * This,
    /* [in] */ VARIANT value,
    /* [in] */ short index);


void __RPC_STUB IDualParameter_SetArrayValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameter_GetArrayDefaultValue_Proxy( 
    IDualParameter * This,
    /* [in] */ short index,
    /* [retval][out] */ VARIANT *retval);


void __RPC_STUB IDualParameter_GetArrayDefaultValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameter_get_ValueEx_Proxy( 
    IDualParameter * This,
    /* [retval][out] */ VARIANT *retval);


void __RPC_STUB IDualParameter_get_ValueEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IDualParameter_put_ValueEx_Proxy( 
    IDualParameter * This,
    /* [in] */ VARIANT nNewValue);


void __RPC_STUB IDualParameter_put_ValueEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDualParameter_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_Parameter,0x22D6A97E,0xAAE5,0x472B,0x83,0x3F,0xDC,0x68,0x33,0x85,0xBC,0x75);

#ifdef __cplusplus

class DECLSPEC_UUID("22D6A97E-AAE5-472B-833F-DC683385BC75")
CNC8070_Parameter;
#endif

#ifndef __IFCParameterTable_DISPINTERFACE_DEFINED__
#define __IFCParameterTable_DISPINTERFACE_DEFINED__

/* dispinterface IFCParameterTable */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCParameterTable,0x53948A0B,0xC8A0,0x4F00,0x9E,0x7C,0x93,0xF9,0xA0,0x63,0x46,0xF2);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("53948A0B-C8A0-4F00-9E7C-93F9A06346F2")
    IFCParameterTable : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCParameterTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCParameterTable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCParameterTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCParameterTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCParameterTable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCParameterTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCParameterTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCParameterTable * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCParameterTableVtbl;

    interface IFCParameterTable
    {
        CONST_VTBL struct IFCParameterTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCParameterTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCParameterTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCParameterTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCParameterTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCParameterTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCParameterTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCParameterTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCParameterTable_DISPINTERFACE_DEFINED__ */


#ifndef __IDualParameterTable_INTERFACE_DEFINED__
#define __IDualParameterTable_INTERFACE_DEFINED__

/* interface IDualParameterTable */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IDualParameterTable,0xC786F7A5,0x167B,0x44ef,0x81,0x97,0x65,0x48,0x2A,0x30,0x54,0xF1);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C786F7A5-167B-44ef-8197-65482A3054F1")
    IDualParameterTable : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAt( 
            /* [retval][out] */ IDualParameter **parameter) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetParameterCount( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MoveFirst( 
            /* [retval][out] */ IDualParameter **parameter) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MoveLast( 
            /* [retval][out] */ IDualParameter **parameter) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MoveNext( 
            /* [retval][out] */ IDualParameter **parameter) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MovePrevious( 
            /* [retval][out] */ IDualParameter **parameter) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AddNew( 
            /* [retval][out] */ IDualParameter **parameter) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IDualParameter *parameter) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MoveTo( 
            /* [in] */ short index,
            /* [retval][out] */ IDualParameter **parameter) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetValues( 
            /* [out] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTypes( 
            /* [out] */ SAFEARRAY * *typesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetDefaultValues( 
            /* [out] */ SAFEARRAY * *defValuesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLLimits( 
            /* [out] */ SAFEARRAY * *lLimitsArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetULimits( 
            /* [out] */ SAFEARRAY * *uLimitsArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetUnits( 
            /* [out] */ SAFEARRAY * *unitsArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetMnemonics( 
            /* [out] */ SAFEARRAY * *mnemonicsArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTableRowNames( 
            /* [out] */ SAFEARRAY * *columnNamesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSizes( 
            /* [out] */ SAFEARRAY * *sizesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetArrayValues( 
            /* [in] */ long paramIndex,
            /* [out] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetArrayDefaultValues( 
            /* [in] */ long paramIndex,
            /* [out] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetParameterValue( 
            /* [in] */ VARIANT value,
            /* [in] */ long elemIndex,
            /* [retval][out] */ SETPARAM_T *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetEnumValues( 
            /* [in] */ long elemIndex,
            /* [out] */ SAFEARRAY * *valuesArray,
            /* [out] */ SAFEARRAY * *textArray,
            /* [out] */ SAFEARRAY * *infoIdArray,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetParamInfor( 
            /* [in] */ long elemIndex,
            /* [retval][out] */ BSTR *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetParamId( 
            /* [in] */ long elemIndex,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTableType( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_CanValidate( 
            /* [retval][out] */ BOOL *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDualParameterTableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDualParameterTable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDualParameterTable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDualParameterTable * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDualParameterTable * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDualParameterTable * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDualParameterTable * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDualParameterTable * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAt )( 
            IDualParameterTable * This,
            /* [retval][out] */ IDualParameter **parameter);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetParameterCount )( 
            IDualParameterTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MoveFirst )( 
            IDualParameterTable * This,
            /* [retval][out] */ IDualParameter **parameter);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MoveLast )( 
            IDualParameterTable * This,
            /* [retval][out] */ IDualParameter **parameter);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MoveNext )( 
            IDualParameterTable * This,
            /* [retval][out] */ IDualParameter **parameter);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MovePrevious )( 
            IDualParameterTable * This,
            /* [retval][out] */ IDualParameter **parameter);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AddNew )( 
            IDualParameterTable * This,
            /* [retval][out] */ IDualParameter **parameter);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IDualParameterTable * This,
            /* [in] */ IDualParameter *parameter);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAll )( 
            IDualParameterTable * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MoveTo )( 
            IDualParameterTable * This,
            /* [in] */ short index,
            /* [retval][out] */ IDualParameter **parameter);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetValues )( 
            IDualParameterTable * This,
            /* [out] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTypes )( 
            IDualParameterTable * This,
            /* [out] */ SAFEARRAY * *typesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetDefaultValues )( 
            IDualParameterTable * This,
            /* [out] */ SAFEARRAY * *defValuesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLLimits )( 
            IDualParameterTable * This,
            /* [out] */ SAFEARRAY * *lLimitsArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetULimits )( 
            IDualParameterTable * This,
            /* [out] */ SAFEARRAY * *uLimitsArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetUnits )( 
            IDualParameterTable * This,
            /* [out] */ SAFEARRAY * *unitsArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetMnemonics )( 
            IDualParameterTable * This,
            /* [out] */ SAFEARRAY * *mnemonicsArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTableRowNames )( 
            IDualParameterTable * This,
            /* [out] */ SAFEARRAY * *columnNamesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetSizes )( 
            IDualParameterTable * This,
            /* [out] */ SAFEARRAY * *sizesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetArrayValues )( 
            IDualParameterTable * This,
            /* [in] */ long paramIndex,
            /* [out] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetArrayDefaultValues )( 
            IDualParameterTable * This,
            /* [in] */ long paramIndex,
            /* [out] */ SAFEARRAY * *valuesArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetParameterValue )( 
            IDualParameterTable * This,
            /* [in] */ VARIANT value,
            /* [in] */ long elemIndex,
            /* [retval][out] */ SETPARAM_T *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetEnumValues )( 
            IDualParameterTable * This,
            /* [in] */ long elemIndex,
            /* [out] */ SAFEARRAY * *valuesArray,
            /* [out] */ SAFEARRAY * *textArray,
            /* [out] */ SAFEARRAY * *infoIdArray,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetParamInfor )( 
            IDualParameterTable * This,
            /* [in] */ long elemIndex,
            /* [retval][out] */ BSTR *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetParamId )( 
            IDualParameterTable * This,
            /* [in] */ long elemIndex,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTableType )( 
            IDualParameterTable * This,
            /* [retval][out] */ long *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CanValidate )( 
            IDualParameterTable * This,
            /* [retval][out] */ BOOL *retval);
        
        END_INTERFACE
    } IDualParameterTableVtbl;

    interface IDualParameterTable
    {
        CONST_VTBL struct IDualParameterTableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDualParameterTable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDualParameterTable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDualParameterTable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDualParameterTable_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDualParameterTable_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDualParameterTable_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDualParameterTable_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDualParameterTable_GetAt(This,parameter)	\
    (This)->lpVtbl -> GetAt(This,parameter)

#define IDualParameterTable_GetParameterCount(This,retval)	\
    (This)->lpVtbl -> GetParameterCount(This,retval)

#define IDualParameterTable_MoveFirst(This,parameter)	\
    (This)->lpVtbl -> MoveFirst(This,parameter)

#define IDualParameterTable_MoveLast(This,parameter)	\
    (This)->lpVtbl -> MoveLast(This,parameter)

#define IDualParameterTable_MoveNext(This,parameter)	\
    (This)->lpVtbl -> MoveNext(This,parameter)

#define IDualParameterTable_MovePrevious(This,parameter)	\
    (This)->lpVtbl -> MovePrevious(This,parameter)

#define IDualParameterTable_AddNew(This,parameter)	\
    (This)->lpVtbl -> AddNew(This,parameter)

#define IDualParameterTable_Add(This,parameter)	\
    (This)->lpVtbl -> Add(This,parameter)

#define IDualParameterTable_RemoveAll(This)	\
    (This)->lpVtbl -> RemoveAll(This)

#define IDualParameterTable_MoveTo(This,index,parameter)	\
    (This)->lpVtbl -> MoveTo(This,index,parameter)

#define IDualParameterTable_GetValues(This,valuesArray,retval)	\
    (This)->lpVtbl -> GetValues(This,valuesArray,retval)

#define IDualParameterTable_GetTypes(This,typesArray,retval)	\
    (This)->lpVtbl -> GetTypes(This,typesArray,retval)

#define IDualParameterTable_GetDefaultValues(This,defValuesArray,retval)	\
    (This)->lpVtbl -> GetDefaultValues(This,defValuesArray,retval)

#define IDualParameterTable_GetLLimits(This,lLimitsArray,retval)	\
    (This)->lpVtbl -> GetLLimits(This,lLimitsArray,retval)

#define IDualParameterTable_GetULimits(This,uLimitsArray,retval)	\
    (This)->lpVtbl -> GetULimits(This,uLimitsArray,retval)

#define IDualParameterTable_GetUnits(This,unitsArray,retval)	\
    (This)->lpVtbl -> GetUnits(This,unitsArray,retval)

#define IDualParameterTable_GetMnemonics(This,mnemonicsArray,retval)	\
    (This)->lpVtbl -> GetMnemonics(This,mnemonicsArray,retval)

#define IDualParameterTable_GetTableRowNames(This,columnNamesArray,retval)	\
    (This)->lpVtbl -> GetTableRowNames(This,columnNamesArray,retval)

#define IDualParameterTable_GetSizes(This,sizesArray,retval)	\
    (This)->lpVtbl -> GetSizes(This,sizesArray,retval)

#define IDualParameterTable_GetArrayValues(This,paramIndex,valuesArray,retval)	\
    (This)->lpVtbl -> GetArrayValues(This,paramIndex,valuesArray,retval)

#define IDualParameterTable_GetArrayDefaultValues(This,paramIndex,valuesArray,retval)	\
    (This)->lpVtbl -> GetArrayDefaultValues(This,paramIndex,valuesArray,retval)

#define IDualParameterTable_SetParameterValue(This,value,elemIndex,retval)	\
    (This)->lpVtbl -> SetParameterValue(This,value,elemIndex,retval)

#define IDualParameterTable_GetEnumValues(This,elemIndex,valuesArray,textArray,infoIdArray,retval)	\
    (This)->lpVtbl -> GetEnumValues(This,elemIndex,valuesArray,textArray,infoIdArray,retval)

#define IDualParameterTable_GetParamInfor(This,elemIndex,retval)	\
    (This)->lpVtbl -> GetParamInfor(This,elemIndex,retval)

#define IDualParameterTable_GetParamId(This,elemIndex,retval)	\
    (This)->lpVtbl -> GetParamId(This,elemIndex,retval)

#define IDualParameterTable_GetTableType(This,retval)	\
    (This)->lpVtbl -> GetTableType(This,retval)

#define IDualParameterTable_get_CanValidate(This,retval)	\
    (This)->lpVtbl -> get_CanValidate(This,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetAt_Proxy( 
    IDualParameterTable * This,
    /* [retval][out] */ IDualParameter **parameter);


void __RPC_STUB IDualParameterTable_GetAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetParameterCount_Proxy( 
    IDualParameterTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetParameterCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_MoveFirst_Proxy( 
    IDualParameterTable * This,
    /* [retval][out] */ IDualParameter **parameter);


void __RPC_STUB IDualParameterTable_MoveFirst_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_MoveLast_Proxy( 
    IDualParameterTable * This,
    /* [retval][out] */ IDualParameter **parameter);


void __RPC_STUB IDualParameterTable_MoveLast_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_MoveNext_Proxy( 
    IDualParameterTable * This,
    /* [retval][out] */ IDualParameter **parameter);


void __RPC_STUB IDualParameterTable_MoveNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_MovePrevious_Proxy( 
    IDualParameterTable * This,
    /* [retval][out] */ IDualParameter **parameter);


void __RPC_STUB IDualParameterTable_MovePrevious_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_AddNew_Proxy( 
    IDualParameterTable * This,
    /* [retval][out] */ IDualParameter **parameter);


void __RPC_STUB IDualParameterTable_AddNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_Add_Proxy( 
    IDualParameterTable * This,
    /* [in] */ IDualParameter *parameter);


void __RPC_STUB IDualParameterTable_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_RemoveAll_Proxy( 
    IDualParameterTable * This);


void __RPC_STUB IDualParameterTable_RemoveAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_MoveTo_Proxy( 
    IDualParameterTable * This,
    /* [in] */ short index,
    /* [retval][out] */ IDualParameter **parameter);


void __RPC_STUB IDualParameterTable_MoveTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetValues_Proxy( 
    IDualParameterTable * This,
    /* [out] */ SAFEARRAY * *valuesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetTypes_Proxy( 
    IDualParameterTable * This,
    /* [out] */ SAFEARRAY * *typesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetDefaultValues_Proxy( 
    IDualParameterTable * This,
    /* [out] */ SAFEARRAY * *defValuesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetDefaultValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetLLimits_Proxy( 
    IDualParameterTable * This,
    /* [out] */ SAFEARRAY * *lLimitsArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetLLimits_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetULimits_Proxy( 
    IDualParameterTable * This,
    /* [out] */ SAFEARRAY * *uLimitsArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetULimits_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetUnits_Proxy( 
    IDualParameterTable * This,
    /* [out] */ SAFEARRAY * *unitsArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetUnits_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetMnemonics_Proxy( 
    IDualParameterTable * This,
    /* [out] */ SAFEARRAY * *mnemonicsArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetMnemonics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetTableRowNames_Proxy( 
    IDualParameterTable * This,
    /* [out] */ SAFEARRAY * *columnNamesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetTableRowNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetSizes_Proxy( 
    IDualParameterTable * This,
    /* [out] */ SAFEARRAY * *sizesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetSizes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetArrayValues_Proxy( 
    IDualParameterTable * This,
    /* [in] */ long paramIndex,
    /* [out] */ SAFEARRAY * *valuesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetArrayValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetArrayDefaultValues_Proxy( 
    IDualParameterTable * This,
    /* [in] */ long paramIndex,
    /* [out] */ SAFEARRAY * *valuesArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetArrayDefaultValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_SetParameterValue_Proxy( 
    IDualParameterTable * This,
    /* [in] */ VARIANT value,
    /* [in] */ long elemIndex,
    /* [retval][out] */ SETPARAM_T *retval);


void __RPC_STUB IDualParameterTable_SetParameterValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetEnumValues_Proxy( 
    IDualParameterTable * This,
    /* [in] */ long elemIndex,
    /* [out] */ SAFEARRAY * *valuesArray,
    /* [out] */ SAFEARRAY * *textArray,
    /* [out] */ SAFEARRAY * *infoIdArray,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualParameterTable_GetEnumValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetParamInfor_Proxy( 
    IDualParameterTable * This,
    /* [in] */ long elemIndex,
    /* [retval][out] */ BSTR *retval);


void __RPC_STUB IDualParameterTable_GetParamInfor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetParamId_Proxy( 
    IDualParameterTable * This,
    /* [in] */ long elemIndex,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetParamId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_GetTableType_Proxy( 
    IDualParameterTable * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IDualParameterTable_GetTableType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDualParameterTable_get_CanValidate_Proxy( 
    IDualParameterTable * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IDualParameterTable_get_CanValidate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDualParameterTable_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_ParameterTable,0x9A98EF89,0xAB76,0x48C1,0x96,0xE6,0x1E,0xE2,0x84,0x11,0xCC,0x53);

#ifdef __cplusplus

class DECLSPEC_UUID("9A98EF89-AB76-48C1-96E6-1EE28411CC53")
CNC8070_ParameterTable;
#endif

#ifndef __IFCMachineParameters_DISPINTERFACE_DEFINED__
#define __IFCMachineParameters_DISPINTERFACE_DEFINED__

/* dispinterface IFCMachineParameters */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCMachineParameters,0x86D4A86D,0x6CE7,0x4791,0xB4,0x42,0x7C,0x84,0x33,0x57,0x0B,0xDE);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("86D4A86D-6CE7-4791-B442-7C8433570BDE")
    IFCMachineParameters : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCMachineParametersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCMachineParameters * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCMachineParameters * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCMachineParameters * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCMachineParameters * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCMachineParameters * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCMachineParameters * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCMachineParameters * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCMachineParametersVtbl;

    interface IFCMachineParameters
    {
        CONST_VTBL struct IFCMachineParametersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCMachineParameters_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCMachineParameters_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCMachineParameters_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCMachineParameters_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCMachineParameters_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCMachineParameters_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCMachineParameters_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCMachineParameters_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualMachineParameters_INTERFACE_DEFINED__
#define __IFCDualMachineParameters_INTERFACE_DEFINED__

/* interface IFCDualMachineParameters */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualMachineParameters,0x5197407F,0x2BA2,0x49be,0xBC,0xA5,0x87,0xD7,0x1C,0x9B,0x57,0x5D);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5197407F-2BA2-49be-BCA5-87D71C9B575D")
    IFCDualMachineParameters : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetDataTable( 
            /* [in] */ long datatable,
            /* [retval][out] */ IDualParameterTable **parameterTable) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTableList( 
            /* [out] */ SAFEARRAY * *idArray,
            /* [out] */ SAFEARRAY * *textArray,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetDefaultValueName( 
            /* [in] */ long idParameter,
            /* [in] */ long datatable,
            /* [retval][out] */ BSTR *name) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UpdateParameter( 
            /* [in] */ long datatable,
            /* [in] */ IDualParameter *parameter) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UpdateArrayParameter( 
            /* [in] */ long datatable,
            /* [in] */ long index,
            /* [in] */ IDualParameter *parameter) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ValidateDataTable( 
            /* [in] */ long datatable,
            /* [in] */ short mmInches) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CanGetDataTable( 
            /* [in] */ long datatable,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetDataTable( 
            /* [in] */ long datatable,
            /* [in] */ IDualParameterTable *table) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAxisDataTableID_FromName( 
            /* [in] */ BSTR nombre,
            /* [retval][out] */ LONG *datatable) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAxisDataTableID_FromLogAxisNr( 
            /* [in] */ long logAxisNr,
            /* [retval][out] */ LONG *datatable) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE BringTablesUpToDate( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE BackupToFolder_MachineParameter( 
            /* [in] */ BSTR bstrFolder,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE BackupToFolder_DriveParameter( 
            /* [in] */ BSTR bstrFolder,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RestoreFromFolder_MachineParameter( 
            /* [in] */ BSTR bstrFolder,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RestoreFromFolder_DriveParameter( 
            /* [in] */ BSTR bstrFolder,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GenMP_BackupToFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GenMP_RestoreFromFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AxisMP_BackupToFile( 
            /* [in] */ long axisNr,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE AxisMP_RestoreFromFile( 
            /* [in] */ long axisNr,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualMP_BackupToFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualMP_RestoreFromFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MFunctionMP_BackupToFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MFunctionMP_RestoreFromFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE KinMP_BackupToFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE KinMP_RestoreFromFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MzMP_BackupToFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MzMP_RestoreFromFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DRVMP_BackupToFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DRVMP_RestoreFromFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MTBMP_BackupToFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MTBMP_RestoreFromFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CAMMP_BackupToFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CAMMP_RestoreFromFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE HMIMP_BackupToFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE HMIMP_RestoreFromFile( 
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualMachineParametersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualMachineParameters * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualMachineParameters * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualMachineParameters * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualMachineParameters * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualMachineParameters * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualMachineParameters * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualMachineParameters * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetDataTable )( 
            IFCDualMachineParameters * This,
            /* [in] */ long datatable,
            /* [retval][out] */ IDualParameterTable **parameterTable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetTableList )( 
            IFCDualMachineParameters * This,
            /* [out] */ SAFEARRAY * *idArray,
            /* [out] */ SAFEARRAY * *textArray,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetDefaultValueName )( 
            IFCDualMachineParameters * This,
            /* [in] */ long idParameter,
            /* [in] */ long datatable,
            /* [retval][out] */ BSTR *name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UpdateParameter )( 
            IFCDualMachineParameters * This,
            /* [in] */ long datatable,
            /* [in] */ IDualParameter *parameter);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UpdateArrayParameter )( 
            IFCDualMachineParameters * This,
            /* [in] */ long datatable,
            /* [in] */ long index,
            /* [in] */ IDualParameter *parameter);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ValidateDataTable )( 
            IFCDualMachineParameters * This,
            /* [in] */ long datatable,
            /* [in] */ short mmInches);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CanGetDataTable )( 
            IFCDualMachineParameters * This,
            /* [in] */ long datatable,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetDataTable )( 
            IFCDualMachineParameters * This,
            /* [in] */ long datatable,
            /* [in] */ IDualParameterTable *table);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAxisDataTableID_FromName )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR nombre,
            /* [retval][out] */ LONG *datatable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAxisDataTableID_FromLogAxisNr )( 
            IFCDualMachineParameters * This,
            /* [in] */ long logAxisNr,
            /* [retval][out] */ LONG *datatable);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *BringTablesUpToDate )( 
            IFCDualMachineParameters * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *BackupToFolder_MachineParameter )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFolder,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *BackupToFolder_DriveParameter )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFolder,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RestoreFromFolder_MachineParameter )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFolder,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RestoreFromFolder_DriveParameter )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFolder,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GenMP_BackupToFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GenMP_RestoreFromFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AxisMP_BackupToFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ long axisNr,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *AxisMP_RestoreFromFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ long axisNr,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ManualMP_BackupToFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ManualMP_RestoreFromFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MFunctionMP_BackupToFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MFunctionMP_RestoreFromFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *KinMP_BackupToFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *KinMP_RestoreFromFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MzMP_BackupToFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MzMP_RestoreFromFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DRVMP_BackupToFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *DRVMP_RestoreFromFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MTBMP_BackupToFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *MTBMP_RestoreFromFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CAMMP_BackupToFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CAMMP_RestoreFromFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *HMIMP_BackupToFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *HMIMP_RestoreFromFile )( 
            IFCDualMachineParameters * This,
            /* [in] */ BSTR bstrFile,
            /* [in] */ BOOL bInches,
            /* [retval][out] */ BOOL *retval);
        
        END_INTERFACE
    } IFCDualMachineParametersVtbl;

    interface IFCDualMachineParameters
    {
        CONST_VTBL struct IFCDualMachineParametersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualMachineParameters_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualMachineParameters_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualMachineParameters_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualMachineParameters_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualMachineParameters_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualMachineParameters_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualMachineParameters_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualMachineParameters_GetDataTable(This,datatable,parameterTable)	\
    (This)->lpVtbl -> GetDataTable(This,datatable,parameterTable)

#define IFCDualMachineParameters_GetTableList(This,idArray,textArray,retval)	\
    (This)->lpVtbl -> GetTableList(This,idArray,textArray,retval)

#define IFCDualMachineParameters_GetDefaultValueName(This,idParameter,datatable,name)	\
    (This)->lpVtbl -> GetDefaultValueName(This,idParameter,datatable,name)

#define IFCDualMachineParameters_UpdateParameter(This,datatable,parameter)	\
    (This)->lpVtbl -> UpdateParameter(This,datatable,parameter)

#define IFCDualMachineParameters_UpdateArrayParameter(This,datatable,index,parameter)	\
    (This)->lpVtbl -> UpdateArrayParameter(This,datatable,index,parameter)

#define IFCDualMachineParameters_ValidateDataTable(This,datatable,mmInches)	\
    (This)->lpVtbl -> ValidateDataTable(This,datatable,mmInches)

#define IFCDualMachineParameters_CanGetDataTable(This,datatable,retval)	\
    (This)->lpVtbl -> CanGetDataTable(This,datatable,retval)

#define IFCDualMachineParameters_SetDataTable(This,datatable,table)	\
    (This)->lpVtbl -> SetDataTable(This,datatable,table)

#define IFCDualMachineParameters_GetAxisDataTableID_FromName(This,nombre,datatable)	\
    (This)->lpVtbl -> GetAxisDataTableID_FromName(This,nombre,datatable)

#define IFCDualMachineParameters_GetAxisDataTableID_FromLogAxisNr(This,logAxisNr,datatable)	\
    (This)->lpVtbl -> GetAxisDataTableID_FromLogAxisNr(This,logAxisNr,datatable)

#define IFCDualMachineParameters_BringTablesUpToDate(This,retval)	\
    (This)->lpVtbl -> BringTablesUpToDate(This,retval)

#define IFCDualMachineParameters_BackupToFolder_MachineParameter(This,bstrFolder,bInches,retval)	\
    (This)->lpVtbl -> BackupToFolder_MachineParameter(This,bstrFolder,bInches,retval)

#define IFCDualMachineParameters_BackupToFolder_DriveParameter(This,bstrFolder,retval)	\
    (This)->lpVtbl -> BackupToFolder_DriveParameter(This,bstrFolder,retval)

#define IFCDualMachineParameters_RestoreFromFolder_MachineParameter(This,bstrFolder,bInches,retval)	\
    (This)->lpVtbl -> RestoreFromFolder_MachineParameter(This,bstrFolder,bInches,retval)

#define IFCDualMachineParameters_RestoreFromFolder_DriveParameter(This,bstrFolder,retval)	\
    (This)->lpVtbl -> RestoreFromFolder_DriveParameter(This,bstrFolder,retval)

#define IFCDualMachineParameters_GenMP_BackupToFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> GenMP_BackupToFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_GenMP_RestoreFromFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> GenMP_RestoreFromFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_AxisMP_BackupToFile(This,axisNr,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> AxisMP_BackupToFile(This,axisNr,bstrFile,bInches,retval)

#define IFCDualMachineParameters_AxisMP_RestoreFromFile(This,axisNr,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> AxisMP_RestoreFromFile(This,axisNr,bstrFile,bInches,retval)

#define IFCDualMachineParameters_ManualMP_BackupToFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> ManualMP_BackupToFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_ManualMP_RestoreFromFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> ManualMP_RestoreFromFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_MFunctionMP_BackupToFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> MFunctionMP_BackupToFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_MFunctionMP_RestoreFromFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> MFunctionMP_RestoreFromFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_KinMP_BackupToFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> KinMP_BackupToFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_KinMP_RestoreFromFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> KinMP_RestoreFromFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_MzMP_BackupToFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> MzMP_BackupToFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_MzMP_RestoreFromFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> MzMP_RestoreFromFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_DRVMP_BackupToFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> DRVMP_BackupToFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_DRVMP_RestoreFromFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> DRVMP_RestoreFromFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_MTBMP_BackupToFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> MTBMP_BackupToFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_MTBMP_RestoreFromFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> MTBMP_RestoreFromFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_CAMMP_BackupToFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> CAMMP_BackupToFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_CAMMP_RestoreFromFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> CAMMP_RestoreFromFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_HMIMP_BackupToFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> HMIMP_BackupToFile(This,bstrFile,bInches,retval)

#define IFCDualMachineParameters_HMIMP_RestoreFromFile(This,bstrFile,bInches,retval)	\
    (This)->lpVtbl -> HMIMP_RestoreFromFile(This,bstrFile,bInches,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_GetDataTable_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ long datatable,
    /* [retval][out] */ IDualParameterTable **parameterTable);


void __RPC_STUB IFCDualMachineParameters_GetDataTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_GetTableList_Proxy( 
    IFCDualMachineParameters * This,
    /* [out] */ SAFEARRAY * *idArray,
    /* [out] */ SAFEARRAY * *textArray,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_GetTableList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_GetDefaultValueName_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ long idParameter,
    /* [in] */ long datatable,
    /* [retval][out] */ BSTR *name);


void __RPC_STUB IFCDualMachineParameters_GetDefaultValueName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_UpdateParameter_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ long datatable,
    /* [in] */ IDualParameter *parameter);


void __RPC_STUB IFCDualMachineParameters_UpdateParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_UpdateArrayParameter_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ long datatable,
    /* [in] */ long index,
    /* [in] */ IDualParameter *parameter);


void __RPC_STUB IFCDualMachineParameters_UpdateArrayParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_ValidateDataTable_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ long datatable,
    /* [in] */ short mmInches);


void __RPC_STUB IFCDualMachineParameters_ValidateDataTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_CanGetDataTable_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ long datatable,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_CanGetDataTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_SetDataTable_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ long datatable,
    /* [in] */ IDualParameterTable *table);


void __RPC_STUB IFCDualMachineParameters_SetDataTable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_GetAxisDataTableID_FromName_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR nombre,
    /* [retval][out] */ LONG *datatable);


void __RPC_STUB IFCDualMachineParameters_GetAxisDataTableID_FromName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_GetAxisDataTableID_FromLogAxisNr_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ long logAxisNr,
    /* [retval][out] */ LONG *datatable);


void __RPC_STUB IFCDualMachineParameters_GetAxisDataTableID_FromLogAxisNr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_BringTablesUpToDate_Proxy( 
    IFCDualMachineParameters * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_BringTablesUpToDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_BackupToFolder_MachineParameter_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFolder,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_BackupToFolder_MachineParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_BackupToFolder_DriveParameter_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFolder,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_BackupToFolder_DriveParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_RestoreFromFolder_MachineParameter_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFolder,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_RestoreFromFolder_MachineParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_RestoreFromFolder_DriveParameter_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFolder,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_RestoreFromFolder_DriveParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_GenMP_BackupToFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_GenMP_BackupToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_GenMP_RestoreFromFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_GenMP_RestoreFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_AxisMP_BackupToFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ long axisNr,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_AxisMP_BackupToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_AxisMP_RestoreFromFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ long axisNr,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_AxisMP_RestoreFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_ManualMP_BackupToFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_ManualMP_BackupToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_ManualMP_RestoreFromFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_ManualMP_RestoreFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_MFunctionMP_BackupToFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_MFunctionMP_BackupToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_MFunctionMP_RestoreFromFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_MFunctionMP_RestoreFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_KinMP_BackupToFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_KinMP_BackupToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_KinMP_RestoreFromFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_KinMP_RestoreFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_MzMP_BackupToFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_MzMP_BackupToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_MzMP_RestoreFromFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_MzMP_RestoreFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_DRVMP_BackupToFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_DRVMP_BackupToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_DRVMP_RestoreFromFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_DRVMP_RestoreFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_MTBMP_BackupToFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_MTBMP_BackupToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_MTBMP_RestoreFromFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_MTBMP_RestoreFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_CAMMP_BackupToFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_CAMMP_BackupToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_CAMMP_RestoreFromFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_CAMMP_RestoreFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_HMIMP_BackupToFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_HMIMP_BackupToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualMachineParameters_HMIMP_RestoreFromFile_Proxy( 
    IFCDualMachineParameters * This,
    /* [in] */ BSTR bstrFile,
    /* [in] */ BOOL bInches,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualMachineParameters_HMIMP_RestoreFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualMachineParameters_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_MachineParameters,0x15B3718B,0xC9DC,0x4E76,0x9F,0x04,0x89,0x22,0x78,0xE1,0x44,0x07);

#ifdef __cplusplus

class DECLSPEC_UUID("15B3718B-C9DC-4E76-9F04-892278E14407")
CNC8070_MachineParameters;
#endif

#ifndef __IFCJog_DISPINTERFACE_DEFINED__
#define __IFCJog_DISPINTERFACE_DEFINED__

/* dispinterface IFCJog */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCJog,0xA010587D,0x49FE,0x47C5,0xA5,0x75,0x2E,0x28,0xA4,0x55,0xD9,0xD9);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A010587D-49FE-47C5-A575-2E28A455D9D9")
    IFCJog : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCJogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCJog * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCJog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCJog * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCJog * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCJog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCJog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCJog * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCJogVtbl;

    interface IFCJog
    {
        CONST_VTBL struct IFCJogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCJog_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCJog_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCJog_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCJog_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCJog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCJog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCJog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCJog_DISPINTERFACE_DEFINED__ */


#ifndef __IJogKeyReport_DISPINTERFACE_DEFINED__
#define __IJogKeyReport_DISPINTERFACE_DEFINED__

/* dispinterface IJogKeyReport */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_IJogKeyReport,0x3DD50F9A,0x7072,0x4694,0x85,0xFA,0x08,0xE2,0x04,0x3A,0x2F,0x45);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3DD50F9A-7072-4694-85FA-08E2043A2F45")
    IJogKeyReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IJogKeyReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IJogKeyReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IJogKeyReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IJogKeyReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IJogKeyReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IJogKeyReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IJogKeyReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IJogKeyReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IJogKeyReportVtbl;

    interface IJogKeyReport
    {
        CONST_VTBL struct IJogKeyReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IJogKeyReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IJogKeyReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IJogKeyReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IJogKeyReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IJogKeyReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IJogKeyReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IJogKeyReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IJogKeyReport_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualJog_INTERFACE_DEFINED__
#define __IFCDualJog_INTERFACE_DEFINED__

/* interface IFCDualJog */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualJog,0x2F44E33C,0xD2A8,0x498c,0x91,0x6F,0xE5,0xC9,0x62,0x42,0x7E,0xAB);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2F44E33C-D2A8-498c-916F-E5C962427EAB")
    IFCDualJog : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey1( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey1( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey2( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey2( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey3( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey3( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey4( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey4( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey5( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey5( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey6( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey6( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey7( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey7( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey8( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey8( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey9( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey9( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey10( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey10( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey11( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey11( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey12( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey12( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey13( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey13( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey14( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey14( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey15( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey15( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_userKey16( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_userKey16( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey0( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey0( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey1( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey1( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey2( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey2( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey3( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey3( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey4( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey4( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey5( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey5( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey6( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey6( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey7( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey7( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey8( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey8( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey9( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey9( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey10( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey10( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey11( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey11( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey12( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey12( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey13( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey13( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_moveKey14( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_moveKey14( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_m3( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_m3( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_srMinus( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_srMinus( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_m19( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_m19( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_m5( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_m5( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_srPlus( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_srPlus( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_m4( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_m4( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_start( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_start( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_stop( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_stop( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_zero( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_zero( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_singleBlock( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_singleBlock( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_reset( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_reset( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ovrPos( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ovrPos( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_manualMode( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_manualMode( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_activateJog( 
            /* [retval][out] */ short *retval) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_activateJog( 
            /* [in] */ short nNewValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetJogClient( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetStateJog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReleaseJogClient( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ExtendedJogKeyReports( 
            BOOL bActivate) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetJogClient2( 
            /* [in] */ IUnknown *pSink) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReleaseJogClient2( 
            /* [in] */ IUnknown *pSink) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualJogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualJog * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualJog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualJog * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualJog * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualJog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualJog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualJog * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey1 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey1 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey2 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey2 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey3 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey3 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey4 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey4 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey5 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey5 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey6 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey6 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey7 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey7 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey8 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey8 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey9 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey9 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey10 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey10 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey11 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey11 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey12 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey12 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey13 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey13 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey14 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey14 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey15 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey15 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_userKey16 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_userKey16 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey0 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey0 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey1 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey1 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey2 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey2 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey3 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey3 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey4 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey4 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey5 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey5 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey6 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey6 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey7 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey7 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey8 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey8 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey9 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey9 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey10 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey10 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey11 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey11 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey12 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey12 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey13 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey13 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_moveKey14 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_moveKey14 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_m3 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_m3 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_srMinus )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_srMinus )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_m19 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_m19 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_m5 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_m5 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_srPlus )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_srPlus )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_m4 )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_m4 )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_start )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_start )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_stop )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_stop )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_zero )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_zero )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_singleBlock )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_singleBlock )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_reset )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_reset )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ovrPos )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ovrPos )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_manualMode )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_manualMode )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_activateJog )( 
            IFCDualJog * This,
            /* [retval][out] */ short *retval);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_activateJog )( 
            IFCDualJog * This,
            /* [in] */ short nNewValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetJogClient )( 
            IFCDualJog * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStateJog )( 
            IFCDualJog * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseJogClient )( 
            IFCDualJog * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ExtendedJogKeyReports )( 
            IFCDualJog * This,
            BOOL bActivate);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetJogClient2 )( 
            IFCDualJog * This,
            /* [in] */ IUnknown *pSink);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseJogClient2 )( 
            IFCDualJog * This,
            /* [in] */ IUnknown *pSink);
        
        END_INTERFACE
    } IFCDualJogVtbl;

    interface IFCDualJog
    {
        CONST_VTBL struct IFCDualJogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualJog_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualJog_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualJog_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualJog_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualJog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualJog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualJog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualJog_get_userKey1(This,retval)	\
    (This)->lpVtbl -> get_userKey1(This,retval)

#define IFCDualJog_put_userKey1(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey1(This,nNewValue)

#define IFCDualJog_get_userKey2(This,retval)	\
    (This)->lpVtbl -> get_userKey2(This,retval)

#define IFCDualJog_put_userKey2(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey2(This,nNewValue)

#define IFCDualJog_get_userKey3(This,retval)	\
    (This)->lpVtbl -> get_userKey3(This,retval)

#define IFCDualJog_put_userKey3(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey3(This,nNewValue)

#define IFCDualJog_get_userKey4(This,retval)	\
    (This)->lpVtbl -> get_userKey4(This,retval)

#define IFCDualJog_put_userKey4(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey4(This,nNewValue)

#define IFCDualJog_get_userKey5(This,retval)	\
    (This)->lpVtbl -> get_userKey5(This,retval)

#define IFCDualJog_put_userKey5(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey5(This,nNewValue)

#define IFCDualJog_get_userKey6(This,retval)	\
    (This)->lpVtbl -> get_userKey6(This,retval)

#define IFCDualJog_put_userKey6(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey6(This,nNewValue)

#define IFCDualJog_get_userKey7(This,retval)	\
    (This)->lpVtbl -> get_userKey7(This,retval)

#define IFCDualJog_put_userKey7(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey7(This,nNewValue)

#define IFCDualJog_get_userKey8(This,retval)	\
    (This)->lpVtbl -> get_userKey8(This,retval)

#define IFCDualJog_put_userKey8(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey8(This,nNewValue)

#define IFCDualJog_get_userKey9(This,retval)	\
    (This)->lpVtbl -> get_userKey9(This,retval)

#define IFCDualJog_put_userKey9(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey9(This,nNewValue)

#define IFCDualJog_get_userKey10(This,retval)	\
    (This)->lpVtbl -> get_userKey10(This,retval)

#define IFCDualJog_put_userKey10(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey10(This,nNewValue)

#define IFCDualJog_get_userKey11(This,retval)	\
    (This)->lpVtbl -> get_userKey11(This,retval)

#define IFCDualJog_put_userKey11(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey11(This,nNewValue)

#define IFCDualJog_get_userKey12(This,retval)	\
    (This)->lpVtbl -> get_userKey12(This,retval)

#define IFCDualJog_put_userKey12(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey12(This,nNewValue)

#define IFCDualJog_get_userKey13(This,retval)	\
    (This)->lpVtbl -> get_userKey13(This,retval)

#define IFCDualJog_put_userKey13(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey13(This,nNewValue)

#define IFCDualJog_get_userKey14(This,retval)	\
    (This)->lpVtbl -> get_userKey14(This,retval)

#define IFCDualJog_put_userKey14(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey14(This,nNewValue)

#define IFCDualJog_get_userKey15(This,retval)	\
    (This)->lpVtbl -> get_userKey15(This,retval)

#define IFCDualJog_put_userKey15(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey15(This,nNewValue)

#define IFCDualJog_get_userKey16(This,retval)	\
    (This)->lpVtbl -> get_userKey16(This,retval)

#define IFCDualJog_put_userKey16(This,nNewValue)	\
    (This)->lpVtbl -> put_userKey16(This,nNewValue)

#define IFCDualJog_get_moveKey0(This,retval)	\
    (This)->lpVtbl -> get_moveKey0(This,retval)

#define IFCDualJog_put_moveKey0(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey0(This,nNewValue)

#define IFCDualJog_get_moveKey1(This,retval)	\
    (This)->lpVtbl -> get_moveKey1(This,retval)

#define IFCDualJog_put_moveKey1(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey1(This,nNewValue)

#define IFCDualJog_get_moveKey2(This,retval)	\
    (This)->lpVtbl -> get_moveKey2(This,retval)

#define IFCDualJog_put_moveKey2(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey2(This,nNewValue)

#define IFCDualJog_get_moveKey3(This,retval)	\
    (This)->lpVtbl -> get_moveKey3(This,retval)

#define IFCDualJog_put_moveKey3(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey3(This,nNewValue)

#define IFCDualJog_get_moveKey4(This,retval)	\
    (This)->lpVtbl -> get_moveKey4(This,retval)

#define IFCDualJog_put_moveKey4(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey4(This,nNewValue)

#define IFCDualJog_get_moveKey5(This,retval)	\
    (This)->lpVtbl -> get_moveKey5(This,retval)

#define IFCDualJog_put_moveKey5(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey5(This,nNewValue)

#define IFCDualJog_get_moveKey6(This,retval)	\
    (This)->lpVtbl -> get_moveKey6(This,retval)

#define IFCDualJog_put_moveKey6(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey6(This,nNewValue)

#define IFCDualJog_get_moveKey7(This,retval)	\
    (This)->lpVtbl -> get_moveKey7(This,retval)

#define IFCDualJog_put_moveKey7(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey7(This,nNewValue)

#define IFCDualJog_get_moveKey8(This,retval)	\
    (This)->lpVtbl -> get_moveKey8(This,retval)

#define IFCDualJog_put_moveKey8(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey8(This,nNewValue)

#define IFCDualJog_get_moveKey9(This,retval)	\
    (This)->lpVtbl -> get_moveKey9(This,retval)

#define IFCDualJog_put_moveKey9(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey9(This,nNewValue)

#define IFCDualJog_get_moveKey10(This,retval)	\
    (This)->lpVtbl -> get_moveKey10(This,retval)

#define IFCDualJog_put_moveKey10(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey10(This,nNewValue)

#define IFCDualJog_get_moveKey11(This,retval)	\
    (This)->lpVtbl -> get_moveKey11(This,retval)

#define IFCDualJog_put_moveKey11(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey11(This,nNewValue)

#define IFCDualJog_get_moveKey12(This,retval)	\
    (This)->lpVtbl -> get_moveKey12(This,retval)

#define IFCDualJog_put_moveKey12(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey12(This,nNewValue)

#define IFCDualJog_get_moveKey13(This,retval)	\
    (This)->lpVtbl -> get_moveKey13(This,retval)

#define IFCDualJog_put_moveKey13(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey13(This,nNewValue)

#define IFCDualJog_get_moveKey14(This,retval)	\
    (This)->lpVtbl -> get_moveKey14(This,retval)

#define IFCDualJog_put_moveKey14(This,nNewValue)	\
    (This)->lpVtbl -> put_moveKey14(This,nNewValue)

#define IFCDualJog_get_m3(This,retval)	\
    (This)->lpVtbl -> get_m3(This,retval)

#define IFCDualJog_put_m3(This,nNewValue)	\
    (This)->lpVtbl -> put_m3(This,nNewValue)

#define IFCDualJog_get_srMinus(This,retval)	\
    (This)->lpVtbl -> get_srMinus(This,retval)

#define IFCDualJog_put_srMinus(This,nNewValue)	\
    (This)->lpVtbl -> put_srMinus(This,nNewValue)

#define IFCDualJog_get_m19(This,retval)	\
    (This)->lpVtbl -> get_m19(This,retval)

#define IFCDualJog_put_m19(This,nNewValue)	\
    (This)->lpVtbl -> put_m19(This,nNewValue)

#define IFCDualJog_get_m5(This,retval)	\
    (This)->lpVtbl -> get_m5(This,retval)

#define IFCDualJog_put_m5(This,nNewValue)	\
    (This)->lpVtbl -> put_m5(This,nNewValue)

#define IFCDualJog_get_srPlus(This,retval)	\
    (This)->lpVtbl -> get_srPlus(This,retval)

#define IFCDualJog_put_srPlus(This,nNewValue)	\
    (This)->lpVtbl -> put_srPlus(This,nNewValue)

#define IFCDualJog_get_m4(This,retval)	\
    (This)->lpVtbl -> get_m4(This,retval)

#define IFCDualJog_put_m4(This,nNewValue)	\
    (This)->lpVtbl -> put_m4(This,nNewValue)

#define IFCDualJog_get_start(This,retval)	\
    (This)->lpVtbl -> get_start(This,retval)

#define IFCDualJog_put_start(This,nNewValue)	\
    (This)->lpVtbl -> put_start(This,nNewValue)

#define IFCDualJog_get_stop(This,retval)	\
    (This)->lpVtbl -> get_stop(This,retval)

#define IFCDualJog_put_stop(This,nNewValue)	\
    (This)->lpVtbl -> put_stop(This,nNewValue)

#define IFCDualJog_get_zero(This,retval)	\
    (This)->lpVtbl -> get_zero(This,retval)

#define IFCDualJog_put_zero(This,nNewValue)	\
    (This)->lpVtbl -> put_zero(This,nNewValue)

#define IFCDualJog_get_singleBlock(This,retval)	\
    (This)->lpVtbl -> get_singleBlock(This,retval)

#define IFCDualJog_put_singleBlock(This,nNewValue)	\
    (This)->lpVtbl -> put_singleBlock(This,nNewValue)

#define IFCDualJog_get_reset(This,retval)	\
    (This)->lpVtbl -> get_reset(This,retval)

#define IFCDualJog_put_reset(This,nNewValue)	\
    (This)->lpVtbl -> put_reset(This,nNewValue)

#define IFCDualJog_get_ovrPos(This,retval)	\
    (This)->lpVtbl -> get_ovrPos(This,retval)

#define IFCDualJog_put_ovrPos(This,nNewValue)	\
    (This)->lpVtbl -> put_ovrPos(This,nNewValue)

#define IFCDualJog_get_manualMode(This,retval)	\
    (This)->lpVtbl -> get_manualMode(This,retval)

#define IFCDualJog_put_manualMode(This,nNewValue)	\
    (This)->lpVtbl -> put_manualMode(This,nNewValue)

#define IFCDualJog_get_activateJog(This,retval)	\
    (This)->lpVtbl -> get_activateJog(This,retval)

#define IFCDualJog_put_activateJog(This,nNewValue)	\
    (This)->lpVtbl -> put_activateJog(This,nNewValue)

#define IFCDualJog_SetJogClient(This)	\
    (This)->lpVtbl -> SetJogClient(This)

#define IFCDualJog_ResetStateJog(This)	\
    (This)->lpVtbl -> ResetStateJog(This)

#define IFCDualJog_ReleaseJogClient(This)	\
    (This)->lpVtbl -> ReleaseJogClient(This)

#define IFCDualJog_ExtendedJogKeyReports(This,bActivate)	\
    (This)->lpVtbl -> ExtendedJogKeyReports(This,bActivate)

#define IFCDualJog_SetJogClient2(This,pSink)	\
    (This)->lpVtbl -> SetJogClient2(This,pSink)

#define IFCDualJog_ReleaseJogClient2(This,pSink)	\
    (This)->lpVtbl -> ReleaseJogClient2(This,pSink)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey1_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey1_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey2_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey2_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey3_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey3_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey4_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey4_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey5_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey5_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey5_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey5_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey6_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey6_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey6_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey6_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey7_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey7_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey7_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey7_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey8_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey8_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey8_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey8_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey9_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey9_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey9_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey9_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey10_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey10_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey10_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey10_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey11_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey11_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey11_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey11_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey12_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey12_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey12_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey12_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey13_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey13_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey13_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey13_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey14_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey14_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey14_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey14_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey15_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey15_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey15_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey15_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_userKey16_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_userKey16_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_userKey16_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_userKey16_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey0_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey0_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey0_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey0_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey1_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey1_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey2_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey2_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey3_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey3_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey4_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey4_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey5_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey5_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey5_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey5_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey6_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey6_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey6_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey6_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey7_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey7_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey7_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey7_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey8_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey8_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey8_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey8_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey9_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey9_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey9_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey9_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey10_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey10_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey10_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey10_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey11_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey11_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey11_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey11_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey12_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey12_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey12_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey12_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey13_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey13_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey13_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey13_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_moveKey14_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_moveKey14_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_moveKey14_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_moveKey14_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_m3_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_m3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_m3_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_m3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_srMinus_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_srMinus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_srMinus_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_srMinus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_m19_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_m19_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_m19_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_m19_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_m5_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_m5_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_m5_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_m5_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_srPlus_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_srPlus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_srPlus_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_srPlus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_m4_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_m4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_m4_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_m4_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_start_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_start_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_stop_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_stop_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_zero_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_zero_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_zero_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_zero_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_singleBlock_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_singleBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_singleBlock_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_singleBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_reset_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_reset_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_ovrPos_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_ovrPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_ovrPos_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_ovrPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_manualMode_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_manualMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_manualMode_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_manualMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IFCDualJog_get_activateJog_Proxy( 
    IFCDualJog * This,
    /* [retval][out] */ short *retval);


void __RPC_STUB IFCDualJog_get_activateJog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IFCDualJog_put_activateJog_Proxy( 
    IFCDualJog * This,
    /* [in] */ short nNewValue);


void __RPC_STUB IFCDualJog_put_activateJog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualJog_SetJogClient_Proxy( 
    IFCDualJog * This);


void __RPC_STUB IFCDualJog_SetJogClient_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualJog_ResetStateJog_Proxy( 
    IFCDualJog * This);


void __RPC_STUB IFCDualJog_ResetStateJog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualJog_ReleaseJogClient_Proxy( 
    IFCDualJog * This);


void __RPC_STUB IFCDualJog_ReleaseJogClient_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualJog_ExtendedJogKeyReports_Proxy( 
    IFCDualJog * This,
    BOOL bActivate);


void __RPC_STUB IFCDualJog_ExtendedJogKeyReports_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualJog_SetJogClient2_Proxy( 
    IFCDualJog * This,
    /* [in] */ IUnknown *pSink);


void __RPC_STUB IFCDualJog_SetJogClient2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualJog_ReleaseJogClient2_Proxy( 
    IFCDualJog * This,
    /* [in] */ IUnknown *pSink);


void __RPC_STUB IFCDualJog_ReleaseJogClient2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualJog_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_Jog,0xE90C1226,0x81CA,0x4F21,0x9B,0x33,0x11,0xED,0x19,0xFA,0xD3,0x8C);

#ifdef __cplusplus

class DECLSPEC_UUID("E90C1226-81CA-4F21-9B33-11ED19FAD38C")
CNC8070_Jog;
#endif

#ifndef __IFCKernelMParam_DISPINTERFACE_DEFINED__
#define __IFCKernelMParam_DISPINTERFACE_DEFINED__

/* dispinterface IFCKernelMParam */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCKernelMParam,0xDAAF6D0E,0x63C3,0x11D5,0x9C,0x5E,0x00,0xC0,0x4F,0xC7,0x04,0xAC);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DAAF6D0E-63C3-11D5-9C5E-00C04FC704AC")
    IFCKernelMParam : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCKernelMParamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCKernelMParam * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCKernelMParam * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCKernelMParam * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCKernelMParam * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCKernelMParam * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCKernelMParam * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCKernelMParam * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCKernelMParamVtbl;

    interface IFCKernelMParam
    {
        CONST_VTBL struct IFCKernelMParamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCKernelMParam_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCKernelMParam_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCKernelMParam_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCKernelMParam_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCKernelMParam_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCKernelMParam_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCKernelMParam_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCKernelMParam_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualKernelMParam_INTERFACE_DEFINED__
#define __IFCDualKernelMParam_INTERFACE_DEFINED__

/* interface IFCDualKernelMParam */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualKernelMParam,0xEA9C9560,0x63F7,0x11d5,0x9C,0x5E,0x00,0xC0,0x4F,0xC7,0x04,0xAC);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EA9C9560-63F7-11d5-9C5E-00C04FC704AC")
    IFCDualKernelMParam : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetLogAxisNum( 
            /* [in] */ short shAxisNum,
            /* [retval][out] */ short *pshLogAxisNum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSlaveAxisLogNum( 
            /* [in] */ short shAxisNum,
            /* [retval][out] */ short *pshSlaveAxisLogNum) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNumAxis( 
            /* [retval][out] */ short *pshNumAxis) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetAxisName( 
            /* [in] */ short shAxisNum,
            /* [retval][out] */ BSTR *pAxisName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualKernelMParamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualKernelMParam * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualKernelMParam * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualKernelMParam * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualKernelMParam * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualKernelMParam * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualKernelMParam * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualKernelMParam * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetLogAxisNum )( 
            IFCDualKernelMParam * This,
            /* [in] */ short shAxisNum,
            /* [retval][out] */ short *pshLogAxisNum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetSlaveAxisLogNum )( 
            IFCDualKernelMParam * This,
            /* [in] */ short shAxisNum,
            /* [retval][out] */ short *pshSlaveAxisLogNum);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNumAxis )( 
            IFCDualKernelMParam * This,
            /* [retval][out] */ short *pshNumAxis);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetAxisName )( 
            IFCDualKernelMParam * This,
            /* [in] */ short shAxisNum,
            /* [retval][out] */ BSTR *pAxisName);
        
        END_INTERFACE
    } IFCDualKernelMParamVtbl;

    interface IFCDualKernelMParam
    {
        CONST_VTBL struct IFCDualKernelMParamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualKernelMParam_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualKernelMParam_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualKernelMParam_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualKernelMParam_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualKernelMParam_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualKernelMParam_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualKernelMParam_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualKernelMParam_GetLogAxisNum(This,shAxisNum,pshLogAxisNum)	\
    (This)->lpVtbl -> GetLogAxisNum(This,shAxisNum,pshLogAxisNum)

#define IFCDualKernelMParam_GetSlaveAxisLogNum(This,shAxisNum,pshSlaveAxisLogNum)	\
    (This)->lpVtbl -> GetSlaveAxisLogNum(This,shAxisNum,pshSlaveAxisLogNum)

#define IFCDualKernelMParam_GetNumAxis(This,pshNumAxis)	\
    (This)->lpVtbl -> GetNumAxis(This,pshNumAxis)

#define IFCDualKernelMParam_GetAxisName(This,shAxisNum,pAxisName)	\
    (This)->lpVtbl -> GetAxisName(This,shAxisNum,pAxisName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernelMParam_GetLogAxisNum_Proxy( 
    IFCDualKernelMParam * This,
    /* [in] */ short shAxisNum,
    /* [retval][out] */ short *pshLogAxisNum);


void __RPC_STUB IFCDualKernelMParam_GetLogAxisNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernelMParam_GetSlaveAxisLogNum_Proxy( 
    IFCDualKernelMParam * This,
    /* [in] */ short shAxisNum,
    /* [retval][out] */ short *pshSlaveAxisLogNum);


void __RPC_STUB IFCDualKernelMParam_GetSlaveAxisLogNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernelMParam_GetNumAxis_Proxy( 
    IFCDualKernelMParam * This,
    /* [retval][out] */ short *pshNumAxis);


void __RPC_STUB IFCDualKernelMParam_GetNumAxis_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKernelMParam_GetAxisName_Proxy( 
    IFCDualKernelMParam * This,
    /* [in] */ short shAxisNum,
    /* [retval][out] */ BSTR *pAxisName);


void __RPC_STUB IFCDualKernelMParam_GetAxisName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualKernelMParam_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_KernelMParam,0xDAAF6D0F,0x63C3,0x11D5,0x9C,0x5E,0x00,0xC0,0x4F,0xC7,0x04,0xAC);

#ifdef __cplusplus

class DECLSPEC_UUID("DAAF6D0F-63C3-11D5-9C5E-00C04FC704AC")
CNC8070_KernelMParam;
#endif

#ifndef __IFCOpcServer_DISPINTERFACE_DEFINED__
#define __IFCOpcServer_DISPINTERFACE_DEFINED__

/* dispinterface IFCOpcServer */
/* [hidden][uuid] */ 


DEFINE_GUID(DIID_IFCOpcServer,0x625C5E2B,0x72B7,0x4CDF,0x99,0xCB,0xDA,0x93,0x09,0x28,0x4A,0x39);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("625C5E2B-72B7-4CDF-99CB-DA9309284A39")
    IFCOpcServer : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCOpcServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCOpcServer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCOpcServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCOpcServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCOpcServer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCOpcServer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCOpcServer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCOpcServer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCOpcServerVtbl;

    interface IFCOpcServer
    {
        CONST_VTBL struct IFCOpcServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCOpcServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCOpcServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCOpcServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCOpcServer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCOpcServer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCOpcServer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCOpcServer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCOpcServer_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualOpcServer_INTERFACE_DEFINED__
#define __IFCDualOpcServer_INTERFACE_DEFINED__

/* interface IFCDualOpcServer */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualOpcServer,0x7FDE89D8,0x8D82,0x48bd,0x99,0xDA,0x3F,0xBE,0x23,0x3D,0xA4,0xA2);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7FDE89D8-8D82-48bd-99DA-3FBE233DA4A2")
    IFCDualOpcServer : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE start( 
            /* [retval][out] */ BOOL *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE stop( 
            /* [retval][out] */ BOOL *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualOpcServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualOpcServer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualOpcServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualOpcServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualOpcServer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualOpcServer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualOpcServer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualOpcServer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *start )( 
            IFCDualOpcServer * This,
            /* [retval][out] */ BOOL *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *stop )( 
            IFCDualOpcServer * This,
            /* [retval][out] */ BOOL *retval);
        
        END_INTERFACE
    } IFCDualOpcServerVtbl;

    interface IFCDualOpcServer
    {
        CONST_VTBL struct IFCDualOpcServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualOpcServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualOpcServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualOpcServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualOpcServer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualOpcServer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualOpcServer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualOpcServer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualOpcServer_start(This,retval)	\
    (This)->lpVtbl -> start(This,retval)

#define IFCDualOpcServer_stop(This,retval)	\
    (This)->lpVtbl -> stop(This,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOpcServer_start_Proxy( 
    IFCDualOpcServer * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualOpcServer_start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOpcServer_stop_Proxy( 
    IFCDualOpcServer * This,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualOpcServer_stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualOpcServer_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_OpcServer,0xF3B5732F,0x351C,0x4AA5,0xBE,0xA9,0x9C,0xB1,0xE2,0x01,0x63,0x3A);

#ifdef __cplusplus

class DECLSPEC_UUID("F3B5732F-351C-4AA5-BEA9-9CB1E201633A")
CNC8070_OpcServer;
#endif

#ifndef __IFCSintaxFun_DISPINTERFACE_DEFINED__
#define __IFCSintaxFun_DISPINTERFACE_DEFINED__

/* dispinterface IFCSintaxFun */
/* [uuid] */ 


DEFINE_GUID(DIID_IFCSintaxFun,0xE5C18C20,0xC0C7,0x11D6,0x8B,0x08,0x00,0xB0,0xD0,0xD6,0x7E,0x96);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E5C18C20-C0C7-11D6-8B08-00B0D0D67E96")
    IFCSintaxFun : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCSintaxFunVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCSintaxFun * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCSintaxFun * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCSintaxFun * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCSintaxFun * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCSintaxFun * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCSintaxFun * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCSintaxFun * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCSintaxFunVtbl;

    interface IFCSintaxFun
    {
        CONST_VTBL struct IFCSintaxFunVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCSintaxFun_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCSintaxFun_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCSintaxFun_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCSintaxFun_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCSintaxFun_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCSintaxFun_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCSintaxFun_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCSintaxFun_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualSintaxFun_INTERFACE_DEFINED__
#define __IFCDualSintaxFun_INTERFACE_DEFINED__

/* interface IFCDualSintaxFun */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualSintaxFun,0x501D2861,0xC0DA,0x11d6,0x8B,0x08,0x00,0xB0,0xD0,0xD6,0x7E,0x96);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("501D2861-C0DA-11d6-8B08-00B0D0D67E96")
    IFCDualSintaxFun : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCNCHlpFileName( 
            /* [in] */ BSTR sTxtLine,
            int nCursorPos,
            /* [retval][out] */ BSTR *pHlpFileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualSintaxFunVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualSintaxFun * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualSintaxFun * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualSintaxFun * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualSintaxFun * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualSintaxFun * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualSintaxFun * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualSintaxFun * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetCNCHlpFileName )( 
            IFCDualSintaxFun * This,
            /* [in] */ BSTR sTxtLine,
            int nCursorPos,
            /* [retval][out] */ BSTR *pHlpFileName);
        
        END_INTERFACE
    } IFCDualSintaxFunVtbl;

    interface IFCDualSintaxFun
    {
        CONST_VTBL struct IFCDualSintaxFunVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualSintaxFun_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualSintaxFun_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualSintaxFun_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualSintaxFun_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualSintaxFun_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualSintaxFun_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualSintaxFun_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualSintaxFun_GetCNCHlpFileName(This,sTxtLine,nCursorPos,pHlpFileName)	\
    (This)->lpVtbl -> GetCNCHlpFileName(This,sTxtLine,nCursorPos,pHlpFileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualSintaxFun_GetCNCHlpFileName_Proxy( 
    IFCDualSintaxFun * This,
    /* [in] */ BSTR sTxtLine,
    int nCursorPos,
    /* [retval][out] */ BSTR *pHlpFileName);


void __RPC_STUB IFCDualSintaxFun_GetCNCHlpFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualSintaxFun_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_SintaxFun,0xE5C18C21,0xC0C7,0x11D6,0x8B,0x08,0x00,0xB0,0xD0,0xD6,0x7E,0x96);

#ifdef __cplusplus

class DECLSPEC_UUID("E5C18C21-C0C7-11D6-8B08-00B0D0D67E96")
CNC8070_SintaxFun;
#endif

#ifndef __IFCOsc8070_DISPINTERFACE_DEFINED__
#define __IFCOsc8070_DISPINTERFACE_DEFINED__

/* dispinterface IFCOsc8070 */
/* [uuid] */ 


DEFINE_GUID(DIID_IFCOsc8070,0x52659342,0x8070,0x11d7,0xB3,0x0D,0x00,0x30,0x05,0x2E,0xEA,0x1B);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("52659342-8070-11d7-B30D-0030052EEA1B")
    IFCOsc8070 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCOsc8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCOsc8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCOsc8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCOsc8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCOsc8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCOsc8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCOsc8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCOsc8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCOsc8070Vtbl;

    interface IFCOsc8070
    {
        CONST_VTBL struct IFCOsc8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCOsc8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCOsc8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCOsc8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCOsc8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCOsc8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCOsc8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCOsc8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCOsc8070_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualOsc8070_INTERFACE_DEFINED__
#define __IFCDualOsc8070_INTERFACE_DEFINED__

/* interface IFCDualOsc8070 */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualOsc8070,0x6E892261,0x807C,0x11d7,0xB3,0x0D,0x00,0x30,0x05,0x2E,0xEA,0x1B);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E892261-807C-11d7-B30D-0030052EEA1B")
    IFCDualOsc8070 : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_CrearEstructuraTraza( 
            /* [retval][out] */ long *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_LiberarEstructuraTraza( 
            /* [retval][out] */ long *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_VarClear( 
            /* [in] */ long canal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TriggerHabilitar( 
            /* [retval][out] */ long *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TriggerDeshabilitar( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TriggerEstado( 
            /* [retval][out] */ long *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TriggerCanalSet( 
            /* [in] */ long canal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TriggerCanalGet( 
            /* [retval][out] */ long *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TriggerFlancoSet( 
            /* [in] */ TIPOFLANCO_T flanco) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TriggerFlancoGet( 
            /* [retval][out] */ TIPOFLANCO_T *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TriggerNivelSet( 
            /* [in] */ double nivel) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TriggerNivelGet( 
            /* [retval][out] */ double *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TriggerPosicionSet( 
            /* [in] */ long posicion) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TriggerPosicionGet( 
            /* [retval][out] */ long *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_NMuestrasSet( 
            /* [in] */ long nMuestras) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_NMuestrasGet( 
            /* [retval][out] */ long *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_NMuestrasRealGet( 
            /* [retval][out] */ long *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TMuestreoSet( 
            /* [in] */ long tMuestreo) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TMuestreoGet( 
            /* [retval][out] */ long *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TMuestreoRealGet( 
            /* [retval][out] */ long *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TrazaStart( 
            /* [retval][out] */ long *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TrazaStop( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_DataGet( 
            /* [in] */ long nCanal,
            /* [in] */ long index,
            /* [retval][out] */ double *retVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_DataMinMaxGet( 
            /* [in] */ long nCanal,
            /* [out] */ double *pMin,
            /* [out] */ double *pMax) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OSC_TrazaIsStarted( 
            /* [retval][out] */ short *retVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualOsc8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualOsc8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualOsc8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualOsc8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualOsc8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualOsc8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualOsc8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualOsc8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_CrearEstructuraTraza )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ long *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_LiberarEstructuraTraza )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ long *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_VarClear )( 
            IFCDualOsc8070 * This,
            /* [in] */ long canal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TriggerHabilitar )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ long *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TriggerDeshabilitar )( 
            IFCDualOsc8070 * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TriggerEstado )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ long *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TriggerCanalSet )( 
            IFCDualOsc8070 * This,
            /* [in] */ long canal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TriggerCanalGet )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ long *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TriggerFlancoSet )( 
            IFCDualOsc8070 * This,
            /* [in] */ TIPOFLANCO_T flanco);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TriggerFlancoGet )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ TIPOFLANCO_T *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TriggerNivelSet )( 
            IFCDualOsc8070 * This,
            /* [in] */ double nivel);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TriggerNivelGet )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ double *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TriggerPosicionSet )( 
            IFCDualOsc8070 * This,
            /* [in] */ long posicion);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TriggerPosicionGet )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ long *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_NMuestrasSet )( 
            IFCDualOsc8070 * This,
            /* [in] */ long nMuestras);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_NMuestrasGet )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ long *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_NMuestrasRealGet )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ long *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TMuestreoSet )( 
            IFCDualOsc8070 * This,
            /* [in] */ long tMuestreo);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TMuestreoGet )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ long *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TMuestreoRealGet )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ long *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TrazaStart )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ long *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TrazaStop )( 
            IFCDualOsc8070 * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_DataGet )( 
            IFCDualOsc8070 * This,
            /* [in] */ long nCanal,
            /* [in] */ long index,
            /* [retval][out] */ double *retVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_DataMinMaxGet )( 
            IFCDualOsc8070 * This,
            /* [in] */ long nCanal,
            /* [out] */ double *pMin,
            /* [out] */ double *pMax);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *OSC_TrazaIsStarted )( 
            IFCDualOsc8070 * This,
            /* [retval][out] */ short *retVal);
        
        END_INTERFACE
    } IFCDualOsc8070Vtbl;

    interface IFCDualOsc8070
    {
        CONST_VTBL struct IFCDualOsc8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualOsc8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualOsc8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualOsc8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualOsc8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualOsc8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualOsc8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualOsc8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualOsc8070_OSC_CrearEstructuraTraza(This,retVal)	\
    (This)->lpVtbl -> OSC_CrearEstructuraTraza(This,retVal)

#define IFCDualOsc8070_OSC_LiberarEstructuraTraza(This,retVal)	\
    (This)->lpVtbl -> OSC_LiberarEstructuraTraza(This,retVal)

#define IFCDualOsc8070_OSC_VarClear(This,canal)	\
    (This)->lpVtbl -> OSC_VarClear(This,canal)

#define IFCDualOsc8070_OSC_TriggerHabilitar(This,retVal)	\
    (This)->lpVtbl -> OSC_TriggerHabilitar(This,retVal)

#define IFCDualOsc8070_OSC_TriggerDeshabilitar(This)	\
    (This)->lpVtbl -> OSC_TriggerDeshabilitar(This)

#define IFCDualOsc8070_OSC_TriggerEstado(This,retVal)	\
    (This)->lpVtbl -> OSC_TriggerEstado(This,retVal)

#define IFCDualOsc8070_OSC_TriggerCanalSet(This,canal)	\
    (This)->lpVtbl -> OSC_TriggerCanalSet(This,canal)

#define IFCDualOsc8070_OSC_TriggerCanalGet(This,retVal)	\
    (This)->lpVtbl -> OSC_TriggerCanalGet(This,retVal)

#define IFCDualOsc8070_OSC_TriggerFlancoSet(This,flanco)	\
    (This)->lpVtbl -> OSC_TriggerFlancoSet(This,flanco)

#define IFCDualOsc8070_OSC_TriggerFlancoGet(This,retVal)	\
    (This)->lpVtbl -> OSC_TriggerFlancoGet(This,retVal)

#define IFCDualOsc8070_OSC_TriggerNivelSet(This,nivel)	\
    (This)->lpVtbl -> OSC_TriggerNivelSet(This,nivel)

#define IFCDualOsc8070_OSC_TriggerNivelGet(This,retVal)	\
    (This)->lpVtbl -> OSC_TriggerNivelGet(This,retVal)

#define IFCDualOsc8070_OSC_TriggerPosicionSet(This,posicion)	\
    (This)->lpVtbl -> OSC_TriggerPosicionSet(This,posicion)

#define IFCDualOsc8070_OSC_TriggerPosicionGet(This,retVal)	\
    (This)->lpVtbl -> OSC_TriggerPosicionGet(This,retVal)

#define IFCDualOsc8070_OSC_NMuestrasSet(This,nMuestras)	\
    (This)->lpVtbl -> OSC_NMuestrasSet(This,nMuestras)

#define IFCDualOsc8070_OSC_NMuestrasGet(This,retVal)	\
    (This)->lpVtbl -> OSC_NMuestrasGet(This,retVal)

#define IFCDualOsc8070_OSC_NMuestrasRealGet(This,retVal)	\
    (This)->lpVtbl -> OSC_NMuestrasRealGet(This,retVal)

#define IFCDualOsc8070_OSC_TMuestreoSet(This,tMuestreo)	\
    (This)->lpVtbl -> OSC_TMuestreoSet(This,tMuestreo)

#define IFCDualOsc8070_OSC_TMuestreoGet(This,retVal)	\
    (This)->lpVtbl -> OSC_TMuestreoGet(This,retVal)

#define IFCDualOsc8070_OSC_TMuestreoRealGet(This,retVal)	\
    (This)->lpVtbl -> OSC_TMuestreoRealGet(This,retVal)

#define IFCDualOsc8070_OSC_TrazaStart(This,retVal)	\
    (This)->lpVtbl -> OSC_TrazaStart(This,retVal)

#define IFCDualOsc8070_OSC_TrazaStop(This)	\
    (This)->lpVtbl -> OSC_TrazaStop(This)

#define IFCDualOsc8070_OSC_DataGet(This,nCanal,index,retVal)	\
    (This)->lpVtbl -> OSC_DataGet(This,nCanal,index,retVal)

#define IFCDualOsc8070_OSC_DataMinMaxGet(This,nCanal,pMin,pMax)	\
    (This)->lpVtbl -> OSC_DataMinMaxGet(This,nCanal,pMin,pMax)

#define IFCDualOsc8070_OSC_TrazaIsStarted(This,retVal)	\
    (This)->lpVtbl -> OSC_TrazaIsStarted(This,retVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_CrearEstructuraTraza_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ long *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_CrearEstructuraTraza_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_LiberarEstructuraTraza_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ long *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_LiberarEstructuraTraza_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_VarClear_Proxy( 
    IFCDualOsc8070 * This,
    /* [in] */ long canal);


void __RPC_STUB IFCDualOsc8070_OSC_VarClear_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TriggerHabilitar_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ long *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_TriggerHabilitar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TriggerDeshabilitar_Proxy( 
    IFCDualOsc8070 * This);


void __RPC_STUB IFCDualOsc8070_OSC_TriggerDeshabilitar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TriggerEstado_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ long *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_TriggerEstado_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TriggerCanalSet_Proxy( 
    IFCDualOsc8070 * This,
    /* [in] */ long canal);


void __RPC_STUB IFCDualOsc8070_OSC_TriggerCanalSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TriggerCanalGet_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ long *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_TriggerCanalGet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TriggerFlancoSet_Proxy( 
    IFCDualOsc8070 * This,
    /* [in] */ TIPOFLANCO_T flanco);


void __RPC_STUB IFCDualOsc8070_OSC_TriggerFlancoSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TriggerFlancoGet_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ TIPOFLANCO_T *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_TriggerFlancoGet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TriggerNivelSet_Proxy( 
    IFCDualOsc8070 * This,
    /* [in] */ double nivel);


void __RPC_STUB IFCDualOsc8070_OSC_TriggerNivelSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TriggerNivelGet_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ double *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_TriggerNivelGet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TriggerPosicionSet_Proxy( 
    IFCDualOsc8070 * This,
    /* [in] */ long posicion);


void __RPC_STUB IFCDualOsc8070_OSC_TriggerPosicionSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TriggerPosicionGet_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ long *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_TriggerPosicionGet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_NMuestrasSet_Proxy( 
    IFCDualOsc8070 * This,
    /* [in] */ long nMuestras);


void __RPC_STUB IFCDualOsc8070_OSC_NMuestrasSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_NMuestrasGet_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ long *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_NMuestrasGet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_NMuestrasRealGet_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ long *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_NMuestrasRealGet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TMuestreoSet_Proxy( 
    IFCDualOsc8070 * This,
    /* [in] */ long tMuestreo);


void __RPC_STUB IFCDualOsc8070_OSC_TMuestreoSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TMuestreoGet_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ long *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_TMuestreoGet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TMuestreoRealGet_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ long *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_TMuestreoRealGet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TrazaStart_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ long *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_TrazaStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TrazaStop_Proxy( 
    IFCDualOsc8070 * This);


void __RPC_STUB IFCDualOsc8070_OSC_TrazaStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_DataGet_Proxy( 
    IFCDualOsc8070 * This,
    /* [in] */ long nCanal,
    /* [in] */ long index,
    /* [retval][out] */ double *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_DataGet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_DataMinMaxGet_Proxy( 
    IFCDualOsc8070 * This,
    /* [in] */ long nCanal,
    /* [out] */ double *pMin,
    /* [out] */ double *pMax);


void __RPC_STUB IFCDualOsc8070_OSC_DataMinMaxGet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualOsc8070_OSC_TrazaIsStarted_Proxy( 
    IFCDualOsc8070 * This,
    /* [retval][out] */ short *retVal);


void __RPC_STUB IFCDualOsc8070_OSC_TrazaIsStarted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualOsc8070_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_Oscilloscope,0xA23B1505,0x807C,0x11d7,0xB3,0x0D,0x00,0x30,0x05,0x2E,0xEA,0x1B);

#ifdef __cplusplus

class DECLSPEC_UUID("A23B1505-807C-11d7-B30D-0030052EEA1B")
CNC8070_Oscilloscope;
#endif

#ifndef __IFCRemoteVar8070_DISPINTERFACE_DEFINED__
#define __IFCRemoteVar8070_DISPINTERFACE_DEFINED__

/* dispinterface IFCRemoteVar8070 */
/* [uuid] */ 


DEFINE_GUID(DIID_IFCRemoteVar8070,0xAA76E9C3,0x2250,0x4FDE,0x8A,0xE2,0x55,0x85,0x8C,0x84,0xC4,0xAD);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AA76E9C3-2250-4FDE-8AE2-55858C84C4AD")
    IFCRemoteVar8070 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCRemoteVar8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCRemoteVar8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCRemoteVar8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCRemoteVar8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCRemoteVar8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCRemoteVar8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCRemoteVar8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCRemoteVar8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCRemoteVar8070Vtbl;

    interface IFCRemoteVar8070
    {
        CONST_VTBL struct IFCRemoteVar8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCRemoteVar8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCRemoteVar8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCRemoteVar8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCRemoteVar8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCRemoteVar8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCRemoteVar8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCRemoteVar8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCRemoteVar8070_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualRemoteVar8070_INTERFACE_DEFINED__
#define __IFCDualRemoteVar8070_INTERFACE_DEFINED__

/* interface IFCDualRemoteVar8070 */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualRemoteVar8070,0x42BDA7F8,0x86E5,0x4d6f,0x9F,0xB8,0x15,0x8C,0x0F,0xB2,0x4B,0x98);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("42BDA7F8-86E5-4d6f-9FB8-158C0FB24B98")
    IFCDualRemoteVar8070 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenVariable( 
            /* [in] */ BSTR nameserver,
            /* [in] */ BSTR namevar,
            /* [retval][out] */ HVAR *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadIntArray( 
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteIntArray( 
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadDoubleArray( 
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteDoubleArray( 
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseVariable( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE CloseRemoteServer( 
            /* [in] */ BSTR nameserver,
            /* [in] */ long bOnlyVarsConnected,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE CloseRemoteServerUnico( 
            /* [in] */ BSTR nameserver,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE AddServerConectado( 
            /* [in] */ BSTR nameserver) = 0;
        
        virtual /* [hidden][id] */ HRESULT STDMETHODCALLTYPE DeleteServerConectado( 
            /* [in] */ BSTR nameserver) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReadVarArray( 
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WriteVarArray( 
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsWritable( 
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualRemoteVar8070Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualRemoteVar8070 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualRemoteVar8070 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualRemoteVar8070 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenVariable )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ BSTR nameserver,
            /* [in] */ BSTR namevar,
            /* [retval][out] */ HVAR *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadIntArray )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteIntArray )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadDoubleArray )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteDoubleArray )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseVariable )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ long *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *CloseRemoteServer )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ BSTR nameserver,
            /* [in] */ long bOnlyVarsConnected,
            /* [retval][out] */ long *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *CloseRemoteServerUnico )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ BSTR nameserver,
            /* [retval][out] */ long *retval);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *AddServerConectado )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ BSTR nameserver);
        
        /* [hidden][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteServerConectado )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ BSTR nameserver);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReadVarArray )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [out][in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *WriteVarArray )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ VARIANT *idArray,
            /* [in] */ VARIANT *valueArray,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsWritable )( 
            IFCDualRemoteVar8070 * This,
            /* [in] */ HVAR h_var,
            /* [retval][out] */ BOOL *retval);
        
        END_INTERFACE
    } IFCDualRemoteVar8070Vtbl;

    interface IFCDualRemoteVar8070
    {
        CONST_VTBL struct IFCDualRemoteVar8070Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualRemoteVar8070_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualRemoteVar8070_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualRemoteVar8070_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualRemoteVar8070_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualRemoteVar8070_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualRemoteVar8070_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualRemoteVar8070_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualRemoteVar8070_OpenVariable(This,nameserver,namevar,retval)	\
    (This)->lpVtbl -> OpenVariable(This,nameserver,namevar,retval)

#define IFCDualRemoteVar8070_ReadIntArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> ReadIntArray(This,idArray,valueArray,retval)

#define IFCDualRemoteVar8070_WriteIntArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> WriteIntArray(This,idArray,valueArray,retval)

#define IFCDualRemoteVar8070_ReadDoubleArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> ReadDoubleArray(This,idArray,valueArray,retval)

#define IFCDualRemoteVar8070_WriteDoubleArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> WriteDoubleArray(This,idArray,valueArray,retval)

#define IFCDualRemoteVar8070_CloseVariable(This,h_var,retval)	\
    (This)->lpVtbl -> CloseVariable(This,h_var,retval)

#define IFCDualRemoteVar8070_CloseRemoteServer(This,nameserver,bOnlyVarsConnected,retval)	\
    (This)->lpVtbl -> CloseRemoteServer(This,nameserver,bOnlyVarsConnected,retval)

#define IFCDualRemoteVar8070_CloseRemoteServerUnico(This,nameserver,retval)	\
    (This)->lpVtbl -> CloseRemoteServerUnico(This,nameserver,retval)

#define IFCDualRemoteVar8070_AddServerConectado(This,nameserver)	\
    (This)->lpVtbl -> AddServerConectado(This,nameserver)

#define IFCDualRemoteVar8070_DeleteServerConectado(This,nameserver)	\
    (This)->lpVtbl -> DeleteServerConectado(This,nameserver)

#define IFCDualRemoteVar8070_ReadVarArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> ReadVarArray(This,idArray,valueArray,retval)

#define IFCDualRemoteVar8070_WriteVarArray(This,idArray,valueArray,retval)	\
    (This)->lpVtbl -> WriteVarArray(This,idArray,valueArray,retval)

#define IFCDualRemoteVar8070_IsWritable(This,h_var,retval)	\
    (This)->lpVtbl -> IsWritable(This,h_var,retval)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_OpenVariable_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ BSTR nameserver,
    /* [in] */ BSTR namevar,
    /* [retval][out] */ HVAR *retval);


void __RPC_STUB IFCDualRemoteVar8070_OpenVariable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_ReadIntArray_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [out][in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualRemoteVar8070_ReadIntArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_WriteIntArray_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualRemoteVar8070_WriteIntArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_ReadDoubleArray_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [out][in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualRemoteVar8070_ReadDoubleArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_WriteDoubleArray_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualRemoteVar8070_WriteDoubleArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_CloseVariable_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualRemoteVar8070_CloseVariable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_CloseRemoteServer_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ BSTR nameserver,
    /* [in] */ long bOnlyVarsConnected,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualRemoteVar8070_CloseRemoteServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_CloseRemoteServerUnico_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ BSTR nameserver,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualRemoteVar8070_CloseRemoteServerUnico_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_AddServerConectado_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ BSTR nameserver);


void __RPC_STUB IFCDualRemoteVar8070_AddServerConectado_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [hidden][id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_DeleteServerConectado_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ BSTR nameserver);


void __RPC_STUB IFCDualRemoteVar8070_DeleteServerConectado_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_ReadVarArray_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [out][in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualRemoteVar8070_ReadVarArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_WriteVarArray_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ VARIANT *idArray,
    /* [in] */ VARIANT *valueArray,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualRemoteVar8070_WriteVarArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualRemoteVar8070_IsWritable_Proxy( 
    IFCDualRemoteVar8070 * This,
    /* [in] */ HVAR h_var,
    /* [retval][out] */ BOOL *retval);


void __RPC_STUB IFCDualRemoteVar8070_IsWritable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualRemoteVar8070_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_RemoteVariables,0x1BDFC86A,0x1ED5,0x454F,0xB0,0x8E,0x5F,0xF8,0xC4,0x40,0x05,0xA3);

#ifdef __cplusplus

class DECLSPEC_UUID("1BDFC86A-1ED5-454F-B08E-5FF8C44005A3")
CNC8070_RemoteVariables;
#endif

#ifndef __IFCHelpEditctrl_DISPINTERFACE_DEFINED__
#define __IFCHelpEditctrl_DISPINTERFACE_DEFINED__

/* dispinterface IFCHelpEditctrl */
/* [uuid] */ 


DEFINE_GUID(DIID_IFCHelpEditctrl,0x84270E91,0xE5D5,0x4687,0xBA,0x37,0x3F,0xE1,0xEB,0x69,0x06,0x1D);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("84270E91-E5D5-4687-BA37-3FE1EB69061D")
    IFCHelpEditctrl : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCHelpEditctrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCHelpEditctrl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCHelpEditctrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCHelpEditctrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCHelpEditctrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCHelpEditctrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCHelpEditctrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCHelpEditctrl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCHelpEditctrlVtbl;

    interface IFCHelpEditctrl
    {
        CONST_VTBL struct IFCHelpEditctrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCHelpEditctrl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCHelpEditctrl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCHelpEditctrl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCHelpEditctrl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCHelpEditctrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCHelpEditctrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCHelpEditctrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCHelpEditctrl_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualHelpEditctrl_INTERFACE_DEFINED__
#define __IFCDualHelpEditctrl_INTERFACE_DEFINED__

/* interface IFCDualHelpEditctrl */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualHelpEditctrl,0x1E09A328,0x92C0,0x4ea4,0xA1,0x81,0x4F,0xE4,0xB3,0x1C,0xE0,0x96);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1E09A328-92C0-4ea4-A181-4FE4B31CE096")
    IFCDualHelpEditctrl : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetSentenceList( 
            /* [retval][out] */ BSTR *pSentenceList) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFlowControlList( 
            /* [retval][out] */ BSTR *pFlowControlList) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualHelpEditctrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualHelpEditctrl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualHelpEditctrl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualHelpEditctrl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualHelpEditctrl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualHelpEditctrl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualHelpEditctrl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualHelpEditctrl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetSentenceList )( 
            IFCDualHelpEditctrl * This,
            /* [retval][out] */ BSTR *pSentenceList);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFlowControlList )( 
            IFCDualHelpEditctrl * This,
            /* [retval][out] */ BSTR *pFlowControlList);
        
        END_INTERFACE
    } IFCDualHelpEditctrlVtbl;

    interface IFCDualHelpEditctrl
    {
        CONST_VTBL struct IFCDualHelpEditctrlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualHelpEditctrl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualHelpEditctrl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualHelpEditctrl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualHelpEditctrl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualHelpEditctrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualHelpEditctrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualHelpEditctrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualHelpEditctrl_GetSentenceList(This,pSentenceList)	\
    (This)->lpVtbl -> GetSentenceList(This,pSentenceList)

#define IFCDualHelpEditctrl_GetFlowControlList(This,pFlowControlList)	\
    (This)->lpVtbl -> GetFlowControlList(This,pFlowControlList)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualHelpEditctrl_GetSentenceList_Proxy( 
    IFCDualHelpEditctrl * This,
    /* [retval][out] */ BSTR *pSentenceList);


void __RPC_STUB IFCDualHelpEditctrl_GetSentenceList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualHelpEditctrl_GetFlowControlList_Proxy( 
    IFCDualHelpEditctrl * This,
    /* [retval][out] */ BSTR *pFlowControlList);


void __RPC_STUB IFCDualHelpEditctrl_GetFlowControlList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualHelpEditctrl_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_HelpEditctrl,0x97B73007,0x0827,0x498d,0xB7,0x29,0x02,0x2B,0x3A,0xAC,0x41,0x87);

#ifdef __cplusplus

class DECLSPEC_UUID("97B73007-0827-498d-B729-022B3AAC4187")
CNC8070_HelpEditctrl;
#endif

#ifndef __IFCKeystrokeEngine_DISPINTERFACE_DEFINED__
#define __IFCKeystrokeEngine_DISPINTERFACE_DEFINED__

/* dispinterface IFCKeystrokeEngine */
/* [uuid] */ 


DEFINE_GUID(DIID_IFCKeystrokeEngine,0x9E846BAA,0x4FC1,0x4ff5,0x8D,0x42,0xD7,0x83,0xAB,0x99,0x9A,0x64);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9E846BAA-4FC1-4ff5-8D42-D783AB999A64")
    IFCKeystrokeEngine : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCKeystrokeEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCKeystrokeEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCKeystrokeEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCKeystrokeEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCKeystrokeEngine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCKeystrokeEngine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCKeystrokeEngine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCKeystrokeEngine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCKeystrokeEngineVtbl;

    interface IFCKeystrokeEngine
    {
        CONST_VTBL struct IFCKeystrokeEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCKeystrokeEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCKeystrokeEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCKeystrokeEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCKeystrokeEngine_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCKeystrokeEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCKeystrokeEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCKeystrokeEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCKeystrokeEngine_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualKeystrokeEngine_INTERFACE_DEFINED__
#define __IFCDualKeystrokeEngine_INTERFACE_DEFINED__

/* interface IFCDualKeystrokeEngine */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualKeystrokeEngine,0xE111A1D6,0x68FA,0x407a,0x86,0xAC,0xDB,0xA3,0xA0,0xF3,0x3A,0x60);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E111A1D6-68FA-407a-86AC-DBA3A0F33A60")
    IFCDualKeystrokeEngine : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SendKeys( 
            /* [in] */ BSTR sKeys) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualKeystrokeEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualKeystrokeEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualKeystrokeEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualKeystrokeEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualKeystrokeEngine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualKeystrokeEngine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualKeystrokeEngine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualKeystrokeEngine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SendKeys )( 
            IFCDualKeystrokeEngine * This,
            /* [in] */ BSTR sKeys);
        
        END_INTERFACE
    } IFCDualKeystrokeEngineVtbl;

    interface IFCDualKeystrokeEngine
    {
        CONST_VTBL struct IFCDualKeystrokeEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualKeystrokeEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualKeystrokeEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualKeystrokeEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualKeystrokeEngine_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualKeystrokeEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualKeystrokeEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualKeystrokeEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualKeystrokeEngine_SendKeys(This,sKeys)	\
    (This)->lpVtbl -> SendKeys(This,sKeys)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IFCDualKeystrokeEngine_SendKeys_Proxy( 
    IFCDualKeystrokeEngine * This,
    /* [in] */ BSTR sKeys);


void __RPC_STUB IFCDualKeystrokeEngine_SendKeys_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualKeystrokeEngine_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_KeystrokeEngine,0xDBAEE442,0xC2E5,0x45da,0x81,0x86,0xD0,0xCE,0x8A,0x25,0xBB,0xB3);

#ifdef __cplusplus

class DECLSPEC_UUID("DBAEE442-C2E5-45da-8186-D0CE8A25BBB3")
CNC8070_KeystrokeEngine;
#endif

#ifndef __IFCAutoAdjust_DISPINTERFACE_DEFINED__
#define __IFCAutoAdjust_DISPINTERFACE_DEFINED__

/* dispinterface IFCAutoAdjust */
/* [uuid] */ 


DEFINE_GUID(DIID_IFCAutoAdjust,0xFB1C62DB,0x5B4B,0x4472,0xB5,0x18,0x78,0xD6,0xAA,0xE2,0x57,0x36);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("FB1C62DB-5B4B-4472-B518-78D6AAE25736")
    IFCAutoAdjust : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCAutoAdjustVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCAutoAdjust * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCAutoAdjust * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCAutoAdjust * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCAutoAdjust * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCAutoAdjust * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCAutoAdjust * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCAutoAdjust * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCAutoAdjustVtbl;

    interface IFCAutoAdjust
    {
        CONST_VTBL struct IFCAutoAdjustVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCAutoAdjust_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCAutoAdjust_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCAutoAdjust_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCAutoAdjust_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCAutoAdjust_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCAutoAdjust_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCAutoAdjust_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCAutoAdjust_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualAutoAdjust_INTERFACE_DEFINED__
#define __IFCDualAutoAdjust_INTERFACE_DEFINED__

/* interface IFCDualAutoAdjust */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualAutoAdjust,0x6AF656DD,0x832F,0x4ab8,0x82,0xBB,0x07,0x4B,0x0C,0x01,0xC6,0xDF);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6AF656DD-832F-4ab8-82BB-074B0C01C6DF")
    IFCDualAutoAdjust : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LeerPM( 
            /* [in] */ BSTR namevar,
            /* [retval][out] */ BSTR *valor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EscribirPM( 
            /* [in] */ BSTR namevar,
            /* [in] */ BSTR valor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RestaurarPM( 
            /* [in] */ BSTR namevar,
            /* [retval][out] */ BSTR *valor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ValidarPM( 
            /* [in] */ BSTR namevar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LeerVSercos_BYTE( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [retval][out] */ BYTE *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LeerVSercos_WORD( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [retval][out] */ WORD *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LeerVSercos_LONG( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [retval][out] */ LONG *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LeerVSercos_STRING( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [retval][out] */ BSTR *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EscribirVSercos_BYTE( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [in] */ BYTE value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EscribirVSercos_WORD( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [in] */ WORD value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EscribirVSercos_LONG( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [in] */ LONG value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EscribirVSercos_STRING( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [in] */ BSTR value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetSercos( 
            /* [in] */ USHORT logAxisNr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EjecutarComandoSercos( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ConfigurarCaptura( 
            /* [in] */ BSTR variable1,
            /* [in] */ BSTR variable2,
            /* [in] */ BSTR variable3,
            /* [in] */ BSTR variable4,
            /* [in] */ USHORT nMuestras,
            /* [in] */ UINT tMuestreo,
            /* [in] */ BOOL bTrigger,
            /* [in] */ USHORT canal,
            /* [in] */ USHORT flanco,
            /* [in] */ double nivel,
            /* [in] */ USHORT posicion) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Capturar( 
            /* [in] */ BSTR output,
            /* [defaultvalue][optional][in] */ BOOL bForzarCaptura = TRUE) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DetenerCaptura( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EstadoCaptura( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VSercos_ID( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ BSTR nombre) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VSercos_Type( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE VSercos_TieneSets( 
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResultadoUltimaCaptura( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualAutoAdjustVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualAutoAdjust * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualAutoAdjust * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualAutoAdjust * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualAutoAdjust * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualAutoAdjust * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualAutoAdjust * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualAutoAdjust * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LeerPM )( 
            IFCDualAutoAdjust * This,
            /* [in] */ BSTR namevar,
            /* [retval][out] */ BSTR *valor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EscribirPM )( 
            IFCDualAutoAdjust * This,
            /* [in] */ BSTR namevar,
            /* [in] */ BSTR valor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RestaurarPM )( 
            IFCDualAutoAdjust * This,
            /* [in] */ BSTR namevar,
            /* [retval][out] */ BSTR *valor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ValidarPM )( 
            IFCDualAutoAdjust * This,
            /* [in] */ BSTR namevar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LeerVSercos_BYTE )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [retval][out] */ BYTE *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LeerVSercos_WORD )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [retval][out] */ WORD *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LeerVSercos_LONG )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [retval][out] */ LONG *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LeerVSercos_STRING )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [retval][out] */ BSTR *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EscribirVSercos_BYTE )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [in] */ BYTE value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EscribirVSercos_WORD )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [in] */ WORD value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EscribirVSercos_LONG )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [in] */ LONG value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EscribirVSercos_STRING )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID,
            /* [in] */ USHORT set,
            /* [in] */ BSTR value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetSercos )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EjecutarComandoSercos )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ConfigurarCaptura )( 
            IFCDualAutoAdjust * This,
            /* [in] */ BSTR variable1,
            /* [in] */ BSTR variable2,
            /* [in] */ BSTR variable3,
            /* [in] */ BSTR variable4,
            /* [in] */ USHORT nMuestras,
            /* [in] */ UINT tMuestreo,
            /* [in] */ BOOL bTrigger,
            /* [in] */ USHORT canal,
            /* [in] */ USHORT flanco,
            /* [in] */ double nivel,
            /* [in] */ USHORT posicion);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Capturar )( 
            IFCDualAutoAdjust * This,
            /* [in] */ BSTR output,
            /* [defaultvalue][optional][in] */ BOOL bForzarCaptura);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DetenerCaptura )( 
            IFCDualAutoAdjust * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EstadoCaptura )( 
            IFCDualAutoAdjust * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VSercos_ID )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ BSTR nombre);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VSercos_Type )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VSercos_TieneSets )( 
            IFCDualAutoAdjust * This,
            /* [in] */ USHORT logAxisNr,
            /* [in] */ USHORT sercosID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResultadoUltimaCaptura )( 
            IFCDualAutoAdjust * This);
        
        END_INTERFACE
    } IFCDualAutoAdjustVtbl;

    interface IFCDualAutoAdjust
    {
        CONST_VTBL struct IFCDualAutoAdjustVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualAutoAdjust_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualAutoAdjust_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualAutoAdjust_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualAutoAdjust_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualAutoAdjust_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualAutoAdjust_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualAutoAdjust_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualAutoAdjust_LeerPM(This,namevar,valor)	\
    (This)->lpVtbl -> LeerPM(This,namevar,valor)

#define IFCDualAutoAdjust_EscribirPM(This,namevar,valor)	\
    (This)->lpVtbl -> EscribirPM(This,namevar,valor)

#define IFCDualAutoAdjust_RestaurarPM(This,namevar,valor)	\
    (This)->lpVtbl -> RestaurarPM(This,namevar,valor)

#define IFCDualAutoAdjust_ValidarPM(This,namevar)	\
    (This)->lpVtbl -> ValidarPM(This,namevar)

#define IFCDualAutoAdjust_LeerVSercos_BYTE(This,logAxisNr,sercosID,set,value)	\
    (This)->lpVtbl -> LeerVSercos_BYTE(This,logAxisNr,sercosID,set,value)

#define IFCDualAutoAdjust_LeerVSercos_WORD(This,logAxisNr,sercosID,set,value)	\
    (This)->lpVtbl -> LeerVSercos_WORD(This,logAxisNr,sercosID,set,value)

#define IFCDualAutoAdjust_LeerVSercos_LONG(This,logAxisNr,sercosID,set,value)	\
    (This)->lpVtbl -> LeerVSercos_LONG(This,logAxisNr,sercosID,set,value)

#define IFCDualAutoAdjust_LeerVSercos_STRING(This,logAxisNr,sercosID,set,value)	\
    (This)->lpVtbl -> LeerVSercos_STRING(This,logAxisNr,sercosID,set,value)

#define IFCDualAutoAdjust_EscribirVSercos_BYTE(This,logAxisNr,sercosID,set,value)	\
    (This)->lpVtbl -> EscribirVSercos_BYTE(This,logAxisNr,sercosID,set,value)

#define IFCDualAutoAdjust_EscribirVSercos_WORD(This,logAxisNr,sercosID,set,value)	\
    (This)->lpVtbl -> EscribirVSercos_WORD(This,logAxisNr,sercosID,set,value)

#define IFCDualAutoAdjust_EscribirVSercos_LONG(This,logAxisNr,sercosID,set,value)	\
    (This)->lpVtbl -> EscribirVSercos_LONG(This,logAxisNr,sercosID,set,value)

#define IFCDualAutoAdjust_EscribirVSercos_STRING(This,logAxisNr,sercosID,set,value)	\
    (This)->lpVtbl -> EscribirVSercos_STRING(This,logAxisNr,sercosID,set,value)

#define IFCDualAutoAdjust_ResetSercos(This,logAxisNr)	\
    (This)->lpVtbl -> ResetSercos(This,logAxisNr)

#define IFCDualAutoAdjust_EjecutarComandoSercos(This,logAxisNr,sercosID)	\
    (This)->lpVtbl -> EjecutarComandoSercos(This,logAxisNr,sercosID)

#define IFCDualAutoAdjust_ConfigurarCaptura(This,variable1,variable2,variable3,variable4,nMuestras,tMuestreo,bTrigger,canal,flanco,nivel,posicion)	\
    (This)->lpVtbl -> ConfigurarCaptura(This,variable1,variable2,variable3,variable4,nMuestras,tMuestreo,bTrigger,canal,flanco,nivel,posicion)

#define IFCDualAutoAdjust_Capturar(This,output,bForzarCaptura)	\
    (This)->lpVtbl -> Capturar(This,output,bForzarCaptura)

#define IFCDualAutoAdjust_DetenerCaptura(This)	\
    (This)->lpVtbl -> DetenerCaptura(This)

#define IFCDualAutoAdjust_EstadoCaptura(This)	\
    (This)->lpVtbl -> EstadoCaptura(This)

#define IFCDualAutoAdjust_VSercos_ID(This,logAxisNr,nombre)	\
    (This)->lpVtbl -> VSercos_ID(This,logAxisNr,nombre)

#define IFCDualAutoAdjust_VSercos_Type(This,logAxisNr,sercosID)	\
    (This)->lpVtbl -> VSercos_Type(This,logAxisNr,sercosID)

#define IFCDualAutoAdjust_VSercos_TieneSets(This,logAxisNr,sercosID)	\
    (This)->lpVtbl -> VSercos_TieneSets(This,logAxisNr,sercosID)

#define IFCDualAutoAdjust_ResultadoUltimaCaptura(This)	\
    (This)->lpVtbl -> ResultadoUltimaCaptura(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_LeerPM_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ BSTR namevar,
    /* [retval][out] */ BSTR *valor);


void __RPC_STUB IFCDualAutoAdjust_LeerPM_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_EscribirPM_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ BSTR namevar,
    /* [in] */ BSTR valor);


void __RPC_STUB IFCDualAutoAdjust_EscribirPM_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_RestaurarPM_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ BSTR namevar,
    /* [retval][out] */ BSTR *valor);


void __RPC_STUB IFCDualAutoAdjust_RestaurarPM_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_ValidarPM_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ BSTR namevar);


void __RPC_STUB IFCDualAutoAdjust_ValidarPM_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_LeerVSercos_BYTE_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ USHORT sercosID,
    /* [in] */ USHORT set,
    /* [retval][out] */ BYTE *value);


void __RPC_STUB IFCDualAutoAdjust_LeerVSercos_BYTE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_LeerVSercos_WORD_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ USHORT sercosID,
    /* [in] */ USHORT set,
    /* [retval][out] */ WORD *value);


void __RPC_STUB IFCDualAutoAdjust_LeerVSercos_WORD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_LeerVSercos_LONG_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ USHORT sercosID,
    /* [in] */ USHORT set,
    /* [retval][out] */ LONG *value);


void __RPC_STUB IFCDualAutoAdjust_LeerVSercos_LONG_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_LeerVSercos_STRING_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ USHORT sercosID,
    /* [in] */ USHORT set,
    /* [retval][out] */ BSTR *value);


void __RPC_STUB IFCDualAutoAdjust_LeerVSercos_STRING_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_EscribirVSercos_BYTE_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ USHORT sercosID,
    /* [in] */ USHORT set,
    /* [in] */ BYTE value);


void __RPC_STUB IFCDualAutoAdjust_EscribirVSercos_BYTE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_EscribirVSercos_WORD_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ USHORT sercosID,
    /* [in] */ USHORT set,
    /* [in] */ WORD value);


void __RPC_STUB IFCDualAutoAdjust_EscribirVSercos_WORD_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_EscribirVSercos_LONG_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ USHORT sercosID,
    /* [in] */ USHORT set,
    /* [in] */ LONG value);


void __RPC_STUB IFCDualAutoAdjust_EscribirVSercos_LONG_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_EscribirVSercos_STRING_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ USHORT sercosID,
    /* [in] */ USHORT set,
    /* [in] */ BSTR value);


void __RPC_STUB IFCDualAutoAdjust_EscribirVSercos_STRING_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_ResetSercos_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr);


void __RPC_STUB IFCDualAutoAdjust_ResetSercos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_EjecutarComandoSercos_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ USHORT sercosID);


void __RPC_STUB IFCDualAutoAdjust_EjecutarComandoSercos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_ConfigurarCaptura_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ BSTR variable1,
    /* [in] */ BSTR variable2,
    /* [in] */ BSTR variable3,
    /* [in] */ BSTR variable4,
    /* [in] */ USHORT nMuestras,
    /* [in] */ UINT tMuestreo,
    /* [in] */ BOOL bTrigger,
    /* [in] */ USHORT canal,
    /* [in] */ USHORT flanco,
    /* [in] */ double nivel,
    /* [in] */ USHORT posicion);


void __RPC_STUB IFCDualAutoAdjust_ConfigurarCaptura_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_Capturar_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ BSTR output,
    /* [defaultvalue][optional][in] */ BOOL bForzarCaptura);


void __RPC_STUB IFCDualAutoAdjust_Capturar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_DetenerCaptura_Proxy( 
    IFCDualAutoAdjust * This);


void __RPC_STUB IFCDualAutoAdjust_DetenerCaptura_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_EstadoCaptura_Proxy( 
    IFCDualAutoAdjust * This);


void __RPC_STUB IFCDualAutoAdjust_EstadoCaptura_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_VSercos_ID_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ BSTR nombre);


void __RPC_STUB IFCDualAutoAdjust_VSercos_ID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_VSercos_Type_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ USHORT sercosID);


void __RPC_STUB IFCDualAutoAdjust_VSercos_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_VSercos_TieneSets_Proxy( 
    IFCDualAutoAdjust * This,
    /* [in] */ USHORT logAxisNr,
    /* [in] */ USHORT sercosID);


void __RPC_STUB IFCDualAutoAdjust_VSercos_TieneSets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualAutoAdjust_ResultadoUltimaCaptura_Proxy( 
    IFCDualAutoAdjust * This);


void __RPC_STUB IFCDualAutoAdjust_ResultadoUltimaCaptura_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualAutoAdjust_INTERFACE_DEFINED__ */


#ifndef __IEventAutoAdjustReport_DISPINTERFACE_DEFINED__
#define __IEventAutoAdjustReport_DISPINTERFACE_DEFINED__

/* dispinterface IEventAutoAdjustReport */
/* [helpstring][uuid] */ 


DEFINE_GUID(DIID_IEventAutoAdjustReport,0xA6BFFA8E,0x6328,0x478c,0xAE,0x1D,0xE8,0x13,0xD0,0x7C,0x31,0x1B);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A6BFFA8E-6328-478c-AE1D-E813D07C311B")
    IEventAutoAdjustReport : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IEventAutoAdjustReportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEventAutoAdjustReport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEventAutoAdjustReport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEventAutoAdjustReport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEventAutoAdjustReport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEventAutoAdjustReport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEventAutoAdjustReport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEventAutoAdjustReport * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IEventAutoAdjustReportVtbl;

    interface IEventAutoAdjustReport
    {
        CONST_VTBL struct IEventAutoAdjustReportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEventAutoAdjustReport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEventAutoAdjustReport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEventAutoAdjustReport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEventAutoAdjustReport_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IEventAutoAdjustReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IEventAutoAdjustReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IEventAutoAdjustReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IEventAutoAdjustReport_DISPINTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_FCAutoAdjust,0xE17055F6,0x6E46,0x41F6,0x9C,0xBA,0x2C,0x6A,0x0A,0x94,0x11,0xAC);

#ifdef __cplusplus

class DECLSPEC_UUID("E17055F6-6E46-41F6-9CBA-2C6A0A9411AC")
CNC8070_FCAutoAdjust;
#endif

#ifndef __IFCF3DGrafCtrlHandles_DISPINTERFACE_DEFINED__
#define __IFCF3DGrafCtrlHandles_DISPINTERFACE_DEFINED__

/* dispinterface IFCF3DGrafCtrlHandles */
/* [uuid] */ 


DEFINE_GUID(DIID_IFCF3DGrafCtrlHandles,0xEE962041,0x2C76,0x4BD8,0x8C,0x77,0xAE,0x3E,0x67,0x9D,0x0D,0x6B);

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EE962041-2C76-4BD8-8C77-AE3E679D0D6B")
    IFCF3DGrafCtrlHandles : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFCF3DGrafCtrlHandlesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCF3DGrafCtrlHandles * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCF3DGrafCtrlHandles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCF3DGrafCtrlHandles * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCF3DGrafCtrlHandles * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCF3DGrafCtrlHandles * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCF3DGrafCtrlHandles * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCF3DGrafCtrlHandles * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IFCF3DGrafCtrlHandlesVtbl;

    interface IFCF3DGrafCtrlHandles
    {
        CONST_VTBL struct IFCF3DGrafCtrlHandlesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCF3DGrafCtrlHandles_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCF3DGrafCtrlHandles_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCF3DGrafCtrlHandles_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCF3DGrafCtrlHandles_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCF3DGrafCtrlHandles_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCF3DGrafCtrlHandles_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCF3DGrafCtrlHandles_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFCF3DGrafCtrlHandles_DISPINTERFACE_DEFINED__ */


#ifndef __IFCDualF3DGrafCtrlHandles_INTERFACE_DEFINED__
#define __IFCDualF3DGrafCtrlHandles_INTERFACE_DEFINED__

/* interface IFCDualF3DGrafCtrlHandles */
/* [dual][oleautomation][uuid][object] */ 


DEFINE_GUID(IID_IFCDualF3DGrafCtrlHandles,0x91A6EFCA,0x08AB,0x4856,0x9E,0x51,0x09,0xE6,0x10,0x11,0x82,0x94);

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("91A6EFCA-08AB-4856-9E51-09E610118294")
    IFCDualF3DGrafCtrlHandles : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetF3DGrafCtrlHandle( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetF3DGrafCtrlHandle( 
            LONG hWnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetF3DGrafCtrlSimuHandle( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetF3DGrafCtrlSimuHandle( 
            LONG hWnd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFCDualF3DGrafCtrlHandlesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFCDualF3DGrafCtrlHandles * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFCDualF3DGrafCtrlHandles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFCDualF3DGrafCtrlHandles * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFCDualF3DGrafCtrlHandles * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFCDualF3DGrafCtrlHandles * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFCDualF3DGrafCtrlHandles * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFCDualF3DGrafCtrlHandles * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetF3DGrafCtrlHandle )( 
            IFCDualF3DGrafCtrlHandles * This,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetF3DGrafCtrlHandle )( 
            IFCDualF3DGrafCtrlHandles * This,
            LONG hWnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetF3DGrafCtrlSimuHandle )( 
            IFCDualF3DGrafCtrlHandles * This,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetF3DGrafCtrlSimuHandle )( 
            IFCDualF3DGrafCtrlHandles * This,
            LONG hWnd);
        
        END_INTERFACE
    } IFCDualF3DGrafCtrlHandlesVtbl;

    interface IFCDualF3DGrafCtrlHandles
    {
        CONST_VTBL struct IFCDualF3DGrafCtrlHandlesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFCDualF3DGrafCtrlHandles_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFCDualF3DGrafCtrlHandles_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFCDualF3DGrafCtrlHandles_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFCDualF3DGrafCtrlHandles_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFCDualF3DGrafCtrlHandles_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFCDualF3DGrafCtrlHandles_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFCDualF3DGrafCtrlHandles_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFCDualF3DGrafCtrlHandles_GetF3DGrafCtrlHandle(This,retval)	\
    (This)->lpVtbl -> GetF3DGrafCtrlHandle(This,retval)

#define IFCDualF3DGrafCtrlHandles_SetF3DGrafCtrlHandle(This,hWnd)	\
    (This)->lpVtbl -> SetF3DGrafCtrlHandle(This,hWnd)

#define IFCDualF3DGrafCtrlHandles_GetF3DGrafCtrlSimuHandle(This,retval)	\
    (This)->lpVtbl -> GetF3DGrafCtrlSimuHandle(This,retval)

#define IFCDualF3DGrafCtrlHandles_SetF3DGrafCtrlSimuHandle(This,hWnd)	\
    (This)->lpVtbl -> SetF3DGrafCtrlSimuHandle(This,hWnd)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualF3DGrafCtrlHandles_GetF3DGrafCtrlHandle_Proxy( 
    IFCDualF3DGrafCtrlHandles * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualF3DGrafCtrlHandles_GetF3DGrafCtrlHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualF3DGrafCtrlHandles_SetF3DGrafCtrlHandle_Proxy( 
    IFCDualF3DGrafCtrlHandles * This,
    LONG hWnd);


void __RPC_STUB IFCDualF3DGrafCtrlHandles_SetF3DGrafCtrlHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualF3DGrafCtrlHandles_GetF3DGrafCtrlSimuHandle_Proxy( 
    IFCDualF3DGrafCtrlHandles * This,
    /* [retval][out] */ long *retval);


void __RPC_STUB IFCDualF3DGrafCtrlHandles_GetF3DGrafCtrlSimuHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IFCDualF3DGrafCtrlHandles_SetF3DGrafCtrlSimuHandle_Proxy( 
    IFCDualF3DGrafCtrlHandles * This,
    LONG hWnd);


void __RPC_STUB IFCDualF3DGrafCtrlHandles_SetF3DGrafCtrlSimuHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFCDualF3DGrafCtrlHandles_INTERFACE_DEFINED__ */


DEFINE_GUID(CLSID_CNC8070_FCF3DGrafCtrlHandles,0x6CAC57BE,0xF832,0x4ACC,0xA5,0xD9,0x8F,0x3F,0x31,0xED,0x30,0x12);

#ifdef __cplusplus

class DECLSPEC_UUID("6CAC57BE-F832-4ACC-A5D9-8F3F31ED3012")
CNC8070_FCF3DGrafCtrlHandles;
#endif
#endif /* __Api8070_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif



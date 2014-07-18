/*******************************************************************************
 * Copyright (c) 2007-2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <string.h>
#include "DEV_MGR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "DEV_MGR_gen.cpp"
#endif
#include "../../core/device.h"
#include <config.h>
#include <stdio.h>
#include <stdlib.h>


DEFINE_FIRMWARE_FB(DEV_MGR, g_nStringIdDEV_MGR)

const CStringDictionary::TStringId DEV_MGR::scm_aunEINameIds[2] = { g_nStringIdINIT, g_nStringIdREQ };
const TDataIOID DEV_MGR::scm_anEIWith[6] = { 0, 255, 0, 1, 2, 255 };
const TForteInt16 DEV_MGR::scm_anEIWithIndexes[2] = { 0, 2 };
const CStringDictionary::TStringId DEV_MGR::scm_aunEONameIds[2] = { g_nStringIdINITO, g_nStringIdCNF };
const TDataIOID DEV_MGR::scm_anEOWith[4] = { 0, 255, 1, 255 };
const TForteInt16 DEV_MGR::scm_anEOWithIndexes[3] = { 0, 2 };
const CStringDictionary::TStringId DEV_MGR::scm_aunDINameIds[3] = { g_nStringIdQI, g_nStringIdDST, g_nStringIdRQST };
const CStringDictionary::TStringId DEV_MGR::scm_aunDIDataTypeIds[] = { g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdSTRING };
const CStringDictionary::TStringId DEV_MGR::scm_aunDONameIds[2] = { g_nStringIdQO, g_nStringIdRESP };
const CStringDictionary::TStringId DEV_MGR::scm_aunDODataTypeIds[] = { g_nStringIdBOOL, g_nStringIdSTRING };

const SFBInterfaceSpec DEV_MGR::scm_stFBInterfaceSpec = { 2, scm_aunEINameIds, scm_anEIWith, scm_anEIWithIndexes, 2, scm_aunEONameIds, scm_anEOWith, scm_anEOWithIndexes, 3, scm_aunDINameIds, scm_aunDIDataTypeIds, 2, scm_aunDONameIds, scm_aunDODataTypeIds, 0, 0 };

const char * const DEV_MGR::scm_sMGMResponseTexts[13] = { "RDY", "BAD_PARAMS", "LOCAL_TERMINATION", "SYSTEM_TERMINATION", "NOT_READY", "UNSUPPORTED_CMD", "UNSUPPORTED_TYPE", "NO_SUCH_OBJECT", "INVALID_OBJECT", "INVALID_OPERATION", "INVALID_STATE", "OVERFLOW", "INVALID_DST" };

void DEV_MGR::executeEvent(int pa_nEIID){
  if(csm_nEventINITID == pa_nEIID){
#ifdef FORTE_SUPPORT_BOOT_FILE
    if((true == QI()) && (false == QO())){
      //this is the first time init is called try to load a boot file
      loadForteBootFile();
    }
#endif
    //TODO think on what todo on deinit
    QO() = QI();
    sendOutputEvent(csm_nEventINITOID);
  }
  else if(csm_nEventREQID == pa_nEIID){
    if(true == QI()){
      executeRQST();
    }
    //TODO: if QI not true send suitable response
//    DEVLOG_DEBUG("sending cnf\n");
    sendOutputEvent(csm_nEventCNFID);
//    DEVLOG_DEBUG("sent cnf\n");
  }
}

void DEV_MGR::executeRQST(void){
  m_stCommand.m_oAdditionalParams.clear();
  EMGMResponse resp = parseAndExecuteMGMCommand(DST().getValue(), RQST().getValue());
  
  #ifdef FORTE_SUPPORT_MONITORING
  if (0 != m_stCommand.m_oMonitorResponse.length()) {
    generateMonitorResponse(resp, m_stCommand);
  } else
#endif //FORTE_SUPPORT_MONITORING
  if(0 < m_stCommand.m_oAdditionalParams.length()){
    generateLongResponse(resp, m_stCommand);
  }
  else{
    generateResponse(m_stCommand.m_acID, resp);
  }
}

char *DEV_MGR::parseRequest(char *pa_acRequestString, SManagementCMD &pa_rstCommand){
//first check if it is an management request
  char *acCommandStart = 0;
  static const int scnCommandLength[] = {7, 7, 6, 5, 5, 6, 5, 6, 6};

  if(!strncmp("<Request ID=\"", pa_acRequestString, 13)){
    int i = 13;
    int j;
    pa_rstCommand.m_acID = &(pa_acRequestString[i]);
    for(j = 0; pa_acRequestString[i] != '\"'; ++i, ++j){
      if(j >= 7){
        return 0;
      }
    }
    pa_acRequestString[i] = '\0'; //close ID
    ++i;
    acCommandStart = strchr((&pa_acRequestString[i]), '\"');
    if(acCommandStart != 0){
      acCommandStart++; //this is the real start of the command
      if(!strncmp("CREATE", acCommandStart, 6)){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Create_Group;
      }
      else if(!strncmp("DELETE", acCommandStart, 6)){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Delete_Group;
      }
      else if(!strncmp("START", acCommandStart, 5)){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Start;
      }
      else if(!strncmp("STOP", acCommandStart, 4)){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Stop;
      }
      else if(!strncmp("KILL", acCommandStart, 4)){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Kill;
      }
      else if(!strncmp("RESET", acCommandStart, 5)){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Reset;
      }
      else if(!strncmp("READ", acCommandStart, 4)){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Read;
      }
      else if(!strncmp("WRITE", acCommandStart, 5)){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Write;
      }
      else if(!strncmp("QUERY", acCommandStart, 5)){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Query_Group;
      }
      else{
        return 0;
      }
      acCommandStart += scnCommandLength[pa_rstCommand.m_nCMD];
    }
  }

  return acCommandStart;
}

bool DEV_MGR::parseFBData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand){
  bool bRetVal = false;

  if(!strncmp("FB Name=\"", pa_acRequestPartLeft, 9)){
    if(strstr("EventIn=\"", pa_acRequestPartLeft) != 0){
      // TODO parse all parameters
    }
    else{
      char *acBuf = &(pa_acRequestPartLeft[9]);
      int i = 0;
      if(acBuf[0] != '*'){
        pa_rstCommand.m_nFirstParam = getIdentifierId(acBuf, '\"', i);
        acBuf = strchr(&(acBuf[i + 1]), '\"');
      }
      else{
        acBuf = strchr(&(acBuf[i + 2]), '\"');
      }

      if(acBuf != 0){
        if(acBuf[1] != '*'){
          ++acBuf;
          pa_rstCommand.m_nSecondParam = getIdentifierId(acBuf, '\"', i);
          acBuf = strchr(&(acBuf[i + 1]), '\"');
          if(acBuf != 0){
            // We have an application name given
            ++acBuf;
            i = 0;
            TForteUInt16 nBufLength = strcspn(acBuf, "\"") + 1;
            pa_rstCommand.m_oAdditionalParams.assign(acBuf, nBufLength);
          }
        }
        bRetVal = true;
      }
    }
  }
  return bRetVal;
}

CStringDictionary::TStringId DEV_MGR::getIdentifierId(char *pa_acIdentifierStart, char pa_cEndChar, int &pa_nCharsUsed){
  CStringDictionary::TStringId nRetVal = CStringDictionary::scm_nInvalidStringId;

  for(pa_nCharsUsed = 0; '\0' != pa_acIdentifierStart[pa_nCharsUsed]; ++pa_nCharsUsed){
    if(pa_acIdentifierStart[pa_nCharsUsed] == pa_cEndChar){
      break;
    }
  }

  if(0 != pa_nCharsUsed){
    char cBuf = pa_acIdentifierStart[pa_nCharsUsed];
    pa_acIdentifierStart[pa_nCharsUsed] = '\0';
//TODO: limit identifier-name length to cg_nIdentifierLength and cut name if too long
    nRetVal = CStringDictionary::getInstance().insert(pa_acIdentifierStart);
    pa_acIdentifierStart[pa_nCharsUsed] = cBuf;
  }

  return nRetVal;
}

TConnectionID DEV_MGR::getConnectionEndPointIdentifier(char *pa_acIdentifierStart, int &pa_nCharsUsed){
  TConnectionID nRetVal = CStringDictionary::scm_nInvalidStringId;

  if(pa_acIdentifierStart[0] != '*'){
    int nCharsUsed;
    nRetVal = ((((TConnectionID) getIdentifierId(pa_acIdentifierStart, '.', nCharsUsed)) << 32) & 0xFFFFFFFF00000000ULL);
    pa_nCharsUsed = nCharsUsed;
    nRetVal += (((TConnectionID) getIdentifierId(&(pa_acIdentifierStart[nCharsUsed + 1]), '\"', nCharsUsed)) & 0xFFFFFFFF);
    pa_nCharsUsed += nCharsUsed;
  }
  return nRetVal;
}

bool DEV_MGR::parseConnectionData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand){
  bool bRetVal = false;
  if(!strncmp("Connection Source=\"", pa_acRequestPartLeft, 19)){
    int i=0;
    //FIXME handle resource or device inputs as connection sources (i.e., will have no dot)
    pa_rstCommand.m_nFirstParam = getConnectionEndPointIdentifier(&(pa_acRequestPartLeft[19]), i);
    char *acBuf = strchr(&(pa_acRequestPartLeft[i + 21]), '\"');
    if(acBuf != 0){
      pa_rstCommand.m_nSecondParam = getConnectionEndPointIdentifier(&(acBuf[1]), i);
      bRetVal = true;
    }
  }
  return bRetVal;
}

bool DEV_MGR::parseTypeListData(char *pa_acRequestPartLeft, SManagementCMD &){
  bool bRetVal = true;

  if (!strncmp("DataType Name=\"", pa_acRequestPartLeft, 15)) {
    if(pa_acRequestPartLeft[15] != '*'){ //does not support query for DataType-Declaration
      bRetVal = false;
    }
  } 
  else if(!strncmp("FBType Name=\"", pa_acRequestPartLeft, 13)){
    if(pa_acRequestPartLeft[13] != '*'){ //does not support query for DataType-Declaration
      bRetVal = false;
    }
  }
  else if(!strncmp("AdapterType Name=\"", pa_acRequestPartLeft, 18)){
    if(pa_acRequestPartLeft[18] != '*'){ //does not support query for DataType-Declaration
      bRetVal = false;
    }
  }
  return bRetVal;
}

bool DEV_MGR::parseWriteConnectionData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand){
  bool bRetVal = false;
  char cBuffer[255] = "";
  if(!strncmp("Connection Source=\"", pa_acRequestPartLeft, 19)){
    pa_acRequestPartLeft = &(pa_acRequestPartLeft[19]);
    //first retreive the data for the param
    if('&' == *pa_acRequestPartLeft){
      do{
        pa_acRequestPartLeft++;
      } while(';' != *pa_acRequestPartLeft);
      pa_acRequestPartLeft++;
    }
    if('\'' == *pa_acRequestPartLeft)
      pa_acRequestPartLeft++;
    // TODO: check if "-character should also be trimmed from pa_acRequestPartLeft
    unsigned int i = 0;
    for(; *pa_acRequestPartLeft != '\"'; ++pa_acRequestPartLeft, ++i){
      if('\0' == *pa_acRequestPartLeft){
        return false;
      }
      if('&' == *pa_acRequestPartLeft){
        do{
          pa_acRequestPartLeft++;
        } while(';' != *pa_acRequestPartLeft);
        pa_acRequestPartLeft += 2; //go beyound the ; and the following "
        break;
      }
      if('\'' == *pa_acRequestPartLeft){
        pa_acRequestPartLeft++;
        break;
      }
      cBuffer[i] = *pa_acRequestPartLeft;
    }

    cBuffer[i + 1] = '\0';
    pa_rstCommand.m_oAdditionalParams.assign(cBuffer, static_cast<TForteUInt16>(i));

    pa_acRequestPartLeft = strchr(&(pa_acRequestPartLeft[1]), '\"');
    if(pa_acRequestPartLeft != 0){
      int nCharsUsed;
      pa_rstCommand.m_nFirstParam = getConnectionEndPointIdentifier(&(pa_acRequestPartLeft[1]), nCharsUsed);
      bRetVal = true;
    }
  }
  return bRetVal;
}

void DEV_MGR::parseCreateData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand){
  pa_rstCommand.m_nCMD = cg_nMGM_CMD_INVALID;
  if(0 != pa_acRequestPartLeft){
      switch (pa_acRequestPartLeft[0]){
        case 'F': // we have an FB to Create
          if(parseFBData(pa_acRequestPartLeft, pa_rstCommand)){
            pa_rstCommand.m_nCMD = cg_nMGM_CMD_Create_FBInstance;
          }
          else{
            pa_rstCommand.m_nCMD = cg_nMGM_CMD_Create_FBType;
          }
          break;
        case 'C': // we have an Connection to Create
          if(parseConnectionData(pa_acRequestPartLeft, pa_rstCommand)){
            pa_rstCommand.m_nCMD = cg_nMGM_CMD_Create_Connection;
          }
          break;
      #ifdef FORTE_SUPPORT_MONITORING
        case 'W': // we have an Watch to Add
          if(parseMonitoringData(pa_acRequestPartLeft, pa_rstCommand)){
            pa_rstCommand.m_nCMD = cg_nMGM_CMD_Monitoring_Add_Watch;
          }
          break;
      #endif // FORTE_SUPPORT_MONITORING
        default:
          break;
      }
  }
}

void DEV_MGR::parseDeleteData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand){
  pa_rstCommand.m_nCMD = cg_nMGM_CMD_INVALID;
  if(0 != pa_acRequestPartLeft){
    switch (pa_acRequestPartLeft[0]){
      case 'F': // we have an FB to delete
        if(parseFBData(pa_acRequestPartLeft, pa_rstCommand)){
          pa_rstCommand.m_nCMD = cg_nMGM_CMD_Delete_FBInstance;
        }
        break;
      case 'C': // we have an Connection to delete
        if(parseConnectionData(pa_acRequestPartLeft, pa_rstCommand)){
          pa_rstCommand.m_nCMD = cg_nMGM_CMD_Delete_Connection;
        }
        break;
    #ifdef FORTE_SUPPORT_MONITORING
      case 'W': // we have an Watch to remove
        if(parseMonitoringData(pa_acRequestPartLeft, pa_rstCommand)){
           pa_rstCommand.m_nCMD = cg_nMGM_CMD_Monitoring_Remove_Watch;
        }
        break;
    #endif // FORTE_SUPPORT_MONITORING
      default:
        break;
    }
  }
}

void DEV_MGR::parseAdditionalStateCommandData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand){
  if(0 != pa_acRequestPartLeft){
    if('/' != pa_acRequestPartLeft[0]){
      //if we have an additional xml token parse if it is an FB definition
      if(!parseFBData(pa_acRequestPartLeft, pa_rstCommand)){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_INVALID;
      }
    }
  }
}

void DEV_MGR::parseReadData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand){
  pa_rstCommand.m_nCMD = cg_nMGM_CMD_INVALID;
  if(0 != pa_acRequestPartLeft){
#ifdef FORTE_SUPPORT_MONITORING
    if('W' == pa_acRequestPartLeft[0]){
          pa_rstCommand.m_nCMD = cg_nMGM_CMD_Monitoring_Read_Watches;
    } else if (!strncmp(pa_acRequestPartLeft, "Connection Source=\"*\" Destination=\"*\"", 37)) {
        if (!parseConnectionStarStarData(pa_acRequestPartLeft + 37, pa_rstCommand)) {
          pa_rstCommand.m_nCMD = cg_nMGM_CMD_INVALID;
        } else {
          pa_rstCommand.m_nCMD = cg_nMGM_CMD_Monitoring_Get_Watches;
        }
    } else
#endif // FORTE_SUPPORT_MONITORING
      if(parseConnectionData(pa_acRequestPartLeft, pa_rstCommand)){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Read;
      }
  }
}

void DEV_MGR::parseWriteData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand){
  //We need an additional xml connection token parse if it is an connection definition
  pa_rstCommand.m_nCMD = cg_nMGM_CMD_INVALID;
  if(0 != pa_acRequestPartLeft){
    if(parseWriteConnectionData(pa_acRequestPartLeft, pa_rstCommand)) {
#ifdef FORTE_SUPPORT_MONITORING
      char *pch = strstr(pa_acRequestPartLeft, "force=\"");
      if (0 != pch) {
        if (!strncmp(&pch[7], "true", 4)) {
          pa_rstCommand.m_nCMD = cg_nMGM_CMD_Monitoring_Force;
        } else if (!strncmp(&pch[7], "false", 5)) {
          pa_rstCommand.m_nCMD = cg_nMGM_CMD_Monitoring_ClearForce;
        }
      } else if ((2 == pa_rstCommand.m_oAdditionalParams.length()) && 
        (('$' == pa_rstCommand.m_oAdditionalParams.getValue()[0]) && 
          (('e' == pa_rstCommand.m_oAdditionalParams.getValue()[1]) ||('E' == pa_rstCommand.m_oAdditionalParams.getValue()[1]) ))){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Monitoring_Trigger_Event;
      }else if ((3 == pa_rstCommand.m_oAdditionalParams.length()) && 
        (('$' == pa_rstCommand.m_oAdditionalParams.getValue()[0]) && 
         (('e' == pa_rstCommand.m_oAdditionalParams.getValue()[1]) ||('E' == pa_rstCommand.m_oAdditionalParams.getValue()[1]) ) && 
         (('r' == pa_rstCommand.m_oAdditionalParams.getValue()[2]) ||('R' == pa_rstCommand.m_oAdditionalParams.getValue()[2]) ) )){
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Monitoring_Reset_Event_Count;
      }else
#endif // FORTE_SUPPORT_MONITORING
        pa_rstCommand.m_nCMD = cg_nMGM_CMD_Write;
    }
  }
}

void DEV_MGR::parseQueryData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand){
  pa_rstCommand.m_nCMD = cg_nMGM_CMD_INVALID;
  if(0 != pa_acRequestPartLeft){
    switch (pa_acRequestPartLeft[0]){
      case 'F': // query fb or fb type list
        if(!strncmp(pa_acRequestPartLeft, "FBT", 3)){
          if(parseTypeListData(pa_acRequestPartLeft, pa_rstCommand)){
            pa_rstCommand.m_nCMD = cg_nMGM_CMD_QUERY_FBTypes;
          } else {
            pa_rstCommand.m_nCMD = cg_nMGM_CMD_Query_Group;
          }
        }else if(parseFBData(pa_acRequestPartLeft, pa_rstCommand)){
          pa_rstCommand.m_nCMD = cg_nMGM_CMD_QUERY_FB;
        }
        break;
      case 'C': // query connection list
        if(parseConnectionData(pa_acRequestPartLeft, pa_rstCommand)){
          pa_rstCommand.m_nCMD = cg_nMGM_CMD_QUERY_Connection;
        }
        break;
      case 'D': // query datatype list
        if(!strncmp(pa_acRequestPartLeft, "DataType", 8)){
          if(parseTypeListData(pa_acRequestPartLeft, pa_rstCommand)){
            pa_rstCommand.m_nCMD = cg_nMGM_CMD_QUERY_DTTypes;
          } else {
            pa_rstCommand.m_nCMD = cg_nMGM_CMD_Query_Group;
          }
        }
        break;
      case 'A': // query adaptertype list
        if(!strncmp(pa_acRequestPartLeft, "AdapterT", 8)){
          if(parseTypeListData(pa_acRequestPartLeft, pa_rstCommand)){
            pa_rstCommand.m_nCMD = cg_nMGM_CMD_QUERY_AdapterTypes;
          } else {
            pa_rstCommand.m_nCMD = cg_nMGM_CMD_Query_Group;
          }
        }

        break;
      default:
        break;
    }
  }
}

void DEV_MGR::generateResponse(const char *pa_acID, EMGMResponse pa_eResp){
  RESP().clear();
  RESP().append("<Response ID=\"");
  if (0 != pa_acID) {
    RESP().append(pa_acID);
  }
  RESP().append("\"");
  if(e_RDY != pa_eResp){
    RESP().append(" Reason=\"");
    RESP().append(scm_sMGMResponseTexts[pa_eResp]);
    RESP().append("\"");
  }
  RESP().append(" />");
}

void DEV_MGR::generateLongResponse(EMGMResponse pa_eResp, SManagementCMD &pa_stCMD){
  RESP().clear();
  RESP().reserve(static_cast<TForteUInt16>(255+(pa_stCMD.m_oAdditionalParams.length())));
  RESP().append("<Response ID=\"");
  if (0 != pa_stCMD.m_acID) {
    RESP().append(pa_stCMD.m_acID);
  }
  RESP().append("\"");
  if(e_RDY != pa_eResp){
    RESP().append(" Reason=\"");
    RESP().append(scm_sMGMResponseTexts[pa_eResp]);
    RESP().append("\">\n  ");
  }
  else{
    RESP().append(">\n  ");
    if(pa_stCMD.m_nCMD == cg_nMGM_CMD_QUERY_Connection){
      if ((CStringDictionary::scm_nInvalidStringId == pa_stCMD.m_nFirstParam) &&
          (CStringDictionary::scm_nInvalidStringId == pa_stCMD.m_nSecondParam)) { //src & dst = *
          RESP().append(pa_stCMD.m_oAdditionalParams.getValue());
      }
      else { //either src or dst = * (both != * should be treated by generateResponse
        RESP().append("<EndpointList>\n    ");
        RESP().append(pa_stCMD.m_oAdditionalParams.getValue());
        RESP().append("\n  </EndpointList>");
      }
    }
    else if(pa_stCMD.m_nCMD == cg_nMGM_CMD_QUERY_FB){
      if(CStringDictionary::scm_nInvalidStringId != pa_stCMD.m_nFirstParam) {	//Name != "*"
        if(CStringDictionary::scm_nInvalidStringId != pa_stCMD.m_nSecondParam){ //Type != "*"
          RESP().append("<FBStatus Status=\"");
          RESP().append(pa_stCMD.m_oAdditionalParams.getValue());
          RESP().append("\" />");
        } else { //Type == "*"
          RESP().append("<FB Name=\"");
          RESP().append(CStringDictionary::getInstance().get(static_cast<CStringDictionary::TStringId>(pa_stCMD.m_nFirstParam)));
          RESP().append("\" Type=\"");
          RESP().append(pa_stCMD.m_oAdditionalParams.getValue());
          RESP().append("\" />");
        }
      }
      else{
        RESP().append("<FBList>\n    ");
        RESP().append(pa_stCMD.m_oAdditionalParams.getValue());
        RESP().append("\n  </FBList>");
      }
    }
    else if(pa_stCMD.m_nCMD == cg_nMGM_CMD_Read){
      RESP().append("<Connection Source=\"");
      if(CStringDictionary::scm_nInvalidStringId != pa_stCMD.m_nFirstParam){
        RESP().append(CStringDictionary::getInstance().get(CConnection::extractFBNameId(pa_stCMD.m_nFirstParam)));
        RESP().append(".");
        RESP().append(CStringDictionary::getInstance().get(CConnection::extractPortNameId(pa_stCMD.m_nFirstParam)));
      }
      RESP().append("\" Destination=\"");
      RESP().append(pa_stCMD.m_oAdditionalParams.getValue());
      RESP().append("\" />");
    }
    else if(pa_stCMD.m_nCMD == cg_nMGM_CMD_QUERY_FBTypes){
      RESP().append("<FBList>\n    ");
      RESP().append(pa_stCMD.m_oAdditionalParams.getValue());
      RESP().append("\n  </FBList>");
    }
    else if(pa_stCMD.m_nCMD == cg_nMGM_CMD_QUERY_DTTypes){
      RESP().append("<DTList>\n    ");
      RESP().append(pa_stCMD.m_oAdditionalParams.getValue());
      RESP().append("\n  </DTList>");
    }
    else if(pa_stCMD.m_nCMD == cg_nMGM_CMD_QUERY_AdapterTypes){
      RESP().append("<AdapterList>\n    ");
      RESP().append(pa_stCMD.m_oAdditionalParams.getValue());
      RESP().append("\n  </AdapterList>");
    }
  }
  RESP().append("\n</Response>");
}

DEV_MGR::~DEV_MGR(){
}


#ifdef FORTE_SUPPORT_BOOT_FILE
void DEV_MGR::loadForteBootFile(){
  char acLineBuf[cg_unBootFileLineBufSize]; //TODO maybe move it out of the stack

  char* bootFileName;
  bootFileName = getenv ("FORTE_BOOT_FILE");
  FILE *bootfile = 0;
  if(bootFileName != 0){
    bootfile = fopen(bootFileName, "r");
  }else{
    bootfile = fopen(FORTE_BOOT_FILE_LOCATION, "r");
  }

  if(0 != bootfile){
    DEVLOG_INFO("Boot file %s opened\n", bootFileName);
    //we could open the file try to load it
    int nLineCount = 1;
    EMGMResponse eResp;
    char *cmdStart;

    while(0 != fgets(acLineBuf, cg_unBootFileLineBufSize, bootfile)){
      if('\n' != acLineBuf[strlen(acLineBuf) - 1]){
         //the line has been longer than our buffer
        DEVLOG_ERROR("Boot file line longer than configured buffer size: %d\n", cg_unBootFileLineBufSize);
        //As we were not able to load the bootfile clean any created resources and FBs and start an empty device
        m_stCommand.m_nCMD = cg_nMGM_CMD_Delete_AllFBInstances;
        m_stCommand.m_nDestination = CStringDictionary::scm_nInvalidStringId;
        m_poDevice.executeMGMCommand(m_stCommand);
        break;
      }

      cmdStart = strchr(acLineBuf, ';');
      if(0 == cmdStart){
        DEVLOG_ERROR("Boot file line does not contain separating ';'. Line: %d\n", nLineCount);
        break;
      }
      *cmdStart = '\0';
      cmdStart++;

      eResp = parseAndExecuteMGMCommand(acLineBuf, cmdStart);
      if(e_RDY != eResp){
        //command was not successful
        DEVLOG_ERROR("Boot file command could not be executed. Line: %d: %s, Response %s\n", nLineCount, cmdStart, scm_sMGMResponseTexts[eResp]);
        break;
      }
      nLineCount++;
    }

    fclose(bootfile);
  }
  else{
    if(bootFileName != 0){
        DEVLOG_WARNING("Boot file %s could not be opened\n", bootFileName);
    }else{
        DEVLOG_WARNING("Boot file forte.fboot could not be opened\n");
    }
  }
}
#endif

EMGMResponse DEV_MGR::parseAndExecuteMGMCommand(char *pa_acDest, char *pa_acCommand){
  EMGMResponse eResp = e_INVALID_OBJECT;

  if(0 != strchr(pa_acCommand, '>')){
//TODO: limit identifier-name length to cg_nIdentifierLength and cut name if too long
    m_stCommand.m_nDestination = (strlen(pa_acDest) != 0) ? CStringDictionary::getInstance().insert(pa_acDest) : CStringDictionary::scm_nInvalidStringId;
    m_stCommand.m_nFirstParam = CStringDictionary::scm_nInvalidStringId;
    m_stCommand.m_nSecondParam = CStringDictionary::scm_nInvalidStringId;
    if ( 255 <= m_stCommand.m_oAdditionalParams.getCapacity()) {
      m_stCommand.m_oAdditionalParams.reserve(255);
    }
    m_stCommand.m_acID=0;
#ifdef FORTE_SUPPORT_MONITORING
	m_stCommand.m_oMonitorResponse.clear();
#endif // FORTE_SUPPORT_MONITORING
    char *acRequestPartLeft = parseRequest(pa_acCommand, m_stCommand);
    if(0 != acRequestPartLeft){
      acRequestPartLeft = strchr(acRequestPartLeft, '<');
      if(0 != acRequestPartLeft){
        acRequestPartLeft++; //point to the next character after the <
      }
      // we got the command for execution
      // now check the rest of the data
      switch (m_stCommand.m_nCMD){
        case cg_nMGM_CMD_Create_Group: // create something
          parseCreateData(acRequestPartLeft, m_stCommand);
          break;
        case cg_nMGM_CMD_Delete_Group: //delete something
          parseDeleteData(acRequestPartLeft, m_stCommand);
          break;
        case cg_nMGM_CMD_Start:
        case cg_nMGM_CMD_Stop:
        case cg_nMGM_CMD_Kill:
        case cg_nMGM_CMD_Reset:
          parseAdditionalStateCommandData(acRequestPartLeft, m_stCommand);
          break;
        case cg_nMGM_CMD_Read:
          parseReadData(acRequestPartLeft, m_stCommand);
          break;
        case cg_nMGM_CMD_Write:
          parseWriteData(acRequestPartLeft, m_stCommand);
          break;
        case cg_nMGM_CMD_Query_Group: // query something
          parseQueryData(acRequestPartLeft, m_stCommand);
          break;
        default:
          break;
      }

      if(cg_nMGM_CMD_INVALID != m_stCommand.m_nCMD) {
          eResp = m_poDevice.executeMGMCommand(m_stCommand);
      }
    }
    else {
      eResp = e_UNSUPPORTED_CMD;
    }
  }

  return eResp;
}

#ifdef FORTE_SUPPORT_MONITORING

bool DEV_MGR::parseConnectionStarStarData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand){
  bool bRetVal = false;

  DEVLOG_DEBUG(pa_acRequestPartLeft);

  if(!strncmp(" forced=\"", pa_acRequestPartLeft, 9)){
    
    if (pa_acRequestPartLeft[9]=='*' && pa_acRequestPartLeft[10] =='\"') {
      pa_rstCommand.m_oAdditionalParams.assign("*",1);
      bRetVal = true;
    } else if (!strncmp(&pa_acRequestPartLeft[9], "true", 4)) {
      pa_rstCommand.m_oAdditionalParams.assign("true", 4);
      bRetVal = true;
    } else if (!strncmp(&pa_acRequestPartLeft[9],"false", 5)) {
      pa_rstCommand.m_oAdditionalParams.assign("false", 5);
      bRetVal = true;
    }
  }

  if (!bRetVal) {
    pa_rstCommand.m_oAdditionalParams.clear();
  }
  return bRetVal;
}

bool DEV_MGR::parseMonitoringData(char *pa_acRequestPartLeft, SManagementCMD &pa_rstCommand){
  bool bRetVal = false;
  if(!strncmp("Watch Source=\"", pa_acRequestPartLeft, 14)){
    int i;
    //FIXME handle resource or device inputs as connection sources (i.e., will have no dot)
    pa_rstCommand.m_nFirstParam = getConnectionEndPointIdentifier(&(pa_acRequestPartLeft[14]), i);
    char *acBuf = strchr(&(pa_acRequestPartLeft[i + 16]), '\"');
    if(acBuf != 0){
      pa_rstCommand.m_nSecondParam = getConnectionEndPointIdentifier(&(acBuf[1]), i);
      bRetVal = true;
    }
  }
  return bRetVal;
}

void DEV_MGR::generateMonitorResponse(EMGMResponse pa_eResp, SManagementCMD &pa_stCMD){
  RESP().clear();
  if(e_RDY != pa_eResp){
    RESP().append("<Response ID=\"");
    RESP().append(pa_stCMD.m_acID);
    RESP().append("\"");
    RESP().append(" Reason=\"");
    RESP().append(scm_sMGMResponseTexts[pa_eResp]);
    RESP().append("\">\n  ");
    RESP().append("\n</Response>");
  }else{
//    CIEC_STRING s;
//    CIEC_STRING *response = pa_stCMD.response;
    //DEVLOG_DEBUG("generateMonitorResponse %d, %d, %s \n", strlen(response->getValue()), response->length(), response->getValue());
    TForteInt16 size = pa_stCMD.m_oMonitorResponse.length() + strlen(pa_stCMD.m_acID) + 74;
    RESP().reserve(size);
    //DEVLOG_DEBUG("generateMonitorResponse after reserve %d \n", size);

    RESP().clear();
    RESP().append("<Response ID=\"");
    RESP().append(pa_stCMD.m_acID);
    RESP().append("\"");
    RESP().append(">\n  ");
    if((pa_stCMD.m_nCMD == cg_nMGM_CMD_Monitoring_Read_Watches) ||
       (pa_stCMD.m_nCMD == cg_nMGM_CMD_Monitoring_Get_Watches)){
      RESP().append("<Watches>\n    ");
      RESP().append(pa_stCMD.m_oMonitorResponse.getValue());
      RESP().append("\n  </Watches>");
    }
    RESP().append("\n</Response>");
  }
  pa_stCMD.m_oMonitorResponse.clear();
}
#endif // FORTE_SUPPORT_MONITORING

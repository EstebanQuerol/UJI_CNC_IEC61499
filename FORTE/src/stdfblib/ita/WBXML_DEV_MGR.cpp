/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <string.h>
#include "WBXML_DEV_MGR.h"
#include "../../core/device.h"
#include <stdio.h>
DEFINE_FIRMWARE_FB(WBXML_DEV_MGR, g_nStringIdWBXML_DEV_MGR)

const CStringDictionary::TStringId WBXML_DEV_MGR::scm_aunEINameIds[2] = { g_nStringIdINIT, g_nStringIdREQ };
const TDataIOID WBXML_DEV_MGR::scm_anEIWith[6] = { 0, 255, 0, 1, 2, 255 };
const TForteInt16 WBXML_DEV_MGR::scm_anEIWithIndexes[2] = { 0, 2 };
const CStringDictionary::TStringId WBXML_DEV_MGR::scm_aunEONameIds[2] = { g_nStringIdINITO, g_nStringIdCNF };
const TDataIOID WBXML_DEV_MGR::scm_anEOWith[4] = { 0, 255, 1, 255 };
const TForteInt16 WBXML_DEV_MGR::scm_anEOWithIndexes[3] = { 0, 2, -1 };
const CStringDictionary::TStringId WBXML_DEV_MGR::scm_aunDINameIds[3] = { g_nStringIdQI, g_nStringIdDST, g_nStringIdRQST };
const CStringDictionary::TStringId WBXML_DEV_MGR::scm_aunDIDataTypeIds[] = { g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdSTRING };
const CStringDictionary::TStringId WBXML_DEV_MGR::scm_aunDONameIds[2] = { g_nStringIdQO, g_nStringIdRESP };
const CStringDictionary::TStringId WBXML_DEV_MGR::scm_aunDODataTypeIds[] = { g_nStringIdBOOL, g_nStringIdSTRING };

const SFBInterfaceSpec WBXML_DEV_MGR::scm_stFBInterfaceSpec = { 2, scm_aunEINameIds, scm_anEIWith, scm_anEIWithIndexes, 2, scm_aunEONameIds, scm_anEOWith, scm_anEOWithIndexes, 3, scm_aunDINameIds, scm_aunDIDataTypeIds, 2, scm_aunDONameIds, scm_aunDODataTypeIds,
    0,
    0 };

void WBXML_DEV_MGR::executeEvent(int pa_nEIID){
  if(csm_nEventINITID == pa_nEIID){
    QO() = QI();
    //up to now I dont know what to do on init
    sendOutputEvent(csm_nEventINITOID);
  }
  else if(csm_nEventREQID == pa_nEIID){
    if(true == QI()){
      executeRQST();
    }
    //TODO: if QI not true send suitable response
    sendOutputEvent(csm_nEventCNFID);
  }
}

void WBXML_DEV_MGR::executeRQST(void){
  char acID[7]; //seven characters should be sufficient for holding the id

  SManagementCMD theCommand;
  EMGMResponse resp = e_INVALID_OBJECT;

  theCommand.m_nDestination = (DST().length() != 0) ? CStringDictionary::getInstance().insert(DST().getValue()) : CStringDictionary::scm_nInvalidStringId;

  theCommand.m_nFirstParam = CStringDictionary::scm_nInvalidStringId;
  theCommand.m_nSecondParam = CStringDictionary::scm_nInvalidStringId;
  theCommand.m_sAdditionalParams[0] = '\0';

  char *acRequest = RQST().getValue();
  unsigned int nChildStart = parseRequestTag(acID, theCommand.m_nCMD);

  switch (theCommand.m_nCMD){
    case cg_nMGM_CMD_Create_Group: // create something
      theCommand.m_nCMD = cg_nMGM_CMD_INVALID;
      if(0 != nChildStart){
        switch (acRequest[nChildStart]){
          case scm_nFBTagId + scm_nItemHasAttribs: // we have an FB to Create
            if(parseFBInstanceData(nChildStart, theCommand)){
              theCommand.m_nCMD = cg_nMGM_CMD_Create_FBInstance;
            }
            break;
          case scm_nConnectionTagId + scm_nItemHasAttribs: // we have an Connection to Create
            if(parseConnectionData(nChildStart, theCommand)){
              theCommand.m_nCMD = cg_nMGM_CMD_Create_Connection;
            }
            break;
          default:
            break;
        }
      }
      break;
    case cg_nMGM_CMD_Delete_Group: //delete something
      theCommand.m_nCMD = cg_nMGM_CMD_INVALID;
      if(0 != nChildStart){
        switch (acRequest[nChildStart]){
          case scm_nFBTagId + scm_nItemHasAttribs: // we have an FB to delete
            if(parseFBInstanceData(nChildStart, theCommand)){
              theCommand.m_nCMD = cg_nMGM_CMD_Delete_FBInstance;
            }
            break;
          case scm_nConnectionTagId + scm_nItemHasAttribs: // we have an Connection to delete
            if(parseConnectionData(nChildStart, theCommand)){
              theCommand.m_nCMD = cg_nMGM_CMD_Delete_Connection;
            }
            break;
          default:
            break;
        }
      }
      break;
    case cg_nMGM_CMD_Start:
    case cg_nMGM_CMD_Stop:
    case cg_nMGM_CMD_Kill:
    case cg_nMGM_CMD_Reset:
      if(0 != nChildStart){
        //if we have an additional xml token parse if it is an FB definition
        if(!parseFBInstanceData(nChildStart, theCommand)){
          theCommand.m_nCMD = cg_nMGM_CMD_INVALID;
        }
      }
      break;
    case cg_nMGM_CMD_Read:
      theCommand.m_nCMD = cg_nMGM_CMD_INVALID;
      if(0 != nChildStart){
        //if we have an additional xml token parse if it is an FB definition
        if(parseConnectionData(nChildStart, theCommand)){
          theCommand.m_nCMD = cg_nMGM_CMD_Read;
        }
      }
      break;
    case cg_nMGM_CMD_Write:
      //We need an additional xml connection token parse if it is an connection definition
      theCommand.m_nCMD = cg_nMGM_CMD_INVALID;
      if(0 != nChildStart){
        if(parseWriteData(nChildStart, theCommand)){
          theCommand.m_nCMD = cg_nMGM_CMD_Write;
        }
      }
      break;
    case cg_nMGM_CMD_Query_Group: // query something
      theCommand.m_nCMD = cg_nMGM_CMD_INVALID;
      if(0 != nChildStart){
        //TODO define and implement QUERY command
      }
      break;
    default:
      break;
  }
  if(cg_nMGM_CMD_INVALID != theCommand.m_nCMD){
    resp = m_poDevice.executeMGMCommand(theCommand);
  }

  if(0 < strlen(theCommand.m_sAdditionalParams)){
    //TODO implement long response, maybe combine with other function for more efficient response generation
    //generateResponse(acID, resp, theCommand);
  }
  else{
    generateResponse(acID, resp);
  }
}

unsigned int WBXML_DEV_MGR::parseRequestTag(char *pa_acID, EMGMCommandType &pa_nRequestedCommand){
  unsigned int nRetVal = 0;
  char *acRequest = RQST().getValue();
  TForteUInt16 unRqstLen = RQST().length();

  pa_nRequestedCommand = cg_nMGM_CMD_INVALID;

  if(6 < unRqstLen){ //the minimal length a request needs to have to be a valid request (e.g., start)
    if(*acRequest & (scm_nRequestTagId + scm_nItemHasAttribs)){
      bool bHasChildren = (scm_nItemHasChildren == (*acRequest & scm_nItemHasChildren));
      if(scm_nIDAttribId == acRequest[1]){
        unsigned int unRunner = 1;
        //TODO check if there is an integer identifier before the integer value
        //extract ID value
        int i = 0;
        do{
          unRunner++;
          if(unRunner > unRqstLen){
            return nRetVal;
          }
          pa_acID[i] = acRequest[unRunner];
        } while(acRequest[unRunner] & 0x80); //if the highest bit is true the next value still belongs to the ID value
        unRunner++;
        if(unRqstLen >= unRunner + 2){ // the minimal remaining part of the request contains additional 2 bytes
          if(scm_nActionAttribId == acRequest[unRunner]){
            unRunner++;
            if((5 <= acRequest[unRunner]) && (acRequest[unRunner] <= 5 + 8)){ //Currently there are 9 commands starting at identifier 5
              pa_nRequestedCommand = static_cast<EMGMCommandType>(acRequest[unRunner] - 5);
              if(bHasChildren){
                unRunner += 2;
                if(unRunner < unRqstLen){
                  nRetVal = unRunner;
                }
                else{
                  pa_nRequestedCommand = cg_nMGM_CMD_INVALID;
                }
              }
            }
          }
        }
      }
    }
  }

  return nRetVal;
}

bool WBXML_DEV_MGR::parseFBInstanceData(unsigned int pa_unChildStart, SManagementCMD &pa_rstCommand){
  bool bRetVal = false;

  char *acRequest = RQST().getValue();
  TForteUInt16 unRqstLen = RQST().length();

  if(unRqstLen > pa_unChildStart + 4)
    if(((scm_nFBTagId + scm_nItemHasAttribs) & acRequest[pa_unChildStart]) && (scm_nNameAttribId == acRequest[pa_unChildStart + 1]) && (scm_nEmbeddedStringMarker == acRequest[pa_unChildStart + 2])){

      pa_unChildStart += 3;
      if('*' != acRequest[pa_unChildStart]){
        pa_rstCommand.m_nFirstParam = CStringDictionary::getInstance().insert(&acRequest[pa_unChildStart]);
        pa_unChildStart += strlen(&acRequest[pa_unChildStart]) + 1; //plus one for the trailing 0 of the embedded string
      }
      else{
        pa_unChildStart += 2; //one for the * and one for the trailing 0 of the embedded string
      }

      if((unRqstLen > pa_unChildStart + 3) && (scm_nTypeAttribId == acRequest[pa_unChildStart]) && (scm_nEmbeddedStringMarker == acRequest[pa_unChildStart])){
        if('*' != acRequest[pa_unChildStart]){
          pa_rstCommand.m_nSecondParam = CStringDictionary::getInstance().insert(&acRequest[pa_unChildStart]);
          pa_unChildStart += strlen(&acRequest[pa_unChildStart]) + 1; //plus one for the trailing 0 of the embedded string
        }
        else{
          pa_unChildStart += 2; //one for the * and one for the trailing 0 of the embedded string
        }
        //TODO handle application name
        bRetVal = true;
      }
    }
  return bRetVal;

}

bool WBXML_DEV_MGR::parseConnectionData(unsigned int pa_unChildStart, SManagementCMD &pa_rstCommand){
  bool bRetVal = false;
  char *acRequest = RQST().getValue();
  TForteUInt16 unRqstLen = RQST().length();

  if(unRqstLen > pa_unChildStart + 4)
    if(((scm_nConnectionTagId + scm_nItemHasAttribs) & acRequest[pa_unChildStart]) && (scm_nSourceAttribId == acRequest[pa_unChildStart + 1]) && (scm_nEmbeddedStringMarker == acRequest[pa_unChildStart + 2])){
      unsigned int i;
      pa_unChildStart += 3;
      if('*' != acRequest[pa_unChildStart]){
        pa_rstCommand.m_nFirstParam = getConnectionEndPointIdentifier(&acRequest[pa_unChildStart], i);
        pa_unChildStart += i;
      }
      else{
        pa_unChildStart += 2; //one for the * and one for the trailing 0 of the embedded string
      }

      if((unRqstLen > pa_unChildStart + 3) && (scm_nDestinationAttribId == acRequest[pa_unChildStart]) && (scm_nEmbeddedStringMarker == acRequest[pa_unChildStart])){
        if('*' != acRequest[pa_unChildStart]){
          pa_rstCommand.m_nSecondParam = getConnectionEndPointIdentifier(&acRequest[pa_unChildStart], i);
        }
        bRetVal = true;
      }
    }
  return bRetVal;

}

TConnectionID WBXML_DEV_MGR::getConnectionEndPointIdentifier(char *pa_acIdentifierStart, unsigned int &pa_nCharsUsed){
  TConnectionID nRetVal = CStringDictionary::scm_nInvalidStringId;
  pa_nCharsUsed = 0;

  if(pa_acIdentifierStart[0] != '*'){
    char *acDot = strchr(pa_acIdentifierStart, '.');
    if(0 != acDot){
      acDot = '\0';
      acDot++;
      nRetVal = CConnection::genConPortId(CStringDictionary::getInstance().insert(pa_acIdentifierStart), CStringDictionary::getInstance().insert(acDot));
      acDot--;
      *acDot = '.';
      pa_nCharsUsed = strlen(pa_acIdentifierStart) + 1;

    }
  }
  else{
    pa_nCharsUsed = 2;
  }
  return nRetVal;
}

bool WBXML_DEV_MGR::parseWriteData(unsigned int pa_unChildStart, SManagementCMD &pa_rstCommand){
  bool bRetVal = false;
  char *acRequest = RQST().getValue();
  TForteUInt16 unRqstLen = RQST().length();

  if(unRqstLen > pa_unChildStart + 4)
    if(((scm_nConnectionTagId + scm_nItemHasAttribs) & acRequest[pa_unChildStart]) && (scm_nSourceAttribId == acRequest[pa_unChildStart + 1]) && (scm_nEmbeddedStringMarker == acRequest[pa_unChildStart + 2])){
      pa_unChildStart += 3;
      acRequest += pa_unChildStart;
      pa_unChildStart += strlen(acRequest) + 1;

      //first retreive the data for the param
      if('&' == *acRequest){
        do{
          acRequest++;
        } while(';' != *acRequest);
        acRequest++;
      }
      if('\'' == *acRequest){
        acRequest++;
      }

      unsigned int i;
      // TODO: check if "-character should also be trimmed from pa_acRequestPartLeft
      for(; *acRequest != '\0'; ++acRequest, ++i){
        if('&' == *acRequest){
          do{
            acRequest++;
          } while(';' != *acRequest);
          acRequest += 2; //go beyound the ; and the following "
          break;
        }
        if('\'' == *acRequest){
          acRequest++;
          break;
        }
        pa_rstCommand.m_sAdditionalParams[i] = *acRequest;
      }
      pa_rstCommand.m_sAdditionalParams[i + 1] = '\0';

      acRequest = RQST().getValue();

      if((unRqstLen > pa_unChildStart + 3) && (scm_nDestinationAttribId == acRequest[pa_unChildStart]) && (scm_nEmbeddedStringMarker == acRequest[pa_unChildStart])){
        if('*' != acRequest[pa_unChildStart]){
          pa_rstCommand.m_nSecondParam = getConnectionEndPointIdentifier(&acRequest[pa_unChildStart], i);
        }
        bRetVal = true;
      }
    }
  return bRetVal;
}

void WBXML_DEV_MGR::generateResponse(const char *pa_acID, EMGMResponse pa_eResp){
  RESP().reserve(6 + 7);
  char *acBuffer = RESP().getValue();

  acBuffer[0] = scm_nReponseTagId + scm_nItemHasAttribs;
  acBuffer[1] = scm_nIDAttribId;
  acBuffer += 2;
  unsigned int unRunner = 0;
  acBuffer[unRunner] = pa_acID[unRunner];
  while(pa_acID[unRunner] & 0x80)         //as long as the highest bit is true add the id value to the respons
  {
    unRunner++;
    acBuffer[unRunner] = pa_acID[unRunner];
  }
  unRunner++;

  if(e_RDY != pa_eResp){
    acBuffer[unRunner] = scm_nReasonAttribId;
    unRunner++;
    acBuffer[unRunner] = pa_eResp + 5;         //Attrib value constant starts at 5
    unRunner++;
  }

  acBuffer[unRunner] = scm_nEndOfItemMarker;

  RESP().assign(RESP().getValue(), unRunner + 2);
}


//TODO implement long response
//void WBXML_DEV_MGR::generateResponse(const char *pa_acID, EMGMResponse pa_eResp, SManagementCMD &pa_stCMD){
//  char cResponse[255] = "<Response ID=\"";
//  strcat(cResponse, pa_acID);
//  strcat(cResponse, "\"");
//  if(e_RDY != pa_eResp){
//    strcat(cResponse, " Reason=\"");
//    strcat(cResponse, scm_sMGMResponseTexts[pa_eResp]);
//    strcat(cResponse, "\">\n  ");
//  }
//  else{
//    strcat(cResponse, ">\n  ");
//    if(pa_stCMD.m_nCMD == cg_nMGM_CMD_QUERY_Connection){
//      strcat(cResponse, "<EndpointList>\n    ");
//      strcat(cResponse, pa_stCMD.m_sAdditionalParams);
//      strcat(cResponse, "\n  </EndpointList>");
//    }
//    else if(pa_stCMD.m_nCMD == cg_nMGM_CMD_QUERY_FB){
//      if((CStringDictionary::scm_nInvalidStringId != pa_stCMD.m_nSecondParam) && (CStringDictionary::scm_nInvalidStringId != pa_stCMD.m_nFirstParam)){
//        strcat(cResponse, "<FB Name=\"");
//        strcat(cResponse, pa_stCMD.m_sAdditionalParams);
//        strcat(cResponse, "\" Type=\"");
//        strcat(cResponse, CStringDictionary::getInstance().get(pa_stCMD.m_nSecondParam));
//        strcat(cResponse, "\" />");
//      }
//      else{
//        strcat(cResponse, "<FBList>\n    ");
//        strcat(cResponse, pa_stCMD.m_sAdditionalParams);
//        strcat(cResponse, "\n  </FBList>");
//      }
//    }
//    else if(pa_stCMD.m_nCMD == cg_nMGM_CMD_Read){
//      strcat(cResponse, "<Connection Source=\"");
//      if(CStringDictionary::scm_nInvalidStringId != pa_stCMD.m_nFirstParam){
//        strcat(cResponse, CStringDictionary::getInstance().get(CConnection::extractFBNameId(pa_stCMD.m_nFirstParam)));
//        strcat(cResponse, ".");
//        strcat(cResponse, CStringDictionary::getInstance().get(CConnection::extractPortNameId(pa_stCMD.m_nFirstParam)));
//      }
//      strcat(cResponse, "\" Destination=\"");
//      strcat(cResponse, pa_stCMD.m_sAdditionalParams);
//      strcat(cResponse, "\" />");
//    }
//    else if(pa_stCMD.m_nCMD == cg_nMGM_CMD_QUERY_FBTypes){
//      strcat(cResponse, "<FBList>\n    ");
//      strcat(cResponse, pa_stCMD.m_sAdditionalParams);
//      strcat(cResponse, "\n  </FBList>");
//    }
//    else if(pa_stCMD.m_nCMD == cg_nMGM_CMD_QUERY_DTTypes){
//      strcat(cResponse, "<DTList>\n    ");
//      strcat(cResponse, pa_stCMD.m_sAdditionalParams);
//      strcat(cResponse, "\n  </DTList>");
//    }
//  }
//  strcat(cResponse, "\n</Response>");
//  RESP = cResponse;
//}

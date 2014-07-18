/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "class1objhand.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "class1objhand_gen.cpp"
#endif
#include "if2indco.h"
#include "typelib.h"
#include "resource.h"
#include "adapterconn.h"

C61499Class1ObjectHandler::C61499Class1ObjectHandler(CResource& pa_roHandlerOwner) :
    m_roHandlerOwner(pa_roHandlerOwner)
#ifdef FORTE_SUPPORT_MONITORING
        , m_stTriggerEvent(0, 0)
#endif
{
}

C61499Class1ObjectHandler::~C61499Class1ObjectHandler(){
  deleteWholeFBNetwork();
}

EMGMResponse C61499Class1ObjectHandler::executeMGMCommand(SManagementCMD &pa_oCommand){
  EMGMResponse eRetVal = e_INVALID_DST;

  if(CStringDictionary::scm_nInvalidStringId == pa_oCommand.m_nDestination){
    switch (pa_oCommand.m_nCMD){
      // This is only needed for class2 object handler
      //case cg_nMGM_CMD_Create_FBType:
      //  break;
      case cg_nMGM_CMD_Create_FBInstance:
        eRetVal = createFB(static_cast<CStringDictionary::TStringId>(pa_oCommand.m_nFirstParam & 0xFFFFFFFF), static_cast<CStringDictionary::TStringId>(pa_oCommand.m_nSecondParam & 0xFFFFFFFF));
        break;
      case cg_nMGM_CMD_Delete_FBInstance:
        eRetVal = deleteFB((pa_oCommand.m_nFirstParam & 0xFFFFFFFF));
        break;
      case cg_nMGM_CMD_Create_Connection:
        eRetVal = createConnection(pa_oCommand.m_nFirstParam, pa_oCommand.m_nSecondParam);
        break;
      case cg_nMGM_CMD_Delete_Connection:
        eRetVal = deleteConnection(pa_oCommand.m_nFirstParam, pa_oCommand.m_nSecondParam);
        break;
      case cg_nMGM_CMD_Delete_AllFBInstances:
        eRetVal = deleteWholeFBNetwork();
        break;
      case cg_nMGM_CMD_Read:
        eRetVal = readValue(pa_oCommand);
        break;
      case cg_nMGM_CMD_Write:
        eRetVal = writeValue(pa_oCommand);
        break;
      case cg_nMGM_CMD_QUERY_FB:
        eRetVal = executeQueryReq(pa_oCommand);
        break;
      case cg_nMGM_CMD_QUERY_Connection:
        eRetVal = executeQueryCon(pa_oCommand);
        break;
      case cg_nMGM_CMD_QUERY_FBTypes:
        pa_oCommand.m_oAdditionalParams.reserve(g_nStringIdNextFreeId / 2);
        eRetVal = queryTypeList(pa_oCommand, CTypeLib::getFBLibStart());
        break;
      case cg_nMGM_CMD_QUERY_DTTypes:
        eRetVal = queryTypeList(pa_oCommand, CTypeLib::getDTLibStart());
        break;
      case cg_nMGM_CMD_QUERY_AdapterTypes:
        eRetVal = queryTypeList(pa_oCommand, CTypeLib::getAdapterLibStart());
        break;
      case cg_nMGM_CMD_Start:
      case cg_nMGM_CMD_Stop:
      case cg_nMGM_CMD_Kill:
      case cg_nMGM_CMD_Reset:
        if(CStringDictionary::scm_nInvalidStringId == (pa_oCommand.m_nFirstParam & 0xFFFFFFFF)){
          eRetVal = m_roHandlerOwner.changeFBExecutionState(pa_oCommand.m_nCMD);
        }
        else{
          CFunctionBlock *fb = getFB((pa_oCommand.m_nFirstParam & 0xFFFFFFFF));
          if(0 != fb){
            eRetVal = fb->changeFBExecutionState(pa_oCommand.m_nCMD);
          }
          else{
            eRetVal = e_NO_SUCH_OBJECT;
          }
        }
        break;
#ifdef FORTE_SUPPORT_MONITORING
      case cg_nMGM_CMD_Monitoring_Add_Watch:
        eRetVal = addWatch(pa_oCommand.m_nFirstParam);
        break;
      case cg_nMGM_CMD_Monitoring_Remove_Watch:
        eRetVal = removeWatch(pa_oCommand.m_nFirstParam);
        break;
      case cg_nMGM_CMD_Monitoring_Read_Watches:
        eRetVal = readWatches(pa_oCommand.m_oMonitorResponse);
        break;
      case cg_nMGM_CMD_Monitoring_Get_Watches:
        eRetVal = getWatches(pa_oCommand.m_oMonitorResponse, pa_oCommand.m_oAdditionalParams.getValue()[0]);
        break;
      case cg_nMGM_CMD_Monitoring_Force:
        eRetVal = forceValue(pa_oCommand);
        break;
      case cg_nMGM_CMD_Monitoring_ClearForce:
        eRetVal = clearForce(pa_oCommand.m_nFirstParam);
        break;
      case cg_nMGM_CMD_Monitoring_Trigger_Event:
        eRetVal = triggerEvent(pa_oCommand.m_nFirstParam);
        break;
      case cg_nMGM_CMD_Monitoring_Reset_Event_Count:
        eRetVal = resetEventCount(pa_oCommand.m_nFirstParam);
        break;
#endif
      default:
        eRetVal = e_UNSUPPORTED_CMD;
        break;
    }
  }
  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::createFB(CStringDictionary::TStringId pa_nFBNameId, CStringDictionary::TStringId pa_nFBTypeId){
  EMGMResponse retval = e_RDY;
  if(0 == getFB(pa_nFBNameId)){ // test if the resource does not contain any FB with the same name

    CFunctionBlock *newFB = CTypeLib::createFB(pa_nFBNameId, pa_nFBTypeId, &m_roHandlerOwner);
    if(0 != newFB){ //we could create a FB now add it to the list of contained resources
      retval = addFB(newFB);
    }
    else
      retval = CTypeLib::getLastError();
  }
  else{
    retval = e_INVALID_STATE; // a FB with this name is already existing in this resource
  }

  return retval;
}

EMGMResponse C61499Class1ObjectHandler::deleteFB(CStringDictionary::TStringId pa_nFBNameId){
  EMGMResponse retval = e_NO_SUCH_OBJECT;

  if((CStringDictionary::scm_nInvalidStringId != pa_nFBNameId) && (!m_lstpoObjectInstanceList.isEmpty())){

    TObjInstanceList::Iterator itRunner = m_lstpoObjectInstanceList.begin();
    TObjInstanceList::Iterator itRefNode = m_lstpoObjectInstanceList.end();

    while(itRunner != m_lstpoObjectInstanceList.end()){
      if((*itRunner)->getInstanceNameId() == pa_nFBNameId){
        if((*itRunner)->isCurrentlyDeleteable()){
          CTypeLib::deleteFB(*itRunner);
          if(itRefNode == m_lstpoObjectInstanceList.end()){
            //we have the first entry in the list
            m_lstpoObjectInstanceList.pop_front();
          }
          else{
            m_lstpoObjectInstanceList.eraseAfter(itRefNode);
          }
          retval = e_RDY;
        }
        else{
          retval = e_INVALID_STATE;
        }
        break;
      }

      itRefNode = itRunner;
      ++itRunner;
    }
  }

  return retval;
}

EMGMResponse C61499Class1ObjectHandler::deleteConnection(TConnectionID pa_nSrcId, TConnectionID pa_nDestId){
  EMGMResponse retval = e_NO_SUCH_OBJECT;

  CFunctionBlock *srcFB = static_cast<CFunctionBlock*>(&m_roHandlerOwner);
  CStringDictionary::TStringId nFBIdBuf = CConnection::extractFBNameId(pa_nSrcId);
  if(CStringDictionary::scm_nInvalidStringId != nFBIdBuf){
    srcFB = getFB(nFBIdBuf);
  }

  CFunctionBlock *dstFB = getFB(CConnection::extractFBNameId(pa_nDestId));

  if((0 != srcFB) && (0 != dstFB)){ // check if the named fbs are existing in this resource
    TConnectionList::Iterator itRunner = m_lstpoConnectionList.begin();
    TConnectionList::Iterator itRefNode = m_lstpoConnectionList.end();

    while(itRunner != m_lstpoConnectionList.end()){
      if((*itRunner)->getSourceId() == pa_nSrcId){
        CConnection *poConToDel = *itRunner;
        retval = poConToDel->disconnect(pa_nDestId, *srcFB, *dstFB);

        if(poConToDel->isEmpty()){
          //this was the last fan of the connection remove it from the list
          CTypeLib::deleteConnection(poConToDel); // if yes delete the connection as it point nowhere
          if(itRefNode == m_lstpoConnectionList.end()){
            m_lstpoConnectionList.pop_front();
          }
          else{
            m_lstpoConnectionList.eraseAfter(itRefNode);
          }
        }

        break;
      }

      itRefNode = itRunner;
      ++itRunner;
    }
  }
  return retval;
}

EMGMResponse C61499Class1ObjectHandler::addFB(CFunctionBlock* pa_poFuncBlock){
  EMGMResponse eRetVal = e_RDY;
  if(0 != pa_poFuncBlock){
    m_lstpoObjectInstanceList.push_back(pa_poFuncBlock);
  }
  else{
    eRetVal = e_INVALID_OBJECT;
  }
  return eRetVal;
}

CFunctionBlock* C61499Class1ObjectHandler::getFB(CStringDictionary::TStringId pa_nFBInstanceNameId){
  CFunctionBlock *pRetVal = 0;

//TODO: Check *it on null

  if(CStringDictionary::scm_nInvalidStringId != pa_nFBInstanceNameId){
    for(TObjInstanceList::Iterator it = m_lstpoObjectInstanceList.begin(); it != m_lstpoObjectInstanceList.end(); ++it){
      if(pa_nFBInstanceNameId == ((*(*it)).getInstanceNameId())){
        pRetVal = (*it);
        break;
      }
    }
  }

  return pRetVal;
}

EMGMResponse C61499Class1ObjectHandler::createConnection(TConnectionID pa_nSrcId, TConnectionID pa_nDestId){
  EMGMResponse retval = e_NO_SUCH_OBJECT;

  CFunctionBlock *srcFB = static_cast<CFunctionBlock*>(&m_roHandlerOwner);
  CStringDictionary::TStringId nFBIdBuf = CConnection::extractFBNameId(pa_nSrcId);
  if(CStringDictionary::scm_nInvalidStringId != nFBIdBuf){
    srcFB = getFB(nFBIdBuf);
  }

  CFunctionBlock *dstFB = getFB(CConnection::extractFBNameId(pa_nDestId));

  CConnection *newConnection = 0;
  if((0 != srcFB) && (0 != dstFB)){ // check if the named fbs are existing in this resource
    newConnection = getConnection(pa_nSrcId); //try to find if there is already a connection with given source

    if(0 == newConnection){
      // there is no connection with given source try to create a new one
      CStringDictionary::TStringId unOutNameId = CConnection::extractPortNameId(pa_nSrcId);
      if(srcFB == static_cast<CFunctionBlock*>(&m_roHandlerOwner)){
        if(0 != m_roHandlerOwner.getDataInput(unOutNameId)){
          newConnection = new CInterface2InternalDataConnection(pa_nSrcId, *srcFB, pa_nDestId, *dstFB);
        }
      }
      else{
        if(cg_nInvalidEventID != srcFB->getEOID(unOutNameId)){
          newConnection = new CEventConnection(pa_nSrcId, *srcFB, pa_nDestId, *dstFB); // it was an event connection to create
        }
        else{
          if(0 != srcFB->getDataOutput(unOutNameId)){
            newConnection = new CDataConnection(pa_nSrcId, *srcFB, pa_nDestId, *dstFB); // it was an data connection to create
          }
          else{
            if(0 != srcFB->getAdapter(unOutNameId)){
              newConnection = new CAdapterConnection(pa_nSrcId, *srcFB, pa_nDestId, *dstFB);
            }
          }
        }
      }
      if(0 != newConnection){
        if(newConnection->isEmpty()){ //Check if it was the only destination this connection had
          delete newConnection; // if yes delete the connection as it point nowhere
        }
        else{
          retval = e_RDY;
          m_lstpoConnectionList.push_back(newConnection);
        }
      }
    }
    else{ // Connection exists, Dest. added to the Dest.-List
      retval = newConnection->connectFannedOut(pa_nDestId, *srcFB, *dstFB); //establish the connection
    }
  }
  return retval;
}

CConnection* C61499Class1ObjectHandler::getConnection(TConnectionID pa_nSrcId){
  CConnection* pRetVal = 0;
  for(TConnectionList::Iterator it = m_lstpoConnectionList.begin(); it != m_lstpoConnectionList.end(); ++it){
    if(pa_nSrcId == (*(*it)).getSourceId()){
      pRetVal = (*it);
      break;
    }
  }
  return pRetVal;
}

EMGMResponse C61499Class1ObjectHandler::changeFBExecutionState(EMGMCommandType pa_unCommand){
  EMGMResponse eRetVal = e_RDY;

  for(TObjInstanceList::Iterator itRunner(m_lstpoObjectInstanceList.begin()); ((itRunner != m_lstpoObjectInstanceList.end()) && (e_RDY == eRetVal)); ++itRunner){
    eRetVal = (*itRunner)->changeFBExecutionState(pa_unCommand);
  }
  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::deleteWholeFBNetwork(){
  changeFBExecutionState(cg_nMGM_CMD_Kill);

  for(TConnectionList::Iterator itRunner(m_lstpoConnectionList.begin()); itRunner != m_lstpoConnectionList.end(); ++itRunner){
    CTypeLib::deleteConnection(*itRunner);
  }
  m_lstpoConnectionList.clearAll();

  for(TObjInstanceList::Iterator itRunner(m_lstpoObjectInstanceList.begin()); itRunner != m_lstpoObjectInstanceList.end(); ++itRunner){
    CTypeLib::deleteFB(*itRunner);
  }
  m_lstpoObjectInstanceList.clearAll();
  return e_RDY;
}

EMGMResponse C61499Class1ObjectHandler::writeValue(SManagementCMD &pa_oCommand){
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;

  CFunctionBlock *poFB = static_cast<CFunctionBlock*>(&m_roHandlerOwner);
  CStringDictionary::TStringId nFBIdBuf = CConnection::extractFBNameId(pa_oCommand.m_nFirstParam);
  if(CStringDictionary::scm_nInvalidStringId != nFBIdBuf){
    poFB = getFB(nFBIdBuf);
  }

  CIEC_ANY *var = 0;
  if(0 != poFB){
    var = poFB->getVar(CStringDictionary::getInstance().get(CConnection::extractPortNameId(pa_oCommand.m_nFirstParam)));
  }
  if(var != 0){
    if(pa_oCommand.m_oAdditionalParams.length() > 0){
      if(pa_oCommand.m_oAdditionalParams.length() == var->fromString(pa_oCommand.m_oAdditionalParams.getValue())){
        //if we cannot parse the full value the value is not valid
        eRetVal = e_RDY;
      }
      else{
        eRetVal = e_BAD_PARAMS;
      }
    }
    else{
      eRetVal = e_BAD_PARAMS; // 0 is not supported in the fromString method
    }
  }
  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::readValue(SManagementCMD &pa_oCommand){
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;

  CFunctionBlock *poFB = static_cast<CFunctionBlock*>(&m_roHandlerOwner);
  CStringDictionary::TStringId nFBIdBuf = CConnection::extractFBNameId(pa_oCommand.m_nFirstParam);
  if(CStringDictionary::scm_nInvalidStringId != nFBIdBuf){
    poFB = getFB(nFBIdBuf);
  }

  if(0 != poFB){
    CIEC_ANY *var = poFB->getVar(CStringDictionary::getInstance().get(CConnection::extractPortNameId(pa_oCommand.m_nFirstParam)));
    if(0 != var){
      int nUsedChars = var->toString(pa_oCommand.m_oAdditionalParams.getValue(), pa_oCommand.m_oAdditionalParams.getCapacity());

      if(-1 != nUsedChars){
        pa_oCommand.m_oAdditionalParams.assign(pa_oCommand.m_oAdditionalParams.getValue(), static_cast<TForteUInt16>(nUsedChars));
        eRetVal = e_RDY;
      }
      else{
        eRetVal = e_INVALID_OBJECT;
      }
    }
  }
  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::executeQueryReq(SManagementCMD &pa_oCommand){ //TConnectionID pa_nSrcId, TConnectionID &pa_nDestId, char *pa_pacResponse) {
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;
  TObjInstanceList::Iterator itRunner = m_lstpoObjectInstanceList.begin();

  pa_oCommand.m_oAdditionalParams.clear();

  if(CStringDictionary::scm_nInvalidStringId == pa_oCommand.m_nFirstParam){
    if(CStringDictionary::scm_nInvalidStringId == pa_oCommand.m_nSecondParam){
      //fetch all fb instancenames of all types and return them
      for(; itRunner != m_lstpoObjectInstanceList.end(); ++itRunner){
        pa_oCommand.m_oAdditionalParams.append((*itRunner)->getInstanceName());
        pa_oCommand.m_oAdditionalParams.append(",", 1);
      }
      eRetVal = e_RDY;
    }
    else{
      //fetch all fb instancenames of the defined type and return them
      CTypeLib::CTypeEntry* FBTypes = CTypeLib::getFBLibStart();
      bool bFoundType = false;
      do{
        if(FBTypes->getTypeNameId() == pa_oCommand.m_nSecondParam){
          bFoundType = true;
          break;
        }
        FBTypes = FBTypes->m_poNext;
      } while(0 != FBTypes);

      if(!bFoundType){
        eRetVal = e_UNSUPPORTED_TYPE;
      }
      else{
        for(; itRunner != m_lstpoObjectInstanceList.end(); ++itRunner){
          if((*itRunner)->getFBTypeId() == pa_oCommand.m_nSecondParam){
            pa_oCommand.m_oAdditionalParams.append((*itRunner)->getInstanceName());
            pa_oCommand.m_oAdditionalParams.append(",", 1);
          }
        }
        eRetVal = e_RDY;
      }
    }
    if(!pa_oCommand.m_oAdditionalParams.empty()){
      pa_oCommand.m_oAdditionalParams.assign(pa_oCommand.m_oAdditionalParams.getValue(), static_cast<TForteUInt16>(pa_oCommand.m_oAdditionalParams.length() - 1));
    }
  }
  else{ // Query whether FB instancename exists + FB Type
    if(CStringDictionary::scm_nInvalidStringId == pa_oCommand.m_nSecondParam){
      const char *acSourceName = CStringDictionary::getInstance().get(static_cast<CStringDictionary::TStringId>(pa_oCommand.m_nFirstParam));
      for(; itRunner != m_lstpoObjectInstanceList.end(); ++itRunner){
        pa_oCommand.m_oAdditionalParams.assign((*itRunner)->getInstanceName(), static_cast<TForteUInt16>(strlen((*itRunner)->getInstanceName())));
        if(!strcmp(pa_oCommand.m_oAdditionalParams.getValue(), acSourceName)){
          //pa_oCommand.m_nSecondParam = (*itRunner)->getFBTypeId();
          pa_oCommand.m_oAdditionalParams.clear(); //clear string (held FB-Name)
          pa_oCommand.m_oAdditionalParams.append(CStringDictionary::getInstance().get(static_cast<CStringDictionary::TStringId>((*itRunner)->getFBTypeId())));
          eRetVal = e_RDY;
          break;
        }
      }

      if(eRetVal != e_RDY){
        pa_oCommand.m_oAdditionalParams.clear(); //clear string (held FB-Name)
        eRetVal = e_NO_SUCH_OBJECT;
      }
    }
    else{ //type and instance-name given -> return status
      const char *acSourceName = CStringDictionary::getInstance().get(static_cast<CStringDictionary::TStringId>(pa_oCommand.m_nFirstParam));
      for(; itRunner != m_lstpoObjectInstanceList.end(); ++itRunner){
        pa_oCommand.m_oAdditionalParams.assign((*itRunner)->getInstanceName(), static_cast<TForteUInt16>(strlen((*itRunner)->getInstanceName())));
        if(!strcmp(pa_oCommand.m_oAdditionalParams.getValue(), acSourceName)){
          pa_oCommand.m_oAdditionalParams.clear(); //clear string (held FB-Name)
          if(pa_oCommand.m_nSecondParam == (*itRunner)->getFBTypeId()){
            switch ((*itRunner)->getState()){
              case CFunctionBlock::e_IDLE:
                pa_oCommand.m_oAdditionalParams.append("IDLE", 4);
                break;
              case CFunctionBlock::e_RUNNING:
                pa_oCommand.m_oAdditionalParams.append("RUNNING", 7);
                break;
              case CFunctionBlock::e_STOPPED:
                pa_oCommand.m_oAdditionalParams.append("STOPPED", 7);
                break;
              case CFunctionBlock::e_KILLED:
                pa_oCommand.m_oAdditionalParams.append("KILLED", 6);
                break;
              default:
                break;
            }
            eRetVal = e_RDY;
          }
          else{
            eRetVal = e_NO_SUCH_OBJECT;
          }
          break;
        }
      }

      if(eRetVal != e_RDY){
        eRetVal = e_NO_SUCH_OBJECT;
      }
    }
  }
  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::executeQueryCon(SManagementCMD &pa_oCommand){
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;
  TConnectionList::Iterator itRunner(m_lstpoConnectionList.begin());

  pa_oCommand.m_oAdditionalParams.reserve(90);
  pa_oCommand.m_oAdditionalParams.clear();

  CIEC_STRING oTempString;
  oTempString.reserve(50);
  oTempString.clear();

  if(CStringDictionary::scm_nInvalidStringId == pa_oCommand.m_nFirstParam){
    if(CStringDictionary::scm_nInvalidStringId == pa_oCommand.m_nSecondParam){ // both parameters are *

      for(; itRunner != m_lstpoConnectionList.end(); ++itRunner){
        oTempString.clear();
        oTempString.append(CStringDictionary::getInstance().get(CConnection::extractFBNameId((*itRunner)->getSourceId())));
        oTempString.append(".", 1);
        oTempString.append(CStringDictionary::getInstance().get(CConnection::extractPortNameId((*itRunner)->getSourceId())));

        CSinglyLinkedList<TConnectionID>::Iterator end = ((*itRunner)->getDestinationIds().end());
        for(CSinglyLinkedList<TConnectionID>::Iterator itDestRunner = ((*itRunner)->getDestinationIds().begin()); itDestRunner != end; ++itDestRunner){
          pa_oCommand.m_oAdditionalParams.append("<Connection Source=\"", 20);
          pa_oCommand.m_oAdditionalParams.append(oTempString.getValue(), oTempString.length());
          pa_oCommand.m_oAdditionalParams.append("\" Destination=\"", 15);
          pa_oCommand.m_oAdditionalParams.append(CStringDictionary::getInstance().get(CConnection::extractFBNameId(*itDestRunner)));
          pa_oCommand.m_oAdditionalParams.append(".", 1);
          pa_oCommand.m_oAdditionalParams.append(CStringDictionary::getInstance().get(CConnection::extractPortNameId(*itDestRunner)));
          pa_oCommand.m_oAdditionalParams.append("\" />\n", 5);
        }
      }
      eRetVal = e_RDY;
    }
    else{ //only first parameter is *

      for(; itRunner != m_lstpoConnectionList.end(); ++itRunner){
        oTempString.clear();
        oTempString.append(CStringDictionary::getInstance().get(CConnection::extractFBNameId((*itRunner)->getSourceId())));
        oTempString.append(".", 1);
        oTempString.append(CStringDictionary::getInstance().get(CConnection::extractPortNameId((*itRunner)->getSourceId())));

        CSinglyLinkedList<TConnectionID>::Iterator end = (*itRunner)->getDestinationIds().end();
        for(CSinglyLinkedList<TConnectionID>::Iterator itDestRunner = ((*itRunner)->getDestinationIds().begin()); itDestRunner != end; ++itDestRunner){
          if(*itDestRunner == pa_oCommand.m_nSecondParam){
            pa_oCommand.m_oAdditionalParams.append(oTempString.getValue(), oTempString.length());
            pa_oCommand.m_oAdditionalParams.append(",", 1);
            break;
          }
        }
      }
      eRetVal = e_RDY;
    }
  }
  else{ //first parameter is != *

    if(CStringDictionary::scm_nInvalidStringId == pa_oCommand.m_nSecondParam){ // only second parameter is *
      for(; itRunner != m_lstpoConnectionList.end(); ++itRunner){
        if((*itRunner)->getSourceId() == pa_oCommand.m_nFirstParam){
          CSinglyLinkedList<TConnectionID>::Iterator end = (*itRunner)->getDestinationIds().end();
          for(CSinglyLinkedList<TConnectionID>::Iterator itDestRunner = (*itRunner)->getDestinationIds().begin(); itDestRunner != end; ++itDestRunner){
            pa_oCommand.m_oAdditionalParams.append(CStringDictionary::getInstance().get(CConnection::extractFBNameId(*itDestRunner)));
            pa_oCommand.m_oAdditionalParams.append(".", 1);
            pa_oCommand.m_oAdditionalParams.append(CStringDictionary::getInstance().get(CConnection::extractPortNameId(*itDestRunner)));
            pa_oCommand.m_oAdditionalParams.append(",", 1);
          }
          break; // all destinations of this connection are included
        }
      }
      eRetVal = e_RDY;
    }
    else{ //both parameters are != 0
      for(; itRunner != m_lstpoConnectionList.end(); ++itRunner){
        if((*itRunner)->getSourceId() == pa_oCommand.m_nFirstParam){
          CSinglyLinkedList<TConnectionID>::Iterator end = (*itRunner)->getDestinationIds().end();
          for(CSinglyLinkedList<TConnectionID>::Iterator itDestRunner = (*itRunner)->getDestinationIds().begin(); itDestRunner != end; ++itDestRunner){
            if((*itDestRunner) == pa_oCommand.m_nSecondParam){
              eRetVal = e_RDY;
              break; // all destinations of this connection are included
            }
          }
          if(e_RDY == eRetVal){
            break;
          }
        }
      }
    }
  }

  if(!pa_oCommand.m_oAdditionalParams.empty()){
    pa_oCommand.m_oAdditionalParams.assign(pa_oCommand.m_oAdditionalParams.getValue(), static_cast<TForteUInt16>(pa_oCommand.m_oAdditionalParams.length() - 1));
  }

  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::queryTypeList(SManagementCMD &pa_oCommand, CTypeLib::CTypeEntry * pa_LibTypeListStart){
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;

  pa_oCommand.m_oAdditionalParams.clear();

  CTypeLib::CTypeEntry *poToFirst = pa_LibTypeListStart;
  if(poToFirst != 0){
    pa_oCommand.m_oAdditionalParams.append(CStringDictionary::getInstance().get(((CTypeLib::CTypeEntry *) poToFirst)->getTypeNameId()));
    while(poToFirst->m_poNext != 0){
      poToFirst = poToFirst->m_poNext;
      pa_oCommand.m_oAdditionalParams.append(",", 1);
      pa_oCommand.m_oAdditionalParams.append(CStringDictionary::getInstance().get(((CTypeLib::CTypeEntry *) poToFirst)->getTypeNameId()));
    }
    eRetVal = e_RDY;
  }
  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::queryTypeVersion(TForteUInt32, char*){
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;
  return eRetVal;
}

#ifdef FORTE_SUPPORT_MONITORING

EMGMResponse C61499Class1ObjectHandler::addWatch(TConnectionID pa_nWatchPointId){
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;

  CFunctionBlock *poFB = getFB(CConnection::extractFBNameId(pa_nWatchPointId));
  if(0 != poFB){
    SFBMonitoringEntry &poFBMonitoringEntry(findOrCreateFBMonitoringEntry(poFB));

    CStringDictionary::TStringId unPortId = CConnection::extractPortNameId(pa_nWatchPointId);
    CIEC_ANY *poDataVal = poFB->getVar(unPortId);
    if(0 != poDataVal){
      addDataWatch(poFBMonitoringEntry, unPortId, poDataVal);
      eRetVal = e_RDY;
    }
    else{
      TEventID unEventId = poFB->getEIID(unPortId);
      if(cg_nInvalidEventID != unEventId){
        addEventWatch(poFBMonitoringEntry, unPortId, poFB->getEIMontiorData(unEventId));
        eRetVal = e_RDY;
      }
      else{
        unEventId = poFB->getEOID(unPortId);
        if(cg_nInvalidEventID != unEventId){
          addEventWatch(poFBMonitoringEntry, unPortId, poFB->getEOMontiorData(unEventId));
          eRetVal = e_RDY;
        }
      }
    }
  }

  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::removeWatch(TConnectionID pa_nWatchPointId){
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;

  CStringDictionary::TStringId unFBInstanceId = CConnection::extractFBNameId(pa_nWatchPointId);
  CStringDictionary::TStringId unPortId = CConnection::extractPortNameId(pa_nWatchPointId);
  TFBMonitoringList::Iterator itRefNode = m_lstFBMonitoringList.end(); //needed for deleting the entry from the list
  TFBMonitoringList::Iterator itRunner = m_lstFBMonitoringList.begin();

  while(itRunner != m_lstFBMonitoringList.end()){
    if(itRunner->m_poFB->getInstanceNameId() == unFBInstanceId){
      SFBMonitoringEntry &poFBMonitoringEntry(*itRunner);

      if(!removeDataWatch(poFBMonitoringEntry, unPortId)){
        if(!removeEventWatch(poFBMonitoringEntry, unPortId)){
          //element is not watched end search and return error
          break;
        }
      }

      if((poFBMonitoringEntry.m_lstWatchedDataPoints.isEmpty()) && (poFBMonitoringEntry.m_lstWatchedEventPoints.isEmpty())){
        //no further values are monitored so remove the entry
        if(itRefNode == m_lstFBMonitoringList.end()){
          //we have the first entry in the list
          m_lstFBMonitoringList.pop_front();
        }
        else{
          m_lstFBMonitoringList.eraseAfter(itRefNode);
        }
      }
      eRetVal = e_RDY;
      break;
    }

    itRefNode = itRunner;
    ++itRunner;
  }
  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::readWatches(CIEC_STRING &pa_roResponse){
  pa_roResponse.clear();
  if(0 == m_roHandlerOwner.getResourcePtr()){
    //we are in the device
    for(TObjInstanceList::Iterator itRunner = m_lstpoObjectInstanceList.begin(); itRunner != m_lstpoObjectInstanceList.end(); ++itRunner){
      ((CResource*) (*itRunner))->getObjectHandler().readResourceWatches(pa_roResponse);
    }

  }
  else{
    //we are within a resource
    readResourceWatches(pa_roResponse);
  }

  return e_RDY;
}

EMGMResponse C61499Class1ObjectHandler::getWatches(CIEC_STRING &pa_roResponse, char pa_cQualifier){
  pa_roResponse.clear();
  if(0 == m_roHandlerOwner.getResourcePtr()){
    //we are in the device
    for(TObjInstanceList::Iterator itRunner = m_lstpoObjectInstanceList.begin(); itRunner != m_lstpoObjectInstanceList.end(); ++itRunner){
      ((CResource*) (*itRunner))->getObjectHandler().getResourceWatches(pa_roResponse, pa_cQualifier);
    }

  }
  else{
    //we are within a resource
    getResourceWatches(pa_roResponse, pa_cQualifier);
  }

  return e_RDY;
}

EMGMResponse C61499Class1ObjectHandler::forceValue(SManagementCMD &pa_rstCommand){
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;
  CFunctionBlock *poFB = getFB(CConnection::extractFBNameId(pa_rstCommand.m_nFirstParam));
  if(0 != poFB){
    eRetVal = (poFB->forceData(CConnection::extractPortNameId(pa_rstCommand.m_nFirstParam), pa_rstCommand.m_oAdditionalParams.getValue())) ? e_RDY : e_INVALID_DST;
  }
  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::clearForce(TConnectionID pa_nDestId){
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;
  CFunctionBlock *poFB = getFB(CConnection::extractFBNameId(pa_nDestId));
  if(0 != poFB){
    CIEC_ANY *poDataVal = poFB->getVar(CConnection::extractPortNameId(pa_nDestId));
    if(0 != poDataVal){
      poDataVal->setForced(false);
      eRetVal = e_RDY;
    }
    else{
      eRetVal = e_INVALID_DST;
    }
  }
  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::triggerEvent(TConnectionID pa_nEventPortId){
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;

  CFunctionBlock *poFB = getFB(CConnection::extractFBNameId(pa_nEventPortId));
  if(0 != poFB){
    CStringDictionary::TStringId unPortId = CConnection::extractPortNameId(pa_nEventPortId);
    CEventChainExecutionThread *poResourceExecution = poFB->getResource().getResourceEventExecution();

    TEventID unEventId = poFB->getEIID(unPortId);
    if(cg_nInvalidEventID != unEventId){
      if(poResourceExecution != 0){
        //only a single event can be triggered simultaneously (until it is executed by ecet!)
        //otherwise the triggerEvent structure needs to be moved to another place!
        m_stTriggerEvent.m_poFB = poFB;
        m_stTriggerEvent.m_nEIID = unEventId;
        poResourceExecution->startEventChain(&m_stTriggerEvent);
        eRetVal = e_RDY;
      }
      else{
        eRetVal = e_INVALID_STATE;
      }
    }
    else{
      unEventId = poFB->getEOID(unPortId);
      if(cg_nInvalidEventID != unEventId){
        if(poResourceExecution != 0){
          poFB->m_poInvokingExecEnv = poResourceExecution;
          poFB->sendOutputEvent(unEventId);
          //TODO a poResourceExecution->resumeSelfSuspend(); may be necessary here
          eRetVal = e_RDY;
        }
        else{
          eRetVal = e_INVALID_STATE;
        }
      }
    }

  }
  return eRetVal;
}

EMGMResponse C61499Class1ObjectHandler::resetEventCount(TConnectionID pa_nEventPortId){
  EMGMResponse eRetVal = e_NO_SUCH_OBJECT;

  CFunctionBlock *poFB = getFB(CConnection::extractFBNameId(pa_nEventPortId));
  if(0 != poFB){
    CStringDictionary::TStringId unPortId = CConnection::extractPortNameId(pa_nEventPortId);
    TEventID unEventId = poFB->getEIID(unPortId);
    SMonitorEvent *pstEventMonitorData = 0;

    if(cg_nInvalidEventID != unEventId){
      pstEventMonitorData = &poFB->getEIMontiorData(unEventId);
    }
    else{
      unEventId = poFB->getEOID(unPortId);
      if(cg_nInvalidEventID != unEventId){
        pstEventMonitorData = &poFB->getEOMontiorData(unEventId);
      }
    }
    if(0 != pstEventMonitorData){
      poFB->getResource().m_oResDataConSync.lock();
      pstEventMonitorData->eventCount[pstEventMonitorData->bufPos] = 0;
      poFB->getResource().m_oResDataConSync.unlock();
      eRetVal = e_RDY;
    }
  }
  return eRetVal;
}

C61499Class1ObjectHandler::SFBMonitoringEntry &C61499Class1ObjectHandler::findOrCreateFBMonitoringEntry(CFunctionBlock *pa_poFB){
  for(TFBMonitoringList::Iterator itRunner = m_lstFBMonitoringList.begin(); itRunner != m_lstFBMonitoringList.end(); ++itRunner){
    if(itRunner->m_poFB->getInstanceNameId() == pa_poFB->getInstanceNameId()){
      return *itRunner;
    }
  }

  m_lstFBMonitoringList.push_back(SFBMonitoringEntry());
  TFBMonitoringList::Iterator itLastEntry(m_lstFBMonitoringList.back());
  itLastEntry->m_poFB = pa_poFB;
  return *itLastEntry;
}

void C61499Class1ObjectHandler::addDataWatch(SFBMonitoringEntry &pa_roFBMonitoringEntry, CStringDictionary::TStringId pa_unPortId, CIEC_ANY *pa_poDataVal){
  for(TDataWatchList::Iterator itRunner = pa_roFBMonitoringEntry.m_lstWatchedDataPoints.begin(); itRunner != pa_roFBMonitoringEntry.m_lstWatchedDataPoints.end(); ++itRunner){
    if(itRunner->m_unPortId == pa_unPortId){
      //the data point is already in the watch list
      return;
    }
  }
  pa_roFBMonitoringEntry.m_lstWatchedDataPoints.push_back(SDataWatchEntry(pa_unPortId, pa_poDataVal));
}

bool C61499Class1ObjectHandler::removeDataWatch(SFBMonitoringEntry &pa_roFBMonitoringEntry, CStringDictionary::TStringId pa_unPortId){
  bool bRetVal = false;

  TDataWatchList::Iterator itRunner = pa_roFBMonitoringEntry.m_lstWatchedDataPoints.begin();
  TDataWatchList::Iterator itRefNode = pa_roFBMonitoringEntry.m_lstWatchedDataPoints.end();

  while(itRunner != pa_roFBMonitoringEntry.m_lstWatchedDataPoints.end()){
    if(itRunner->m_unPortId == pa_unPortId){
      if(itRefNode == pa_roFBMonitoringEntry.m_lstWatchedDataPoints.end()){
        //we have the first entry in the list
        pa_roFBMonitoringEntry.m_lstWatchedDataPoints.pop_front();
      }
      else{
        pa_roFBMonitoringEntry.m_lstWatchedDataPoints.eraseAfter(itRefNode);
      }
      bRetVal = true;
      break;
    }

    itRefNode = itRunner;
    ++itRunner;
  }

  return bRetVal;
}

void C61499Class1ObjectHandler::addEventWatch(SFBMonitoringEntry &pa_roFBMonitoringEntry, CStringDictionary::TStringId pa_unPortId, SMonitorEvent &pa_rstEventData){
  for(TEventWatchList::Iterator itRunner = pa_roFBMonitoringEntry.m_lstWatchedEventPoints.begin(); itRunner != pa_roFBMonitoringEntry.m_lstWatchedEventPoints.end(); ++itRunner){
    if(itRunner->m_unPortId == pa_unPortId){
      //the event point is already in the watch list
      return;
    }
  }
  pa_roFBMonitoringEntry.m_lstWatchedEventPoints.push_back(SEventWatchEntry(pa_unPortId, pa_rstEventData));
}

bool C61499Class1ObjectHandler::removeEventWatch(SFBMonitoringEntry &pa_roFBMonitoringEntry, CStringDictionary::TStringId pa_unPortId){
  bool bRetVal = false;

  TEventWatchList::Iterator itRunner = pa_roFBMonitoringEntry.m_lstWatchedEventPoints.begin();
  TEventWatchList::Iterator itRefNode = pa_roFBMonitoringEntry.m_lstWatchedEventPoints.end();

  while(itRunner != pa_roFBMonitoringEntry.m_lstWatchedEventPoints.end()){
    if(itRunner->m_unPortId == pa_unPortId){
      if(itRefNode == pa_roFBMonitoringEntry.m_lstWatchedEventPoints.end()){
        //we have the first entry in the list
        pa_roFBMonitoringEntry.m_lstWatchedEventPoints.pop_front();
      }
      else{
        pa_roFBMonitoringEntry.m_lstWatchedEventPoints.eraseAfter(itRefNode);
      }
      bRetVal = true;
      break;
    }

    itRefNode = itRunner;
    ++itRunner;
  }

  return bRetVal;
}

void C61499Class1ObjectHandler::readResourceWatches(CIEC_ANY_STRING &pa_roResponse){
  if(!m_lstFBMonitoringList.isEmpty()){
    pa_roResponse.append("<Resource name=\"");
    pa_roResponse.append(m_roHandlerOwner.getInstanceName());
    pa_roResponse.append("\">");

    m_roHandlerOwner.m_oResDataConSync.lock();

    for(TFBMonitoringList::Iterator itRunner = m_lstFBMonitoringList.begin(); itRunner != m_lstFBMonitoringList.end(); ++itRunner){
      pa_roResponse.append("<FB name=\"");
      pa_roResponse.append(itRunner->m_poFB->getInstanceName());
      pa_roResponse.append("\">");

      //add the data watches
      for(TDataWatchList::Iterator itDataRunner = itRunner->m_lstWatchedDataPoints.begin(); itDataRunner != itRunner->m_lstWatchedDataPoints.end(); ++itDataRunner){
        appendDataWatch(pa_roResponse, *itDataRunner);
      }

      //add the event watches
      for(TEventWatchList::Iterator itEventRunner = itRunner->m_lstWatchedEventPoints.begin();
          itEventRunner != itRunner->m_lstWatchedEventPoints.end();
          ++itEventRunner){
        appendEventWatch(pa_roResponse, *itEventRunner);
      }

      pa_roResponse.append("</FB>");
    }

    m_roHandlerOwner.m_oResDataConSync.unlock();
    pa_roResponse.append("</Resource>");
  }
}

void C61499Class1ObjectHandler::getResourceWatches(CIEC_ANY_STRING &pa_roResponse, char pa_cQualifier){
  if(!m_lstFBMonitoringList.isEmpty()){
    pa_roResponse.append("<Resource name=\"");
    pa_roResponse.append(m_roHandlerOwner.getInstanceName());
    pa_roResponse.append("\">");

    for(TFBMonitoringList::Iterator itRunner = m_lstFBMonitoringList.begin(); itRunner != m_lstFBMonitoringList.end(); ++itRunner){
      pa_roResponse.append("<FB name=\"");
      pa_roResponse.append(itRunner->m_poFB->getInstanceName());
      pa_roResponse.append("\">");

      //FIXME implement the watches

      pa_roResponse.append("</FB>");
    }

    pa_roResponse.append("</Resource>");
  }
}

void C61499Class1ObjectHandler::appendDataWatch(CIEC_ANY_STRING &pa_roResponse, SDataWatchEntry &pa_roDataWatchEntry){
  appendPortTag(pa_roResponse, pa_roDataWatchEntry.m_unPortId);
  pa_roResponse.append("<Data value=\"");

  char acDataValue[80]; //TODO try to directly use the response string instead
  int nConsumedBytes;
  switch (pa_roDataWatchEntry.m_poDataValue->getDataTypeID()){
    case CIEC_ANY::e_WSTRING:
    case CIEC_ANY::e_STRING:
      nConsumedBytes = static_cast<CIEC_WSTRING*>(pa_roDataWatchEntry.m_poDataValue)->toUTF8(acDataValue, sizeof(acDataValue), false);
      break;
    default:
      nConsumedBytes = pa_roDataWatchEntry.m_poDataValue->toString(acDataValue, sizeof(acDataValue));
      break;
  }
  if(-1 != nConsumedBytes){
    acDataValue[nConsumedBytes] = '\0';
  }

  pa_roResponse.append(acDataValue);
  pa_roResponse.append("\" forced=\"");
  pa_roResponse.append(((pa_roDataWatchEntry.m_poDataValue->isForced()) ? "true" : "false"));
  pa_roResponse.append("\">");
  pa_roResponse.append("</Data>");

  pa_roResponse.append("</Port>");
}

void C61499Class1ObjectHandler::appendPortTag(CIEC_ANY_STRING &pa_roResponse, CStringDictionary::TStringId pa_unPortId){
  pa_roResponse.append("<Port name=\"");
  pa_roResponse.append(CStringDictionary::getInstance().get(pa_unPortId));
  pa_roResponse.append("\">");
}

void C61499Class1ObjectHandler::appendEventWatch(CIEC_ANY_STRING &pa_roResponse, SEventWatchEntry &pa_roEventWatchEntry){
  appendPortTag(pa_roResponse, pa_roEventWatchEntry.m_unPortId);

  CIEC_UDINT udint;
  CIEC_ULINT ulint;

  char acEventCount[10];  // the bigest number in an uint is 4294967296, TODO directly use pa_roResponse
  char acTimeStamp[21];   // the bigest number in an ulint is 18446744073709551616, TODO directly use pa_roResponse

  for(TForteUInt16 i = 0; i <= pa_roEventWatchEntry.m_roEventData.bufPos; i++){
    udint = pa_roEventWatchEntry.m_roEventData.eventCount[i];
    ulint = pa_roEventWatchEntry.m_roEventData.timestamp[i];

    pa_roResponse.append("<Data value=\"");
    udint.toString(acEventCount, sizeof(acEventCount));
    pa_roResponse.append(acEventCount);
    pa_roResponse.append("\" time=\"");
    ulint.toString(acTimeStamp, sizeof(acTimeStamp));
    pa_roResponse.append(acTimeStamp);
    pa_roResponse.append("\">");
    pa_roResponse.append("</Data>");
  }

  pa_roEventWatchEntry.m_roEventData.bufPos = 0;

  pa_roResponse.append("</Port>");
}

#endif  // #ifdef FORTE_SUPPORT_MONITORING

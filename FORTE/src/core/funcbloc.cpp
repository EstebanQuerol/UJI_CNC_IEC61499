/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include <string.h>
#include <stdlib.h>
#include "timerha.h"
#include "funcbloc.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "funcbloc_gen.cpp"
#endif
#include "resource.h"
#include "adapter.h"
#include "datatypes/forte_array.h"

CFunctionBlock::CFunctionBlock(CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec, const CStringDictionary::TStringId pa_nInstanceNameId, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData) :
   m_apoEOConns(0), m_apoDIConns(0), m_apoDOConns(0),
    m_apoAdapters(0), m_poResource(pa_poSrcRes), m_nFBInstanceName(pa_nInstanceNameId), m_aoDIs(0), m_aoDOs(0), m_enFBState(e_IDLE), m_bDeletable(true){

  #ifdef FORTE_SUPPORT_MONITORING
  m_nEIMonitorCount = 0;
  m_nEOMonitorCount = 0;
#endif

  setupFBInterface(pa_pstInterfaceSpec, pa_acFBConnData, pa_acFBVarsData, false);
}

CFunctionBlock::~CFunctionBlock(){
  freeAllData();
}

void CFunctionBlock::freeAllData(){
  if(0 != m_pstInterfaceSpec){
    if(m_pstInterfaceSpec->m_nNumDIs){
      for(int i = 0; i < m_pstInterfaceSpec->m_nNumDIs; ++i){
        getDI(i)->~CIEC_ANY();
      }
    }

    if(m_pstInterfaceSpec->m_nNumDOs){
      for(int i = 0; i < m_pstInterfaceSpec->m_nNumDOs; ++i){
        getDO(i)->~CIEC_ANY();
      }
    }

    for(unsigned int i = 0; i < m_pstInterfaceSpec->m_nNumAdapters; ++i){
      delete m_apoAdapters[i];
    }
  }

  if(m_bManagesFBData){
    TForteByte *acFBConnData = 0;
    TForteByte *acFBVarsData = 0;

    if(0 != m_apoEOConns){
      //if not 0 m_apoEOConns points to the start of the connection data array
      acFBConnData = reinterpret_cast<TForteByte *>(m_apoEOConns);
    }
    else{
      if(0 != m_apoDIConns){
        //if not 0 m_apoDIConns points to the start of the connection data array
        acFBConnData = reinterpret_cast<TForteByte *>(m_apoDIConns);
      }
      else{
        if(0 != m_apoDOConns){
          //if not 0 m_apoDOConns points to the start of the connection data array
          acFBConnData = reinterpret_cast<TForteByte *>(m_apoDOConns);
        }
      }
    }

    if(0 != m_aoDIs){
      //if not 0 m_aoDIs points to the start of the vars data array
      acFBVarsData = reinterpret_cast<TForteByte *>(m_aoDIs);
    }
    else{
      if(0 != m_aoDOs){
        //if not 0 m_aoDOs points to the start of the vars data array
        acFBVarsData = reinterpret_cast<TForteByte *>(m_aoDOs);
      }
      else{
        if(0 != m_apoAdapters){
          //if not 0 m_apoAdapters points to the start of the vars data array
          acFBVarsData = reinterpret_cast<TForteByte *>(m_apoAdapters);
        }
      }
    }

    delete[] acFBConnData;
    delete[] acFBVarsData;
    delete m_pstInterfaceSpec;
  }
#ifdef  FORTE_SUPPORT_MONITORING
  delete[] m_nEOMonitorCount;
  delete[] m_nEIMonitorCount;
#endif //FORTE_SUPPORT_MONITORING
}

void CFunctionBlock::setupAdapters(const SFBInterfaceSpec *pa_pstInterfaceSpec, TForteByte *pa_acFBData){
  if((0 != pa_pstInterfaceSpec) && (0 != pa_acFBData)){
    if(pa_pstInterfaceSpec->m_nNumAdapters){
      m_apoAdapters = reinterpret_cast<TAdapterPtr *>(pa_acFBData);
      for(unsigned int i = 0; i < pa_pstInterfaceSpec->m_nNumAdapters; ++i){
        //set pointer to right place in pa_acFBData
        m_apoAdapters[i] = ((CAdapter*) CTypeLib::createAdapter(pa_pstInterfaceSpec->m_pstAdapterInstanceDefinition[i].m_nAdapterNameID, pa_pstInterfaceSpec->m_pstAdapterInstanceDefinition[i].m_nAdapterTypeNameID, getResourcePtr(), pa_pstInterfaceSpec->m_pstAdapterInstanceDefinition[i].m_bIsPlug));
        if(0 != m_apoAdapters[i]){
          ((CAdapter*) m_apoAdapters[i])->setParentFB(this, static_cast<TForteUInt8>(i));
        }
      }
    }
  }
}

bool CFunctionBlock::connectEO(CStringDictionary::TStringId pa_uEONameId, CEventConnection *pa_poEventCon){
  for(int i = 0; i < m_pstInterfaceSpec->m_nNumEOs; ++i){
    if(pa_uEONameId == m_pstInterfaceSpec->m_aunEONames[i]){
      m_apoEOConns[i] = pa_poEventCon;
      return true;
    }
  }
  return false;
}

bool CFunctionBlock::connectDI(CStringDictionary::TStringId pa_unDINameId, CDataConnection *pa_poDataCon){
  bool bRetVal = false;
  unsigned int unDID = getDIID(pa_unDINameId);

  if(cg_unInvalidPortId != unDID){ //catch invalid ID

    if(0 == pa_poDataCon){
      m_apoDIConns[unDID] = 0;
      bRetVal = true;
    }
    else{
      //only perform connection checks if it is not a disconnection request.
      if(0 != m_apoDIConns[unDID]){
        DEVLOG_ERROR("%s cannot connect input data %s to more sources, using the latest connection attempt\n", CStringDictionary::getInstance().get(getFBTypeId()), CStringDictionary::getInstance().get(m_pstInterfaceSpec->m_aunDINames[unDID]));
      }else{
        m_apoDIConns[unDID] = pa_poDataCon;
        if(getDI(unDID)->getDataTypeID() == CIEC_ANY::e_ANY){
          if(pa_poDataCon != 0 && 0 != pa_poDataCon->getValue()){
            pa_poDataCon->getValue()->clone(reinterpret_cast<TForteByte *>(getDI(unDID)));
          }
        }
        bRetVal = true;
      }
    }
  }
  return bRetVal;
}

bool CFunctionBlock::connectDO(CStringDictionary::TStringId pa_unDONameId, CDataConnection *pa_poDataCon){
  bool bRetVal = false;
  unsigned int unDID = getDOID(pa_unDONameId);

  if(cg_unInvalidPortId != unDID){ //catch invalid ID
    if(0 == pa_poDataCon){
      //disconnection request
      m_apoDOConns[unDID] = 0;
      bRetVal = true;
    }
    else{
      //only perform connection checks if it is not a disconnection request.
      if(0 != m_apoDOConns[unDID]){
        //This should typically not happen as the object handler will use the existing connection for fan-outs
        DEVLOG_ERROR("%s cannot connect output data %s to more connections, using the latest connection attempt\n", CStringDictionary::getInstance().get(getFBTypeId()), CStringDictionary::getInstance().get(m_pstInterfaceSpec->m_aunDONames[unDID]));
      }
      else{
        m_apoDOConns[unDID] = pa_poDataCon;
        if(getDO(unDID)->getDataTypeID() == CIEC_ANY::e_ANY){
          if(pa_poDataCon != 0 && 0 != pa_poDataCon->getValue()){
            pa_poDataCon->getValue()->clone(reinterpret_cast<TForteByte *>(getDO(unDID)));
          }
        }
        bRetVal = true;
      }
    }
  }
  return bRetVal;
}

CIEC_ANY *CFunctionBlock::getDataOutput(CStringDictionary::TStringId pa_unDONameId){
  CIEC_ANY *poRetVal = 0;
  unsigned int unDID = getDOID(pa_unDONameId);

  if(cg_unInvalidPortId != unDID){
    poRetVal = getDO(unDID);
  }
  return poRetVal;
}

CIEC_ANY *CFunctionBlock::getDataInput(CStringDictionary::TStringId pa_unDINameId){
  CIEC_ANY *poRetVal = 0;
  unsigned int unDID = getDIID(pa_unDINameId);

  if(cg_unInvalidPortId != unDID){
    poRetVal = getDI(unDID);
  }
  return poRetVal;
}

CIEC_ANY *CFunctionBlock::getVar(const char *pa_acVarName){
  return getVar(CStringDictionary::getInstance().getId(pa_acVarName));
}

CIEC_ANY* CFunctionBlock::getVar(CStringDictionary::TStringId pa_unNameId){
  CIEC_ANY *poRetVal = 0;
  unsigned int unDID = getDIID(pa_unNameId);
  if(cg_unInvalidPortId != unDID){
    poRetVal = getDI(unDID);
  }
  else{
    unDID = getDOID(pa_unNameId);
    if(cg_unInvalidPortId != unDID){
      poRetVal = getDO(unDID);
    }
  }
  return poRetVal;
}

CAdapter *CFunctionBlock::getAdapter(CStringDictionary::TStringId pa_uAdapterNameId){
  for(int i = 0; i < m_pstInterfaceSpec->m_nNumAdapters; ++i){
    if(m_apoAdapters[i]->getInstanceNameId() == pa_uAdapterNameId){
      return m_apoAdapters[i];
    }
  }
  return 0;
}

void CFunctionBlock::sendOutputEvent(int pa_nEO){
  FORTE_TRACE("OutputEvent: Function Block sending event: %d (maxid: %d)\n", pa_nEO, m_pstInterfaceSpec->m_nNumEOs - 1);
  if(pa_nEO < m_pstInterfaceSpec->m_nNumEOs){
#ifdef FORTE_SUPPORT_MONITORING
    // breakpoint set, ignore all other events
    if(m_nEOMonitorCount[pa_nEO].breakpoint_set[m_nEOMonitorCount[pa_nEO].bufPos] > 0){
      return;
    }
#endif //FORTE_SUPPORT_MONITORING
    if(0 != m_pstInterfaceSpec->m_anEOWithIndexes){
      if(-1 != m_pstInterfaceSpec->m_anEOWithIndexes[pa_nEO]){
        const TDataIOID *poEOWithStart = &(m_pstInterfaceSpec->m_anEOWith[m_pstInterfaceSpec->m_anEOWithIndexes[pa_nEO]]);
        //TODO think on this lock
        m_poResource->m_oResDataConSync.lock();
        for(int i = 0; poEOWithStart[i] != 255; ++i){
          //printf("Output With. i: %d, DO: %d\n", i, poEOWithStart[i]);
          if(0 != m_apoDOConns[poEOWithStart[i]]){
            CIEC_ANY *poDO = getDO(poEOWithStart[i]);
#ifdef FORTE_SUPPORT_MONITORING
            if(poDO->isForced() != true){
#endif //FORTE_SUPPORT_MONITORING
              m_apoDOConns[poEOWithStart[i]]->writeData(poDO);
#ifdef FORTE_SUPPORT_MONITORING
            }
            else{
              //when forcing we write back the value from the connection to keep the forced value on the output
              m_apoDOConns[poEOWithStart[i]]->readData(poDO);
            }
#endif //FORTE_SUPPORT_MONITORING
          }
        }
        // TODO think on this lock
        m_poResource->m_oResDataConSync.unlock();
      }
    }
    if(0 != m_apoEOConns[pa_nEO]){
      //      printf("triggering events\n");
      m_apoEOConns[pa_nEO]->triggerEvent(*m_poInvokingExecEnv);
    }
#ifdef FORTE_SUPPORT_MONITORING
    // stop execution on Breakpoint
    if(m_nEOMonitorCount[pa_nEO].breakpoint_enable[m_nEOMonitorCount[pa_nEO].bufPos] == true){
      if(m_nEOMonitorCount[pa_nEO].breakpoint_set[m_nEOMonitorCount[pa_nEO].bufPos] < 0){ // if < 0 -> continue called
        m_nEOMonitorCount[pa_nEO].breakpoint_set[m_nEOMonitorCount[pa_nEO].bufPos] = 0;
      }
      else{
        m_nEOMonitorCount[pa_nEO].breakpoint_set[m_nEOMonitorCount[pa_nEO].bufPos] = 1;
        return;
      }
      // Get Resource
      //CResource &res = this->getResource();
      //res.stopManagedObject();		// we cant restart it,
    }
    // Count Event for monitoring
    if(m_nEOMonitorCount[pa_nEO].running){
      m_nEOMonitorCount[pa_nEO].eventCount[m_nEOMonitorCount[pa_nEO].bufPos]++;

      m_nEOMonitorCount[pa_nEO].timestamp[m_nEOMonitorCount[pa_nEO].bufPos] = CTimerHandler::sm_poFORTETimer->getForteTime().m_nUpperValue;
      m_nEOMonitorCount[pa_nEO].timestamp[m_nEOMonitorCount[pa_nEO].bufPos] <<= 32;
      m_nEOMonitorCount[pa_nEO].timestamp[m_nEOMonitorCount[pa_nEO].bufPos] |= CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue;

      m_nEOMonitorCount[pa_nEO].bufPos = (m_nEOMonitorCount[pa_nEO].bufPos + 1) % MONITOR_BUFFER_LENGTH;
    }
    //this->setUpdated(true);
    bool *p = const_cast<bool *>(&m_updated);
    *p = true;
#endif //FORTE_SUPPORT_MONITORING
  }
  //  printf("finished sendoutputevent\n");
}

void CFunctionBlock::sendAdapterEvent(int pa_nAdapterID, int pa_nEID) const{
  if(0 != m_apoAdapters[pa_nAdapterID]){
    ((CAdapter*) m_apoAdapters[pa_nAdapterID])->receiveInputEvent(pa_nEID, *m_poInvokingExecEnv);
  }
}

bool CFunctionBlock::configureFB(const char *){
  return true;
}

void CFunctionBlock::receiveInputEvent(int pa_nEIID, CEventChainExecutionThread &pa_poExecEnv){
  FORTE_TRACE("InputEvent: Function Block (%s) got event: %d (maxid: %d)\n", CStringDictionary::getInstance().get(getInstanceNameId()), pa_nEIID, m_pstInterfaceSpec->m_nNumEIs - 1);

  if(e_RUNNING == getState()){
    if(pa_nEIID < m_pstInterfaceSpec->m_nNumEIs){
#ifdef FORTE_SUPPORT_MONITORING
      m_updated = true;
      // breakpoint set, ignore all other events
      if(m_nEIMonitorCount[pa_nEIID].breakpoint_set[m_nEIMonitorCount[pa_nEIID].bufPos] > 0){
        return;
      }
#endif //FORTE_SUPPORT_MONITORING
      if(0 != m_pstInterfaceSpec->m_anEIWithIndexes){

        //        printf(   "Event name: %s\n", m_pstInterfaceSpec->m_acEINames[pa_nEIID]);
        if(-1 != m_pstInterfaceSpec->m_anEIWithIndexes[pa_nEIID]){
          const TDataIOID *poEIWithStart = &(m_pstInterfaceSpec->m_anEIWith[m_pstInterfaceSpec->m_anEIWithIndexes[pa_nEIID]]);

          // TODO think on this lock
          m_poResource->m_oResDataConSync.lock();
          for(int i = 0; poEIWithStart[i] != 255; ++i){
            if(0 != m_apoDIConns[poEIWithStart[i]]){
              CIEC_ANY *poDI = getDI(poEIWithStart[i]);
#ifdef FORTE_SUPPORT_MONITORING
              if(true != poDI->isForced()){
#endif //FORTE_SUPPORT_MONITORING
                m_apoDIConns[poEIWithStart[i]]->readData(poDI);
#ifdef FORTE_SUPPORT_MONITORING
              }
#endif //FORTE_SUPPORT_MONITORING
            }
          }
          // TODO think on this lock
          m_poResource->m_oResDataConSync.unlock();
        }
      }
#ifdef FORTE_SUPPORT_MONITORING
      // stop execution on Breakpoint
      if(m_nEIMonitorCount[pa_nEIID].breakpoint_enable[m_nEIMonitorCount[pa_nEIID].bufPos] == true){
        m_poResource->m_oResDataConSync.lock();
        if(m_nEIMonitorCount[pa_nEIID].breakpoint_set[m_nEIMonitorCount[pa_nEIID].bufPos] < 0){ // if < 0 -> continue called
          m_nEIMonitorCount[pa_nEIID].breakpoint_set[m_nEIMonitorCount[pa_nEIID].bufPos] = 0;
        }
        else{
          m_nEIMonitorCount[pa_nEIID].breakpoint_set[m_nEIMonitorCount[pa_nEIID].bufPos] = 1;
          m_poResource->m_oResDataConSync.unlock();
          return;
        }
        m_poResource->m_oResDataConSync.unlock();
        // Get Resource
        //CResource &res = this->getResource();
        //res.stopManagedObject();		// we cant restart it,
      }
      // Count Event for monitoring
      if(m_nEIMonitorCount[pa_nEIID].running == true){
        m_nEIMonitorCount[pa_nEIID].eventCount[m_nEIMonitorCount[pa_nEIID].bufPos]++;

        m_nEIMonitorCount[pa_nEIID].timestamp[m_nEIMonitorCount[pa_nEIID].bufPos] = CTimerHandler::sm_poFORTETimer->getForteTime().m_nUpperValue;
        m_nEIMonitorCount[pa_nEIID].timestamp[m_nEIMonitorCount[pa_nEIID].bufPos] <<= 32;
        m_nEIMonitorCount[pa_nEIID].timestamp[m_nEIMonitorCount[pa_nEIID].bufPos] |= CTimerHandler::sm_poFORTETimer->getForteTime().m_nLowerValue;

        m_nEIMonitorCount[pa_nEIID].bufPos = (m_nEIMonitorCount[pa_nEIID].bufPos + 1) % MONITOR_BUFFER_LENGTH;
      }
#endif //FORTE_SUPPORT_MONITORING
    }
    m_poInvokingExecEnv = &pa_poExecEnv;
    executeEvent(pa_nEIID);
  }
}

EMGMResponse CFunctionBlock::changeFBExecutionState(EMGMCommandType pa_unCommand){
  EMGMResponse nRetVal = e_INVALID_STATE;
  switch (pa_unCommand){
    case cg_nMGM_CMD_Start:
      if(e_KILLED != m_enFBState){
        m_enFBState = e_RUNNING;
        nRetVal = e_RDY;
      }
      break;
    case cg_nMGM_CMD_Stop:
      if(e_RUNNING == m_enFBState){
        m_enFBState = e_STOPPED;
        nRetVal = e_RDY;
      }
      break;
    case cg_nMGM_CMD_Kill:
      if(e_RUNNING == m_enFBState){
        m_enFBState = e_KILLED;
        nRetVal = e_RDY;
      }
      break;
    case cg_nMGM_CMD_Reset:
      if(e_RUNNING != m_enFBState){
        m_enFBState = e_IDLE;
        nRetVal = e_RDY;
        setInitialValues();
      }
      break;
    default:
      nRetVal = e_INVALID_OPERATION;
      break;
  }

  if(e_RDY == nRetVal){
    if(0 != m_pstInterfaceSpec){
      for(int i = 0; i < m_pstInterfaceSpec->m_nNumAdapters; ++i){
        if(0 != m_apoAdapters[i]){
          m_apoAdapters[i]->changeFBExecutionState(pa_unCommand);
        }
      }
    }
  }
  return nRetVal;
}

CIEC_ANY *CFunctionBlock::createDataPoint(const CStringDictionary::TStringId **pa_panDataTypeIds, TForteByte *pa_acDataBuf){
  CIEC_ANY *poRetVal = CTypeLib::createDataTypeInstance(**pa_panDataTypeIds, pa_acDataBuf);
  ++(*pa_panDataTypeIds);
#ifdef FORTE_SUPPORT_ARRAYS
  if(g_nStringIdARRAY == (*pa_panDataTypeIds)[-1]){
    if(0 != poRetVal){
      //For an array we have to do more
      ((CIEC_ARRAY *) poRetVal)->setup(static_cast<TForteUInt16>(**pa_panDataTypeIds), (*pa_panDataTypeIds)[1]);
    }
    (*pa_panDataTypeIds) += 2;
  }
#endif
  return poRetVal;
}

void CFunctionBlock::setupFBInterface(const SFBInterfaceSpec *pa_pstInterfaceSpec, TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData, bool pa_bManagesFBData){
  m_pstInterfaceSpec = const_cast<SFBInterfaceSpec *>(pa_pstInterfaceSpec);
  m_bManagesFBData = pa_bManagesFBData;

  if(0 != pa_pstInterfaceSpec){
    if((0 != pa_acFBConnData) && (0 != pa_acFBVarsData)){
      int i;
      if(m_pstInterfaceSpec->m_nNumEOs){
        m_apoEOConns = reinterpret_cast<TEventConnectionPtr *>(pa_acFBConnData);
        pa_acFBConnData += sizeof(TEventConnectionPtr) * m_pstInterfaceSpec->m_nNumEOs;
        for(i = 0; i < m_pstInterfaceSpec->m_nNumEOs; ++i){
          m_apoEOConns[i] = 0;
        }
      }
      else{
        m_apoEOConns = 0;
      }

      const CStringDictionary::TStringId *pnDataIds;
      if(m_pstInterfaceSpec->m_nNumDIs){
        m_apoDIConns = reinterpret_cast<TDataConnectionPtr *>(pa_acFBConnData);
        pa_acFBConnData += sizeof(TDataConnectionPtr) * m_pstInterfaceSpec->m_nNumDIs;

        //let m_aoDIs point to the first data input
        m_aoDIs = reinterpret_cast<CIEC_ANY *>(pa_acFBVarsData);

        pnDataIds = pa_pstInterfaceSpec->m_aunDIDataTypeNames;
        for(i = 0; i < m_pstInterfaceSpec->m_nNumDIs; ++i){
          m_apoDIConns[i] = 0;
          createDataPoint(&pnDataIds, pa_acFBVarsData);
          pa_acFBVarsData += sizeof(CIEC_ANY);
        }
      }
      else{
        m_apoDIConns = 0;
        m_aoDIs = 0;
      }

      if(m_pstInterfaceSpec->m_nNumDOs){
        m_apoDOConns = reinterpret_cast<TDataConnectionPtr *>(pa_acFBConnData);
        pa_acFBConnData += sizeof(TDataConnectionPtr) * m_pstInterfaceSpec->m_nNumDOs;

        //let m_aoDIs point to the first data input
        m_aoDOs = reinterpret_cast<CIEC_ANY *>(pa_acFBVarsData);

        pnDataIds = pa_pstInterfaceSpec->m_aunDODataTypeNames;
        for(i = 0; i < m_pstInterfaceSpec->m_nNumDOs; ++i){
          m_apoDOConns[i] = 0;
          createDataPoint(&pnDataIds, pa_acFBVarsData);
          pa_acFBVarsData += sizeof(CIEC_ANY);
        }
      }
      else{
        m_apoDOConns = 0;
        m_aoDOs = 0;
      }
      if(m_pstInterfaceSpec->m_nNumAdapters){
        setupAdapters(pa_pstInterfaceSpec, pa_acFBVarsData);
      }
    }
#ifdef FORTE_SUPPORT_MONITORING
    setupEventMonitoringData();
#endif
  }

}

unsigned int CFunctionBlock::getPortId(CStringDictionary::TStringId pa_unPortNameId, unsigned int pa_unMaxPortNames, const CStringDictionary::TStringId* pa_aunPortNames){
  for(unsigned int i = 0; i < pa_unMaxPortNames; ++i){
    if(pa_unPortNameId == pa_aunPortNames[i]){
      return i;
    }
  }
  return cg_unInvalidPortId;
}

void CFunctionBlock::generateGenericInterfacePointNameArray(const char * const pa_acPrefix, CStringDictionary::TStringId* pa_anNamesArayStart, unsigned int pa_unNumGenericDataPoints){
  TIdentifier acBuffer;

  size_t unLen = strlen(pa_acPrefix);

  if(cg_nIdentifierLength > unLen){
    memcpy(acBuffer, pa_acPrefix, unLen);
    char *acRunner = &acBuffer[unLen];
    char *acTenth = 0;
    char *acHundret = 0;
    acRunner[1] = '\0';

    for(unsigned int i = 1, j = 0, jj = 0; i <= pa_unNumGenericDataPoints; i++){
      if(0 == (i % 10)){
        if(j == 0){
          acTenth = acRunner;
          acRunner++;
          acRunner[1] = '\0';
        }
        j++;

        if(0 == (j % 10)){
          if(jj == 0){
            acHundret = acTenth;
            acTenth = acRunner;
            acRunner++;
            acRunner[1] = '\0';
          }
          jj++;
          *acHundret = static_cast<char>(0x30 + (jj % 10));
        }
        *acTenth = static_cast<char>(0x30 + (j % 10));
      }
      *acRunner = static_cast<char>(0x30 + (i % 10));
      pa_anNamesArayStart[i - 1] = CStringDictionary::getInstance().insert(acBuffer);
    }
  }
}

void CFunctionBlock::generateGenericDataPointArrays(const char * const pa_acPrefix, CStringDictionary::TStringId* pa_anDataTypeNamesArrayStart, CStringDictionary::TStringId* pa_anNamesArrayStart, unsigned int pa_unNumGenericDataPoints){
  generateGenericInterfacePointNameArray(pa_acPrefix, pa_anNamesArrayStart, pa_unNumGenericDataPoints);

  for(unsigned int i = 0; i < pa_unNumGenericDataPoints; i++){
    pa_anDataTypeNamesArrayStart[i] = g_nStringIdANY;
  }
}

#ifdef FORTE_SUPPORT_MONITORING
void CFunctionBlock::setupEventMonitoringData(){

  if(0 != m_pstInterfaceSpec->m_nNumEIs){
    m_nEIMonitorCount = new SMonitorEvent[m_pstInterfaceSpec->m_nNumEIs];

    for(TForteUInt32 i = 0; i < m_pstInterfaceSpec->m_nNumEIs; i++){
      for(unsigned int j = 0; j < MONITOR_BUFFER_LENGTH; j++){
        m_nEIMonitorCount[i].eventCount[j] = 0;
        m_nEIMonitorCount[i].timestamp[j] = 0;
        m_nEIMonitorCount[i].breakpoint_enable[j] = false;
        m_nEIMonitorCount[i].breakpoint_set[j] = 0;
      }
      m_nEIMonitorCount[i].running = true;
      m_nEIMonitorCount[i].bufPos = 0;
    }
  }

  if(0 != m_pstInterfaceSpec->m_nNumEOs){
    m_nEOMonitorCount = new SMonitorEvent[m_pstInterfaceSpec->m_nNumEOs];

    for(TForteUInt32 i = 0; i < m_pstInterfaceSpec->m_nNumEOs; i++){
      for(unsigned int j = 0; j < MONITOR_BUFFER_LENGTH; j++){
        m_nEOMonitorCount[i].eventCount[j] = 0;
        m_nEOMonitorCount[i].timestamp[j] = 0;
        m_nEOMonitorCount[i].breakpoint_enable[j] = false;
        m_nEOMonitorCount[i].breakpoint_set[j] = 0;
      }
      m_nEOMonitorCount[i].running = true;
      m_nEOMonitorCount[i].bufPos = 0;
    }
  }

}

//////////////////////////////////////////////////////////////////////////////
// EO-Monitor functions
//////////////////////////////////////////////////////////////////////////////
bool CFunctionBlock::startEIBreakpoint(TEventID p_nEventId){
  m_poResource->m_oResDataConSync.lock();
  if(p_nEventId < cg_unInvalidPortId){
    m_nEIMonitorCount[p_nEventId].breakpoint_enable[m_nEIMonitorCount[p_nEventId].bufPos] = true;
  }
  m_poResource->m_oResDataConSync.unlock();
  return true;
}

bool CFunctionBlock::stopEIBreakpoint(TEventID p_nEventId){
  m_poResource->m_oResDataConSync.lock();
  if(p_nEventId < cg_unInvalidPortId){
    m_nEIMonitorCount[p_nEventId].breakpoint_enable[m_nEIMonitorCount[p_nEventId].bufPos] = false;
  }
  m_poResource->m_oResDataConSync.unlock();
  return true;
}

bool CFunctionBlock::clearEIBreakpoint(TEventID p_nEventId){
  m_poResource->m_oResDataConSync.lock();
  if(p_nEventId == cg_unInvalidPortId){
    m_poResource->m_oResDataConSync.unlock();
    return false;
  }
  if(m_nEIMonitorCount[p_nEventId].breakpoint_set[m_nEIMonitorCount[p_nEventId].bufPos] > 0){
    // Get Resource
    //CResource &res = this->getResource();
    //res.startManagedObject();
    if(m_nEIMonitorCount[p_nEventId].breakpoint_enable[m_nEIMonitorCount[p_nEventId].bufPos] == true){
      m_nEIMonitorCount[p_nEventId].breakpoint_set[m_nEIMonitorCount[p_nEventId].bufPos] = -1; // clear breakpoint, execute once
    }
    else{
      m_nEIMonitorCount[p_nEventId].breakpoint_set[m_nEIMonitorCount[p_nEventId].bufPos] = 0; // clear breakpoint
    }
  }
  m_poResource->m_oResDataConSync.unlock();
  return true;
}

//////////////////////////////////////////////////////////////////////////////
// EI-Monitor functions
//////////////////////////////////////////////////////////////////////////////
bool CFunctionBlock::startEOBreakpoint(TEventID p_nEventId){
  m_poResource->m_oResDataConSync.lock();
  if(p_nEventId < cg_unInvalidPortId){
    m_nEOMonitorCount[p_nEventId].breakpoint_enable[m_nEOMonitorCount[p_nEventId].bufPos] = true;
    m_nEOMonitorCount[p_nEventId].breakpoint_set[m_nEOMonitorCount[p_nEventId].bufPos] = 0;
  }
  m_poResource->m_oResDataConSync.unlock();
  return true;
}

bool CFunctionBlock::stopEOBreakpoint(TEventID p_nEventId){
  m_poResource->m_oResDataConSync.lock();
  if(p_nEventId < cg_unInvalidPortId){
    m_nEOMonitorCount[p_nEventId].breakpoint_enable[m_nEOMonitorCount[p_nEventId].bufPos] = false;
    m_nEOMonitorCount[p_nEventId].breakpoint_set[m_nEOMonitorCount[p_nEventId].bufPos] = 0;
  }
  m_poResource->m_oResDataConSync.unlock();
  return true;
}

bool CFunctionBlock::clearEOBreakpoint(TEventID p_nEventId){
  m_poResource->m_oResDataConSync.lock();
  if(p_nEventId == cg_unInvalidPortId){
    m_poResource->m_oResDataConSync.unlock();
    return false;
  }
  if(m_nEOMonitorCount[p_nEventId].breakpoint_set[m_nEOMonitorCount[p_nEventId].bufPos] > 0){
    // Get Resource
    //CResource &res = this->getResource();
    //res.startManagedObject();
    if(m_nEOMonitorCount[p_nEventId].breakpoint_enable[m_nEOMonitorCount[p_nEventId].bufPos] == true){
      m_nEOMonitorCount[p_nEventId].breakpoint_set[m_nEOMonitorCount[p_nEventId].bufPos] = -1; // clear breakpoint, execute once
    }
    else{
      m_nEOMonitorCount[p_nEventId].breakpoint_set[m_nEOMonitorCount[p_nEventId].bufPos] = 0; // clear breakpoint
    }
  }
  m_poResource->m_oResDataConSync.unlock();
  return true;
}

bool CFunctionBlock::getEIBreakpoint(TEventID p_nEventId, bool & enable, int & set){
  bool ret = false;
  m_poResource->m_oResDataConSync.lock();
  if(p_nEventId < cg_unInvalidPortId){
    enable = m_nEIMonitorCount[p_nEventId].breakpoint_enable[m_nEIMonitorCount[p_nEventId].bufPos];
    set = m_nEIMonitorCount[p_nEventId].breakpoint_set[m_nEIMonitorCount[p_nEventId].bufPos]; // > 0;
    ret = true;
  }
  m_poResource->m_oResDataConSync.unlock();
  return ret;
}

bool CFunctionBlock::getEOBreakpoint(TEventID p_nEventId, bool & enable, int & set){
  bool ret = false;
  m_poResource->m_oResDataConSync.lock();
  if(p_nEventId < cg_unInvalidPortId){
    enable = m_nEOMonitorCount[p_nEventId].breakpoint_enable[m_nEOMonitorCount[p_nEventId].bufPos];
    set = m_nEOMonitorCount[p_nEventId].breakpoint_set[m_nEOMonitorCount[p_nEventId].bufPos]; // > 0;
    ret = true;
  }
  m_poResource->m_oResDataConSync.unlock();
  return ret;
}

//////////////////////////////////////////////////////////////////////////////
// Data-Monitor functions
//////////////////////////////////////////////////////////////////////////////
bool CFunctionBlock::forceData(CStringDictionary::TStringId pa_acName, const char * forceValue){

  unsigned int portID = 0;

  portID = getDOID(pa_acName);
  if(portID != cg_unInvalidPortId){
    CIEC_ANY *poDO = getDO(portID);
    poDO->setForced(true);
    poDO->fromString(forceValue);

    if(0 != m_apoDOConns[portID]){
      m_poResource->m_oResDataConSync.lock();
      m_apoDOConns[portID]->writeData(poDO);
      m_poResource->m_oResDataConSync.unlock();
    }
    return true;
  }

  portID = getDIID(pa_acName);

  if(portID != cg_unInvalidPortId){
    CIEC_ANY *poDI = getDI(portID);
    poDI->setForced(true);
    poDI->fromString(forceValue);
    return true;
  }

  return false;
}

#endif //FORTE_SUPPORT_MONITORING

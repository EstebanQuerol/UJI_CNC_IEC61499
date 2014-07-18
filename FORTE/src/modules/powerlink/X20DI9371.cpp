/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: X20DI9371
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     0.0: 2011-05-31/4DIAC-IDE - 4DIAC-Consortium - null
 ***     1.0: 2011-05-31/FA,TS - AIT - null
 *************************************************************************/

#include "X20DI9371.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "X20DI9371_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_X20DI9371, g_nStringIdX20DI9371)

const CStringDictionary::TStringId FORTE_X20DI9371::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdCNID, g_nStringIdMODID };

const CStringDictionary::TStringId FORTE_X20DI9371::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdUINT };

const CStringDictionary::TStringId FORTE_X20DI9371::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdCNIDO, g_nStringIdSTATUS, g_nStringIdDI01, g_nStringIdDI02, g_nStringIdDI03, g_nStringIdDI04, g_nStringIdDI05, g_nStringIdDI06, g_nStringIdDI07, g_nStringIdDI08, g_nStringIdDI09, g_nStringIdDI10, g_nStringIdDI11, g_nStringIdDI12 };

const CStringDictionary::TStringId FORTE_X20DI9371::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdUSINT, g_nStringIdSTRING, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL, g_nStringIdBOOL };

const TForteInt16 FORTE_X20DI9371::scm_anEIWithIndexes[] = { 0, 4 };
const TDataIOID FORTE_X20DI9371::scm_anEIWith[] = { 0, 1, 2, 255, 0, 255 };
const CStringDictionary::TStringId FORTE_X20DI9371::scm_anEventInputNames[] = { g_nStringIdINIT, g_nStringIdREQ };

const TDataIOID FORTE_X20DI9371::scm_anEOWith[] = { 0, 2, 1, 255, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 2, 0, 255 };
const TForteInt16 FORTE_X20DI9371::scm_anEOWithIndexes[] = { 0, 4, -1 };
const CStringDictionary::TStringId FORTE_X20DI9371::scm_anEventOutputNames[] = { g_nStringIdINITO, g_nStringIdCNF };

const SFBInterfaceSpec FORTE_X20DI9371::scm_stFBInterfaceSpec = { 2, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 2, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 3, scm_anDataInputNames, scm_anDataInputTypeIds, 15, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_X20DI9371::executeEvent(int pa_nEIID){
  switch (pa_nEIID){
    case scm_nEventINITID:
      if(QI() == true){
        m_bInitOk = false;

        CEplStackWrapper &eplStack = CEplStackWrapper::getInstance();

        // Get settings for intputs
        CProcessImageMatrix* moduleIOs = eplStack.getProcessImageMatrixOut()->getModuleEntries(CNID(), MODID());

        if(moduleIOs){
          // Inputs (process inputs) always start with i = 1
          // Check xap.xml if a BitUnused is present
          for(unsigned int i = 1; i < moduleIOs->getNrOfEntries() - 1; i++){
            m_oEplMapping.m_lCurrentValues.push_back(new SEplMapping::SEplMappingValues(moduleIOs->getEntry(i)[0], moduleIOs->getEntry(i)[1], moduleIOs->getEntry(i)[2]));
          }

          delete moduleIOs;

          eplStack.registerCallback((IEplCNCallback*) this);

          m_bInitOk = true;
        }
      }
      QO() = QI();
      CNIDO() = CNID();
      sendOutputEvent(scm_nEventINITOID);
      break;
    case scm_nEventREQID:
      if(QI() == true && m_bInitOk){
        m_oSync.lock();
        SEplMapping::TEplMappingList::Iterator itEnd = m_oEplMapping.m_lCurrentValues.end();
        SEplMapping::TEplMappingList::Iterator it = m_oEplMapping.m_lCurrentValues.begin();
        for(int i = 3; i < m_pstInterfaceSpec->m_nNumDOs && it != itEnd; i++, ++it){
          bool ioVal = false;
          ioVal = *(it->m_pchCurrentValue) != 0x00;
          *static_cast<CIEC_BOOL*>(getDO(i)) = ioVal;
        }
        m_oSync.unlock();
      }
      QO() = QI();
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}

void FORTE_X20DI9371::cnSynchCallback(){
  CEplStackWrapper &eplStack = CEplStackWrapper::getInstance();

  m_oSync.lock();

  SEplMapping::TEplMappingList::Iterator itEnd = m_oEplMapping.m_lCurrentValues.end();
  SEplMapping::TEplMappingList::Iterator it = m_oEplMapping.m_lCurrentValues.begin();
  for(it; it != itEnd; ++it){
    bool ioVal = false;
    ioVal = (eplStack.getProcImageOut()[it->m_nPiOffset] & (char) (0x01 << it->m_nBitOffset)) != 0x00;
    *(it->m_pchCurrentValue) = (char) ioVal;
  }

  m_oSync.unlock();
}


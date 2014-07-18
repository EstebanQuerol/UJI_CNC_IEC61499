/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: EMB_RMT_RES
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     0.0: 2010-01-20/4DIAC-IDE - 4DIAC-Consortium -
 *************************************************************************/
#include "EMB_RMT_RES.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "EMB_RMT_RES_gen.cpp"
#endif
#include "../events/E_RESTART.h"
#include "../ita/DEV_MGR.h"
#include "../events/E_SR.h"
#include <commfb.h>


//DEFINE_FIRMWARE_FB(EMB_RMT_RES, g_nStringIdEMB_RMT_RES);

const SFBInterfaceSpec EMB_RMT_RES::scm_stRESInterfaceSpec = {
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

//const char * const EMB_RMT_RES::scm_acId = "fbdk[].ip[localhost:61499]";

EMB_RMT_RES::EMB_RMT_RES(const CStringDictionary::TStringId pa_nInstanceNameId, CResource* pa_poDevice, const char * pa_acId):
             CResource(pa_poDevice, &scm_stRESInterfaceSpec, pa_nInstanceNameId, 0, 0){

  m_oObjectHandler.addFB(CTypeLib::createFB(g_nStringIdSTART, g_nStringIdE_RESTART, this));
  m_oObjectHandler.addFB(CTypeLib::createFB(g_nStringIdMGR_FF, g_nStringIdE_SR, this));
  CFunctionBlock *poFB = CTypeLib::createFB(g_nStringIdSVR, g_nStringIdSERVER_1_2, this);
  m_oObjectHandler.addFB(poFB);
  static_cast<forte::com_infra::CCommFB *>(poFB)->ID() = pa_acId;

  m_oObjectHandler.addFB(CTypeLib::createFB(g_nStringIdMGR, g_nStringIdDEV_MGR, this));


  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSTART, g_nStringIdCOLD),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR_FF, g_nStringIdS));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSTART, g_nStringIdWARM),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR_FF, g_nStringIdS));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSTART, g_nStringIdSTOP),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR_FF, g_nStringIdR));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR_FF, g_nStringIdEO),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSVR, g_nStringIdINIT));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSVR, g_nStringIdINITO),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR, g_nStringIdINIT));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSVR, g_nStringIdIND),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR, g_nStringIdREQ));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR, g_nStringIdCNF),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSVR, g_nStringIdRSP));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR_FF, g_nStringIdQ),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSVR, g_nStringIdQI));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSVR, g_nStringIdQO),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR, g_nStringIdQI));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSVR, g_nStringIdRD_1),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR, g_nStringIdDST));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSVR, g_nStringIdRD_2),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR, g_nStringIdRQST));
  m_oObjectHandler.createConnection(GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdMGR, g_nStringIdRESP),
                     GENERATE_CONNECTION_PORT_ID_2_ARG(g_nStringIdSVR, g_nStringIdSD_1));
}

EMB_RMT_RES::~EMB_RMT_RES(){
}

CStringDictionary::TStringId EMB_RMT_RES::getFBTypeId(void) const {
  return g_nStringIdEMB_RMT_RES;
}




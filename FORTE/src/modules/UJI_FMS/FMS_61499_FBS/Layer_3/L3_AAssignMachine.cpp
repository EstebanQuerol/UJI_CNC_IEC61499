/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: L3_AAssignMachine
 *** Description: null
 *** Version: 
 *************************************************************************/

#include "L3_AAssignMachine.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "L3_AAssignMachine_gen.cpp"
#endif

DEFINE_ADAPTER_TYPE(FORTE_L3_AAssignMachine, g_nStringIdL3_AAssignMachine)

const CStringDictionary::TStringId FORTE_L3_AAssignMachine::scm_anDataInputNames[] = {g_nStringIdMTypeS, g_nStringIdMStateS, g_nStringIdMPriorityS, g_nStringIdMAssignS, g_nStringIdMFinalAssignS};

const CStringDictionary::TStringId FORTE_L3_AAssignMachine::scm_anDataInputTypeIds[] = {g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdINT, g_nStringIdARRAY, 15, g_nStringIdUINT, g_nStringIdARRAY, 15, g_nStringIdUINT};

const CStringDictionary::TStringId FORTE_L3_AAssignMachine::scm_anDataOutputNames[] = {g_nStringIdMTypeP, g_nStringIdMStateP, g_nStringIdMPriorityP, g_nStringIdMAssignP, g_nStringIdMFinalAssignP};

const CStringDictionary::TStringId FORTE_L3_AAssignMachine::scm_anDataOutputTypeIds[] = {g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdUSINT, g_nStringIdARRAY, 15, g_nStringIdINT, g_nStringIdARRAY, 15, g_nStringIdUINT, g_nStringIdARRAY, 15, g_nStringIdUINT};

const TDataIOID FORTE_L3_AAssignMachine::scm_anEIWith[] = {0, 1, 2, 3, 255, 4, 255};
const TForteInt16 FORTE_L3_AAssignMachine::scm_anEIWithIndexes[] = {0, 5, -1};
const CStringDictionary::TStringId FORTE_L3_AAssignMachine::scm_anEventInputNames[] = {g_nStringIdCNF1, g_nStringIdCNF2};

const TDataIOID FORTE_L3_AAssignMachine::scm_anEOWith[] = {0, 1, 2, 3, 255, 4, 255};
const TForteInt16 FORTE_L3_AAssignMachine::scm_anEOWithIndexes[] = {0, 5, -1};
const CStringDictionary::TStringId FORTE_L3_AAssignMachine::scm_anEventOutputNames[] = {g_nStringIdCHK, g_nStringIdASG};

const SFBInterfaceSpec FORTE_L3_AAssignMachine::scm_stFBInterfaceSpecSocket = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

const SFBInterfaceSpec FORTE_L3_AAssignMachine::scm_stFBInterfaceSpecPlug = {
  2,  scm_anEventOutputNames,  scm_anEOWith,  scm_anEOWithIndexes,
  2,  scm_anEventInputNames,  scm_anEIWith, scm_anEIWithIndexes,  5,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  5,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0, 0
};




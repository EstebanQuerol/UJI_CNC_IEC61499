/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: TrkBlob
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-06-30/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "TrkBlob.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_TrkBlob, g_nStringIdTrkBlob)

const CStringDictionary::TStringId FORTE_TrkBlob::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdCH, g_nStringIdI_BLOB, g_nStringIdINFO };

const CStringDictionary::TStringId FORTE_TrkBlob::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL };

const CStringDictionary::TStringId FORTE_TrkBlob::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdCOUNT, g_nStringIdX, g_nStringIdY };

const CStringDictionary::TStringId FORTE_TrkBlob::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT };

const TForteInt16 FORTE_TrkBlob::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_TrkBlob::scm_anEIWith[] = { 0, 1, 2, 3, 255 };
const CStringDictionary::TStringId FORTE_TrkBlob::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_TrkBlob::scm_anEOWith[] = { 0, 1, 2, 3, 255 };
const TForteInt16 FORTE_TrkBlob::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_TrkBlob::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_TrkBlob::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 4, scm_anDataInputNames, scm_anDataInputTypeIds, 4, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_TrkBlob::executeEvent(int pa_nEIID){
  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventREQID:
      if(true == QI()){
        //TODO: test with and without type casts
        track_update(); // get new image data
        COUNT() = static_cast<TForteInt16>(track_count(CH()));
        if(COUNT() > I_BLOB()){ // there is at least I_BLOBs on CH()
          X() = static_cast<TForteInt16>(track_x(CH(), I_BLOB())); // get image x data
          Y() = static_cast<TForteInt16>(track_y(CH(), I_BLOB())); //    and y data
          if(true == INFO()){
            if(COUNT() > I_BLOB()){ // there is a blob
              printf("On Channel=%i  Blob#%i is at (%d,%d)\n", (int) CH(), (int) I_BLOB(), (int) X(), (int) Y());
            }
            else{
              printf("No Blob#%i in sight on Color Channel %i\n", (int) I_BLOB(), (int) CH());
            }
          }
        }
      }
      sendOutputEvent(scm_nEventCNFID);
      break;
  }
}


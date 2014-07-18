/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: TrkCentroid
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-05-22/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "TrkCentroid.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_TrkCentroid, g_nStringIdTrkCentroid)

const CStringDictionary::TStringId FORTE_TrkCentroid::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdCH, g_nStringIdI_BLOB, g_nStringIdINFO };

const CStringDictionary::TStringId FORTE_TrkCentroid::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL };

const CStringDictionary::TStringId FORTE_TrkCentroid::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdCOUNT, g_nStringIdSIZE, g_nStringIdFRAME, g_nStringIdX, g_nStringIdY, g_nStringIdCONFIDENCE };

const CStringDictionary::TStringId FORTE_TrkCentroid::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT };

const TForteInt16 FORTE_TrkCentroid::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_TrkCentroid::scm_anEIWith[] = { 0, 1, 2, 3, 255 };
const CStringDictionary::TStringId FORTE_TrkCentroid::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_TrkCentroid::scm_anEOWith[] = { 0, 1, 2, 3, 4, 5, 6, 255 };
const TForteInt16 FORTE_TrkCentroid::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_TrkCentroid::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_TrkCentroid::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 4, scm_anDataInputNames, scm_anDataInputTypeIds, 7, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_TrkCentroid::executeEvent(int pa_nEIID){
  QO() = QI();
  switch (pa_nEIID){
    case scm_nEventREQID:
      if(true == QI()){
        //TODO: test with and without type casts
        track_update(); // get new image data
        COUNT() = static_cast<TForteInt16>(track_count(CH()));

        if(COUNT() > I_BLOB()){ // there is at least I_BLOBs on CH()
          SIZE() = static_cast<TForteInt16>(track_size(CH(), I_BLOB())); //
          FRAME() = static_cast<TForteInt16>(track_get_frame()); //
          CONFIDENCE() = static_cast<TForteInt16>(track_confidence(CH(), I_BLOB()));
          X() = static_cast<TForteInt16>(track_x(CH(), I_BLOB())); // get image  data
          Y() = static_cast<TForteInt16>(track_y(CH(), I_BLOB())); //    and data

          if(true == INFO()){
            if(COUNT() > I_BLOB()){ // there is a blob
              printf("On Channel=%d  Eclipse Blob#%d is at (X,Y)=(%d,%d)\n", (int) CH(), (int) I_BLOB(), (int) X(), (int) Y());
              printf("\t Confidence=%d; Size=%d;Frame=%d\n", (int) CONFIDENCE(), (int) SIZE(), (int) FRAME());
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


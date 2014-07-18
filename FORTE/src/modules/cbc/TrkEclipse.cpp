/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: TrkEclipse
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-05-22/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "TrkEclipse.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_TrkEclipse, g_nStringIdTrkEclipse)

const CStringDictionary::TStringId FORTE_TrkEclipse::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdCH, g_nStringIdI_BLOB, g_nStringIdINFO };

const CStringDictionary::TStringId FORTE_TrkEclipse::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL };

const CStringDictionary::TStringId FORTE_TrkEclipse::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdCOUNT, g_nStringIdSIZE, g_nStringIdFRAME, g_nStringIdX, g_nStringIdY, g_nStringIdCONFIDENCE, g_nStringIdMAJOR, g_nStringIdMINOR };

const CStringDictionary::TStringId FORTE_TrkEclipse::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT };

const TForteInt16 FORTE_TrkEclipse::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_TrkEclipse::scm_anEIWith[] = { 0, 1, 2, 3, 255 };
const CStringDictionary::TStringId FORTE_TrkEclipse::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_TrkEclipse::scm_anEOWith[] = { 0, 1, 2, 3, 6, 7, 8, 4, 5, 255 };
const TForteInt16 FORTE_TrkEclipse::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_TrkEclipse::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_TrkEclipse::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 4, scm_anDataInputNames, scm_anDataInputTypeIds, 9, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_TrkEclipse::executeEvent(int pa_nEIID){
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
          MAJOR() = static_cast<TForteInt16>(track_major_axis(CH(), I_BLOB())); // get image  data
          MINOR() = static_cast<TForteInt16>(track_minor_axis(CH(), I_BLOB())); //    and data

          if(true == INFO()){
            if(COUNT() > I_BLOB()){ // there is a blob
              printf("On Channel=%d  Eclipse Blob#%d is at (X,Y,MAJOR,MINOR)=(%d,%d,%d,%d)\n", (int) CH(), (int) I_BLOB(), (int) X(), (int) Y(), (int) MAJOR(), (int) MINOR());
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


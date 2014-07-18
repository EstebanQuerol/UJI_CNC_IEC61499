/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: TrkBox
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-05-22/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "TrkBox.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_TrkBox, g_nStringIdTrkBox)

const CStringDictionary::TStringId FORTE_TrkBox::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdCH, g_nStringIdI_BLOB, g_nStringIdINFO };

const CStringDictionary::TStringId FORTE_TrkBox::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL };

const CStringDictionary::TStringId FORTE_TrkBox::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdCOUNT, g_nStringIdSIZE, g_nStringIdFRAME, g_nStringIdCONFIDENCE, g_nStringIdRT, g_nStringIdLT, g_nStringIdTOP, g_nStringIdBOTTOM, g_nStringIdW, g_nStringIdH };

const CStringDictionary::TStringId FORTE_TrkBox::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT };

const TForteInt16 FORTE_TrkBox::scm_anEIWithIndexes[] = { 0 };
const TDataIOID FORTE_TrkBox::scm_anEIWith[] = { 0, 1, 2, 3, 255 };
const CStringDictionary::TStringId FORTE_TrkBox::scm_anEventInputNames[] = { g_nStringIdREQ };

const TDataIOID FORTE_TrkBox::scm_anEOWith[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 255 };
const TForteInt16 FORTE_TrkBox::scm_anEOWithIndexes[] = { 0, -1 };
const CStringDictionary::TStringId FORTE_TrkBox::scm_anEventOutputNames[] = { g_nStringIdCNF };

const SFBInterfaceSpec FORTE_TrkBox::scm_stFBInterfaceSpec = { 1, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 1, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 4, scm_anDataInputNames, scm_anDataInputTypeIds, 11, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_TrkBox::executeEvent(int pa_nEIID){
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
          LT() = static_cast<TForteInt16>(track_bbox_left(CH(), I_BLOB())); // get image  data
          RT() = static_cast<TForteInt16>(track_bbox_right(CH(), I_BLOB())); //    and data
          TOP() = static_cast<TForteInt16>(track_bbox_top(CH(), I_BLOB())); // get image  data
          BOTTOM() = static_cast<TForteInt16>(track_bbox_bottom(CH(), I_BLOB())); //    and data
          W() = static_cast<TForteInt16>(track_bbox_width(CH(), I_BLOB())); //
          H() = static_cast<TForteInt16>(track_bbox_height(CH(), I_BLOB())); //
          if(true == INFO()){
            if(COUNT() > I_BLOB()){ // there is a blob
              printf("On Channel=%d  Box Blob#%d is at (LT,RT,T,B)=(%d,%d,%d,%d)\n", (int) CH(), (int) I_BLOB(), (int) LT(), (int) RT(), (int) TOP(), (int) BOTTOM());
              printf("\t(W;H)=(%d,%d), Confidence=%d; Size=%d;Frame=%d\n", (int) W(), (int) H(), (int) CONFIDENCE(), (int) SIZE(), (int) FRAME());
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


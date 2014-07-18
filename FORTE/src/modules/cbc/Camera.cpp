/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Camera
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-05-26/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#include "Camera.h"
#include <autoinclude_cbc.h>

DEFINE_FIRMWARE_FB(FORTE_Camera, g_nStringIdCamera)

const CStringDictionary::TStringId FORTE_Camera::scm_anDataInputNames[] = { g_nStringIdQI, g_nStringIdCH, g_nStringIdI_BLOB, g_nStringIdINFO };

const CStringDictionary::TStringId FORTE_Camera::scm_anDataInputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdBOOL };

const CStringDictionary::TStringId FORTE_Camera::scm_anDataOutputNames[] = { g_nStringIdQO, g_nStringIdCOUNT, g_nStringIdSIZE, g_nStringIdFRAME, g_nStringIdCONFIDENCE, g_nStringIdBLOB_WL, g_nStringIdCENTRIOD_POS, g_nStringIdBOX_POS, g_nStringIdECLIPSE_POS };

const CStringDictionary::TStringId FORTE_Camera::scm_anDataOutputTypeIds[] = { g_nStringIdBOOL, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdARRAY, 2, g_nStringIdINT, g_nStringIdARRAY, 2, g_nStringIdINT, g_nStringIdARRAY, 4, g_nStringIdINT, g_nStringIdARRAY, 2, g_nStringIdINT };

const TForteInt16 FORTE_Camera::scm_anEIWithIndexes[] = { 0, 5, 10 };
const TDataIOID FORTE_Camera::scm_anEIWith[] = { 0, 1, 2, 3, 255, 2, 1, 0, 3, 255, 0, 1, 2, 3, 255 };
const CStringDictionary::TStringId FORTE_Camera::scm_anEventInputNames[] = { g_nStringIdREQ, g_nStringIdBOX, g_nStringIdECLIPSE };

const TDataIOID FORTE_Camera::scm_anEOWith[] = { 0, 1, 2, 3, 6, 4, 5, 255, 4, 5, 0, 7, 255, 8, 4, 3, 2, 255 };
const TForteInt16 FORTE_Camera::scm_anEOWithIndexes[] = { 0, 8, 13, -1 };
const CStringDictionary::TStringId FORTE_Camera::scm_anEventOutputNames[] = { g_nStringIdCNF, g_nStringIdBOXO, g_nStringIdECLIPSEO };

const SFBInterfaceSpec FORTE_Camera::scm_stFBInterfaceSpec = { 3, scm_anEventInputNames, scm_anEIWith, scm_anEIWithIndexes, 3, scm_anEventOutputNames, scm_anEOWith, scm_anEOWithIndexes, 4, scm_anDataInputNames, scm_anDataInputTypeIds, 9, scm_anDataOutputNames, scm_anDataOutputTypeIds, 0, 0 };

void FORTE_Camera::executeEvent(int pa_nEIID){
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
          CENTRIOD_POS()[0] = static_cast<TForteInt16>(track_x(CH(), I_BLOB())); // get image  data
          CENTRIOD_POS()[1] = static_cast<TForteInt16>(track_y(CH(), I_BLOB())); //    and data

          if(true == INFO()){
            if(COUNT() > I_BLOB()){ // there is a blob
              printf("On Channel=%d  Eclipse Blob#%d is at (X,Y)=(%d,%d)\n", (int) CH(), (int) I_BLOB(), (int) CENTRIOD_POS()[0], (int) CENTRIOD_POS()[1]);
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
    case scm_nEventBOXID:
      if(true == QI()){
        //TODO: test with and without type casts
        track_update(); // get new image data
        COUNT() = static_cast<TForteInt16>(track_count(CH()));
        if(COUNT() > I_BLOB()){ // there is at least I_BLOBs on CH()
          SIZE() = static_cast<TForteInt16>(track_size(CH(), I_BLOB())); //
          FRAME() = static_cast<TForteInt16>(track_get_frame()); //
          CONFIDENCE() = static_cast<TForteInt16>(track_confidence(CH(), I_BLOB()));

          BOX_POS()[0] = static_cast<TForteInt16>(track_bbox_left(CH(), I_BLOB())); // get image  data
          BOX_POS()[1] = static_cast<TForteInt16>(track_bbox_right(CH(), I_BLOB())); //    and data
          BOX_POS()[2] = static_cast<TForteInt16>(track_bbox_top(CH(), I_BLOB())); // get image  data
          BOX_POS()[3] = static_cast<TForteInt16>(track_bbox_bottom(CH(), I_BLOB())); //    and data

          BLOB_WL()[0] = static_cast<TForteInt16>(track_bbox_width(CH(), I_BLOB())); //
          BLOB_WL()[1] = static_cast<TForteInt16>(track_bbox_height(CH(), I_BLOB())); //

          if(true == INFO()){
            if(COUNT() > I_BLOB()){ // there is a blob
              printf("On Channel=%d  Box Blob#%d is at (LT,RT,T,B)=(%d,%d,%d,%d)\n", (int) CH(), (int) I_BLOB(), (int) BOX_POS()[0], (int) BOX_POS()[1], (int) BOX_POS()[2], (int) BOX_POS()[3]);
              printf("\t(W;H)=(%d,%d), Confidence=%d; Size=%d;Frame=%d\n", (int) BLOB_WL()[0], (int) BLOB_WL()[1], (int) CONFIDENCE(), (int) SIZE(), (int) FRAME());
            }
            else{
              printf("No Blob#%i in sight on Color Channel %i\n", (int) I_BLOB(), (int) CH());
            }
          }
        }
      }
      sendOutputEvent(scm_nEventBOXOID);
      break;
    case scm_nEventECLIPSEID:
      if(true == QI()){
        //TODO: test with and without type casts
        track_update(); // get new image data
        COUNT() = static_cast<TForteInt16>(track_count(CH()));

        if(COUNT() > I_BLOB()){ // there is at least I_BLOBs on CH()
          SIZE() = static_cast<TForteInt16>(track_size(CH(), I_BLOB())); //
          FRAME() = static_cast<TForteInt16>(track_get_frame()); //
          CONFIDENCE() = static_cast<TForteInt16>(track_confidence(CH(), I_BLOB()));
          //X() = static_cast<TForteInt16>(track_x(CH(), I_BLOB())); // get image  data
          //Y() = static_cast<TForteInt16>(track_y(CH(), I_BLOB())); //    and data
          ECLIPSE_POS()[0] = static_cast<TForteInt16>(track_major_axis(CH(), I_BLOB())); // get image  data
          ECLIPSE_POS()[1] = static_cast<TForteInt16>(track_minor_axis(CH(), I_BLOB())); //    and data

          if(true == INFO()){
            if(COUNT() > I_BLOB()){ // there is a blob
              printf("On Channel=%d  Eclipse Blob#%d is at (MAJOR,MINOR)=(%d,%d)\n", (int) CH(), (int) I_BLOB(), (int) ECLIPSE_POS()[0], (int) ECLIPSE_POS()[1]);
              printf("\t Confidence=%d; Size=%d;Frame=%d\n", (int) CONFIDENCE(), (int) SIZE(), (int) FRAME());
            }
            else{
              printf("No Blob#%i in sight on Color Channel %i\n", (int) I_BLOB(), (int) CH());
            }
          }

        }
      }
      sendOutputEvent(scm_nEventECLIPSEOID);
      break;
  }
}


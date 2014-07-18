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

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_bool.h>
#include <forte_array.h>

class FORTE_Camera : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_Camera)

  private:
    static const CStringDictionary::TStringId scm_anDataInputNames[];
    static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }
    ;

    CIEC_INT &CH(){
      return *static_cast<CIEC_INT*>(getDI(1));
    }
    ;

    CIEC_INT &I_BLOB(){
      return *static_cast<CIEC_INT*>(getDI(2));
    }
    ;

    CIEC_BOOL &INFO(){
      return *static_cast<CIEC_BOOL*>(getDI(3));
    }
    ;

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    CIEC_INT &COUNT(){
      return *static_cast<CIEC_INT*>(getDO(1));
    }
    ;

    CIEC_INT &SIZE(){
      return *static_cast<CIEC_INT*>(getDO(2));
    }
    ;

    CIEC_INT &FRAME(){
      return *static_cast<CIEC_INT*>(getDO(3));
    }
    ;

    CIEC_INT &CONFIDENCE(){
      return *static_cast<CIEC_INT*>(getDO(4));
    }
    ;

    CIEC_INT *BLOB_WL(){
      return (CIEC_INT*) (*static_cast<CIEC_ARRAY *>(getDO(5)))[0]; //the first element marks the start of the array
    }
    ;

    CIEC_ARRAY &BLOB_WL_Array(){
      return *static_cast<CIEC_ARRAY*>(getDO(5));
    }
    ;

    CIEC_INT *CENTRIOD_POS(){
      return (CIEC_INT*) (*static_cast<CIEC_ARRAY *>(getDO(6)))[0]; //the first element marks the start of the array
    }
    ;

    CIEC_ARRAY &CENTRIOD_POS_Array(){
      return *static_cast<CIEC_ARRAY*>(getDO(6));
    }
    ;

    CIEC_INT *BOX_POS(){
      return (CIEC_INT*) (*static_cast<CIEC_ARRAY *>(getDO(7)))[0]; //the first element marks the start of the array
    }
    ;

    CIEC_ARRAY &BOX_POS_Array(){
      return *static_cast<CIEC_ARRAY*>(getDO(7));
    }
    ;

    CIEC_INT *ECLIPSE_POS(){
      return (CIEC_INT*) (*static_cast<CIEC_ARRAY *>(getDO(8)))[0]; //the first element marks the start of the array
    }
    ;

    CIEC_ARRAY &ECLIPSE_POS_Array(){
      return *static_cast<CIEC_ARRAY*>(getDO(8));
    }
    ;

    static const TEventID scm_nEventREQID = 0;
    static const TEventID scm_nEventBOXID = 1;
    static const TEventID scm_nEventECLIPSEID = 2;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const TDataIOID scm_anEIWith[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventCNFID = 0;
    static const TEventID scm_nEventBOXOID = 1;
    static const TEventID scm_nEventECLIPSEOID = 2;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(3, 4, 9, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_Camera){
  };

  virtual ~FORTE_Camera(){};

};

#endif //close the ifdef sequence from the beginning of the file

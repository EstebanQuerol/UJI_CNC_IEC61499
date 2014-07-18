/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateCliffSensors
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-07-26/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _ICREATECLIFFSENSORS_H_
#define _ICREATECLIFFSENSORS_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_bool.h>
#include <forte_array.h>

class FORTE_iCreateCliffSensors : public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_iCreateCliffSensors)

  private:
    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL *DarkCliff(){
      return (CIEC_BOOL*) (*static_cast<CIEC_ARRAY *>(getDO(0)))[0]; //the first element marks the start of the array
    }
    ;

    CIEC_ARRAY &DarkCliff_Array(){
      return *static_cast<CIEC_ARRAY*>(getDO(0));
    }
    ;

    CIEC_INT *State(){
      return (CIEC_INT*) (*static_cast<CIEC_ARRAY *>(getDO(1)))[0]; //the first element marks the start of the array
    }
    ;

    CIEC_ARRAY &State_Array(){
      return *static_cast<CIEC_ARRAY*>(getDO(1));
    }
    ;

    static const TEventID scm_nEventREQID = 0;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventCNFID = 0;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    static const SFBInterfaceSpec scm_stFBInterfaceSpec;

    FORTE_FB_DATA_ARRAY(1, 0, 2, 0)
    ;

    void executeEvent(int pa_nEIID);

  public:
    FUNCTION_BLOCK_CTOR(FORTE_iCreateCliffSensors){
  };

  virtual ~FORTE_iCreateCliffSensors(){};

};

#endif //close the ifdef sequence from the beginning of the file

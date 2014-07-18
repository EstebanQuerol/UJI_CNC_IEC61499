/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: iCreateDrive
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     0.0: 2012-08-27/4DIAC-IDE - 4DIAC-Consortium - null
 *************************************************************************/

#ifndef _ICREATEDRIVE_H_
#define _ICREATEDRIVE_H_

#include <funcbloc.h>
#include <forte_int.h>
#include <forte_bool.h>
#include <forte_array.h>

class FORTE_iCreateDrive: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_iCreateDrive)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_INT &Radius() {
    return *static_cast<CIEC_INT*>(getDI(0));
  };

  CIEC_INT &Speed() {
    return *static_cast<CIEC_INT*>(getDI(1));
  };

  CIEC_INT &LtSpeed() {
    return *static_cast<CIEC_INT*>(getDI(2));
  };

  CIEC_INT &RtSpeed() {
    return *static_cast<CIEC_INT*>(getDI(3));
  };

  CIEC_BOOL &Clockwise() {
    return *static_cast<CIEC_BOOL*>(getDI(4));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_INT &RadiusOut() {
    return *static_cast<CIEC_INT*>(getDO(0));
  };

  CIEC_INT *Speeds() {
    return (CIEC_INT*)(*static_cast<CIEC_ARRAY *>(getDO(1)))[0]; //the first element marks the start of the array
  };

  CIEC_ARRAY &Speeds_Array() {
    return *static_cast<CIEC_ARRAY*>(getDO(1));
  };

  CIEC_INT &Velocity() {
    return *static_cast<CIEC_INT*>(getDO(2));
  };

  CIEC_INT &VelocityLt() {
    return *static_cast<CIEC_INT*>(getDO(3));
  };

  CIEC_INT &VelocityRt() {
    return *static_cast<CIEC_INT*>(getDO(4));
  };

  CIEC_INT &Angle() {
    return *static_cast<CIEC_INT*>(getDO(5));
  };

  CIEC_INT &AngleTotal() {
    return *static_cast<CIEC_INT*>(getDO(6));
  };

  CIEC_INT &Distance() {
    return *static_cast<CIEC_INT*>(getDO(7));
  };

  static const TEventID scm_nEventStopID = 0;
  static const TEventID scm_nEventArcID = 1;
  static const TEventID scm_nEventStraightID = 2;
  static const TEventID scm_nEventSpinID = 3;
  static const TEventID scm_nEventDirectID = 4;
  static const TEventID scm_nEventGetInfoID = 5;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventStopOID = 0;
  static const TEventID scm_nEventArcOID = 1;
  static const TEventID scm_nEventStraightOID = 2;
  static const TEventID scm_nEventSpinOID = 3;
  static const TEventID scm_nEventDirectOID = 4;
  static const TEventID scm_nEventGetInfoOID = 5;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(6, 5, 8, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_iCreateDrive){
  };

  virtual ~FORTE_iCreateDrive(){};

};

#endif //close the ifdef sequence from the beginning of the file


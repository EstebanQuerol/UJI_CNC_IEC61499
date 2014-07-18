/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: FB_R_TRIG
 *** Description: rising edge detector
 *** Version:
 ***     1.0: 2009-09-14/4DIAC-IDE - 4DIAC-Consortium -
 *************************************************************************/

#ifndef _FB_R_TRIG_H_
#define _FB_R_TRIG_H_

#include <funcbloc.h>
#include <forte_bool.h>
#include <forte_array.h>

class FB_R_TRIG: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FB_R_TRIG)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[], scm_aunDIDataTypeIds[];
  static const CStringDictionary::TStringId scm_anDataOutputNames[], scm_aunDODataTypeIds[];
  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  FORTE_FB_DATA_ARRAY(1,1,1, 0);

  CIEC_BOOL M;

  void executeEvent(int pa_nEIID);

  CIEC_BOOL& CLK() {
  	return *static_cast<CIEC_BOOL*>(getDI(0));
  }

  CIEC_BOOL& Q() {
  	return *static_cast<CIEC_BOOL*>(getDO(0));
  }

public:
  FUNCTION_BLOCK_CTOR(FB_R_TRIG){};
  virtual ~FB_R_TRIG(){};

};

#endif //close the ifdef sequence from the beginning of the file


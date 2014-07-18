/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _E_D_FF_H_
#define _E_D_FF_H_

#include <funcbloc.h>
#include <forte_bool.h>

class E_D_FF: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(E_D_FF)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[], scm_aunDIDataTypeIds[];
  static const CStringDictionary::TStringId scm_anDataOutputNames[], scm_aunDODataTypeIds[];


  static const TEventID scm_nEventCLKID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventEOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  FORTE_FB_DATA_ARRAY(1,1,1, 0);


  virtual void executeEvent(int pa_nEIID);

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;
  
  CIEC_BOOL& D() {
   	return *static_cast<CIEC_BOOL*>(getDI(0));
  }

  CIEC_BOOL& Q() {
   	return *static_cast<CIEC_BOOL*>(getDO(0));
  }

public:
  FUNCTION_BLOCK_CTOR(E_D_FF){
  };

  virtual ~E_D_FF(){ };

};
#endif //close the ifdef sequence from the beginning of the file


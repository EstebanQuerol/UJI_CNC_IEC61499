/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _E_SR_H_
#define _E_SR_H_

#include <funcbloc.h>
#include <forte_bool.h>

class E_SR: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(E_SR)

private:
  static const CStringDictionary::TStringId scm_aunDataOutputNameIds[];
  static const CStringDictionary::TStringId scm_aunDataOutputDataTypeIds[];

  static const TEventID scm_nEventSID = 0;
  static const TEventID scm_nEventRID = 1;
  static const CStringDictionary::TStringId scm_aunEventInputNameIds[];

  static const TEventID scm_nEventEOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_aunEventOutputNameIds[];


  virtual void executeEvent(int pa_nEIID);

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;
  FORTE_FB_DATA_ARRAY(1,0,1, 0);

  CIEC_BOOL& Q() {
   	return *static_cast<CIEC_BOOL*>(getDO(0));
  }

public:
  FUNCTION_BLOCK_CTOR(E_SR){
  };
  virtual ~E_SR(){ };

};
#endif //close the ifdef sequence from the beginning of the file


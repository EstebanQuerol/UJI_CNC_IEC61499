/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _E_F_TRIG_H_
#define _E_F_TRIG_H_

#include <funcbloc.h>
#include <forte_bool.h>

class E_F_TRIG: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(E_F_TRIG)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[], scm_aunDIDataTypeIds[];

  static const TEventID scm_nEventEIID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventEOID = 0;
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  FORTE_FB_DATA_ARRAY(1,1,0, 0);

  bool m_bOldVal;


  virtual void executeEvent(int pa_nEIID);
  
  CIEC_BOOL& QI() {
   	return *static_cast<CIEC_BOOL*>(getDI(0));
  }

public:
  FUNCTION_BLOCK_CTOR(E_F_TRIG), m_bOldVal(false) {
  };

  virtual ~E_F_TRIG(){};

};

#endif //close the ifdef sequence from the beginning of the file


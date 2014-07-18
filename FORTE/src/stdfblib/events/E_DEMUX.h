/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _E_DEMUX_H_
#define _E_DEMUX_H_

#include <funcbloc.h>
#include <forte_uint.h>

class E_DEMUX: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(E_DEMUX)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[], scm_aunDIDataTypeIds[];

  static const TEventID scm_nEventEIID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventEO0ID = 0;
  static const TEventID scm_nEventEO1ID = 1;
  static const TEventID scm_nEventEO2ID = 2;
  static const TEventID scm_nEventEO3ID = 3;
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  FORTE_FB_DATA_ARRAY(1,1,1, 0);

  virtual void executeEvent(int pa_nEIID);
  
  CIEC_UINT& K() {
   	return *static_cast<CIEC_UINT*>(getDI(0));
  }

public:
  FUNCTION_BLOCK_CTOR(E_DEMUX){
  };
  virtual ~E_DEMUX(){};

};
#endif //close the ifdef sequence from the beginning of the file


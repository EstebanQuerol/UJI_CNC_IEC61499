/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef _TestStruct2TestStruct_H_
#define _TestStruct2TestStruct_H_

#include <funcbloc.h>
#include "FORTE_TestStruct.h"


class TestStruct2TestStruct: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(TestStruct2TestStruct)

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

  virtual void executeEvent(int pa_nEIID);

  CIEC_TestStruct& IN() {
	return *static_cast<CIEC_TestStruct*>(getDI(0));
  }

  CIEC_TestStruct& OUT() {
	return *static_cast<CIEC_TestStruct*>(getDO(0));
  }

public:
  FUNCTION_BLOCK_CTOR(TestStruct2TestStruct){};
  virtual ~TestStruct2TestStruct();


};

#endif /*_TestStruct2TestStruct_H_*/


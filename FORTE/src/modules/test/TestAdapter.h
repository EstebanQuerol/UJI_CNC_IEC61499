/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *     <date>: <author>, <author email> - changes
 *******************************************************************************/
#ifndef _TESTADAPTER_H_
#define _TESTADAPTER_H_

#include <adapter.h>
#include <forte_wstring.h>

class TESTADAPTER: public CAdapter{
  DECLARE_ADAPTER_TYPE(TESTADAPTER)
private:
  static const CStringDictionary::TStringId scm_anDataInputNamesSocket[], scm_aunDIDataTypeIds[];
  static const CStringDictionary::TStringId scm_anDataOutputNamesSocket[], scm_aunDODataTypeIds[];

  static const TEventID scm_nEventEIIDSocket = 0;
  static const TForteInt16 scm_anEIWithIndexesSocket[];
  static const TDataIOID scm_anEIWithSocket[];
  static const CStringDictionary::TStringId scm_anEventInputNamesSocket[];

  static const TEventID scm_nEventEOIDSocket = 0;
  static const TForteInt16 scm_anEOWithIndexesSocket[];
  static const TDataIOID scm_anEOWithSocket[];
  static const CStringDictionary::TStringId scm_anEventOutputNamesSocket[];

  FORTE_ADAPTER_DATA_ARRAY(2, 2, 2, 2, 0);

  static const SFBInterfaceSpec scm_stFBInterfaceSpecSocket;
  static const SFBInterfaceSpec scm_stFBInterfaceSpecPlug;

public:
  ADAPTER_CTOR(TESTADAPTER){
  };
  virtual ~TESTADAPTER();

};
#endif //close the ifdef sequence from the beginning of the file


/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef _FORTE_TESTSTRUCT_H_
#define _FORTE_TESTSTRUCT_H_

#include <forte_struct.h>
#include <forte_bool.h>
#include <forte_int.h>
#include <forte_any.h>


class CIEC_TestStruct : public CIEC_STRUCT {
  DECLARE_FIRMWARE_DATATYPE(TestStruct)

private:
  static const CStringDictionary::TStringId scm_unElementTypes[];
  static const CStringDictionary::TStringId scm_unElementNames[];

public:
  CIEC_TestStruct();

  virtual ~CIEC_TestStruct() {}

  CIEC_BOOL& FOO() {
    return (static_cast<CIEC_BOOL&>(getMembers()[0]));
  }

  CIEC_INT& BAR() {
      return (static_cast<CIEC_INT&>(getMembers()[1]));
  }
};

#endif /*_FORTE_TESTSTRUCT_H_*/

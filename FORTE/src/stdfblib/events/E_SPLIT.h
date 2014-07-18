/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _E_SPLIT_H_
#define _E_SPLIT_H_

#include <funcbloc.h>

class E_SPLIT: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(E_SPLIT)

private:
  static const TEventID scm_nEventEIID = 0;
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventEO1ID = 0;
  static const TEventID scm_nEventEO2ID = 1;
  static const CStringDictionary::TStringId scm_anEventOutputNames[];


  virtual void executeEvent(int pa_nEIID){
    if(scm_nEventEIID == pa_nEIID){
      sendOutputEvent( scm_nEventEO1ID);
      sendOutputEvent( scm_nEventEO2ID);
    }
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

  FORTE_FB_DATA_ARRAY(2,0,0, 0);

public:
  FUNCTION_BLOCK_CTOR(E_SPLIT){
  };
  virtual ~E_SPLIT(){};

};
#endif //close the ifdef sequence from the beginning of the file


/*******************************************************************************
 * Copyright (c) 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _GEN_E_MUX_H_
#define _GEN_E_MUX_H_

#include <funcbloc.h>
#include <forte_uint.h>

class GEN_E_MUX : public CFunctionBlock{
  DECLARE_GENERIC_FIRMWARE_FB(GEN_E_MUX)

  private:
    static const CStringDictionary::TStringId scm_anDataOutputNames[], scm_aunDODataTypeIds[];

    static const TEventID scm_nEventEOID = 0;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    CStringDictionary::TStringId *m_anEventInputNames;
    CStringDictionary::TStringId m_nConfiguredFBTypeNameId;

    virtual void executeEvent(int pa_nEIID);

    CIEC_UINT& K(){
      return *static_cast<CIEC_UINT*>(getDO(0));
    }

    GEN_E_MUX(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);
    virtual ~GEN_E_MUX();
  public:

    CStringDictionary::TStringId getFBTypeId(void) const{
      return m_nConfiguredFBTypeNameId;
    }

    bool configureFB(const char *pa_acConfigString);


};
#endif //close the ifdef sequence from the beginning of the file

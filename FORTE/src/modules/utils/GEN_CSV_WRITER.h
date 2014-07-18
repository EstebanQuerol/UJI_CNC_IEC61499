/*******************************************************************************
 * Copyright (c) 2012 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _GEN_CSV_WRITER_H_
#define _GEN_CSV_WRITER_H_

#include <funcbloc.h>
#include <forte_any.h>
#include <forte_string.h>
#include <forte_bool.h>
#include <stdio.h>

class GEN_CSV_WRITER : public CFunctionBlock{
    DECLARE_GENERIC_FIRMWARE_FB(GEN_CSV_WRITER)

  private:
    CIEC_BOOL &QI(){
      return *static_cast<CIEC_BOOL*>(getDI(0));
    }

    CIEC_STRING &FILE_NAME(){
      return *static_cast<CIEC_STRING*>(getDI(1));
    }

    static const CStringDictionary::TStringId scm_anDataOutputNames[];
    static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
    CIEC_BOOL &QO(){
      return *static_cast<CIEC_BOOL*>(getDO(0));
    }
    ;

    CIEC_STRING &STATUS(){
      return *static_cast<CIEC_STRING*>(getDO(1));
    }
    ;

    static const TEventID scm_nEventINITID = 0;
    static const TEventID scm_nEventREQID = 1;
    static const TForteInt16 scm_anEIWithIndexes[];
    static const CStringDictionary::TStringId scm_anEventInputNames[];

    static const TEventID scm_nEventINITOID = 0;
    static const TEventID scm_nEventCNFID = 1;
    static const TForteInt16 scm_anEOWithIndexes[];
    static const TDataIOID scm_anEOWith[];
    static const CStringDictionary::TStringId scm_anEventOutputNames[];

    void executeEvent(int pa_nEIID);

  public:
    GEN_CSV_WRITER(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes);
    virtual ~GEN_CSV_WRITER();

    virtual bool configureFB(const char *pa_acConfigString);

    CStringDictionary::TStringId getFBTypeId(void) const{
      return m_nConfiguredFBTypeNameId;
    }

  private:
    void openCSVFile();
    void closeCSVFile();
    void writeCSVFileLine();

    FILE *m_pstCSVFile;

    CStringDictionary::TStringId *m_anDataInputNames;
    CStringDictionary::TStringId *m_anDataInputTypeIds;

    TDataIOID *m_anEIWith;

    CStringDictionary::TStringId m_nConfiguredFBTypeNameId;

};

#endif //close the ifdef sequence from the beginning of the file

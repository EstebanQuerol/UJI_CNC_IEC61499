/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: EMB_RMT_RES
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     0.0: 2010-01-20/4DIAC-IDE - 4DIAC-Consortium -
 *************************************************************************/
#ifndef _EMB_RMT_RES_H_
#define _EMB_RMT_RES_H_

#include <resource.h>
#include <class1objhand.h>

class EMB_RMT_RES : public CResource{
  //DECLARE_FIRMWARE_FB(EMB_RMT_RES)

  public:
    EMB_RMT_RES(CStringDictionary::TStringId pa_nInstanceNameId, CResource* pa_roDevice, const char * pa_acId);

    virtual ~EMB_RMT_RES();

    virtual CStringDictionary::TStringId getFBTypeId(void) const;

  private:
    static const SFBInterfaceSpec scm_stRESInterfaceSpec;
};

#endif //close the ifdef sequence from the beginning of the file

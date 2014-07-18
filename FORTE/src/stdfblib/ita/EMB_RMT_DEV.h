/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V0.4!
 ***
 *** Name: EMB_RMT_DEV
 *** Description: Service Interface Function Block Type
 *** Version:
 ***     0.0: 2010-01-20/4DIAC-IDE - 4DIAC-Consortium -
 *************************************************************************/
#ifndef _LMS_DEV_H_
#define _LMS_DEV_H_

#include <device.h>
#include "EMB_RMT_RES.h"
#include <class1objhand.h>

class EMB_RMT_DEV : public CDevice{


public:
  EMB_RMT_RES MGR;

  EMB_RMT_DEV(const char * pa_acId);
  virtual ~EMB_RMT_DEV();

/*! \brief Adds additional functionality to the originals execute func of the device.
 *
 * This is that it waits till the thread of the MGR resource has anded
 */
  virtual int startDevice(void);

  virtual EMGMResponse changeFBExecutionState(EMGMCommandType pa_unCommand);

private:

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

};

#endif /*EMB_RMT_DEV_H_*/

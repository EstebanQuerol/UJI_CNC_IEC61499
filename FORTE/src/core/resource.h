/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include "ecet.h"
#include "funcbloc.h"
#include "class1objhand.h"

class CDevice;

/*! \ingroup CORE\brief Base class for all resources handling the reconfiguration management within this
 * resource and the background execution of event chains.
 */
class CResource : public CFunctionBlock{

  public:
    CSyncObject m_oResDataConSync;
    /*! \brief The main constructor for a resource.
     *
     * The resource can only be generated with a given device the resource is contained. A resource can not exist outside of an device.
     *  \param pa_poDevice           the device the resource is contained in
     *  \param pa_pstInterfaceSpec   interface-specification of resource
     *  \param pa_nInstanceNameId    StringId of instance-name
     *  \param pa_roObjectHandler    reference to object handler
     *  \param pa_acFBData           Byte-array for resource-specific data
     */
    CResource(CResource* pa_poDevice, const SFBInterfaceSpec *pa_pstInterfaceSpec, const CStringDictionary::TStringId pa_nInstanceNameId,
        TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData);

    virtual ~CResource(){
      delete m_poResourceEventExecution;
    }
    ;

    /*! \brief Returns the pointer to the objecthandler
     *
     * \return Pointer to the objecthandler
     */
    C61499Class1ObjectHandler &getObjectHandler(){
      return m_oObjectHandler;
    }

    /*! \brief Get the device the resource is contained in
     */
    CDevice &getDevice(void){
      return (CDevice &)getResource();
    }
    ;

    CEventChainExecutionThread *getResourceEventExecution(void){
      return m_poResourceEventExecution;
    }
    ;

    virtual EMGMResponse changeFBExecutionState(EMGMCommandType pa_unCommand);

  protected:
    CResource(const SFBInterfaceSpec *pa_pstInterfaceSpec, const CStringDictionary::TStringId pa_nInstanceNameId,
              TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData);

    /*! \brief The objecthandler of the resource
     */
    C61499Class1ObjectHandler m_oObjectHandler;

    virtual void executeEvent(int){
    }
    ;

  private:
    /*!\brief The event chain execution of background (low priority) event chains started within this resource
     */
    CEventChainExecutionThread *m_poResourceEventExecution;

};

#endif /*RESOURCE_H_*/

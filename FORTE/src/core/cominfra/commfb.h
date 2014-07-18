/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _COMMFB_H_
#define _COMMFB_H_

#include <config.h>
#include "../esfb.h"
#include "../datatypes/forte_bool.h"
#ifdef FORTE_USE_WSTRING_DATATYPE
#include "../datatypes/forte_wstring.h"
#else
#include "../datatypes/forte_string.h"
#endif
#include "comtypes.h"

namespace forte {
  namespace com_infra {

    class CComLayer;
    class IComCallback;

    class CCommFB : public CEventSourceFB{
      public:
        virtual ~CCommFB();

        /*!\brief The getFBType method is used by the Query command to get the instances correct type name (eg. "CLIENT_3_2")
         * \return pointer to typename string
         */
        CStringDictionary::TStringId getFBTypeId(void) const{
          return m_nConfiguredFBTypeNameId;
        }

        forte::com_infra::EComServiceType getComServiceType() const{
          return m_eCommServiceType;
        }

        unsigned int getNumSD() const{
          return m_pstInterfaceSpec->m_nNumDIs - 2;
        }

        unsigned int getNumRD() const{
          return m_pstInterfaceSpec->m_nNumDOs - 2;
        }

        CIEC_ANY *getSDs(){
          return getDI(2);
        }

        CIEC_ANY *getRDs(){
          return getDO(2);
        }

        void interruptCommFB(IComCallback *pa_poComLayer);

        CIEC_BOOL& QI() {
        	return *static_cast<CIEC_BOOL*>(getDI(0));
        }

#ifdef FORTE_USE_WSTRING_DATATYPE
        CIEC_WSTRING& ID() {
        	return *static_cast<CIEC_WSTRING*>(getDI(1));
        }

        CIEC_WSTRING& STATUS() {
	        return *static_cast<CIEC_WSTRING*>(getDO(1));
        }
#else
        //TODO after fixing discussion on the new compliance profile fix these values to STRING
        CIEC_STRING& ID() {
          return *static_cast<CIEC_STRING*>(getDI(1));
        }

        CIEC_STRING& STATUS() {
          return *static_cast<CIEC_STRING*>(getDO(1));
        }
#endif

        CIEC_BOOL& QO() {
	        return *static_cast<CIEC_BOOL*>(getDO(0));
        }

      protected:
        CCommFB(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes, forte::com_infra::EComServiceType pa_eCommServiceType);

        CCommFB(const CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes, const SFBInterfaceSpec *pa_pstInterfaceSpec,
            TForteByte *pa_acFBConnData, TForteByte *pa_acFBVarsData, forte::com_infra::EComServiceType pa_eCommServiceType);

        /*!\brief The configureFB method is used by the typelib to parametrize the number of inputs/outputs
         * \param pa_acConfigString : the string containing the requested typename (eg. "CLIENT_3_2"
         */
        bool configureFB(const char *pa_acConfigString);

        void executeEvent(int pa_nEIID);

        static const TEventID scm_nEventINITID = 0;
        static const TEventID scm_nEventINITOID = 0;
        static const TEventID scm_nSendNotificationEventID = 1;
        static const TEventID scm_nReceiveNotificationEventID = 1;

        static const unsigned int scm_QI_ID = 0; //Input ID 0 for QI Input
        static const unsigned int scm_QO_ID = 0; //Output ID 0 for QO Output
        static const unsigned int scm_ID_ID = 1; //Input ID 1 for ID Input
        static const unsigned int scm_STATUS_ID = 1; //Output ID 1 for STATUS Output


        CStringDictionary::TStringId m_nConfiguredFBTypeNameId;

      private:
        static const CStringDictionary::TStringId scm_aunRequesterEventInputNameIds[];
        static const CStringDictionary::TStringId scm_aunRequesterEventOutputNameIds[];

        static const CStringDictionary::TStringId scm_aunResponderEventInputNameIds[];
        static const CStringDictionary::TStringId scm_aunResponderEventOutputNameIds[];

        static const TForteInt16 scm_anEIWithIndexes[];
        static const TForteInt16 scm_anEOWithIndexes[];

        static const char * const scm_sResponseTexts[];

        EComResponse openConnection();
        void closeConnection();
        EComResponse receiveData();
        /*! If the ID string does not contain [] indicating that there is a layer setup given this Function is called to
         *  to generate an default layer configuration. This function may be overwriten by special Comfbs to provide their
         *  own default layer config. See for example GEN_PUBL or GEN_SUBL.
         * @return id with layer configuration
         */
        virtual char * getDefaultIDString();

        forte::com_infra::EComServiceType m_eCommServiceType;
        forte::com_infra::CComLayer *m_poTopOfComStack;
        unsigned int m_unComInterruptQueueCount; //!< number of triggers pending from the network
        IComCallback *m_apoInterruptQueue[cg_unCommunicationInterruptQueueSize];
    };

  }
}

#endif //_COMMFB_H_

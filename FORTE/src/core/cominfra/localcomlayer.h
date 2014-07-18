/*******************************************************************************
 * Copyright (c) 2007 - 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef LOCALCOMLAYER_H_
#define LOCALCOMLAYER_H_

#include "comlayer.h"
#include "comcallback.h"
#include "commfb.h"
#include "../stringdict.h"
#include "../fortelist.h"
#include <sync.h>

namespace forte {

  namespace com_infra {

    class CLocalComLayer : public CComLayer, public IComCallback{

      public:
        static char *getDefaultLocalCommIdString(const char *pa_acIdValue);

        CLocalComLayer(CComLayer* pa_poUpperLayer, CCommFB * pa_poFB);
        virtual ~CLocalComLayer();

        virtual void closeConnection();
        virtual EComResponse sendData(void *pa_pvData, unsigned int pa_unSize);
        virtual EComResponse recvData(const void *, unsigned int ){
          return e_ProcessDataOk;
        }

        virtual CEventSourceFB *onComEvent(){
          return m_poFb;
        }

        virtual EComResponse processComEvent(){
          return e_ProcessDataOk;
        }

      protected:
      private:
        virtual EComResponse openConnection(char *pa_acLayerParameter);
        void setRDs(CLocalComLayer *pa_poSublLayer, CIEC_ANY *pa_aSDs, unsigned int pa_unNumSDs);

        struct SLocalCommGroup{

            SLocalCommGroup(CStringDictionary::TStringId pa_nGroupName) :
            m_nGroupName(pa_nGroupName), m_lPublList(), m_lSublList(){
            }

            SLocalCommGroup(const SLocalCommGroup& pa_roLocalCommGroup) :
            m_nGroupName(pa_roLocalCommGroup.m_nGroupName), m_lPublList(), m_lSublList(){
            }

            ~SLocalCommGroup(){
            }

            CStringDictionary::TStringId m_nGroupName;
            CSinglyLinkedList<CLocalComLayer*> m_lPublList;
            CSinglyLinkedList<CLocalComLayer*> m_lSublList;
        };

        class CLocalCommGroupsManager{

          public:

            SLocalCommGroup* registerPubl(const CStringDictionary::TStringId pa_nID, CLocalComLayer *pa_poLayer);
            void unregisterPubl(SLocalCommGroup *pa_poGroup, CLocalComLayer *pa_poLayer);

            SLocalCommGroup* registerSubl(const CStringDictionary::TStringId pa_nID, CLocalComLayer *pa_poLayer);
            void unregisterSubl(SLocalCommGroup *pa_poGroup, CLocalComLayer *pa_poLayer);

          protected:
          private:
            CLocalCommGroupsManager(){};

            SLocalCommGroup* findLocalCommGroup(CStringDictionary::TStringId pa_nID);
            SLocalCommGroup* createLocalCommGroup(CStringDictionary::TStringId pa_nID);
            void removeCommGroup(SLocalCommGroup *pa_poGroup);

            static void removeListEntry(CSinglyLinkedList<CLocalComLayer*>  &pa_rlstList, CLocalComLayer *pa_poLayer);

            /*!\brief The Sync object used locking the access to the internal used datastructures
             */
            CSyncObject m_oSync;

            CSinglyLinkedList<SLocalCommGroup> m_lstLocalCommGroups;

            friend class CLocalComLayer;

            //not to be implemented
            CLocalCommGroupsManager(const CLocalCommGroupsManager &);
            CLocalCommGroupsManager &operator =(const CLocalCommGroupsManager&);
        };

        static CLocalCommGroupsManager sm_oLocalCommGroupsManager;


        SLocalCommGroup *m_poLocalCommGroup;
    };
  }

}

#endif /* LOCALCOMLAYER_H_ */

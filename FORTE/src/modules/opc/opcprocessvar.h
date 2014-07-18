/*******************************************************************************
 * Copyright (c) 2007 - 2010 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/

#ifndef OPCPROCESSVAR_H_
#define OPCPROCESSVAR_H_

#include "windows.h"
#include "Variant.h"
#include "fortelist.h"
#include "sync.h"

class COPCItem;

class COpcProcessVar{
  public:
    enum EOpcProcessVarFunctions{
      e_FBInput, e_FBOutput
    };

    COpcProcessVar(const char* pa_acItemGroupName, const char* pa_acItemName, EOpcProcessVarFunctions pa_eFunction);
    ~COpcProcessVar(){
    }

    const char* getItemName() const {
      return m_acItemName;
    }
    const char* getItemGroupName() const {
      return m_acItemGroupName;
    }
    EOpcProcessVarFunctions getItemFunction() const {
      return m_eFunction;
    }

    void setOpcItem(COPCItem* pa_pOpcItem){
      m_pOpcItem = pa_pOpcItem;
    }

    void sendItemData();

    void setNewValue(Variant pa_oNewValue);
    Variant peekNewValue();

    Variant updateValue();

    bool getIsActive() const {
      return m_bActive;
    }

    void setIsActive(bool pa_bActive){
      m_bActive = pa_bActive;
    }

  private:
    COPCItem* m_pOpcItem;

    const char* m_acItemGroupName;
    const char* m_acItemName;
	  bool m_bActive;

    Variant m_oCurrentValue;

    typedef CSinglyLinkedList<Variant> TVariantList;
    TVariantList m_lNewValueQueue;

    Variant m_oNewValue;

    CSyncObject m_oSync;

    EOpcProcessVarFunctions m_eFunction;

};

#endif // OPCPROCESSVAR_H_

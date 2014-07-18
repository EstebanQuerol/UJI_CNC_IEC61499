/*******************************************************************************
 * Copyright (c) 2007 - 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef ANYELEMHELPER_H_
#define ANYELEMHELPER_H_

#include <forte_real.h>
#include <forte_lreal.h>
#include <forte_lint.h>
#include <forte_dint.h>

template<class T>
void anyBitFBHelper(CIEC_ANY::EDataTypeID pa_eDataTypeId, T &pa_roFB){
  switch (pa_eDataTypeId){
    case CIEC_ANY::e_BOOL:
      pa_roFB.template calculateValue<CIEC_BOOL>();
      break;
    case CIEC_ANY::e_BYTE:
      pa_roFB.template calculateValue<CIEC_BYTE>();
      break;
    case CIEC_ANY::e_WORD:
      pa_roFB.template calculateValue<CIEC_WORD>();
      break;
    #ifdef FORTE_USE_64BIT_DATATYPES
      case  CIEC_ANY::e_LWORD:
        pa_roFB.template calculateValue<CIEC_LWORD>();
        break;
    #endif
    default:
      pa_roFB.template calculateValue<CIEC_DWORD>();
      break;
  }
}

template<class T>
void anyMagnitudeFBHelper(CIEC_ANY::EDataTypeID pa_eDataTypeId, T &pa_roFB){
  switch (pa_eDataTypeId){
    case CIEC_ANY::e_REAL:
      #ifdef FORTE_USE_REAL_DATATYPE
        pa_roFB.template calculateValue<CIEC_REAL>();
      #endif
      break;
    case CIEC_ANY::e_LREAL:
      #ifdef FORTE_USE_REAL_DATATYPE
        #ifdef FORTE_USE_64BIT_DATATYPES
          pa_roFB.template calculateValue<CIEC_LREAL>();
        #endif
      #endif
      break;
    default:
      if(pa_eDataTypeId <= CIEC_ANY::e_TIME){
        #ifdef FORTE_USE_64BIT_DATATYPES
          pa_roFB.template calculateValue<CIEC_LINT>();
        #else
          pa_roFB.template calculateValue<CIEC_DINT>();
        #endif
      }
      break;
  }
}

template<class T>
void anyIntFBHelper(CIEC_ANY::EDataTypeID pa_eDataTypeId, T &pa_roFB){
  switch (pa_eDataTypeId){
    case CIEC_ANY::e_SINT:
    	pa_roFB.template calculateValue<CIEC_SINT>();
    	break;
    case CIEC_ANY::e_DINT:
    	pa_roFB.template calculateValue<CIEC_DINT>();
    	break;
    #ifdef FORTE_USE_64BIT_DATATYPES
    case CIEC_ANY::e_LINT:
    	pa_roFB.template calculateValue<CIEC_LINT>();
    	break;
    case CIEC_ANY::e_ULINT:
		pa_roFB.template calculateValue<CIEC_ULINT>();
		break;
    #endif
    case CIEC_ANY::e_UINT:
    	pa_roFB.template calculateValue<CIEC_UINT>();
    	break;
    case CIEC_ANY::e_USINT:
        pa_roFB.template calculateValue<CIEC_USINT>();
        break;
    case CIEC_ANY::e_UDINT:
      pa_roFB.template calculateValue<CIEC_UDINT>();
      break;
    default:
    	pa_roFB.template calculateValue<CIEC_INT>();
    	break;
  }
}

template<class T>
void anyRealFBHelper(CIEC_ANY::EDataTypeID pa_eDataTypeId, T &pa_roFB){
  switch (pa_eDataTypeId){
    case CIEC_ANY::e_REAL:
      #ifdef FORTE_USE_REAL_DATATYPE
        pa_roFB.template calculateValue<CIEC_REAL>();
      #endif
      break;
    case CIEC_ANY::e_LREAL:
      #ifdef FORTE_USE_LREAL_DATATYPE
        pa_roFB.template calculateValue<CIEC_LREAL>();
      #endif
      break;
    default:
      break;
  }
}

template<class T>
void anyNumFBHelper(CIEC_ANY::EDataTypeID pa_eDataTypeId, T &pa_roFB){
    if(CIEC_ANY::e_LREAL == pa_eDataTypeId || CIEC_ANY::e_REAL == pa_eDataTypeId){
      anyRealFBHelper(pa_eDataTypeId, pa_roFB);
    }else{
      anyIntFBHelper(pa_eDataTypeId, pa_roFB);
    }
}

template<class T>
void anyElementaryFBHelper(CIEC_ANY::EDataTypeID pa_eDataTypeId, T &pa_roFB){
  if(CIEC_STRING::e_STRING == pa_eDataTypeId){
     pa_roFB.template calculateValueString<CIEC_STRING>();
  }
#ifdef FORTE_USE_WSTRING_DATATYPE
  else  if(CIEC_WSTRING::e_WSTRING == pa_eDataTypeId){
      pa_roFB.template calculateValueString<CIEC_WSTRING>();
  }
#endif
  else{
    anyMagnitudeFBHelper(pa_eDataTypeId, pa_roFB);
  }
}

template<class T>
void anyStringFBHelper(CIEC_ANY::EDataTypeID pa_eDataTypeId, T &pa_roFB){
  if(CIEC_STRING::e_STRING == pa_eDataTypeId){
     pa_roFB.template calculateValueString<CIEC_STRING>();
  }
#ifdef FORTE_USE_WSTRING_DATATYPE
  else  if(CIEC_WSTRING::e_WSTRING == pa_eDataTypeId){
      pa_roFB.template calculateValueString<CIEC_WSTRING>();
  }
#endif
}

#endif /* ANYELEMHELPER_H_ */

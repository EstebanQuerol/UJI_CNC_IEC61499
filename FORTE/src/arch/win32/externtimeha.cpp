/*******************************************************************************
 * Copyright (c) 2007 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "externtimeha.h"
#include "../../core/devexec.h"
//#include <time.h>
#include <windows.h>


const TForteInt32 CExternTimerHandler::csm_nTicksPerSecond = 1000;

extern "C" __declspec(dllexport) 
void __stdcall nextTick(void){
	CExternTimerHandler::externNextTick();
}

extern "C" __declspec(dllexport) 
unsigned int __stdcall getTicksPerSecond(){
	return CExternTimerHandler::getExternTicksPerSecond();
}

void CTimerHandler::createTimerHandler(void){
  if(0 == sm_poFORTETimer)
    sm_poFORTETimer = new CExternTimerHandler();

}

CExternTimerHandler::CExternTimerHandler(){
}

CExternTimerHandler::~CExternTimerHandler(){
  disableHandler();
}

void CExternTimerHandler::externNextTick(){
  if(0 != sm_poFORTETimer){
	  sm_poFORTETimer->nextTick();
  }
}


void CExternTimerHandler::enableHandler(void){
	//TODO think on hwo to handle this.
}

void CExternTimerHandler::disableHandler(void){
	//TODO think on hwo to handle this.
}

void CExternTimerHandler::setPriority(int pa_nPriority){
  //TODO think on hwo to handle this.
}

int CExternTimerHandler::getPriority(void) const{
  //TODO think on hwo to handle this.
  return 1;
}

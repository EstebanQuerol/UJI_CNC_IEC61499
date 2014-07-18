/*******************************************************************************
 * Copyright (c) 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#include "fbtester.h"
#include "stringdict.h"
#include <stdio.h>
#include <algorithm>
#include <ecet.h>

#ifdef WIN32
	#include <windows.h>
	#define usleep(x) Sleep((x)/1000)
#else
	#include <unistd.h>
#endif

/**Helper functor for deleting stuf in containers
 *
 */
struct SDeleteFunctor{
   template<class T>
    void operator()(T* paVal) const{
      delete paVal;
    }
};

CFBTester::CFBTester(CResource *pa_poTestResource) :
    CFunctionBlock(pa_poTestResource, 0, 0, 0, 0),
    mFBUnderTest(0),
    m_nNumSuccesfulTestCases(0), m_nNumUnsuccesfulTestCases(
        0){

  changeFBExecutionState(cg_nMGM_CMD_Start);
}

CFBTester::~CFBTester(){
}

void CFBTester::executeTests(){
  printf("*****************************************************\n");
  printf("*** Testing FB: %s\n",
      CStringDictionary::getInstance().get(getFBTypeId()));
  printf("*** \n");

  if(prepareTests()){
    evaluateTestResult(testCaseWrongInputEvent(), "Wrong Input Event");
    executeAllTests();
  }
  cleanupTestData();

  printf("***\n");
  printf("*** Test Summary:\n");
  printf("*** Executed %d test cases (%d successful, %d unsuccessful)\n",
      m_nNumSuccesfulTestCases + m_nNumUnsuccesfulTestCases,
      m_nNumSuccesfulTestCases, m_nNumUnsuccesfulTestCases);
  printf("*****************************************************\n");

}

bool CFBTester::prepareTests(){
  bool retVal = false;

  m_nNumSuccesfulTestCases = 0;
  m_nNumUnsuccesfulTestCases = 0;

  performCreationTest();

  if(0 != mFBUnderTest){
    mFBUnderTest->changeFBExecutionState(cg_nMGM_CMD_Start);

    createEventOutputConnections();
    if(createDataInputConnections()){
      if(createDataOutputConnections()){
        retVal = true;
      }
    }
    if(false == retVal){
      //Inform test runner that we had an issue
      m_nNumUnsuccesfulTestCases++;
    }
  }

  return retVal;
}

void CFBTester::cleanupTestData(){
  const SFBInterfaceSpec* interfaceSpec = mFBUnderTest->getFBInterfaceSpec();

  for(std::vector<CEventConnection>::size_type i = 0; i < mEOConnections.size(); ++i){
    mEOConnections[i]->disconnect(CConnection::genConPortId(this->getInstanceNameId(), interfaceSpec->m_aunEONames[i]),
        *mFBUnderTest, *this);
    delete mEOConnections[i];
  }

  for_each(mDIConnections.begin(), mDIConnections.end(), SDeleteFunctor());
  for_each(mDOConnections.begin(), mDOConnections.end(), SDeleteFunctor());

  performFBDeleteTests();
}

void CFBTester::performFBDeleteTests(){
  bool bTestResult = true;

  if(0 != mFBUnderTest){
    if(mFBUnderTest->isCurrentlyDeleteable()){
      bTestResult = false;
    }

    if(e_RDY != mFBUnderTest->changeFBExecutionState(cg_nMGM_CMD_Stop)){
      bTestResult = false;
    }

    if(!mFBUnderTest->isCurrentlyDeleteable()){
      bTestResult = false;
    }

    if(!CTypeLib::deleteFB(mFBUnderTest)){
      bTestResult = false;
    }
  }else{
    bTestResult = false;
  }

  mFBUnderTest = 0;

  evaluateTestResult(bTestResult, "Type deletion");
}

void CFBTester::executeEvent(int pa_nEIID){
  mOutputEventLock.lock();
  mFBOutputEvents.push_back(pa_nEIID);
  mOutputEventLock.unlock();
}

void CFBTester::triggerEvent(int pa_nEIId){
  CEventChainExecutionThread *execThread = getResource().getResourceEventExecution();
  SEventEntry entry(mFBUnderTest, pa_nEIId);

  execThread->startEventChain(&entry);

  //Wait till event execution for this input event has finished
  do{
     usleep(1000); //TODO tune this value
  }while(!execThread->isSelfSuspended());

}

void CFBTester::performCreationTest(){
  bool bTestResult = true;

  mFBUnderTest = CTypeLib::createFB(getFBTypeId(), getFBTypeId(), getResourcePtr());

  if(0 == mFBUnderTest){
    bTestResult = false;
  }else {
    if((getFBTypeId() != mFBUnderTest->getFBTypeId()) && (getFBTypeId() != mFBUnderTest->getInstanceNameId())){
      bTestResult = false;
    } else{

      const SFBInterfaceSpec* interfaceSpec = mFBUnderTest->getFBInterfaceSpec();

      SFBInterfaceSpec* testerInterfaceSpec = new SFBInterfaceSpec;
      testerInterfaceSpec->m_nNumEIs = interfaceSpec->m_nNumEOs;
      testerInterfaceSpec->m_aunEINames = interfaceSpec->m_aunEONames;
      testerInterfaceSpec->m_anEIWith = 0;
      testerInterfaceSpec->m_anEIWithIndexes = 0;
      testerInterfaceSpec->m_nNumEOs = 0;
      testerInterfaceSpec->m_aunEONames = 0;
      testerInterfaceSpec->m_anEOWith = 0;
      testerInterfaceSpec->m_anEOWithIndexes = 0;
      testerInterfaceSpec->m_nNumDIs = 0;
      testerInterfaceSpec->m_aunDINames = 0;
      testerInterfaceSpec->m_aunDIDataTypeNames = 0;
      testerInterfaceSpec->m_nNumDOs = 0;
      testerInterfaceSpec->m_aunDONames = 0;
      testerInterfaceSpec->m_aunDODataTypeNames = 0;
      testerInterfaceSpec->m_nNumAdapters = 0;
      testerInterfaceSpec->m_pstAdapterInstanceDefinition = 0;

      setupFBInterface(testerInterfaceSpec, 0, 0, true);
    }
  }

  evaluateTestResult(bTestResult, "Type creation");
}

void CFBTester::evaluateTestResult(bool pa_bSuccess,
    const char* pa_acTestCaseName){
  if(pa_bSuccess){
    ++m_nNumSuccesfulTestCases;
  }
  else{
    ++m_nNumUnsuccesfulTestCases;
  }

  printf("*** Test case: %s: %s\n", pa_acTestCaseName,
      (pa_bSuccess) ? "ok" : "error");
}

int CFBTester::pullFirstChainEventID(){
  mOutputEventLock.lock();
  int retVal = mFBOutputEvents.front();
  mFBOutputEvents.pop_front();
  mOutputEventLock.unlock();
  return retVal;
}

bool CFBTester::eventChainEmpty(){
  mOutputEventLock.lock();
  bool retVal = mFBOutputEvents.empty();
  mOutputEventLock.unlock();
  return retVal;
}

bool CFBTester::checkForSingleOutputEventOccurence(int pa_nExpectedEOId){
  bool bResult = (pullFirstChainEventID() == pa_nExpectedEOId);

  //Test if event chain is empty
  if(!eventChainEmpty()){
    bResult = false;
  }

  return bResult;
}

void CFBTester::setInputData(TIEC_ANYPtr paInputData[], size_t paLenght){
  mInputDataBuffers.reserve(paLenght);
  mInputDataBuffers.assign(paInputData, paInputData + paLenght);
}

void CFBTester::setOutputData(TIEC_ANYPtr paOutputData[], size_t paLenght){
  mOutputDataBuffers.reserve(paLenght);
  mOutputDataBuffers.assign(paOutputData, paOutputData + paLenght);
}


void CFBTester::createEventOutputConnections(){
  const SFBInterfaceSpec* interfaceSpec = mFBUnderTest->getFBInterfaceSpec();

  for(unsigned int i = 0; i < interfaceSpec->m_nNumEOs; i++){
    mEOConnections.push_back(
        new CEventConnection(CConnection::genConPortId(mFBUnderTest->getInstanceNameId(), interfaceSpec->m_aunEONames[i]),  *mFBUnderTest,
            CConnection::genConPortId(this->getInstanceNameId(), interfaceSpec->m_aunEONames[i]), *this));
  }
}

bool CFBTester::createDataInputConnections(){
  bool retVal = true;

  const SFBInterfaceSpec* interfaceSpec = mFBUnderTest->getFBInterfaceSpec();

  if(interfaceSpec->m_nNumDIs == mInputDataBuffers.size()){
    for(unsigned int i = 0; i < interfaceSpec->m_nNumDIs; ++i){
      if(CFBTestDIConn::canBeConnected(mInputDataBuffers[i],
          mFBUnderTest->getDataInput(
              interfaceSpec->m_aunDINames[i]))){
        mDIConnections.push_back(new CFBTestDIConn(*mFBUnderTest, interfaceSpec->m_aunDINames[i], mInputDataBuffers[i]));
      }
      else{
        printf(
            "*** FB test preparation: Given input data value for input %s can not be connected!\n",
            CStringDictionary::getInstance().get(
                interfaceSpec->m_aunDINames[i]));
        retVal = false;
        break;
      }
    }
  }
  else{
    printf(
        "*** FB test preparation: Wrong amount of input data given! Expected: %d, got: %lu\n",
        interfaceSpec->m_nNumDIs, mInputDataBuffers.size());
    retVal = false;
  }

  return retVal;
}

bool CFBTester::createDataOutputConnections(){
  bool retVal = true;

  const SFBInterfaceSpec* interfaceSpec = mFBUnderTest->getFBInterfaceSpec();

  if(interfaceSpec->m_nNumDOs == mOutputDataBuffers.size()){
    for(unsigned int i = 0; i < interfaceSpec->m_nNumDOs; ++i){
      if(CFBTestDIConn::canBeConnected(mOutputDataBuffers[i],
          mFBUnderTest->getDataOutput(
              interfaceSpec->m_aunDONames[i]))){
        mDOConnections.push_back(new CFBTestDOConn(*mFBUnderTest, interfaceSpec->m_aunDONames[i], mOutputDataBuffers[i]));
      }
      else{
        printf(
            "*** FB test preparation: Given output data value for input %s can not be connected!\n",
            CStringDictionary::getInstance().get(
                interfaceSpec->m_aunDONames[i]));
        retVal = false;
        break;
      }
    }
  }
  else{
    printf(
        "*** FB test preparation: Wrong amount of output data given! Expected: %d, got: %lu\n",
        interfaceSpec->m_nNumDOs, mOutputDataBuffers.size());
    retVal = false;
  }

  return retVal;

}

bool CFBTester::testCaseWrongInputEvent(){
  bool bResult = true;

  for(int i = mFBUnderTest->getFBInterfaceSpec()->m_nNumEIs; i < 2000; i++){
    if(cg_nExternalEventID != i){
      triggerEvent(i);
      if(!eventChainEmpty()){
        bResult = false;
        break;
      }
    }
  }

  return bResult;
}

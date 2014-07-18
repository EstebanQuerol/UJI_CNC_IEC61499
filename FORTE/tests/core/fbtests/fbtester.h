/*******************************************************************************
 * Copyright (c) 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef FBTESTER_H_
#define FBTESTER_H_

#include "funcbloc.h"
#include "fbtestdoconn.h"
#include "fbtestdiconn.h"
#include "fbtestsmanager.h"
#include <vector>
#include <deque>


#define SETUP_INPUTDATA(...)                                                \
  {                                                                         \
    TIEC_ANYPtr inputData[] = {__VA_ARGS__};                                \
    setInputData(inputData, (sizeof(inputData) / sizeof(inputData[0])) );   \
  }                                                                         \


#define SETUP_OUTPUTDATA(...)                                                \
  {                                                                          \
    TIEC_ANYPtr outputData[] = {__VA_ARGS__};                                \
    setOutputData(outputData, (sizeof(outputData) / sizeof(outputData[0])) ); \
  }                                                                          \


class CFBTester : public CFunctionBlock{
  public:
    virtual ~CFBTester();

    //!execute the test cases for the FB and generate a test report
    void executeTests();

    unsigned int getNumSuccesfullTestCases(){
      return m_nNumSuccesfulTestCases;
    }

    unsigned int getNumUnsuccesfullTestCases(){
      return m_nNumUnsuccesfulTestCases;
    }

  protected:
    CFBTester(CResource *pa_poTestResource);

    /*!\brief invoke the FB under Test with the given event id
     *
     * @param pa_nEIId input event id to be sent to the fb under test
     */
    void triggerEvent(int pa_nEIId);

    /*!\brief report the status of a test case
     *
     * This function should be invoked for each test case executed within
     * executeAllTests().
     *
     * @param pa_bSuccess true if the test case was successful
     * @param pa_acTestCaseName name of the test case
     */
    void evaluateTestResult(bool pa_bSuccess, const char* pa_acTestCaseName);

    int pullFirstChainEventID();

    bool eventChainEmpty();

    /** Check if only one output event of the given event output Id has been sent by the FB
     *
     * @param pa_nExpectedEOId the output event Id to be checked for
     * @return true if only one event of the given Id is in the event queue
     */
    bool checkForSingleOutputEventOccurence(int pa_nExpectedEOId);

    void setInputData(TIEC_ANYPtr paInputData[], size_t paLenght);
    void setOutputData(TIEC_ANYPtr paInputData[], size_t paLenght);

  private:
    virtual void executeEvent(int pa_nEIID);
    /*!\brief attempt to create the type from the type library
     *
     */
    void performCreationTest();

    /*! \brief execute all tests cases of the FB
     *
     *  This function needs to be implemented by the specific test class of
     *  a FB. each test cases has to report its results by invoking
     *  evaluateTestResult(bool pa_bSuccess, const char* pa_acTestCaseName)
     */
    virtual void executeAllTests() = 0;

    /*! Prepare internal variables and the testee for the test
     *
     */
    bool prepareTests();
    void cleanupTestData();
    void performFBDeleteTests();
    void createEventOutputConnections();
    bool createDataInputConnections();
    bool createDataOutputConnections();

    bool testCaseWrongInputEvent();


    std::vector<CIEC_ANY *> mInputDataBuffers;
    std::vector<CIEC_ANY *> mOutputDataBuffers;


    CFunctionBlock *mFBUnderTest;
    std::vector<CEventConnection *> mEOConnections;
    std::vector<CFBTestDIConn *> mDIConnections;
    std::vector<CFBTestDOConn *> mDOConnections;

    /*! \brief list for storing the output events received from the testee
     *
     * TODO add timestamps to the list
     */
    std::deque<int> mFBOutputEvents;

    CSyncObject mOutputEventLock;

    unsigned int m_nNumSuccesfulTestCases;
    unsigned int m_nNumUnsuccesfulTestCases;

};

#endif /* FBTESTER_H_ */

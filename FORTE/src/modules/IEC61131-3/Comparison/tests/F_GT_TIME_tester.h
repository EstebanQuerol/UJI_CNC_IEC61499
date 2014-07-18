/*******************************************************************************
 * Copyright (c) 2011 4DIAC - consortium.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *******************************************************************************/
#ifndef _E_SR_TESTER_H_
#define _E_SR_TESTER_H_

#include "fbtester.h"
#include <forte_time.h>
#include "../F_GT.h"

/***********************************************************************************/
/***********************************************************************************/

class F_GT_TIME_tester  : public CFBTester{
    DECLARE_FB_TESTER(F_GT_TIME_tester);

  public:
    F_GT_TIME_tester(CResource *m_poTestResource);

  private:
    virtual void executeAllTests();

    bool testCase_GTual();
    bool testCase_Larger();
    bool testCase_Smaller();

    FORTE_F_GT m_oTestee;

    CFBTestEOConn m_poOut_EO_Conn;

    CIEC_TIME m_oIN1;
    CFBTestDIConn m_oIn_IN1_Conn;
    CIEC_TIME m_oIN2;
    CFBTestDIConn m_oIn_IN2_Conn;
    CIEC_BOOL m_oOut_OUT; //DATA OUTPUT
    CFBTestDOConn m_oOut_OUT_Conn; //DATA OUTPUT

};

/***********************************************************************************/
/***********************************************************************************/

#endif /* _E_SR_TESTER_H_ */ 

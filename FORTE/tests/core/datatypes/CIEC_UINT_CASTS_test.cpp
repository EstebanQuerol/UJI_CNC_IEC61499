
#include <boost/test/unit_test.hpp>

#ifdef FORTE_USE_REAL_DATATYPE
  #include <boost/test/floating_point_comparison.hpp>

  #include "../../../src/core/datatypes/forte_real.h"
#endif //FORTE_USE_REAL_DATATYPE

//BOOLEAN
#include "../../../src/core/datatypes/forte_bool.h"
//BIT-Datatypes
#include "../../../src/core/datatypes/forte_byte.h"
#include "../../../src/core/datatypes/forte_word.h"
#include "../../../src/core/datatypes/forte_dword.h"
//INT-Datatypes
#include "../../../src/core/datatypes/forte_sint.h"
#include "../../../src/core/datatypes/forte_usint.h"
#include "../../../src/core/datatypes/forte_int.h"
#include "../../../src/core/datatypes/forte_uint.h"
#include "../../../src/core/datatypes/forte_dint.h"
#include "../../../src/core/datatypes/forte_udint.h"
//STRING-Datatypes
#include "../../../src/core/datatypes/forte_string.h"
#include "../../../src/core/datatypes/forte_wstring.h"
//TIME
#include "../../../src/core/datatypes/forte_time.h"


#ifdef FORTE_USE_64BIT_DATATYPES
  #include "../../../src/core/datatypes/forte_lword.h"
  #include "../../../src/core/datatypes/forte_lint.h"
  #include "../../../src/core/datatypes/forte_ulint.h"

#ifdef FORTE_USE_REAL_DATATYPE
  #include "../../../src/core/datatypes/forte_lreal.h"
#endif //FORTE_USE_REAL_DATATYPE
#endif //FORTE_USE_64BIT_DATATYPES

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE(CIEC_UINT_casts_function_test)


BOOST_AUTO_TEST_CASE(CASTS_UINT_to_BOOL)
{
  CIEC_UINT nTestUInt0;
  CIEC_UINT nTestUInt1;
  CIEC_UINT nTestUInt256;
  CIEC_UINT nTestUInt65535;

  CIEC_BOOL bTestBool;

//check initial values
  BOOST_CHECK_EQUAL(nTestUInt0, 0);
  BOOST_CHECK_EQUAL(nTestUInt1, 0);
  BOOST_CHECK_EQUAL(nTestUInt256, 0);
  BOOST_CHECK_EQUAL(nTestUInt65535, 0);

  nTestUInt0=0;
  nTestUInt1=1;
  nTestUInt256=256;
  nTestUInt65535=65535;

  BOOST_CHECK_EQUAL(nTestUInt0, 0);
  BOOST_CHECK_EQUAL(nTestUInt1, 1);
  BOOST_CHECK_EQUAL(nTestUInt256, 256);
  BOOST_CHECK_EQUAL(nTestUInt65535, 65535);

//checks
  bTestBool.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(false, bTestBool);
  bTestBool.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(true, bTestBool);
  bTestBool.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(true, bTestBool);
  bTestBool.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(true, bTestBool);

}

BOOST_AUTO_TEST_CASE(CASTS_UINT_to_BITDTs)
{
  CIEC_UINT nTestUInt0;
  CIEC_UINT nTestUInt1;
  CIEC_UINT nTestUInt256;
  CIEC_UINT nTestUInt65535;

  CIEC_BYTE nTestByte;
  CIEC_WORD nTestWord;
  CIEC_DWORD nTestDWord;
#ifdef FORTE_USE_64BIT_DATATYPES
  CIEC_DWORD nTestLWord;
#endif //FORTE_USE_64BIT_DATATYPES

//check initial values
  BOOST_CHECK_EQUAL(nTestUInt0, 0);
  BOOST_CHECK_EQUAL(nTestUInt1, 0);
  BOOST_CHECK_EQUAL(nTestUInt256, 0);
  BOOST_CHECK_EQUAL(nTestUInt65535, 0);

  nTestUInt0=0;
  nTestUInt1=1;
  nTestUInt256=256;
  nTestUInt65535=65535;

  BOOST_CHECK_EQUAL(nTestUInt0, 0);
  BOOST_CHECK_EQUAL(nTestUInt1, 1);
  BOOST_CHECK_EQUAL(nTestUInt256, 256);
  BOOST_CHECK_EQUAL(nTestUInt65535, 65535);

//toByte
  nTestByte.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(nTestByte, 0);
  nTestByte.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(nTestByte, 1);
  nTestByte.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(nTestByte, 0);
  nTestByte.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(nTestByte, 255);

//toWord
  nTestWord.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(nTestWord, 0);
  nTestWord.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(nTestWord, 1);
  nTestWord.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(nTestWord, 256);
  nTestWord.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(nTestWord, 65535);

//toDWord
  nTestDWord.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(nTestDWord, 0UL);
  nTestDWord.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(nTestDWord, 1UL);
  nTestDWord.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(nTestDWord, 256UL);
  nTestDWord.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(nTestDWord, 65535UL);


#ifdef FORTE_USE_64BIT_DATATYPES
//toLWord
  nTestLWord.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(nTestLWord, 0ULL);
  nTestLWord.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(nTestLWord, 1ULL);
  nTestLWord.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(nTestLWord, 256ULL);
  nTestLWord.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(nTestLWord, 65535ULL);

#endif
}

BOOST_AUTO_TEST_CASE(CASTS_UINT_to_INTS)
{
  CIEC_UINT nTestUInt0;
  CIEC_UINT nTestUInt1;
  CIEC_UINT nTestUInt256;
  CIEC_UINT nTestUInt65535;

  CIEC_SINT nTestSInt;
  CIEC_USINT nTestUSInt;
  CIEC_INT nTestInt;
  CIEC_DINT nTestDInt;
  CIEC_UDINT nTestUDInt;
#ifdef FORTE_USE_64BIT_DATATYPES
  CIEC_LINT nTestLInt;
  CIEC_ULINT nTestULInt;
#endif //FORTE_USE_64BIT_DATATYPES

  //check initial values
    BOOST_CHECK_EQUAL(nTestUInt0, 0U);
    BOOST_CHECK_EQUAL(nTestUInt1, 0U);
    BOOST_CHECK_EQUAL(nTestUInt256, 0U);
    BOOST_CHECK_EQUAL(nTestUInt65535, 0U);

    nTestUInt0=0U;
    nTestUInt1=1U;
    nTestUInt256=256U;
    nTestUInt65535=65535U;

    BOOST_CHECK_EQUAL(nTestUInt0, 0U);
    BOOST_CHECK_EQUAL(nTestUInt1, 1U);
    BOOST_CHECK_EQUAL(nTestUInt256, 256U);
    BOOST_CHECK_EQUAL(nTestUInt65535, 65535U);

//toSINT
  nTestSInt.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(nTestSInt, 0);
  nTestSInt.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(nTestSInt, 1);
  nTestSInt.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(nTestSInt, 0);
  nTestSInt.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(nTestSInt, -1);

//toUSINT
  nTestUSInt.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(nTestUSInt, 0U);
  nTestUSInt.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(nTestUSInt, 1U);
  nTestUSInt.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(nTestUSInt, 0U);
  nTestUSInt.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(nTestUSInt, 255U);

//toINT
  nTestInt.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(nTestInt, 0);
  nTestInt.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(nTestInt, 1);
  nTestInt.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(nTestInt, 256);
  nTestInt.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(nTestInt, -1);


//toDINT
  nTestDInt.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(nTestDInt, 0);
  nTestDInt.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(nTestDInt, 1);
  nTestDInt.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(nTestDInt, 256);
  nTestDInt.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(nTestDInt, 65535);

//toUDINT
  nTestUDInt.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(nTestUDInt, 0UL);
  nTestUDInt.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(nTestUDInt, 1UL);
  nTestUDInt.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(nTestUDInt, 256UL);
  nTestUDInt.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(nTestUDInt, 65535UL);

#ifdef FORTE_USE_64BIT_DATATYPES
//toLINT
  nTestLInt.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(nTestLInt, 0LL);
  nTestLInt.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(nTestLInt, 1LL);
  nTestLInt.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(nTestLInt, 256LL);
  nTestLInt.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(nTestLInt, 65535LL);

//toULINT
  nTestULInt.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(nTestULInt, 0ULL);
  nTestULInt.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(nTestULInt, 1ULL);
  nTestULInt.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(nTestULInt, 256ULL);
  nTestULInt.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(nTestULInt, 65535ULL);
#endif
}

#ifdef FORTE_USE_REAL_DATATYPE
BOOST_AUTO_TEST_CASE(CASTS_UINT_to_REAL)
{
  CIEC_UINT nTestUInt0;
  CIEC_UINT nTestUInt1;
  CIEC_UINT nTestUInt256;
  CIEC_UINT nTestUInt65535;

  CIEC_REAL nTestReal;

//check initial values
  BOOST_CHECK_EQUAL(nTestUInt0, 0U);
  BOOST_CHECK_EQUAL(nTestUInt1, 0U);
  BOOST_CHECK_EQUAL(nTestUInt256, 0U);
  BOOST_CHECK_EQUAL(nTestUInt65535, 0U);

  nTestUInt0=0U;
  nTestUInt1=1U;
  nTestUInt256=256U;
  nTestUInt65535=65535U;

  BOOST_CHECK_EQUAL(nTestUInt0, 0U);
  BOOST_CHECK_EQUAL(nTestUInt1, 1U);
  BOOST_CHECK_EQUAL(nTestUInt256, 256U);
  BOOST_CHECK_EQUAL(nTestUInt65535, 65535U);

//toREAL
  nTestReal.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(0.0f, nTestReal);
  nTestReal.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(1.0f, nTestReal); 
  nTestReal.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(256.0f, nTestReal); 
  nTestReal.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(65535.0f, nTestReal); 


#ifdef FORTE_USE_64BIT_DATATYPES
  CIEC_LREAL nTestLReal;

//toLREAL
  nTestLReal.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(0.0, nTestLReal);
  nTestLReal.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(1.0, nTestLReal); 
  nTestLReal.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(256.0, nTestLReal); 
  nTestLReal.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(65535.0, nTestLReal);
#endif //FORTE_USE_64BIT_DATATYPES

}
#endif //FORTE_USE_REAL_DATATYPE

BOOST_AUTO_TEST_CASE(CASTS_UINT_to_TIME)
{
  CIEC_UINT nTestUInt0;
  CIEC_UINT nTestUInt1;
  CIEC_UINT nTestUInt256;
  CIEC_UINT nTestUInt65535;

  CIEC_TIME nTestTime;

//check initial values
  BOOST_CHECK_EQUAL(nTestUInt0, 0U);
  BOOST_CHECK_EQUAL(nTestUInt1, 0U);
  BOOST_CHECK_EQUAL(nTestUInt256, 0U);
  BOOST_CHECK_EQUAL(nTestUInt65535, 0U);

  nTestUInt0=0U;
  nTestUInt1=1U;
  nTestUInt256=256U;
  nTestUInt65535=65535U;

  BOOST_CHECK_EQUAL(nTestUInt0, 0U);
  BOOST_CHECK_EQUAL(nTestUInt1, 1U);
  BOOST_CHECK_EQUAL(nTestUInt256, 256U);
  BOOST_CHECK_EQUAL(nTestUInt65535, 65535U);

//toTIME
  nTestTime.setValue(nTestUInt0);
  BOOST_CHECK_EQUAL(0, nTestTime);
  nTestTime.setValue(nTestUInt1);
  BOOST_CHECK_EQUAL(1, nTestTime);
  nTestTime.setValue(nTestUInt256);
  BOOST_CHECK_EQUAL(256, nTestTime);
  nTestTime.setValue(nTestUInt65535);
  BOOST_CHECK_EQUAL(65535, nTestTime);
}

BOOST_AUTO_TEST_CASE(UINT_Castable_test)
{
  bool bUp, bDown;

  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_BOOL, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);

  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_SINT, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_INT, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_DINT, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_LINT, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);

  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_USINT, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_UINT, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_UDINT, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_ULINT, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);

  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_BYTE, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_WORD, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_DWORD, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_LWORD, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);

  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_DATE, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_TIME_OF_DAY, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_DATE_AND_TIME, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_TIME, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);

  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_REAL, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_LREAL, bUp, bDown)); BOOST_CHECK(bUp); BOOST_CHECK(! bDown);

  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_STRING, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);
  BOOST_CHECK(!CIEC_ANY::isCastable(CIEC_ANY::e_UINT, CIEC_ANY::e_WSTRING, bUp, bDown)); BOOST_CHECK(! bUp); BOOST_CHECK(! bDown);
}

BOOST_AUTO_TEST_SUITE_END()

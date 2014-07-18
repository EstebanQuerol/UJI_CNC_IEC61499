#include <boost/test/unit_test.hpp>

#include "../../../src/core/datatypes/forte_date.h"

BOOST_AUTO_TEST_SUITE(CIEC_DATE_function_test)
BOOST_AUTO_TEST_CASE(Type_test)
{
	CIEC_DATE nTest;
	//check type information
	BOOST_CHECK_EQUAL(nTest.getDataTypeID(), CIEC_ANY::e_DATE);
	//check operator book data type size
	BOOST_CHECK_EQUAL(sizeof(nTest.operator TForteUInt64()), sizeof(TForteUInt64));

}

BOOST_AUTO_TEST_CASE(Operator_test)
{
	CIEC_DATE nTest1;
	CIEC_DATE nTest2;

	//check if data type is initialized with value of zero
	BOOST_CHECK_EQUAL(nTest1,0ULL);

	nTest1 = std::numeric_limits<TForteUInt64>::min();
	nTest2 = nTest1;
	BOOST_CHECK_EQUAL(nTest1, std::numeric_limits<TForteUInt64>::min());
	BOOST_CHECK_EQUAL(nTest2, std::numeric_limits<TForteUInt64>::min());

	nTest1 = 9657545ULL;
	nTest2 = nTest1;
	BOOST_CHECK_EQUAL(nTest1, 9657545ULL);
	BOOST_CHECK_EQUAL(nTest2, 9657545ULL);

	nTest1 = std::numeric_limits<TForteUInt64>::max();
	nTest2 = nTest1;
	BOOST_CHECK_EQUAL(nTest1, std::numeric_limits<TForteUInt64>::max());
	BOOST_CHECK_EQUAL(nTest2, std::numeric_limits<TForteUInt64>::max());

	nTest2 = 564874642ULL;
	BOOST_CHECK_EQUAL(nTest1, std::numeric_limits<TForteUInt64>::max());
	BOOST_CHECK_EQUAL(nTest2, 564874642ULL);

	++nTest2;
	BOOST_CHECK_EQUAL(nTest2, 564874643ULL);

}

BOOST_AUTO_TEST_CASE(Conversion_test)
{
	CIEC_DATE nTest;
  TForteInt32 nTZOffset;

	char cBuffer[11];
	char cBufferFail[2];

  nTZOffset = CIEC_ANY_DATE::getTimeZoneOffset();
	BOOST_CHECK_EQUAL(nTZOffset, 60); // Western Europe, adjust if somewhere else

	//check cast operator
	nTest = 0;
	strcpy(cBuffer, "");

	BOOST_CHECK_EQUAL(nTest.operator TForteUInt64(), 0ULL);

	nTest = std::numeric_limits<TForteUInt64>::min();
	BOOST_CHECK_EQUAL(nTest.operator TForteUInt64(), std::numeric_limits<TForteUInt64>::min());

	nTest = 4268743213844LL;
	BOOST_CHECK_EQUAL(nTest.operator TForteUInt64(), 4268743213844ULL);

	nTest = std::numeric_limits<TForteUInt64>::max();
	BOOST_CHECK_EQUAL(nTest.operator TForteUInt64(), std::numeric_limits<TForteUInt64>::max());

	//check toString and fromString
	strcpy(cBuffer, "");

	//TODO: Check if this is really a legal literal
	BOOST_CHECK_EQUAL(nTest.fromString("1994-06-22"), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBuffer, 11), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBufferFail, 2), -1);
	BOOST_CHECK_EQUAL(strcmp(cBuffer, "1994-06-22"), 0);
	strcpy(cBuffer, "");
  nTest = 0;

	BOOST_CHECK_EQUAL(nTest.fromString("DATE#1994-06-22"), 15);
	BOOST_CHECK_EQUAL(nTest.toString(cBuffer, 11), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBufferFail, 2), -1);
	BOOST_CHECK_EQUAL(strcmp(cBuffer, "1994-06-22"), 0);
	strcpy(cBuffer, "");
  nTest = 0;

	BOOST_CHECK_EQUAL(nTest.fromString("date#1994-06-22"), 15);
	BOOST_CHECK_EQUAL(nTest.toString(cBuffer, 11), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBufferFail, 2), -1);
	BOOST_CHECK_EQUAL(strcmp(cBuffer, "1994-06-22"), 0);
	strcpy(cBuffer, "");
  nTest = 0;

	BOOST_CHECK_EQUAL(nTest.fromString("D#1994-06-22"), 12);
	BOOST_CHECK_EQUAL(nTest.toString(cBuffer, 11), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBufferFail, 2), -1);
	BOOST_CHECK_EQUAL(strcmp(cBuffer, "1994-06-22"), 0);
	strcpy(cBuffer, "");
  nTest = 0;

	BOOST_CHECK_EQUAL(nTest.fromString("d#1994-06-22"), 12);
	BOOST_CHECK_EQUAL(nTest.toString(cBuffer, 11), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBufferFail, 2), -1);
	BOOST_CHECK_EQUAL(strcmp(cBuffer, "1994-06-22"), 0);
	strcpy(cBuffer, "");
  nTest = 0;

	//TODO: Check if this is really a legal literal
	BOOST_CHECK_EQUAL(nTest.fromString("2008-04-03"), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBuffer, 11), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBufferFail, 2), -1);
	BOOST_CHECK_EQUAL(strcmp(cBuffer, "2008-04-03"), 0);
	strcpy(cBuffer, "");
  nTest = 0;

	BOOST_CHECK_EQUAL(nTest.fromString("DATE#2008-04-03"), 15);
	BOOST_CHECK_EQUAL(nTest.toString(cBuffer, 11), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBufferFail, 2), -1);
	BOOST_CHECK_EQUAL(strcmp(cBuffer, "2008-04-03"), 0);
	strcpy(cBuffer, "");
  nTest = 0;

	BOOST_CHECK_EQUAL(nTest.fromString("date#2008-04-03"), 15);
	BOOST_CHECK_EQUAL(nTest.toString(cBuffer, 11), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBufferFail, 2), -1);
	BOOST_CHECK_EQUAL(strcmp(cBuffer, "2008-04-03"), 0);
	strcpy(cBuffer, "");
  nTest = 0;

	BOOST_CHECK_EQUAL(nTest.fromString("D#2008-04-03"), 12);
	BOOST_CHECK_EQUAL(nTest.toString(cBuffer, 11), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBufferFail, 2), -1);
	BOOST_CHECK_EQUAL(strcmp(cBuffer, "2008-04-03"), 0);
	strcpy(cBuffer, "");
  nTest = 0;

	BOOST_CHECK_EQUAL(nTest.fromString("d#2008-04-03"), 12);
	BOOST_CHECK_EQUAL(nTest.toString(cBuffer, 11), 10);
	BOOST_CHECK_EQUAL(nTest.toString(cBufferFail, 2), -1);
	BOOST_CHECK_EQUAL(strcmp(cBuffer, "2008-04-03"), 0);
	strcpy(cBuffer, "");

  // Check timezone handling
	BOOST_CHECK_EQUAL(nTest.fromString("1970-01-01"), 10);
	BOOST_CHECK_EQUAL(nTest.operator TForteUInt64(), 0ULL);
}
BOOST_AUTO_TEST_SUITE_END()

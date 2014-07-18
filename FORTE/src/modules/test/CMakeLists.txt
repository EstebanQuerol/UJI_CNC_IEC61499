forte_add_module(Test "Test function blocks")

#############################################################################
# Test FB
#############################################################################
forte_add_sourcefile_hcpp(AdapterTest_P  CRYPT_1  CRYPT_2  DECRYPT_1  DECRYPT_2  SocketTest_S  TestAdapter)
forte_add_sourcefile_hcpp(FORTE_TestStruct)
forte_add_sourcefile_hcpp(TestStruct2TestStruct)


FIND_PROGRAM(GCOV_PATH gcov)
FIND_PROGRAM(LCOV_PATH lcov)
FIND_PROGRAM(GENHTML_PATH genhtml)

IF(NOT GCOV_PATH)
        MESSAGE(FATAL_ERROR "Error: gcov not found")
ENDIF()

FUNCTION(SETUP_GCOV targetName testRunner outputName)

        IF(NOT LCOV_PATH)
                MESSAGE(FATAL_ERROR "Error: lcov not found")
        ENDIF()

        IF(NOT GENHTML_PATH)
                MESSAGE(FATAL_ERROR "Error:  genhtml not found")
        ENDIF()

        # Setup target
        ADD_CUSTOM_TARGET(${targetName}
                ${LCOV_PATH} --directory . --zerocounters
                
                COMMAND ${testRunner} ${ARGV3}
                
                COMMAND ${LCOV_PATH} --directory . --capture --gcov-tool ${GCOV_PATH} --output-file ${outputName}.info
                COMMAND ${LCOV_PATH} --remove ${outputName}.info 'tests/*' '/usr/*' --output-file ${outputName}.info.cleaned
                COMMAND ${GENHTML_PATH} -o ${outputName} ${outputName}.info.cleaned --demangle-cpp --rc lcov_branch_coverage=1
                COMMAND ${CMAKE_COMMAND} -E remove ${outputName}.info ${outputName}.info.cleaned
                
                WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        )
        
ENDFUNCTION()
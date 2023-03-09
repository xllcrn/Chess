cmake_minimum_required(VERSION 3.16)

## List all files containing tests. (Change as needed)
set(TESTFILES        # All .cpp files in tests/
        test.cpp
        )
set(TEST_MAIN "Boost_Tests_run")
set(Boost_USE_STATIC_LIBS ON)
set(BOOST_ROOT "C:/boost_1_71_0_x32/boost")
set(Boost_INCLUDE_DIR "C:/boost_1_71_0_x32")
set (Boost_INCLUDE_DIRS "C:/boost_1_71_0_x32")
set(Boost_LIBRARY_DIR "C:/boost_1_71_0_x32/lib32-msvc-14.2")
find_package (Boost 1.71.0 REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

add_executable (${TEST_MAIN} test.cpp)
target_link_libraries (Boost_Tests_run ${Boost_LIBRARIES} ${LIBRARY_NAME})
#target_link_libraries(${TEST_MAIN} ${LIBRARY_NAME} )


#
#
#
##include_directories("C:\\Boost\\boost_1_81_0\\boost_1_81_0")
#set(BOOST_ROOT C:\\Boost\\boost_1_81_0\\boost_1_81_0)
#find_package(Boost REQUIRED)
##find_package(Boost 1.81.0 COMPONENTS system filesystem REQUIRED)
#
#
## List all files containing tests. (Change as needed)
#set(TESTFILES        # All .cpp files in tests/
#        test.cpp
#        )
#
#set(TEST_MAIN unit_tests)   # Default name for test executable (change if you wish).
#set(TEST_RUNNER_PARAMS "")  # Any arguemnts to feed the test runner (change as needed).
#
## --------------------------------------------------------------------------------
##                         Make Tests (no change needed).
## --------------------------------------------------------------------------------
#add_executable(${TEST_MAIN} ${TESTFILES})
##target_link_libraries("C:\\Boost\\boost_1_81_0\\boost_1_81_0\\stage\\lib")
##target_link_libraries(${TEST_MAIN} PRIVATE ${LIBRARY_NAME} doctest)
#set_target_properties(${TEST_MAIN} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
##target_set_warnings(${TEST_MAIN} ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).
#
#set_target_properties(${TEST_MAIN} PROPERTIES
#        CXX_STANDARD 17
#        CXX_STANDARD_REQUIRED YES
#        CXX_EXTENSIONS NO
#        )
#
#add_test(
#        # Use some per-module/project prefix so that it is easier to run only tests for this module
#        NAME ${LIBRARY_NAME}.${TEST_MAIN}
#        COMMAND ${TEST_MAIN} ${TEST_RUNNER_PARAMS})
#
## Adds a 'coverage' target.
##include(CodeCoverage)
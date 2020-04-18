cmake_minimum_required(VERSION 3.8.2)

# List all files containing tests. (Change as needed)
set(ANIMATION_TEST_SRC        # All .cpp files in tests/
    ${CMAKE_CURRENT_SOURCE_DIR}/animation/animation_tests.cpp
)
set(SCENE_TEST_SRC        # All .cpp files in tests/
    ${CMAKE_CURRENT_SOURCE_DIR}/scene/scene_tests.cpp
)

set(TEST_ANIMATION animation_unittest)   # Default name for test executable (change if you wish).
set(TEST_SCENE scene_unittest)   # Default name for test executable (change if you wish).
set(TEST_RUNNER_PARAMS "")  # Any arguemnts to feed the test runner (change as needed).

# --------------------------------------------------------------------------------
#                         Make Tests (no change needed).
# --------------------------------------------------------------------------------
add_executable(${TEST_ANIMATION} ${ANIMATION_TEST_SRC})
target_link_libraries(${TEST_ANIMATION} PRIVATE ${LIBRARY_NAME} ${CONAN_LIBS})
set_target_properties(${TEST_ANIMATION} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
target_set_warnings(${TEST_ANIMATION} ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).
set_target_properties(${TEST_ANIMATION} PROPERTIES 
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED YES 
    CXX_EXTENSIONS NO
)

add_test(
    # Use some per-module/project prefix so that it is easier to run only tests for this module
    NAME ${TEST_ANIMATION}
    COMMAND ${TEST_ANIMATION} ${TEST_RUNNER_PARAMS})

add_executable(${TEST_SCENE} ${SCENE_TEST_SRC})
target_link_libraries(${TEST_SCENE} PRIVATE ${LIBRARY_NAME} ${Boost_LIBRARIES})
set_target_properties(${TEST_SCENE} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
target_set_warnings(${TEST_SCENE} ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).
set_target_properties(${TEST_SCENE} PROPERTIES 
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED YES 
    CXX_EXTENSIONS NO
)

add_test(
    # Use some per-module/project prefix so that it is easier to run only tests for this module
    NAME ${TEST_SCENE}
    COMMAND ${TEST_SCENE} ${TEST_RUNNER_PARAMS})
# Adds a 'coverage' target.
include(CodeCoverage)


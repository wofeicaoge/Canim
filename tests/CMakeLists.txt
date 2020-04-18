cmake_minimum_required(VERSION 3.8.2)

# List all files containing tests. (Change as needed)
set(ANIMATION_TEST_SRC        # All .cpp files in tests/
    ${CMAKE_CURRENT_SOURCE_DIR}/animation/animation_tests.cpp
)
set(SCENE_TEST_SRC        # All .cpp files in tests/
    ${CMAKE_CURRENT_SOURCE_DIR}/scene/scene_tests.cpp
)

set(TEST_MAIN unit_test)   # Default name for test executable (change if you wish).
set(TEST_RUNNER_PARAMS "")  # Any arguemnts to feed the test runner (change as needed).

# --------------------------------------------------------------------------------
#                         Make Tests (no change needed).
# --------------------------------------------------------------------------------
add_executable(${TEST_MAIN} ${ANIMATION_TEST_SRC})
target_link_libraries(${TEST_MAIN} PRIVATE ${LIBRARY_NAME} ${CONAN_LIBS})
set_target_properties(${TEST_MAIN} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
target_set_warnings(${TEST_MAIN} ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).
set_target_properties(${TEST_MAIN} PROPERTIES
    CXX_STANDARD 17 
    CXX_STANDARD_REQUIRED YES 
    CXX_EXTENSIONS NO
)

add_test(
    # Use some per-module/project prefix so that it is easier to run only tests for this module
    NAME ${TEST_MAIN}
    COMMAND ${TEST_MAIN} ${TEST_RUNNER_PARAMS})


# Adds a 'coverage' target.
include(CodeCoverage)


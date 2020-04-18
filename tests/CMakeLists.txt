cmake_minimum_required(VERSION 3.8.2)

# List all files containing tests. (Change as needed)
set(ANIMATION_TEST_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/animation/animation_tests.cpp
)
set(SCENE_TEST_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/scene/scene_tests.cpp
)

set(TEST_ANIMATION animation_unittest)
set(TEST_SCENE scene_unittest)
set(TEST_MAIN canim_unittest)   # Default name for test executable (change if you wish).
set(TEST_RUNNER_PARAMS "")  # Any arguemnts to feed the test runner (change as needed).

FUNCTION(ADD_TEST_EXECUTE _test_name _test_src)
    add_executable(${_test_name} ${_test_src})
    target_link_libraries(${_test_name} PRIVATE ${LIBRARY_NAME} ${CONAN_LIBS})
    set_target_properties(${_test_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
    set_target_properties(${_test_name} PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED YES
            CXX_EXTENSIONS NO
            )

    add_test(
            NAME ${_test_name}
            COMMAND ${_test_name})
ENDFUNCTION()

# --------------------------------------------------------------------------------
#                         Make Tests (no change needed).
# --------------------------------------------------------------------------------

ADD_TEST_EXECUTE(${TEST_ANIMATION} ${ANIMATION_TEST_SRC})
ADD_TEST_EXECUTE(${TEST_SCENE} ${SCENE_TEST_SRC})


# Adds a 'coverage' target.
include(CodeCoverage)


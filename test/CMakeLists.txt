enable_testing()

set(ANIMATION_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/animation/animation_tests.cpp)


add_executable(animation_unittest ${ANIMATION_TEST_SRC})
target_link_libraries(animation_unittest ${ANIMATION_LIB} ${CONAN_LIBS})


add_test(test animation_unittest)
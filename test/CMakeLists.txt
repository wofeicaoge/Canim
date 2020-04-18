enable_testing()

set(ANIMATION_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/animation/animation_tests.cpp)


add_executable(animation_unittest ${ANIMATION_TEST_SRC})
target_include_directories(animation_unittest PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(animation_unittest ${ANIMATION_LIB} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_compile_definitions(animation_unittest PRIVATE "BOOST_TEST_DYN_LINK=1")


add_test(test animation_unittest)
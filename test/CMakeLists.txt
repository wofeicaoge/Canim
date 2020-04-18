enable_testing()

set(ANIMATION_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/animation/animation_tests.cpp)

set(SCENE_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/scene/scene_tests.cpp)

add_executable(animation_unittest ${ANIMATION_TEST_SRC})
target_link_libraries(animation_unittest ${ANIMATION_LIB} ${CONAN_LIBS})

add_executable(scene_unittest ${SCENE_TEST_SRC})
target_link_libraries(scene_unittest ${ANIMATION_LIB} ${CONAN_LIBS})

add_test(NAME animation_unittest COMMAND $<TARGET_FILE:animation_unittest>)
add_test(NAME scene_unittest COMMAND $<TARGET_FILE:scene_unittest>)
cmake_minimum_required(VERSION 3.5)
project(Canim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

find_package(Boost REQUIRED COMPONENTS unit_test_framework)


if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif ()

include_directories(src)
add_subdirectory(test)

set(ANIMATION_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/animation/animation.cpp)
set(ANIMATION_LIB animationlib)

add_library(${ANIMATION_LIB} ${ANIMATION_SRC})
target_link_libraries(${ANIMATION_LIB})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${ANIMATION_LIB})






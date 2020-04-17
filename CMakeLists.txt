cmake_minimum_required(VERSION 2.8)
project(Canim)

add_definitions("-std=c++17")

include_directories(src)

set(ANIMATION_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/animation/animation.cpp)

add_executable(canim main.cpp ${ANIMATION_SRC})

add_library(canimlib ${ANIMATION_SRC})
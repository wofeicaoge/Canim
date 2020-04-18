cmake_minimum_required(VERSION 3.5)
project(Canim)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()


if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif ()

set(ANIMATION_LIB animationlib)

include_directories(src)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

enable_testing()
find_package(codecov)

add_subdirectory(src)
add_subdirectory(test)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${ANIMATION_LIB} ${CONAN_LIBS})

coverage_evaluate()






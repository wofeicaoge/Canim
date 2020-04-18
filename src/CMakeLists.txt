set(ANIMATION_SRC ${CMAKE_CURRENT_SOURCE_DIR}/animation/animation.cpp)

add_library(${ANIMATION_LIB} ${ANIMATION_SRC})
target_link_libraries(${ANIMATION_LIB})
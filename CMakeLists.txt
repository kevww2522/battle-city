cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(PROJ_NAME battle-city)
project(${PROJ_NAME})

add_executable(${PROJ_NAME} src/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJ_NAME} glfw)
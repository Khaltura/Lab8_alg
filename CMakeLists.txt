cmake_minimum_required(VERSION 3.5)
project(LAB_8 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(LAB_8 src/main.cpp)
add_library(Index src/Index.cpp)
target_link_libraries(LAB_8 Index)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

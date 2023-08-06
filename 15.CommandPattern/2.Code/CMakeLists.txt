cmake_minimum_required(VERSION 3.17)
project(Command)

message(STATUS "start building......")

set(OUT_DIR ../)
set(EXECUTABLE_OUTPUT_PATH ${OUT_DIR}/bin)

file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(app ${SRC_LIST})

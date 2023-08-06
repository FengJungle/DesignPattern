cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)

project(AbstractFatory)


set(SRC_LIST main.cpp)
add_executable(app ${SRC_LIST})
set(WORK_DIR ../)
set(EXECUTABLE_OUTPUT_PATH ${WORK_DIR})

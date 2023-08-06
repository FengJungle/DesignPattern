cmake_minimum_required(VERSION 3.10)

# 指定C++版本
set(CMAKE_CXX_STANDARD 11)

project(AbstractFatory)


set(SRC_LIST main.cpp)
add_executable(app ${SRC_LIST})

# 指定可执行文件的输出路径，相对路径是相对makefile文件位置的路径
set(WORK_DIR ../)
set(EXECUTABLE_OUTPUT_PATH ${WORK_DIR})

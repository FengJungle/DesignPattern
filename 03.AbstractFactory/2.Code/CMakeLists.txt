cmake_minimum_required(VERSION 3.10)

# 指定C++版本
set(CMAKE_CXX_STANDARD 11)

project(AbstractFatory)


set(SRC_LIST main.cpp)
add_executable(app3 ${SRC_LIST})

# 指定可执行文件的输出路径，相对路径是相对makefile文件位置的路径
get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(FOLDER_NAME ${FOLDER_NAME} NAME)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIR}/${FOLDER_NAME})

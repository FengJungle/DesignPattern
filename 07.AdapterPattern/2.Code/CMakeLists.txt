cmake_minimum_required(VERSION 3.15)
project(BuilderPattern)
set(SRC_LIST main.cpp)

get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(FOLDER_NAME ${FOLDER_NAME} NAME)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIR}/${FOLDER_NAME})
add_executable(app7 ${SRC_LIST})
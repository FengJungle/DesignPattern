cmake_minimum_required(VERSION 3.15)
project(Prototype)

get_filename_component(FOLDER_NAME ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(FOLDER_NAME ${FOLDER_NAME} NAME)
set(EXECUTABLE_OUTPUT_PATH ${OUTPUT_DIR}/${FOLDER_NAME})

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(app5 ${SRC_LIST})
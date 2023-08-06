cmake_minimum_required(VERSION 3.15)
project(Iterator)

set(WORK_DIR ../)
set(EXECUTABLE_OUTPUT_PATH ${WORK_DIR}/bin)

set(CMAKE_CXX_STANDARD 11)

# 搜索指定路径下的cpp文件，组成一个列表，结果保存至SRC_LIST变量
# CMAKE_CURRENT_SOURCE_DIR是CMakeLists.txt文件所在的路径
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(app ${SRC_LIST})
cmake_minimum_required(VERSION 3.15)
project(cplusplus_design_pattern)

set(OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin/)
message(STATUS "output dir : ${OUTPUT_DIR}")

add_subdirectory(01.SimpleFactory/2.Code/)
add_subdirectory(02.FactoryMethod/2.Code/)
add_subdirectory(03.AbstractFactory/2.Code/)
add_subdirectory(17.IteratorPattern/2.Code/)

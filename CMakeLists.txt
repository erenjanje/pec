cmake_minimum_required(VERSION 3.13)

project("pec")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(TO_CMAKE_PATH ${CMAKE_SOURCE_DIR} SOURCE_DIR)
string(LENGTH ${SOURCE_DIR} SOURCE_DIR_LEN)

add_compile_definitions("__FILENAME__=(__FILE__+${SOURCE_DIR_LEN}+1)")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")

include_directories("${CMAKE_SOURCE_DIR}/source")

add_subdirectory("source")

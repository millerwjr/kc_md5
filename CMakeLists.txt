cmake_minimum_required(VERSION 3.6)
project(kc_md5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp kc_md5.h kc_md5.cpp)
add_executable(kc_md5 ${SOURCE_FILES})
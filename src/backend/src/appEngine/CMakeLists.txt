cmake_minimum_required(VERSION 3.2)

project(appEngine)

set(SOURCE_LIB testManager.cpp)
add_library(appEngine STATIC ${SOURCE_LIB})

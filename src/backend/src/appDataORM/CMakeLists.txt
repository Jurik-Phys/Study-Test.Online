cmake_minimum_required(VERSION 3.2)

project(appDataManager)

set(SOURCE_LIB appDataManager.cpp)
add_library(appDataORM STATIC ${SOURCE_LIB})

cmake_minimum_required(VERSION 3.2)

project(backAppQtTest)

set(CMAKE_CXX_STANDART 14)

find_package(Qt5Test REQUIRED)

set(SOURCE_EXE backAppQtTest.cpp ./../src/appDataORM/appDataManager.cpp)

add_executable(backAppQtTest ${SOURCE_EXE})

set_target_properties(backAppQtTest PROPERTIES AUTOMOC ON)

## Alternative MOC support (Qt native)
# qt_wrap_cpp(MOC_SOURCES backAppQtTest.h)
# add_executable(backAppQtTest ${SOURCE_EXE} ${MOC_SOURCES})

target_link_libraries(backAppQtTest Qt5::Test)

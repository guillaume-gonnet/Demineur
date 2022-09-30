cmake_minimum_required(VERSION 3.5)

project(unit_test LANGUAGES CXX)

enable_testing()

include_directories(../../demineur)
#set(PROJECT_SOURCES
#        scoreCard.h
#	scoreCard.cpp
#    )

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(unit_test SHARED tst_unit_test.cpp)
add_test(NAME unit_test COMMAND unit_test)

target_link_libraries(unit_test PRIVATE Qt${QT_VERSION_MAJOR}::Test demineur)


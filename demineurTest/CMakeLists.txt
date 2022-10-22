cmake_minimum_required(VERSION 3.15)

enable_testing()
project(test LANGUAGES CXX)

include_directories(../demineur)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(demineurTest tst_unit_test.cpp tst_gui_mainwindow.cpp)
add_test(NAME demineurTest COMMAND demineurTest)

target_link_libraries(demineurTest PRIVATE Qt${QT_VERSION_MAJOR}::Test demineur)



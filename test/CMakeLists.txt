cmake_minimum_required(VERSION 3.15)

enable_testing()
project(test LANGUAGES CXX)


find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)

add_subdirectory(unit_test)

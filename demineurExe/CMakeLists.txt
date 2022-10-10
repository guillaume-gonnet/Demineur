cmake_minimum_required(VERSION 3.5)

project(demineurExe VERSION 0.1 LANGUAGES CXX)

include_directories(../demineur)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets )

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(demineurExe
        ${PROJECT_SOURCES}
    )

else()
    if(ANDROID)
        add_library(demineurExe SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
	add_executable(demineurExe
	    ${PROJECT_SOURCES}
	)

    endif()

endif()

#target_compile_definitions(semineurExe
#  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)


target_link_libraries(demineurExe PUBLIC demineur PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)

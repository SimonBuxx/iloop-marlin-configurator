cmake_minimum_required(VERSION 3.5)

project(Marlin_Configurator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/resources/icon.rc")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Marlin_Configurator
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${APP_ICON_RESOURCE_WINDOWS}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Marlin_Configurator APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Marlin_Configurator SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Marlin_Configurator
            ${PROJECT_SOURCES}
            ${APP_ICON_RESOURCE_WINDOWS}
        )
    endif()
endif()

target_link_libraries(Marlin_Configurator
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        GUI_IMC::GUI
)

target_sources(Marlin_Configurator
    PRIVATE
        main.cpp
        Application.h
        Application.cpp
        Configuration.h
        HelperFunctions.h
        resources/resources.qrc
)

set_target_properties(Marlin_Configurator
    PROPERTIES
        OUTPUT_NAME "iMC"
)

set_target_properties(Marlin_Configurator
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

install(TARGETS Marlin_Configurator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Marlin_Configurator)
endif()

add_subdirectory(gui)

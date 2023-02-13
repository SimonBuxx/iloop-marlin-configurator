add_library(GUI_IMC_GUI)
add_library(GUI_IMC::GUI ALIAS GUI_IMC_GUI)

target_link_libraries(GUI_IMC_GUI
    PUBLIC
        Qt${QT_VERSION_MAJOR}::Widgets
)

target_include_directories(GUI_IMC_GUI
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_sources(GUI_IMC_GUI
    PRIVATE
        MainWindow.h
        MainWindow.cpp
        MainWindow.ui
        AbstractPage.h
        AbstractPage.cpp
        FirmwarePage.h
        FirmwarePage.cpp
        FirmwarePage.ui
        HardwarePage.h
        HardwarePage.cpp
        HardwarePage.ui
        AboutDialog.h
        AboutDialog.cpp
        AboutDialog.ui
        PowerSupplyPage.h
        PowerSupplyPage.cpp
        PowerSupplyPage.ui
        WelcomePage.h
        WelcomePage.cpp
        WelcomePage.ui
        ExtruderPage.h
        ExtruderPage.cpp
        ExtruderPage.ui
)

add_subdirectory(widgets)

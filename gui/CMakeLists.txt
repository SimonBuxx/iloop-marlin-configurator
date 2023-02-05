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
        FirmwarePage.h
        FirmwarePage.cpp
        FirmwarePage.ui
        HardwarePage.h
        HardwarePage.cpp
        HardwarePage.ui
        Endstops_Configurator.h
        Endstops_Configurator.cpp
        Endstops_Configurator.ui
        AboutDialog.h
        AboutDialog.cpp
        AboutDialog.ui
        TemperaturesPage.h
        TemperaturesPage.cpp
        TemperaturesPage.ui
        PowerSupplyPage.h
        PowerSupplyPage.cpp
        PowerSupplyPage.ui
        HotendTempSensorsConfigurator.h
        HotendTempSensorsConfigurator.cpp
        HotendTempSensorsConfigurator.ui
)

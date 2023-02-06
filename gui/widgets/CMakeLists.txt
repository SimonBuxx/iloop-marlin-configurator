target_sources(GUI_IMC_GUI
    PRIVATE
        widgets/Dropdown.h
        widgets/Dropdown.cpp
)

target_include_directories(GUI_IMC_GUI
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

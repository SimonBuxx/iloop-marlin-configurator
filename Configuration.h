#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QJsonObject>
#include <cstdint>
#include <string>

namespace defaults
{
static constexpr auto SHOW_BOOTSCREEN{true};
static constexpr auto SERIAL_PORT{0};
static constexpr auto BAUDRATE{250000};
static constexpr auto CUSTOM_MACHINE_NAME{""};
static constexpr auto STRING_CONFIG_H_AUTHOR{""};
static constexpr auto MOTHERBOARD{"RAMPS 1.4 (Power outputs: Hotend, Fan, Bed) [BOARD_RAMPS_14_EFB]"};
static constexpr auto LCD_DISPLAY{"REPRAP_DISCOUNT_SMART_CONTROLLER"};
static constexpr auto EXTRUDERS{1};
static constexpr auto DEFAULT_NOMINAL_FILAMENT_DIA{1.75f}; // mm
static constexpr auto X_BED_SIZE{200}; // mm
static constexpr auto Y_BED_SIZE{200}; // mm

static constexpr auto USE_XMIN_PLUG{true};
static constexpr auto USE_YMIN_PLUG{true};
static constexpr auto USE_ZMIN_PLUG{true};
static constexpr auto USE_IMIN_PLUG{false};
static constexpr auto USE_JMIN_PLUG{false};
static constexpr auto USE_KMIN_PLUG{false};

static constexpr auto USE_XMAX_PLUG{false};
static constexpr auto USE_YMAX_PLUG{false};
static constexpr auto USE_ZMAX_PLUG{false};
static constexpr auto USE_IMAX_PLUG{false};
static constexpr auto USE_JMAX_PLUG{false};
static constexpr auto USE_KMAX_PLUG{false};

static constexpr auto X_MIN_ENDSTOP_INVERTING{false};
static constexpr auto Y_MIN_ENDSTOP_INVERTING{false};
static constexpr auto Z_MIN_ENDSTOP_INVERTING{false};
static constexpr auto I_MIN_ENDSTOP_INVERTING{false};
static constexpr auto J_MIN_ENDSTOP_INVERTING{false};
static constexpr auto K_MIN_ENDSTOP_INVERTING{false};

static constexpr auto X_MAX_ENDSTOP_INVERTING{false};
static constexpr auto Y_MAX_ENDSTOP_INVERTING{false};
static constexpr auto Z_MAX_ENDSTOP_INVERTING{false};
static constexpr auto I_MAX_ENDSTOP_INVERTING{false};
static constexpr auto J_MAX_ENDSTOP_INVERTING{false};
static constexpr auto K_MAX_ENDSTOP_INVERTING{false};

static constexpr auto Z_MIN_PROBE_ENDSTOP_INVERTING{false};

}

struct Configuration
{
    bool SHOW_BOOTSCREEN{defaults::SHOW_BOOTSCREEN};
    int8_t SERIAL_PORT{defaults::SERIAL_PORT};
    int32_t BAUDRATE{defaults::BAUDRATE};
    QString CUSTOM_MACHINE_NAME{defaults::CUSTOM_MACHINE_NAME};
    QString STRING_CONFIG_H_AUTHOR{defaults::STRING_CONFIG_H_AUTHOR};
    QString MOTHERBOARD{defaults::MOTHERBOARD};
    QString LCD_DISPLAY{defaults::LCD_DISPLAY};
    int8_t EXTRUDERS{defaults::EXTRUDERS};
    qreal DEFAULT_NOMINAL_FILAMENT_DIA{defaults::DEFAULT_NOMINAL_FILAMENT_DIA};
    int32_t X_BED_SIZE{defaults::X_BED_SIZE};
    int32_t Y_BED_SIZE{defaults::Y_BED_SIZE};

    bool USE_XMIN_PLUG{defaults::USE_XMIN_PLUG};
    bool USE_YMIN_PLUG{defaults::USE_YMIN_PLUG};
    bool USE_ZMIN_PLUG{defaults::USE_ZMIN_PLUG};
    bool USE_IMIN_PLUG{defaults::USE_IMIN_PLUG};
    bool USE_JMIN_PLUG{defaults::USE_JMIN_PLUG};
    bool USE_KMIN_PLUG{defaults::USE_KMIN_PLUG};

    bool USE_XMAX_PLUG{defaults::USE_XMAX_PLUG};
    bool USE_YMAX_PLUG{defaults::USE_YMAX_PLUG};
    bool USE_ZMAX_PLUG{defaults::USE_ZMAX_PLUG};
    bool USE_IMAX_PLUG{defaults::USE_IMAX_PLUG};
    bool USE_JMAX_PLUG{defaults::USE_JMAX_PLUG};
    bool USE_KMAX_PLUG{defaults::USE_KMAX_PLUG};

    bool X_MIN_ENDSTOP_INVERTING{defaults::X_MIN_ENDSTOP_INVERTING};
    bool Y_MIN_ENDSTOP_INVERTING{defaults::Y_MIN_ENDSTOP_INVERTING};
    bool Z_MIN_ENDSTOP_INVERTING{defaults::Z_MIN_ENDSTOP_INVERTING};
    bool I_MIN_ENDSTOP_INVERTING{defaults::I_MIN_ENDSTOP_INVERTING};
    bool J_MIN_ENDSTOP_INVERTING{defaults::J_MIN_ENDSTOP_INVERTING};
    bool K_MIN_ENDSTOP_INVERTING{defaults::K_MIN_ENDSTOP_INVERTING};

    bool X_MAX_ENDSTOP_INVERTING{defaults::X_MAX_ENDSTOP_INVERTING};
    bool Y_MAX_ENDSTOP_INVERTING{defaults::Y_MAX_ENDSTOP_INVERTING};
    bool Z_MAX_ENDSTOP_INVERTING{defaults::Z_MAX_ENDSTOP_INVERTING};
    bool I_MAX_ENDSTOP_INVERTING{defaults::I_MAX_ENDSTOP_INVERTING};
    bool J_MAX_ENDSTOP_INVERTING{defaults::J_MAX_ENDSTOP_INVERTING};
    bool K_MAX_ENDSTOP_INVERTING{defaults::K_MAX_ENDSTOP_INVERTING};

    bool Z_MIN_PROBE_ENDSTOP_INVERTING{defaults::Z_MIN_PROBE_ENDSTOP_INVERTING};

public:
    QJsonObject ToJson(void) const
    {
        QJsonObject json;

        json["SHOW_BOOTSCREEN"] = SHOW_BOOTSCREEN;
        json["SERIAL_PORT"] = SERIAL_PORT;
        json["BAUDRATE"] = BAUDRATE;
        json["CUSTOM_MACHINE_NAME"] = CUSTOM_MACHINE_NAME;
        json["STRING_CONFIG_H_AUTHOR"] = STRING_CONFIG_H_AUTHOR;
        json["MOTHERBOARD"] = MOTHERBOARD;
        json["LCD_DISPLAY"] = LCD_DISPLAY;
        json["EXTRUDERS"] = EXTRUDERS;
        json["DEFAULT_NOMINAL_FILAMENT_DIA"] = DEFAULT_NOMINAL_FILAMENT_DIA;
        json["X_BED_SIZE"] = X_BED_SIZE;
        json["Y_BED_SIZE"] = Y_BED_SIZE;

        json["USE_XMIN_PLUG"] = USE_XMIN_PLUG;
        json["USE_YMIN_PLUG"] = USE_YMIN_PLUG;
        json["USE_ZMIN_PLUG"] = USE_ZMIN_PLUG;
        json["USE_IMIN_PLUG"] = USE_IMIN_PLUG;
        json["USE_JMIN_PLUG"] = USE_JMIN_PLUG;
        json["USE_KMIN_PLUG"] = USE_KMIN_PLUG;

        json["USE_XMAX_PLUG"] = USE_XMAX_PLUG;
        json["USE_YMAX_PLUG"] = USE_YMAX_PLUG;
        json["USE_ZMAX_PLUG"] = USE_ZMAX_PLUG;
        json["USE_IMAX_PLUG"] = USE_IMAX_PLUG;
        json["USE_JMAX_PLUG"] = USE_JMAX_PLUG;
        json["USE_KMAX_PLUG"] = USE_KMAX_PLUG;

        json["X_MIN_ENDSTOP_INVERTING"] = X_MIN_ENDSTOP_INVERTING;
        json["Y_MIN_ENDSTOP_INVERTING"] = Y_MIN_ENDSTOP_INVERTING;
        json["Z_MIN_ENDSTOP_INVERTING"] = Z_MIN_ENDSTOP_INVERTING;
        json["I_MIN_ENDSTOP_INVERTING"] = I_MIN_ENDSTOP_INVERTING;
        json["J_MIN_ENDSTOP_INVERTING"] = J_MIN_ENDSTOP_INVERTING;
        json["K_MIN_ENDSTOP_INVERTING"] = K_MIN_ENDSTOP_INVERTING;

        json["X_MAX_ENDSTOP_INVERTING"] = X_MAX_ENDSTOP_INVERTING;
        json["Y_MAX_ENDSTOP_INVERTING"] = Y_MAX_ENDSTOP_INVERTING;
        json["Z_MAX_ENDSTOP_INVERTING"] = Z_MAX_ENDSTOP_INVERTING;
        json["I_MAX_ENDSTOP_INVERTING"] = I_MAX_ENDSTOP_INVERTING;
        json["J_MAX_ENDSTOP_INVERTING"] = J_MAX_ENDSTOP_INVERTING;
        json["K_MAX_ENDSTOP_INVERTING"] = K_MAX_ENDSTOP_INVERTING;

        json["Z_MIN_PROBE_ENDSTOP_INVERTING"] = Z_MIN_PROBE_ENDSTOP_INVERTING;

        return json;
    }
};

#endif // CONFIGURATION_H

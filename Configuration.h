#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QJsonObject>
#include <cstdint>
#include <string>

namespace disabled_values
{
static constexpr auto SERIAL_PORT_2{"No port selected"};
static constexpr auto BAUDRATE_2{"Use BAUDRATE"};
static constexpr auto SERIAL_PORT_3{"No port selected"};
static constexpr auto BAUDRATE_3{"Use BAUDRATE"};
}

namespace defaults
{
// Firmware
static constexpr auto STRING_CONFIG_H_AUTHOR{""};
static constexpr auto CUSTOM_VERSION_FILE{""};
static constexpr auto SHOW_BOOTSCREEN{true};
static constexpr auto SHOW_CUSTOM_BOOTSCREEN{false};
static constexpr auto CUSTOM_STATUS_SCREEN_IMAGE{false};

// Hardware
static constexpr auto MOTHERBOARD{"RAMPS 1.4 (Power outputs: Hotend, Fan, Bed) [BOARD_RAMPS_14_EFB]"};
static constexpr auto SERIAL_PORT{"0"};
static constexpr auto BAUDRATE{"250000"};
static constexpr auto BAUD_RATE_GCODE{false};
static constexpr auto SERIAL_PORT_2{disabled_values::SERIAL_PORT_2};
static constexpr auto BAUDRATE_2{disabled_values::BAUDRATE_2};
static constexpr auto SERIAL_PORT_3{disabled_values::SERIAL_PORT_3};
static constexpr auto BAUDRATE_3{disabled_values::BAUDRATE_3};
static constexpr auto BLUETOOTH{false};
static constexpr auto CUSTOM_MACHINE_NAME{""};
static constexpr auto MACHINE_UUID{""};

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

struct FirmwareConfiguration
{
    QString STRING_CONFIG_H_AUTHOR{defaults::STRING_CONFIG_H_AUTHOR};
    QString CUSTOM_VERSION_FILE{defaults::CUSTOM_VERSION_FILE};
    bool SHOW_BOOTSCREEN{defaults::SHOW_BOOTSCREEN};
    bool SHOW_CUSTOM_BOOTSCREEN{defaults::SHOW_CUSTOM_BOOTSCREEN};
    bool CUSTOM_STATUS_SCREEN_IMAGE{defaults::CUSTOM_STATUS_SCREEN_IMAGE};

public:
    QJsonObject ToJson(void) const
    {
        QJsonObject json;

        json["STRING_CONFIG_H_AUTHOR"] = STRING_CONFIG_H_AUTHOR;
        json["CUSTOM_VERSION_FILE"] = CUSTOM_VERSION_FILE;
        json["SHOW_BOOTSCREEN"] = SHOW_BOOTSCREEN;
        json["SHOW_CUSTOM_BOOTSCREEN"] = SHOW_CUSTOM_BOOTSCREEN;
        json["CUSTOM_STATUS_SCREEN_IMAGE"] = CUSTOM_STATUS_SCREEN_IMAGE;

        return json;
    }
};

struct HardwareConfiguration
{
    QString MOTHERBOARD{defaults::MOTHERBOARD};
    QString SERIAL_PORT{defaults::SERIAL_PORT};
    QString BAUDRATE{defaults::BAUDRATE};
    bool BAUD_RATE_GCODE{defaults::BAUD_RATE_GCODE};
    QString SERIAL_PORT_2{defaults::SERIAL_PORT_2};
    QString BAUDRATE_2{defaults::BAUDRATE_2};
    QString SERIAL_PORT_3{defaults::SERIAL_PORT_3};
    QString BAUDRATE_3{defaults::BAUDRATE_3};
    bool BLUETOOTH{defaults::BLUETOOTH};
    QString CUSTOM_MACHINE_NAME{defaults::CUSTOM_MACHINE_NAME};
    QString MACHINE_UUID{defaults::MACHINE_UUID};

public:
    QJsonObject ToJson(void) const
    {
        QJsonObject json;

        json["MOTHERBOARD"] = MOTHERBOARD;
        json["SERIAL_PORT"] = SERIAL_PORT;
        json["BAUDRATE"] = BAUDRATE;
        json["BAUD_RATE_GCODE"] = BAUD_RATE_GCODE;
        json["SERIAL_PORT_2"] = SERIAL_PORT_2;
        json["BAUDRATE_2"] = BAUDRATE_2;
        json["SERIAL_PORT_3"] = SERIAL_PORT_3;
        json["BAUDRATE_3"] = BAUDRATE_3;
        json["BLUETOOTH"] = BLUETOOTH;
        json["CUSTOM_MACHINE_NAME"] = CUSTOM_MACHINE_NAME;
        json["MACHINE_UUID"] = MACHINE_UUID;

        return json;
    }
};

struct Configuration
{
    FirmwareConfiguration firmware;
    HardwareConfiguration hardware;

    /*
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

    bool Z_MIN_PROBE_ENDSTOP_INVERTING{defaults::Z_MIN_PROBE_ENDSTOP_INVERTING};*/

public:
    QJsonObject ToJson(void) const
    {
        QJsonObject json;

        json["firmware"] = firmware.ToJson();
        json["hardware"] = hardware.ToJson();

        return json;
    }
};

#endif // CONFIGURATION_H

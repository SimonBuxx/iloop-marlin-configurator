/*!
 * \file Configuration.h
 * \brief The configuration file contains global constants
 * \author Simon Buchholz
 * \copyright Copyright (c) 2023, Simon Buchholz
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QJsonObject>
#include <cstdint>
#include <string>

/* Contains special values that indicates that the line in the
 * generated config should be commented out (bool flags are always commented out when false)
 */
namespace disabled_values
{
static constexpr auto SERIAL_PORT_2{"No port selected"};
static constexpr auto BAUDRATE_2{"Use BAUDRATE"};
static constexpr auto SERIAL_PORT_3{"No port selected"};
static constexpr auto BAUDRATE_3{"Use BAUDRATE"};
}

// Contains default values of all configuration parameters
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

// Extruders
static constexpr auto EXTRUDERS{1};

// Power Supply
static constexpr auto PSU_CONTROL{false};
static constexpr auto PSU_NAME{""};
static constexpr auto MKS_PWC{false};
static constexpr auto PS_OFF_CONFIRM{false};
static constexpr auto PS_OFF_SOUND{false};
static constexpr auto PSU_ACTIVE_STATE{"LOW (for ATX)"};
static constexpr auto PSU_DEFAULT_OFF{false};
static constexpr auto PSU_POWERUP_DELAY{250};
static constexpr auto LED_POWEROFF_TIMEOUT{10000};
static constexpr auto POWER_OFF_TIMER{false};
static constexpr auto POWER_OFF_WAIT_FOR_COOLDOWN{false};
static constexpr auto PSU_POWERUP_GCODE{""};
static constexpr auto PSU_POWEROFF_GCODE{""};
static constexpr auto AUTO_POWER_CONTROL{false};
static constexpr auto AUTO_POWER_FANS{true};
static constexpr auto AUTO_POWER_E_FANS{true};
static constexpr auto AUTO_POWER_CONTROLLERFAN{true};
static constexpr auto AUTO_POWER_CHAMBER_FAN{true};
static constexpr auto AUTO_POWER_COOLER_FAN{true};
static constexpr auto POWER_TIMEOUT{30};
static constexpr auto POWER_OFF_DELAY{60};
static constexpr auto AUTO_POWER_E_TEMP{50};
static constexpr auto AUTO_POWER_CHAMBER_TEMP{30};
static constexpr auto AUTO_POWER_COOLER_TEMP{26};

// Legacy
static constexpr auto LCD_DISPLAY{"REPRAP_DISCOUNT_SMART_CONTROLLER"};
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

///
/// \brief The FirmwareConfiguration struct contains firmware configurations
///
struct FirmwareConfiguration
{
    QString STRING_CONFIG_H_AUTHOR{defaults::STRING_CONFIG_H_AUTHOR};
    QString CUSTOM_VERSION_FILE{defaults::CUSTOM_VERSION_FILE};
    bool SHOW_BOOTSCREEN{defaults::SHOW_BOOTSCREEN};
    bool SHOW_CUSTOM_BOOTSCREEN{defaults::SHOW_CUSTOM_BOOTSCREEN};
    bool CUSTOM_STATUS_SCREEN_IMAGE{defaults::CUSTOM_STATUS_SCREEN_IMAGE};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
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

///
/// \brief The HardwareConfiguration struct contains hardware configurations
///
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
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
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

///
/// \brief The ExtruderConfiguration struct contains extruder configurations
///
struct ExtruderConfiguration
{
    int32_t EXTRUDERS{defaults::EXTRUDERS};
public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const
    {
        QJsonObject json;

        json["EXTRUDERS"] = EXTRUDERS;

        return json;
    }
};

///
/// \brief The PowerSupplyConfiguration struct contains power supply configurations
///
struct PowerSupplyConfiguration
{
    bool PSU_CONTROL{defaults::PSU_CONTROL};
    QString PSU_NAME{defaults::PSU_NAME};
    bool MKS_PWC{defaults::MKS_PWC};
    bool PS_OFF_CONFIRM{defaults::PS_OFF_CONFIRM};
    bool PS_OFF_SOUND{defaults::PS_OFF_SOUND};
    QString PSU_ACTIVE_STATE{defaults::PSU_ACTIVE_STATE};
    bool PSU_DEFAULT_OFF{defaults::PSU_DEFAULT_OFF};
    int32_t PSU_POWERUP_DELAY{defaults::PSU_POWERUP_DELAY};
    int32_t LED_POWEROFF_TIMEOUT{defaults::LED_POWEROFF_TIMEOUT};
    bool POWER_OFF_TIMER{defaults::POWER_OFF_TIMER};
    bool POWER_OFF_WAIT_FOR_COOLDOWN{defaults::POWER_OFF_WAIT_FOR_COOLDOWN};
    QString PSU_POWERUP_GCODE{defaults::PSU_POWERUP_GCODE};
    QString PSU_POWEROFF_GCODE{defaults::PSU_POWEROFF_GCODE};
    bool AUTO_POWER_CONTROL{defaults::AUTO_POWER_CONTROL};
    bool AUTO_POWER_FANS{defaults::AUTO_POWER_FANS};
    bool AUTO_POWER_E_FANS{defaults::AUTO_POWER_E_FANS};
    bool AUTO_POWER_CONTROLLERFAN{defaults::AUTO_POWER_CONTROLLERFAN};
    bool AUTO_POWER_CHAMBER_FAN{defaults::AUTO_POWER_CHAMBER_FAN};
    bool AUTO_POWER_COOLER_FAN{defaults::AUTO_POWER_COOLER_FAN};
    int32_t POWER_TIMEOUT{defaults::POWER_TIMEOUT};
    int32_t POWER_OFF_DELAY{defaults::POWER_OFF_DELAY};
    int32_t AUTO_POWER_E_TEMP{defaults::AUTO_POWER_E_TEMP};
    int32_t AUTO_POWER_CHAMBER_TEMP{defaults::AUTO_POWER_CHAMBER_TEMP};
    int32_t AUTO_POWER_COOLER_TEMP{defaults::AUTO_POWER_COOLER_TEMP};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const
    {
        QJsonObject json;

        json["PSU_CONTROL"] = PSU_CONTROL;
        json["PSU_NAME"] = PSU_NAME;
        json["MKS_PWC"] = MKS_PWC;
        json["PS_OFF_CONFIRM"] = PS_OFF_CONFIRM;
        json["PS_OFF_SOUND"] = PS_OFF_SOUND;
        json["PSU_ACTIVE_STATE"] = PSU_ACTIVE_STATE;
        json["PSU_DEFAULT_OFF"] = PSU_DEFAULT_OFF;
        json["PSU_POWERUP_DELAY"] = PSU_POWERUP_DELAY;
        json["LED_POWEROFF_TIMEOUT"] = LED_POWEROFF_TIMEOUT;
        json["POWER_OFF_TIMER"] = POWER_OFF_TIMER;
        json["POWER_OFF_WAIT_FOR_COOLDOWN"] = POWER_OFF_WAIT_FOR_COOLDOWN;
        json["PSU_POWERUP_GCODE"] = PSU_POWERUP_GCODE;
        json["PSU_POWEROFF_GCODE"] = PSU_POWEROFF_GCODE;
        json["AUTO_POWER_CONTROL"] = AUTO_POWER_CONTROL;
        json["AUTO_POWER_FANS"] = AUTO_POWER_FANS;
        json["AUTO_POWER_E_FANS"] = AUTO_POWER_E_FANS;
        json["AUTO_POWER_CONTROLLERFAN"] = AUTO_POWER_CONTROLLERFAN;
        json["AUTO_POWER_CHAMBER_FAN"] = AUTO_POWER_CHAMBER_FAN;
        json["AUTO_POWER_COOLER_FAN"] = AUTO_POWER_COOLER_FAN;
        json["POWER_TIMEOUT"] = POWER_TIMEOUT;
        json["POWER_OFF_DELAY"] = POWER_OFF_DELAY;
        json["AUTO_POWER_E_TEMP"] = AUTO_POWER_E_TEMP;
        json["AUTO_POWER_CHAMBER_TEMP"] = AUTO_POWER_CHAMBER_TEMP;
        json["AUTO_POWER_COOLER_TEMP"] = AUTO_POWER_COOLER_TEMP;

        return json;
    }
};

///
/// \brief The Configuration struct contains a complete Marlin configuration
///
struct Configuration
{
    FirmwareConfiguration firmware;
    HardwareConfiguration hardware;
    ExtruderConfiguration extruder;
    PowerSupplyConfiguration powerSupply;

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const
    {
        QJsonObject json;

        json["firmware"] = firmware.ToJson();
        json["hardware"] = hardware.ToJson();
        json["extruder"] = extruder.ToJson();
        json["powerSupply"] = powerSupply.ToJson();

        return json;
    }
};

#endif // CONFIGURATION_H

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

static constexpr auto SW_VERSION{"0.1.0"};
static constexpr auto MARLIN_VERSION{"2.1.2"};

static constexpr auto TEMPLATE_PATH{":/configuration_template.txt"};
static constexpr auto FIRMWARE_TEMPLATE_PATH{":/firmware_template.txt"};
static constexpr auto HARDWARE_TEMPLATE_PATH{":/hardware_template.txt"};
static constexpr auto EXTRUDER_TEMPLATE_PATH{":/extruder_template.txt"};
static constexpr auto POWERSUPPLY_TEMPLATE_PATH{":/powersupply_template.txt"};

// Contains default values of all configuration parameters
namespace defaults
{
// Firmware Info
static constexpr auto STRING_CONFIG_H_AUTHOR{""};
static constexpr auto CUSTOM_VERSION_FILE{""};
static constexpr auto SHOW_BOOTSCREEN{true};
static constexpr auto SHOW_CUSTOM_BOOTSCREEN{false};
static constexpr auto CUSTOM_STATUS_SCREEN_IMAGE{false};

static constexpr auto ENABLE_STRING_CONFIG_H_AUTHOR{false};
static constexpr auto ENABLE_CUSTOM_VERSION_FILE{false};

// Hardware Info
static constexpr auto MOTHERBOARD{"RAMPS 1.4 (Power outputs: Hotend, Fan, Bed) [BOARD_RAMPS_14_EFB]"};
static constexpr auto SERIAL_PORT{"0"};
static constexpr auto BAUDRATE{"250000"};
static constexpr auto BAUD_RATE_GCODE{false};
static constexpr auto SERIAL_PORT_2{"-1"};
static constexpr auto BAUDRATE_2{"250000"};
static constexpr auto SERIAL_PORT_3{"1"};
static constexpr auto BAUDRATE_3{"250000"};
static constexpr auto BLUETOOTH{false};
static constexpr auto CUSTOM_MACHINE_NAME{""};
static constexpr auto MACHINE_UUID{""};

static constexpr auto ENABLE_SERIAL_PORT_2{false};
static constexpr auto ENABLE_BAUDRATE_2{false};
static constexpr auto ENABLE_SERIAL_PORT_3{false};
static constexpr auto ENABLE_BAUDRATE_3{false};
static constexpr auto ENABLE_CUSTOM_MACHINE_NAME{false};
static constexpr auto ENABLE_MACHINE_UUID{false};

// Extruder Info
static constexpr auto EXTRUDERS{1};
static constexpr auto DEFAULT_NOMINAL_FILAMENT_DIA{1.75f};
static constexpr auto SINGLENOZZLE{false};
static constexpr auto SINGLENOZZLE_STANDBY_TEMP{false};
static constexpr auto SINGLENOZZLE_STANDBY_FAN{false};
static constexpr auto MMU_MODEL{"Průša MMU2 [PRUSA_MMU2]"};
static constexpr auto SWITCHING_EXTRUDER{false};
static constexpr auto SWITCHING_EXTRUDER_SERVO_NR{0};
static constexpr auto SWITCHING_EXTRUDER_SERVO_ANGLES_E0{0};
static constexpr auto SWITCHING_EXTRUDER_SERVO_ANGLES_E1{90};
static constexpr auto SWITCHING_EXTRUDER_SERVO_ANGLES_E2{0};
static constexpr auto SWITCHING_EXTRUDER_SERVO_ANGLES_E3{0};
static constexpr auto SWITCHING_EXTRUDER_E23_SERVO_NR{1};
static constexpr auto SWITCHING_NOZZLE{false};
static constexpr auto SWITCHING_NOZZLE_SERVO_NR{0};
static constexpr auto SWITCHING_NOZZLE_E1_SERVO_NR{1};
static constexpr auto SWITCHING_NOZZLE_SERVO_ANGLES_E0{0};
static constexpr auto SWITCHING_NOZZLE_SERVO_ANGLES_E1{90};
static constexpr auto SWITCHING_NOZZLE_SERVO_DWELL{2500};
static constexpr auto PARKING_EXTRUDER{false};
static constexpr auto MAGNETIC_PARKING_EXTRUDER{false};
static constexpr auto PARKING_EXTRUDER_PARKING_X_0{-78};
static constexpr auto PARKING_EXTRUDER_PARKING_X_1{184};
static constexpr auto PARKING_EXTRUDER_GRAB_DISTANCE{1};
static constexpr auto PARKING_EXTRUDER_SOLENOIDS_INVERT{false};
static constexpr auto PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE{"LOW"};
static constexpr auto PARKING_EXTRUDER_SOLENOIDS_DELAY{250};
static constexpr auto MANUAL_SOLENOID_CONTROL{false};
static constexpr auto MPE_FAST_SPEED{9000};
static constexpr auto MPE_SLOW_SPEED{4500};
static constexpr auto MPE_TRAVEL_DISTANCE{10};
static constexpr auto MPE_COMPENSATION{"0"};
static constexpr auto SWITCHING_TOOLHEAD{false};
static constexpr auto MAGNETIC_SWITCHING_TOOLHEAD{false};
static constexpr auto ELECTROMAGNETIC_SWITCHING_TOOLHEAD{false};
static constexpr auto ENABLE_MMU_MODEL{false};
static constexpr auto ENABLE_SWITCHING_EXTRUDER_SERVO_ANGLES_E23{false};
static constexpr auto ENABLE_SWITCHING_NOZZLE_E1_SERVO_NR{false};
static constexpr auto ENABLE_PARKING_EXTRUDER_SOLENOIDS_DELAY{false};

// Power Supply
static constexpr auto PSU_CONTROL{false};
static constexpr auto PSU_NAME{""};
static constexpr auto MKS_PWC{false};
static constexpr auto PS_OFF_CONFIRM{false};
static constexpr auto PS_OFF_SOUND{false};
static constexpr auto PSU_ACTIVE_STATE{"LOW"};
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

static constexpr auto ENABLE_PSU_NAME{false};
static constexpr auto ENABLE_PSU_POWERUP_DELAY{false};
static constexpr auto ENABLE_LED_POWEROFF_TIMEOUT{false};
static constexpr auto ENABLE_PSU_POWERUP_GCODE{false};
static constexpr auto ENABLE_PSU_POWEROFF_GCODE{false};
static constexpr auto ENABLE_POWER_TIMEOUT{false};
static constexpr auto ENABLE_POWER_OFF_DELAY{false};
static constexpr auto ENABLE_AUTO_POWER_E_TEMP{false};
static constexpr auto ENABLE_AUTO_POWER_CHAMBER_TEMP{false};
static constexpr auto ENABLE_AUTO_POWER_COOLER_TEMP{false};

// Legacy
static constexpr auto LCD_DISPLAY{"REPRAP_DISCOUNT_SMART_CONTROLLER"};
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

struct PageConfiguration
{
    virtual QJsonObject ToJson(void) const = 0;
};

///
/// \brief The FirmwareConfiguration struct contains firmware configurations
///
struct FirmwareConfiguration : public PageConfiguration
{
    QString STRING_CONFIG_H_AUTHOR{defaults::STRING_CONFIG_H_AUTHOR};
    QString CUSTOM_VERSION_FILE{defaults::CUSTOM_VERSION_FILE};
    bool SHOW_BOOTSCREEN{defaults::SHOW_BOOTSCREEN};
    bool SHOW_CUSTOM_BOOTSCREEN{defaults::SHOW_CUSTOM_BOOTSCREEN};
    bool CUSTOM_STATUS_SCREEN_IMAGE{defaults::CUSTOM_STATUS_SCREEN_IMAGE};

    bool ENABLE_STRING_CONFIG_H_AUTHOR{defaults::ENABLE_STRING_CONFIG_H_AUTHOR};
    bool ENABLE_CUSTOM_VERSION_FILE{defaults::ENABLE_CUSTOM_VERSION_FILE};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["STRING_CONFIG_H_AUTHOR"] = STRING_CONFIG_H_AUTHOR;
        json["CUSTOM_VERSION_FILE"] = CUSTOM_VERSION_FILE;
        json["SHOW_BOOTSCREEN"] = SHOW_BOOTSCREEN;
        json["SHOW_CUSTOM_BOOTSCREEN"] = SHOW_CUSTOM_BOOTSCREEN;
        json["CUSTOM_STATUS_SCREEN_IMAGE"] = CUSTOM_STATUS_SCREEN_IMAGE;

        json["ENABLE_STRING_CONFIG_H_AUTHOR"] = ENABLE_STRING_CONFIG_H_AUTHOR;
        json["ENABLE_CUSTOM_VERSION_FILE"] = ENABLE_CUSTOM_VERSION_FILE;

        return json;
    }
};

///
/// \brief The HardwareConfiguration struct contains hardware configurations
///
struct HardwareConfiguration : public PageConfiguration
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

    bool ENABLE_SERIAL_PORT_2{defaults::ENABLE_SERIAL_PORT_2};
    bool ENABLE_BAUDRATE_2{defaults::ENABLE_BAUDRATE_2};
    bool ENABLE_SERIAL_PORT_3{defaults::ENABLE_SERIAL_PORT_3};
    bool ENABLE_BAUDRATE_3{defaults::ENABLE_BAUDRATE_3};
    bool ENABLE_CUSTOM_MACHINE_NAME{defaults::ENABLE_CUSTOM_MACHINE_NAME};
    bool ENABLE_MACHINE_UUID{defaults::ENABLE_MACHINE_UUID};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
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

        json["ENABLE_SERIAL_PORT_2"] = ENABLE_SERIAL_PORT_2;
        json["ENABLE_BAUDRATE_2"] = ENABLE_BAUDRATE_2;
        json["ENABLE_SERIAL_PORT_3"] = ENABLE_SERIAL_PORT_3;
        json["ENABLE_BAUDRATE_3"] = ENABLE_BAUDRATE_3;
        json["ENABLE_CUSTOM_MACHINE_NAME"] = ENABLE_CUSTOM_MACHINE_NAME;
        json["ENABLE_MACHINE_UUID"] = ENABLE_MACHINE_UUID;

        return json;
    }
};

///
/// \brief The ExtruderConfiguration struct contains extruder configurations
///
struct ExtruderConfiguration : public PageConfiguration
{
    int32_t EXTRUDERS{defaults::EXTRUDERS};
    double DEFAULT_NOMINAL_FILAMENT_DIA{defaults::DEFAULT_NOMINAL_FILAMENT_DIA};
    bool SINGLENOZZLE{defaults::SINGLENOZZLE};
    bool SINGLENOZZLE_STANDBY_TEMP{defaults::SINGLENOZZLE_STANDBY_TEMP};
    bool SINGLENOZZLE_STANDBY_FAN{defaults::SINGLENOZZLE_STANDBY_FAN};
    QString MMU_MODEL{defaults::MMU_MODEL};
    bool SWITCHING_EXTRUDER{defaults::SWITCHING_EXTRUDER};
    int32_t SWITCHING_EXTRUDER_SERVO_NR{defaults::SWITCHING_EXTRUDER_SERVO_NR};
    int32_t SWITCHING_EXTRUDER_SERVO_ANGLES_E0{defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E0};
    int32_t SWITCHING_EXTRUDER_SERVO_ANGLES_E1{defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E1};
    int32_t SWITCHING_EXTRUDER_SERVO_ANGLES_E2{defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E2};
    int32_t SWITCHING_EXTRUDER_SERVO_ANGLES_E3{defaults::SWITCHING_EXTRUDER_SERVO_ANGLES_E3};
    int32_t SWITCHING_EXTRUDER_E23_SERVO_NR{defaults::SWITCHING_EXTRUDER_E23_SERVO_NR};
    bool SWITCHING_NOZZLE{defaults::SWITCHING_NOZZLE};
    int32_t SWITCHING_NOZZLE_SERVO_NR{defaults::SWITCHING_NOZZLE_SERVO_NR};
    int32_t SWITCHING_NOZZLE_E1_SERVO_NR{defaults::SWITCHING_NOZZLE_E1_SERVO_NR};
    int32_t SWITCHING_NOZZLE_SERVO_ANGLES_E0{defaults::SWITCHING_NOZZLE_SERVO_ANGLES_E0};
    int32_t SWITCHING_NOZZLE_SERVO_ANGLES_E1{defaults::SWITCHING_NOZZLE_SERVO_ANGLES_E1};
    int32_t SWITCHING_NOZZLE_SERVO_DWELL{defaults::SWITCHING_NOZZLE_SERVO_DWELL};
    bool PARKING_EXTRUDER{defaults::PARKING_EXTRUDER};
    bool MAGNETIC_PARKING_EXTRUDER{defaults::MAGNETIC_PARKING_EXTRUDER};
    int32_t PARKING_EXTRUDER_PARKING_X_0{defaults::PARKING_EXTRUDER_PARKING_X_0};
    int32_t PARKING_EXTRUDER_PARKING_X_1{defaults::PARKING_EXTRUDER_PARKING_X_1};
    int32_t PARKING_EXTRUDER_GRAB_DISTANCE{defaults::PARKING_EXTRUDER_GRAB_DISTANCE};
    bool PARKING_EXTRUDER_SOLENOIDS_INVERT{defaults::PARKING_EXTRUDER_SOLENOIDS_INVERT};
    QString PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE{defaults::PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE};
    int32_t PARKING_EXTRUDER_SOLENOIDS_DELAY{defaults::PARKING_EXTRUDER_SOLENOIDS_DELAY};
    bool MANUAL_SOLENOID_CONTROL{defaults::MANUAL_SOLENOID_CONTROL};
    int32_t MPE_FAST_SPEED{defaults::MPE_FAST_SPEED};
    int32_t MPE_SLOW_SPEED{defaults::MPE_SLOW_SPEED};
    int32_t MPE_TRAVEL_DISTANCE{defaults::MPE_TRAVEL_DISTANCE};
    QString MPE_COMPENSATION{defaults::MPE_COMPENSATION};
    bool SWITCHING_TOOLHEAD{defaults::SWITCHING_TOOLHEAD};
    bool MAGNETIC_SWITCHING_TOOLHEAD{defaults::MAGNETIC_SWITCHING_TOOLHEAD};
    bool ELECTROMAGNETIC_SWITCHING_TOOLHEAD{defaults::ELECTROMAGNETIC_SWITCHING_TOOLHEAD};
    bool ENABLE_MMU_MODEL{defaults::ENABLE_MMU_MODEL};
    bool ENABLE_SWITCHING_EXTRUDER_SERVO_ANGLES_E23{defaults::ENABLE_SWITCHING_EXTRUDER_SERVO_ANGLES_E23};
    bool ENABLE_SWITCHING_NOZZLE_E1_SERVO_NR{defaults::ENABLE_SWITCHING_NOZZLE_E1_SERVO_NR};
    bool ENABLE_PARKING_EXTRUDER_SOLENOIDS_DELAY{defaults::ENABLE_PARKING_EXTRUDER_SOLENOIDS_DELAY};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["EXTRUDERS"] = EXTRUDERS;
        json["DEFAULT_NOMINAL_FILAMENT_DIA"] = DEFAULT_NOMINAL_FILAMENT_DIA;
        json["SINGLENOZZLE"] = SINGLENOZZLE;
        json["SINGLENOZZLE_STANDBY_TEMP"] = SINGLENOZZLE_STANDBY_TEMP;
        json["SINGLENOZZLE_STANDBY_FAN"] = SINGLENOZZLE_STANDBY_FAN;
        json["MMU_MODEL"] = MMU_MODEL;
        json["SWITCHING_EXTRUDER"] = SWITCHING_EXTRUDER;
        json["SWITCHING_EXTRUDER_SERVO_NR"] = SWITCHING_EXTRUDER_SERVO_NR;
        json["SWITCHING_EXTRUDER_SERVO_ANGLES_E0"] = SWITCHING_EXTRUDER_SERVO_ANGLES_E0;
        json["SWITCHING_EXTRUDER_SERVO_ANGLES_E1"] = SWITCHING_EXTRUDER_SERVO_ANGLES_E1;
        json["SWITCHING_EXTRUDER_SERVO_ANGLES_E2"] = SWITCHING_EXTRUDER_SERVO_ANGLES_E2;
        json["SWITCHING_EXTRUDER_SERVO_ANGLES_E3"] = SWITCHING_EXTRUDER_SERVO_ANGLES_E3;
        json["SWITCHING_EXTRUDER_E23_SERVO_NR"] = SWITCHING_EXTRUDER_E23_SERVO_NR;
        json["SWITCHING_NOZZLE"] = SWITCHING_NOZZLE;
        json["SWITCHING_NOZZLE_SERVO_NR"] = SWITCHING_NOZZLE_SERVO_NR;
        json["SWITCHING_NOZZLE_E1_SERVO_NR"] = SWITCHING_NOZZLE_E1_SERVO_NR;
        json["SWITCHING_NOZZLE_SERVO_ANGLES_E0"] = SWITCHING_NOZZLE_SERVO_ANGLES_E0;
        json["SWITCHING_NOZZLE_SERVO_ANGLES_E1"] = SWITCHING_NOZZLE_SERVO_ANGLES_E1;
        json["SWITCHING_NOZZLE_SERVO_DWELL"] = SWITCHING_NOZZLE_SERVO_DWELL;
        json["PARKING_EXTRUDER"] = PARKING_EXTRUDER;
        json["MAGNETIC_PARKING_EXTRUDER"] = MAGNETIC_PARKING_EXTRUDER;
        json["PARKING_EXTRUDER_PARKING_X_0"] = PARKING_EXTRUDER_PARKING_X_0;
        json["PARKING_EXTRUDER_PARKING_X_1"] = PARKING_EXTRUDER_PARKING_X_1;
        json["PARKING_EXTRUDER_GRAB_DISTANCE"] = PARKING_EXTRUDER_GRAB_DISTANCE;
        json["PARKING_EXTRUDER_SOLENOIDS_INVERT"] = PARKING_EXTRUDER_SOLENOIDS_INVERT;
        json["PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE"] = PARKING_EXTRUDER_SOLENOIDS_PINS_ACTIVE;
        json["PARKING_EXTRUDER_SOLENOIDS_DELAY"] = PARKING_EXTRUDER_SOLENOIDS_DELAY;
        json["MANUAL_SOLENOID_CONTROL"] = MANUAL_SOLENOID_CONTROL;
        json["MPE_FAST_SPEED"] = MPE_FAST_SPEED;
        json["MPE_SLOW_SPEED"] = MPE_SLOW_SPEED;
        json["MPE_TRAVEL_DISTANCE"] = MPE_TRAVEL_DISTANCE;
        json["MPE_COMPENSATION"] = MPE_COMPENSATION;
        json["SWITCHING_TOOLHEAD"] = SWITCHING_TOOLHEAD;
        json["MAGNETIC_SWITCHING_TOOLHEAD"] = MAGNETIC_SWITCHING_TOOLHEAD;
        json["ELECTROMAGNETIC_SWITCHING_TOOLHEAD"] = ELECTROMAGNETIC_SWITCHING_TOOLHEAD;
        json["ENABLE_MMU_MODEL"] = ENABLE_MMU_MODEL;
        json["ENABLE_SWITCHING_EXTRUDER_SERVO_ANGLES_E23"] = ENABLE_SWITCHING_EXTRUDER_SERVO_ANGLES_E23;
        json["ENABLE_SWITCHING_NOZZLE_E1_SERVO_NR"] = ENABLE_SWITCHING_NOZZLE_E1_SERVO_NR;
        json["ENABLE_PARKING_EXTRUDER_SOLENOIDS_DELAY"] = ENABLE_PARKING_EXTRUDER_SOLENOIDS_DELAY;

        return json;
    }
};

///
/// \brief The PowerSupplyConfiguration struct contains power supply configurations
///
struct PowerSupplyConfiguration : public PageConfiguration
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

    bool ENABLE_PSU_NAME{defaults::ENABLE_PSU_NAME};
    bool ENABLE_PSU_POWERUP_DELAY{defaults::ENABLE_PSU_POWERUP_DELAY};
    bool ENABLE_LED_POWEROFF_TIMEOUT{defaults::ENABLE_LED_POWEROFF_TIMEOUT};
    bool ENABLE_PSU_POWERUP_GCODE{defaults::ENABLE_PSU_POWERUP_GCODE};
    bool ENABLE_PSU_POWEROFF_GCODE{defaults::ENABLE_PSU_POWEROFF_GCODE};
    bool ENABLE_POWER_TIMEOUT{defaults::ENABLE_POWER_TIMEOUT};
    bool ENABLE_POWER_OFF_DELAY{defaults::ENABLE_POWER_OFF_DELAY};
    bool ENABLE_AUTO_POWER_E_TEMP{defaults::ENABLE_AUTO_POWER_E_TEMP};
    bool ENABLE_AUTO_POWER_CHAMBER_TEMP{defaults::ENABLE_AUTO_POWER_CHAMBER_TEMP};
    bool ENABLE_AUTO_POWER_COOLER_TEMP{defaults::ENABLE_AUTO_POWER_COOLER_TEMP};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
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

        json["ENABLE_PSU_NAME"] = ENABLE_PSU_NAME;
        json["ENABLE_PSU_POWERUP_DELAY"] = ENABLE_PSU_POWERUP_DELAY;
        json["ENABLE_LED_POWEROFF_TIMEOUT"] = ENABLE_LED_POWEROFF_TIMEOUT;
        json["ENABLE_PSU_POWERUP_GCODE"] = ENABLE_PSU_POWERUP_GCODE;
        json["ENABLE_PSU_POWEROFF_GCODE"] = ENABLE_PSU_POWEROFF_GCODE;
        json["ENABLE_POWER_TIMEOUT"] = ENABLE_POWER_TIMEOUT;
        json["ENABLE_POWER_OFF_DELAY"] = ENABLE_POWER_OFF_DELAY;
        json["ENABLE_AUTO_POWER_E_TEMP"] = ENABLE_AUTO_POWER_E_TEMP;
        json["ENABLE_AUTO_POWER_CHAMBER_TEMP"] = ENABLE_AUTO_POWER_CHAMBER_TEMP;
        json["ENABLE_AUTO_POWER_COOLER_TEMP"] = ENABLE_AUTO_POWER_COOLER_TEMP;

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

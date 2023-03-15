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
static constexpr auto THERMALSETTINGS_TEMPLATE_PATH{":/thermalsettings_template.txt"};
static constexpr auto KINEMATICS_TEMPLATE_PATH{":/kinematics_template.txt"};
static constexpr auto ENDSTOPS_TEMPLATE_PATH{":/endstops_template.txt"};
static constexpr auto MOVEMENT_TEMPLATE_PATH{":/movement_template.txt"};
static constexpr auto Z_PROBE_OPTIONS_TEMPLATE_PATH{":/z_probe_options_template.txt"};
static constexpr auto STEPPER_DRIVERS_TEMPLATE_PATH{":/stepper_drivers_template.txt"};
static constexpr auto HOMING_AND_BOUNDS_TEMPLATE_PATH{":/homing_and_bounds_template.txt"};
static constexpr auto FILAMENT_RUNOUT_SENSOR_TEMPLATE_PATH{":/filament_runout_sensor_template.txt"};
static constexpr auto BED_LEVELING_TEMPLATE_PATH{":/bed_leveling_template.txt"};
static constexpr auto HOMING_OPTIONS_TEMPLATE_PATH{":/homing_options_template.txt"};
static constexpr auto ADDITIONAL_FEATURES_TEMPLATE_PATH{":/additional_features_template.txt"};
static constexpr auto USER_INTERFACE_LANGUAGE_TEMPLATE_PATH{":/user_interface_language_template.txt"};
static constexpr auto SD_CARD_TEMPLATE_PATH{":/sd_card_template.txt"};
static constexpr auto LCD_MENU_ITEMS_TEMPLATE_PATH{":/lcd_menu_items_template.txt"};
static constexpr auto ENCODER_TEMPLATE_PATH{":/encoder_template.txt"};
static constexpr auto SPEAKER_TEMPLATE_PATH{":/speaker_template.txt"};
static constexpr auto LCD_CONTROLLER_TEMPLATE_PATH{":/lcd_controller_template.txt"};
static constexpr auto EXTRA_FEATURES_TEMPLATE_PATH{":/extra_features_template.txt"};

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
static constexpr auto ENVIRONMENT{"mega2560"};
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
static constexpr auto SWITCHING_TOOLHEAD_Y_POS{235};
static constexpr auto SWITCHING_TOOLHEAD_Y_SECURITY{10};
static constexpr auto SWITCHING_TOOLHEAD_Y_CLEAR{60};
static constexpr auto SWITCHING_TOOLHEAD_X_POS0{215};
static constexpr auto SWITCHING_TOOLHEAD_X_POS1{0};
static constexpr auto SWITCHING_TOOLHEAD_SERVO_NR{2};
static constexpr auto SWITCHING_TOOLHEAD_SERVO_ANGLES0{0};
static constexpr auto SWITCHING_TOOLHEAD_SERVO_ANGLES1{180};
static constexpr auto SWITCHING_TOOLHEAD_Y_RELEASE{5};
static constexpr auto SWITCHING_TOOLHEAD_X_SECURITY_T0{90};
static constexpr auto SWITCHING_TOOLHEAD_X_SECURITY_T1{150};
static constexpr auto PRIME_BEFORE_REMOVE{false};
static constexpr auto SWITCHING_TOOLHEAD_PRIME_MM{20};
static constexpr auto SWITCHING_TOOLHEAD_RETRACT_MM{10};
static constexpr auto SWITCHING_TOOLHEAD_PRIME_FEEDRATE{300};
static constexpr auto SWITCHING_TOOLHEAD_RETRACT_FEEDRATE{2400};
static constexpr auto SWITCHING_TOOLHEAD_Z_HOP{2};
static constexpr auto MIXING_EXTRUDER{false};
static constexpr auto MIXING_STEPPERS{2};
static constexpr auto MIXING_VIRTUAL_TOOLS{16};
static constexpr auto DIRECT_MIXING_IN_G1{false};
static constexpr auto GRADIENT_MIX{false};
static constexpr auto MIXING_PRESETS{false};
static constexpr auto GRADIENT_VTOOL{false};
static constexpr auto HOTEND_OFFSET_X{"{ 0.0, 20.00 }"};
static constexpr auto HOTEND_OFFSET_Y{"{ 0.0, 5.00 }"};
static constexpr auto HOTEND_OFFSET_Z{"{ 0.0, 0.00 }"};
static constexpr auto ENABLE_HOTEND_OFFSET_X{false};
static constexpr auto ENABLE_HOTEND_OFFSET_Y{false};
static constexpr auto ENABLE_HOTEND_OFFSET_Z{false};

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

// Thermal Settings
static constexpr auto TEMP_SENSOR_0{"100kΩ EPCOS - Best choice for EPCOS thermistors [1]"};
static constexpr auto TEMP_SENSOR_1{"not used [0]"};
static constexpr auto TEMP_SENSOR_2{"not used [0]"};
static constexpr auto TEMP_SENSOR_3{"not used [0]"};
static constexpr auto TEMP_SENSOR_4{"not used [0]"};
static constexpr auto TEMP_SENSOR_5{"not used [0]"};
static constexpr auto TEMP_SENSOR_6{"not used [0]"};
static constexpr auto TEMP_SENSOR_7{"not used [0]"};
static constexpr auto TEMP_SENSOR_BED{"not used [0]"};
static constexpr auto TEMP_SENSOR_PROBE{"not used [0]"};
static constexpr auto TEMP_SENSOR_CHAMBER{"not used [0]"};
static constexpr auto TEMP_SENSOR_COOLER{"not used [0]"};
static constexpr auto TEMP_SENSOR_BOARD{"not used [0]"};
static constexpr auto TEMP_SENSOR_REDUNDANT{"not used [0]"};
static constexpr auto DUMMY_THERMISTOR_998_VALUE{25};
static constexpr auto DUMMY_THERMISTOR_999_VALUE{100};
static constexpr auto MAX31865_SENSOR_OHMS_0{100};
static constexpr auto MAX31865_CALIBRATION_OHMS_0{430};
static constexpr auto MAX31865_SENSOR_OHMS_1{100};
static constexpr auto MAX31865_CALIBRATION_OHMS_1{430};
static constexpr auto MAX31865_SENSOR_OHMS_2{100};
static constexpr auto MAX31865_CALIBRATION_OHMS_2{430};
static constexpr auto TEMP_RESIDENCY_TIME{10};
static constexpr auto TEMP_WINDOW{1};
static constexpr auto TEMP_HYSTERESIS{3};
static constexpr auto TEMP_BED_RESIDENCY_TIME{10};
static constexpr auto TEMP_BED_WINDOW{1};
static constexpr auto TEMP_BED_HYSTERESIS{3};
static constexpr auto TEMP_CHAMBER_RESIDENCY_TIME{10};
static constexpr auto TEMP_CHAMBER_WINDOW{1};
static constexpr auto TEMP_CHAMBER_HYSTERESIS{3};
static constexpr auto TEMP_SENSOR_REDUNDANT_SOURCE{"E1"};
static constexpr auto TEMP_SENSOR_REDUNDANT_TARGET{"E0"};
static constexpr auto TEMP_SENSOR_REDUNDANT_MAX_DIFF{10};
static constexpr auto HEATER_0_MINTEMP{5};
static constexpr auto HEATER_1_MINTEMP{5};
static constexpr auto HEATER_2_MINTEMP{5};
static constexpr auto HEATER_3_MINTEMP{5};
static constexpr auto HEATER_4_MINTEMP{5};
static constexpr auto HEATER_5_MINTEMP{5};
static constexpr auto HEATER_6_MINTEMP{5};
static constexpr auto HEATER_7_MINTEMP{5};
static constexpr auto BED_MINTEMP{5};
static constexpr auto CHAMBER_MINTEMP{5};
static constexpr auto HEATER_0_MAXTEMP{275};
static constexpr auto HEATER_1_MAXTEMP{275};
static constexpr auto HEATER_2_MAXTEMP{275};
static constexpr auto HEATER_3_MAXTEMP{275};
static constexpr auto HEATER_4_MAXTEMP{275};
static constexpr auto HEATER_5_MAXTEMP{275};
static constexpr auto HEATER_6_MAXTEMP{275};
static constexpr auto HEATER_7_MAXTEMP{275};
static constexpr auto BED_MAXTEMP{150};
static constexpr auto CHAMBER_MAXTEMP{60};
static constexpr auto HOTEND_OVERSHOOT{15};
static constexpr auto BED_OVERSHOOT{10};
static constexpr auto COOLER_OVERSHOOT{2};
static constexpr auto PIDTEMP{true};
static constexpr auto MPCTEMP{false};
static constexpr auto BANG_MAX{255};
static constexpr auto PID_MAX{255};
static constexpr auto PID_K1{0.95};
static constexpr auto PID_DEBUG{false};
static constexpr auto PID_PARAMS_PER_HOTEND{false};
static constexpr auto DEFAULT_Kp_LIST{"{ 22.20, 22.20 }"};
static constexpr auto DEFAULT_Ki_LIST{"{ 1.08, 1.08 }"};
static constexpr auto DEFAULT_Kd_LIST{"{ 114.00, 114.00 }"};
static constexpr auto DEFAULT_Kp{22.20};
static constexpr auto DEFAULT_Ki{1.08};
static constexpr auto DEFAULT_Kd{114.00};
static constexpr auto MPC_EDIT_MENU{false};
static constexpr auto MPC_AUTOTUNE_MENU{false};
static constexpr auto MPC_MAX{255};
static constexpr auto MPC_HEATER_POWER{"{ 40.0f }"};
static constexpr auto MPC_INCLUDE_FAN{true};
static constexpr auto MPC_BLOCK_HEAT_CAPACITY{"{ 16.7f }"};
static constexpr auto MPC_SENSOR_RESPONSIVENESS{"{ 0.22f }"};
static constexpr auto MPC_AMBIENT_XFER_COEFF{"{ 0.068f }"};
static constexpr auto MPC_AMBIENT_XFER_COEFF_FAN255{"{ 0.097f }"};
static constexpr auto MPC_FAN_0_ALL_HOTENDS{false};
static constexpr auto MPC_FAN_0_ACTIVE_HOTEND{false};
static constexpr auto FILAMENT_HEAT_CAPACITY_PERMM{"{ 0.0056f }"};
static constexpr auto MPC_SMOOTHING_FACTOR{0.5f};
static constexpr auto MPC_MIN_AMBIENT_CHANGE{1.0f};
static constexpr auto MPC_STEADYSTATE{0.5f};
static constexpr auto MPC_TUNING_POS{"{ X_CENTER, Y_CENTER, 1.0f }"};
static constexpr auto MPC_TUNING_END_Z{10.0f};
static constexpr auto PIDTEMPBED{false};
static constexpr auto BED_LIMIT_SWITCHING{false};
static constexpr auto MAX_BED_POWER{255};
static constexpr auto MIN_BED_POWER{0};
static constexpr auto ENABLE_MIN_BED_POWER{false};
static constexpr auto PID_BED_DEBUG{false};
static constexpr auto DEFAULT_bedKp{10.00};
static constexpr auto DEFAULT_bedKi{0.023};
static constexpr auto DEFAULT_bedKd{305.4};
static constexpr auto PIDTEMPCHAMBER{false};
static constexpr auto CHAMBER_LIMIT_SWITCHING{false};
static constexpr auto MAX_CHAMBER_POWER{255};
static constexpr auto MIN_CHAMBER_POWER{0};
static constexpr auto ENABLE_MIN_CHAMBER_POWER{false};
static constexpr auto PID_CHAMBER_DEBUG{false};
static constexpr auto DEFAULT_chamberKp{37.04f};
static constexpr auto DEFAULT_chamberKi{1.40f};
static constexpr auto DEFAULT_chamberKd{655.17f};
static constexpr auto PID_OPENLOOP{false};
static constexpr auto SLOW_PWM_HEATERS{false};
static constexpr auto PID_FUNCTIONAL_RANGE{10};
static constexpr auto PID_EDIT_MENU{false};
static constexpr auto PID_AUTOTUNE_MENU{false};
static constexpr auto PREVENT_COLD_EXTRUSION{true};
static constexpr auto EXTRUDE_MINTEMP{170};
static constexpr auto PREVENT_LENGTHY_EXTRUDE{true};
static constexpr auto EXTRUDE_MAXLENGTH{200};
static constexpr auto THERMAL_PROTECTION_HOTENDS{true};
static constexpr auto THERMAL_PROTECTION_BED{true};
static constexpr auto THERMAL_PROTECTION_CHAMBER{true};
static constexpr auto THERMAL_PROTECTION_COOLER{true};

// Filament Runout Sensor
static constexpr auto FILAMENT_RUNOUT_SENSOR{false};
static constexpr auto FIL_RUNOUT_ENABLED_DEFAULT{"true"};
static constexpr auto NUM_RUNOUT_SENSORS{"1"};
static constexpr auto FIL_RUNOUT_STATE{"LOW"};
static constexpr auto FIL_RUNOUT_PULLUP{true};
static constexpr auto FIL_RUNOUT_PULLDOWN{false};
static constexpr auto WATCH_ALL_RUNOUT_SENSORS{false};
static constexpr auto FIL_RUNOUT1_STATE{"LOW"};
static constexpr auto ENABLE_FIL_RUNOUT1_STATE{false};
static constexpr auto FIL_RUNOUT1_PULLUP{false};
static constexpr auto FIL_RUNOUT1_PULLDOWN{false};
static constexpr auto FIL_RUNOUT2_STATE{"LOW"};
static constexpr auto ENABLE_FIL_RUNOUT2_STATE{false};
static constexpr auto FIL_RUNOUT2_PULLUP{false};
static constexpr auto FIL_RUNOUT2_PULLDOWN{false};
static constexpr auto FIL_RUNOUT3_STATE{"LOW"};
static constexpr auto ENABLE_FIL_RUNOUT3_STATE{false};
static constexpr auto FIL_RUNOUT3_PULLUP{false};
static constexpr auto FIL_RUNOUT3_PULLDOWN{false};
static constexpr auto FIL_RUNOUT4_STATE{"LOW"};
static constexpr auto ENABLE_FIL_RUNOUT4_STATE{false};
static constexpr auto FIL_RUNOUT4_PULLUP{false};
static constexpr auto FIL_RUNOUT4_PULLDOWN{false};
static constexpr auto FIL_RUNOUT5_STATE{"LOW"};
static constexpr auto ENABLE_FIL_RUNOUT5_STATE{false};
static constexpr auto FIL_RUNOUT5_PULLUP{false};
static constexpr auto FIL_RUNOUT5_PULLDOWN{false};
static constexpr auto FIL_RUNOUT6_STATE{"LOW"};
static constexpr auto ENABLE_FIL_RUNOUT6_STATE{false};
static constexpr auto FIL_RUNOUT6_PULLUP{false};
static constexpr auto FIL_RUNOUT6_PULLDOWN{false};
static constexpr auto FIL_RUNOUT7_STATE{"LOW"};
static constexpr auto ENABLE_FIL_RUNOUT7_STATE{false};
static constexpr auto FIL_RUNOUT7_PULLUP{false};
static constexpr auto FIL_RUNOUT7_PULLDOWN{false};
static constexpr auto FIL_RUNOUT8_STATE{"LOW"};
static constexpr auto ENABLE_FIL_RUNOUT8_STATE{false};
static constexpr auto FIL_RUNOUT8_PULLUP{false};
static constexpr auto FIL_RUNOUT8_PULLDOWN{false};
static constexpr auto FILAMENT_RUNOUT_SCRIPT{"M600"};
static constexpr auto FILAMENT_RUNOUT_DISTANCE_MM{25};
static constexpr auto ENABLE_FILAMENT_RUNOUT_DISTANCE_MM{false};
static constexpr auto FILAMENT_MOTION_SENSOR{false};

// SD Card
static constexpr auto SDSUPPORT{false};
static constexpr auto SD_CHECK_AND_RETRY{false};

// LCD Menu Items
static constexpr auto NO_LCD_MENUS{false};
static constexpr auto SLIM_LCD_MENUS{false};

// Speaker
static constexpr auto SPEAKER{false};
static constexpr auto LCD_FEEDBACK_FREQUENCY_DURATION_MS{2};
static constexpr auto ENABLE_LCD_FEEDBACK_FREQUENCY_DURATION_MS{false};
static constexpr auto LCD_FEEDBACK_FREQUENCY_HZ{5000};
static constexpr auto ENABLE_LCD_FEEDBACK_FREQUENCY_HZ{false};
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
    QString ENVIRONMENT{defaults::ENVIRONMENT};
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

        json["ENVIRONMENT"] = ENVIRONMENT;
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
    int32_t SWITCHING_TOOLHEAD_Y_POS{defaults::SWITCHING_TOOLHEAD_Y_POS};
    int32_t SWITCHING_TOOLHEAD_Y_SECURITY{defaults::SWITCHING_TOOLHEAD_Y_SECURITY};
    int32_t SWITCHING_TOOLHEAD_Y_CLEAR{defaults::SWITCHING_TOOLHEAD_Y_CLEAR};
    int32_t SWITCHING_TOOLHEAD_X_POS0{defaults::SWITCHING_TOOLHEAD_X_POS0};
    int32_t SWITCHING_TOOLHEAD_X_POS1{defaults::SWITCHING_TOOLHEAD_X_POS1};
    int32_t SWITCHING_TOOLHEAD_SERVO_NR{defaults::SWITCHING_TOOLHEAD_SERVO_NR};
    int32_t SWITCHING_TOOLHEAD_SERVO_ANGLES0{defaults::SWITCHING_TOOLHEAD_SERVO_ANGLES0};
    int32_t SWITCHING_TOOLHEAD_SERVO_ANGLES1{defaults::SWITCHING_TOOLHEAD_SERVO_ANGLES1};
    int32_t SWITCHING_TOOLHEAD_Y_RELEASE{defaults::SWITCHING_TOOLHEAD_Y_RELEASE};
    int32_t SWITCHING_TOOLHEAD_X_SECURITY_T0{defaults::SWITCHING_TOOLHEAD_X_SECURITY_T0};
    int32_t SWITCHING_TOOLHEAD_X_SECURITY_T1{defaults::SWITCHING_TOOLHEAD_X_SECURITY_T1};
    bool PRIME_BEFORE_REMOVE{defaults::PRIME_BEFORE_REMOVE};
    int32_t SWITCHING_TOOLHEAD_PRIME_MM{defaults::SWITCHING_TOOLHEAD_PRIME_MM};
    int32_t SWITCHING_TOOLHEAD_RETRACT_MM{defaults::SWITCHING_TOOLHEAD_RETRACT_MM};
    int32_t SWITCHING_TOOLHEAD_PRIME_FEEDRATE{defaults::SWITCHING_TOOLHEAD_PRIME_FEEDRATE};
    int32_t SWITCHING_TOOLHEAD_RETRACT_FEEDRATE{defaults::SWITCHING_TOOLHEAD_RETRACT_FEEDRATE};
    int32_t SWITCHING_TOOLHEAD_Z_HOP{defaults::SWITCHING_TOOLHEAD_Z_HOP};
    bool MIXING_EXTRUDER{defaults::MIXING_EXTRUDER};
    int32_t MIXING_STEPPERS{defaults::MIXING_STEPPERS};
    int32_t MIXING_VIRTUAL_TOOLS{defaults::MIXING_VIRTUAL_TOOLS};
    bool DIRECT_MIXING_IN_G1{defaults::DIRECT_MIXING_IN_G1};
    bool GRADIENT_MIX{defaults::GRADIENT_MIX};
    bool MIXING_PRESETS{defaults::MIXING_PRESETS};
    bool GRADIENT_VTOOL{defaults::GRADIENT_VTOOL};
    QString HOTEND_OFFSET_X{defaults::HOTEND_OFFSET_X};
    QString HOTEND_OFFSET_Y{defaults::HOTEND_OFFSET_Y};
    QString HOTEND_OFFSET_Z{defaults::HOTEND_OFFSET_Z};
    bool ENABLE_HOTEND_OFFSET_X{defaults::ENABLE_HOTEND_OFFSET_X};
    bool ENABLE_HOTEND_OFFSET_Y{defaults::ENABLE_HOTEND_OFFSET_Y};
    bool ENABLE_HOTEND_OFFSET_Z{defaults::ENABLE_HOTEND_OFFSET_Z};

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
        json["SWITCHING_TOOLHEAD_Y_POS"] = SWITCHING_TOOLHEAD_Y_POS;
        json["SWITCHING_TOOLHEAD_Y_SECURITY"] = SWITCHING_TOOLHEAD_Y_SECURITY;
        json["SWITCHING_TOOLHEAD_Y_CLEAR"] = SWITCHING_TOOLHEAD_Y_CLEAR;
        json["SWITCHING_TOOLHEAD_X_POS0"] = SWITCHING_TOOLHEAD_X_POS0;
        json["SWITCHING_TOOLHEAD_X_POS1"] = SWITCHING_TOOLHEAD_X_POS1;
        json["SWITCHING_TOOLHEAD_SERVO_NR"] = SWITCHING_TOOLHEAD_SERVO_NR;
        json["SWITCHING_TOOLHEAD_SERVO_ANGLES0"] = SWITCHING_TOOLHEAD_SERVO_ANGLES0;
        json["SWITCHING_TOOLHEAD_SERVO_ANGLES1"] = SWITCHING_TOOLHEAD_SERVO_ANGLES1;
        json["SWITCHING_TOOLHEAD_Y_RELEASE"] = SWITCHING_TOOLHEAD_Y_RELEASE;
        json["SWITCHING_TOOLHEAD_X_SECURITY_T0"] = SWITCHING_TOOLHEAD_X_SECURITY_T0;
        json["SWITCHING_TOOLHEAD_X_SECURITY_T1"] = SWITCHING_TOOLHEAD_X_SECURITY_T1;
        json["PRIME_BEFORE_REMOVE"] = PRIME_BEFORE_REMOVE;
        json["SWITCHING_TOOLHEAD_PRIME_MM"] = SWITCHING_TOOLHEAD_PRIME_MM;
        json["SWITCHING_TOOLHEAD_RETRACT_MM"] = SWITCHING_TOOLHEAD_RETRACT_MM;
        json["SWITCHING_TOOLHEAD_PRIME_FEEDRATE"] = SWITCHING_TOOLHEAD_PRIME_FEEDRATE;
        json["SWITCHING_TOOLHEAD_RETRACT_FEEDRATE"] = SWITCHING_TOOLHEAD_RETRACT_FEEDRATE;
        json["SWITCHING_TOOLHEAD_Z_HOP"] = SWITCHING_TOOLHEAD_Z_HOP;
        json["MIXING_EXTRUDER"] = MIXING_EXTRUDER;
        json["MIXING_STEPPERS"] = MIXING_STEPPERS;
        json["MIXING_VIRTUAL_TOOLS"] = MIXING_VIRTUAL_TOOLS;
        json["DIRECT_MIXING_IN_G1"] = DIRECT_MIXING_IN_G1;
        json["GRADIENT_MIX"] = GRADIENT_MIX;
        json["MIXING_PRESETS"] = MIXING_PRESETS;
        json["GRADIENT_VTOOL"] = GRADIENT_VTOOL;
        json["HOTEND_OFFSET_X"] = HOTEND_OFFSET_X;
        json["HOTEND_OFFSET_Y"] = HOTEND_OFFSET_Y;
        json["HOTEND_OFFSET_Z"] = HOTEND_OFFSET_Z;
        json["ENABLE_HOTEND_OFFSET_X"] = ENABLE_HOTEND_OFFSET_X;
        json["ENABLE_HOTEND_OFFSET_Y"] = ENABLE_HOTEND_OFFSET_Y;
        json["ENABLE_HOTEND_OFFSET_Z"] = ENABLE_HOTEND_OFFSET_Z;

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
/// \brief The ThermalSettingsConfiguration struct contains thermal settings configurations
///
struct ThermalSettingsConfiguration : public PageConfiguration
{
    QString TEMP_SENSOR_0{defaults::TEMP_SENSOR_0};
    QString TEMP_SENSOR_1{defaults::TEMP_SENSOR_1};
    QString TEMP_SENSOR_2{defaults::TEMP_SENSOR_2};
    QString TEMP_SENSOR_3{defaults::TEMP_SENSOR_3};
    QString TEMP_SENSOR_4{defaults::TEMP_SENSOR_4};
    QString TEMP_SENSOR_5{defaults::TEMP_SENSOR_5};
    QString TEMP_SENSOR_6{defaults::TEMP_SENSOR_6};
    QString TEMP_SENSOR_7{defaults::TEMP_SENSOR_7};
    QString TEMP_SENSOR_BED{defaults::TEMP_SENSOR_BED};
    QString TEMP_SENSOR_PROBE{defaults::TEMP_SENSOR_PROBE};
    QString TEMP_SENSOR_CHAMBER{defaults::TEMP_SENSOR_CHAMBER};
    QString TEMP_SENSOR_COOLER{defaults::TEMP_SENSOR_COOLER};
    QString TEMP_SENSOR_BOARD{defaults::TEMP_SENSOR_BOARD};
    QString TEMP_SENSOR_REDUNDANT{defaults::TEMP_SENSOR_REDUNDANT};
    int32_t DUMMY_THERMISTOR_998_VALUE{defaults::DUMMY_THERMISTOR_998_VALUE};
    int32_t DUMMY_THERMISTOR_999_VALUE{defaults::DUMMY_THERMISTOR_999_VALUE};
    int32_t MAX31865_SENSOR_OHMS_0{defaults::MAX31865_SENSOR_OHMS_0};
    int32_t MAX31865_CALIBRATION_OHMS_0{defaults::MAX31865_CALIBRATION_OHMS_0};
    int32_t MAX31865_SENSOR_OHMS_1{defaults::MAX31865_SENSOR_OHMS_1};
    int32_t MAX31865_CALIBRATION_OHMS_1{defaults::MAX31865_CALIBRATION_OHMS_1};
    int32_t MAX31865_SENSOR_OHMS_2{defaults::MAX31865_SENSOR_OHMS_2};
    int32_t MAX31865_CALIBRATION_OHMS_2{defaults::MAX31865_CALIBRATION_OHMS_2};
    int32_t TEMP_RESIDENCY_TIME{defaults::TEMP_RESIDENCY_TIME};
    int32_t TEMP_WINDOW{defaults::TEMP_WINDOW};
    int32_t TEMP_HYSTERESIS{defaults::TEMP_HYSTERESIS};
    int32_t TEMP_BED_RESIDENCY_TIME{defaults::TEMP_BED_RESIDENCY_TIME};
    int32_t TEMP_BED_WINDOW{defaults::TEMP_BED_WINDOW};
    int32_t TEMP_BED_HYSTERESIS{defaults::TEMP_BED_HYSTERESIS};
    int32_t TEMP_CHAMBER_RESIDENCY_TIME{defaults::TEMP_CHAMBER_RESIDENCY_TIME};
    int32_t TEMP_CHAMBER_WINDOW{defaults::TEMP_CHAMBER_WINDOW};
    int32_t TEMP_CHAMBER_HYSTERESIS{defaults::TEMP_CHAMBER_HYSTERESIS};
    QString TEMP_SENSOR_REDUNDANT_SOURCE{defaults::TEMP_SENSOR_REDUNDANT_SOURCE};
    QString TEMP_SENSOR_REDUNDANT_TARGET{defaults::TEMP_SENSOR_REDUNDANT_TARGET};
    int32_t TEMP_SENSOR_REDUNDANT_MAX_DIFF{defaults::TEMP_SENSOR_REDUNDANT_MAX_DIFF};
    int32_t HEATER_0_MINTEMP{defaults::HEATER_0_MINTEMP};
    int32_t HEATER_1_MINTEMP{defaults::HEATER_1_MINTEMP};
    int32_t HEATER_2_MINTEMP{defaults::HEATER_2_MINTEMP};
    int32_t HEATER_3_MINTEMP{defaults::HEATER_3_MINTEMP};
    int32_t HEATER_4_MINTEMP{defaults::HEATER_4_MINTEMP};
    int32_t HEATER_5_MINTEMP{defaults::HEATER_5_MINTEMP};
    int32_t HEATER_6_MINTEMP{defaults::HEATER_6_MINTEMP};
    int32_t HEATER_7_MINTEMP{defaults::HEATER_7_MINTEMP};
    int32_t BED_MINTEMP{defaults::BED_MINTEMP};
    int32_t CHAMBER_MINTEMP{defaults::CHAMBER_MINTEMP};
    int32_t HEATER_0_MAXTEMP{defaults::HEATER_0_MAXTEMP};
    int32_t HEATER_1_MAXTEMP{defaults::HEATER_1_MAXTEMP};
    int32_t HEATER_2_MAXTEMP{defaults::HEATER_2_MAXTEMP};
    int32_t HEATER_3_MAXTEMP{defaults::HEATER_3_MAXTEMP};
    int32_t HEATER_4_MAXTEMP{defaults::HEATER_4_MAXTEMP};
    int32_t HEATER_5_MAXTEMP{defaults::HEATER_5_MAXTEMP};
    int32_t HEATER_6_MAXTEMP{defaults::HEATER_6_MAXTEMP};
    int32_t HEATER_7_MAXTEMP{defaults::HEATER_7_MAXTEMP};
    int32_t BED_MAXTEMP{defaults::BED_MAXTEMP};
    int32_t CHAMBER_MAXTEMP{defaults::CHAMBER_MAXTEMP};
    int32_t HOTEND_OVERSHOOT{defaults::HOTEND_OVERSHOOT};
    int32_t BED_OVERSHOOT{defaults::BED_OVERSHOOT};
    int32_t COOLER_OVERSHOOT{defaults::COOLER_OVERSHOOT};
    bool PIDTEMP{defaults::PIDTEMP};
    bool MPCTEMP{defaults::MPCTEMP};
    int32_t BANG_MAX{defaults::BANG_MAX};
    int32_t PID_MAX{defaults::PID_MAX};
    double PID_K1{defaults::PID_K1};
    bool PID_DEBUG{defaults::PID_DEBUG};
    bool PID_PARAMS_PER_HOTEND{defaults::PID_PARAMS_PER_HOTEND};
    QString DEFAULT_Kp_LIST{defaults::DEFAULT_Kp_LIST};
    QString DEFAULT_Ki_LIST{defaults::DEFAULT_Ki_LIST};
    QString DEFAULT_Kd_LIST{defaults::DEFAULT_Kd_LIST};
    double DEFAULT_Kp{defaults::DEFAULT_Kp};
    double DEFAULT_Ki{defaults::DEFAULT_Ki};
    double DEFAULT_Kd{defaults::DEFAULT_Kd};
    bool MPC_EDIT_MENU{defaults::MPC_EDIT_MENU};
    bool MPC_AUTOTUNE_MENU{defaults::MPC_AUTOTUNE_MENU};
    int32_t MPC_MAX{defaults::MPC_MAX};
    QString MPC_HEATER_POWER{defaults::MPC_HEATER_POWER};
    bool MPC_INCLUDE_FAN{defaults::MPC_INCLUDE_FAN};
    QString MPC_BLOCK_HEAT_CAPACITY{defaults::MPC_BLOCK_HEAT_CAPACITY};
    QString MPC_SENSOR_RESPONSIVENESS{defaults::MPC_SENSOR_RESPONSIVENESS};
    QString MPC_AMBIENT_XFER_COEFF{defaults::MPC_AMBIENT_XFER_COEFF};
    QString MPC_AMBIENT_XFER_COEFF_FAN255{defaults::MPC_AMBIENT_XFER_COEFF_FAN255};
    bool MPC_FAN_0_ALL_HOTENDS{defaults::MPC_FAN_0_ALL_HOTENDS};
    bool MPC_FAN_0_ACTIVE_HOTEND{defaults::MPC_FAN_0_ACTIVE_HOTEND};
    QString FILAMENT_HEAT_CAPACITY_PERMM{defaults::FILAMENT_HEAT_CAPACITY_PERMM};
    double MPC_SMOOTHING_FACTOR{defaults::MPC_SMOOTHING_FACTOR};
    double MPC_MIN_AMBIENT_CHANGE{defaults::MPC_MIN_AMBIENT_CHANGE};
    double MPC_STEADYSTATE{defaults::MPC_STEADYSTATE};
    QString MPC_TUNING_POS{defaults::MPC_TUNING_POS};
    double MPC_TUNING_END_Z{defaults::MPC_TUNING_END_Z};
    bool PIDTEMPBED{defaults::PIDTEMPBED};
    bool BED_LIMIT_SWITCHING{defaults::BED_LIMIT_SWITCHING};
    int32_t MAX_BED_POWER{defaults::MAX_BED_POWER};
    int32_t MIN_BED_POWER{defaults::MIN_BED_POWER};
    bool ENABLE_MIN_BED_POWER{defaults::ENABLE_MIN_BED_POWER};
    bool PID_BED_DEBUG{defaults::PID_BED_DEBUG};
    double DEFAULT_bedKp{defaults::DEFAULT_bedKp};
    double DEFAULT_bedKi{defaults::DEFAULT_bedKi};
    double DEFAULT_bedKd{defaults::DEFAULT_bedKd};
    bool PIDTEMPCHAMBER{defaults::PIDTEMPCHAMBER};
    bool CHAMBER_LIMIT_SWITCHING{defaults::CHAMBER_LIMIT_SWITCHING};
    int32_t MAX_CHAMBER_POWER{defaults::MAX_CHAMBER_POWER};
    int32_t MIN_CHAMBER_POWER{defaults::MIN_CHAMBER_POWER};
    bool ENABLE_MIN_CHAMBER_POWER{defaults::ENABLE_MIN_CHAMBER_POWER};
    bool PID_CHAMBER_DEBUG{defaults::PID_CHAMBER_DEBUG};
    double DEFAULT_chamberKp{defaults::DEFAULT_chamberKp};
    double DEFAULT_chamberKi{defaults::DEFAULT_chamberKi};
    double DEFAULT_chamberKd{defaults::DEFAULT_chamberKd};
    bool PID_OPENLOOP{defaults::PID_OPENLOOP};
    bool SLOW_PWM_HEATERS{defaults::SLOW_PWM_HEATERS};
    int32_t PID_FUNCTIONAL_RANGE{defaults::PID_FUNCTIONAL_RANGE};
    bool PID_EDIT_MENU{defaults::PID_EDIT_MENU};
    bool PID_AUTOTUNE_MENU{defaults::PID_AUTOTUNE_MENU};
    bool PREVENT_COLD_EXTRUSION{defaults::PREVENT_COLD_EXTRUSION};
    int32_t EXTRUDE_MINTEMP{defaults::EXTRUDE_MINTEMP};
    bool PREVENT_LENGTHY_EXTRUDE{defaults::PREVENT_LENGTHY_EXTRUDE};
    int32_t EXTRUDE_MAXLENGTH{defaults::EXTRUDE_MAXLENGTH};
    bool THERMAL_PROTECTION_HOTENDS{defaults::THERMAL_PROTECTION_HOTENDS};
    bool THERMAL_PROTECTION_BED{defaults::THERMAL_PROTECTION_BED};
    bool THERMAL_PROTECTION_CHAMBER{defaults::THERMAL_PROTECTION_CHAMBER};
    bool THERMAL_PROTECTION_COOLER{defaults::THERMAL_PROTECTION_COOLER};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["TEMP_SENSOR_0"] = TEMP_SENSOR_0;
        json["TEMP_SENSOR_1"] = TEMP_SENSOR_1;
        json["TEMP_SENSOR_2"] = TEMP_SENSOR_2;
        json["TEMP_SENSOR_3"] = TEMP_SENSOR_3;
        json["TEMP_SENSOR_4"] = TEMP_SENSOR_4;
        json["TEMP_SENSOR_5"] = TEMP_SENSOR_5;
        json["TEMP_SENSOR_6"] = TEMP_SENSOR_6;
        json["TEMP_SENSOR_7"] = TEMP_SENSOR_7;
        json["TEMP_SENSOR_BED"] = TEMP_SENSOR_BED;
        json["TEMP_SENSOR_PROBE"] = TEMP_SENSOR_PROBE;
        json["TEMP_SENSOR_CHAMBER"] = TEMP_SENSOR_CHAMBER;
        json["TEMP_SENSOR_COOLER"] = TEMP_SENSOR_COOLER;
        json["TEMP_SENSOR_BOARD"] = TEMP_SENSOR_BOARD;
        json["TEMP_SENSOR_REDUNDANT"] = TEMP_SENSOR_REDUNDANT;
        json["DUMMY_THERMISTOR_998_VALUE"] = DUMMY_THERMISTOR_998_VALUE;
        json["DUMMY_THERMISTOR_999_VALUE"] = DUMMY_THERMISTOR_999_VALUE;
        json["MAX31865_SENSOR_OHMS_0"] = MAX31865_SENSOR_OHMS_0;
        json["MAX31865_CALIBRATION_OHMS_0"] = MAX31865_CALIBRATION_OHMS_0;
        json["MAX31865_SENSOR_OHMS_1"] = MAX31865_SENSOR_OHMS_1;
        json["MAX31865_CALIBRATION_OHMS_1"] = MAX31865_CALIBRATION_OHMS_1;
        json["MAX31865_SENSOR_OHMS_2"] = MAX31865_SENSOR_OHMS_2;
        json["MAX31865_CALIBRATION_OHMS_2"] = MAX31865_CALIBRATION_OHMS_2;
        json["TEMP_RESIDENCY_TIME"] = TEMP_RESIDENCY_TIME;
        json["TEMP_WINDOW"] = TEMP_WINDOW;
        json["TEMP_HYSTERESIS"] = TEMP_HYSTERESIS;
        json["TEMP_BED_RESIDENCY_TIME"] = TEMP_BED_RESIDENCY_TIME;
        json["TEMP_BED_WINDOW"] = TEMP_BED_WINDOW;
        json["TEMP_BED_HYSTERESIS"] = TEMP_BED_HYSTERESIS;
        json["TEMP_CHAMBER_RESIDENCY_TIME"] = TEMP_CHAMBER_RESIDENCY_TIME;
        json["TEMP_CHAMBER_WINDOW"] = TEMP_CHAMBER_WINDOW;
        json["TEMP_CHAMBER_HYSTERESIS"] = TEMP_CHAMBER_HYSTERESIS;
        json["TEMP_SENSOR_REDUNDANT_SOURCE"] = TEMP_SENSOR_REDUNDANT_SOURCE;
        json["TEMP_SENSOR_REDUNDANT_TARGET"] = TEMP_SENSOR_REDUNDANT_TARGET;
        json["TEMP_SENSOR_REDUNDANT_MAX_DIFF"] = TEMP_SENSOR_REDUNDANT_MAX_DIFF;
        json["HEATER_0_MINTEMP"] = HEATER_0_MINTEMP;
        json["HEATER_1_MINTEMP"] = HEATER_1_MINTEMP;
        json["HEATER_2_MINTEMP"] = HEATER_2_MINTEMP;
        json["HEATER_3_MINTEMP"] = HEATER_3_MINTEMP;
        json["HEATER_4_MINTEMP"] = HEATER_4_MINTEMP;
        json["HEATER_5_MINTEMP"] = HEATER_5_MINTEMP;
        json["HEATER_6_MINTEMP"] = HEATER_6_MINTEMP;
        json["HEATER_7_MINTEMP"] = HEATER_7_MINTEMP;
        json["BED_MINTEMP"] = BED_MINTEMP;
        json["CHAMBER_MINTEMP"] = CHAMBER_MINTEMP;
        json["HEATER_0_MAXTEMP"] = HEATER_0_MAXTEMP;
        json["HEATER_1_MAXTEMP"] = HEATER_1_MAXTEMP;
        json["HEATER_2_MAXTEMP"] = HEATER_2_MAXTEMP;
        json["HEATER_3_MAXTEMP"] = HEATER_3_MAXTEMP;
        json["HEATER_4_MAXTEMP"] = HEATER_4_MAXTEMP;
        json["HEATER_5_MAXTEMP"] = HEATER_5_MAXTEMP;
        json["HEATER_6_MAXTEMP"] = HEATER_6_MAXTEMP;
        json["HEATER_7_MAXTEMP"] = HEATER_7_MAXTEMP;
        json["BED_MAXTEMP"] = BED_MAXTEMP;
        json["CHAMBER_MAXTEMP"] = CHAMBER_MAXTEMP;
        json["HOTEND_OVERSHOOT"] = HOTEND_OVERSHOOT;
        json["BED_OVERSHOOT"] = BED_OVERSHOOT;
        json["COOLER_OVERSHOOT"] = COOLER_OVERSHOOT;
        json["PIDTEMP"] = PIDTEMP;
        json["MPCTEMP"] = MPCTEMP;
        json["BANG_MAX"] = BANG_MAX;
        json["PID_MAX"] = PID_MAX;
        json["PID_K1"] = PID_K1;
        json["PID_DEBUG"] = PID_DEBUG;
        json["PID_PARAMS_PER_HOTEND"] = PID_PARAMS_PER_HOTEND;
        json["DEFAULT_Kp_LIST"] = DEFAULT_Kp_LIST;
        json["DEFAULT_Ki_LIST"] = DEFAULT_Ki_LIST;
        json["DEFAULT_Kd_LIST"] = DEFAULT_Kd_LIST;
        json["DEFAULT_Kp"] = DEFAULT_Kp;
        json["DEFAULT_Ki"] = DEFAULT_Ki;
        json["DEFAULT_Kd"] = DEFAULT_Kd;
        json["MPC_EDIT_MENU"] = MPC_EDIT_MENU;
        json["MPC_AUTOTUNE_MENU"] = MPC_AUTOTUNE_MENU;
        json["MPC_MAX"] = MPC_MAX;
        json["MPC_HEATER_POWER"] = MPC_HEATER_POWER;
        json["MPC_INCLUDE_FAN"] = MPC_INCLUDE_FAN;
        json["MPC_BLOCK_HEAT_CAPACITY"] = MPC_BLOCK_HEAT_CAPACITY;
        json["MPC_SENSOR_RESPONSIVENESS"] = MPC_SENSOR_RESPONSIVENESS;
        json["MPC_AMBIENT_XFER_COEFF"] = MPC_AMBIENT_XFER_COEFF;
        json["MPC_AMBIENT_XFER_COEFF_FAN255"] = MPC_AMBIENT_XFER_COEFF_FAN255;
        json["MPC_FAN_0_ALL_HOTENDS"] = MPC_FAN_0_ALL_HOTENDS;
        json["MPC_FAN_0_ACTIVE_HOTEND"] = MPC_FAN_0_ACTIVE_HOTEND;
        json["FILAMENT_HEAT_CAPACITY_PERMM"] = FILAMENT_HEAT_CAPACITY_PERMM;
        json["MPC_SMOOTHING_FACTOR"] = MPC_SMOOTHING_FACTOR;
        json["MPC_MIN_AMBIENT_CHANGE"] = MPC_MIN_AMBIENT_CHANGE;
        json["MPC_STEADYSTATE"] = MPC_STEADYSTATE;
        json["MPC_TUNING_POS"] = MPC_TUNING_POS;
        json["MPC_TUNING_END_Z"] = MPC_TUNING_END_Z;
        json["PIDTEMPBED"] = PIDTEMPBED;
        json["BED_LIMIT_SWITCHING"] = BED_LIMIT_SWITCHING;
        json["MAX_BED_POWER"] = MAX_BED_POWER;
        json["MIN_BED_POWER"] = MIN_BED_POWER;
        json["ENABLE_MIN_BED_POWER"] = ENABLE_MIN_BED_POWER;
        json["PID_BED_DEBUG"] = PID_BED_DEBUG;
        json["DEFAULT_bedKp"] = DEFAULT_bedKp;
        json["DEFAULT_bedKi"] = DEFAULT_bedKi;
        json["DEFAULT_bedKd"] = DEFAULT_bedKd;
        json["PIDTEMPCHAMBER"] = PIDTEMPCHAMBER;
        json["CHAMBER_LIMIT_SWITCHING"] = CHAMBER_LIMIT_SWITCHING;
        json["MAX_CHAMBER_POWER"] = MAX_CHAMBER_POWER;
        json["MIN_CHAMBER_POWER"] = MIN_CHAMBER_POWER;
        json["ENABLE_MIN_CHAMBER_POWER"] = ENABLE_MIN_CHAMBER_POWER;
        json["PID_CHAMBER_DEBUG"] = PID_CHAMBER_DEBUG;
        json["DEFAULT_chamberKp"] = DEFAULT_chamberKp;
        json["DEFAULT_chamberKi"] = DEFAULT_chamberKi;
        json["DEFAULT_chamberKd"] = DEFAULT_chamberKd;
        json["PID_OPENLOOP"] = PID_OPENLOOP;
        json["SLOW_PWM_HEATERS"] = SLOW_PWM_HEATERS;
        json["PID_FUNCTIONAL_RANGE"] = PID_FUNCTIONAL_RANGE;
        json["PID_EDIT_MENU"] = PID_EDIT_MENU;
        json["PID_AUTOTUNE_MENU"] = PID_AUTOTUNE_MENU;
        json["PREVENT_COLD_EXTRUSION"] = PREVENT_COLD_EXTRUSION;
        json["EXTRUDE_MINTEMP"] = EXTRUDE_MINTEMP;
        json["PREVENT_LENGTHY_EXTRUDE"] = PREVENT_LENGTHY_EXTRUDE;
        json["EXTRUDE_MAXLENGTH"] = EXTRUDE_MAXLENGTH;
        json["THERMAL_PROTECTION_HOTENDS"] = THERMAL_PROTECTION_HOTENDS;
        json["THERMAL_PROTECTION_BED"] = THERMAL_PROTECTION_BED;
        json["THERMAL_PROTECTION_CHAMBER"] = THERMAL_PROTECTION_CHAMBER;
        json["THERMAL_PROTECTION_COOLER"] = THERMAL_PROTECTION_COOLER;

        return json;
    }
};

///
/// \brief The FilamentRunoutSensorConfiguration struct contains filament runout sensor configurations
///
struct FilamentRunoutSensorConfiguration : public PageConfiguration
{
    bool FILAMENT_RUNOUT_SENSOR{defaults::FILAMENT_RUNOUT_SENSOR};
    QString FIL_RUNOUT_ENABLED_DEFAULT{defaults::FIL_RUNOUT_ENABLED_DEFAULT};
    QString NUM_RUNOUT_SENSORS{defaults::NUM_RUNOUT_SENSORS};
    QString FIL_RUNOUT_STATE{defaults::FIL_RUNOUT_STATE};
    bool FIL_RUNOUT_PULLUP{defaults::FIL_RUNOUT_PULLUP};
    bool FIL_RUNOUT_PULLDOWN{defaults::FIL_RUNOUT_PULLDOWN};
    bool WATCH_ALL_RUNOUT_SENSORS{defaults::WATCH_ALL_RUNOUT_SENSORS};
    QString FIL_RUNOUT1_STATE{defaults::FIL_RUNOUT1_STATE};
    bool ENABLE_FIL_RUNOUT1_STATE{defaults::ENABLE_FIL_RUNOUT1_STATE};
    bool FIL_RUNOUT1_PULLUP{defaults::FIL_RUNOUT1_PULLUP};
    bool FIL_RUNOUT1_PULLDOWN{defaults::FIL_RUNOUT1_PULLDOWN};
    QString FIL_RUNOUT2_STATE{defaults::FIL_RUNOUT2_STATE};
    bool ENABLE_FIL_RUNOUT2_STATE{defaults::ENABLE_FIL_RUNOUT2_STATE};
    bool FIL_RUNOUT2_PULLUP{defaults::FIL_RUNOUT2_PULLUP};
    bool FIL_RUNOUT2_PULLDOWN{defaults::FIL_RUNOUT2_PULLDOWN};
    QString FIL_RUNOUT3_STATE{defaults::FIL_RUNOUT3_STATE};
    bool ENABLE_FIL_RUNOUT3_STATE{defaults::ENABLE_FIL_RUNOUT3_STATE};
    bool FIL_RUNOUT3_PULLUP{defaults::FIL_RUNOUT3_PULLUP};
    bool FIL_RUNOUT3_PULLDOWN{defaults::FIL_RUNOUT3_PULLDOWN};
    QString FIL_RUNOUT4_STATE{defaults::FIL_RUNOUT4_STATE};
    bool ENABLE_FIL_RUNOUT4_STATE{defaults::ENABLE_FIL_RUNOUT4_STATE};
    bool FIL_RUNOUT4_PULLUP{defaults::FIL_RUNOUT4_PULLUP};
    bool FIL_RUNOUT4_PULLDOWN{defaults::FIL_RUNOUT4_PULLDOWN};
    QString FIL_RUNOUT5_STATE{defaults::FIL_RUNOUT5_STATE};
    bool ENABLE_FIL_RUNOUT5_STATE{defaults::ENABLE_FIL_RUNOUT5_STATE};
    bool FIL_RUNOUT5_PULLUP{defaults::FIL_RUNOUT5_PULLUP};
    bool FIL_RUNOUT5_PULLDOWN{defaults::FIL_RUNOUT5_PULLDOWN};
    QString FIL_RUNOUT6_STATE{defaults::FIL_RUNOUT6_STATE};
    bool ENABLE_FIL_RUNOUT6_STATE{defaults::ENABLE_FIL_RUNOUT6_STATE};
    bool FIL_RUNOUT6_PULLUP{defaults::FIL_RUNOUT6_PULLUP};
    bool FIL_RUNOUT6_PULLDOWN{defaults::FIL_RUNOUT6_PULLDOWN};
    QString FIL_RUNOUT7_STATE{defaults::FIL_RUNOUT7_STATE};
    bool ENABLE_FIL_RUNOUT7_STATE{defaults::ENABLE_FIL_RUNOUT7_STATE};
    bool FIL_RUNOUT7_PULLUP{defaults::FIL_RUNOUT7_PULLUP};
    bool FIL_RUNOUT7_PULLDOWN{defaults::FIL_RUNOUT7_PULLDOWN};
    QString FIL_RUNOUT8_STATE{defaults::FIL_RUNOUT8_STATE};
    bool ENABLE_FIL_RUNOUT8_STATE{defaults::ENABLE_FIL_RUNOUT8_STATE};
    bool FIL_RUNOUT8_PULLUP{defaults::FIL_RUNOUT8_PULLUP};
    bool FIL_RUNOUT8_PULLDOWN{defaults::FIL_RUNOUT8_PULLDOWN};
    QString FILAMENT_RUNOUT_SCRIPT{defaults::FILAMENT_RUNOUT_SCRIPT};
    int32_t FILAMENT_RUNOUT_DISTANCE_MM{defaults::FILAMENT_RUNOUT_DISTANCE_MM};
    bool ENABLE_FILAMENT_RUNOUT_DISTANCE_MM{defaults::ENABLE_FILAMENT_RUNOUT_DISTANCE_MM};
    bool FILAMENT_MOTION_SENSOR{defaults::FILAMENT_MOTION_SENSOR};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["FILAMENT_RUNOUT_SENSOR"] = FILAMENT_RUNOUT_SENSOR;
        json["FIL_RUNOUT_ENABLED_DEFAULT"] = FIL_RUNOUT_ENABLED_DEFAULT;
        json["NUM_RUNOUT_SENSORS"] = NUM_RUNOUT_SENSORS;
        json["FIL_RUNOUT_STATE"] = FIL_RUNOUT_STATE;
        json["FIL_RUNOUT_PULLUP"] = FIL_RUNOUT_PULLUP;
        json["FIL_RUNOUT_PULLDOWN"] = FIL_RUNOUT_PULLDOWN;
        json["WATCH_ALL_RUNOUT_SENSORS"] = WATCH_ALL_RUNOUT_SENSORS;
        json["FIL_RUNOUT1_STATE"] = FIL_RUNOUT1_STATE;
        json["ENABLE_FIL_RUNOUT1_STATE"] = ENABLE_FIL_RUNOUT1_STATE;
        json["FIL_RUNOUT1_PULLUP"] = FIL_RUNOUT1_PULLUP;
        json["FIL_RUNOUT1_PULLDOWN"] = FIL_RUNOUT1_PULLDOWN;
        json["FIL_RUNOUT2_STATE"] = FIL_RUNOUT2_STATE;
        json["ENABLE_FIL_RUNOUT2_STATE"] = ENABLE_FIL_RUNOUT2_STATE;
        json["FIL_RUNOUT2_PULLUP"] = FIL_RUNOUT2_PULLUP;
        json["FIL_RUNOUT2_PULLDOWN"] = FIL_RUNOUT2_PULLDOWN;
        json["FIL_RUNOUT3_STATE"] = FIL_RUNOUT3_STATE;
        json["ENABLE_FIL_RUNOUT3_STATE"] = ENABLE_FIL_RUNOUT3_STATE;
        json["FIL_RUNOUT3_PULLUP"] = FIL_RUNOUT3_PULLUP;
        json["FIL_RUNOUT3_PULLDOWN"] = FIL_RUNOUT3_PULLDOWN;
        json["FIL_RUNOUT4_STATE"] = FIL_RUNOUT4_STATE;
        json["ENABLE_FIL_RUNOUT4_STATE"] = ENABLE_FIL_RUNOUT4_STATE;
        json["FIL_RUNOUT4_PULLUP"] = FIL_RUNOUT4_PULLUP;
        json["FIL_RUNOUT4_PULLDOWN"] = FIL_RUNOUT4_PULLDOWN;
        json["FIL_RUNOUT5_STATE"] = FIL_RUNOUT5_STATE;
        json["ENABLE_FIL_RUNOUT5_STATE"] = ENABLE_FIL_RUNOUT5_STATE;
        json["FIL_RUNOUT5_PULLUP"] = FIL_RUNOUT5_PULLUP;
        json["FIL_RUNOUT5_PULLDOWN"] = FIL_RUNOUT5_PULLDOWN;
        json["FIL_RUNOUT6_STATE"] = FIL_RUNOUT6_STATE;
        json["ENABLE_FIL_RUNOUT6_STATE"] = ENABLE_FIL_RUNOUT6_STATE;
        json["FIL_RUNOUT6_PULLUP"] = FIL_RUNOUT6_PULLUP;
        json["FIL_RUNOUT6_PULLDOWN"] = FIL_RUNOUT6_PULLDOWN;
        json["FIL_RUNOUT7_STATE"] = FIL_RUNOUT7_STATE;
        json["ENABLE_FIL_RUNOUT7_STATE"] = ENABLE_FIL_RUNOUT7_STATE;
        json["FIL_RUNOUT7_PULLUP"] = FIL_RUNOUT7_PULLUP;
        json["FIL_RUNOUT7_PULLDOWN"] = FIL_RUNOUT7_PULLDOWN;
        json["FIL_RUNOUT8_STATE"] = FIL_RUNOUT8_STATE;
        json["ENABLE_FIL_RUNOUT8_STATE"] = ENABLE_FIL_RUNOUT8_STATE;
        json["FIL_RUNOUT8_PULLUP"] = FIL_RUNOUT8_PULLUP;
        json["FIL_RUNOUT8_PULLDOWN"] = FIL_RUNOUT8_PULLDOWN;
        json["FILAMENT_RUNOUT_SCRIPT"] = FILAMENT_RUNOUT_SCRIPT;
        json["FILAMENT_RUNOUT_DISTANCE_MM"] = FILAMENT_RUNOUT_DISTANCE_MM;
        json["ENABLE_FILAMENT_RUNOUT_DISTANCE_MM"] = ENABLE_FILAMENT_RUNOUT_DISTANCE_MM;
        json["FILAMENT_MOTION_SENSOR"] = FILAMENT_MOTION_SENSOR;

        return json;
    }
};

///
/// \brief The SDCardConfiguration struct contains SD card configurations
///
struct SDCardConfiguration : public PageConfiguration
{
    bool SDSUPPORT{defaults::SDSUPPORT};
    bool SD_CHECK_AND_RETRY{defaults::SD_CHECK_AND_RETRY};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["SDSUPPORT"] = SDSUPPORT;
        json["SD_CHECK_AND_RETRY"] = SD_CHECK_AND_RETRY;

        return json;
    }
};

///
/// \brief The LCDMenuItemsConfiguration struct contains LCD menu items configurations
///
struct LCDMenuItemsConfiguration : public PageConfiguration
{
    bool NO_LCD_MENUS{defaults::NO_LCD_MENUS};
    bool SLIM_LCD_MENUS{defaults::SLIM_LCD_MENUS};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["NO_LCD_MENUS"] = NO_LCD_MENUS;
        json["SLIM_LCD_MENUS"] = SLIM_LCD_MENUS;

        return json;
    }
};

///
/// \brief The SpeakerConfiguration struct contains speaker configurations
///
struct SpeakerConfiguration : public PageConfiguration
{
    bool SPEAKER{defaults::SPEAKER};
    int32_t LCD_FEEDBACK_FREQUENCY_DURATION_MS{defaults::LCD_FEEDBACK_FREQUENCY_DURATION_MS};
    bool ENABLE_LCD_FEEDBACK_FREQUENCY_DURATION_MS{defaults::ENABLE_LCD_FEEDBACK_FREQUENCY_DURATION_MS};
    int32_t LCD_FEEDBACK_FREQUENCY_HZ{defaults::LCD_FEEDBACK_FREQUENCY_HZ};
    bool ENABLE_LCD_FEEDBACK_FREQUENCY_HZ{defaults::ENABLE_LCD_FEEDBACK_FREQUENCY_HZ};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["SPEAKER"] = SPEAKER;
        json["LCD_FEEDBACK_FREQUENCY_DURATION_MS"] = LCD_FEEDBACK_FREQUENCY_DURATION_MS;
        json["ENABLE_LCD_FEEDBACK_FREQUENCY_DURATION_MS"] = ENABLE_LCD_FEEDBACK_FREQUENCY_DURATION_MS;
        json["LCD_FEEDBACK_FREQUENCY_HZ"] = LCD_FEEDBACK_FREQUENCY_HZ;
        json["ENABLE_LCD_FEEDBACK_FREQUENCY_HZ"] = ENABLE_LCD_FEEDBACK_FREQUENCY_HZ;

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
    ThermalSettingsConfiguration thermalSettings;
    FilamentRunoutSensorConfiguration filamentRunoutSensor;
    SDCardConfiguration sdCard;
    LCDMenuItemsConfiguration lcdMenuItems;
    SpeakerConfiguration speaker;

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
        json["thermalSettings"] = thermalSettings.ToJson();
        json["filamentRunoutSensor"] = filamentRunoutSensor.ToJson();
        json["sdCard"] = sdCard.ToJson();
        json["lcdMenuItems"] = lcdMenuItems.ToJson();
        json["speaker"] = speaker.ToJson();

        return json;
    }
};

#endif // CONFIGURATION_H

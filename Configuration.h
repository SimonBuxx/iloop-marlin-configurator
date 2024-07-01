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

static constexpr auto SW_VERSION{"0.2.0"};
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

// Kinematics
static constexpr auto COREXY{false};
static constexpr auto COREXZ{false};
static constexpr auto COREYZ{false};
static constexpr auto COREYX{false};
static constexpr auto COREZX{false};
static constexpr auto COREZY{false};
static constexpr auto MARKFORGED_XY{false};
static constexpr auto MARKFORGED_YX{false};
static constexpr auto BELTPRINTER{false};
static constexpr auto POLARGRAPH{false};
static constexpr auto POLARGRAPH_MAX_BELT_LEN{1035.0f};
static constexpr auto DEFAULT_SEGMENTS_PER_SECOND{5};
static constexpr auto DELTA{false};
static constexpr auto DELTA_HOME_TO_SAFE_ZONE{false};
static constexpr auto DELTA_CALIBRATION_MENU{false};
static constexpr auto DELTA_AUTO_CALIBRATION{false};
static constexpr auto DELTA_CALIBRATION_DEFAULT_POINTS{4};
static constexpr auto PROBE_MANUALLY_STEP{0.05f};
static constexpr auto DELTA_PRINTABLE_RADIUS{140.0f};
static constexpr auto DELTA_MAX_RADIUS{140.0f};
static constexpr auto DELTA_DIAGONAL_ROD{250.0f};
static constexpr auto DELTA_HEIGHT{250.0f};
static constexpr auto DELTA_ENDSTOP_ADJ{"{ 0.0, 0.0, 0.0 }"};
static constexpr auto DELTA_RADIUS{124.0f};
static constexpr auto DELTA_TOWER_ANGLE_TRIM{"{ 0.0, 0.0, 0.0 }"};
static constexpr auto DELTA_RADIUS_TRIM_TOWER{"{ 0.0, 0.0, 0.0 }"};
static constexpr auto DELTA_DIAGONAL_ROD_TRIM_TOWER{"{ 0.0, 0.0, 0.0 }"};
static constexpr auto ENABLE_DELTA_RADIUS_TRIM_TOWER{false};
static constexpr auto ENABLE_DELTA_DIAGONAL_ROD_TRIM_TOWER{false};
static constexpr auto MORGAN_SCARA{false};
static constexpr auto MP_SCARA{false};
static constexpr auto SCARA_LINKAGE_1{150};
static constexpr auto SCARA_LINKAGE_2{150};
static constexpr auto SCARA_OFFSET_X{100};
static constexpr auto SCARA_OFFSET_Y{-56};
static constexpr auto DEBUG_SCARA_KINEMATICS{false};
static constexpr auto SCARA_FEEDRATE_SCALING{true};
static constexpr auto MIDDLE_DEAD_ZONE_R{0};
static constexpr auto THETA_HOMING_OFFSET{0};
static constexpr auto PSI_HOMING_OFFSET{0};
static constexpr auto SCARA_OFFSET_THETA1{12};
static constexpr auto SCARA_OFFSET_THETA2{131};
static constexpr auto AXEL_TPARA{false};
static constexpr auto DEBUG_TPARA_KINEMATICS{true};
static constexpr auto TPARA_LINKAGE_1{120};
static constexpr auto TPARA_LINKAGE_2{120};
static constexpr auto TPARA_OFFSET_X{0};
static constexpr auto TPARA_OFFSET_Y{0};
static constexpr auto TPARA_OFFSET_Z{0};
static constexpr auto ARTICULATED_ROBOT_ARM{false};
static constexpr auto FOAMCUTTER_XYUV{false};

// Endstops
static constexpr auto USE_XMIN_PLUG{true};
static constexpr auto USE_YMIN_PLUG{true};
static constexpr auto USE_ZMIN_PLUG{true};
static constexpr auto USE_IMIN_PLUG{false};
static constexpr auto USE_JMIN_PLUG{false};
static constexpr auto USE_KMIN_PLUG{false};
static constexpr auto USE_UMIN_PLUG{false};
static constexpr auto USE_VMIN_PLUG{false};
static constexpr auto USE_WMIN_PLUG{false};
static constexpr auto USE_XMAX_PLUG{false};
static constexpr auto USE_YMAX_PLUG{false};
static constexpr auto USE_ZMAX_PLUG{false};
static constexpr auto USE_IMAX_PLUG{false};
static constexpr auto USE_JMAX_PLUG{false};
static constexpr auto USE_KMAX_PLUG{false};
static constexpr auto USE_UMAX_PLUG{false};
static constexpr auto USE_VMAX_PLUG{false};
static constexpr auto USE_WMAX_PLUG{false};
static constexpr auto ENDSTOPPULLUPS{true};
static constexpr auto ENDSTOPPULLUP_XMIN{false};
static constexpr auto ENDSTOPPULLUP_YMIN{false};
static constexpr auto ENDSTOPPULLUP_ZMIN{false};
static constexpr auto ENDSTOPPULLUP_IMIN{false};
static constexpr auto ENDSTOPPULLUP_JMIN{false};
static constexpr auto ENDSTOPPULLUP_KMIN{false};
static constexpr auto ENDSTOPPULLUP_UMIN{false};
static constexpr auto ENDSTOPPULLUP_VMIN{false};
static constexpr auto ENDSTOPPULLUP_WMIN{false};
static constexpr auto ENDSTOPPULLUP_XMAX{false};
static constexpr auto ENDSTOPPULLUP_YMAX{false};
static constexpr auto ENDSTOPPULLUP_ZMAX{false};
static constexpr auto ENDSTOPPULLUP_IMAX{false};
static constexpr auto ENDSTOPPULLUP_JMAX{false};
static constexpr auto ENDSTOPPULLUP_KMAX{false};
static constexpr auto ENDSTOPPULLUP_UMAX{false};
static constexpr auto ENDSTOPPULLUP_VMAX{false};
static constexpr auto ENDSTOPPULLUP_WMAX{false};
static constexpr auto ENDSTOPPULLUP_ZMIN_PROBE{false};
static constexpr auto ENDSTOPPULLDOWNS{false};
static constexpr auto ENDSTOPPULLDOWN_XMIN{false};
static constexpr auto ENDSTOPPULLDOWN_YMIN{false};
static constexpr auto ENDSTOPPULLDOWN_ZMIN{false};
static constexpr auto ENDSTOPPULLDOWN_IMIN{false};
static constexpr auto ENDSTOPPULLDOWN_JMIN{false};
static constexpr auto ENDSTOPPULLDOWN_KMIN{false};
static constexpr auto ENDSTOPPULLDOWN_UMIN{false};
static constexpr auto ENDSTOPPULLDOWN_VMIN{false};
static constexpr auto ENDSTOPPULLDOWN_WMIN{false};
static constexpr auto ENDSTOPPULLDOWN_XMAX{false};
static constexpr auto ENDSTOPPULLDOWN_YMAX{false};
static constexpr auto ENDSTOPPULLDOWN_ZMAX{false};
static constexpr auto ENDSTOPPULLDOWN_IMAX{false};
static constexpr auto ENDSTOPPULLDOWN_JMAX{false};
static constexpr auto ENDSTOPPULLDOWN_KMAX{false};
static constexpr auto ENDSTOPPULLDOWN_UMAX{false};
static constexpr auto ENDSTOPPULLDOWN_VMAX{false};
static constexpr auto ENDSTOPPULLDOWN_WMAX{false};
static constexpr auto ENDSTOPPULLDOWN_ZMIN_PROBE{false};
static constexpr auto X_MIN_ENDSTOP_INVERTING{"false"};
static constexpr auto Y_MIN_ENDSTOP_INVERTING{"false"};
static constexpr auto Z_MIN_ENDSTOP_INVERTING{"false"};
static constexpr auto I_MIN_ENDSTOP_INVERTING{"false"};
static constexpr auto J_MIN_ENDSTOP_INVERTING{"false"};
static constexpr auto K_MIN_ENDSTOP_INVERTING{"false"};
static constexpr auto U_MIN_ENDSTOP_INVERTING{"false"};
static constexpr auto V_MIN_ENDSTOP_INVERTING{"false"};
static constexpr auto W_MIN_ENDSTOP_INVERTING{"false"};
static constexpr auto X_MAX_ENDSTOP_INVERTING{"false"};
static constexpr auto Y_MAX_ENDSTOP_INVERTING{"false"};
static constexpr auto Z_MAX_ENDSTOP_INVERTING{"false"};
static constexpr auto I_MAX_ENDSTOP_INVERTING{"false"};
static constexpr auto J_MAX_ENDSTOP_INVERTING{"false"};
static constexpr auto K_MAX_ENDSTOP_INVERTING{"false"};
static constexpr auto U_MAX_ENDSTOP_INVERTING{"false"};
static constexpr auto V_MAX_ENDSTOP_INVERTING{"false"};
static constexpr auto W_MAX_ENDSTOP_INVERTING{"false"};
static constexpr auto Z_MIN_PROBE_ENDSTOP_INVERTING{"false"};
static constexpr auto ENDSTOP_INTERRUPTS_FEATURE{false};
static constexpr auto ENDSTOP_NOISE_THRESHOLD{"2"};
static constexpr auto ENABLE_ENDSTOP_NOISE_THRESHOLD{false};
static constexpr auto DETECT_BROKEN_ENDSTOP{false};

// Stepper Drivers
static constexpr auto X_DRIVER_TYPE{"A4988"};
static constexpr auto Y_DRIVER_TYPE{"A4988"};
static constexpr auto Z_DRIVER_TYPE{"A4988"};
static constexpr auto X2_DRIVER_TYPE{"A4988"};
static constexpr auto Y2_DRIVER_TYPE{"A4988"};
static constexpr auto Z2_DRIVER_TYPE{"A4988"};
static constexpr auto Z3_DRIVER_TYPE{"A4988"};
static constexpr auto Z4_DRIVER_TYPE{"A4988"};
static constexpr auto ENABLE_X_DRIVER_TYPE{true};
static constexpr auto ENABLE_Y_DRIVER_TYPE{true};
static constexpr auto ENABLE_Z_DRIVER_TYPE{true};
static constexpr auto ENABLE_X2_DRIVER_TYPE{false};
static constexpr auto ENABLE_Y2_DRIVER_TYPE{false};
static constexpr auto ENABLE_Z2_DRIVER_TYPE{false};
static constexpr auto ENABLE_Z3_DRIVER_TYPE{false};
static constexpr auto ENABLE_Z4_DRIVER_TYPE{false};
static constexpr auto I_DRIVER_TYPE{"A4988"};
static constexpr auto J_DRIVER_TYPE{"A4988"};
static constexpr auto K_DRIVER_TYPE{"A4988"};
static constexpr auto ENABLE_I_DRIVER_TYPE{false};
static constexpr auto ENABLE_J_DRIVER_TYPE{false};
static constexpr auto ENABLE_K_DRIVER_TYPE{false};
static constexpr auto U_DRIVER_TYPE{"A4988"};
static constexpr auto V_DRIVER_TYPE{"A4988"};
static constexpr auto W_DRIVER_TYPE{"A4988"};
static constexpr auto ENABLE_U_DRIVER_TYPE{false};
static constexpr auto ENABLE_V_DRIVER_TYPE{false};
static constexpr auto ENABLE_W_DRIVER_TYPE{false};
static constexpr auto E0_DRIVER_TYPE{"A4988"};
static constexpr auto E1_DRIVER_TYPE{"A4988"};
static constexpr auto E2_DRIVER_TYPE{"A4988"};
static constexpr auto E3_DRIVER_TYPE{"A4988"};
static constexpr auto E4_DRIVER_TYPE{"A4988"};
static constexpr auto E5_DRIVER_TYPE{"A4988"};
static constexpr auto E6_DRIVER_TYPE{"A4988"};
static constexpr auto E7_DRIVER_TYPE{"A4988"};
static constexpr auto ENABLE_E0_DRIVER_TYPE{true};
static constexpr auto ENABLE_E1_DRIVER_TYPE{false};
static constexpr auto ENABLE_E2_DRIVER_TYPE{false};
static constexpr auto ENABLE_E3_DRIVER_TYPE{false};
static constexpr auto ENABLE_E4_DRIVER_TYPE{false};
static constexpr auto ENABLE_E5_DRIVER_TYPE{false};
static constexpr auto ENABLE_E6_DRIVER_TYPE{false};
static constexpr auto ENABLE_E7_DRIVER_TYPE{false};
static constexpr auto AXIS4_NAME{"A"};
static constexpr auto AXIS5_NAME{"B"};
static constexpr auto AXIS6_NAME{"C"};
static constexpr auto AXIS4_ROTATES{true};
static constexpr auto AXIS5_ROTATES{true};
static constexpr auto AXIS6_ROTATES{true};
static constexpr auto AXIS7_NAME{"U"};
static constexpr auto AXIS8_NAME{"V"};
static constexpr auto AXIS9_NAME{"W"};
static constexpr auto AXIS7_ROTATES{false};
static constexpr auto AXIS8_ROTATES{false};
static constexpr auto AXIS9_ROTATES{false};
static constexpr auto X_ENABLE_ON{"0"};
static constexpr auto Y_ENABLE_ON{"0"};
static constexpr auto Z_ENABLE_ON{"0"};
static constexpr auto E_ENABLE_ON{"0"};
static constexpr auto I_ENABLE_ON{"0"};
static constexpr auto J_ENABLE_ON{"0"};
static constexpr auto K_ENABLE_ON{"0"};
static constexpr auto U_ENABLE_ON{"0"};
static constexpr auto V_ENABLE_ON{"0"};
static constexpr auto W_ENABLE_ON{"0"};
static constexpr auto ENABLE_X_ENABLE_ON{true};
static constexpr auto ENABLE_Y_ENABLE_ON{true};
static constexpr auto ENABLE_Z_ENABLE_ON{true};
static constexpr auto ENABLE_E_ENABLE_ON{true};
static constexpr auto ENABLE_I_ENABLE_ON{false};
static constexpr auto ENABLE_J_ENABLE_ON{false};
static constexpr auto ENABLE_K_ENABLE_ON{false};
static constexpr auto ENABLE_U_ENABLE_ON{false};
static constexpr auto ENABLE_V_ENABLE_ON{false};
static constexpr auto ENABLE_W_ENABLE_ON{false};
static constexpr auto DISABLE_X{"false"};
static constexpr auto DISABLE_Y{"false"};
static constexpr auto DISABLE_Z{"false"};
static constexpr auto DISABLE_E{"false"};
static constexpr auto DISABLE_I{"false"};
static constexpr auto DISABLE_J{"false"};
static constexpr auto DISABLE_K{"false"};
static constexpr auto DISABLE_U{"false"};
static constexpr auto DISABLE_V{"false"};
static constexpr auto DISABLE_W{"false"};
static constexpr auto ENABLE_DISABLE_X{true};
static constexpr auto ENABLE_DISABLE_Y{true};
static constexpr auto ENABLE_DISABLE_Z{true};
static constexpr auto ENABLE_DISABLE_I{false};
static constexpr auto ENABLE_DISABLE_J{false};
static constexpr auto ENABLE_DISABLE_K{false};
static constexpr auto ENABLE_DISABLE_U{false};
static constexpr auto ENABLE_DISABLE_V{false};
static constexpr auto ENABLE_DISABLE_W{false};
static constexpr auto DISABLE_INACTIVE_EXTRUDER{true};
static constexpr auto INVERT_X_DIR{"false"};
static constexpr auto INVERT_Y_DIR{"true"};
static constexpr auto INVERT_Z_DIR{"false"};
static constexpr auto INVERT_I_DIR{"false"};
static constexpr auto INVERT_J_DIR{"false"};
static constexpr auto INVERT_K_DIR{"false"};
static constexpr auto INVERT_U_DIR{"false"};
static constexpr auto INVERT_V_DIR{"false"};
static constexpr auto INVERT_W_DIR{"false"};
static constexpr auto ENABLE_INVERT_X_DIR{true};
static constexpr auto ENABLE_INVERT_Y_DIR{true};
static constexpr auto ENABLE_INVERT_Z_DIR{true};
static constexpr auto ENABLE_INVERT_I_DIR{false};
static constexpr auto ENABLE_INVERT_J_DIR{false};
static constexpr auto ENABLE_INVERT_K_DIR{false};
static constexpr auto ENABLE_INVERT_U_DIR{false};
static constexpr auto ENABLE_INVERT_V_DIR{false};
static constexpr auto ENABLE_INVERT_W_DIR{false};
static constexpr auto INVERT_E0_DIR{"false"};
static constexpr auto INVERT_E1_DIR{"false"};
static constexpr auto INVERT_E2_DIR{"false"};
static constexpr auto INVERT_E3_DIR{"false"};
static constexpr auto INVERT_E4_DIR{"false"};
static constexpr auto INVERT_E5_DIR{"false"};
static constexpr auto INVERT_E6_DIR{"false"};
static constexpr auto INVERT_E7_DIR{"false"};
static constexpr auto DISABLE_REDUCED_ACCURACY_WARNING{false};

// Homing And Bounds
static constexpr auto NO_MOTION_BEFORE_HOMING{false};
static constexpr auto HOME_AFTER_DEACTIVATE{false};
static constexpr auto Z_IDLE_HEIGHT{0};
static constexpr auto Z_HOMING_HEIGHT{4};
static constexpr auto Z_AFTER_HOMING{10};
static constexpr auto ENABLE_Z_IDLE_HEIGHT{false};
static constexpr auto ENABLE_Z_HOMING_HEIGHT{false};
static constexpr auto ENABLE_Z_AFTER_HOMING{false};
static constexpr auto X_HOME_DIR{"MIN [-1]"};
static constexpr auto Y_HOME_DIR{"MIN [-1]"};
static constexpr auto Z_HOME_DIR{"MIN [-1]"};
static constexpr auto I_HOME_DIR{"MIN [-1]"};
static constexpr auto J_HOME_DIR{"MIN [-1]"};
static constexpr auto K_HOME_DIR{"MIN [-1]"};
static constexpr auto U_HOME_DIR{"MIN [-1]"};
static constexpr auto V_HOME_DIR{"MIN [-1]"};
static constexpr auto W_HOME_DIR{"MIN [-1]"};
static constexpr auto ENABLE_X_HOME_DIR{true};
static constexpr auto ENABLE_Y_HOME_DIR{true};
static constexpr auto ENABLE_Z_HOME_DIR{true};
static constexpr auto ENABLE_I_HOME_DIR{false};
static constexpr auto ENABLE_J_HOME_DIR{false};
static constexpr auto ENABLE_K_HOME_DIR{false};
static constexpr auto ENABLE_U_HOME_DIR{false};
static constexpr auto ENABLE_V_HOME_DIR{false};
static constexpr auto ENABLE_W_HOME_DIR{false};
static constexpr auto X_BED_SIZE{200};
static constexpr auto Y_BED_SIZE{200};
static constexpr auto X_MIN_POS{0};
static constexpr auto Y_MIN_POS{0};
static constexpr auto Z_MIN_POS{0};
static constexpr auto X_MAX_POS{200};
static constexpr auto Y_MAX_POS{200};
static constexpr auto Z_MAX_POS{200};
static constexpr auto ENABLE_X_MIN_POS{true};
static constexpr auto ENABLE_Y_MIN_POS{true};
static constexpr auto ENABLE_Z_MIN_POS{true};
static constexpr auto ENABLE_X_MAX_POS{true};
static constexpr auto ENABLE_Y_MAX_POS{true};
static constexpr auto ENABLE_Z_MAX_POS{true};
static constexpr auto I_MIN_POS{0};
static constexpr auto J_MIN_POS{0};
static constexpr auto K_MIN_POS{0};
static constexpr auto I_MAX_POS{50};
static constexpr auto J_MAX_POS{50};
static constexpr auto K_MAX_POS{50};
static constexpr auto ENABLE_I_MIN_POS{false};
static constexpr auto ENABLE_J_MIN_POS{false};
static constexpr auto ENABLE_K_MIN_POS{false};
static constexpr auto ENABLE_I_MAX_POS{false};
static constexpr auto ENABLE_J_MAX_POS{false};
static constexpr auto ENABLE_K_MAX_POS{false};
static constexpr auto U_MIN_POS{0};
static constexpr auto V_MIN_POS{0};
static constexpr auto W_MIN_POS{0};
static constexpr auto U_MAX_POS{50};
static constexpr auto V_MAX_POS{50};
static constexpr auto W_MAX_POS{50};
static constexpr auto ENABLE_U_MIN_POS{false};
static constexpr auto ENABLE_V_MIN_POS{false};
static constexpr auto ENABLE_W_MIN_POS{false};
static constexpr auto ENABLE_U_MAX_POS{false};
static constexpr auto ENABLE_V_MAX_POS{false};
static constexpr auto ENABLE_W_MAX_POS{false};
static constexpr auto MIN_SOFTWARE_ENDSTOPS{true};
static constexpr auto MIN_SOFTWARE_ENDSTOP_X{true};
static constexpr auto MIN_SOFTWARE_ENDSTOP_Y{true};
static constexpr auto MIN_SOFTWARE_ENDSTOP_Z{true};
static constexpr auto MIN_SOFTWARE_ENDSTOP_I{true};
static constexpr auto MIN_SOFTWARE_ENDSTOP_J{true};
static constexpr auto MIN_SOFTWARE_ENDSTOP_K{true};
static constexpr auto MIN_SOFTWARE_ENDSTOP_U{true};
static constexpr auto MIN_SOFTWARE_ENDSTOP_V{true};
static constexpr auto MIN_SOFTWARE_ENDSTOP_W{true};
static constexpr auto MAX_SOFTWARE_ENDSTOPS{true};
static constexpr auto MAX_SOFTWARE_ENDSTOP_X{true};
static constexpr auto MAX_SOFTWARE_ENDSTOP_Y{true};
static constexpr auto MAX_SOFTWARE_ENDSTOP_Z{true};
static constexpr auto MAX_SOFTWARE_ENDSTOP_I{true};
static constexpr auto MAX_SOFTWARE_ENDSTOP_J{true};
static constexpr auto MAX_SOFTWARE_ENDSTOP_K{true};
static constexpr auto MAX_SOFTWARE_ENDSTOP_U{true};
static constexpr auto MAX_SOFTWARE_ENDSTOP_V{true};
static constexpr auto MAX_SOFTWARE_ENDSTOP_W{true};
static constexpr auto SOFT_ENDSTOPS_MENU_ITEM{false};

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

// Bed Leveling
static constexpr auto AUTO_BED_LEVELING_3POINT{false};
static constexpr auto AUTO_BED_LEVELING_LINEAR{false};
static constexpr auto AUTO_BED_LEVELING_BILINEAR{false};
static constexpr auto AUTO_BED_LEVELING_UBL{false};
static constexpr auto MESH_BED_LEVELING{false};
static constexpr auto RESTORE_LEVELING_AFTER_G28{false};
static constexpr auto ENABLE_LEVELING_AFTER_G28{false};
static constexpr auto LEVELING_NOZZLE_TEMP{120};
static constexpr auto LEVELING_BED_TEMP{50};
static constexpr auto BD_SENSOR{false};
static constexpr auto DEBUG_LEVELING_FEATURE{false};
static constexpr auto MANUAL_PROBE_START_Z{0.2f};
static constexpr auto ENABLE_MANUAL_PROBE_START_Z{true};
static constexpr auto ENABLE_LEVELING_FADE_HEIGHT{true};
static constexpr auto DEFAULT_LEVELING_FADE_HEIGHT{10.0f};
static constexpr auto SEGMENT_LEVELED_MOVES{true};
static constexpr auto LEVELED_SEGMENT_LENGTH{5.0f};
static constexpr auto G26_MESH_VALIDATION{false};
static constexpr auto MESH_TEST_NOZZLE_SIZE{0.4f};
static constexpr auto MESH_TEST_LAYER_HEIGHT{0.2f};
static constexpr auto MESH_TEST_HOTEND_TEMP{205};
static constexpr auto MESH_TEST_BED_TEMP{60};
static constexpr auto G26_XY_FEEDRATE{20};
static constexpr auto G26_XY_FEEDRATE_TRAVEL{100};
static constexpr auto G26_RETRACT_MULTIPLIER{1.0f};
static constexpr auto PREHEAT_BEFORE_LEVELING{false};
static constexpr auto GRID_MAX_POINTS_X{3};
static constexpr auto GRID_MAX_POINTS_Y{3};
static constexpr auto PROBE_Y_FIRST{false};
static constexpr auto EXTRAPOLATE_BEYOND_GRID{false};
static constexpr auto ABL_BILINEAR_SUBDIVISION{false};
static constexpr auto BILINEAR_SUBDIVISIONS{3};
static constexpr auto MESH_EDIT_GFX_OVERLAY{false};
static constexpr auto MESH_INSET{1};
static constexpr auto GRID_MAX_POINTS_X_2{10};
static constexpr auto GRID_MAX_POINTS_Y_2{10};
static constexpr auto UBL_HILBERT_CURVE{false};
static constexpr auto UBL_MESH_EDIT_MOVES_Z{true};
static constexpr auto UBL_SAVE_ACTIVE_ON_M500{true};
static constexpr auto UBL_Z_RAISE_WHEN_OFF_MESH{2.5f};
static constexpr auto ENABLE_UBL_Z_RAISE_WHEN_OFF_MESH{false};
static constexpr auto UBL_MESH_WIZARD{false};
static constexpr auto MESH_INSET_2{10};
static constexpr auto GRID_MAX_POINTS_X_3{3};
static constexpr auto GRID_MAX_POINTS_Y_3{3};
static constexpr auto MESH_G28_REST_ORIGIN{false};
static constexpr auto LCD_BED_LEVELING{false};
static constexpr auto MESH_EDIT_Z_STEP{0.025f};
static constexpr auto LCD_PROBE_Z_RANGE{4};
static constexpr auto MESH_EDIT_MENU{false};
static constexpr auto LCD_BED_TRAMMING{false};
static constexpr auto BED_TRAMMING_INSET_LFRB{"{ 30, 30, 30, 30 }"};
static constexpr auto BED_TRAMMING_HEIGHT{0.0f};
static constexpr auto BED_TRAMMING_Z_HOP{4.0f};
static constexpr auto BED_TRAMMING_INCLUDE_CENTER{false};
static constexpr auto BED_TRAMMING_USE_PROBE{false};
static constexpr auto BED_TRAMMING_PROBE_TOLERANCE{0.1f};
static constexpr auto BED_TRAMMING_VERIFY_RAISED{true};
static constexpr auto BED_TRAMMING_AUDIO_FEEDBACK{false};
static constexpr auto BED_TRAMMING_LEVELING_ORDER{"{ LF, RF, RB, LB }"};
static constexpr auto Z_PROBE_END_SCRIPT{"G1 Z10 F12000\nG1 X15 Y330\nG1 Z0.5\nG1 Z10"};
static constexpr auto ENABLE_Z_PROBE_END_SCRIPT{false};

// Homing Options
static constexpr auto BED_CENTER_AT_0_0{false};
static constexpr auto MANUAL_X_HOME_POS{0};
static constexpr auto MANUAL_Y_HOME_POS{0};
static constexpr auto MANUAL_Z_HOME_POS{0};
static constexpr auto MANUAL_I_HOME_POS{0};
static constexpr auto MANUAL_J_HOME_POS{0};
static constexpr auto MANUAL_K_HOME_POS{0};
static constexpr auto MANUAL_U_HOME_POS{0};
static constexpr auto MANUAL_V_HOME_POS{0};
static constexpr auto MANUAL_W_HOME_POS{0};
static constexpr auto ENABLE_MANUAL_X_HOME_POS{false};
static constexpr auto ENABLE_MANUAL_Y_HOME_POS{false};
static constexpr auto ENABLE_MANUAL_Z_HOME_POS{false};
static constexpr auto ENABLE_MANUAL_I_HOME_POS{false};
static constexpr auto ENABLE_MANUAL_J_HOME_POS{false};
static constexpr auto ENABLE_MANUAL_K_HOME_POS{false};
static constexpr auto ENABLE_MANUAL_U_HOME_POS{false};
static constexpr auto ENABLE_MANUAL_V_HOME_POS{false};
static constexpr auto ENABLE_MANUAL_W_HOME_POS{false};
static constexpr auto Z_SAFE_HOMING{false};
static constexpr auto Z_SAFE_HOMING_X_POINT{0};
static constexpr auto Z_SAFE_HOMING_Y_POINT{0};
static constexpr auto ENABLE_Z_SAFE_HOMING_X_POINT{false};
static constexpr auto ENABLE_Z_SAFE_HOMING_Y_POINT{false};
static constexpr auto HOMING_FEEDRATE_MM_M{"{ (50*60), (50*60), (4*60) }"};
static constexpr auto VALIDATE_HOMING_ENDSTOPS{true};
static constexpr auto SKEW_CORRECTION{false};
static constexpr auto XY_DIAG_AC{282.8427124746f};
static constexpr auto XY_DIAG_BD{282.8427124746f};
static constexpr auto XY_SIDE_AD{200.0f};
static constexpr auto XY_SKEW_FACTOR{0.0f};
static constexpr auto ENABLE_XY_SKEW_FACTOR{false};
static constexpr auto SKEW_CORRECTION_FOR_Z{false};
static constexpr auto XZ_DIAG_AC{282.8427124746f};
static constexpr auto XZ_DIAG_BD{282.8427124746f};
static constexpr auto YZ_DIAG_AC{282.8427124746f};
static constexpr auto YZ_DIAG_BD{282.8427124746f};
static constexpr auto YZ_SIDE_AD{200.0f};
static constexpr auto XZ_SKEW_FACTOR{0.0f};
static constexpr auto YZ_SKEW_FACTOR{0.0f};
static constexpr auto ENABLE_XZ_SKEW_FACTOR{false};
static constexpr auto ENABLE_YZ_SKEW_FACTOR{false};
static constexpr auto SKEW_CORRECTION_GCODE{false};

// User Interface Language
static constexpr auto LCD_LANGUAGE{"en"};
static constexpr auto DISPLAY_CHARSET_HD44780{"JAPANESE"};
static constexpr auto LCD_INFO_SCREEN_STYLE{"0"};

// SD Card
static constexpr auto SDSUPPORT{false};
static constexpr auto SD_CHECK_AND_RETRY{false};

// LCD Menu Items
static constexpr auto NO_LCD_MENUS{false};
static constexpr auto SLIM_LCD_MENUS{false};

// Encoder
static constexpr auto ENCODER_PULSES_PER_STEP{4};
static constexpr auto ENABLE_ENCODER_PULSES_PER_STEP{false};
static constexpr auto ENCODER_STEPS_PER_MENU_ITEM{1};
static constexpr auto ENABLE_ENCODER_STEPS_PER_MENU_ITEM{false};
static constexpr auto REVERSE_ENCODER_DIRECTION{false};
static constexpr auto REVERSE_MENU_DIRECTION{false};
static constexpr auto REVERSE_SELECT_DIRECTION{false};
static constexpr auto ENCODER_NOISE_FILTER{false};
static constexpr auto ENCODER_SAMPLES{10};
static constexpr auto INDIVIDUAL_AXIS_HOMING_MENU{false};
static constexpr auto INDIVIDUAL_AXIS_HOMING_SUBMENU{false};

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
/// \brief The KinematicsConfiguration struct contains kinematics configurations
///
struct KinematicsConfiguration : public PageConfiguration
{
    bool COREXY{defaults::COREXY};
    bool COREXZ{defaults::COREXZ};
    bool COREYZ{defaults::COREYZ};
    bool COREYX{defaults::COREYX};
    bool COREZX{defaults::COREZX};
    bool COREZY{defaults::COREZY};
    bool MARKFORGED_XY{defaults::MARKFORGED_XY};
    bool MARKFORGED_YX{defaults::MARKFORGED_YX};
    bool BELTPRINTER{defaults::BELTPRINTER};
    bool POLARGRAPH{defaults::POLARGRAPH};
    double POLARGRAPH_MAX_BELT_LEN{defaults::POLARGRAPH_MAX_BELT_LEN};
    int32_t DEFAULT_SEGMENTS_PER_SECOND{defaults::DEFAULT_SEGMENTS_PER_SECOND};
    bool DELTA{defaults::DELTA};
    bool DELTA_HOME_TO_SAFE_ZONE{defaults::DELTA_HOME_TO_SAFE_ZONE};
    bool DELTA_CALIBRATION_MENU{defaults::DELTA_CALIBRATION_MENU};
    bool DELTA_AUTO_CALIBRATION{defaults::DELTA_AUTO_CALIBRATION};
    int32_t DELTA_CALIBRATION_DEFAULT_POINTS{defaults::DELTA_CALIBRATION_DEFAULT_POINTS};
    double PROBE_MANUALLY_STEP{defaults::PROBE_MANUALLY_STEP};
    double DELTA_PRINTABLE_RADIUS{defaults::DELTA_PRINTABLE_RADIUS};
    double DELTA_MAX_RADIUS{defaults::DELTA_MAX_RADIUS};
    double DELTA_DIAGONAL_ROD{defaults::DELTA_DIAGONAL_ROD};
    double DELTA_HEIGHT{defaults::DELTA_HEIGHT};
    QString DELTA_ENDSTOP_ADJ{defaults::DELTA_ENDSTOP_ADJ};
    double DELTA_RADIUS{defaults::DELTA_RADIUS};
    QString DELTA_TOWER_ANGLE_TRIM{defaults::DELTA_TOWER_ANGLE_TRIM};
    QString DELTA_RADIUS_TRIM_TOWER{defaults::DELTA_RADIUS_TRIM_TOWER};
    QString DELTA_DIAGONAL_ROD_TRIM_TOWER{defaults::DELTA_DIAGONAL_ROD_TRIM_TOWER};
    bool ENABLE_DELTA_RADIUS_TRIM_TOWER{defaults::ENABLE_DELTA_RADIUS_TRIM_TOWER};
    bool ENABLE_DELTA_DIAGONAL_ROD_TRIM_TOWER{defaults::ENABLE_DELTA_DIAGONAL_ROD_TRIM_TOWER};
    bool MORGAN_SCARA{defaults::MORGAN_SCARA};
    bool MP_SCARA{defaults::MP_SCARA};
    int32_t SCARA_LINKAGE_1{defaults::SCARA_LINKAGE_1};
    int32_t SCARA_LINKAGE_2{defaults::SCARA_LINKAGE_2};
    int32_t SCARA_OFFSET_X{defaults::SCARA_OFFSET_X};
    int32_t SCARA_OFFSET_Y{defaults::SCARA_OFFSET_Y};
    bool DEBUG_SCARA_KINEMATICS{defaults::DEBUG_SCARA_KINEMATICS};
    bool SCARA_FEEDRATE_SCALING{defaults::SCARA_FEEDRATE_SCALING};
    int32_t MIDDLE_DEAD_ZONE_R{defaults::MIDDLE_DEAD_ZONE_R};
    int32_t THETA_HOMING_OFFSET{defaults::THETA_HOMING_OFFSET};
    int32_t PSI_HOMING_OFFSET{defaults::PSI_HOMING_OFFSET};
    int32_t SCARA_OFFSET_THETA1{defaults::SCARA_OFFSET_THETA1};
    int32_t SCARA_OFFSET_THETA2{defaults::SCARA_OFFSET_THETA2};
    bool AXEL_TPARA{defaults::AXEL_TPARA};
    bool DEBUG_TPARA_KINEMATICS{defaults::DEBUG_TPARA_KINEMATICS};
    int32_t TPARA_LINKAGE_1{defaults::TPARA_LINKAGE_1};
    int32_t TPARA_LINKAGE_2{defaults::TPARA_LINKAGE_2};
    int32_t TPARA_OFFSET_X{defaults::TPARA_OFFSET_X};
    int32_t TPARA_OFFSET_Y{defaults::TPARA_OFFSET_Y};
    int32_t TPARA_OFFSET_Z{defaults::TPARA_OFFSET_Z};
    bool ARTICULATED_ROBOT_ARM{defaults::ARTICULATED_ROBOT_ARM};
    bool FOAMCUTTER_XYUV{defaults::FOAMCUTTER_XYUV};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["COREXY"] = COREXY;
        json["COREXZ"] = COREXZ;
        json["COREYZ"] = COREYZ;
        json["COREYX"] = COREYX;
        json["COREZX"] = COREZX;
        json["COREZY"] = COREZY;
        json["MARKFORGED_XY"] = MARKFORGED_XY;
        json["MARKFORGED_YX"] = MARKFORGED_YX;
        json["BELTPRINTER"] = BELTPRINTER;
        json["POLARGRAPH"] = POLARGRAPH;
        json["POLARGRAPH_MAX_BELT_LEN"] = POLARGRAPH_MAX_BELT_LEN;
        json["DEFAULT_SEGMENTS_PER_SECOND"] = DEFAULT_SEGMENTS_PER_SECOND;
        json["DELTA"] = DELTA;
        json["DELTA_HOME_TO_SAFE_ZONE"] = DELTA_HOME_TO_SAFE_ZONE;
        json["DELTA_CALIBRATION_MENU"] = DELTA_CALIBRATION_MENU;
        json["DELTA_AUTO_CALIBRATION"] = DELTA_AUTO_CALIBRATION;
        json["DELTA_CALIBRATION_DEFAULT_POINTS"] = DELTA_CALIBRATION_DEFAULT_POINTS;
        json["PROBE_MANUALLY_STEP"] = PROBE_MANUALLY_STEP;
        json["DELTA_PRINTABLE_RADIUS"] = DELTA_PRINTABLE_RADIUS;
        json["DELTA_MAX_RADIUS"] = DELTA_MAX_RADIUS;
        json["DELTA_DIAGONAL_ROD"] = DELTA_DIAGONAL_ROD;
        json["DELTA_HEIGHT"] = DELTA_HEIGHT;
        json["DELTA_ENDSTOP_ADJ"] = DELTA_ENDSTOP_ADJ;
        json["DELTA_RADIUS"] = DELTA_RADIUS;
        json["DELTA_TOWER_ANGLE_TRIM"] = DELTA_TOWER_ANGLE_TRIM;
        json["DELTA_RADIUS_TRIM_TOWER"] = DELTA_RADIUS_TRIM_TOWER;
        json["DELTA_DIAGONAL_ROD_TRIM_TOWER"] = DELTA_DIAGONAL_ROD_TRIM_TOWER;
        json["ENABLE_DELTA_RADIUS_TRIM_TOWER"] = ENABLE_DELTA_RADIUS_TRIM_TOWER;
        json["ENABLE_DELTA_DIAGONAL_ROD_TRIM_TOWER"] = ENABLE_DELTA_DIAGONAL_ROD_TRIM_TOWER;
        json["MORGAN_SCARA"] = MORGAN_SCARA;
        json["MP_SCARA"] = MP_SCARA;
        json["SCARA_LINKAGE_1"] = SCARA_LINKAGE_1;
        json["SCARA_LINKAGE_2"] = SCARA_LINKAGE_2;
        json["SCARA_OFFSET_X"] = SCARA_OFFSET_X;
        json["SCARA_OFFSET_Y"] = SCARA_OFFSET_Y;
        json["DEBUG_SCARA_KINEMATICS"] = DEBUG_SCARA_KINEMATICS;
        json["SCARA_FEEDRATE_SCALING"] = SCARA_FEEDRATE_SCALING;
        json["MIDDLE_DEAD_ZONE_R"] = MIDDLE_DEAD_ZONE_R;
        json["THETA_HOMING_OFFSET"] = THETA_HOMING_OFFSET;
        json["PSI_HOMING_OFFSET"] = PSI_HOMING_OFFSET;
        json["SCARA_OFFSET_THETA1"] = SCARA_OFFSET_THETA1;
        json["SCARA_OFFSET_THETA2"] = SCARA_OFFSET_THETA2;
        json["AXEL_TPARA"] = AXEL_TPARA;
        json["DEBUG_TPARA_KINEMATICS"] = DEBUG_TPARA_KINEMATICS;
        json["TPARA_LINKAGE_1"] = TPARA_LINKAGE_1;
        json["TPARA_LINKAGE_2"] = TPARA_LINKAGE_2;
        json["TPARA_OFFSET_X"] = TPARA_OFFSET_X;
        json["TPARA_OFFSET_Y"] = TPARA_OFFSET_Y;
        json["TPARA_OFFSET_Z"] = TPARA_OFFSET_Z;
        json["ARTICULATED_ROBOT_ARM"] = ARTICULATED_ROBOT_ARM;
        json["FOAMCUTTER_XYUV"] = FOAMCUTTER_XYUV;

        return json;
    }
};


///
/// \brief The EndstopsConfiguration struct contains endstops configurations
///
struct EndstopsConfiguration : public PageConfiguration
{
    bool USE_XMIN_PLUG{defaults::USE_XMIN_PLUG};
    bool USE_YMIN_PLUG{defaults::USE_YMIN_PLUG};
    bool USE_ZMIN_PLUG{defaults::USE_ZMIN_PLUG};
    bool USE_IMIN_PLUG{defaults::USE_IMIN_PLUG};
    bool USE_JMIN_PLUG{defaults::USE_JMIN_PLUG};
    bool USE_KMIN_PLUG{defaults::USE_KMIN_PLUG};
    bool USE_UMIN_PLUG{defaults::USE_UMIN_PLUG};
    bool USE_VMIN_PLUG{defaults::USE_VMIN_PLUG};
    bool USE_WMIN_PLUG{defaults::USE_WMIN_PLUG};
    bool USE_XMAX_PLUG{defaults::USE_XMAX_PLUG};
    bool USE_YMAX_PLUG{defaults::USE_YMAX_PLUG};
    bool USE_ZMAX_PLUG{defaults::USE_ZMAX_PLUG};
    bool USE_IMAX_PLUG{defaults::USE_IMAX_PLUG};
    bool USE_JMAX_PLUG{defaults::USE_JMAX_PLUG};
    bool USE_KMAX_PLUG{defaults::USE_KMAX_PLUG};
    bool USE_UMAX_PLUG{defaults::USE_UMAX_PLUG};
    bool USE_VMAX_PLUG{defaults::USE_VMAX_PLUG};
    bool USE_WMAX_PLUG{defaults::USE_WMAX_PLUG};
    bool ENDSTOPPULLUPS{defaults::ENDSTOPPULLUPS};
    bool ENDSTOPPULLUP_XMIN{defaults::ENDSTOPPULLUP_XMIN};
    bool ENDSTOPPULLUP_YMIN{defaults::ENDSTOPPULLUP_YMIN};
    bool ENDSTOPPULLUP_ZMIN{defaults::ENDSTOPPULLUP_ZMIN};
    bool ENDSTOPPULLUP_IMIN{defaults::ENDSTOPPULLUP_IMIN};
    bool ENDSTOPPULLUP_JMIN{defaults::ENDSTOPPULLUP_JMIN};
    bool ENDSTOPPULLUP_KMIN{defaults::ENDSTOPPULLUP_KMIN};
    bool ENDSTOPPULLUP_UMIN{defaults::ENDSTOPPULLUP_UMIN};
    bool ENDSTOPPULLUP_VMIN{defaults::ENDSTOPPULLUP_VMIN};
    bool ENDSTOPPULLUP_WMIN{defaults::ENDSTOPPULLUP_WMIN};
    bool ENDSTOPPULLUP_XMAX{defaults::ENDSTOPPULLUP_XMAX};
    bool ENDSTOPPULLUP_YMAX{defaults::ENDSTOPPULLUP_YMAX};
    bool ENDSTOPPULLUP_ZMAX{defaults::ENDSTOPPULLUP_ZMAX};
    bool ENDSTOPPULLUP_IMAX{defaults::ENDSTOPPULLUP_IMAX};
    bool ENDSTOPPULLUP_JMAX{defaults::ENDSTOPPULLUP_JMAX};
    bool ENDSTOPPULLUP_KMAX{defaults::ENDSTOPPULLUP_KMAX};
    bool ENDSTOPPULLUP_UMAX{defaults::ENDSTOPPULLUP_UMAX};
    bool ENDSTOPPULLUP_VMAX{defaults::ENDSTOPPULLUP_VMAX};
    bool ENDSTOPPULLUP_WMAX{defaults::ENDSTOPPULLUP_WMAX};
    bool ENDSTOPPULLUP_ZMIN_PROBE{defaults::ENDSTOPPULLUP_ZMIN_PROBE};
    bool ENDSTOPPULLDOWNS{defaults::ENDSTOPPULLDOWNS};
    bool ENDSTOPPULLDOWN_XMIN{defaults::ENDSTOPPULLDOWN_XMIN};
    bool ENDSTOPPULLDOWN_YMIN{defaults::ENDSTOPPULLDOWN_YMIN};
    bool ENDSTOPPULLDOWN_ZMIN{defaults::ENDSTOPPULLDOWN_ZMIN};
    bool ENDSTOPPULLDOWN_IMIN{defaults::ENDSTOPPULLDOWN_IMIN};
    bool ENDSTOPPULLDOWN_JMIN{defaults::ENDSTOPPULLDOWN_JMIN};
    bool ENDSTOPPULLDOWN_KMIN{defaults::ENDSTOPPULLDOWN_KMIN};
    bool ENDSTOPPULLDOWN_UMIN{defaults::ENDSTOPPULLDOWN_UMIN};
    bool ENDSTOPPULLDOWN_VMIN{defaults::ENDSTOPPULLDOWN_VMIN};
    bool ENDSTOPPULLDOWN_WMIN{defaults::ENDSTOPPULLDOWN_WMIN};
    bool ENDSTOPPULLDOWN_XMAX{defaults::ENDSTOPPULLDOWN_XMAX};
    bool ENDSTOPPULLDOWN_YMAX{defaults::ENDSTOPPULLDOWN_YMAX};
    bool ENDSTOPPULLDOWN_ZMAX{defaults::ENDSTOPPULLDOWN_ZMAX};
    bool ENDSTOPPULLDOWN_IMAX{defaults::ENDSTOPPULLDOWN_IMAX};
    bool ENDSTOPPULLDOWN_JMAX{defaults::ENDSTOPPULLDOWN_JMAX};
    bool ENDSTOPPULLDOWN_KMAX{defaults::ENDSTOPPULLDOWN_KMAX};
    bool ENDSTOPPULLDOWN_UMAX{defaults::ENDSTOPPULLDOWN_UMAX};
    bool ENDSTOPPULLDOWN_VMAX{defaults::ENDSTOPPULLDOWN_VMAX};
    bool ENDSTOPPULLDOWN_WMAX{defaults::ENDSTOPPULLDOWN_WMAX};
    bool ENDSTOPPULLDOWN_ZMIN_PROBE{defaults::ENDSTOPPULLDOWN_ZMIN_PROBE};
    QString X_MIN_ENDSTOP_INVERTING{defaults::X_MIN_ENDSTOP_INVERTING};
    QString Y_MIN_ENDSTOP_INVERTING{defaults::Y_MIN_ENDSTOP_INVERTING};
    QString Z_MIN_ENDSTOP_INVERTING{defaults::Z_MIN_ENDSTOP_INVERTING};
    QString I_MIN_ENDSTOP_INVERTING{defaults::I_MIN_ENDSTOP_INVERTING};
    QString J_MIN_ENDSTOP_INVERTING{defaults::J_MIN_ENDSTOP_INVERTING};
    QString K_MIN_ENDSTOP_INVERTING{defaults::K_MIN_ENDSTOP_INVERTING};
    QString U_MIN_ENDSTOP_INVERTING{defaults::U_MIN_ENDSTOP_INVERTING};
    QString V_MIN_ENDSTOP_INVERTING{defaults::V_MIN_ENDSTOP_INVERTING};
    QString W_MIN_ENDSTOP_INVERTING{defaults::W_MIN_ENDSTOP_INVERTING};
    QString X_MAX_ENDSTOP_INVERTING{defaults::X_MAX_ENDSTOP_INVERTING};
    QString Y_MAX_ENDSTOP_INVERTING{defaults::Y_MAX_ENDSTOP_INVERTING};
    QString Z_MAX_ENDSTOP_INVERTING{defaults::Z_MAX_ENDSTOP_INVERTING};
    QString I_MAX_ENDSTOP_INVERTING{defaults::I_MAX_ENDSTOP_INVERTING};
    QString J_MAX_ENDSTOP_INVERTING{defaults::J_MAX_ENDSTOP_INVERTING};
    QString K_MAX_ENDSTOP_INVERTING{defaults::K_MAX_ENDSTOP_INVERTING};
    QString U_MAX_ENDSTOP_INVERTING{defaults::U_MAX_ENDSTOP_INVERTING};
    QString V_MAX_ENDSTOP_INVERTING{defaults::V_MAX_ENDSTOP_INVERTING};
    QString W_MAX_ENDSTOP_INVERTING{defaults::W_MAX_ENDSTOP_INVERTING};
    QString Z_MIN_PROBE_ENDSTOP_INVERTING{defaults::Z_MIN_PROBE_ENDSTOP_INVERTING};
    bool ENDSTOP_INTERRUPTS_FEATURE{defaults::ENDSTOP_INTERRUPTS_FEATURE};
    QString ENDSTOP_NOISE_THRESHOLD{defaults::ENDSTOP_NOISE_THRESHOLD};
    bool ENABLE_ENDSTOP_NOISE_THRESHOLD{defaults::ENABLE_ENDSTOP_NOISE_THRESHOLD};
    bool DETECT_BROKEN_ENDSTOP{defaults::DETECT_BROKEN_ENDSTOP};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["USE_XMIN_PLUG"] = USE_XMIN_PLUG;
        json["USE_YMIN_PLUG"] = USE_YMIN_PLUG;
        json["USE_ZMIN_PLUG"] = USE_ZMIN_PLUG;
        json["USE_IMIN_PLUG"] = USE_IMIN_PLUG;
        json["USE_JMIN_PLUG"] = USE_JMIN_PLUG;
        json["USE_KMIN_PLUG"] = USE_KMIN_PLUG;
        json["USE_UMIN_PLUG"] = USE_UMIN_PLUG;
        json["USE_VMIN_PLUG"] = USE_VMIN_PLUG;
        json["USE_WMIN_PLUG"] = USE_WMIN_PLUG;
        json["USE_XMAX_PLUG"] = USE_XMAX_PLUG;
        json["USE_YMAX_PLUG"] = USE_YMAX_PLUG;
        json["USE_ZMAX_PLUG"] = USE_ZMAX_PLUG;
        json["USE_IMAX_PLUG"] = USE_IMAX_PLUG;
        json["USE_JMAX_PLUG"] = USE_JMAX_PLUG;
        json["USE_KMAX_PLUG"] = USE_KMAX_PLUG;
        json["USE_UMAX_PLUG"] = USE_UMAX_PLUG;
        json["USE_VMAX_PLUG"] = USE_VMAX_PLUG;
        json["USE_WMAX_PLUG"] = USE_WMAX_PLUG;
        json["ENDSTOPPULLUPS"] = ENDSTOPPULLUPS;
        json["ENDSTOPPULLUP_XMIN"] = ENDSTOPPULLUP_XMIN;
        json["ENDSTOPPULLUP_YMIN"] = ENDSTOPPULLUP_YMIN;
        json["ENDSTOPPULLUP_ZMIN"] = ENDSTOPPULLUP_ZMIN;
        json["ENDSTOPPULLUP_IMIN"] = ENDSTOPPULLUP_IMIN;
        json["ENDSTOPPULLUP_JMIN"] = ENDSTOPPULLUP_JMIN;
        json["ENDSTOPPULLUP_KMIN"] = ENDSTOPPULLUP_KMIN;
        json["ENDSTOPPULLUP_UMIN"] = ENDSTOPPULLUP_UMIN;
        json["ENDSTOPPULLUP_VMIN"] = ENDSTOPPULLUP_VMIN;
        json["ENDSTOPPULLUP_WMIN"] = ENDSTOPPULLUP_WMIN;
        json["ENDSTOPPULLUP_XMAX"] = ENDSTOPPULLUP_XMAX;
        json["ENDSTOPPULLUP_YMAX"] = ENDSTOPPULLUP_YMAX;
        json["ENDSTOPPULLUP_ZMAX"] = ENDSTOPPULLUP_ZMAX;
        json["ENDSTOPPULLUP_IMAX"] = ENDSTOPPULLUP_IMAX;
        json["ENDSTOPPULLUP_JMAX"] = ENDSTOPPULLUP_JMAX;
        json["ENDSTOPPULLUP_KMAX"] = ENDSTOPPULLUP_KMAX;
        json["ENDSTOPPULLUP_UMAX"] = ENDSTOPPULLUP_UMAX;
        json["ENDSTOPPULLUP_VMAX"] = ENDSTOPPULLUP_VMAX;
        json["ENDSTOPPULLUP_WMAX"] = ENDSTOPPULLUP_WMAX;
        json["ENDSTOPPULLUP_ZMIN_PROBE"] = ENDSTOPPULLUP_ZMIN_PROBE;
        json["ENDSTOPPULLDOWNS"] = ENDSTOPPULLDOWNS;
        json["ENDSTOPPULLDOWN_XMIN"] = ENDSTOPPULLDOWN_XMIN;
        json["ENDSTOPPULLDOWN_YMIN"] = ENDSTOPPULLDOWN_YMIN;
        json["ENDSTOPPULLDOWN_ZMIN"] = ENDSTOPPULLDOWN_ZMIN;
        json["ENDSTOPPULLDOWN_IMIN"] = ENDSTOPPULLDOWN_IMIN;
        json["ENDSTOPPULLDOWN_JMIN"] = ENDSTOPPULLDOWN_JMIN;
        json["ENDSTOPPULLDOWN_KMIN"] = ENDSTOPPULLDOWN_KMIN;
        json["ENDSTOPPULLDOWN_UMIN"] = ENDSTOPPULLDOWN_UMIN;
        json["ENDSTOPPULLDOWN_VMIN"] = ENDSTOPPULLDOWN_VMIN;
        json["ENDSTOPPULLDOWN_WMIN"] = ENDSTOPPULLDOWN_WMIN;
        json["ENDSTOPPULLDOWN_XMAX"] = ENDSTOPPULLDOWN_XMAX;
        json["ENDSTOPPULLDOWN_YMAX"] = ENDSTOPPULLDOWN_YMAX;
        json["ENDSTOPPULLDOWN_ZMAX"] = ENDSTOPPULLDOWN_ZMAX;
        json["ENDSTOPPULLDOWN_IMAX"] = ENDSTOPPULLDOWN_IMAX;
        json["ENDSTOPPULLDOWN_JMAX"] = ENDSTOPPULLDOWN_JMAX;
        json["ENDSTOPPULLDOWN_KMAX"] = ENDSTOPPULLDOWN_KMAX;
        json["ENDSTOPPULLDOWN_UMAX"] = ENDSTOPPULLDOWN_UMAX;
        json["ENDSTOPPULLDOWN_VMAX"] = ENDSTOPPULLDOWN_VMAX;
        json["ENDSTOPPULLDOWN_WMAX"] = ENDSTOPPULLDOWN_WMAX;
        json["ENDSTOPPULLDOWN_ZMIN_PROBE"] = ENDSTOPPULLDOWN_ZMIN_PROBE;
        json["X_MIN_ENDSTOP_INVERTING"] = X_MIN_ENDSTOP_INVERTING;
        json["Y_MIN_ENDSTOP_INVERTING"] = Y_MIN_ENDSTOP_INVERTING;
        json["Z_MIN_ENDSTOP_INVERTING"] = Z_MIN_ENDSTOP_INVERTING;
        json["I_MIN_ENDSTOP_INVERTING"] = I_MIN_ENDSTOP_INVERTING;
        json["J_MIN_ENDSTOP_INVERTING"] = J_MIN_ENDSTOP_INVERTING;
        json["K_MIN_ENDSTOP_INVERTING"] = K_MIN_ENDSTOP_INVERTING;
        json["U_MIN_ENDSTOP_INVERTING"] = U_MIN_ENDSTOP_INVERTING;
        json["V_MIN_ENDSTOP_INVERTING"] = V_MIN_ENDSTOP_INVERTING;
        json["W_MIN_ENDSTOP_INVERTING"] = W_MIN_ENDSTOP_INVERTING;
        json["X_MAX_ENDSTOP_INVERTING"] = X_MAX_ENDSTOP_INVERTING;
        json["Y_MAX_ENDSTOP_INVERTING"] = Y_MAX_ENDSTOP_INVERTING;
        json["Z_MAX_ENDSTOP_INVERTING"] = Z_MAX_ENDSTOP_INVERTING;
        json["I_MAX_ENDSTOP_INVERTING"] = I_MAX_ENDSTOP_INVERTING;
        json["J_MAX_ENDSTOP_INVERTING"] = J_MAX_ENDSTOP_INVERTING;
        json["K_MAX_ENDSTOP_INVERTING"] = K_MAX_ENDSTOP_INVERTING;
        json["U_MAX_ENDSTOP_INVERTING"] = U_MAX_ENDSTOP_INVERTING;
        json["V_MAX_ENDSTOP_INVERTING"] = V_MAX_ENDSTOP_INVERTING;
        json["W_MAX_ENDSTOP_INVERTING"] = W_MAX_ENDSTOP_INVERTING;
        json["Z_MIN_PROBE_ENDSTOP_INVERTING"] = Z_MIN_PROBE_ENDSTOP_INVERTING;
        json["ENDSTOP_INTERRUPTS_FEATURE"] = ENDSTOP_INTERRUPTS_FEATURE;
        json["ENDSTOP_NOISE_THRESHOLD"] = ENDSTOP_NOISE_THRESHOLD;
        json["ENABLE_ENDSTOP_NOISE_THRESHOLD"] = ENABLE_ENDSTOP_NOISE_THRESHOLD;
        json["DETECT_BROKEN_ENDSTOP"] = DETECT_BROKEN_ENDSTOP;

        return json;
    }
};

///
/// \brief The StepperDriversConfiguration struct contains stepper drivers configurations
///
struct StepperDriversConfiguration : public PageConfiguration
{
    QString X_DRIVER_TYPE{defaults::X_DRIVER_TYPE};
    QString Y_DRIVER_TYPE{defaults::Y_DRIVER_TYPE};
    QString Z_DRIVER_TYPE{defaults::Z_DRIVER_TYPE};
    QString X2_DRIVER_TYPE{defaults::X2_DRIVER_TYPE};
    QString Y2_DRIVER_TYPE{defaults::Y2_DRIVER_TYPE};
    QString Z2_DRIVER_TYPE{defaults::Z2_DRIVER_TYPE};
    QString Z3_DRIVER_TYPE{defaults::Z3_DRIVER_TYPE};
    QString Z4_DRIVER_TYPE{defaults::Z4_DRIVER_TYPE};
    bool ENABLE_X_DRIVER_TYPE{defaults::ENABLE_X_DRIVER_TYPE};
    bool ENABLE_Y_DRIVER_TYPE{defaults::ENABLE_Y_DRIVER_TYPE};
    bool ENABLE_Z_DRIVER_TYPE{defaults::ENABLE_Z_DRIVER_TYPE};
    bool ENABLE_X2_DRIVER_TYPE{defaults::ENABLE_X2_DRIVER_TYPE};
    bool ENABLE_Y2_DRIVER_TYPE{defaults::ENABLE_Y2_DRIVER_TYPE};
    bool ENABLE_Z2_DRIVER_TYPE{defaults::ENABLE_Z2_DRIVER_TYPE};
    bool ENABLE_Z3_DRIVER_TYPE{defaults::ENABLE_Z3_DRIVER_TYPE};
    bool ENABLE_Z4_DRIVER_TYPE{defaults::ENABLE_Z4_DRIVER_TYPE};
    QString I_DRIVER_TYPE{defaults::I_DRIVER_TYPE};
    QString J_DRIVER_TYPE{defaults::J_DRIVER_TYPE};
    QString K_DRIVER_TYPE{defaults::K_DRIVER_TYPE};
    bool ENABLE_I_DRIVER_TYPE{defaults::ENABLE_I_DRIVER_TYPE};
    bool ENABLE_J_DRIVER_TYPE{defaults::ENABLE_J_DRIVER_TYPE};
    bool ENABLE_K_DRIVER_TYPE{defaults::ENABLE_K_DRIVER_TYPE};
    QString U_DRIVER_TYPE{defaults::U_DRIVER_TYPE};
    QString V_DRIVER_TYPE{defaults::V_DRIVER_TYPE};
    QString W_DRIVER_TYPE{defaults::W_DRIVER_TYPE};
    bool ENABLE_U_DRIVER_TYPE{defaults::ENABLE_U_DRIVER_TYPE};
    bool ENABLE_V_DRIVER_TYPE{defaults::ENABLE_V_DRIVER_TYPE};
    bool ENABLE_W_DRIVER_TYPE{defaults::ENABLE_W_DRIVER_TYPE};
    QString E0_DRIVER_TYPE{defaults::E0_DRIVER_TYPE};
    QString E1_DRIVER_TYPE{defaults::E1_DRIVER_TYPE};
    QString E2_DRIVER_TYPE{defaults::E2_DRIVER_TYPE};
    QString E3_DRIVER_TYPE{defaults::E3_DRIVER_TYPE};
    QString E4_DRIVER_TYPE{defaults::E4_DRIVER_TYPE};
    QString E5_DRIVER_TYPE{defaults::E5_DRIVER_TYPE};
    QString E6_DRIVER_TYPE{defaults::E6_DRIVER_TYPE};
    QString E7_DRIVER_TYPE{defaults::E7_DRIVER_TYPE};
    bool ENABLE_E0_DRIVER_TYPE{defaults::ENABLE_E0_DRIVER_TYPE};
    bool ENABLE_E1_DRIVER_TYPE{defaults::ENABLE_E1_DRIVER_TYPE};
    bool ENABLE_E2_DRIVER_TYPE{defaults::ENABLE_E2_DRIVER_TYPE};
    bool ENABLE_E3_DRIVER_TYPE{defaults::ENABLE_E3_DRIVER_TYPE};
    bool ENABLE_E4_DRIVER_TYPE{defaults::ENABLE_E4_DRIVER_TYPE};
    bool ENABLE_E5_DRIVER_TYPE{defaults::ENABLE_E5_DRIVER_TYPE};
    bool ENABLE_E6_DRIVER_TYPE{defaults::ENABLE_E6_DRIVER_TYPE};
    bool ENABLE_E7_DRIVER_TYPE{defaults::ENABLE_E7_DRIVER_TYPE};
    QString AXIS4_NAME{defaults::AXIS4_NAME};
    QString AXIS5_NAME{defaults::AXIS5_NAME};
    QString AXIS6_NAME{defaults::AXIS6_NAME};
    bool AXIS4_ROTATES{defaults::AXIS4_ROTATES};
    bool AXIS5_ROTATES{defaults::AXIS5_ROTATES};
    bool AXIS6_ROTATES{defaults::AXIS6_ROTATES};
    QString AXIS7_NAME{defaults::AXIS7_NAME};
    QString AXIS8_NAME{defaults::AXIS8_NAME};
    QString AXIS9_NAME{defaults::AXIS9_NAME};
    bool AXIS7_ROTATES{defaults::AXIS7_ROTATES};
    bool AXIS8_ROTATES{defaults::AXIS8_ROTATES};
    bool AXIS9_ROTATES{defaults::AXIS9_ROTATES};
    QString X_ENABLE_ON{defaults::X_ENABLE_ON};
    QString Y_ENABLE_ON{defaults::Y_ENABLE_ON};
    QString Z_ENABLE_ON{defaults::Z_ENABLE_ON};
    QString E_ENABLE_ON{defaults::E_ENABLE_ON};
    QString I_ENABLE_ON{defaults::I_ENABLE_ON};
    QString J_ENABLE_ON{defaults::J_ENABLE_ON};
    QString K_ENABLE_ON{defaults::K_ENABLE_ON};
    QString U_ENABLE_ON{defaults::U_ENABLE_ON};
    QString V_ENABLE_ON{defaults::V_ENABLE_ON};
    QString W_ENABLE_ON{defaults::W_ENABLE_ON};
    bool ENABLE_X_ENABLE_ON{defaults::ENABLE_X_ENABLE_ON};
    bool ENABLE_Y_ENABLE_ON{defaults::ENABLE_Y_ENABLE_ON};
    bool ENABLE_Z_ENABLE_ON{defaults::ENABLE_Z_ENABLE_ON};
    bool ENABLE_E_ENABLE_ON{defaults::ENABLE_E_ENABLE_ON};
    bool ENABLE_I_ENABLE_ON{defaults::ENABLE_I_ENABLE_ON};
    bool ENABLE_J_ENABLE_ON{defaults::ENABLE_J_ENABLE_ON};
    bool ENABLE_K_ENABLE_ON{defaults::ENABLE_K_ENABLE_ON};
    bool ENABLE_U_ENABLE_ON{defaults::ENABLE_U_ENABLE_ON};
    bool ENABLE_V_ENABLE_ON{defaults::ENABLE_V_ENABLE_ON};
    bool ENABLE_W_ENABLE_ON{defaults::ENABLE_W_ENABLE_ON};
    QString DISABLE_X{defaults::DISABLE_X};
    QString DISABLE_Y{defaults::DISABLE_Y};
    QString DISABLE_Z{defaults::DISABLE_Z};
    QString DISABLE_E{defaults::DISABLE_E};
    QString DISABLE_I{defaults::DISABLE_I};
    QString DISABLE_J{defaults::DISABLE_J};
    QString DISABLE_K{defaults::DISABLE_K};
    QString DISABLE_U{defaults::DISABLE_U};
    QString DISABLE_V{defaults::DISABLE_V};
    QString DISABLE_W{defaults::DISABLE_W};
    bool ENABLE_DISABLE_X{defaults::ENABLE_DISABLE_X};
    bool ENABLE_DISABLE_Y{defaults::ENABLE_DISABLE_Y};
    bool ENABLE_DISABLE_Z{defaults::ENABLE_DISABLE_Z};
    bool ENABLE_DISABLE_I{defaults::ENABLE_DISABLE_I};
    bool ENABLE_DISABLE_J{defaults::ENABLE_DISABLE_J};
    bool ENABLE_DISABLE_K{defaults::ENABLE_DISABLE_K};
    bool ENABLE_DISABLE_U{defaults::ENABLE_DISABLE_U};
    bool ENABLE_DISABLE_V{defaults::ENABLE_DISABLE_V};
    bool ENABLE_DISABLE_W{defaults::ENABLE_DISABLE_W};
    bool DISABLE_INACTIVE_EXTRUDER{defaults::DISABLE_INACTIVE_EXTRUDER};
    QString INVERT_X_DIR{defaults::INVERT_X_DIR};
    QString INVERT_Y_DIR{defaults::INVERT_Y_DIR};
    QString INVERT_Z_DIR{defaults::INVERT_Z_DIR};
    QString INVERT_I_DIR{defaults::INVERT_I_DIR};
    QString INVERT_J_DIR{defaults::INVERT_J_DIR};
    QString INVERT_K_DIR{defaults::INVERT_K_DIR};
    QString INVERT_U_DIR{defaults::INVERT_U_DIR};
    QString INVERT_V_DIR{defaults::INVERT_V_DIR};
    QString INVERT_W_DIR{defaults::INVERT_W_DIR};
    bool ENABLE_INVERT_X_DIR{defaults::ENABLE_INVERT_X_DIR};
    bool ENABLE_INVERT_Y_DIR{defaults::ENABLE_INVERT_Y_DIR};
    bool ENABLE_INVERT_Z_DIR{defaults::ENABLE_INVERT_Z_DIR};
    bool ENABLE_INVERT_I_DIR{defaults::ENABLE_INVERT_I_DIR};
    bool ENABLE_INVERT_J_DIR{defaults::ENABLE_INVERT_J_DIR};
    bool ENABLE_INVERT_K_DIR{defaults::ENABLE_INVERT_K_DIR};
    bool ENABLE_INVERT_U_DIR{defaults::ENABLE_INVERT_U_DIR};
    bool ENABLE_INVERT_V_DIR{defaults::ENABLE_INVERT_V_DIR};
    bool ENABLE_INVERT_W_DIR{defaults::ENABLE_INVERT_W_DIR};
    QString INVERT_E0_DIR{defaults::INVERT_E0_DIR};
    QString INVERT_E1_DIR{defaults::INVERT_E1_DIR};
    QString INVERT_E2_DIR{defaults::INVERT_E2_DIR};
    QString INVERT_E3_DIR{defaults::INVERT_E3_DIR};
    QString INVERT_E4_DIR{defaults::INVERT_E4_DIR};
    QString INVERT_E5_DIR{defaults::INVERT_E5_DIR};
    QString INVERT_E6_DIR{defaults::INVERT_E6_DIR};
    QString INVERT_E7_DIR{defaults::INVERT_E7_DIR};
    bool DISABLE_REDUCED_ACCURACY_WARNING{defaults::DISABLE_REDUCED_ACCURACY_WARNING};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["X_DRIVER_TYPE"] = X_DRIVER_TYPE;
        json["Y_DRIVER_TYPE"] = Y_DRIVER_TYPE;
        json["Z_DRIVER_TYPE"] = Z_DRIVER_TYPE;
        json["X2_DRIVER_TYPE"] = X2_DRIVER_TYPE;
        json["Y2_DRIVER_TYPE"] = Y2_DRIVER_TYPE;
        json["Z2_DRIVER_TYPE"] = Z2_DRIVER_TYPE;
        json["Z3_DRIVER_TYPE"] = Z3_DRIVER_TYPE;
        json["Z4_DRIVER_TYPE"] = Z4_DRIVER_TYPE;
        json["ENABLE_X_DRIVER_TYPE"] = ENABLE_X_DRIVER_TYPE;
        json["ENABLE_Y_DRIVER_TYPE"] = ENABLE_Y_DRIVER_TYPE;
        json["ENABLE_Z_DRIVER_TYPE"] = ENABLE_Z_DRIVER_TYPE;
        json["ENABLE_X2_DRIVER_TYPE"] = ENABLE_X2_DRIVER_TYPE;
        json["ENABLE_Y2_DRIVER_TYPE"] = ENABLE_Y2_DRIVER_TYPE;
        json["ENABLE_Z2_DRIVER_TYPE"] = ENABLE_Z2_DRIVER_TYPE;
        json["ENABLE_Z3_DRIVER_TYPE"] = ENABLE_Z3_DRIVER_TYPE;
        json["ENABLE_Z4_DRIVER_TYPE"] = ENABLE_Z4_DRIVER_TYPE;
        json["I_DRIVER_TYPE"] = I_DRIVER_TYPE;
        json["J_DRIVER_TYPE"] = J_DRIVER_TYPE;
        json["K_DRIVER_TYPE"] = K_DRIVER_TYPE;
        json["ENABLE_I_DRIVER_TYPE"] = ENABLE_I_DRIVER_TYPE;
        json["ENABLE_J_DRIVER_TYPE"] = ENABLE_J_DRIVER_TYPE;
        json["ENABLE_K_DRIVER_TYPE"] = ENABLE_K_DRIVER_TYPE;
        json["U_DRIVER_TYPE"] = U_DRIVER_TYPE;
        json["V_DRIVER_TYPE"] = V_DRIVER_TYPE;
        json["W_DRIVER_TYPE"] = W_DRIVER_TYPE;
        json["ENABLE_U_DRIVER_TYPE"] = ENABLE_U_DRIVER_TYPE;
        json["ENABLE_V_DRIVER_TYPE"] = ENABLE_V_DRIVER_TYPE;
        json["ENABLE_W_DRIVER_TYPE"] = ENABLE_W_DRIVER_TYPE;
        json["E0_DRIVER_TYPE"] = E0_DRIVER_TYPE;
        json["E1_DRIVER_TYPE"] = E1_DRIVER_TYPE;
        json["E2_DRIVER_TYPE"] = E2_DRIVER_TYPE;
        json["E3_DRIVER_TYPE"] = E3_DRIVER_TYPE;
        json["E4_DRIVER_TYPE"] = E4_DRIVER_TYPE;
        json["E5_DRIVER_TYPE"] = E5_DRIVER_TYPE;
        json["E6_DRIVER_TYPE"] = E6_DRIVER_TYPE;
        json["E7_DRIVER_TYPE"] = E7_DRIVER_TYPE;
        json["ENABLE_E0_DRIVER_TYPE"] = ENABLE_E0_DRIVER_TYPE;
        json["ENABLE_E1_DRIVER_TYPE"] = ENABLE_E1_DRIVER_TYPE;
        json["ENABLE_E2_DRIVER_TYPE"] = ENABLE_E2_DRIVER_TYPE;
        json["ENABLE_E3_DRIVER_TYPE"] = ENABLE_E3_DRIVER_TYPE;
        json["ENABLE_E4_DRIVER_TYPE"] = ENABLE_E4_DRIVER_TYPE;
        json["ENABLE_E5_DRIVER_TYPE"] = ENABLE_E5_DRIVER_TYPE;
        json["ENABLE_E6_DRIVER_TYPE"] = ENABLE_E6_DRIVER_TYPE;
        json["ENABLE_E7_DRIVER_TYPE"] = ENABLE_E7_DRIVER_TYPE;
        json["AXIS4_NAME"] = AXIS4_NAME;
        json["AXIS5_NAME"] = AXIS5_NAME;
        json["AXIS6_NAME"] = AXIS6_NAME;
        json["AXIS4_ROTATES"] = AXIS4_ROTATES;
        json["AXIS5_ROTATES"] = AXIS5_ROTATES;
        json["AXIS6_ROTATES"] = AXIS6_ROTATES;
        json["AXIS7_NAME"] = AXIS7_NAME;
        json["AXIS8_NAME"] = AXIS8_NAME;
        json["AXIS9_NAME"] = AXIS9_NAME;
        json["AXIS7_ROTATES"] = AXIS7_ROTATES;
        json["AXIS8_ROTATES"] = AXIS8_ROTATES;
        json["AXIS9_ROTATES"] = AXIS9_ROTATES;
        json["X_ENABLE_ON"] = X_ENABLE_ON;
        json["Y_ENABLE_ON"] = Y_ENABLE_ON;
        json["Z_ENABLE_ON"] = Z_ENABLE_ON;
        json["E_ENABLE_ON"] = E_ENABLE_ON;
        json["I_ENABLE_ON"] = I_ENABLE_ON;
        json["J_ENABLE_ON"] = J_ENABLE_ON;
        json["K_ENABLE_ON"] = K_ENABLE_ON;
        json["U_ENABLE_ON"] = U_ENABLE_ON;
        json["V_ENABLE_ON"] = V_ENABLE_ON;
        json["W_ENABLE_ON"] = W_ENABLE_ON;
        json["ENABLE_X_ENABLE_ON"] = ENABLE_X_ENABLE_ON;
        json["ENABLE_Y_ENABLE_ON"] = ENABLE_Y_ENABLE_ON;
        json["ENABLE_Z_ENABLE_ON"] = ENABLE_Z_ENABLE_ON;
        json["ENABLE_E_ENABLE_ON"] = ENABLE_E_ENABLE_ON;
        json["ENABLE_I_ENABLE_ON"] = ENABLE_I_ENABLE_ON;
        json["ENABLE_J_ENABLE_ON"] = ENABLE_J_ENABLE_ON;
        json["ENABLE_K_ENABLE_ON"] = ENABLE_K_ENABLE_ON;
        json["ENABLE_U_ENABLE_ON"] = ENABLE_U_ENABLE_ON;
        json["ENABLE_V_ENABLE_ON"] = ENABLE_V_ENABLE_ON;
        json["ENABLE_W_ENABLE_ON"] = ENABLE_W_ENABLE_ON;
        json["DISABLE_X"] = DISABLE_X;
        json["DISABLE_Y"] = DISABLE_Y;
        json["DISABLE_Z"] = DISABLE_Z;
        json["DISABLE_E"] = DISABLE_E;
        json["DISABLE_I"] = DISABLE_I;
        json["DISABLE_J"] = DISABLE_J;
        json["DISABLE_K"] = DISABLE_K;
        json["DISABLE_U"] = DISABLE_U;
        json["DISABLE_V"] = DISABLE_V;
        json["DISABLE_W"] = DISABLE_W;
        json["ENABLE_DISABLE_X"] = ENABLE_DISABLE_X;
        json["ENABLE_DISABLE_Y"] = ENABLE_DISABLE_Y;
        json["ENABLE_DISABLE_Z"] = ENABLE_DISABLE_Z;
        json["ENABLE_DISABLE_I"] = ENABLE_DISABLE_I;
        json["ENABLE_DISABLE_J"] = ENABLE_DISABLE_J;
        json["ENABLE_DISABLE_K"] = ENABLE_DISABLE_K;
        json["ENABLE_DISABLE_U"] = ENABLE_DISABLE_U;
        json["ENABLE_DISABLE_V"] = ENABLE_DISABLE_V;
        json["ENABLE_DISABLE_W"] = ENABLE_DISABLE_W;
        json["DISABLE_INACTIVE_EXTRUDER"] = DISABLE_INACTIVE_EXTRUDER;
        json["INVERT_X_DIR"] = INVERT_X_DIR;
        json["INVERT_Y_DIR"] = INVERT_Y_DIR;
        json["INVERT_Z_DIR"] = INVERT_Z_DIR;
        json["INVERT_I_DIR"] = INVERT_I_DIR;
        json["INVERT_J_DIR"] = INVERT_J_DIR;
        json["INVERT_K_DIR"] = INVERT_K_DIR;
        json["INVERT_U_DIR"] = INVERT_U_DIR;
        json["INVERT_V_DIR"] = INVERT_V_DIR;
        json["INVERT_W_DIR"] = INVERT_W_DIR;
        json["ENABLE_INVERT_X_DIR"] = ENABLE_INVERT_X_DIR;
        json["ENABLE_INVERT_Y_DIR"] = ENABLE_INVERT_Y_DIR;
        json["ENABLE_INVERT_Z_DIR"] = ENABLE_INVERT_Z_DIR;
        json["ENABLE_INVERT_I_DIR"] = ENABLE_INVERT_I_DIR;
        json["ENABLE_INVERT_J_DIR"] = ENABLE_INVERT_J_DIR;
        json["ENABLE_INVERT_K_DIR"] = ENABLE_INVERT_K_DIR;
        json["ENABLE_INVERT_U_DIR"] = ENABLE_INVERT_U_DIR;
        json["ENABLE_INVERT_V_DIR"] = ENABLE_INVERT_V_DIR;
        json["ENABLE_INVERT_W_DIR"] = ENABLE_INVERT_W_DIR;
        json["INVERT_E0_DIR"] = INVERT_E0_DIR;
        json["INVERT_E1_DIR"] = INVERT_E1_DIR;
        json["INVERT_E2_DIR"] = INVERT_E2_DIR;
        json["INVERT_E3_DIR"] = INVERT_E3_DIR;
        json["INVERT_E4_DIR"] = INVERT_E4_DIR;
        json["INVERT_E5_DIR"] = INVERT_E5_DIR;
        json["INVERT_E6_DIR"] = INVERT_E6_DIR;
        json["INVERT_E7_DIR"] = INVERT_E7_DIR;
        json["DISABLE_REDUCED_ACCURACY_WARNING"] = DISABLE_REDUCED_ACCURACY_WARNING;

        return json;
    }
};

///
/// \brief The HomingAndBoundsConfiguration struct contains homing and bounds configurations
///
struct HomingAndBoundsConfiguration : public PageConfiguration
{
    bool NO_MOTION_BEFORE_HOMING{defaults::NO_MOTION_BEFORE_HOMING};
    bool HOME_AFTER_DEACTIVATE{defaults::HOME_AFTER_DEACTIVATE};
    int32_t Z_IDLE_HEIGHT{defaults::Z_IDLE_HEIGHT};
    int32_t Z_HOMING_HEIGHT{defaults::Z_HOMING_HEIGHT};
    int32_t Z_AFTER_HOMING{defaults::Z_AFTER_HOMING};
    bool ENABLE_Z_IDLE_HEIGHT{defaults::ENABLE_Z_IDLE_HEIGHT};
    bool ENABLE_Z_HOMING_HEIGHT{defaults::ENABLE_Z_HOMING_HEIGHT};
    bool ENABLE_Z_AFTER_HOMING{defaults::ENABLE_Z_AFTER_HOMING};
    QString X_HOME_DIR{defaults::X_HOME_DIR};
    QString Y_HOME_DIR{defaults::Y_HOME_DIR};
    QString Z_HOME_DIR{defaults::Z_HOME_DIR};
    QString I_HOME_DIR{defaults::I_HOME_DIR};
    QString J_HOME_DIR{defaults::J_HOME_DIR};
    QString K_HOME_DIR{defaults::K_HOME_DIR};
    QString U_HOME_DIR{defaults::U_HOME_DIR};
    QString V_HOME_DIR{defaults::V_HOME_DIR};
    QString W_HOME_DIR{defaults::W_HOME_DIR};
    bool ENABLE_X_HOME_DIR{defaults::ENABLE_X_HOME_DIR};
    bool ENABLE_Y_HOME_DIR{defaults::ENABLE_Y_HOME_DIR};
    bool ENABLE_Z_HOME_DIR{defaults::ENABLE_Z_HOME_DIR};
    bool ENABLE_I_HOME_DIR{defaults::ENABLE_I_HOME_DIR};
    bool ENABLE_J_HOME_DIR{defaults::ENABLE_J_HOME_DIR};
    bool ENABLE_K_HOME_DIR{defaults::ENABLE_K_HOME_DIR};
    bool ENABLE_U_HOME_DIR{defaults::ENABLE_U_HOME_DIR};
    bool ENABLE_V_HOME_DIR{defaults::ENABLE_V_HOME_DIR};
    bool ENABLE_W_HOME_DIR{defaults::ENABLE_W_HOME_DIR};
    int32_t X_BED_SIZE{defaults::X_BED_SIZE};
    int32_t Y_BED_SIZE{defaults::Y_BED_SIZE};
    int32_t X_MIN_POS{defaults::X_MIN_POS};
    int32_t Y_MIN_POS{defaults::Y_MIN_POS};
    int32_t Z_MIN_POS{defaults::Z_MIN_POS};
    int32_t X_MAX_POS{defaults::X_MAX_POS};
    int32_t Y_MAX_POS{defaults::Y_MAX_POS};
    int32_t Z_MAX_POS{defaults::Z_MAX_POS};
    bool ENABLE_X_MIN_POS{defaults::ENABLE_X_MIN_POS};
    bool ENABLE_Y_MIN_POS{defaults::ENABLE_Y_MIN_POS};
    bool ENABLE_Z_MIN_POS{defaults::ENABLE_Z_MIN_POS};
    bool ENABLE_X_MAX_POS{defaults::ENABLE_X_MAX_POS};
    bool ENABLE_Y_MAX_POS{defaults::ENABLE_Y_MAX_POS};
    bool ENABLE_Z_MAX_POS{defaults::ENABLE_Z_MAX_POS};
    int32_t I_MIN_POS{defaults::I_MIN_POS};
    int32_t J_MIN_POS{defaults::J_MIN_POS};
    int32_t K_MIN_POS{defaults::K_MIN_POS};
    int32_t I_MAX_POS{defaults::I_MAX_POS};
    int32_t J_MAX_POS{defaults::J_MAX_POS};
    int32_t K_MAX_POS{defaults::K_MAX_POS};
    bool ENABLE_I_MIN_POS{defaults::ENABLE_I_MIN_POS};
    bool ENABLE_J_MIN_POS{defaults::ENABLE_J_MIN_POS};
    bool ENABLE_K_MIN_POS{defaults::ENABLE_K_MIN_POS};
    bool ENABLE_I_MAX_POS{defaults::ENABLE_I_MAX_POS};
    bool ENABLE_J_MAX_POS{defaults::ENABLE_J_MAX_POS};
    bool ENABLE_K_MAX_POS{defaults::ENABLE_K_MAX_POS};
    int32_t U_MIN_POS{defaults::U_MIN_POS};
    int32_t V_MIN_POS{defaults::V_MIN_POS};
    int32_t W_MIN_POS{defaults::W_MIN_POS};
    int32_t U_MAX_POS{defaults::U_MAX_POS};
    int32_t V_MAX_POS{defaults::V_MAX_POS};
    int32_t W_MAX_POS{defaults::W_MAX_POS};
    bool ENABLE_U_MIN_POS{defaults::ENABLE_U_MIN_POS};
    bool ENABLE_V_MIN_POS{defaults::ENABLE_V_MIN_POS};
    bool ENABLE_W_MIN_POS{defaults::ENABLE_W_MIN_POS};
    bool ENABLE_U_MAX_POS{defaults::ENABLE_U_MAX_POS};
    bool ENABLE_V_MAX_POS{defaults::ENABLE_V_MAX_POS};
    bool ENABLE_W_MAX_POS{defaults::ENABLE_W_MAX_POS};
    bool MIN_SOFTWARE_ENDSTOPS{defaults::MIN_SOFTWARE_ENDSTOPS};
    bool MIN_SOFTWARE_ENDSTOP_X{defaults::MIN_SOFTWARE_ENDSTOP_X};
    bool MIN_SOFTWARE_ENDSTOP_Y{defaults::MIN_SOFTWARE_ENDSTOP_Y};
    bool MIN_SOFTWARE_ENDSTOP_Z{defaults::MIN_SOFTWARE_ENDSTOP_Z};
    bool MIN_SOFTWARE_ENDSTOP_I{defaults::MIN_SOFTWARE_ENDSTOP_I};
    bool MIN_SOFTWARE_ENDSTOP_J{defaults::MIN_SOFTWARE_ENDSTOP_J};
    bool MIN_SOFTWARE_ENDSTOP_K{defaults::MIN_SOFTWARE_ENDSTOP_K};
    bool MIN_SOFTWARE_ENDSTOP_U{defaults::MIN_SOFTWARE_ENDSTOP_U};
    bool MIN_SOFTWARE_ENDSTOP_V{defaults::MIN_SOFTWARE_ENDSTOP_V};
    bool MIN_SOFTWARE_ENDSTOP_W{defaults::MIN_SOFTWARE_ENDSTOP_W};
    bool MAX_SOFTWARE_ENDSTOPS{defaults::MAX_SOFTWARE_ENDSTOPS};
    bool MAX_SOFTWARE_ENDSTOP_X{defaults::MAX_SOFTWARE_ENDSTOP_X};
    bool MAX_SOFTWARE_ENDSTOP_Y{defaults::MAX_SOFTWARE_ENDSTOP_Y};
    bool MAX_SOFTWARE_ENDSTOP_Z{defaults::MAX_SOFTWARE_ENDSTOP_Z};
    bool MAX_SOFTWARE_ENDSTOP_I{defaults::MAX_SOFTWARE_ENDSTOP_I};
    bool MAX_SOFTWARE_ENDSTOP_J{defaults::MAX_SOFTWARE_ENDSTOP_J};
    bool MAX_SOFTWARE_ENDSTOP_K{defaults::MAX_SOFTWARE_ENDSTOP_K};
    bool MAX_SOFTWARE_ENDSTOP_U{defaults::MAX_SOFTWARE_ENDSTOP_U};
    bool MAX_SOFTWARE_ENDSTOP_V{defaults::MAX_SOFTWARE_ENDSTOP_V};
    bool MAX_SOFTWARE_ENDSTOP_W{defaults::MAX_SOFTWARE_ENDSTOP_W};
    bool SOFT_ENDSTOPS_MENU_ITEM{defaults::SOFT_ENDSTOPS_MENU_ITEM};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["NO_MOTION_BEFORE_HOMING"] = NO_MOTION_BEFORE_HOMING;
        json["HOME_AFTER_DEACTIVATE"] = HOME_AFTER_DEACTIVATE;
        json["Z_IDLE_HEIGHT"] = Z_IDLE_HEIGHT;
        json["Z_HOMING_HEIGHT"] = Z_HOMING_HEIGHT;
        json["Z_AFTER_HOMING"] = Z_AFTER_HOMING;
        json["ENABLE_Z_IDLE_HEIGHT"] = ENABLE_Z_IDLE_HEIGHT;
        json["ENABLE_Z_HOMING_HEIGHT"] = ENABLE_Z_HOMING_HEIGHT;
        json["ENABLE_Z_AFTER_HOMING"] = ENABLE_Z_AFTER_HOMING;
        json["X_HOME_DIR"] = X_HOME_DIR;
        json["Y_HOME_DIR"] = Y_HOME_DIR;
        json["Z_HOME_DIR"] = Z_HOME_DIR;
        json["I_HOME_DIR"] = I_HOME_DIR;
        json["J_HOME_DIR"] = J_HOME_DIR;
        json["K_HOME_DIR"] = K_HOME_DIR;
        json["U_HOME_DIR"] = U_HOME_DIR;
        json["V_HOME_DIR"] = V_HOME_DIR;
        json["W_HOME_DIR"] = W_HOME_DIR;
        json["ENABLE_X_HOME_DIR"] = ENABLE_X_HOME_DIR;
        json["ENABLE_Y_HOME_DIR"] = ENABLE_Y_HOME_DIR;
        json["ENABLE_Z_HOME_DIR"] = ENABLE_Z_HOME_DIR;
        json["ENABLE_I_HOME_DIR"] = ENABLE_I_HOME_DIR;
        json["ENABLE_J_HOME_DIR"] = ENABLE_J_HOME_DIR;
        json["ENABLE_K_HOME_DIR"] = ENABLE_K_HOME_DIR;
        json["ENABLE_U_HOME_DIR"] = ENABLE_U_HOME_DIR;
        json["ENABLE_V_HOME_DIR"] = ENABLE_V_HOME_DIR;
        json["ENABLE_W_HOME_DIR"] = ENABLE_W_HOME_DIR;
        json["X_BED_SIZE"] = X_BED_SIZE;
        json["Y_BED_SIZE"] = Y_BED_SIZE;
        json["X_MIN_POS"] = X_MIN_POS;
        json["Y_MIN_POS"] = Y_MIN_POS;
        json["Z_MIN_POS"] = Z_MIN_POS;
        json["X_MAX_POS"] = X_MAX_POS;
        json["Y_MAX_POS"] = Y_MAX_POS;
        json["Z_MAX_POS"] = Z_MAX_POS;
        json["ENABLE_X_MIN_POS"] = ENABLE_X_MIN_POS;
        json["ENABLE_Y_MIN_POS"] = ENABLE_Y_MIN_POS;
        json["ENABLE_Z_MIN_POS"] = ENABLE_Z_MIN_POS;
        json["ENABLE_X_MAX_POS"] = ENABLE_X_MAX_POS;
        json["ENABLE_Y_MAX_POS"] = ENABLE_Y_MAX_POS;
        json["ENABLE_Z_MAX_POS"] = ENABLE_Z_MAX_POS;
        json["I_MIN_POS"] = I_MIN_POS;
        json["J_MIN_POS"] = J_MIN_POS;
        json["K_MIN_POS"] = K_MIN_POS;
        json["I_MAX_POS"] = I_MAX_POS;
        json["J_MAX_POS"] = J_MAX_POS;
        json["K_MAX_POS"] = K_MAX_POS;
        json["ENABLE_I_MIN_POS"] = ENABLE_I_MIN_POS;
        json["ENABLE_J_MIN_POS"] = ENABLE_J_MIN_POS;
        json["ENABLE_K_MIN_POS"] = ENABLE_K_MIN_POS;
        json["ENABLE_I_MAX_POS"] = ENABLE_I_MAX_POS;
        json["ENABLE_J_MAX_POS"] = ENABLE_J_MAX_POS;
        json["ENABLE_K_MAX_POS"] = ENABLE_K_MAX_POS;
        json["U_MIN_POS"] = U_MIN_POS;
        json["V_MIN_POS"] = V_MIN_POS;
        json["W_MIN_POS"] = W_MIN_POS;
        json["U_MAX_POS"] = U_MAX_POS;
        json["V_MAX_POS"] = V_MAX_POS;
        json["W_MAX_POS"] = W_MAX_POS;
        json["ENABLE_U_MIN_POS"] = ENABLE_U_MIN_POS;
        json["ENABLE_V_MIN_POS"] = ENABLE_V_MIN_POS;
        json["ENABLE_W_MIN_POS"] = ENABLE_W_MIN_POS;
        json["ENABLE_U_MAX_POS"] = ENABLE_U_MAX_POS;
        json["ENABLE_V_MAX_POS"] = ENABLE_V_MAX_POS;
        json["ENABLE_W_MAX_POS"] = ENABLE_W_MAX_POS;
        json["MIN_SOFTWARE_ENDSTOPS"] = MIN_SOFTWARE_ENDSTOPS;
        json["MIN_SOFTWARE_ENDSTOP_X"] = MIN_SOFTWARE_ENDSTOP_X;
        json["MIN_SOFTWARE_ENDSTOP_Y"] = MIN_SOFTWARE_ENDSTOP_Y;
        json["MIN_SOFTWARE_ENDSTOP_Z"] = MIN_SOFTWARE_ENDSTOP_Z;
        json["MIN_SOFTWARE_ENDSTOP_I"] = MIN_SOFTWARE_ENDSTOP_I;
        json["MIN_SOFTWARE_ENDSTOP_J"] = MIN_SOFTWARE_ENDSTOP_J;
        json["MIN_SOFTWARE_ENDSTOP_K"] = MIN_SOFTWARE_ENDSTOP_K;
        json["MIN_SOFTWARE_ENDSTOP_U"] = MIN_SOFTWARE_ENDSTOP_U;
        json["MIN_SOFTWARE_ENDSTOP_V"] = MIN_SOFTWARE_ENDSTOP_V;
        json["MIN_SOFTWARE_ENDSTOP_W"] = MIN_SOFTWARE_ENDSTOP_W;
        json["MAX_SOFTWARE_ENDSTOPS"] = MAX_SOFTWARE_ENDSTOPS;
        json["MAX_SOFTWARE_ENDSTOP_X"] = MAX_SOFTWARE_ENDSTOP_X;
        json["MAX_SOFTWARE_ENDSTOP_Y"] = MAX_SOFTWARE_ENDSTOP_Y;
        json["MAX_SOFTWARE_ENDSTOP_Z"] = MAX_SOFTWARE_ENDSTOP_Z;
        json["MAX_SOFTWARE_ENDSTOP_I"] = MAX_SOFTWARE_ENDSTOP_I;
        json["MAX_SOFTWARE_ENDSTOP_J"] = MAX_SOFTWARE_ENDSTOP_J;
        json["MAX_SOFTWARE_ENDSTOP_K"] = MAX_SOFTWARE_ENDSTOP_K;
        json["MAX_SOFTWARE_ENDSTOP_U"] = MAX_SOFTWARE_ENDSTOP_U;
        json["MAX_SOFTWARE_ENDSTOP_V"] = MAX_SOFTWARE_ENDSTOP_V;
        json["MAX_SOFTWARE_ENDSTOP_W"] = MAX_SOFTWARE_ENDSTOP_W;
        json["SOFT_ENDSTOPS_MENU_ITEM"] = SOFT_ENDSTOPS_MENU_ITEM;

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
/// \brief The BedLevelingConfiguration struct contains bed leveling configurations
///
struct BedLevelingConfiguration : public PageConfiguration
{
    bool AUTO_BED_LEVELING_3POINT{defaults::AUTO_BED_LEVELING_3POINT};
    bool AUTO_BED_LEVELING_LINEAR{defaults::AUTO_BED_LEVELING_LINEAR};
    bool AUTO_BED_LEVELING_BILINEAR{defaults::AUTO_BED_LEVELING_BILINEAR};
    bool AUTO_BED_LEVELING_UBL{defaults::AUTO_BED_LEVELING_UBL};
    bool MESH_BED_LEVELING{defaults::MESH_BED_LEVELING};
    bool RESTORE_LEVELING_AFTER_G28{defaults::RESTORE_LEVELING_AFTER_G28};
    bool ENABLE_LEVELING_AFTER_G28{defaults::ENABLE_LEVELING_AFTER_G28};
    int32_t LEVELING_NOZZLE_TEMP{defaults::LEVELING_NOZZLE_TEMP};
    int32_t LEVELING_BED_TEMP{defaults::LEVELING_BED_TEMP};
    bool BD_SENSOR{defaults::BD_SENSOR};
    bool DEBUG_LEVELING_FEATURE{defaults::DEBUG_LEVELING_FEATURE};
    double MANUAL_PROBE_START_Z{defaults::MANUAL_PROBE_START_Z};
    bool ENABLE_MANUAL_PROBE_START_Z{defaults::ENABLE_MANUAL_PROBE_START_Z};
    bool ENABLE_LEVELING_FADE_HEIGHT{defaults::ENABLE_LEVELING_FADE_HEIGHT};
    double DEFAULT_LEVELING_FADE_HEIGHT{defaults::DEFAULT_LEVELING_FADE_HEIGHT};
    bool SEGMENT_LEVELED_MOVES{defaults::SEGMENT_LEVELED_MOVES};
    double LEVELED_SEGMENT_LENGTH{defaults::LEVELED_SEGMENT_LENGTH};
    bool G26_MESH_VALIDATION{defaults::G26_MESH_VALIDATION};
    double MESH_TEST_NOZZLE_SIZE{defaults::MESH_TEST_NOZZLE_SIZE};
    double MESH_TEST_LAYER_HEIGHT{defaults::MESH_TEST_LAYER_HEIGHT};
    int32_t MESH_TEST_HOTEND_TEMP{defaults::MESH_TEST_HOTEND_TEMP};
    int32_t MESH_TEST_BED_TEMP{defaults::MESH_TEST_BED_TEMP};
    int32_t G26_XY_FEEDRATE{defaults::G26_XY_FEEDRATE};
    int32_t G26_XY_FEEDRATE_TRAVEL{defaults::G26_XY_FEEDRATE_TRAVEL};
    double G26_RETRACT_MULTIPLIER{defaults::G26_RETRACT_MULTIPLIER};
    bool PREHEAT_BEFORE_LEVELING{defaults::PREHEAT_BEFORE_LEVELING};
    int32_t GRID_MAX_POINTS_X{defaults::GRID_MAX_POINTS_X};
    int32_t GRID_MAX_POINTS_Y{defaults::GRID_MAX_POINTS_Y};
    bool PROBE_Y_FIRST{defaults::PROBE_Y_FIRST};
    bool EXTRAPOLATE_BEYOND_GRID{defaults::EXTRAPOLATE_BEYOND_GRID};
    bool ABL_BILINEAR_SUBDIVISION{defaults::ABL_BILINEAR_SUBDIVISION};
    int32_t BILINEAR_SUBDIVISIONS{defaults::BILINEAR_SUBDIVISIONS};
    bool MESH_EDIT_GFX_OVERLAY{defaults::MESH_EDIT_GFX_OVERLAY};
    int32_t MESH_INSET{defaults::MESH_INSET};
    int32_t GRID_MAX_POINTS_X_2{defaults::GRID_MAX_POINTS_X_2};
    int32_t GRID_MAX_POINTS_Y_2{defaults::GRID_MAX_POINTS_Y_2};
    bool UBL_HILBERT_CURVE{defaults::UBL_HILBERT_CURVE};
    bool UBL_MESH_EDIT_MOVES_Z{defaults::UBL_MESH_EDIT_MOVES_Z};
    bool UBL_SAVE_ACTIVE_ON_M500{defaults::UBL_SAVE_ACTIVE_ON_M500};
    double UBL_Z_RAISE_WHEN_OFF_MESH{defaults::UBL_Z_RAISE_WHEN_OFF_MESH};
    bool ENABLE_UBL_Z_RAISE_WHEN_OFF_MESH{defaults::ENABLE_UBL_Z_RAISE_WHEN_OFF_MESH};
    bool UBL_MESH_WIZARD{defaults::UBL_MESH_WIZARD};
    int32_t MESH_INSET_2{defaults::MESH_INSET_2};
    int32_t GRID_MAX_POINTS_X_3{defaults::GRID_MAX_POINTS_X_3};
    int32_t GRID_MAX_POINTS_Y_3{defaults::GRID_MAX_POINTS_Y_3};
    bool MESH_G28_REST_ORIGIN{defaults::MESH_G28_REST_ORIGIN};
    bool LCD_BED_LEVELING{defaults::LCD_BED_LEVELING};
    double MESH_EDIT_Z_STEP{defaults::MESH_EDIT_Z_STEP};
    int32_t LCD_PROBE_Z_RANGE{defaults::LCD_PROBE_Z_RANGE};
    bool MESH_EDIT_MENU{defaults::MESH_EDIT_MENU};
    bool LCD_BED_TRAMMING{defaults::LCD_BED_TRAMMING};
    QString BED_TRAMMING_INSET_LFRB{defaults::BED_TRAMMING_INSET_LFRB};
    double BED_TRAMMING_HEIGHT{defaults::BED_TRAMMING_HEIGHT};
    double BED_TRAMMING_Z_HOP{defaults::BED_TRAMMING_Z_HOP};
    bool BED_TRAMMING_INCLUDE_CENTER{defaults::BED_TRAMMING_INCLUDE_CENTER};
    bool BED_TRAMMING_USE_PROBE{defaults::BED_TRAMMING_USE_PROBE};
    double BED_TRAMMING_PROBE_TOLERANCE{defaults::BED_TRAMMING_PROBE_TOLERANCE};
    bool BED_TRAMMING_VERIFY_RAISED{defaults::BED_TRAMMING_VERIFY_RAISED};
    bool BED_TRAMMING_AUDIO_FEEDBACK{defaults::BED_TRAMMING_AUDIO_FEEDBACK};
    QString BED_TRAMMING_LEVELING_ORDER{defaults::BED_TRAMMING_LEVELING_ORDER};
    QString Z_PROBE_END_SCRIPT{defaults::Z_PROBE_END_SCRIPT};
    bool ENABLE_Z_PROBE_END_SCRIPT{defaults::ENABLE_Z_PROBE_END_SCRIPT};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["AUTO_BED_LEVELING_3POINT"] = AUTO_BED_LEVELING_3POINT;
        json["AUTO_BED_LEVELING_LINEAR"] = AUTO_BED_LEVELING_LINEAR;
        json["AUTO_BED_LEVELING_BILINEAR"] = AUTO_BED_LEVELING_BILINEAR;
        json["AUTO_BED_LEVELING_UBL"] = AUTO_BED_LEVELING_UBL;
        json["MESH_BED_LEVELING"] = MESH_BED_LEVELING;
        json["RESTORE_LEVELING_AFTER_G28"] = RESTORE_LEVELING_AFTER_G28;
        json["ENABLE_LEVELING_AFTER_G28"] = ENABLE_LEVELING_AFTER_G28;
        json["LEVELING_NOZZLE_TEMP"] = LEVELING_NOZZLE_TEMP;
        json["LEVELING_BED_TEMP"] = LEVELING_BED_TEMP;
        json["BD_SENSOR"] = BD_SENSOR;
        json["DEBUG_LEVELING_FEATURE"] = DEBUG_LEVELING_FEATURE;
        json["MANUAL_PROBE_START_Z"] = MANUAL_PROBE_START_Z;
        json["ENABLE_MANUAL_PROBE_START_Z"] = ENABLE_MANUAL_PROBE_START_Z;
        json["ENABLE_LEVELING_FADE_HEIGHT"] = ENABLE_LEVELING_FADE_HEIGHT;
        json["DEFAULT_LEVELING_FADE_HEIGHT"] = DEFAULT_LEVELING_FADE_HEIGHT;
        json["SEGMENT_LEVELED_MOVES"] = SEGMENT_LEVELED_MOVES;
        json["LEVELED_SEGMENT_LENGTH"] = LEVELED_SEGMENT_LENGTH;
        json["G26_MESH_VALIDATION"] = G26_MESH_VALIDATION;
        json["MESH_TEST_NOZZLE_SIZE"] = MESH_TEST_NOZZLE_SIZE;
        json["MESH_TEST_LAYER_HEIGHT"] = MESH_TEST_LAYER_HEIGHT;
        json["MESH_TEST_HOTEND_TEMP"] = MESH_TEST_HOTEND_TEMP;
        json["MESH_TEST_BED_TEMP"] = MESH_TEST_BED_TEMP;
        json["G26_XY_FEEDRATE"] = G26_XY_FEEDRATE;
        json["G26_XY_FEEDRATE_TRAVEL"] = G26_XY_FEEDRATE_TRAVEL;
        json["G26_RETRACT_MULTIPLIER"] = G26_RETRACT_MULTIPLIER;
        json["PREHEAT_BEFORE_LEVELING"] = PREHEAT_BEFORE_LEVELING;
        json["GRID_MAX_POINTS_X"] = GRID_MAX_POINTS_X;
        json["GRID_MAX_POINTS_Y"] = GRID_MAX_POINTS_Y;
        json["PROBE_Y_FIRST"] = PROBE_Y_FIRST;
        json["EXTRAPOLATE_BEYOND_GRID"] = EXTRAPOLATE_BEYOND_GRID;
        json["ABL_BILINEAR_SUBDIVISION"] = ABL_BILINEAR_SUBDIVISION;
        json["BILINEAR_SUBDIVISIONS"] = BILINEAR_SUBDIVISIONS;
        json["MESH_EDIT_GFX_OVERLAY"] = MESH_EDIT_GFX_OVERLAY;
        json["MESH_INSET"] = MESH_INSET;
        json["GRID_MAX_POINTS_X_2"] = GRID_MAX_POINTS_X_2;
        json["GRID_MAX_POINTS_Y_2"] = GRID_MAX_POINTS_Y_2;
        json["UBL_HILBERT_CURVE"] = UBL_HILBERT_CURVE;
        json["UBL_MESH_EDIT_MOVES_Z"] = UBL_MESH_EDIT_MOVES_Z;
        json["UBL_SAVE_ACTIVE_ON_M500"] = UBL_SAVE_ACTIVE_ON_M500;
        json["UBL_Z_RAISE_WHEN_OFF_MESH"] = UBL_Z_RAISE_WHEN_OFF_MESH;
        json["ENABLE_UBL_Z_RAISE_WHEN_OFF_MESH"] = ENABLE_UBL_Z_RAISE_WHEN_OFF_MESH;
        json["UBL_MESH_WIZARD"] = UBL_MESH_WIZARD;
        json["MESH_INSET_2"] = MESH_INSET_2;
        json["GRID_MAX_POINTS_X_3"] = GRID_MAX_POINTS_X_3;
        json["GRID_MAX_POINTS_Y_3"] = GRID_MAX_POINTS_Y_3;
        json["MESH_G28_REST_ORIGIN"] = MESH_G28_REST_ORIGIN;
        json["LCD_BED_LEVELING"] = LCD_BED_LEVELING;
        json["MESH_EDIT_Z_STEP"] = MESH_EDIT_Z_STEP;
        json["LCD_PROBE_Z_RANGE"] = LCD_PROBE_Z_RANGE;
        json["MESH_EDIT_MENU"] = MESH_EDIT_MENU;
        json["LCD_BED_TRAMMING"] = LCD_BED_TRAMMING;
        json["BED_TRAMMING_INSET_LFRB"] = BED_TRAMMING_INSET_LFRB;
        json["BED_TRAMMING_HEIGHT"] = BED_TRAMMING_HEIGHT;
        json["BED_TRAMMING_Z_HOP"] = BED_TRAMMING_Z_HOP;
        json["BED_TRAMMING_INCLUDE_CENTER"] = BED_TRAMMING_INCLUDE_CENTER;
        json["BED_TRAMMING_USE_PROBE"] = BED_TRAMMING_USE_PROBE;
        json["BED_TRAMMING_PROBE_TOLERANCE"] = BED_TRAMMING_PROBE_TOLERANCE;
        json["BED_TRAMMING_VERIFY_RAISED"] = BED_TRAMMING_VERIFY_RAISED;
        json["BED_TRAMMING_AUDIO_FEEDBACK"] = BED_TRAMMING_AUDIO_FEEDBACK;
        json["BED_TRAMMING_LEVELING_ORDER"] = BED_TRAMMING_LEVELING_ORDER;
        json["Z_PROBE_END_SCRIPT"] = Z_PROBE_END_SCRIPT;
        json["ENABLE_Z_PROBE_END_SCRIPT"] = ENABLE_Z_PROBE_END_SCRIPT;

        return json;
    }
};

///
/// \brief The HomingOptionsConfiguration struct contains homing options configurations
///
struct HomingOptionsConfiguration : public PageConfiguration
{
    bool BED_CENTER_AT_0_0{defaults::BED_CENTER_AT_0_0};
    int32_t MANUAL_X_HOME_POS{defaults::MANUAL_X_HOME_POS};
    int32_t MANUAL_Y_HOME_POS{defaults::MANUAL_Y_HOME_POS};
    int32_t MANUAL_Z_HOME_POS{defaults::MANUAL_Z_HOME_POS};
    int32_t MANUAL_I_HOME_POS{defaults::MANUAL_I_HOME_POS};
    int32_t MANUAL_J_HOME_POS{defaults::MANUAL_J_HOME_POS};
    int32_t MANUAL_K_HOME_POS{defaults::MANUAL_K_HOME_POS};
    int32_t MANUAL_U_HOME_POS{defaults::MANUAL_U_HOME_POS};
    int32_t MANUAL_V_HOME_POS{defaults::MANUAL_V_HOME_POS};
    int32_t MANUAL_W_HOME_POS{defaults::MANUAL_W_HOME_POS};
    bool ENABLE_MANUAL_X_HOME_POS{defaults::ENABLE_MANUAL_X_HOME_POS};
    bool ENABLE_MANUAL_Y_HOME_POS{defaults::ENABLE_MANUAL_Y_HOME_POS};
    bool ENABLE_MANUAL_Z_HOME_POS{defaults::ENABLE_MANUAL_Z_HOME_POS};
    bool ENABLE_MANUAL_I_HOME_POS{defaults::ENABLE_MANUAL_I_HOME_POS};
    bool ENABLE_MANUAL_J_HOME_POS{defaults::ENABLE_MANUAL_J_HOME_POS};
    bool ENABLE_MANUAL_K_HOME_POS{defaults::ENABLE_MANUAL_K_HOME_POS};
    bool ENABLE_MANUAL_U_HOME_POS{defaults::ENABLE_MANUAL_U_HOME_POS};
    bool ENABLE_MANUAL_V_HOME_POS{defaults::ENABLE_MANUAL_V_HOME_POS};
    bool ENABLE_MANUAL_W_HOME_POS{defaults::ENABLE_MANUAL_W_HOME_POS};
    bool Z_SAFE_HOMING{defaults::Z_SAFE_HOMING};
    int32_t Z_SAFE_HOMING_X_POINT{defaults::Z_SAFE_HOMING_X_POINT};
    int32_t Z_SAFE_HOMING_Y_POINT{defaults::Z_SAFE_HOMING_Y_POINT};
    bool ENABLE_Z_SAFE_HOMING_X_POINT{defaults::ENABLE_Z_SAFE_HOMING_X_POINT};
    bool ENABLE_Z_SAFE_HOMING_Y_POINT{defaults::ENABLE_Z_SAFE_HOMING_Y_POINT};
    QString HOMING_FEEDRATE_MM_M{defaults::HOMING_FEEDRATE_MM_M};
    bool VALIDATE_HOMING_ENDSTOPS{defaults::VALIDATE_HOMING_ENDSTOPS};
    bool SKEW_CORRECTION{defaults::SKEW_CORRECTION};
    double XY_DIAG_AC{defaults::XY_DIAG_AC};
    double XY_DIAG_BD{defaults::XY_DIAG_BD};
    double XY_SIDE_AD{defaults::XY_SIDE_AD};
    double XY_SKEW_FACTOR{defaults::XY_SKEW_FACTOR};
    bool ENABLE_XY_SKEW_FACTOR{defaults::ENABLE_XY_SKEW_FACTOR};
    bool SKEW_CORRECTION_FOR_Z{defaults::SKEW_CORRECTION_FOR_Z};
    double XZ_DIAG_AC{defaults::XZ_DIAG_AC};
    double XZ_DIAG_BD{defaults::XZ_DIAG_BD};
    double YZ_DIAG_AC{defaults::YZ_DIAG_AC};
    double YZ_DIAG_BD{defaults::YZ_DIAG_BD};
    double YZ_SIDE_AD{defaults::YZ_SIDE_AD};
    double XZ_SKEW_FACTOR{defaults::XZ_SKEW_FACTOR};
    double YZ_SKEW_FACTOR{defaults::YZ_SKEW_FACTOR};
    bool ENABLE_XZ_SKEW_FACTOR{defaults::ENABLE_XZ_SKEW_FACTOR};
    bool ENABLE_YZ_SKEW_FACTOR{defaults::ENABLE_YZ_SKEW_FACTOR};
    bool SKEW_CORRECTION_GCODE{defaults::SKEW_CORRECTION_GCODE};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["BED_CENTER_AT_0_0"] = BED_CENTER_AT_0_0;
        json["MANUAL_X_HOME_POS"] = MANUAL_X_HOME_POS;
        json["MANUAL_Y_HOME_POS"] = MANUAL_Y_HOME_POS;
        json["MANUAL_Z_HOME_POS"] = MANUAL_Z_HOME_POS;
        json["MANUAL_I_HOME_POS"] = MANUAL_I_HOME_POS;
        json["MANUAL_J_HOME_POS"] = MANUAL_J_HOME_POS;
        json["MANUAL_K_HOME_POS"] = MANUAL_K_HOME_POS;
        json["MANUAL_U_HOME_POS"] = MANUAL_U_HOME_POS;
        json["MANUAL_V_HOME_POS"] = MANUAL_V_HOME_POS;
        json["MANUAL_W_HOME_POS"] = MANUAL_W_HOME_POS;
        json["ENABLE_MANUAL_X_HOME_POS"] = ENABLE_MANUAL_X_HOME_POS;
        json["ENABLE_MANUAL_Y_HOME_POS"] = ENABLE_MANUAL_Y_HOME_POS;
        json["ENABLE_MANUAL_Z_HOME_POS"] = ENABLE_MANUAL_Z_HOME_POS;
        json["ENABLE_MANUAL_I_HOME_POS"] = ENABLE_MANUAL_I_HOME_POS;
        json["ENABLE_MANUAL_J_HOME_POS"] = ENABLE_MANUAL_J_HOME_POS;
        json["ENABLE_MANUAL_K_HOME_POS"] = ENABLE_MANUAL_K_HOME_POS;
        json["ENABLE_MANUAL_U_HOME_POS"] = ENABLE_MANUAL_U_HOME_POS;
        json["ENABLE_MANUAL_V_HOME_POS"] = ENABLE_MANUAL_V_HOME_POS;
        json["ENABLE_MANUAL_W_HOME_POS"] = ENABLE_MANUAL_W_HOME_POS;
        json["Z_SAFE_HOMING"] = Z_SAFE_HOMING;
        json["Z_SAFE_HOMING_X_POINT"] = Z_SAFE_HOMING_X_POINT;
        json["Z_SAFE_HOMING_Y_POINT"] = Z_SAFE_HOMING_Y_POINT;
        json["ENABLE_Z_SAFE_HOMING_X_POINT"] = ENABLE_Z_SAFE_HOMING_X_POINT;
        json["ENABLE_Z_SAFE_HOMING_Y_POINT"] = ENABLE_Z_SAFE_HOMING_Y_POINT;
        json["HOMING_FEEDRATE_MM_M"] = HOMING_FEEDRATE_MM_M;
        json["VALIDATE_HOMING_ENDSTOPS"] = VALIDATE_HOMING_ENDSTOPS;
        json["SKEW_CORRECTION"] = SKEW_CORRECTION;
        json["XY_DIAG_AC"] = XY_DIAG_AC;
        json["XY_DIAG_BD"] = XY_DIAG_BD;
        json["XY_SIDE_AD"] = XY_SIDE_AD;
        json["XY_SKEW_FACTOR"] = XY_SKEW_FACTOR;
        json["ENABLE_XY_SKEW_FACTOR"] = ENABLE_XY_SKEW_FACTOR;
        json["SKEW_CORRECTION_FOR_Z"] = SKEW_CORRECTION_FOR_Z;
        json["XZ_DIAG_AC"] = XZ_DIAG_AC;
        json["XZ_DIAG_BD"] = XZ_DIAG_BD;
        json["YZ_DIAG_AC"] = YZ_DIAG_AC;
        json["YZ_DIAG_BD"] = YZ_DIAG_BD;
        json["YZ_SIDE_AD"] = YZ_SIDE_AD;
        json["XZ_SKEW_FACTOR"] = XZ_SKEW_FACTOR;
        json["YZ_SKEW_FACTOR"] = YZ_SKEW_FACTOR;
        json["ENABLE_XZ_SKEW_FACTOR"] = ENABLE_XZ_SKEW_FACTOR;
        json["ENABLE_YZ_SKEW_FACTOR"] = ENABLE_YZ_SKEW_FACTOR;
        json["SKEW_CORRECTION_GCODE"] = SKEW_CORRECTION_GCODE;

        return json;
    }
};

///
/// \brief The UserInterfaceLanguageConfiguration struct contains user interface language configurations
///
struct UserInterfaceLanguageConfiguration : public PageConfiguration
{
    QString LCD_LANGUAGE{defaults::LCD_LANGUAGE};
    QString DISPLAY_CHARSET_HD44780{defaults::DISPLAY_CHARSET_HD44780};
    QString LCD_INFO_SCREEN_STYLE{defaults::LCD_INFO_SCREEN_STYLE};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["LCD_LANGUAGE"] = LCD_LANGUAGE;
        json["DISPLAY_CHARSET_HD44780"] = DISPLAY_CHARSET_HD44780;
        json["LCD_INFO_SCREEN_STYLE"] = LCD_INFO_SCREEN_STYLE;

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
/// \brief The EncoderConfiguration struct contains encoder configurations
///
struct EncoderConfiguration : public PageConfiguration
{
    int32_t ENCODER_PULSES_PER_STEP{defaults::ENCODER_PULSES_PER_STEP};
    bool ENABLE_ENCODER_PULSES_PER_STEP{defaults::ENABLE_ENCODER_PULSES_PER_STEP};
    int32_t ENCODER_STEPS_PER_MENU_ITEM{defaults::ENCODER_STEPS_PER_MENU_ITEM};
    bool ENABLE_ENCODER_STEPS_PER_MENU_ITEM{defaults::ENABLE_ENCODER_STEPS_PER_MENU_ITEM};
    bool REVERSE_ENCODER_DIRECTION{defaults::REVERSE_ENCODER_DIRECTION};
    bool REVERSE_MENU_DIRECTION{defaults::REVERSE_MENU_DIRECTION};
    bool REVERSE_SELECT_DIRECTION{defaults::REVERSE_SELECT_DIRECTION};
    bool ENCODER_NOISE_FILTER{defaults::ENCODER_NOISE_FILTER};
    int32_t ENCODER_SAMPLES{defaults::ENCODER_SAMPLES};
    bool INDIVIDUAL_AXIS_HOMING_MENU{defaults::INDIVIDUAL_AXIS_HOMING_MENU};
    bool INDIVIDUAL_AXIS_HOMING_SUBMENU{defaults::INDIVIDUAL_AXIS_HOMING_SUBMENU};

public:
    /// \brief Converts the configuration into a JSON object
    ///
    /// \return a JSON object containing the configuration data
    QJsonObject ToJson(void) const override
    {
        QJsonObject json;

        json["ENCODER_PULSES_PER_STEP"] = ENCODER_PULSES_PER_STEP;
        json["ENABLE_ENCODER_PULSES_PER_STEP"] = ENABLE_ENCODER_PULSES_PER_STEP;
        json["ENCODER_STEPS_PER_MENU_ITEM"] = ENCODER_STEPS_PER_MENU_ITEM;
        json["ENABLE_ENCODER_STEPS_PER_MENU_ITEM"] = ENABLE_ENCODER_STEPS_PER_MENU_ITEM;
        json["REVERSE_ENCODER_DIRECTION"] = REVERSE_ENCODER_DIRECTION;
        json["REVERSE_MENU_DIRECTION"] = REVERSE_MENU_DIRECTION;
        json["REVERSE_SELECT_DIRECTION"] = REVERSE_SELECT_DIRECTION;
        json["ENCODER_NOISE_FILTER"] = ENCODER_NOISE_FILTER;
        json["ENCODER_SAMPLES"] = ENCODER_SAMPLES;
        json["INDIVIDUAL_AXIS_HOMING_MENU"] = INDIVIDUAL_AXIS_HOMING_MENU;
        json["INDIVIDUAL_AXIS_HOMING_SUBMENU"] = INDIVIDUAL_AXIS_HOMING_SUBMENU;

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
    KinematicsConfiguration kinematics;
    EndstopsConfiguration endstops;
    StepperDriversConfiguration stepperDrivers;
    HomingAndBoundsConfiguration homingAndBounds;
    FilamentRunoutSensorConfiguration filamentRunoutSensor;
    BedLevelingConfiguration bedLeveling;
    HomingOptionsConfiguration homingOptions;
    UserInterfaceLanguageConfiguration userInterfaceLanguage;
    SDCardConfiguration sdCard;
    LCDMenuItemsConfiguration lcdMenuItems;
    EncoderConfiguration encoder;
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
        json["kinematics"] = kinematics.ToJson();
        json["endstops"] = endstops.ToJson();
        json["stepperDrivers"] = stepperDrivers.ToJson();
        json["homingAndBounds"] = homingAndBounds.ToJson();
        json["filamentRunoutSensor"] = filamentRunoutSensor.ToJson();
        json["bedLeveling"] = bedLeveling.ToJson();
        json["homingOptions"] = homingOptions.ToJson();
        json["userInterfaceLanguage"] = userInterfaceLanguage.ToJson();
        json["sdCard"] = sdCard.ToJson();
        json["lcdMenuItems"] = lcdMenuItems.ToJson();
        json["encoder"] = encoder.ToJson();
        json["speaker"] = speaker.ToJson();

        return json;
    }
};

#endif // CONFIGURATION_H

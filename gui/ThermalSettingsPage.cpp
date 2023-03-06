/*!
 * \file ThermalSettingsPage.cpp
/// \brief The ThermalSettingsPage class represents the thermal settings page
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

#include "ThermalSettingsPage.h"
#include "./ui_ThermalSettingsPage.h"
#include "HelperFunctions.h"

ThermalSettingsPage::ThermalSettingsPage(QWidget *pParent) :
    AbstractPage(THERMALSETTINGS_TEMPLATE_PATH, pParent),
    mUi(new Ui::ThermalSettingsPage)
{
    mUi->setupUi(this);
}

ThermalSettingsPage::~ThermalSettingsPage()
{
    delete mUi;
}

void ThermalSettingsPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&]()
    {
        OpenMarlinDocumentation("thermal-settings");
    });

    QObject::connect(mUi->uTempSensor0Dropdown, &Dropdown::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uTempSensorIsMaxTc0Box->setEnabled(pIndex <= 2);
    });

    QObject::connect(mUi->uTempSensor1Dropdown, &Dropdown::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uTempSensorIsMaxTc1Box->setEnabled(pIndex <= 2);
    });

    QObject::connect(mUi->uTempSensor2Dropdown, &Dropdown::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uTempSensorIsMaxTc2Box->setEnabled(pIndex <= 2);
    });

    QObject::connect(mUi->uTempSensor0Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor1Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor2Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor3Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
});

    QObject::connect(mUi->uTempSensor4Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
            mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
            mUi->uTempWindowBox->setEnabled(hasETempSensor);
            mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor5Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor6Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensor7Dropdown, &Dropdown::currentIndexChanged, this, [&]()
    {
        const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                     mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);
        mUi->uTempResidencyTimeBox->setEnabled(hasETempSensor);
        mUi->uTempWindowBox->setEnabled(hasETempSensor);
        mUi->uTempHysteresisBox->setEnabled(hasETempSensor);
    });

    QObject::connect(mUi->uTempSensorBedDropdown, &Dropdown::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uTempBedResidencyTimeBox->setEnabled(pIndex != 53);
        mUi->uTempBedWindowBox->setEnabled(pIndex != 53);
        mUi->uTempBedHysteresisBox->setEnabled(pIndex != 53);
    });

    QObject::connect(mUi->uTempSensorChamberDropdown, &Dropdown::currentIndexChanged, this, [&](auto pIndex)
    {
        mUi->uTempChamberResidencyTimeBox->setEnabled(pIndex != 53);
        mUi->uTempChamberWindowBox->setEnabled(pIndex != 53);
        mUi->uTempChamberHysteresisBox->setEnabled(pIndex != 53);
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void ThermalSettingsPage::ResetValues()
{
    mIsLoading = true;

    mUi->uTempSensor0Dropdown->setCurrentText(defaults::TEMP_SENSOR_0);
    mUi->uTempSensor1Dropdown->setCurrentText(defaults::TEMP_SENSOR_1);
    mUi->uTempSensor2Dropdown->setCurrentText(defaults::TEMP_SENSOR_2);
    mUi->uTempSensor3Dropdown->setCurrentText(defaults::TEMP_SENSOR_3);
    mUi->uTempSensor4Dropdown->setCurrentText(defaults::TEMP_SENSOR_4);
    mUi->uTempSensor5Dropdown->setCurrentText(defaults::TEMP_SENSOR_5);
    mUi->uTempSensor6Dropdown->setCurrentText(defaults::TEMP_SENSOR_6);
    mUi->uTempSensor7Dropdown->setCurrentText(defaults::TEMP_SENSOR_7);
    mUi->uTempSensorBedDropdown->setCurrentText(defaults::TEMP_SENSOR_BED);
    mUi->uTempSensorProbeDropdown->setCurrentText(defaults::TEMP_SENSOR_PROBE);
    mUi->uTempSensorChamberDropdown->setCurrentText(defaults::TEMP_SENSOR_CHAMBER);
    mUi->uTempSensorCoolerDropdown->setCurrentText(defaults::TEMP_SENSOR_COOLER);
    mUi->uTempSensorBoardDropdown->setCurrentText(defaults::TEMP_SENSOR_BOARD);
    mUi->uTempSensorRedundantDropdown->setCurrentText(defaults::TEMP_SENSOR_REDUNDANT);
    mUi->uDummyThermistor998ValueSpinBox->setValue(defaults::DUMMY_THERMISTOR_998_VALUE);
    mUi->uDummyThermistor999ValueSpinBox->setValue(defaults::DUMMY_THERMISTOR_999_VALUE);
    mUi->uMax31865SensorOhms0SpinBox->setValue(defaults::MAX31865_SENSOR_OHMS_0);
    mUi->uMax31865CalibrationOhms0SpinBox->setValue(defaults::MAX31865_CALIBRATION_OHMS_0);
    mUi->uMax31865SensorOhms1SpinBox->setValue(defaults::MAX31865_SENSOR_OHMS_1);
    mUi->uMax31865CalibrationOhms1SpinBox->setValue(defaults::MAX31865_CALIBRATION_OHMS_1);
    mUi->uMax31865SensorOhms2SpinBox->setValue(defaults::MAX31865_SENSOR_OHMS_2);
    mUi->uMax31865CalibrationOhms2SpinBox->setValue(defaults::MAX31865_CALIBRATION_OHMS_2);
    mUi->uTempResidencyTimeSpinBox->setValue(defaults::TEMP_RESIDENCY_TIME);
    mUi->uTempWindowSpinBox->setValue(defaults::TEMP_WINDOW);
    mUi->uTempHysteresisSpinBox->setValue(defaults::TEMP_HYSTERESIS);
    mUi->uTempBedResidencyTimeSpinBox->setValue(defaults::TEMP_BED_RESIDENCY_TIME);
    mUi->uTempBedWindowSpinBox->setValue(defaults::TEMP_BED_WINDOW);
    mUi->uTempBedHysteresisSpinBox->setValue(defaults::TEMP_BED_HYSTERESIS);
    mUi->uTempChamberResidencyTimeSpinBox->setValue(defaults::TEMP_CHAMBER_RESIDENCY_TIME);
    mUi->uTempChamberWindowSpinBox->setValue(defaults::TEMP_CHAMBER_WINDOW);
    mUi->uTempChamberHysteresisSpinBox->setValue(defaults::TEMP_CHAMBER_HYSTERESIS);

    mUi->uSensorTabWidget->setCurrentIndex(0);

    mIsLoading = false;
}

bool ThermalSettingsPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uTempSensor0Dropdown, pJson, "TEMP_SENSOR_0");
    success &= LoadConfig(mUi->uTempSensor1Dropdown, pJson, "TEMP_SENSOR_1");
    success &= LoadConfig(mUi->uTempSensor2Dropdown, pJson, "TEMP_SENSOR_2");
    success &= LoadConfig(mUi->uTempSensor3Dropdown, pJson, "TEMP_SENSOR_3");
    success &= LoadConfig(mUi->uTempSensor4Dropdown, pJson, "TEMP_SENSOR_4");
    success &= LoadConfig(mUi->uTempSensor5Dropdown, pJson, "TEMP_SENSOR_5");
    success &= LoadConfig(mUi->uTempSensor6Dropdown, pJson, "TEMP_SENSOR_6");
    success &= LoadConfig(mUi->uTempSensor7Dropdown, pJson, "TEMP_SENSOR_7");
    success &= LoadConfig(mUi->uTempSensorBedDropdown, pJson, "TEMP_SENSOR_BED");
    success &= LoadConfig(mUi->uTempSensorProbeDropdown, pJson, "TEMP_SENSOR_PROBE");
    success &= LoadConfig(mUi->uTempSensorChamberDropdown, pJson, "TEMP_SENSOR_CHAMBER");
    success &= LoadConfig(mUi->uTempSensorCoolerDropdown, pJson, "TEMP_SENSOR_COOLER");
    success &= LoadConfig(mUi->uTempSensorBoardDropdown, pJson, "TEMP_SENSOR_BOARD");
    success &= LoadConfig(mUi->uTempSensorRedundantDropdown, pJson, "TEMP_SENSOR_REDUNDANT");
    success &= LoadConfig(mUi->uDummyThermistor998ValueSpinBox, pJson, "DUMMY_THERMISTOR_998_VALUE");
    success &= LoadConfig(mUi->uDummyThermistor999ValueSpinBox, pJson, "DUMMY_THERMISTOR_999_VALUE");
    success &= LoadConfig(mUi->uMax31865SensorOhms0SpinBox, pJson, "MAX31865_SENSOR_OHMS_0");
    success &= LoadConfig(mUi->uMax31865CalibrationOhms0SpinBox, pJson, "MAX31865_CALIBRATION_OHMS_0");
    success &= LoadConfig(mUi->uMax31865SensorOhms1SpinBox, pJson, "MAX31865_SENSOR_OHMS_1");
    success &= LoadConfig(mUi->uMax31865CalibrationOhms1SpinBox, pJson, "MAX31865_CALIBRATION_OHMS_1");
    success &= LoadConfig(mUi->uMax31865SensorOhms2SpinBox, pJson, "MAX31865_SENSOR_OHMS_2");
    success &= LoadConfig(mUi->uMax31865CalibrationOhms2SpinBox, pJson, "MAX31865_CALIBRATION_OHMS_2");
    success &= LoadConfig(mUi->uTempResidencyTimeSpinBox, pJson, "TEMP_RESIDENCY_TIME");
    success &= LoadConfig(mUi->uTempWindowSpinBox, pJson, "TEMP_WINDOW");
    success &= LoadConfig(mUi->uTempHysteresisSpinBox, pJson, "TEMP_HYSTERESIS");
    success &= LoadConfig(mUi->uTempBedResidencyTimeSpinBox, pJson, "TEMP_BED_RESIDENCY_TIME");
    success &= LoadConfig(mUi->uTempBedWindowSpinBox, pJson, "TEMP_BED_WINDOW");
    success &= LoadConfig(mUi->uTempBedHysteresisSpinBox, pJson, "TEMP_BED_HYSTERESIS");
    success &= LoadConfig(mUi->uTempChamberResidencyTimeSpinBox, pJson, "TEMP_CHAMBER_RESIDENCY_TIME");
    success &= LoadConfig(mUi->uTempChamberWindowSpinBox, pJson, "TEMP_CHAMBER_WINDOW");
    success &= LoadConfig(mUi->uTempChamberHysteresisSpinBox, pJson, "TEMP_CHAMBER_HYSTERESIS");

    mIsLoading = false;
    return success;
}

void ThermalSettingsPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_0, mUi->uTempSensor0Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_1, mUi->uTempSensor1Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_2, mUi->uTempSensor2Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_3, mUi->uTempSensor3Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_4, mUi->uTempSensor4Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_5, mUi->uTempSensor5Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_6, mUi->uTempSensor6Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_7, mUi->uTempSensor7Dropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_BED, mUi->uTempSensorBedDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_PROBE, mUi->uTempSensorProbeDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_CHAMBER, mUi->uTempSensorChamberDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_COOLER, mUi->uTempSensorCoolerDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_BOARD, mUi->uTempSensorBoardDropdown);
    SetConfig(pConfig.thermalSettings.TEMP_SENSOR_REDUNDANT, mUi->uTempSensorRedundantDropdown);
    SetConfig(pConfig.thermalSettings.DUMMY_THERMISTOR_998_VALUE, mUi->uDummyThermistor998ValueSpinBox);
    SetConfig(pConfig.thermalSettings.DUMMY_THERMISTOR_999_VALUE, mUi->uDummyThermistor999ValueSpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_SENSOR_OHMS_0, mUi->uMax31865SensorOhms0SpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_CALIBRATION_OHMS_0, mUi->uMax31865CalibrationOhms0SpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_SENSOR_OHMS_1, mUi->uMax31865SensorOhms1SpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_CALIBRATION_OHMS_1, mUi->uMax31865CalibrationOhms1SpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_SENSOR_OHMS_2, mUi->uMax31865SensorOhms2SpinBox);
    SetConfig(pConfig.thermalSettings.MAX31865_CALIBRATION_OHMS_2, mUi->uMax31865CalibrationOhms2SpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_RESIDENCY_TIME, mUi->uTempResidencyTimeSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_WINDOW, mUi->uTempWindowSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_HYSTERESIS, mUi->uTempHysteresisSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_BED_RESIDENCY_TIME, mUi->uTempBedResidencyTimeSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_BED_WINDOW, mUi->uTempBedWindowSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_BED_HYSTERESIS, mUi->uTempBedHysteresisSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_CHAMBER_RESIDENCY_TIME, mUi->uTempChamberResidencyTimeSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_CHAMBER_WINDOW, mUi->uTempChamberWindowSpinBox);
    SetConfig(pConfig.thermalSettings.TEMP_CHAMBER_HYSTERESIS, mUi->uTempChamberHysteresisSpinBox);
}

void ThermalSettingsPage::ReplaceTags(QStringList& pOutput)
{
    const bool hasETempSensor = (mUi->uTempSensor0Dropdown->currentIndex() != 53 || mUi->uTempSensor1Dropdown->currentIndex() != 53 || mUi->uTempSensor2Dropdown->currentIndex() != 53 || mUi->uTempSensor3Dropdown->currentIndex() != 53 &&
                                 mUi->uTempSensor4Dropdown->currentIndex() != 53 || mUi->uTempSensor5Dropdown->currentIndex() != 53 || mUi->uTempSensor6Dropdown->currentIndex() != 53 || mUi->uTempSensor7Dropdown->currentIndex() != 53);

    ReplaceTag(pOutput, "#{TEMP_SENSOR_0}", mUi->uTempSensor0Dropdown, false, "TEMP_SENSOR_0", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_1}", mUi->uTempSensor1Dropdown, false, "TEMP_SENSOR_1", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_2}", mUi->uTempSensor2Dropdown, false, "TEMP_SENSOR_2", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_3}", mUi->uTempSensor3Dropdown, false, "TEMP_SENSOR_3", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_4}", mUi->uTempSensor4Dropdown, false, "TEMP_SENSOR_4", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_5}", mUi->uTempSensor5Dropdown, false, "TEMP_SENSOR_5", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_6}", mUi->uTempSensor6Dropdown, false, "TEMP_SENSOR_6", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_7}", mUi->uTempSensor7Dropdown, false, "TEMP_SENSOR_7", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_BED}", mUi->uTempSensorBedDropdown, false, "TEMP_SENSOR_BED", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_PROBE}", mUi->uTempSensorProbeDropdown, false, "TEMP_SENSOR_PROBE", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_CHAMBER}", mUi->uTempSensorChamberDropdown, false, "TEMP_SENSOR_CHAMBER", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_COOLER}", mUi->uTempSensorCoolerDropdown, false, "TEMP_SENSOR_COOLER", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_BOARD}", mUi->uTempSensorBoardDropdown, false, "TEMP_SENSOR_BOARD", true);
    ReplaceTag(pOutput, "#{TEMP_SENSOR_REDUNDANT}", mUi->uTempSensorRedundantDropdown, false, "TEMP_SENSOR_REDUNDANT", true);
    ReplaceTag(pOutput, "#{DUMMY_THERMISTOR_998_VALUE}", mUi->uDummyThermistor998ValueSpinBox, false, "DUMMY_THERMISTOR_998_VALUE");
    ReplaceTag(pOutput, "#{DUMMY_THERMISTOR_999_VALUE}", mUi->uDummyThermistor999ValueSpinBox, false, "DUMMY_THERMISTOR_999_VALUE");
    ReplaceTag(pOutput, "#{MAX31865_SENSOR_OHMS_0}", mUi->uMax31865SensorOhms0SpinBox, mUi->uTempSensor0Dropdown->currentIndex() > 2, "MAX31865_SENSOR_OHMS_0");
    ReplaceTag(pOutput, "#{MAX31865_CALIBRATION_OHMS_0}", mUi->uMax31865CalibrationOhms0SpinBox, mUi->uTempSensor0Dropdown->currentIndex() > 2, "MAX31865_CALIBRATION_OHMS_0");
    ReplaceTag(pOutput, "#{MAX31865_SENSOR_OHMS_1}", mUi->uMax31865SensorOhms1SpinBox, mUi->uTempSensor1Dropdown->currentIndex() > 2, "MAX31865_SENSOR_OHMS_1");
    ReplaceTag(pOutput, "#{MAX31865_CALIBRATION_OHMS_1}", mUi->uMax31865CalibrationOhms1SpinBox, mUi->uTempSensor1Dropdown->currentIndex() > 2, "MAX31865_CALIBRATION_OHMS_1");
    ReplaceTag(pOutput, "#{MAX31865_SENSOR_OHMS_2}", mUi->uMax31865SensorOhms2SpinBox, mUi->uTempSensor2Dropdown->currentIndex() > 2, "MAX31865_SENSOR_OHMS_2");
    ReplaceTag(pOutput, "#{MAX31865_CALIBRATION_OHMS_2}", mUi->uMax31865CalibrationOhms2SpinBox, mUi->uTempSensor2Dropdown->currentIndex() > 2, "MAX31865_CALIBRATION_OHMS_2");
    ReplaceTag(pOutput, "#{TEMP_RESIDENCY_TIME}", mUi->uTempResidencyTimeSpinBox, !hasETempSensor, "TEMP_RESIDENCY_TIME");
    ReplaceTag(pOutput, "#{TEMP_WINDOW}", mUi->uTempWindowSpinBox, !hasETempSensor, "TEMP_WINDOW");
    ReplaceTag(pOutput, "#{TEMP_HYSTERESIS}", mUi->uTempHysteresisSpinBox, !hasETempSensor, "TEMP_HYSTERESIS");
    ReplaceTag(pOutput, "#{TEMP_BED_RESIDENCY_TIME}", mUi->uTempBedResidencyTimeSpinBox, mUi->uTempSensorBedDropdown->currentIndex() == 53, "TEMP_BED_RESIDENCY_TIME");
    ReplaceTag(pOutput, "#{TEMP_BED_WINDOW}", mUi->uTempBedWindowSpinBox, mUi->uTempSensorBedDropdown->currentIndex() == 53, "TEMP_BED_WINDOW");
    ReplaceTag(pOutput, "#{TEMP_BED_HYSTERESIS}", mUi->uTempBedHysteresisSpinBox, mUi->uTempSensorBedDropdown->currentIndex() == 53, "TEMP_BED_HYSTERESIS");
    ReplaceTag(pOutput, "#{TEMP_CHAMBER_RESIDENCY_TIME}", mUi->uTempChamberResidencyTimeSpinBox, mUi->uTempSensorChamberDropdown->currentIndex() == 53, "TEMP_CHAMBER_RESIDENCY_TIME");
    ReplaceTag(pOutput, "#{TEMP_CHAMBER_WINDOW}", mUi->uTempChamberWindowSpinBox, mUi->uTempSensorChamberDropdown->currentIndex() == 53, "TEMP_CHAMBER_WINDOW");
    ReplaceTag(pOutput, "#{TEMP_CHAMBER_HYSTERESIS}", mUi->uTempChamberHysteresisSpinBox, mUi->uTempSensorChamberDropdown->currentIndex() == 53, "TEMP_CHAMBER_HYSTERESIS");
}

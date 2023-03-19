/*!
 * \file EndstopsPage.cpp
/// \brief The EndstopsPage class represents the endstops page
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

#include "EndstopsPage.h"
#include "./ui_EndstopsPage.h"
#include "HelperFunctions.h"

EndstopsPage::EndstopsPage(QWidget *pParent) :
    AbstractPage(ENDSTOPS_TEMPLATE_PATH, pParent),
    mUi(new Ui::EndstopsPage)
{
    mUi->setupUi(this);
}

EndstopsPage::~EndstopsPage()
{
    delete mUi;
}

void EndstopsPage::ConnectGuiSignalsAndSlots()
{
    QObject::connect(mUi->uDocumentationButton, &QPushButton::clicked, this, [&](){
        OpenMarlinDocumentation("endstops");
    });

    QObject::connect(mUi->uEndstoppullupsBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uEndstopsPullupsTabWidget->setEnabled(!pChecked);
        mUi->uEndstoppullupZminProbeBox->setEnabled(!pChecked);
    });

    QObject::connect(mUi->uEndstoppulldownsBox, &QGroupBox::toggled, this, [&](auto pChecked){
        mUi->uEndstopsPulldownsTabWidget->setEnabled(!pChecked);
        mUi->uEndstoppulldownZminProbeBox->setEnabled(!pChecked);
    });

    AbstractPage::ConnectGuiSignalsAndSlots();
}

void EndstopsPage::ResetValues()
{
    mIsLoading = true;

    mUi->uUseXminPlugBox->setChecked(defaults::USE_XMIN_PLUG);
    mUi->uUseYminPlugBox->setChecked(defaults::USE_YMIN_PLUG);
    mUi->uUseZminPlugBox->setChecked(defaults::USE_ZMIN_PLUG);
    mUi->uUseIminPlugBox->setChecked(defaults::USE_IMIN_PLUG);
    mUi->uUseJminPlugBox->setChecked(defaults::USE_JMIN_PLUG);
    mUi->uUseKminPlugBox->setChecked(defaults::USE_KMIN_PLUG);
    mUi->uUseUminPlugBox->setChecked(defaults::USE_UMIN_PLUG);
    mUi->uUseVminPlugBox->setChecked(defaults::USE_VMIN_PLUG);
    mUi->uUseWminPlugBox->setChecked(defaults::USE_WMIN_PLUG);
    mUi->uUseXmaxPlugBox->setChecked(defaults::USE_XMAX_PLUG);
    mUi->uUseYmaxPlugBox->setChecked(defaults::USE_YMAX_PLUG);
    mUi->uUseZmaxPlugBox->setChecked(defaults::USE_ZMAX_PLUG);
    mUi->uUseImaxPlugBox->setChecked(defaults::USE_IMAX_PLUG);
    mUi->uUseJmaxPlugBox->setChecked(defaults::USE_JMAX_PLUG);
    mUi->uUseKmaxPlugBox->setChecked(defaults::USE_KMAX_PLUG);
    mUi->uUseUmaxPlugBox->setChecked(defaults::USE_UMAX_PLUG);
    mUi->uUseVmaxPlugBox->setChecked(defaults::USE_VMAX_PLUG);
    mUi->uUseWmaxPlugBox->setChecked(defaults::USE_WMAX_PLUG);
    mUi->uEndstoppullupsBox->setChecked(defaults::ENDSTOPPULLUPS);
    mUi->uEndstoppullupXminBox->setChecked(defaults::ENDSTOPPULLUP_XMIN);
    mUi->uEndstoppullupYminBox->setChecked(defaults::ENDSTOPPULLUP_YMIN);
    mUi->uEndstoppullupZminBox->setChecked(defaults::ENDSTOPPULLUP_ZMIN);
    mUi->uEndstoppullupIminBox->setChecked(defaults::ENDSTOPPULLUP_IMIN);
    mUi->uEndstoppullupJminBox->setChecked(defaults::ENDSTOPPULLUP_JMIN);
    mUi->uEndstoppullupKminBox->setChecked(defaults::ENDSTOPPULLUP_KMIN);
    mUi->uEndstoppullupUminBox->setChecked(defaults::ENDSTOPPULLUP_UMIN);
    mUi->uEndstoppullupVminBox->setChecked(defaults::ENDSTOPPULLUP_VMIN);
    mUi->uEndstoppullupWminBox->setChecked(defaults::ENDSTOPPULLUP_WMIN);
    mUi->uEndstoppullupXmaxBox->setChecked(defaults::ENDSTOPPULLUP_XMAX);
    mUi->uEndstoppullupYmaxBox->setChecked(defaults::ENDSTOPPULLUP_YMAX);
    mUi->uEndstoppullupZmaxBox->setChecked(defaults::ENDSTOPPULLUP_ZMAX);
    mUi->uEndstoppullupImaxBox->setChecked(defaults::ENDSTOPPULLUP_IMAX);
    mUi->uEndstoppullupJmaxBox->setChecked(defaults::ENDSTOPPULLUP_JMAX);
    mUi->uEndstoppullupKmaxBox->setChecked(defaults::ENDSTOPPULLUP_KMAX);
    mUi->uEndstoppullupUmaxBox->setChecked(defaults::ENDSTOPPULLUP_UMAX);
    mUi->uEndstoppullupVmaxBox->setChecked(defaults::ENDSTOPPULLUP_VMAX);
    mUi->uEndstoppullupWmaxBox->setChecked(defaults::ENDSTOPPULLUP_WMAX);
    mUi->uEndstoppullupZminProbeBox->setChecked(defaults::ENDSTOPPULLUP_ZMIN_PROBE);
    mUi->uEndstoppulldownsBox->setChecked(defaults::ENDSTOPPULLDOWNS);
    mUi->uEndstoppulldownXminBox->setChecked(defaults::ENDSTOPPULLDOWN_XMIN);
    mUi->uEndstoppulldownYminBox->setChecked(defaults::ENDSTOPPULLDOWN_YMIN);
    mUi->uEndstoppulldownZminBox->setChecked(defaults::ENDSTOPPULLDOWN_ZMIN);
    mUi->uEndstoppulldownIminBox->setChecked(defaults::ENDSTOPPULLDOWN_IMIN);
    mUi->uEndstoppulldownJminBox->setChecked(defaults::ENDSTOPPULLDOWN_JMIN);
    mUi->uEndstoppulldownKminBox->setChecked(defaults::ENDSTOPPULLDOWN_KMIN);
    mUi->uEndstoppulldownUminBox->setChecked(defaults::ENDSTOPPULLDOWN_UMIN);
    mUi->uEndstoppulldownVminBox->setChecked(defaults::ENDSTOPPULLDOWN_VMIN);
    mUi->uEndstoppulldownWminBox->setChecked(defaults::ENDSTOPPULLDOWN_WMIN);
    mUi->uEndstoppulldownXmaxBox->setChecked(defaults::ENDSTOPPULLDOWN_XMAX);
    mUi->uEndstoppulldownYmaxBox->setChecked(defaults::ENDSTOPPULLDOWN_YMAX);
    mUi->uEndstoppulldownZmaxBox->setChecked(defaults::ENDSTOPPULLDOWN_ZMAX);
    mUi->uEndstoppulldownImaxBox->setChecked(defaults::ENDSTOPPULLDOWN_IMAX);
    mUi->uEndstoppulldownJmaxBox->setChecked(defaults::ENDSTOPPULLDOWN_JMAX);
    mUi->uEndstoppulldownKmaxBox->setChecked(defaults::ENDSTOPPULLDOWN_KMAX);
    mUi->uEndstoppulldownUmaxBox->setChecked(defaults::ENDSTOPPULLDOWN_UMAX);
    mUi->uEndstoppulldownVmaxBox->setChecked(defaults::ENDSTOPPULLDOWN_VMAX);
    mUi->uEndstoppulldownWmaxBox->setChecked(defaults::ENDSTOPPULLDOWN_WMAX);
    mUi->uEndstoppulldownZminProbeBox->setChecked(defaults::ENDSTOPPULLDOWN_ZMIN_PROBE);
    mUi->uXMinEndstopInvertingDropdown->setCurrentText(defaults::X_MIN_ENDSTOP_INVERTING);
    mUi->uYMinEndstopInvertingDropdown->setCurrentText(defaults::Y_MIN_ENDSTOP_INVERTING);
    mUi->uZMinEndstopInvertingDropdown->setCurrentText(defaults::Z_MIN_ENDSTOP_INVERTING);
    mUi->uIMinEndstopInvertingDropdown->setCurrentText(defaults::I_MIN_ENDSTOP_INVERTING);
    mUi->uJMinEndstopInvertingDropdown->setCurrentText(defaults::J_MIN_ENDSTOP_INVERTING);
    mUi->uKMinEndstopInvertingDropdown->setCurrentText(defaults::K_MIN_ENDSTOP_INVERTING);
    mUi->uUMinEndstopInvertingDropdown->setCurrentText(defaults::U_MIN_ENDSTOP_INVERTING);
    mUi->uVMinEndstopInvertingDropdown->setCurrentText(defaults::V_MIN_ENDSTOP_INVERTING);
    mUi->uWMinEndstopInvertingDropdown->setCurrentText(defaults::W_MIN_ENDSTOP_INVERTING);
    mUi->uXMaxEndstopInvertingDropdown->setCurrentText(defaults::X_MAX_ENDSTOP_INVERTING);
    mUi->uYMaxEndstopInvertingDropdown->setCurrentText(defaults::Y_MAX_ENDSTOP_INVERTING);
    mUi->uZMaxEndstopInvertingDropdown->setCurrentText(defaults::Z_MAX_ENDSTOP_INVERTING);
    mUi->uIMaxEndstopInvertingDropdown->setCurrentText(defaults::I_MAX_ENDSTOP_INVERTING);
    mUi->uJMaxEndstopInvertingDropdown->setCurrentText(defaults::J_MAX_ENDSTOP_INVERTING);
    mUi->uKMaxEndstopInvertingDropdown->setCurrentText(defaults::K_MAX_ENDSTOP_INVERTING);
    mUi->uUMaxEndstopInvertingDropdown->setCurrentText(defaults::U_MAX_ENDSTOP_INVERTING);
    mUi->uVMaxEndstopInvertingDropdown->setCurrentText(defaults::V_MAX_ENDSTOP_INVERTING);
    mUi->uWMaxEndstopInvertingDropdown->setCurrentText(defaults::W_MAX_ENDSTOP_INVERTING);
    mUi->uZMinProbeEndstopInvertingDropdown->setCurrentText(defaults::Z_MIN_PROBE_ENDSTOP_INVERTING);
    mUi->uEndstopInterruptsFeatureBox->setChecked(defaults::ENDSTOP_INTERRUPTS_FEATURE);
    mUi->uEndstopNoiseThresholdDropdown->setCurrentText(defaults::ENDSTOP_NOISE_THRESHOLD);
    mUi->uEndstopNoiseThresholdBox->setChecked(defaults::ENABLE_ENDSTOP_NOISE_THRESHOLD);
    mUi->uDetectBrokenEndstopBox->setChecked(defaults::DETECT_BROKEN_ENDSTOP);

    mUi->uAvailableEndstopsTabWidget->setCurrentIndex(0);
    mUi->uEndstopsPullupsTabWidget->setCurrentIndex(0);
    mUi->uEndstopsPulldownsTabWidget->setCurrentIndex(0);
    mUi->uEndstopsInvertingTabWidget->setCurrentIndex(0);

    mUi->uEndstopsPullupsTabWidget->setEnabled(false);

    mIsLoading = false;
}

bool EndstopsPage::LoadFromJson(const QJsonObject &pJson)
{
    bool success = true;
    mIsLoading = true;

    success &= LoadConfig(mUi->uUseXminPlugBox, pJson, "USE_XMIN_PLUG");
    success &= LoadConfig(mUi->uUseYminPlugBox, pJson, "USE_YMIN_PLUG");
    success &= LoadConfig(mUi->uUseZminPlugBox, pJson, "USE_ZMIN_PLUG");
    success &= LoadConfig(mUi->uUseIminPlugBox, pJson, "USE_IMIN_PLUG");
    success &= LoadConfig(mUi->uUseJminPlugBox, pJson, "USE_JMIN_PLUG");
    success &= LoadConfig(mUi->uUseKminPlugBox, pJson, "USE_KMIN_PLUG");
    success &= LoadConfig(mUi->uUseUminPlugBox, pJson, "USE_UMIN_PLUG");
    success &= LoadConfig(mUi->uUseVminPlugBox, pJson, "USE_VMIN_PLUG");
    success &= LoadConfig(mUi->uUseWminPlugBox, pJson, "USE_WMIN_PLUG");
    success &= LoadConfig(mUi->uUseXmaxPlugBox, pJson, "USE_XMAX_PLUG");
    success &= LoadConfig(mUi->uUseYmaxPlugBox, pJson, "USE_YMAX_PLUG");
    success &= LoadConfig(mUi->uUseZmaxPlugBox, pJson, "USE_ZMAX_PLUG");
    success &= LoadConfig(mUi->uUseImaxPlugBox, pJson, "USE_IMAX_PLUG");
    success &= LoadConfig(mUi->uUseJmaxPlugBox, pJson, "USE_JMAX_PLUG");
    success &= LoadConfig(mUi->uUseKmaxPlugBox, pJson, "USE_KMAX_PLUG");
    success &= LoadConfig(mUi->uUseUmaxPlugBox, pJson, "USE_UMAX_PLUG");
    success &= LoadConfig(mUi->uUseVmaxPlugBox, pJson, "USE_VMAX_PLUG");
    success &= LoadConfig(mUi->uUseWmaxPlugBox, pJson, "USE_WMAX_PLUG");
    success &= LoadConfig(mUi->uEndstoppullupsBox, pJson, "ENDSTOPPULLUPS");
    success &= LoadConfig(mUi->uEndstoppullupXminBox, pJson, "ENDSTOPPULLUP_XMIN");
    success &= LoadConfig(mUi->uEndstoppullupYminBox, pJson, "ENDSTOPPULLUP_YMIN");
    success &= LoadConfig(mUi->uEndstoppullupZminBox, pJson, "ENDSTOPPULLUP_ZMIN");
    success &= LoadConfig(mUi->uEndstoppullupIminBox, pJson, "ENDSTOPPULLUP_IMIN");
    success &= LoadConfig(mUi->uEndstoppullupJminBox, pJson, "ENDSTOPPULLUP_JMIN");
    success &= LoadConfig(mUi->uEndstoppullupKminBox, pJson, "ENDSTOPPULLUP_KMIN");
    success &= LoadConfig(mUi->uEndstoppullupUminBox, pJson, "ENDSTOPPULLUP_UMIN");
    success &= LoadConfig(mUi->uEndstoppullupVminBox, pJson, "ENDSTOPPULLUP_VMIN");
    success &= LoadConfig(mUi->uEndstoppullupWminBox, pJson, "ENDSTOPPULLUP_WMIN");
    success &= LoadConfig(mUi->uEndstoppullupXmaxBox, pJson, "ENDSTOPPULLUP_XMAX");
    success &= LoadConfig(mUi->uEndstoppullupYmaxBox, pJson, "ENDSTOPPULLUP_YMAX");
    success &= LoadConfig(mUi->uEndstoppullupZmaxBox, pJson, "ENDSTOPPULLUP_ZMAX");
    success &= LoadConfig(mUi->uEndstoppullupImaxBox, pJson, "ENDSTOPPULLUP_IMAX");
    success &= LoadConfig(mUi->uEndstoppullupJmaxBox, pJson, "ENDSTOPPULLUP_JMAX");
    success &= LoadConfig(mUi->uEndstoppullupKmaxBox, pJson, "ENDSTOPPULLUP_KMAX");
    success &= LoadConfig(mUi->uEndstoppullupUmaxBox, pJson, "ENDSTOPPULLUP_UMAX");
    success &= LoadConfig(mUi->uEndstoppullupVmaxBox, pJson, "ENDSTOPPULLUP_VMAX");
    success &= LoadConfig(mUi->uEndstoppullupWmaxBox, pJson, "ENDSTOPPULLUP_WMAX");
    success &= LoadConfig(mUi->uEndstoppullupZminProbeBox, pJson, "ENDSTOPPULLUP_ZMIN_PROBE");
    success &= LoadConfig(mUi->uEndstoppulldownsBox, pJson, "ENDSTOPPULLDOWNS");
    success &= LoadConfig(mUi->uEndstoppulldownXminBox, pJson, "ENDSTOPPULLDOWN_XMIN");
    success &= LoadConfig(mUi->uEndstoppulldownYminBox, pJson, "ENDSTOPPULLDOWN_YMIN");
    success &= LoadConfig(mUi->uEndstoppulldownZminBox, pJson, "ENDSTOPPULLDOWN_ZMIN");
    success &= LoadConfig(mUi->uEndstoppulldownIminBox, pJson, "ENDSTOPPULLDOWN_IMIN");
    success &= LoadConfig(mUi->uEndstoppulldownJminBox, pJson, "ENDSTOPPULLDOWN_JMIN");
    success &= LoadConfig(mUi->uEndstoppulldownKminBox, pJson, "ENDSTOPPULLDOWN_KMIN");
    success &= LoadConfig(mUi->uEndstoppulldownUminBox, pJson, "ENDSTOPPULLDOWN_UMIN");
    success &= LoadConfig(mUi->uEndstoppulldownVminBox, pJson, "ENDSTOPPULLDOWN_VMIN");
    success &= LoadConfig(mUi->uEndstoppulldownWminBox, pJson, "ENDSTOPPULLDOWN_WMIN");
    success &= LoadConfig(mUi->uEndstoppulldownXmaxBox, pJson, "ENDSTOPPULLDOWN_XMAX");
    success &= LoadConfig(mUi->uEndstoppulldownYmaxBox, pJson, "ENDSTOPPULLDOWN_YMAX");
    success &= LoadConfig(mUi->uEndstoppulldownZmaxBox, pJson, "ENDSTOPPULLDOWN_ZMAX");
    success &= LoadConfig(mUi->uEndstoppulldownImaxBox, pJson, "ENDSTOPPULLDOWN_IMAX");
    success &= LoadConfig(mUi->uEndstoppulldownJmaxBox, pJson, "ENDSTOPPULLDOWN_JMAX");
    success &= LoadConfig(mUi->uEndstoppulldownKmaxBox, pJson, "ENDSTOPPULLDOWN_KMAX");
    success &= LoadConfig(mUi->uEndstoppulldownUmaxBox, pJson, "ENDSTOPPULLDOWN_UMAX");
    success &= LoadConfig(mUi->uEndstoppulldownVmaxBox, pJson, "ENDSTOPPULLDOWN_VMAX");
    success &= LoadConfig(mUi->uEndstoppulldownWmaxBox, pJson, "ENDSTOPPULLDOWN_WMAX");
    success &= LoadConfig(mUi->uEndstoppulldownZminProbeBox, pJson, "ENDSTOPPULLDOWN_ZMIN_PROBE");
    success &= LoadConfig(mUi->uXMinEndstopInvertingDropdown, pJson, "X_MIN_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uYMinEndstopInvertingDropdown, pJson, "Y_MIN_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uZMinEndstopInvertingDropdown, pJson, "Z_MIN_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uIMinEndstopInvertingDropdown, pJson, "I_MIN_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uJMinEndstopInvertingDropdown, pJson, "J_MIN_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uKMinEndstopInvertingDropdown, pJson, "K_MIN_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uUMinEndstopInvertingDropdown, pJson, "U_MIN_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uVMinEndstopInvertingDropdown, pJson, "V_MIN_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uWMinEndstopInvertingDropdown, pJson, "W_MIN_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uXMaxEndstopInvertingDropdown, pJson, "X_MAX_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uYMaxEndstopInvertingDropdown, pJson, "Y_MAX_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uZMaxEndstopInvertingDropdown, pJson, "Z_MAX_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uIMaxEndstopInvertingDropdown, pJson, "I_MAX_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uJMaxEndstopInvertingDropdown, pJson, "J_MAX_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uKMaxEndstopInvertingDropdown, pJson, "K_MAX_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uUMaxEndstopInvertingDropdown, pJson, "U_MAX_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uVMaxEndstopInvertingDropdown, pJson, "V_MAX_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uWMaxEndstopInvertingDropdown, pJson, "W_MAX_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uZMinProbeEndstopInvertingDropdown, pJson, "Z_MIN_PROBE_ENDSTOP_INVERTING");
    success &= LoadConfig(mUi->uEndstopInterruptsFeatureBox, pJson, "ENDSTOP_INTERRUPTS_FEATURE");
    success &= LoadConfig(mUi->uEndstopNoiseThresholdDropdown, pJson, "ENDSTOP_NOISE_THRESHOLD");
    success &= LoadConfig(mUi->uEndstopNoiseThresholdBox, pJson, "ENABLE_ENDSTOP_NOISE_THRESHOLD");
    success &= LoadConfig(mUi->uDetectBrokenEndstopBox, pJson, "DETECT_BROKEN_ENDSTOP");

    mIsLoading = false;
    return success;
}

void EndstopsPage::FetchConfiguration(Configuration& pConfig)
{
    SetConfig(pConfig.endstops.USE_XMIN_PLUG, mUi->uUseXminPlugBox);
    SetConfig(pConfig.endstops.USE_YMIN_PLUG, mUi->uUseYminPlugBox);
    SetConfig(pConfig.endstops.USE_ZMIN_PLUG, mUi->uUseZminPlugBox);
    SetConfig(pConfig.endstops.USE_IMIN_PLUG, mUi->uUseIminPlugBox);
    SetConfig(pConfig.endstops.USE_JMIN_PLUG, mUi->uUseJminPlugBox);
    SetConfig(pConfig.endstops.USE_KMIN_PLUG, mUi->uUseKminPlugBox);
    SetConfig(pConfig.endstops.USE_UMIN_PLUG, mUi->uUseUminPlugBox);
    SetConfig(pConfig.endstops.USE_VMIN_PLUG, mUi->uUseVminPlugBox);
    SetConfig(pConfig.endstops.USE_WMIN_PLUG, mUi->uUseWminPlugBox);
    SetConfig(pConfig.endstops.USE_XMAX_PLUG, mUi->uUseXmaxPlugBox);
    SetConfig(pConfig.endstops.USE_YMAX_PLUG, mUi->uUseYmaxPlugBox);
    SetConfig(pConfig.endstops.USE_ZMAX_PLUG, mUi->uUseZmaxPlugBox);
    SetConfig(pConfig.endstops.USE_IMAX_PLUG, mUi->uUseImaxPlugBox);
    SetConfig(pConfig.endstops.USE_JMAX_PLUG, mUi->uUseJmaxPlugBox);
    SetConfig(pConfig.endstops.USE_KMAX_PLUG, mUi->uUseKmaxPlugBox);
    SetConfig(pConfig.endstops.USE_UMAX_PLUG, mUi->uUseUmaxPlugBox);
    SetConfig(pConfig.endstops.USE_VMAX_PLUG, mUi->uUseVmaxPlugBox);
    SetConfig(pConfig.endstops.USE_WMAX_PLUG, mUi->uUseWmaxPlugBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUPS, mUi->uEndstoppullupsBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_XMIN, mUi->uEndstoppullupXminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_YMIN, mUi->uEndstoppullupYminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_ZMIN, mUi->uEndstoppullupZminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_IMIN, mUi->uEndstoppullupIminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_JMIN, mUi->uEndstoppullupJminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_KMIN, mUi->uEndstoppullupKminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_UMIN, mUi->uEndstoppullupUminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_VMIN, mUi->uEndstoppullupVminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_WMIN, mUi->uEndstoppullupWminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_XMAX, mUi->uEndstoppullupXmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_YMAX, mUi->uEndstoppullupYmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_ZMAX, mUi->uEndstoppullupZmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_IMAX, mUi->uEndstoppullupImaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_JMAX, mUi->uEndstoppullupJmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_KMAX, mUi->uEndstoppullupKmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_UMAX, mUi->uEndstoppullupUmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_VMAX, mUi->uEndstoppullupVmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_WMAX, mUi->uEndstoppullupWmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLUP_ZMIN_PROBE, mUi->uEndstoppullupZminProbeBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWNS, mUi->uEndstoppulldownsBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_XMIN, mUi->uEndstoppulldownXminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_YMIN, mUi->uEndstoppulldownYminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_ZMIN, mUi->uEndstoppulldownZminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_IMIN, mUi->uEndstoppulldownIminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_JMIN, mUi->uEndstoppulldownJminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_KMIN, mUi->uEndstoppulldownKminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_UMIN, mUi->uEndstoppulldownUminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_VMIN, mUi->uEndstoppulldownVminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_WMIN, mUi->uEndstoppulldownWminBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_XMAX, mUi->uEndstoppulldownXmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_YMAX, mUi->uEndstoppulldownYmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_ZMAX, mUi->uEndstoppulldownZmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_IMAX, mUi->uEndstoppulldownImaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_JMAX, mUi->uEndstoppulldownJmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_KMAX, mUi->uEndstoppulldownKmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_UMAX, mUi->uEndstoppulldownUmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_VMAX, mUi->uEndstoppulldownVmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_WMAX, mUi->uEndstoppulldownWmaxBox);
    SetConfig(pConfig.endstops.ENDSTOPPULLDOWN_ZMIN_PROBE, mUi->uEndstoppulldownZminProbeBox);
    SetConfig(pConfig.endstops.X_MIN_ENDSTOP_INVERTING, mUi->uXMinEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.Y_MIN_ENDSTOP_INVERTING, mUi->uYMinEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.Z_MIN_ENDSTOP_INVERTING, mUi->uZMinEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.I_MIN_ENDSTOP_INVERTING, mUi->uIMinEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.J_MIN_ENDSTOP_INVERTING, mUi->uJMinEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.K_MIN_ENDSTOP_INVERTING, mUi->uKMinEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.U_MIN_ENDSTOP_INVERTING, mUi->uUMinEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.V_MIN_ENDSTOP_INVERTING, mUi->uVMinEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.W_MIN_ENDSTOP_INVERTING, mUi->uWMinEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.X_MAX_ENDSTOP_INVERTING, mUi->uXMaxEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.Y_MAX_ENDSTOP_INVERTING, mUi->uYMaxEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.Z_MAX_ENDSTOP_INVERTING, mUi->uZMaxEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.I_MAX_ENDSTOP_INVERTING, mUi->uIMaxEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.J_MAX_ENDSTOP_INVERTING, mUi->uJMaxEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.K_MAX_ENDSTOP_INVERTING, mUi->uKMaxEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.U_MAX_ENDSTOP_INVERTING, mUi->uUMaxEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.V_MAX_ENDSTOP_INVERTING, mUi->uVMaxEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.W_MAX_ENDSTOP_INVERTING, mUi->uWMaxEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.Z_MIN_PROBE_ENDSTOP_INVERTING, mUi->uZMinProbeEndstopInvertingDropdown);
    SetConfig(pConfig.endstops.ENDSTOP_INTERRUPTS_FEATURE, mUi->uEndstopInterruptsFeatureBox);
    SetConfig(pConfig.endstops.ENDSTOP_NOISE_THRESHOLD, mUi->uEndstopNoiseThresholdDropdown);
    SetConfig(pConfig.endstops.ENABLE_ENDSTOP_NOISE_THRESHOLD, mUi->uEndstopNoiseThresholdBox);
    SetConfig(pConfig.endstops.DETECT_BROKEN_ENDSTOP, mUi->uDetectBrokenEndstopBox);
}

void EndstopsPage::ReplaceTags(QStringList& pOutput)
{
    ReplaceTag(pOutput, "#{USE_XMIN_PLUG}", mUi->uUseXminPlugBox, "USE_XMIN_PLUG");
    ReplaceTag(pOutput, "#{USE_YMIN_PLUG}", mUi->uUseYminPlugBox, "USE_YMIN_PLUG");
    ReplaceTag(pOutput, "#{USE_ZMIN_PLUG}", mUi->uUseZminPlugBox, "USE_ZMIN_PLUG");
    ReplaceTag(pOutput, "#{USE_IMIN_PLUG}", mUi->uUseIminPlugBox, "USE_IMIN_PLUG");
    ReplaceTag(pOutput, "#{USE_JMIN_PLUG}", mUi->uUseJminPlugBox, "USE_JMIN_PLUG");
    ReplaceTag(pOutput, "#{USE_KMIN_PLUG}", mUi->uUseKminPlugBox, "USE_KMIN_PLUG");
    ReplaceTag(pOutput, "#{USE_UMIN_PLUG}", mUi->uUseUminPlugBox, "USE_UMIN_PLUG");
    ReplaceTag(pOutput, "#{USE_VMIN_PLUG}", mUi->uUseVminPlugBox, "USE_VMIN_PLUG");
    ReplaceTag(pOutput, "#{USE_WMIN_PLUG}", mUi->uUseWminPlugBox, "USE_WMIN_PLUG");
    ReplaceTag(pOutput, "#{USE_XMAX_PLUG}", mUi->uUseXmaxPlugBox, "USE_XMAX_PLUG");
    ReplaceTag(pOutput, "#{USE_YMAX_PLUG}", mUi->uUseYmaxPlugBox, "USE_YMAX_PLUG");
    ReplaceTag(pOutput, "#{USE_ZMAX_PLUG}", mUi->uUseZmaxPlugBox, "USE_ZMAX_PLUG");
    ReplaceTag(pOutput, "#{USE_IMAX_PLUG}", mUi->uUseImaxPlugBox, "USE_IMAX_PLUG");
    ReplaceTag(pOutput, "#{USE_JMAX_PLUG}", mUi->uUseJmaxPlugBox, "USE_JMAX_PLUG");
    ReplaceTag(pOutput, "#{USE_KMAX_PLUG}", mUi->uUseKmaxPlugBox, "USE_KMAX_PLUG");
    ReplaceTag(pOutput, "#{USE_UMAX_PLUG}", mUi->uUseUmaxPlugBox, "USE_UMAX_PLUG");
    ReplaceTag(pOutput, "#{USE_VMAX_PLUG}", mUi->uUseVmaxPlugBox, "USE_VMAX_PLUG");
    ReplaceTag(pOutput, "#{USE_WMAX_PLUG}", mUi->uUseWmaxPlugBox, "USE_WMAX_PLUG");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUPS}", mUi->uEndstoppullupsBox, "ENDSTOPPULLUPS");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_XMIN}", mUi->uEndstoppullupXminBox, "ENDSTOPPULLUP_XMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_YMIN}", mUi->uEndstoppullupYminBox, "ENDSTOPPULLUP_YMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_ZMIN}", mUi->uEndstoppullupZminBox, "ENDSTOPPULLUP_ZMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_IMIN}", mUi->uEndstoppullupIminBox, "ENDSTOPPULLUP_IMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_JMIN}", mUi->uEndstoppullupJminBox, "ENDSTOPPULLUP_JMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_KMIN}", mUi->uEndstoppullupKminBox, "ENDSTOPPULLUP_KMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_UMIN}", mUi->uEndstoppullupUminBox, "ENDSTOPPULLUP_UMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_VMIN}", mUi->uEndstoppullupVminBox, "ENDSTOPPULLUP_VMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_WMIN}", mUi->uEndstoppullupWminBox, "ENDSTOPPULLUP_WMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_XMAX}", mUi->uEndstoppullupXmaxBox, "ENDSTOPPULLUP_XMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_YMAX}", mUi->uEndstoppullupYmaxBox, "ENDSTOPPULLUP_YMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_ZMAX}", mUi->uEndstoppullupZmaxBox, "ENDSTOPPULLUP_ZMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_IMAX}", mUi->uEndstoppullupImaxBox, "ENDSTOPPULLUP_IMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_JMAX}", mUi->uEndstoppullupJmaxBox, "ENDSTOPPULLUP_JMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_KMAX}", mUi->uEndstoppullupKmaxBox, "ENDSTOPPULLUP_KMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_UMAX}", mUi->uEndstoppullupUmaxBox, "ENDSTOPPULLUP_UMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_VMAX}", mUi->uEndstoppullupVmaxBox, "ENDSTOPPULLUP_VMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_WMAX}", mUi->uEndstoppullupWmaxBox, "ENDSTOPPULLUP_WMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLUP_ZMIN_PROBE}", mUi->uEndstoppullupZminProbeBox, "ENDSTOPPULLUP_ZMIN_PROBE");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWNS}", mUi->uEndstoppulldownsBox, "ENDSTOPPULLDOWNS");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_XMIN}", mUi->uEndstoppulldownXminBox, "ENDSTOPPULLDOWN_XMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_YMIN}", mUi->uEndstoppulldownYminBox, "ENDSTOPPULLDOWN_YMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_ZMIN}", mUi->uEndstoppulldownZminBox, "ENDSTOPPULLDOWN_ZMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_IMIN}", mUi->uEndstoppulldownIminBox, "ENDSTOPPULLDOWN_IMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_JMIN}", mUi->uEndstoppulldownJminBox, "ENDSTOPPULLDOWN_JMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_KMIN}", mUi->uEndstoppulldownKminBox, "ENDSTOPPULLDOWN_KMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_UMIN}", mUi->uEndstoppulldownUminBox, "ENDSTOPPULLDOWN_UMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_VMIN}", mUi->uEndstoppulldownVminBox, "ENDSTOPPULLDOWN_VMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_WMIN}", mUi->uEndstoppulldownWminBox, "ENDSTOPPULLDOWN_WMIN");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_XMAX}", mUi->uEndstoppulldownXmaxBox, "ENDSTOPPULLDOWN_XMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_YMAX}", mUi->uEndstoppulldownYmaxBox, "ENDSTOPPULLDOWN_YMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_ZMAX}", mUi->uEndstoppulldownZmaxBox, "ENDSTOPPULLDOWN_ZMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_IMAX}", mUi->uEndstoppulldownImaxBox, "ENDSTOPPULLDOWN_IMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_JMAX}", mUi->uEndstoppulldownJmaxBox, "ENDSTOPPULLDOWN_JMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_KMAX}", mUi->uEndstoppulldownKmaxBox, "ENDSTOPPULLDOWN_KMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_UMAX}", mUi->uEndstoppulldownUmaxBox, "ENDSTOPPULLDOWN_UMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_VMAX}", mUi->uEndstoppulldownVmaxBox, "ENDSTOPPULLDOWN_VMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_WMAX}", mUi->uEndstoppulldownWmaxBox, "ENDSTOPPULLDOWN_WMAX");
    ReplaceTag(pOutput, "#{ENDSTOPPULLDOWN_ZMIN_PROBE}", mUi->uEndstoppulldownZminProbeBox, "ENDSTOPPULLDOWN_ZMIN_PROBE");
    ReplaceTag(pOutput, "#{X_MIN_ENDSTOP_INVERTING}", mUi->uXMinEndstopInvertingDropdown, false, "X_MIN_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{Y_MIN_ENDSTOP_INVERTING}", mUi->uYMinEndstopInvertingDropdown, false, "Y_MIN_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{Z_MIN_ENDSTOP_INVERTING}", mUi->uZMinEndstopInvertingDropdown, false, "Z_MIN_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{I_MIN_ENDSTOP_INVERTING}", mUi->uIMinEndstopInvertingDropdown, false, "I_MIN_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{J_MIN_ENDSTOP_INVERTING}", mUi->uJMinEndstopInvertingDropdown, false, "J_MIN_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{K_MIN_ENDSTOP_INVERTING}", mUi->uKMinEndstopInvertingDropdown, false, "K_MIN_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{U_MIN_ENDSTOP_INVERTING}", mUi->uUMinEndstopInvertingDropdown, false, "U_MIN_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{V_MIN_ENDSTOP_INVERTING}", mUi->uVMinEndstopInvertingDropdown, false, "V_MIN_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{W_MIN_ENDSTOP_INVERTING}", mUi->uWMinEndstopInvertingDropdown, false, "W_MIN_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{X_MAX_ENDSTOP_INVERTING}", mUi->uXMaxEndstopInvertingDropdown, false, "X_MAX_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{Y_MAX_ENDSTOP_INVERTING}", mUi->uYMaxEndstopInvertingDropdown, false, "Y_MAX_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{Z_MAX_ENDSTOP_INVERTING}", mUi->uZMaxEndstopInvertingDropdown, false, "Z_MAX_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{I_MAX_ENDSTOP_INVERTING}", mUi->uIMaxEndstopInvertingDropdown, false, "I_MAX_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{J_MAX_ENDSTOP_INVERTING}", mUi->uJMaxEndstopInvertingDropdown, false, "J_MAX_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{K_MAX_ENDSTOP_INVERTING}", mUi->uKMaxEndstopInvertingDropdown, false, "K_MAX_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{U_MAX_ENDSTOP_INVERTING}", mUi->uUMaxEndstopInvertingDropdown, false, "U_MAX_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{V_MAX_ENDSTOP_INVERTING}", mUi->uVMaxEndstopInvertingDropdown, false, "V_MAX_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{W_MAX_ENDSTOP_INVERTING}", mUi->uWMaxEndstopInvertingDropdown, false, "W_MAX_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{Z_MIN_PROBE_ENDSTOP_INVERTING}", mUi->uZMinProbeEndstopInvertingDropdown, false, "Z_MIN_PROBE_ENDSTOP_INVERTING");
    ReplaceTag(pOutput, "#{ENDSTOP_INTERRUPTS_FEATURE}", mUi->uEndstopInterruptsFeatureBox, "ENDSTOP_INTERRUPTS_FEATURE");
    ReplaceTag(pOutput, "#{ENDSTOP_NOISE_THRESHOLD}", mUi->uEndstopNoiseThresholdDropdown, false, "ENDSTOP_NOISE_THRESHOLD");
    ReplaceTag(pOutput, "#{ENABLE_ENDSTOP_NOISE_THRESHOLD}", mUi->uEndstopNoiseThresholdBox, "ENABLE_ENDSTOP_NOISE_THRESHOLD");
    ReplaceTag(pOutput, "#{DETECT_BROKEN_ENDSTOP}", mUi->uDetectBrokenEndstopBox, "DETECT_BROKEN_ENDSTOP");
}

/* antimicrox Gamepad to KB+M event mapper
 * Copyright (C) 2015 Travis Nickles <nickles.travis@gmail.com>
 * Copyright (C) 2020 Jagoda Górska <juliagoda.pl@protonmail>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MOUSEBUTTONSETTINGSDIALOG_H
#define MOUSEBUTTONSETTINGSDIALOG_H

#include "ui_mousesettingsdialog.h"

#include "mousesettingsdialog.h"
#include "uihelpers/mousebuttonsettingsdialoghelper.h"

class JoyButton;
class SpringModeRegionPreview;

class MouseButtonSettingsDialog : public MouseSettingsDialog
{
    Q_OBJECT

  public:
    explicit MouseButtonSettingsDialog(JoyButton *button, QWidget *parent = nullptr);

    JoyButton *getButton() const;
    SpringModeRegionPreview *getSpringPreviewWidget() const;
    MouseButtonSettingsDialogHelper const &getHelper();

  protected:
    void selectCurrentMouseModePreset();
    void calculateSpringPreset();
    void calculateMouseSpeedPreset();
    void updateWindowTitleButtonName();
    void calculateExtraAccelerationCurve();

  public slots:
    void changeMouseMode(int index);
    void changeMouseCurve(int index);
    void updateConfigHorizontalSpeed(int value);
    void updateConfigVerticalSpeed(int value);
    void updateSpringWidth(int value);
    void updateSpringHeight(int value);
    void updateSensitivity(double value);
    void updateAccelerationCurvePresetComboBox();

  private slots:
    void updateExtraAccelerationCurve(int index);

  private:
    MouseButtonSettingsDialogHelper &getHelperLocal();

    JoyButton *button;
    SpringModeRegionPreview *springPreviewWidget;
    MouseButtonSettingsDialogHelper helper;
};

#endif // MOUSEBUTTONSETTINGSDIALOG_H

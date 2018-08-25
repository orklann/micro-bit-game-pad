#include "JoystickService.h"
#include "mbed.h"

uint8_t joystick_report[] = { 0, 0, 0, 0, 0 };


JoystickService::JoystickService(BLE &_ble) :
    HIDServiceBase(_ble,
                   JOYSTICK_REPORT_MAP, sizeof(JOYSTICK_REPORT_MAP),
                   inputReport          = joystick_report,
                   outputReport         = NULL,
                   featureReport        = NULL,
                   inputReportLength    = sizeof(joystick_report),
                   outputReportLength   = 0,
                   featureReportLength  = 0,
                   reportTickerDelay    = 20),
    buttonsState (0),
    failedReports (0)
{
    speed[0] = 0;
    speed[1] = 0;
    speed[2] = 0;
    speed[3] = 0;
    //startReportTicker();
}

int JoystickService::setSpeed(int8_t x, int8_t y, int8_t z)
{
    speed[0] = x;
    speed[1] = y;
    speed[2] = z;

    return 0;
}

int JoystickService::setButton(JoystickButton button, ButtonState state)
{
    if (state == BUTTON_UP)
        buttonsState &= ~(button);
    else
        buttonsState |= button;

    sendCallback();
    return 0;
}

void JoystickService::pressButton(JoystickButton button) {
    if (!connected)
        return ;

    joystick_report[0] = button;   // press button
    joystick_report[1] = speed[0];
    joystick_report[2] = speed[1];
    joystick_report[3] = speed[2];
    joystick_report[4] = speed[3];

    if (send(joystick_report))
        failedReports++;

    // wait for a little time to send button release report
    // This fix: OpenEmu in game button not work
    wait(0.100);

    joystick_report[0] = 0x00;   // release button
    joystick_report[1] = speed[0];
    joystick_report[2] = speed[1];
    joystick_report[3] = speed[2];
    joystick_report[4] = speed[3];

    if (send(joystick_report))
        failedReports++;


}

void JoystickService::sendCallback(void) {
    if (!connected)
        return;

    joystick_report[0] = 0x02;   //buttonsState & 0x7;
    joystick_report[1] = speed[0];
    joystick_report[2] = speed[1];
    joystick_report[3] = speed[2];
    joystick_report[4] = speed[3];

    if (send(joystick_report))
        failedReports++;

    joystick_report[0] = 0x00;   //buttonsState & 0x7;
    joystick_report[1] = speed[0];
    joystick_report[2] = speed[1];
    joystick_report[3] = speed[2];
    joystick_report[4] = speed[3];

    if (send(joystick_report))
        failedReports++;
}

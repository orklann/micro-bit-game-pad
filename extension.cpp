#include "pxt.h"
#include "MicroBitConfig.h"
#include "ble/BLE.h"
#include "MicroBitThermometer.h"
#include "EventModel.h"
#include "JoystickService.h"

namespace bluetooth {
     JoystickService *_pService = NULL;
     /**
     * A function to start bluetooth Joystick service
     */
     //% blockId=bluetooth_startJoystickService block="bluetooth startJoystickService"
     void startJoystickService() {
        if (NULL != _pService) return ;

        _pService = new JoystickService(*uBit.ble);
     }

     /**
     * A function to press joystick button
     */
     //% blockId=bluetooth_pressJoystickButton block="bluetooth press joystick button %button"
     void pressJoystickButton(JoystickButton button) {
        if (NULL == _pService) return ;

        _pService->pressButton(button);
     }
}


namespace basic {
    /**
    * A function to show my name
    */
    //% blockId=bluetooth_showMyName block="basic show my name %name"
    void setMyName(StringData *name) {
        ManagedString s(name);
        uBit.display.scroll(s, 1);
    }
}

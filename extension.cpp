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
     * A function to set joystick button State
     */
     //% blockId=bluetooth_setJoystickButton block="bluetooth set joystick button %button %state"
     void setJoystickButton(JoystickButton button, ButtonState state) {
        if (NULL == _pService) return ;

        _pService->setButton(button, state);
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

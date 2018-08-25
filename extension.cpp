#include "pxt.h"
#include "MicroBitConfig.h"
#include "ble/BLE.h"
#include "MicroBitThermometer.h"
#include "EventModel.h"
#include "JoystickService.h"

namespace bluetooth {
     static JoystickService *_pService = nullptr;

     static JoystickService *getJoystick(){
        if (_pService == nullptr) {
            _pService = new JoystickService(*uBit.ble);
        }
        return _pService;
     }

     /**
     * A function to start bluetooth Joystick service
     */
     //% blockId=bluetooth_startJoystickService block="bluetooth startJoystickService"
     void startJoystickService() {
        getJoystick();
     }

     /**
     * A function to press joystick button
     */
     //% blockId=bluetooth_pressJoystickButton block="bluetooth press joystick button %button"
     void pressJoystickButton(JoystickButton button) {
        JoystickService *joystick = getJoystick();

        joystick->pressButton(button);
     }
}

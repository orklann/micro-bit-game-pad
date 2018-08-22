#include "pxt.h"
#include "MicroBitConfig.h"
#include "ble/BLE.h"
#include "MicroBitThermometer.h"
#include "EventModel.h"

namespace bluetooth {
     /**
     * A function to changer Microbit bluetooth device name
     */
     //% blockId=bluetooth_setBLEDeviceName block="bluetooth set device name %name"
     void setBLEDeviceName(StringData *name) {
         ManagedString s(name);
         (*uBit.ble).gap().setDeviceName((const uint8_t *)s.toCharArray());
         //uBit.display.scroll(s, 1);
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

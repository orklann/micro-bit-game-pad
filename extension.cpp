#include "pxt.h"

namespace bluetooth {
    /**
     * A function to changer Microbit bluetooth device name
     */

     //% blockId=bluetooth_setBLEDeviceName block="bluetooth set device name %name"
     void setBLEDeviceName(StringData *name) {
         ManagedString s(name);
         //(*uBit.ble).gap().setDeviceName((const uint8_t *)s.toCharArray());
         uBit.display.scroll(s, 1);
     }
}

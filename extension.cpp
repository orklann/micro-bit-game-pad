#include "pxt.h"
#include "MicroBitConfig.h"
#include "ble/BLE.h"

using namespace pxt;

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


namespace basic {
    /**
     * A function to show "Microbit
     */

    //% blockId=basic_showMyName block="basic show my name %name"
    void showMyName(StringData *name) {
        ManagedString s(name);
        uBit.display.scroll(s, 1);
    }
}

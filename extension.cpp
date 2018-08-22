#include "pxt.h"
#include "MicroBitConfig.h"
#include "ble/BLE.h"
#include <string.h>

using namespace pxt;

namespace bluetooth {
    /**
     * A function to changer Microbit bluetooth device name
     */

    //% blockId=bluetooth_setDeviceName block="bluetooth set device name %name"
    void setDeviceName(StringData *name) {
        ManagedString s(name);
        (*uBit.ble).gap().setDeviceName((const uint8_t *)s.toCharArray());
    }
}

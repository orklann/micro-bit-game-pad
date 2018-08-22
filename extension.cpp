#include "pxt.h"
using namespace pxt;

/**
 * A function to changer Microbit bluetooth device name
 */

namespace bluetooth {
    //% blockId=bluetooth_setDeviceName block="bluetooth set device name %name"
    void setDeviceName(char *name) {
        (*uBit.ble).gap().setDeviceName((const uint8_t *)name);
    }
}

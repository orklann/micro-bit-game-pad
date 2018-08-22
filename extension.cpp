#include "pxt.h"
using namespace pxt;

namespace bluetooth {
    //% blockId=bluetooth_setDeviceName block="bluetooth set device name %name"
    void setBluetoothDeviceName(char *name) {
        uBit.ble.gap().setDeviceName((const uint8_t *)name);
    }
}

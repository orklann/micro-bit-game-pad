#include "pxt.h"

using namespace pxt;

namespace basic {
    /**
     * A function to show "Microbit"
     */

    //% blockId=basic_showMyName block="basic show my name %name"
    void showMyName(StringData *name) {
        ManagedString s(name);
        uBit.display.scroll(s, 1);
    }
}

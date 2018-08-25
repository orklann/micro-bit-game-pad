// tests go here; this will not be compiled when this package is used as a library
input.onButtonPressed(Button.A, () => {
    bluetooth.pressJoystickButton(JoystickButton.JOYSTICK_BUTTON_1);
    basic.showString("A");
})

// Two input work only with this pxt.json config
// "yotta": {
//     "config": {
//         "microbit-dal": {
//             "bluetooth": {
//                 "dfu_service": 0,
//                 "event_service": 0,
//                 "device_info_service": 0,
//                 "security_level": "SECURITY_MODE_ENCRYPTION_NO_MITM"
//             },
//             "gatt_table_size": "0x700"
//         }
//     }
// }
input.onButtonPressed(Button.B, () => {
    bluetooth.pressJoystickButton(JoystickButton.JOYSTICK_BUTTON_2);
    basic.showString("B");
})


basic.showString("OK")
bluetooth.startJoystickService()

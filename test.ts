// tests go here; this will not be compiled when this package is used as a library
input.onButtonPressed(Button.A, () => {
    bluetooth.pressJoystickButton(JoystickButton.JOYSTICK_BUTTON_2);
    basic.showString("A");
})

// input.onButtonPressed(Button.B, () => {
//     //bluetooth.pressJoystickButton(JoystickButton.JOYSTICK_BUTTON_2);
//     basic.showString("B");
// })

basic.showString("OK")
bluetooth.startJoystickService()

// tests go here; this will not be compiled when this package is used as a library
// tests go here; this will not be compiled when this package is used as a library
input.onButtonPressed(Button.A, () => {
    bluetooth.setJoystickButton(JoystickButton.JOYSTICK_BUTTON_1);
})
basic.showString("OK")
bluetooth.startJoystickService()

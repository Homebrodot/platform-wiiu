#include "input_wiiu.h"

#include <vpad/input.h>

const button_translate gamepad_buttons[] = {
    {VPAD_BUTTON_HOME, JoyButton::GUIDE},
    {VPAD_BUTTON_A, JoyButton::A},
    {VPAD_BUTTON_B, JoyButton::B},
    {VPAD_BUTTON_Y, JoyButton::Y},
    {VPAD_BUTTON_X, JoyButton::X},
    {VPAD_BUTTON_PLUS, JoyButton::START}, //I think?
    {VPAD_BUTTON_MINUS, JoyButton::BACK}, //I think?
    {VPAD_BUTTON_STICK_L, JoyButton::LEFT_STICK},
    {VPAD_BUTTON_STICK_R, JoyButton::RIGHT_STICK},
    {VPAD_BUTTON_L, JoyButton::LEFT_SHOULDER},
    {VPAD_BUTTON_R, JoyButton::RIGHT_SHOULDER},
};

const hat_translate gamepad_dpad[4] = {
    {VPAD_BUTTON_UP, HatMask::UP},
    {VPAD_BUTTON_DOWN, HatMask::DOWN},
    {VPAD_BUTTON_LEFT, HatMask::LEFT},
    {VPAD_BUTTON_RIGHT, HatMask::RIGHT},
};

void WiiUController::update_vpad(){
    VPADStatus status;
    
    VPADReadError err;
    VPADRead((VPADChan) cont_chan, &status, 1, &err);

    uint8_t it = 0;
    //Buttons
    for (button_translate current; it <= 13; it++){
        current = gamepad_buttons[it];
        if (current.wiiu_button & status.trigger){
            p_input_sing->joy_button(gd_controller_id, current.godot_button, true);
        }
    }

    //Dpad (hat)
    it = 0;
    BitField<HatMask> bitf;
    for(hat_translate current; it < 5; it++){
        current = gamepad_dpad[it];
        if (current.wiiu_button & status.trigger){
            bitf.set_flag(current.godot_button);
        }
    }
    p_input_sing->joy_hat(gd_controller_id, bitf);

    //Axes
    axis_translate gamepad_axes = {
        status.leftStick.x,
        status.leftStick.y,
        status.rightStick.x,
        status.rightStick.y,
        status.trigger & VPAD_BUTTON_ZL,
        status.trigger & VPAD_BUTTON_ZR
    };
    axis_process(gamepad_axes);

    //Todo: Send touch info to the DisplayServer

    Dictionary controller_info;
    controller_info["controller"] = "Wii U Gamepad";
    controller_info["headphones_connected"] = status.usingHeadphones ? "yes" : "no";
    //Todo: Add battery info, volume slider info
    p_input_sing->joy_connection_changed(gd_controller_id, true, "Wii U Gamepad", "", controller_info);
}




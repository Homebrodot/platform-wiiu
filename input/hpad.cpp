#include "input_wiiu.h"

#include <nn/hpad/hpad.h>

const button_translate gamecube_buttons[] = {
    {HPAD_BUTTON_A, JoyButton::A},
    {HPAD_BUTTON_B, JoyButton::B},
    {HPAD_BUTTON_Y, JoyButton::Y},
    {HPAD_BUTTON_X, JoyButton::X},
    {HPAD_BUTTON_START, JoyButton::START}, 
    {HPAD_TRIGGER_Z, JoyButton::BACK},
    //Not sure about having these two here
    {HPAD_TRIGGER_L, JoyButton::LEFT_SHOULDER},
    {HPAD_TRIGGER_R, JoyButton::RIGHT_SHOULDER},
};

const hat_translate gamecube_dpad[] = {
    {HPAD_BUTTON_UP, HatMask::UP},
    {HPAD_BUTTON_DOWN, HatMask::DOWN},
    {HPAD_BUTTON_LEFT, HatMask::LEFT},
    {HPAD_BUTTON_RIGHT,  HatMask::RIGHT},
};

void WiiUController::update_hpad(){
    HPADStatus status[16];
    HPADRead( (HPADChan) cont_chan, status, 16);
    uint8_t it = 0;
    //Buttons
    for (button_translate current; it <= 13; it++){
        current = gamecube_buttons[it];
        if (current.wiiu_button & status[0].trigger){
            p_input_sing->joy_button(gd_controller_id, current.godot_button, true);
        }
    }

    //Dpad (hat)
    it = 0;
    BitField<HatMask> bitf;
    for(hat_translate current; it < 5; it++){
        current = gamecube_dpad[it];
        if (current.wiiu_button & status[0].trigger){
            bitf.set_flag(current.godot_button);
        }
    }
    p_input_sing->joy_hat(gd_controller_id, bitf);

    //Axes
    axis_translate gc_axes = {
        (status->stickX / (float) HPAD_STICK_AXIS_MAX),
        (status->stickY / (float) HPAD_STICK_AXIS_MAX),
        (status->substickX / (float) HPAD_SUBSTICK_AXIS_MAX),
        (status->substickY /(float) HPAD_SUBSTICK_AXIS_MAX),
        (status->triggerL /(float) HPAD_TRIGGER_MAX),
        (status->triggerR /(float) HPAD_TRIGGER_MAX)
    };
    axis_process(gc_axes);

    //Update info
    Dictionary controller_info;
    controller_info["controller"] = "GameCube";
}

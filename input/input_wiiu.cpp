#include "input_wiiu.h"

#include <padscore/kpad.h>


void WiiUController::axis_process(axis_translate translate){
    //Left stick
    p_input_sing->joy_axis(gd_controller_id, JoyAxis::LEFT_X, translate.left_x);
    p_input_sing->joy_axis(gd_controller_id, JoyAxis::LEFT_Y, translate.left_y);
    //Right Stick
    p_input_sing->joy_axis(gd_controller_id, JoyAxis::RIGHT_X, translate.right_x);
    p_input_sing->joy_axis(gd_controller_id, JoyAxis::LEFT_Y, translate.right_y);
    //Triggers
    p_input_sing->joy_axis(gd_controller_id, JoyAxis::TRIGGER_LEFT, translate.trigger_l);
    p_input_sing->joy_axis(gd_controller_id, JoyAxis::TRIGGER_RIGHT, translate.trigger_r);
}

InputWiiU::InputWiiU(){
    WiiUController::p_input_sing = Input::get_singleton();
}


//This is only for one-time initalization things.
WiiUController::WiiUController(WiiUAPITypes type){
    api_type = type;
    switch (api_type){
        case API_KPAD:
            cont_chan = kpad_increment;
            kpad_increment += 1;
            init_kpad();
            break;
        case API_VPAD:
            cont_chan = vpad_increment;
            vpad_increment += 1;
            init_vpad();
            break;
        case API_HPAD:
            cont_chan = hpad_increment;
            hpad_increment += 1;
            init_hpad();
        case API_USB_HID:

            break;
    }
    gd_controller_id = Input::get_singleton()->get_unused_joy_id();
}

WiiUController::~WiiUController(){
    switch (api_type){
        case API_KPAD:
            kpad_increment -= 1;
            break;
        case API_VPAD:
            vpad_increment -= 1;
            break;
        case API_HPAD:
            hpad_increment -= 1;
        case API_USB_HID:

            break;
    }
    p_input_sing->joy_connection_changed(gd_controller_id, false, "");
}


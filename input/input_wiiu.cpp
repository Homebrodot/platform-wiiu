#include "input_wiiu.h"

#include <padscore/kpad.h>

/*
void internal_read(uint32_t &in_buttons, button_struct *button_chart, uint8_t chart_size_plus_1){
    uint32_t output;
    uint8_t iter;
    button_struct current;
    for (iter = 0; iter < chart_size_plus_1; iter++){
        current = button_chart[iter];
        if (in_buttons & current.orig_button){
        output |= current.u_button;
        }
    }
    return output;
}
*/

InputWiiU::InputWiiU(){
    WiiUController::p_input_sing = Input::get_singleton();
}

void WiiUController::button_read(){

}

void WiiUController::analog_read(){
    
}

void WiiUController::update(){
    uint32_t trigger;
    switch (controller_type){
        case TYPE_WIIMOTE_ALONE:
            KPADStatus status; 
            KPADRead((KPADChan) cont_chan, &status, 1);
            break;
    }
}

inline uint8_t WiiUController::get_player_place(){
    
}

WiiUController::WiiUController(WiiUControllerTypes type = TYPE_WIIMOTE_ALONE){
    controller_type = type;
    switch (controller_type){
        case TYPE_WIIMOTE_ALONE:
        case TYPE_WIIMOTE_NUNCHUK:
        case TYPE_WIIMOTE_CLASSIC:
        case TYPE_WIIU_PRO:
            cont_chan = kpad_increment;
            kpad_increment += 1;
            break;
        case TYPE_GAMEPAD:
            cont_chan = vpad_increment;
            vpad_increment += 1;
            break;
        case TYPE_GAMECUBE_HPAD:
            cont_chan = hpad_increment;
            hpad_increment += 1;
        case TYPE_HID_USB:

            break;
    }
    gd_controller_id = Input::get_singleton()->get_unused_joy_id();
    update();
}

WiiUController::~WiiUController(){
    switch (controller_type){
        case TYPE_WIIMOTE_ALONE:
        case TYPE_WIIMOTE_NUNCHUK:
        case TYPE_WIIMOTE_CLASSIC:
        case TYPE_WIIU_PRO:
            kpad_increment -= 1;
            break;
        case TYPE_GAMEPAD:
            vpad_increment -= 1;
            break;
        case TYPE_GAMECUBE_HPAD:
            hpad_increment -= 1;
        case TYPE_HID_USB:

            break;
    }
    p_input_sing->joy_connection_changed(gd_controller_id, false, "");
}


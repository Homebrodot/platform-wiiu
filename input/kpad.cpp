#include "input_wiiu.h"

#include <padscore/kpad.h>

const button_translate WiiUController::wiimote_buttons[11] = {
    {WPAD_BUTTON_HOME, (int) JoyButton::GUIDE},
    {WPAD_BUTTON_A, (int) JoyButton::A},
    {WPAD_BUTTON_B, (int) JoyButton::B},
    {WPAD_BUTTON_1, (int) JoyButton::Y},
    {WPAD_BUTTON_2, (int) JoyButton::X},
    {WPAD_BUTTON_PLUS, (int) JoyButton::START}, //I think?
    {WPAD_BUTTON_MINUS, (int) JoyButton::BACK}, //I think?
    {WPAD_BUTTON_UP, (int) JoyButton::DPAD_UP},
    {WPAD_BUTTON_DOWN, (int) JoyButton::DPAD_DOWN},
    {WPAD_BUTTON_LEFT, (int) JoyButton::DPAD_LEFT},
    {WPAD_BUTTON_RIGHT, (int) JoyButton::DPAD_RIGHT},
};

const button_translate WiiUController::nunchuck_buttons[11] = {

};

const button_translate WiiUController::classic_buttons[15] = {
    {WPAD_CLASSIC_BUTTON_HOME, (int) JoyButton::GUIDE},
    {WPAD_CLASSIC_BUTTON_A, (int) JoyButton::A},
    {WPAD_CLASSIC_BUTTON_B, (int) JoyButton::B},
    {WPAD_CLASSIC_BUTTON_X, (int) JoyButton::X},
    {WPAD_CLASSIC_BUTTON_Y, (int) JoyButton::Y},
    {WPAD_CLASSIC_BUTTON_PLUS, (int) JoyButton::START},
    {WPAD_CLASSIC_BUTTON_MINUS, (int) JoyButton::BACK},
    {WPAD_CLASSIC_BUTTON_UP, (int) JoyButton::DPAD_UP},
    {WPAD_CLASSIC_BUTTON_DOWN, (int) JoyButton::DPAD_DOWN},
    {WPAD_CLASSIC_BUTTON_LEFT, (int) JoyButton::DPAD_LEFT},
    {WPAD_CLASSIC_BUTTON_RIGHT, (int) JoyButton::DPAD_RIGHT},
    {WPAD_CLASSIC_BUTTON_L, (int) JoyButton::LEFT_SHOULDER},
    {WPAD_CLASSIC_BUTTON_R, (int) JoyButton::RIGHT_SHOULDER},
};

const button_translate WiiUController::classic_axes[10] = {
    {WPAD_CLASSIC_STICK_L_EMULATION_UP, (int) JoyAxis::LEFT_Y},
    {WPAD_CLASSIC_STICK_L_EMULATION_DOWN, (int) JoyAxis::LEFT_Y},
    {WPAD_CLASSIC_STICK_L_EMULATION_LEFT, (int) JoyAxis::LEFT_X},
    {WPAD_CLASSIC_STICK_L_EMULATION_RIGHT, (int) JoyAxis::LEFT_X},
    {WPAD_CLASSIC_STICK_R_EMULATION_UP, (int) JoyAxis::RIGHT_Y},
    {WPAD_CLASSIC_STICK_R_EMULATION_DOWN, (int) JoyAxis::RIGHT_Y},
    {WPAD_CLASSIC_STICK_R_EMULATION_LEFT, (int) JoyAxis::RIGHT_X},
    {WPAD_CLASSIC_STICK_R_EMULATION_RIGHT, (int) JoyAxis::RIGHT_X},
    {WPAD_CLASSIC_BUTTON_ZL, (int) JoyAxis::TRIGGER_LEFT},
    {WPAD_CLASSIC_BUTTON_ZR, (int) JoyAxis::TRIGGER_RIGHT},
};

const button_translate WiiUController::pro_buttons[15] = {
    {WPAD_PRO_BUTTON_HOME, (int) JoyButton::GUIDE},
    {WPAD_PRO_BUTTON_A, (int) JoyButton::A},
    {WPAD_PRO_BUTTON_B, (int) JoyButton::B},
    {WPAD_PRO_BUTTON_X, (int) JoyButton::X},
    {WPAD_PRO_BUTTON_Y, (int) JoyButton::Y},
    {WPAD_PRO_BUTTON_PLUS, (int) JoyButton::START},
    {WPAD_PRO_BUTTON_MINUS, (int) JoyButton::BACK},
    {WPAD_PRO_BUTTON_UP, (int) JoyButton::DPAD_UP},
    {WPAD_PRO_BUTTON_DOWN, (int) JoyButton::DPAD_DOWN},
    {WPAD_PRO_BUTTON_LEFT, (int) JoyButton::DPAD_LEFT},
    {WPAD_PRO_BUTTON_RIGHT, (int) JoyButton::DPAD_RIGHT},
    {WPAD_PRO_TRIGGER_L, (int) JoyButton::LEFT_SHOULDER},
    {WPAD_PRO_TRIGGER_R, (int) JoyButton::RIGHT_SHOULDER},
    //These may split off into a different struct
};

const button_translate pro_axes[] = {
    {WPAD_PRO_TRIGGER_ZL, (int) JoyAxis::TRIGGER_LEFT},
    {WPAD_PRO_TRIGGER_ZR, (int) JoyAxis::TRIGGER_RIGHT},
};

void InputWiiU::process_kpad(){
    KPADStatus wiimote;
    KPADRead(WPAD_CHAN_0, &wiimote, 1);
    
}

void InputWiiU::setup_kpad(){
    
}

void internal_process_kpad_button(KPADStatus &buttons){
    
}
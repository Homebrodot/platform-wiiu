#include "input_wiiu.h"

#include <padscore/kpad.h>

const button_translate wiimote_buttons[] = {
    {WPAD_BUTTON_HOME, JoyButton::GUIDE},
    {WPAD_BUTTON_A, JoyButton::A},
    {WPAD_BUTTON_B, JoyButton::B},
    {WPAD_BUTTON_1, JoyButton::Y},
    {WPAD_BUTTON_2, JoyButton::X},
    {WPAD_BUTTON_PLUS, JoyButton::START}, //I think?
    {WPAD_BUTTON_MINUS, JoyButton::BACK}, //I think?
};

const hat_translate wiimote_dpad[] = {
    {WPAD_BUTTON_UP, HatMask::UP},
    {WPAD_BUTTON_DOWN, HatMask::DOWN},
    {WPAD_BUTTON_LEFT, HatMask::LEFT},
    {WPAD_BUTTON_RIGHT, HatMask::RIGHT},
};

//I wasn't sure how to map these tbh
const button_translate nunchuck_buttons[] = {
    {WPAD_NUNCHUK_BUTTON_C, JoyButton::LEFT_SHOULDER},
    {WPAD_NUNCHUK_BUTTON_Z, JoyButton::RIGHT_SHOULDER},
};

const button_translate classic_buttons[] = {
    {WPAD_CLASSIC_BUTTON_HOME, JoyButton::GUIDE},
    {WPAD_CLASSIC_BUTTON_A, JoyButton::A},
    {WPAD_CLASSIC_BUTTON_B, JoyButton::B},
    {WPAD_CLASSIC_BUTTON_X, JoyButton::X},
    {WPAD_CLASSIC_BUTTON_Y, JoyButton::Y},
    {WPAD_CLASSIC_BUTTON_PLUS, JoyButton::START},
    {WPAD_CLASSIC_BUTTON_MINUS, JoyButton::BACK},
    {WPAD_CLASSIC_BUTTON_L, JoyButton::LEFT_SHOULDER},
    {WPAD_CLASSIC_BUTTON_R, JoyButton::RIGHT_SHOULDER},
};

const hat_translate classic_dpad[] = {
    {WPAD_CLASSIC_BUTTON_UP, HatMask::UP},
    {WPAD_CLASSIC_BUTTON_DOWN, HatMask::DOWN},
    {WPAD_CLASSIC_BUTTON_LEFT, HatMask::LEFT},
    {WPAD_CLASSIC_BUTTON_RIGHT, HatMask::RIGHT},
};

const button_translate pro_buttons[] = {
    {WPAD_PRO_BUTTON_HOME, JoyButton::GUIDE},
    {WPAD_PRO_BUTTON_A, JoyButton::A},
    {WPAD_PRO_BUTTON_B, JoyButton::B},
    {WPAD_PRO_BUTTON_X, JoyButton::X},
    {WPAD_PRO_BUTTON_Y, JoyButton::Y},
    {WPAD_PRO_BUTTON_PLUS, JoyButton::START},
    {WPAD_PRO_BUTTON_MINUS, JoyButton::BACK},
    {WPAD_PRO_BUTTON_STICK_L, JoyButton::LEFT_STICK},
    {WPAD_PRO_BUTTON_STICK_R, JoyButton::RIGHT_STICK},
    {WPAD_PRO_TRIGGER_L, JoyButton::LEFT_SHOULDER},
    {WPAD_PRO_TRIGGER_R, JoyButton::RIGHT_SHOULDER},
};

const hat_translate pro_dpad[] = {
    {WPAD_PRO_BUTTON_UP, HatMask::UP},
    {WPAD_PRO_BUTTON_DOWN, HatMask::DOWN},
    {WPAD_PRO_BUTTON_LEFT, HatMask::LEFT},
    {WPAD_PRO_BUTTON_RIGHT, HatMask::RIGHT},
};


void WiiUController::update_kpad(){
    KPADStatus wiimote;
    KPADRead( (KPADChan) cont_chan, &wiimote, 1);

    switch (wiimote.extensionType){
        case WPAD_EXT_CORE:
        case WPAD_EXT_MPLUS:
        case WPAD_EXT_NUNCHUK:
        case WPAD_EXT_MPLUS_NUNCHUK:


            break;
        case WPAD_EXT_CLASSIC:
        case WPAD_EXT_MPLUS_CLASSIC:

            break;
        case WPAD_EXT_PRO_CONTROLLER:

            break;
    };


    Dictionary controller_info;
    controller_info["controller"] = controller_type_as_string((KPADExtensionType) wiimote.extensionType);

}

inline String controller_type_as_string(KPADExtensionType type){
    switch (type){
        case WPAD_EXT_CORE:
            return "Standard Wiimote";
        case WPAD_EXT_MPLUS:
            return "Wiimote with Motion Plus";
        case WPAD_EXT_NUNCHUK:
            return "Standard Wiimote with Nunchuk";
        case WPAD_EXT_MPLUS_NUNCHUK:
            return "Wiimote with Motion Plus and Nunchuk";
        case WPAD_EXT_CLASSIC:
            return "Wiimote with Wii Classic Controller";
        case WPAD_EXT_MPLUS_CLASSIC:
            return "Wiimote with Motion Plus and Wii Classic Controller";
        case WPAD_EXT_PRO_CONTROLLER:
            return "Wii U Pro Controller";
    }
}

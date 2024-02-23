#include "core/input/input.h"



typedef struct button_translate {
    //Some sort of "*Button" value from one of the APIs
    uint32_t wiiu_button;
    //Either a JoyButton or JoyAxis
    int godot_button; 
};

enum WiiUControllerTypes {
    TYPE_GAMEPAD,
    TYPE_WIIMOTE_ALONE,
    TYPE_WIIMOTE_NUNCHUK,
    TYPE_WIIMOTE_CLASSIC,
    TYPE_WIIU_PRO,
    TYPE_GAMECUBE_HPAD,
    TYPE_HID_USB,
};

/*
These are little objects representing each controller.
They're designed to be semi API agnostic so that I can reuse them 
for the mostly quite similar VPAD, KPAD, HPAD, etc APIs.
*/
class WiiUController {
//Class shared
public:

    //Defined in kpad.cpp
    static const button_translate wiimote_buttons[11];
    static const button_translate nunchuck_buttons[11];
    static const button_translate classic_buttons[15];
    static const button_translate classic_axes[10];
    static const button_translate pro_buttons[15];

    //Defined in vpad.cpp
    static const button_translate gamepad_buttons[15];

    //Defined in (coming soon)
    static const button_translate gamecube_buttons[15];

    /*
    These increase when a controller is added and 
    decrease when one is destroyed, so that channels 
    can be properly assigned/freed upon creation/deletion
    */
    static uint8_t vpad_increment;
    static uint8_t kpad_increment;
    static uint8_t hpad_increment;

    static Input *p_input_sing;

//Object specific and kinda touchy
private:

    //Godot-side controller ID

    //Note to self: Use this ID to tie a gamepad to a Window/Viewport/Something; When
    //the controller is closed, close the associated "Window" for its screen
    int gd_controller_id;

    WiiUControllerTypes controller_type;

    //The channel the controller internally corresponds to. Typecast to the right type.
    uint8_t cont_chan;

    //For performance reasons, keep a pointer to the translation chart of the controller
    button_translate *chart;

    void button_read();
    void analog_read();

//Object specific
public:

    //Update the controller
    void update();

    inline uint8_t get_player_place();
    inline uint8_t find_new_player_place();

    //Setup joypad
    WiiUController(WiiUControllerTypes type = TYPE_WIIMOTE_ALONE); 
    //destroy joypad
    ~WiiUController();

};

/*
Note: Touch input is *usually* handled by DisplayServer, not the input singleton,
which might cause issues with multi-DRC and touch inputs, idk.
*/

class InputWiiU {
public:
    InputWiiU();
    ~InputWiiU();

    WiiUController controllers[15];

    Input *input = nullptr;

    void setup_kpad();
    void remove_kpad();
    void setup_vpad();
    void remove_vpad();
    void setup_hpad();
    void remove_hpad();

    void process_vpad();
    void process_kpad();
    void process_hpad();

    //Used for input processing when swkbd is active, possibly also HID USB keyboards?
    void process_keyboard();

    inline void process_joypads(){
        process_vpad();
        process_kpad();
    }
};


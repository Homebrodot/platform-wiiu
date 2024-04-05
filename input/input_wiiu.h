#include "core/input/input.h"

struct button_translate {
    uint32_t wiiu_button;
    JoyButton godot_button;
};

//Up, Down, Left, Right
struct hat_translate {
    uint32_t wiiu_button;
    HatMask godot_button;
};

//Left X, Left Y, Right X, Right Y, Left Trigger, Right Trigger
struct axis_translate {
    float left_x;
    float left_y;
    float right_x;
    float right_y;
    float trigger_l;
    float trigger_r;
};

enum WiiUAPITypes {
    API_NULL,
    API_VPAD,
    API_KPAD,
    API_HPAD,
    API_USB_HID,
};

/*
These are little objects representing each controller.
They're designed to be API agnostic in the frontend so that I can 
reuse them for the mostly quite similar VPAD, KPAD, HPAD, etc APIs,
changing relevant code in the backend.
*/
class WiiUController {
//Class shared
public:

    /*
    These increase when a controller is added and 
    decrease when one is destroyed, so that channels 
    can be properly assigned/"freed" upon creation/deletion
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

    //Tbh could replace with WiiUAPIType
    WiiUAPITypes api_type;

    //The channel the controller internally corresponds to in its API. (Typecast as needed)
    uint8_t cont_chan;

    //Helper function for sending all standard joypad axis info to the singleton
    //Any extra axes have to be passed manually by the backing API processing function
    void axis_process(axis_translate axis_group);

    //These are defined here in order to be in class scope for other functions

    void init_vpad();
    void update_vpad();

    void init_kpad();
    void update_kpad();

    void init_hpad();
    void update_hpad();

    void init_hid();
    void update_hid();

//Object specific
public:

    //Update the controller
    void (*update)() = nullptr;

    //Sometimes, the object will need to change its backing controller
    void change_controller_type(WiiUAPITypes type);

    //Setup joypad
    WiiUController(WiiUAPITypes type = API_NULL); 
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

    //Used for input processing when swkbd is active?
    void process_swkbd();

    inline void process_joypads(){
        for (uint8_t i = 0; i < Input::JOYPADS_MAX; i++){
            controllers[i].update();
        }
    }
};


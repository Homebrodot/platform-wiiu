#include "os_wiiu.h"

#include "core/debugger/engine_debugger.h"
#include "core/debugger/script_debugger.h"
#include "core/io/marshalls.h"
#include "core/version_generated.gen.h"
// #include "fileaccess/dir_access_wiiu.h" //placeholder
// #include "fileaccess/file_access_wiiu.h" //placeholder
#include "main/main.h"
#include "servers/audio_server.h"
#include "servers/rendering/rendering_server_default.h"
#include "servers/text_server.h"
#include "core/variant/typed_array.h"

void OS_WiiU::alert(const String &p_alert, const String &p_title) {
//I'd like to put in an adaptation of https://github.com/Lynx64/WiiVCLaunch/blob/main/src/main.cpp here
}

String OS_WiiU::get_name() const {
	return "Wii U";
}

String OS_WiiU::get_distribution_name() const {
	return "Cafe OS";
}

String OS_WiiU::get_version() const {
    return "5.5.5"; //todo: Get the actual version from the console
}

String OS_WiiU::get_processor_name() const {
    return "Espresso";
}

PackedStringArray OS_WiiU::get_video_adapter_driver_info() const {
    PackedStringArray info;
    info.append("amd");
    info.append("1.0");
    return info;
}

Error OS_WiiU::shell_open(String uri) {
    //Implement check for http, open in Internet Browser if found
    return ERR_METHOD_NOT_FOUND
}

#include "export_plugin.h"

//EditorExportPlatformWiiU::EditorExportPlatformWiiU(){

//};

void EditorExportPlatformWiiU::get_preset_features(const Ref<EditorExportPreset> &p_preset, List<String> *r_features) const {

};

void EditorExportPlatformWiiU::get_export_options(List<ExportOption> *r_options) const {

};

String EditorExportPlatformWiiU::get_name() const {
    return "Wii U";
}

String EditorExportPlatformWiiU::get_os_name() const { 
	return "Cafe OS"; 
}

Ref<Texture2D> EditorExportPlatformWiiU::get_logo() const {
    return logo;
}

Ref<Texture2D> EditorExportPlatformWiiU::get_run_icon() const {
    return run_icon;
}

bool EditorExportPlatformWiiU::has_valid_export_configuration(const Ref<EditorExportPreset> &p_preset, String &r_error, bool &r_missing_templates, bool p_debug) const {
    return false;
}

bool EditorExportPlatformWiiU::has_valid_project_configuration(const Ref<EditorExportPreset> &p_preset, String &r_error) const {
    return false;
}

List<String> EditorExportPlatformWiiU::get_binary_extensions(const Ref<EditorExportPreset> &p_preset) const {
	List<String> list;
	list.push_back("elf");
	list.push_back("rpx");
	list.push_back("wuhb");
	
	return list;
}

Error EditorExportPlatformWiiU::export_project(const Ref<EditorExportPreset> &p_preset, bool p_debug, const String &p_path, int p_flags){
    return ERR_CANT_CREATE;
}

void EditorExportPlatformWiiU::get_platform_features(List<String> *r_features) const {
		r_features->push_back("game_console");
		r_features->push_back("homebrew");
		r_features->push_back("wii_pointer");
}

void EditorExportPlatformWiiU::resolve_platform_feature_priorities(const Ref<EditorExportPreset> &p_preset, HashSet<String> &p_features){

}
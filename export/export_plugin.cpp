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

//TODO: Fix this; this is literally copy-pasted from IOS with a line change, lol
List<String> EditorExportPlatformWiiU::get_binary_extensions(const Ref<EditorExportPreset> &p_preset) const {
	List<String> list;
	if (p_preset.is_valid()) {
		bool project_only = p_preset->get("application/export_project_only");
		if (project_only) {
			list.push_back("xcodeproj");
		} else {
			list.push_back("rpx");
		}
	}
	return list;
}

Error EditorExportPlatformWiiU::export_project(const Ref<EditorExportPreset> &p_preset, bool p_debug, const String &p_path, int p_flags){
    return ERR_CANT_CREATE;
}

void EditorExportPlatformWiiU::get_platform_features(List<String> *r_features) const {
		r_features->push_back("game_console");
		r_features->push_back("homebrew");
}

void EditorExportPlatformWiiU::resolve_platform_feature_priorities(const Ref<EditorExportPreset> &p_preset, HashSet<String> &p_features){

}
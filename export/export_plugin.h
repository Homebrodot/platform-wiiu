
#include "editor/export/editor_export_platform.h"

//A lot of this comes from the IOS port

class EditorExportPlatformWiiU: public EditorExportPlatform {
	GDCLASS(EditorExportPlatformWiiU, EditorExportPlatform);
	
	Ref<ImageTexture> logo;
	Ref<ImageTexture> run_icon;
	
protected:
	virtual void get_preset_features(const Ref<EditorExportPreset> &p_preset, List<String> *r_features) const override;
	virtual void get_export_options(List<ExportOption> *r_options) const override;
	
public:
	virtual String get_name() const override;
	virtual String get_os_name() const override;
	virtual Ref<Texture2D> get_logo() const override;
	virtual Ref<Texture2D> get_run_icon() const override;
	
	virtual bool has_valid_export_configuration(const Ref<EditorExportPreset> &p_preset, String &r_error, bool &r_missing_templates, bool p_debug = false) const override;
	virtual bool has_valid_project_configuration(const Ref<EditorExportPreset> &p_preset, String &r_error) const override;
	
	virtual List<String> get_binary_extensions(const Ref<EditorExportPreset> &p_preset) const override;
	
	
	virtual Error export_project(const Ref<EditorExportPreset> &p_preset, bool p_debug, const String &p_path, int p_flags = 0) override;
	
	virtual void get_platform_features(List<String> *r_features) const override;
	
	virtual void resolve_platform_feature_priorities(const Ref<EditorExportPreset> &p_preset, HashSet<String> &p_features) override;
	
	//EditorExportPlatformWiiU();
	//~EditorExportPlatformWiiU();
};

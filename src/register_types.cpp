#include "register_types.h"

#include "hello_world/gdexample.h"
#include "ECSWorld.h"
#include "GDEntity.h"
#include "GDComponent.h"
#include "GDSystem.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_gdflecs_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    ClassDB::register_class<GDExample>();
    ClassDB::register_class<GDEntity>();
    ClassDB::register_class<GDComponent>();
    ClassDB::register_class<ECSWorld>();
    ClassDB::register_class<GDSystem>();}

void uninitialize_gdflecs_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT gdflecs_library_init(const GDExtensionInterface *p_interface, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

    init_obj.register_initializer(initialize_gdflecs_module);
    init_obj.register_terminator(uninitialize_gdflecs_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}
}
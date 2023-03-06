#ifndef GDSYSTEM_H
#define GDSYSTEM_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/string.hpp>
#include "flecs/flecs.h"

class ECSWorld;
struct ScriptEntity;

class GDSystem : public godot::Node {
    GDCLASS(GDSystem, Node);

    private:
        godot::String filterDsl;
        flecs::query<ScriptEntity> q;

    protected:
        static void _bind_methods();
        
    public:
        flecs::world* ecs;
        GDSystem();
        ~GDSystem();
        void InitSystem(ECSWorld* world);
        void Tick(float delta);
        void SetFilter(const godot::String& dsl);
        godot::String GetFilter() const;
};

#endif

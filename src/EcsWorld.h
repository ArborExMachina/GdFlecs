#ifndef ECSWORLD_H
#define ECSWORLD_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/string.hpp>

#include "flecs/flecs.h"

class GDEntity;
class GDComponent;
struct ScriptEntity;

class ECSWorld : public godot::Node {
	GDCLASS(ECSWorld, Node);

private:
	
protected:
	static void _bind_methods();
	void _notification(int p_notification);

public:
	ECSWorld();
	~ECSWorld();
	
	flecs::world world;
	GDEntity* Entity();
	godot::Ref<GDComponent> ECSWorld::CreateComponent(const godot::String& name);
	godot::Array Filter(const godot::String& query);
	void Tick(float delta);

	flecs::query<ScriptEntity> BuildSystemQuery(const godot::String& query) const;
	int GetEntityCount() const;
};

#endif

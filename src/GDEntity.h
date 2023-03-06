#ifndef GDENTITY_H
#define GDENTITY_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/string.hpp>

#include "flecs/flecs.h"

class GDComponent;

class GDEntity : public godot::Object {
	GDCLASS(GDEntity, Object);

private:
// add a dictionary/map that maps a scriptable comp id to its corrasponding pair on this entity, then write a Get() method that takes a GDComp and returns the ScriptableData dictionary for it
protected:
	static void _bind_methods();

public:
	godot::Dictionary dataBag;
	flecs::world* ecs;
	bool valid;
	flecs::entity entity;
	GDEntity();
	~GDEntity();

	void SetComp(godot::Ref<GDComponent> gdComp, godot::Variant values);
	void Remove(godot::Ref<GDComponent> gdComp);
	godot::Variant GetComp(godot::Ref<GDComponent> gdComp);
	int GetID() const;
	godot::String GetTypeID() const;
};

#endif // SUMMATOR_H

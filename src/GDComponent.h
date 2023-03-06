
#ifndef GDCOMP_H
#define GDCOMP_H

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/string_name.hpp>
#include "flecs/flecs.h"

class GDComponent : public godot::RefCounted {
	GDCLASS(GDComponent, RefCounted);

protected:
	static void _bind_methods();

public:
    flecs::entity gd_comp;

	GDComponent();
	~GDComponent();

    godot::StringName GetTypeName();	
	int GetID();
};

#endif // SUMMATOR_H

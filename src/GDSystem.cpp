#include <iostream>

#include <godot_cpp/classes/engine.hpp>

#include "GDSystem.h"
#include "ECSWorld.h"
#include "ScriptEntity.h"

using namespace godot;

void GDSystem::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_filter", "dsl"), &GDSystem::SetFilter);
	ClassDB::bind_method(D_METHOD("get_filter"), &GDSystem::GetFilter);

	ADD_PROPERTY(
		PropertyInfo(Variant::STRING, "filter"),
		"set_filter", "get_filter");
}

GDSystem::GDSystem()
{
}

GDSystem::~GDSystem()
{
}

void GDSystem::Tick(float delta)
{
	// std::wstring ws = filterDsl.c_str();
	// std::string s(ws.begin(), ws.end());
	// std::cout << "SystemTick: " << s.c_str() << std::endl;

	this->call("_pre_tick", delta);

	ecs->defer_begin();
	q.each([this, delta](flecs::iter& it, size_t index, ScriptEntity& script_ent) {
		// std::cout << "entity: " << it.entity(index).id() << std::endl;
		Array comps = Array();
		int field_count = it.field_count() + 1;
		for (int i = 2; i < field_count; i++)
		{
			auto comp = it.id(i);
			// std::cout << "comp id: " << comp.name().c_str() << std::endl;
			// std::cout << "script comps entity id: " << script_ent.ent->entity.id() << std::endl;
			// std::cout << "has comp: " << script_ent.ent->dataBag.has(comp.id()) << std::endl;
			comps.append(script_ent.ent->dataBag[comp.id()]);
		}		

		this->call("_proccess_entity", delta, script_ent.ent, comps);
	});
	ecs->defer_end();
}

void GDSystem::InitSystem(ECSWorld *world)
{
    q = world->BuildSystemQuery(filterDsl);
    ecs = &(world->world);
}

void GDSystem::SetFilter(const String& dsl)
{
	filterDsl = dsl;
}

String GDSystem::GetFilter() const
{
	return filterDsl;
}
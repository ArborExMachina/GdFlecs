/* summator.cpp */
#include <iostream>
#include "GDEntity.h"
#include "GDComponent.h"
#include "ECSWorld.h"
#include "ScriptEntity.h"

using namespace godot;

void GDEntity::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_comp", "gd_comp_def"), &GDEntity::SetComp);
    ClassDB::bind_method(D_METHOD("get_id"), &GDEntity::GetID);
    ClassDB::bind_method(D_METHOD("get_type_id"), &GDEntity::GetTypeID);
    ClassDB::bind_method(D_METHOD("remove_comp", "component"), &GDEntity::Remove);
    ClassDB::bind_method(D_METHOD("get_comp", "component"), &GDEntity::GetComp);
}

GDEntity::GDEntity() {
    valid = false;
}

GDEntity::~GDEntity()
{
    // bool defered = ecs->is_deferred();
    // if (!defered)
    //     ecs->defer_begin();
    dataBag.clear();
    auto se = entity.get_mut<ScriptEntity>();
    se->ent = nullptr;
    entity.destruct();
    // if (!defered)
    //     ecs->defer_end();
}

// TODO: rename this. set() is a builtin
void GDEntity::SetComp(Ref<GDComponent> gdComp, Variant values)
{
    if (!valid)
    {
        std::cout << "FLECS: tried to add comp to a GDEntity with no backer entity" << std::endl;
        return;
    }

    auto tag = gdComp->gd_comp;
    if (entity.has(tag))
    {
        return;
    }

    // bool defered = ecs->is_deferred();
    // if (!defered)
    //     ecs->defer_begin();
    entity.add(tag);
    dataBag[tag.id()] = values;

    //std::cout << "added comp " << gdComp->gd_comp.name().c_str() << "[" << gdComp->gd_comp.id() << "]" << std::endl;
    // if (!defered)
    //     ecs->defer_end();
}

void GDEntity::Remove(Ref<GDComponent> gdComp)
{
    auto tag = gdComp->gd_comp;
    if(entity.has(tag))
    {
        bool defered = ecs->is_deferred();
        // if (!defered)
        //     ecs->defer_begin();
        entity.remove(tag);
        // if (!defered)
        //     ecs->defer_end();
        dataBag.erase(tag.id());
    }
}

Variant GDEntity::GetComp(Ref<GDComponent> gdComp)
{
    auto tag = gdComp->gd_comp;
    if(entity.has(tag))
    {
        return dataBag.get(tag.id(), Variant());
    }
    return Variant();
}

int GDEntity::GetID() const
{
    return entity.id();
}

String GDEntity::GetTypeID() const
{
    return entity.type_id().str().c_str();
}

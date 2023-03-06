/* summator.cpp */

#include "GDComponent.h"

using namespace godot;

void GDComponent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_type_name"), &GDComponent::GetTypeName);
    ClassDB::bind_method(D_METHOD("get_ID"), &GDComponent::GetID);
}

GDComponent::GDComponent() {
    
}

GDComponent::~GDComponent()
{
	
}

StringName GDComponent::GetTypeName()
{
    return gd_comp.name().c_str();
}

int GDComponent::GetID()
{
    return gd_comp.id();
}

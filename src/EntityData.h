#ifndef ENTITYDATAH
#define ENTITYDATAH

#include <godot_cpp/variant/dictionary.hpp>
#include "GDEntity.h"

struct EntityData
{
    public:
    GDEntity entity;
    godot::Dictionary data;
};

#endif
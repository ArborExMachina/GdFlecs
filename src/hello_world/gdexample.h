#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>
#include "flecs/flecs.h"

namespace godot {

class GDExample : public Sprite2D {
    GDCLASS(GDExample, Sprite2D)

private:
    float time_passed;
    flecs::world ecsWorld;
    flecs::system moveSystem;

protected:
    static void _bind_methods();

public:
    GDExample();
    ~GDExample();

    void _process(float delta);
};

}

#endif
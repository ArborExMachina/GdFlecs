#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

struct nodeRef
{
    Node2D* node;
    float timePassed;
};


void GDExample::_bind_methods() {
}

GDExample::GDExample() {
    // initialize any variables here
    time_passed = 0.0;
    auto e = ecsWorld.entity();
    e.add<nodeRef>();
    e.set<nodeRef>({this, 0});

    moveSystem = ecsWorld.system<nodeRef>()
        .each([](flecs::iter it, size_t index, nodeRef& nodeRef) {
            nodeRef.timePassed += it.delta_time();
            Vector2 new_position = Vector2(10.0 + (10.0 * sin(nodeRef.timePassed * 2.0)), 10.0 + (10.0 * cos(nodeRef.timePassed * 1.5)));
            nodeRef.node->set_position(new_position);
        });
}

GDExample::~GDExample() {
    // add your cleanup here
}

void GDExample::_process(float delta) {
    moveSystem.run(delta);
}
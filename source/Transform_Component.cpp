#include "../headers/Transform_Component.h"

blood_engine::Transform_Component::Transform_Component(const Transform_Component& other) :
    Component(other), Position(other.Position), Rotation(other.Rotation), Scale(other.Scale)
{
}

std::unique_ptr<blood_engine::Component> blood_engine::Transform_Component::Clone() const
{
    return std::make_unique<Transform_Component>(*this);
}
#include "../headers/Renderable_Component.h"
std::unique_ptr<blood_engine::Component> blood_engine::Renderable_Component::Clone() const
{
    return std::unique_ptr<Component>(new Renderable_Component(*this));
}

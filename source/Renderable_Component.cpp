#include "../headers/Renderable_Component.h"
#include <string>
#include <iostream>


blood_engine::Renderable_Component::Renderable_Component(std::string name, std::shared_ptr<Model> model) : name(name), model(model)
{
}

std::unique_ptr<blood_engine::Component> blood_engine::Renderable_Component::Clone() const
{
    return std::unique_ptr<Component>(new Renderable_Component(*this));
}

std::string blood_engine::Renderable_Component::GetName()
{
    return this->name;
}

std::shared_ptr<Model> blood_engine::Renderable_Component::GetModel()
{
    return this->model;
}

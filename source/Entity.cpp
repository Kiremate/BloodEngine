#include "../headers/Entity.h"
#include "../headers/Renderable_Component.h"
#include "../headers/Physics_Component.h"
#include "../headers/Transform_Component.h"
template void blood_engine::Entity::AddComponent<blood_engine::Renderable_Component>(std::shared_ptr<blood_engine::Renderable_Component>);
template void blood_engine::Entity::AddComponent<blood_engine::Physics_Component>(std::shared_ptr<blood_engine::Physics_Component>);
template void blood_engine::Entity::AddComponent<blood_engine::Transform_Component>(std::shared_ptr<blood_engine::Transform_Component>);

blood_engine::Entity::Entity()
{
	this->ID = 0;
	this->parent = nullptr;
	this->scene = nullptr;
	this->transform = nullptr;
}

blood_engine::Entity::Entity(size_t ID, Entity* parent, Scene* scene)
{
	this->ID = ID;
	this->parent = parent;
	this->scene = scene;
	// TODO initialize Transform
}

blood_engine::Entity::Entity(const Entity& other)
    : ID(other.ID), parent(other.parent), scene(other.scene), transform(other.transform)
{
    // copy the vector of components
    for (auto& comp : other.components) {
        components.push_back(comp->Clone());
    }
}

blood_engine::Entity::Entity(const std::string& name) : name(name)
{
}

template<typename T>
void blood_engine::Entity::AddComponent(std::shared_ptr<T> component)
{
	static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");
	components.push_back(std::static_pointer_cast<Component>(component));
}
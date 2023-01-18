#include "../headers/Entity.h"

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
#include "../headers/Component.h"

blood_engine::Component::Component(){ owner = nullptr;}
blood_engine::Component::Component(Entity* owner) : 
	owner(owner) {}
blood_engine::Component::Component(const Component& other) : 
	owner(other.owner) {}

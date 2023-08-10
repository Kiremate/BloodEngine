/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#ifndef ENTITY_H
#define ENTITY_H

#include "Transform_Component.h"
#include <vector>
#include <string>
#include <iostream>
class Scene;

namespace blood_engine {
	class Entity {


	public:
		// Empty constructor
		Entity();
		// Parametrized Constructor
		Entity(size_t ID, Entity* parent, Scene* scene);
		// Copy Constructor
		Entity(const Entity& other);
		Entity(const std::string& name);
		virtual ~Entity() = default;
		template<typename T>
		void AddComponent(std::shared_ptr<T> component);
	private:
		size_t ID;
		std::string name;
		Entity* parent;
		Scene* scene;
		Transform_Component* transform;
		std::vector<std::shared_ptr<Component>> components;
	};
	
}
#endif // !ENTITY_H

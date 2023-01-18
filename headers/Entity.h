#ifndef ENTITY_H
#define ENTITY_H

#include "Transform_Component.h"
#include <vector>

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
		virtual ~Entity();

	private:
		size_t ID;
		Entity* parent;
		Scene* scene;
		Transform_Component* transform;
		std::vector<std::unique_ptr<Component>> components;
	};
}
#endif // !ENTITY_H

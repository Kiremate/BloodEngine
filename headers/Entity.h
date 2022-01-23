#ifndef ENTITY_H
#define ENTITY_H

#include "Transform_Component.h"
#include <vector>

class Scene;

namespace blood_engine {
	class Entity {


	public:


	private:
		size_t ID;
		Entity* parent;
		Scene* scene;
		Transform_Component transform;
		std::vector<Component> components;
	};
}
#endif // !ENTITY_H

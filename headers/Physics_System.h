/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#ifndef PHYSICS_SYSTEM
#define PHYSICS_SYSTEM
#include "System.h"
#include <vector>
#include "Physics_Component.h"

namespace blood_engine {

	class Physics_System : public System {


	public:
		Physics_System() = default;
		~Physics_System() override = default;
		virtual SystemType GetType() const { return SystemType::PHYSICS; }
		
		bool CreatePhysicsComponent();
		// Add a new Physic_Component to the system
		void AddComponent(std::unique_ptr<Physics_Component> component);
		void RemoveComponent(Physics_Component* component);
		virtual void Update() override;
	private:

		// World BOX2D
		// b2World m_world;
		// Components
		std::vector<std::unique_ptr<Physics_Component>> physics_components;


	};
}
#endif // !PHYSICS_SYSTEM


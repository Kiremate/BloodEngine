#ifndef PHYSICS_SYSTEM
#define PHYSICS_SYSTEM
#include "System.h"
#include <vector>
#include "Physics_Component.h"

namespace blood_engine {

	class Physics_System : System {


	public:
		virtual SystemType GetType() const { return SystemType::PHYSICS; }
		bool CreatePhysicsComponent();
	private:

		// World

		// Components
		std::vector<Physics_Component> physics_components;


	};
}
#endif // !PHYSICS_SYSTEM


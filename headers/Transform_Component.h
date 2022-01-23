#ifndef TRANSFORM_COMPONENT
#define TRANSFORM_COMPONENT

#include "Component.h"
#include "glm/vec3.hpp"

using namespace glm;
// vec3 is aids to my eyes
typedef vec3 Vector3;

namespace blood_engine {
	class Transform_Component : Component {
	public:


	private:

		Vector3 Position;
		Vector3 Rotation;
		Vector3 Scale;


	};
}
#endif // !TRANSFORM_COMPONENT

/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#ifndef TRANSFORM_COMPONENT
#define TRANSFORM_COMPONENT

#include "Component.h"
#include "glm/vec3.hpp"

using namespace glm;
typedef vec3 Vector3;

namespace blood_engine {

	class Transform_Component : public Component {
	public:

		// Constructors
		Transform_Component() = default;
		~Transform_Component() = default;
		Transform_Component(const Transform_Component& other);
		
		// Clone function
		std::unique_ptr<Component> Clone() const override;
		// Getters n' Setters
		inline Vector3 GetPosition() const { return Position; }
		inline void SetPosition(const Vector3& newPosition) { Position = newPosition; }
		
		inline Vector3 GetRotation() const { return Rotation; }
		inline void SetRotation(const Vector3& newRotation) { Rotation = newRotation; }
		
		inline Vector3 GetScale() const { return Scale; }
		inline void SetScale(const Vector3& newScale) { Scale = newScale; }

	private:

		Vector3 Position;
		Vector3 Rotation;
		Vector3 Scale;


	};
}
#endif // !TRANSFORM_COMPONENT

/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#ifndef SYSTEM_H
#define SYSTEM_H

#include "Component.h"
#include "Task.h"

class Scene;

namespace blood_engine {
	enum SystemType{RENDER, PHYSICS, AUDIO, INPUT};

	class System : Task {

	public:
		virtual SystemType GetType() const = 0;
		Component CreateComponent();
		System() = default;
		virtual ~System() = default;
		virtual void Update() = 0;
	private:
		Scene* scene;
		SystemType type;
	};
}
#endif // !SYSTEM_H

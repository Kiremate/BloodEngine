#ifndef SYSTEM_H
#define SYSTEM_H

#include "Component.h"
#include "Task.h"

class Scene;

namespace blood_engine {
	enum SystemType{RENDER, PHYSICS, AUDIO};

	class System : Task {

	public:
		virtual SystemType GetType() const = 0;
		Component CreateComponent();
		System() = default;
		virtual void Update() = 0;
		virtual ~System();
	private:
		Scene* scene;
		SystemType type;
	};
}
#endif // !SYSTEM_H

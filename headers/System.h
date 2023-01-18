#ifndef SYSTEM_H
#define SYSTEM_H

#include "Component.h"
#include "Task.h"

class Scene;

namespace blood_engine {
	class System : Task {

	public:
		Component CreateComponent();
		System() = default;
		virtual void Update() = 0;
		virtual ~System();
	private:
		Scene* scene;

	};
}
#endif // !SYSTEM_H

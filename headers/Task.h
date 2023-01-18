#ifndef TASK_H
#define TASK_H

#include <functional>

namespace blood_engine {

	enum Task_Status {
		WAITING,
		RUNNING,
		FINISHED
	};
	enum Task_Priority {
		HIGH,
		MEDIUM,
		LOW
	};
	
	//template <typename SIGNATURE_FUNC>
	class Task {

	public:
		// Update method
		virtual void Update() = 0;
		size_t ID;
		bool consumable;
		Task() = default;
		virtual ~Task() = default;
		Task_Status status;
		Task_Priority priority;
	};
}
#endif // !TASK_H

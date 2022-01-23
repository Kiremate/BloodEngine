#ifndef TASK_H
#define TASK_H

#include <functional>

namespace blood_engine {

	//template <typename SIGNATURE_FUNC>
	class Task {

	public:

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

		size_t ID;
		bool consumable;

		Task() = default;
		virtual ~Task();

		std::function<void()> run;

		Task_Status status;
		Task_Priority priority;
	};
}
#endif // !TASK_H

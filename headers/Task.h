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

		Task() {

		}

		Task_Status status;
		std::function<void()> func;


	};
}
#endif // !TASK_H

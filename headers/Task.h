#pragma once
#ifndef TASK_H
#define TASK_H

#include "thread_pool.hpp"
#include <functional>
namespace blood_engine {

	template <typename T>
	class Task {

	public:

		enum Task_Status {
			WAITING,
			RUNNING,
			FINISHED
		};

		Task_Status status;
		std::function<T> run;


	};
}
#endif // !TASK_H

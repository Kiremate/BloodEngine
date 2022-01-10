#pragma once
#ifndef TASK_H
#define TASK_H

#include "thread_pool.hpp"
#include <functional>
namespace blood_engine {


	class Task {

	public:
		std::function<int> run;


	};
}
#endif // !TASK_H

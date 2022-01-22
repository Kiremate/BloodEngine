#ifndef SCENE_H
#define SCENE_H
#include <SDL_gesture.h>
#include <vector>
#include "Task.h"
#include "thread_pool.hpp"

namespace blood_engine {

	class Scene {

	public:
		Scene() {
			for (auto &task : task_list) {
				future_list.push_back(task_pool.submit(task.func));
			}
		}
	private:

		SDL_Window* mainWindow;
		// Contains task list to check priority and otherf
		std::vector<Task> task_list;
		// it just contains all func references
		thread_pool task_pool;
		std::future<bool> f;
		
		std::vector<std::future<bool >> future_list;
		std::function<int()> GetOneRef = GetOne;
	};

	int GetOne() {
		return 1;
	}
}
#endif // !SCENE_H

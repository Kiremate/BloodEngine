#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include "Kernel.h"
#include "Task.h"
#include "declarations.h"
#include "System.h"
#include "Entity.h"

namespace blood_engine {

	class Scene {

	public:
		Scene() {

		}
		Scene(SDL_Window& given_window) {
		/*for (auto &task : task_list) {
				future_list.push_back(task_pool.submit(task.run));
			}*/
		}

		// Loads the Scene from a Json file - returns false if couldn't create scene, returns true otherwise
		bool LoadSceneFromJson(const char* str, size_t length);
		// Loads the Scene with default values - returns false if couldn't create scene, returns true otherwise
		bool LoadScene();
	private:
		SDL_Window* mainWindow;
		// Contains task list to check priority and otherf
		std::vector<Task> task_list;
		// Contains all systems
		// Kernel, executes tasks and systems
		Kernel kernel;
		std::vector <System> system_list;
		std::vector <Entity> entity_list;
		// it just contains all func references
		thread_pool task_pool;
		std::future<bool> f;
		std::vector<std::future<bool >> future_list;
	};

}
#endif // !SCENE_H

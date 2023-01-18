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
		typedef std::uint_fast32_t ui32;
	public:
		Scene() {
			std::cout << "Hello World" << std::endl;
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
		template<typename T>
		void UpdateSystem(std::unique_ptr<T> system);
		template<typename T>
		void AddSystem(std::unique_ptr<T> system);
		void Render();
		void Update();

		std::vector <std::unique_ptr<System>> system_list;
	private:
		// Main Window
		SDL_Window* mainWindow;
		// Opengl Context
		SDL_GLContext gl_context;

		////////////////////
		ui32 get_WindowScene_width() const;
		ui32 get_WindowScene_height() const;
		/////////////////////
		
		void activate_vsync();
		void deactivate_vsync();

		void clear_WindowScene() const;

		// Contains task list to check priority and otherf
		std::vector<Task> task_list;
		// Contains all systems
		// Kernel, executes tasks and systems
		Kernel kernel;
		
		// it just contains all func references
		/*thread_pool task_pool;
		std::future<bool> f;
		std::vector<std::future<bool >> future_list;*/
		std::vector <Entity> entity_list;
	};

}
#endif // !SCENE_H

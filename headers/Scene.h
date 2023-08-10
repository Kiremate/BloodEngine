/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#ifndef SCENE_H
#define SCENE_H
#include <vector>
#include "Task.h"
#include "declarations.h"
#include "System.h"
#include "Entity.h"
#include <iostream>

namespace blood_engine {
	class Kernel;
	class Scene {
		typedef std::uint_fast32_t ui32;
	public:
		Scene() = default;
		Scene(SDL_Window* window, SDL_GLContext* gl_context);
		~Scene() = default;

		// Loads the Scene from a Json file - returns false if couldn't create scene, returns true otherwise
		bool LoadSceneFromJson(const char* str, size_t length);
		// Loads the Scene with default values - returns false if couldn't create scene, returns true otherwise
		bool LoadScene();
		// Update
		template <typename T> 
		void UpdateSystem(std::shared_ptr<T> system);
		// Adds a new system to the scene
		template <typename T>
		void AddSystem(std::shared_ptr<T> system);
		// Removes a new system to the scene
		template <typename T>
		void RemoveSystem(std::shared_ptr<T> system);
		std::vector<std::shared_ptr<System>> system_list;
		void StopScene();
		void Clear_WindowScene() const;
		void SwapWindowBuffers() const;
	private:
		// Main Window
		SDL_Window* mainWindow;
		// Opengl Context
		SDL_GLContext* gl_context;

		////////////////////
		ui32 get_WindowScene_width() const;
		ui32 get_WindowScene_height() const;
		/////////////////////
		
		void activate_vsync();
		void deactivate_vsync();

		// Contains task list to check priority and other
		std::vector<Task> task_list;
		
		// Kernel, executes tasks and systems
		Kernel* kernel;
	
		std::vector <Entity> entity_list;
	};

}
#endif // !SCENE_H

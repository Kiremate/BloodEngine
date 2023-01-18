#include "..\headers\Scene.h"
#include "rapidjson/reader.h"
#include <iostream>
#include "..\headers\types.h"
#include "../headers/Render_System.h"
#include "SDL.h"
bool blood_engine::Scene::LoadSceneFromJson(const char* str, size_t length)
{
	return false;
}

bool blood_engine::Scene::LoadScene()
{
	return false;
}

template<typename T>
void blood_engine::Scene::UpdateSystem(std::unique_ptr<T> system)
{
    for (auto& existing_system : system_list) {
        T* existing_system_as_T = dynamic_cast<T*>(existing_system.get());
        if (existing_system_as_T) {
            existing_system = std::move(system);
            return;
        }
    }
    throw std::runtime_error("System of type " + std::string(typeid(T).name()) + " not found in scene.");
}

template<typename T>
void blood_engine::Scene::AddSystem(std::unique_ptr<T> system)
{
    system_list.push_back(std::move(system));
}

template<typename T>
void blood_engine::Scene::RemoveSystem(std::unique_ptr<T> system)
{
    for (auto it = system_list.begin(); it != system_list.end(); ++it) {
        if (T* cast_existing_system = dynamic_cast<T*>((*it).get())) {
            if (cast_existing_system->GetType() == system->GetType()) {
                system_list.erase(it);
                return;
            }
        }
    }
}

blood_engine::ui32 blood_engine::Scene::get_WindowScene_width() const
{
	return ui32();
}

#include "..\headers\Scene.h"
#include "rapidjson/reader.h"
#include <iostream>
#include "..\headers\types.h"
#include "../headers/Render_System.h"
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
}
template<typename T>
void blood_engine::Scene::AddSystem(std::unique_ptr<T> system)
{
	system_list.push_back(std::move(std::unique_ptr<System>(std::move(system))))
}

blood_engine::ui32 blood_engine::Scene::get_WindowScene_width() const
{
	return ui32();
}

void blood_engine::Scene::Update() {

}
void blood_engine::Scene::Render() {
	for (auto& system : system_list) {
		auto render_system = dynamic_cast<blood_engine::Render_System*>(system.get());
		assert(render_system != nullptr && "Render System not found in the system list.");
		render_system->Render();
	}
}
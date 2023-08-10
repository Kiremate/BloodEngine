#include "../headers/Scene.h"
#include "rapidjson/reader.h"
#include "rapidjson/document.h"
#include <iostream>
#include "../headers/types.h"
#include "../headers/Render_System.h"
#include "../headers/Physics_System.h"
#include "../headers/Audio_System.h"
#include "../headers/Input_System.h"
#include "../headers/Kernel.h"
#include "SDL.h"


template void blood_engine::Scene::AddSystem<blood_engine::Render_System>(std::shared_ptr<blood_engine::Render_System>);
template void blood_engine::Scene::AddSystem<blood_engine::Physics_System>(std::shared_ptr<blood_engine::Physics_System>);
template void blood_engine::Scene::AddSystem<blood_engine::Audio_System>(std::shared_ptr<blood_engine::Audio_System>);
template void blood_engine::Scene::AddSystem<blood_engine::Input_System>(std::shared_ptr<blood_engine::Input_System>);

blood_engine::Scene::Scene(SDL_Window* window, SDL_GLContext* gl_context) :
    mainWindow(window), gl_context(gl_context)
{

}
bool blood_engine::Scene::LoadSceneFromJson(const char* str, size_t length)
{
    // Parse the JSON string
    rapidjson::Document doc;
    doc.Parse(str, length);

    // Check for parse errors
    if (doc.HasParseError()) {
        std::cout << "Error parsing JSON: " << doc.GetParseError() << std::endl;
        return false;
    }

    #pragma region Parse_Systems
        if (doc.HasMember("systems")) {
            const rapidjson::Value& systems = doc["systems"];
            for (rapidjson::SizeType i = 0; i < systems.Size(); i++) {
                const rapidjson::Value& system = systems[i];
                std::string type = system["type"].GetString();
                if (type == "Render") {
                    // Create and add a Render_System
                    auto render_system = std::make_shared<Render_System>();
                    AddSystem(render_system);
                }
                else if (type == "Physics") {
                    // Create and add a Physics_System
                    auto physics_system = std::make_shared<Physics_System>();
                    AddSystem(physics_system);
                }
                else if (type == "Audio") {
                    // Create and add a Audio_System
                    auto audio_system = std::make_shared<Audio_System>();
                    AddSystem(audio_system);
                }
                else if (type == "Input") {
                    // Create abd add a Input_System
                    auto input_system = std::make_shared<Input_System>();
                    AddSystem(input_system);
                }
            }
        }
    #pragma endregion Parse_Systems
    
    #pragma region Parse_Entities
        if (doc.HasMember("entities")) {
            const rapidjson::Value& entities = doc["entities"];
            for (rapidjson::SizeType i = 0; i < entities.Size(); i++) {
                const rapidjson::Value& entity = entities[i];
                std::string name = entity["name"].GetString();
                auto new_entity = std::make_shared<Entity>(name);

                if (entity.HasMember("components")) {
                    const rapidjson::Value& components = entity["components"];
                    for (rapidjson::SizeType j = 0; j < components.Size(); j++) {
                        const rapidjson::Value& component = components[j];
                        std::string type = component["type"].GetString();
                        if (type == "Transform") {
                            // Create and add a Transform_Component
                            auto transform_component = std::make_shared<Transform_Component>();
                            new_entity->AddComponent(transform_component);
                        }
                        else if (type == "Renderable") {
                            // Create and add a Renderable_Component
                            auto renderable_component = std::make_shared<Renderable_Component>();
                            new_entity->AddComponent(renderable_component);
                        }
                    }
                }
            }
        }
    #pragma endregion Parse_Entities

    return true;
}

bool blood_engine::Scene::LoadScene()
{
	return false;
}

template<typename T>
void blood_engine::Scene::UpdateSystem(std::shared_ptr<T> system)
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
void blood_engine::Scene::AddSystem(std::shared_ptr<T> system)
{
    static_assert(std::is_base_of<System, T>::value, "T must derive from System");
    system_list.push_back(std::static_pointer_cast<System>(system));
}

template<typename T>
void blood_engine::Scene::RemoveSystem(std::shared_ptr<T> system)
{
    for (auto it = system_list.begin(); it != system_list.end(); ++it) {
        if (T* cast_existing_system = it->get()) {
            if (cast_existing_system->GetType() == system->GetType()) {
                system_list.erase(it);
                return;
            }
        }
    }
}

void blood_engine::Scene::StopScene()
{
    kernel->Stop();
}

void blood_engine::Scene::Clear_WindowScene() const
{
    if (gl_context) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void blood_engine::Scene::SwapWindowBuffers() const
{
    if (gl_context) SDL_GL_SwapWindow(mainWindow);
}

blood_engine::ui32 blood_engine::Scene::get_WindowScene_width() const
{
	return ui32();
}

blood_engine::ui32 blood_engine::Scene::get_WindowScene_height() const
{
    return ui32();
}

void blood_engine::Scene::activate_vsync()
{
}

void blood_engine::Scene::deactivate_vsync()
{
}

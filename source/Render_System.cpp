#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <ciso646>

#include <SDL.h>
#include "Camera.hpp"
#include "Cube.hpp"
#include <Model.hpp>

#include "../headers/Renderable_Component.h"
#include "../headers/Render_System.h"


blood_engine::Render_System::Render_System()
{
    this->width = 1920;
    this->height = 1080;

    renderer.reset(new Render_Node);
    if (!renderer) {
        std::cerr << "Failed to create Render_Node" << std::endl;
        return;
    }
    // Initializated
    camera = std::make_shared<glt::Camera>();
    light = std::make_shared<glt::Light>();

    renderer->add("camera", camera);
    renderer->add("light", light);
    

    // Transform Properties
    renderer->get("camera")->translate(Vector3(0.f, 0.f, 5.f));
    renderer->get("light")->translate(Vector3(10.f, 10.f, 10.f));
}

blood_engine::Render_System::Render_System(int width, int height)
{
    renderer.reset(new Render_Node);

    this->width = width;
    this->height = height;
    renderer.reset(new Render_Node);
	// Initializated
    camera = std::make_shared<glt::Camera>(20.f, 1.f, 50.f, (float(width) / height));
	light = std::make_shared<glt::Light>();

    renderer->add("camera", camera);
    renderer->add("light", light);

    // Transform Properties
    renderer->get("camera")->translate(Vector3(0.f, 0.f, 5.f));
    renderer->get("light")->translate(Vector3(10.f, 10.f, 10.f));
}

bool blood_engine::Render_System::CreateRenderComponent(std::string name, std::shared_ptr<Model> model)
{
	auto render_component = std::make_unique<Renderable_Component>(name, model);
    if (render_component == nullptr) {
        std::cerr << "Failed to create render component" << std::endl;
        return false;
    }
	// Add the render component to the vector

    render_components.push_back(std::move(render_component));
    auto& render_component_ref = render_components.back();
    renderer->add(render_component_ref->GetName(), render_component_ref->GetModel());

	return true;
}

void blood_engine::Render_System::Render()
{
    if (scene) {
        scene->Clear_WindowScene();
        renderer->get_active_camera()->set_aspect_ratio((float(width) / height));
        glViewport(0, 0, width, height);
        renderer->render();
        scene->SwapWindowBuffers();
    }
}

void blood_engine::Render_System::Update()
{
	// Render the scene
	Render();
}

void blood_engine::Render_System::SetScene(std::shared_ptr<Scene> scene)
{
    this->scene = scene;
}

void blood_engine::Render_System::SetResolution(int width, int height)
{
    this->width = width;
    this->height = height;
}

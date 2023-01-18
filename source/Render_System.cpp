#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <Render_Node.hpp>
#include "../headers/Renderable_Component.h"
#include <SDL.h>
#include <ciso646>
#include "../headers/Render_System.h"

blood_engine::Render_System::Render_System(int width, int height)
{
    this->width = width;
    this->height = height;
}

bool blood_engine::Render_System::CreateRenderComponent()
{
	auto render_component = std::make_unique<Renderable_Component>();
    if (render_component != nullptr) {
        std::cerr << "Failed to create render component" << std::endl;
        return false;
    }
	// Add the render component to the vector
	render_components.push_back(std::move(render_component));
	return true;
}

void blood_engine::Render_System::Render()
{
    renderer->get_active_camera()->set_aspect_ratio(float(width) / height);
    glViewport(0, 0, width, height);
    renderer->render();
}

void blood_engine::Render_System::Update()
{
	// Render the scene
	Render();
}

void blood_engine::Render_System::SetResolution(int width, int height)
{
    this->width = width;
    this->height = height;
}

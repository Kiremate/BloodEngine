/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM

#include "System.h" 
#include "declarations.h"
#include "Renderable_Component.h"
#include <Render_Node.hpp>
#include <Light.hpp>
#include "Scene.h"
// Forward declarations
//class Renderable_Component;
class Camera;
class Light;
namespace blood_engine {
	class Render_System : public System {
	public:
		Render_System();
		Render_System(int width, int height);
		~Render_System() override = default;
		bool CreateRenderComponent(std::string namename, std::shared_ptr<Model> model);
		// Metodos de Task.h
		void Render();
		void Update() override;
		void SetScene(std::shared_ptr<Scene> scene);
		void SetResolution(int width, int height);
		virtual SystemType GetType() const { return SystemType::RENDER; }
	private:
		// Renderer
		std::unique_ptr<glt::Render_Node> renderer;
		std::shared_ptr<glt::Camera> camera;
		std::shared_ptr<glt::Light> light;
		// Scene reference
		std::shared_ptr<Scene> scene;
		// lista de Render Comps
		std::vector<std::unique_ptr<Renderable_Component>> render_components;
		// OpenGL glad window sizes
		int width;
		int height;
	};
}
#endif // !RENDER_SYSTEM


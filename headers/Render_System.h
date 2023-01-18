#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM

#include "System.h" 
#include "declarations.h"
// Forward declarations
class Renderable_Component;

namespace blood_engine {
	class Render_System : System {
	public:
		Render_System() = default;
		Render_System(int width, int height);
		virtual ~Render_System() = default;
		bool CreateRenderComponent();
		// Metodos de Task.h
		void Render();
		void Update() override;
		void SetResolution(int width, int height);
		virtual SystemType GetType() const { return SystemType::RENDER; }
	private:
		// Renderer
		std::unique_ptr< glt::Render_Node > renderer;
		// lista de Render Comps
		std::vector<std::unique_ptr<Renderable_Component>> render_components;
		// OpenGL glad window sizes
		int width;
		int height;
	};
}
#endif // !RENDER_SYSTEM


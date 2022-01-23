#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM
#include "System.h" 
#include <vector>
#include "declarations.h"
#include <memory>
#include <string>
#include "Renderable_Component.h"

namespace blood_engine {
	class Render_System : System {


	public:
		bool CreateRenderComponent();
		// Metodos de Task.h
		void Render();
	private:
		// Renderer
		std::unique_ptr< glt::Render_Node > renderer;

		// lista de Render Comps
		std::vector<Renderable_Component> render_components;

	};
}
#endif // !RENDER_SYSTEM


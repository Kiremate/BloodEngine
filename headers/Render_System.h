#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM
#include "System.h" 
#include <vector>
#include "Renderable_Component.h"
namespace blood_engine {
	class Render_System : System {


	public:
		bool CreateRenderComponent();
		// Metodos de Task.h
		void Render();
	private:

		// TODO Create Render.h

		// lista de Render Comps
		std::vector<Renderable_Component> render_components;

	};
}
#endif // !RENDER_SYSTEM


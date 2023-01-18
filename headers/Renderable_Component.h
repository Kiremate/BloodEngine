#ifndef RENDERABLE_COMPONENT_H
#define RENDERABLE_COMPONENT_H

#include "Model.hpp"
#include "Component.h"

using namespace glt;
namespace blood_engine {

	class Renderable_Component : Component {

	public:
		 std::unique_ptr<Component> Clone() const override;
		
	private:

	// Model that combines mesh and material
	std::shared_ptr<Model> model;

	};
}
#endif // !RENDERABLE_COMPONENT_H

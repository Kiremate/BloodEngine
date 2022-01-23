#ifndef RENDERABLE_COMPONENT_H
#define RENDERABLE_COMPONENT_H

#include "Component.h"
#include "Model.hpp"
using namespace glt;

namespace blood_engine {

	class Renderable_Component : Component {

	public:



	private:

	// Modelo que combina malla y material
	std::shared_ptr<Model> model;

	};
}
#endif // !RENDERABLE_COMPONENT_H

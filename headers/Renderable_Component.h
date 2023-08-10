/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#ifndef RENDERABLE_COMPONENT_H
#define RENDERABLE_COMPONENT_H

#include "Model.hpp"
#include "Component.h"

using namespace glt;
namespace blood_engine {

	class Renderable_Component : public Component {

	public:
		Renderable_Component() = default;
		~Renderable_Component() = default;
		Renderable_Component(std::string name, std::shared_ptr<Model> model);
		std::unique_ptr<Component> Clone() const override;
		std::string GetName();
		std::shared_ptr<Model> GetModel();
	private:

	// Model that combines mesh and material
	std::shared_ptr<Model> model;
	std::string name;
	};
}
#endif // !RENDERABLE_COMPONENT_H

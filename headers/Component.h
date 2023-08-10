/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#include <memory>
#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

namespace blood_engine {
	class Component {
	public:
		Component();
		Component(Entity* owner);
		Component(const Component& other);
		virtual ~Component() = default;
		virtual std::unique_ptr<Component> Clone() const = 0;

	private:
		Entity* owner;
	};
}
#endif // !COMPONENT_H

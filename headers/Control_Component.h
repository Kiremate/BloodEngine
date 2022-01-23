#ifndef CONTROL_COMPONENT
#define CONTROL_COMPONENT

#include "Component.h"
#include <functional>

namespace blood_engine {
	class Control_Component : Component
	{
	public: 

		/*	template <typename CallbackFunction>
		void myFunction(..., CallbackFunction&& callback) {
			
				callback(...);
			
		}*/
	private:
	
		std::function<void>* control_func;
	
	};
}
#endif // !CONTROL_COMPONENT

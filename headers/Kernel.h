#ifndef KERNEL_H
#define KERNEL_H

#include "thread_pool.hpp"
#include <vector>
#include "System.h"
namespace blood_engine {
	class Kernel {
	public:
		Kernel();
		virtual ~Kernel();
		// Initializes the kernel and the systems
		virtual bool Initialize();
		// Runs the kernel and the systems
		virtual void Run(Scene* scene);
		// Stops the kernel and the systems
		virtual void Stop();
		// Adds a new system to the kernel
		virtual void AddSystem(std::unique_ptr<System> system);
		
	private:
		thread_pool task_pool;
		std::vector<std::unique_ptr<System>> system_list;
	};

}
#endif // !KERNEL_H

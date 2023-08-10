/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#ifndef KERNEL_H
#define KERNEL_H

#include "thread_pool.hpp"
#include <vector>
#include "System.h"

namespace blood_engine {
    class Scene;
    class Kernel {
    private:
        bool running;
        thread_pool task_pool;
        std::vector<std::unique_ptr<System>> system_list;
    public:
        Kernel();
        virtual ~Kernel();
        // Initializes the kernel and the systems
        virtual bool Initialize();
        // Runs the kernel and the systems
        void Run(Scene* scene);
        // Stops the kernel and the systems
        virtual void Stop();
        
    };
}
#endif // !KERNEL_H
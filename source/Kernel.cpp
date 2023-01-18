#include "../headers/Kernel.h"
#include "../headers/Scene.h"
#include "../headers/Render_System.h"
#include "../headers/Physics_System.h"
#include "../headers/Audio_System.h"

blood_engine::Kernel::Kernel()
{
}

void blood_engine::Kernel::Run(Scene* scene)
{
    //Create thread pool
    thread_pool task_pool;
	
    std::vector<std::future<bool>> future_list;

    // Add systems update tasks to the thread pool
    for (auto& system : scene->system_list) {
        std::function<void()> task_update = std::bind(&System::Update, system);
        future_list.push_back(task_pool.submit(task_update));

    
        // Main game loop
        while (true) {
            // Wait for all update tasks to complete
            for (auto& future : future_list) {
                future.wait();
            }

            // Render the scene
            scene->Render();

            // Add new update tasks for next iteration
            future_list.clear();
            for (auto& system : scene->system_list) {
                std::function<void()> update_task = std::bind(&System::Update, system);
                future_list.push_back(task_pool.submit(update_task));
            }

            // Sleep for a bit to prevent high CPU usage
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
        }
    }
}









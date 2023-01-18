#include "../headers/Kernel.h"
#include "../headers/Scene.h"
#include "../headers/Render_System.h"
#include "../headers/Physics_System.h"
#include "../headers/Audio_System.h"

blood_engine::Kernel::Kernel()
{
}

blood_engine::Kernel::~Kernel()
{
}

bool blood_engine::Kernel::Initialize()
{
    return false;
}

void blood_engine::Kernel::Run(Scene* scene)
{
    this->running = true;
    std::vector<std::future<bool>> future_list;

    while (this->running) {
        // Add systems update tasks to the thread pool
        future_list.clear();
        for (auto& system : scene->system_list) {
            if (system->GetType() != SystemType::RENDER)
            {
                std::function<void()> task_update = std::bind(&System::Update, system.get());
                future_list.push_back(task_pool.submit(task_update));
            }
        }
        // Wait for all update tasks to complete
        for (auto& future : future_list) {
            future.wait();
        }

        // Render the scene
        auto render_system = std::find_if(scene->system_list.begin(), scene->system_list.end(),
            [](const auto& system) { return system->GetType() == SystemType::RENDER; });
        if (render_system != scene->system_list.end())
            (*render_system)->Update();
    }
    // Sleep for a bit to prevent high CPU usage
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
}

void blood_engine::Kernel::Stop()
{
    running = false;
}


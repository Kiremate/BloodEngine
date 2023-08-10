#include "../headers/Input_System.h"
blood_engine::Input_System::Input_System() {
    // Initialize input settings
}

void blood_engine::Input_System::SetScene(std::shared_ptr<Scene> scene)
{
    this->scene = scene;
}

void blood_engine::Input_System::Init() {
    std::cout << "Initializing Input System" << std::endl;
}

void blood_engine::Input_System::Update() {
    HandleInputEvents();
}

void blood_engine::Input_System::Shutdown() {
    std::cout << "Shutting down Input System" << std::endl;
}

void blood_engine::Input_System::HandleInputEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            // Handle quit event
            break;
        case SDL_KEYDOWN:
            // Handle key down event
            // Finish the program
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                scene->StopScene();
            }
            break;
        case SDL_KEYUP:
            // Handle key up event
            break;
        case SDL_MOUSEBUTTONDOWN:
            // Handle mouse button down event
            break;
        case SDL_MOUSEBUTTONUP:
            // Handle mouse button up event
            break;
        case SDL_MOUSEMOTION:
            // Handle mouse motion event
            break;
        default:
            break;
        }
    }
}
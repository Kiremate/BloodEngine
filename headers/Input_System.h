/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#pragma once
#include "System.h"
#include "SDL.h"
#include <iostream>
#include "Scene.h"

namespace blood_engine {

    class Input_System : public System {
    public:
        Input_System();
        inline virtual ~Input_System() override {
            //SDL_Quit();
        }

        virtual SystemType GetType() const { return SystemType::INPUT; }
        void SetScene(std::shared_ptr<Scene> scene);
        void Init();
        void Update() override;
        void Shutdown();

    private:
        // Scene reference
        std::shared_ptr<Scene> scene;
        // Handle input events, such as keyboard and mouse
        void HandleInputEvents();
    };
}

/**
 * @author Bloodmask
 * @copyright Copyright (c) 2023, Bloodmask
 * @license All rights reserved
 */
#pragma once
#include "System.h"
#include "SDL.h"
#include <iostream>
//#include <SDL_mixer.h>
namespace blood_engine {
	
    class Audio_System : public System {
    public:
        Audio_System();
        inline virtual ~Audio_System() override {
            //SDL_Quit();
        }

        virtual SystemType GetType() const { return SystemType::AUDIO; }
        // Initialize audio settings, such as sample rate, channels, etc.
        // Open audio device
        // Load audio files
        void Init();
        // Play, pause, stop audio
        // Update audio settings, such as volume, pitch, etc.
        void Update() override;
        // Close audio device
        // Unload audio files
        void Shutdown();
    };
}
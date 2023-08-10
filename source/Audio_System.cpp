#include "../headers/Audio_System.h"

blood_engine::Audio_System::Audio_System()
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "Error initializing SDL_audio: " << SDL_GetError() << std::endl;
    }
}

//blood_engine::Audio_System::~Audio_System() 
//{
//    SDL_Quit();
//}

void blood_engine::Audio_System::Init()
{
	// Initialize audio settings, open audio device, load audio files
	std::cout << "Initializing Audio System" << std::endl;
	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		std::cerr << "Error initializing SDL audio: " << SDL_GetError() << std::endl;
		return;
	}
	//Mix_Music* music = Mix_LoadMUS("path/to/music.ogg");
	//Mix_Chunk* soundEffect = Mix_LoadWAV("path/to/soundEffect.wav");
	
}

void blood_engine::Audio_System::Update()
{
	//Mix_PlayMusic(music, -1); // -1 means the music will loop indefinitely
	//Mix_PlayChannel(-1, soundEffect, 0); // -1 means the sound effect will play on the next available channel
	//Mix_PauseMusic();
}

void blood_engine::Audio_System::Shutdown() {
	// Close audio device, unload audio files
	std::cout << "Shutting down Audio System" << std::endl;
}
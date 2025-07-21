#include "music.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>

static Mix_Music* currentMusic = nullptr;

void initMusic() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL Init error: " << SDL_GetError() << std::endl;
        return;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer Init error: " << Mix_GetError() << std::endl;
    }
}

void playMusic(const std::string& filename, int loops) {
    // 如果当前有音乐在播放，则先淡出并等待
    if (Mix_PlayingMusic()) {
        Mix_FadeOutMusic(1000);  // 1秒淡出
        SDL_Delay(1000);         // 等待淡出完成
    }

    // 释放旧音乐资源
    if (currentMusic != nullptr) {
        Mix_FreeMusic(currentMusic);
        currentMusic = nullptr;
    }

    // 加载新音乐
    currentMusic = Mix_LoadMUS(filename.c_str());
    if (!currentMusic) {
        std::cerr << "Failed to load " << filename << ": " << Mix_GetError() << std::endl;
        return;
    }

    // 淡入播放（1秒）
    if (Mix_FadeInMusic(currentMusic, loops, 1000) == -1) {
        std::cerr << "Failed to fade in music: " << Mix_GetError() << std::endl;
    }
}

void stopMusic(int fade_ms) {
    Mix_FadeOutMusic(fade_ms);
}

void closeMusic() {
    Mix_CloseAudio();
    SDL_Quit();
}
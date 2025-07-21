#pragma once
#include <string>

void initMusic();
void playMusic(const std::string& filename, int loops = -1);
void stopMusic(int fade_ms = 1000);
void closeMusic();
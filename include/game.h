#pragma once
#include <iostream>
#include <vector>
#include "Hero_and_Monster.h"
using namespace std;


const std::string RED     = "\033[31m";
const std::string GREEN   = "\033[32m";
const std::string YELLOW  = "\033[33m";
const std::string GOLD  = "\033[1;33m";
const std::string BLUE    = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN    = "\033[36m";
const std::string DARK_RED = "\033[38;5;88m";
const std::string FIRE     = "\033[38;5;202m";
const std::string RESET   = "\033[0m";
const std::string CLEAR    = "\033[2J\033[H"; 



extern int count_easy;
extern int count_medium;
extern int count_hard;
extern int count_challenge;

class Game {
public: 
    void init(Game* game);
    void menu1(Game* game);
    void menu2(Hero* hero);
    void start();
    void load(){cout<<"Game Load"<<endl;};
    void save();
};

class SceneColorConfig {
private:
    std::vector<int> redLines;
    std::vector<int> yellowLines;

public:
    SceneColorConfig(const std::vector<int>& redLines, const std::vector<int>& yellowLines)
        : redLines(redLines), yellowLines(yellowLines) {}

    const std::vector<int>& getRedLines() const { return redLines; }
    const std::vector<int>& getYellowLines() const { return yellowLines; }
};



void printWithDelay(const std::string& text, int delayMs = 50, const std::string& color = RESET);
void printLineByLine(const std::vector<std::string>& lines, int delayMs, const SceneColorConfig& config);

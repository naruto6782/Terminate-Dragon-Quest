#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <vector>
#include "Hero_and_Monster.h"
using namespace std;
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

//test github
#endif
//SceneColorConfig haha({1,2,4},{5,7},{3,6})
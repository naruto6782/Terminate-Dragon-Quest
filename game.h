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
    std::vector<int> rdLines;  // 假设这是红色龙的行，名称可能需要更正
    std::vector<int> blLines; // 假设这是蓝色的部分，名称可能需要更正

public:
    // 构造函数，初始化所有行
    SceneColorConfig() : 
        redLines{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27},
        yellowLines{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13},
        rdLines{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28},
        blLines{} 
    {}
};
//test github
#endif
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "maze.h"
#include "battle.h"
#include "Hero_and_Monster.h"
extern Equipment silver_spear,defense_shield,brave_amulet;
int easy_maze[round][event] = {
    {0, 1, 3, 1, 1, 4, 1, 5},
    {0, 1, 2, 3, 1, 1, 1, 5},
    {0, 1, 1, 1, 4, 3, 2, 5},
    {0, 1, 2, 1, 1, 3, 1, 5},
    {0, 1, 1, 3, 1, 2, 1, 5},
    {0, 1, 1, 1, 2, 1, 3, 5}
};

int middle_maze[round][event] = {
    {1, 2, 3, 1, 1, 1, 5},
    {1, 1, 2, 1, 3, 1, 5},
    {1, 1, 1, 2, 3, 1, 5},
    {2, 3, 1, 4, 1, 1, 5},
    {1, 1, 3, 2, 4, 1, 5},
    {2, 2, 1, 3, 1, 1, 5}
};

int difficult_maze[round][event] = {
    {1, 2, 1, 3, 1, 4, 5},
    {2, 4, 3, 1, 1, 1, 5},
    {1, 1, 4, 2, 1, 3, 5},
    {2, 1, 1, 1, 3, 4, 5},
    {1, 1, 1, 4, 2, 3, 5},
    {1, 2, 1, 3, 4, 1, 5}
};

int* select_random_maze(int maze[][event]) {
    int r = rand() % round;
    return maze[r];
}

void easy(Hero* hero) {
    srand(time(0)); // 初始化随机数种子

    int* current_maze = select_random_maze(easy_maze);
    int difficulty = current_maze[0];

    std::cout << "当前难度:简单"<< "\n事件路径: ";
    unsigned int HP = hero->get_HP();
    for (int i = 1; i < event; i++) {
    int e = current_maze[i];
    if (e == 1) {
        std::cout << "遭遇怪物！按Enter开始战斗...\n";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        // rest();
        Medicine medicine("血瓶", 1, 100);
        Poison poison("毒瓶", 1, 100);
        hero->equip(&silver_spear);
        hero->equip(&defense_shield);
        hero->equip(&brave_amulet);
        Monster monster("zengtou", 100,10,1,10,10,10);
        backpack *bag=hero->get_backpack();
        bag->add_item(&medicine);
        Battle battle(hero,&monster);
        battle.Battle_round(HP);  // 调用战斗函数
        cout <<"🎊 按Enter前往下一关卡...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
    } else if (e == 2) {
        std::cout << "商店\n";
        cout <<"🎊 按Enter前往下一关卡...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        // shop();
    } else if (e == 3) {
        std::cout << "到达篝火，回复20生命值！\n";
        hero->set_max_HP(HP);
        hero->change_HP(20,1.0,hero->get_max_HP());
        hero->set_max_HP(1000000);
        cout <<"🎊 按Enter前往下一关卡...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        // rest();
    } else if (e == 4) {
        std::cout << "遇到陷阱\n";
        cout <<"🎊 按Enter前往下一关卡...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        // trap();
    } else if (e == 5) {
        std::cout << "你找到了宝箱\n";
        // open_chest();
    }
    }
    hero->set_max_HP(HP);
    hero->reborn(1.0);
    hero->set_max_HP(1000000);
    cout <<"🎊 按Enter返回主界面...";
    getchar(); // 等待用户按任意键
    system("cls"); // 清屏

}

void middle() {
    srand(time(0)); // 初始化随机数种子

    int* current_maze = select_random_maze(middle_maze);
    int difficulty = current_maze[0];

    std::cout << "当前难度:中等"<< "\n事件路径: ";
    for (int i = 1; i < event; i++) {
    int e = current_maze[i];
    if (e == 1) {
        std::cout << "遭遇怪物！战斗开始...\n";
        ;  // 调用战斗函数
    } else if (e == 2) {
        std::cout << "商店\n";
        // shop();
    } else if (e == 3) {
        std::cout << "篝火\n";
        // rest();
    } else if (e == 4) {
        std::cout << "陷阱\n";
        // trap();
    } else if (e == 5) {
        std::cout << "宝箱\n";
        // open_chest();
    }
}
    std::cout << "\n";
    getchar();

}
void difficult() {
    srand(time(0)); // 初始化随机数种子

    int* current_maze = select_random_maze(difficult_maze);
    int difficulty = current_maze[0];

    std::cout << "当前难度:困难"<< "\n事件路径: ";
    for (int i = 1; i < event; i++) {
    int e = current_maze[i];
    if (e == 1) {
        std::cout << "遭遇怪物！战斗开始...\n";
        // 调用战斗函数
    } else if (e == 2) {
        std::cout << "商店\n";
        // shop();
    } else if (e == 3) {
        std::cout << "篝火\n";
        // rest();
    } else if (e == 4) {
        std::cout << "陷阱\n";
        // trap();
    } else if (e == 5) {
        std::cout << "宝箱\n";
        // open_chest();
    }
}
    std::cout << "\n";
    getchar();

}
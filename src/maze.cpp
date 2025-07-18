#include <iostream>
#include <cstdlib>
#include <ctime>
#include "maze.h"
#include "battle.h"
#include "Hero_and_Monster.h"
#include "shop.h"
#include "game.h"
#include "monsters.h"
extern Equipment silver_spear,defense_shield,brave_amulet;
extern int count_easy, count_medium, count_hard;
Shop shop;
int easy_maze[round][event] = {
    {0, 1, 3, 1, 1, 4, 1, 5},
    {0, 1, 2, 3, 1, 1, 1, 5},
    {0, 1, 1, 1, 4, 3, 2, 5},
    {0, 1, 2, 1, 1, 3, 1, 5},
    {0, 1, 1, 3, 1, 2, 1, 5},
    {0, 1, 1, 1, 2, 1, 3, 5}
};

int medium_maze[round][event] = {
    {1, 1, 2, 3, 1, 1, 1, 5},
    {1, 1, 1, 2, 1, 3, 1, 5},
    {1, 1, 1, 1, 2, 3, 1, 5},
    {1, 2, 3, 1, 4, 1, 1, 5},
    {1, 1, 1, 3, 2, 4, 1, 5},
    {1, 2, 2, 1, 3, 1, 1, 5}
};

int difficult_maze[round][event] = {
    {2, 1, 2, 1, 3, 1, 4, 5},
    {2, 2, 4, 3, 1, 1, 1, 5},
    {2, 1, 1, 4, 2, 1, 3, 5},
    {2, 2, 1, 1, 1, 3, 4, 5},
    {2, 1, 1, 1, 4, 2, 3, 5},
    {2, 1, 2, 1, 3, 4, 1, 5}
};

int* select_random_maze(int maze[][event]) {
    int r = rand() % round;
    return maze[r];
}

void easy(Hero* hero) {
    srand(time(0)); // 初始化随机数种子
    int* current_maze = select_random_maze(easy_maze);
    int difficulty = current_maze[0];
    std::cout << "当前难度:简单"<< "\n按Enter进入冒险...\n";
    getchar(); 
    unsigned int HP = hero->get_HP();
    hero->set_max_HP(HP);
    for (int i = 1; i < event; i++) {
    int e = current_maze[i];
    if (e == 1) {
        std::cout << "遭遇怪物！按Enter开始战斗...\n";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        hero->equip(&defense_shield);
        hero->equip(&brave_amulet);
        std::srand(std::time(nullptr));
        int index = std::rand() % 6;
        Monster monster = monsters[0][index];
        backpack *bag=hero->get_backpack();
        Battle battle(hero,&monster);
        int result=battle.Battle_round(HP);  // 调用战斗函数
        if (result == 0){
            cout << "💀 你的战术堪称完美...可惜敌人不按剧本演。" << endl<<endl;
            cout << "💔 按Enter返回主菜单...";
            hero->set_max_HP(HP);
            hero->change_HP(1000000,1.0,hero->get_max_HP());
            hero->set_max_HP(1000000);
            getchar(); // 等待用户按任意键
            system("cls"); // 清屏
            return;
        }
        else if (result == 1) {
            cout <<"🎊 按Enter前往下一关卡...";
            getchar(); // 等待用户按任意键
            system("cls"); // 清屏
        }
    } 
    else if (e == 2) {
        std::cout << "商店\n";
        shop.show_shop(hero);
        cout <<"🎊 按Enter前往下一关卡...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        // shop();
    } 
    else if (e == 3) {
        hero->set_max_HP(HP);
        hero->change_HP(20,1.0,hero->get_max_HP());
        hero->set_max_HP(1000000);
        std::cout << "到达篝火，回复20生命值！当前生命值：" << hero->get_HP() << "\n";
        cout <<"🎊 按Enter前往下一关卡...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        // rest();
    } 
    else if (e == 4) {
        std::cout << "你遇到了一个陷阱\n";
        int choice;
        std::cout << "请选择：";
        std::cout << "1. 扣除5生命值\n";
        std::cout << "2. 扣除50金币\n";
        std::cin >> choice;
        if (choice == 1) {
            hero->change_HP(-5,1.0,hero->get_max_HP());
            std::cout << "扣除50生命值成功！,剩余生命值：" << hero->get_HP() << "\n";
            getchar(); // 等待用户按任意键
            if (hero->get_HP() <= 0) {
                    cout << "💀 你迈出了探索的重要一步，然后...没再迈第二步。" << endl<<endl;
                    cout << "💔 按Enter返回主菜单...";
                    getchar(); // 等待用户按任意键
                    system("cls"); // 清屏
                    return;
                }
        } 
        else if (choice == 2) {
            hero->change_Money(-50);
            if (hero->get_Money() < 0)
            {
                std::cout << "金币不足,将扣除50生命值！\n";
                getchar(); // 等待用户按任意键
                hero->change_Money(50);
                hero->change_HP(-5,1.0,hero->get_max_HP());
                if (hero->get_HP() <= 0) {
                    cout << "💀 你迈出了探索的重要一步，然后...没再迈第二步。" << endl<<endl;
                    cout << "💔 按Enter返回主菜单...";
                    getchar(); // 等待用户按任意键
                    system("cls"); // 清屏
                    return;
                }
            }
            else {
                std::cout << "扣除50金币成功！,剩余金币：" << hero->get_Money() << "\n";
                getchar(); // 等待用户按任意键
            }
        }
        else {
            std::cout << "输入错误，请重新输入！\n";
        }
        cout <<"🎊 按Enter前往下一关卡...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        // trap();
        } 
        else if (e == 5) {
        std::cout << "你找到了宝箱\n";
        std::cout << "按Enter打开宝箱...\n";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        drop_equipment_easy();
        drop_equipment_easy();
        }
    }

        hero->set_max_HP(HP);
        hero->reborn(1.0);
        hero->set_max_HP(1000000);
        cout << "你已打败了简单难度的" << "\n";
        cout <<"🎊 按Enter返回主界面...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏

    }


void medium() {
    srand(time(0)); // 初始化随机数种子

    int* current_maze = select_random_maze(medium_maze);
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


void hard() {
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
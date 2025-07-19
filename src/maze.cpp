#include <iostream>
#include <cstdlib>
#include <ctime>
#include "maze.h"
#include "battle.h"
#include "Hero_and_Monster.h"
#include "game.h"
#include "story.h"
#include "monsters.h"
#include "backpack.h"
extern Equipment silver_spear,defense_shield,brave_amulet;
extern int count_easy, count_medium, count_hard;
Shop shop;
int easy_maze[ROUNDS][EVENTS] = {
    {0, 1, 3, 1, 1, 4, 1, 5},//11111
    {0, 1, 2, 3, 1, 1, 1, 5},
    {0, 1, 1, 1, 4, 3, 2, 5},//
    {0, 1, 2, 1, 1, 3, 1, 5},
    {0, 1, 1, 3, 1, 2, 1, 5},
    {0, 1, 1, 1, 2, 1, 3, 5}
};

int medium_maze[ROUNDS][EVENTS] = {
    {1, 1, 2, 3, 1, 1, 1, 5},
    {1, 1, 1, 2, 1, 3, 1, 5},
    {1, 1, 1, 1, 2, 3, 1, 5},
    {1, 2, 3, 1, 4, 1, 1, 5},
    {1, 1, 1, 3, 2, 4, 1, 5},
    {1, 2, 2, 1, 3, 1, 1, 5}
};

int hard_maze[ROUNDS][EVENTS] = {
    {2, 1, 2, 1, 3, 1, 4, 5},
    {2, 2, 4, 3, 1, 1, 1, 5},
    {2, 1, 1, 4, 2, 1, 3, 5},
    {2, 2, 1, 1, 1, 3, 4, 5},
    {2, 1, 1, 1, 4, 2, 3, 5},
    {2, 1, 2, 1, 3, 4, 1, 5}
};

int* select_random_maze(int maze[][EVENTS]) {
    int r = rand() % ROUNDS;
    return maze[r];
}

void easy(Hero* hero) {
    srand(time(0)); // 初始化随机数种子
    int* current_maze = select_random_maze(easy_maze);
    int difficulty = current_maze[0];
    std::cout << "当前难度:简单"<< "\n按Enter进入冒险...\n";
    getchar(); 
    unsigned int HP = hero->get_HP();
    for (int i = 1; i < EVENTS; i++) {
    int e = current_maze[i];
    if (e == 1) {
        std::cout << "遭遇怪物！按Enter开始战斗...\n";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        hero->equip(&defense_shield);
        hero->equip(&brave_amulet);
        std::srand(std::time(nullptr));
        int index = std::rand() % 6;
        Monster* monster = &monsters[0][index];
        Backpack *bag=hero->get_backpack();
        Battle battle(hero,monster);
        int result=battle.Battle_round(HP);  // 调用战斗函数
        if (result == 0){
            cout << "💀 你的战术堪称完美...可惜敌人不按剧本演。" << endl<<endl;
            cout << "💔 按Enter返回主菜单...";
            hero->reborn(1.0, HP);
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
        Shop shop;
        shop.show_shop_items();
        cout <<"🎊 按Enter前往下一关卡...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        // shop();
    } 
    else if (e == 3) {
        hero->change_HP(20,1.0,HP);
        printLineByLine(campfire, 40, SceneColorConfig(std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, std::vector<int>{}));
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
            hero->change_HP(-50,1.0,HP);
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
                hero->change_HP(-50,1.0,HP);
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
        if(count_easy == 0)
        {std::cout << "首次\n";}
        else if(count_easy == 1)
        {std::cout << "第二次\n";}
        printLineByLine(chest, 40, SceneColorConfig(std::vector<int>{}, std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}));
        std::cout << "你找到了宝箱\n";
        std::cout << "按Enter打开宝箱...\n";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        hero->get_equipment_backpack()->add_equipment(drop_equipment_easy());
        hero->get_equipment_backpack()->add_equipment(drop_equipment_easy());
        }
    }
        hero->reborn(1.0,HP);
        count_easy++;
        cout << "你已打败了简单难度的" << "\n";
        cout <<"🎊 按Enter返回主界面...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏

    }


void medium(Hero* hero) {
    srand(time(0)); // 初始化随机数种子
    int* current_maze = select_random_maze(medium_maze);
    int difficulty = current_maze[0];
    std::cout << "当前难度:中等"<< "\n按Enter进入冒险...\n";
    getchar(); 
    unsigned int HP = hero->get_HP();
    for (int i = 1; i < EVENTS; i++) {
    int e = current_maze[i];
    if (e == 1) {
        std::cout << "遭遇怪物！按Enter开始战斗...\n";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        hero->equip(&defense_shield);
        hero->equip(&brave_amulet);
        std::srand(std::time(nullptr));
        int index = std::rand() % 6;
        Monster* monster = &monsters[0][index];
        Backpack *bag=hero->get_backpack();
        Battle battle(hero,monster);
        int result=battle.Battle_round(HP);  // 调用战斗函数
        if (result == 0){
            cout << "💀 你的战术堪称完美...可惜敌人不按剧本演。" << endl<<endl;
            cout << "💔 按Enter返回主菜单...";
            hero->reborn(1.0, HP);
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
        shop.show_shop_items();
        cout <<"🎊 按Enter前往下一关卡...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        // shop();
    } 
    else if (e == 3) {
        hero->change_HP(20,1.0, HP);
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
            hero->change_HP(-5, 1.0, HP);
            std::cout << "扣除5生命值成功！,剩余生命值：" << hero->get_HP() << "\n";
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
                std::cout << "金币不足,将扣除5生命值！\n";
                getchar(); // 等待用户按任意键
                hero->change_Money(50);
                hero->change_HP(-5, 1.0, HP);
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
        if(count_easy == 0)
        {std::cout << "首次\n";}
        else if(count_easy == 1)
        {std::cout << "第二次\n";}
        std::cout << "你找到了宝箱\n";
        std::cout << "按Enter打开宝箱...\n";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        drop_equipment_easy();
        drop_equipment_easy();
        }
    }

        hero->reborn(1.0, HP);
        count_medium++;
        cout << "你通过中等难度的冒险！" << "\n";
        cout <<"🎊 按Enter返回主界面...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏

    }


void hard(Hero* hero) {
    srand(time(0)); // 初始化随机数种子
    int* current_maze = select_random_maze(hard_maze);
    int difficulty = current_maze[0];
    std::cout << "当前难度:困难"<< "\n按Enter进入冒险...\n";
    getchar(); 
    unsigned int HP = hero->get_HP();
    for (int i = 1; i < EVENTS; i++) {
    int e = current_maze[i];
    if (e == 1) {
        std::cout << "遭遇怪物！按Enter开始战斗...\n";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        hero->equip(&defense_shield);
        hero->equip(&brave_amulet);
        std::srand(std::time(nullptr));
        int index = std::rand() % 6;
        Monster* monster = &monsters[0][index];
        Backpack *bag=hero->get_backpack();
        Battle battle(hero,monster);
        int result=battle.Battle_round(HP);  // 调用战斗函数
        if (result == 0){
            cout << "💀 你的战术堪称完美...可惜敌人不按剧本演。" << endl<<endl;
            cout << "💔 按Enter返回主菜单...";
            hero->reborn(1.0, HP);
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
        shop.show_shop_items();
        cout <<"🎊 按Enter前往下一关卡...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        // shop();
    } 
    else if (e == 3) {
        hero->change_HP(20,1.0,HP);
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
            hero->change_HP(-5, 1.0, HP);
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
                hero->change_HP(-5, 1.0, HP);
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
        if(count_easy == 0)
        {std::cout << "首次\n";}
        else if(count_easy == 1)
        {std::cout << "第二次\n";}
        std::cout << "你找到了宝箱\n";
        std::cout << "按Enter打开宝箱...\n";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        drop_equipment_easy();
        drop_equipment_easy();
        }
    }

        hero->reborn(1.0, HP);
        count_hard++;
        cout << "你已打败了简单难度的" << "\n";
        cout <<"🎊 按Enter返回主界面...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏

    }
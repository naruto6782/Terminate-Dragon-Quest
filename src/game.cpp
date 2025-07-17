#include <iostream>
#include "game.h"
#include "story.h"
#include "Hero_and_Monster.h"
#include "battle.h"
#include "equip.h"
#include "shop.h"
#include "backpack.h"
#include "maze.h"
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>

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

void Game::init(Game* game){
    std::cout << "游戏已启动!" << std::endl;
    std::cout << "按Enter继续..." << std::endl;
    getchar();
    system("cls");
    game->menu1(game);
}

void Game::menu1(Game* game){
    std::cout << "请做出你的选择:" << std::endl << "1.新的开始" << std::endl << "2.加载游戏" << std::endl << "3.退出游戏" << std::endl;
    int choice;
    std::cin >> choice;
    switch(choice){
        case 1:
            system("cls");
            game->start();
            break;
        case 2:
            game->load();
            break;
        case 3:
            break;
        default:
            std::cout << "迷途的羔羊啊，请重新选择。" << std::endl;
            getchar();
            getchar();
            game->menu1(game);
        };
}

void Game::menu2(Hero* hero){//after name
    int choice;
    Shop shop;
    Medicine medicine("血瓶", 1, 100);
    Poison poison("毒瓶", 1, 100);
    // Equipment equipment(EquipmentType::Weapon, "暴风大剑", 10, 100, 3);
    // Equipment wwwww(EquipmentType::Armor, "流云铠甲", 10, 100, 2);
    // Equipment eeeee(EquipmentType::Accessory, "1111", 10, 100, 2);
    // hero->equip_Accessory(&eeeee);
    // hero->equip_Weapon(&equipment);
    // hero->equip_Armor(&wwwww);
    // Monster monster("zengtou", 100,10,1,10,10,10);
    backpack *bag=hero->get_backpack();
    bag->add_item(&medicine);
    while(1){
        std::cout << "请做出你的选择" << std::endl
        << "1.冒险" << std::endl << "2.挑战" << std::endl << "3.属性" << std::endl
        << "4.物品" << std::endl << "5.商店" << std::endl << "6.退出" << std::endl;
        std::cin >> choice;
        getchar();
        switch(choice){ 
        case 3:
            system("cls");
            hero->show_info(hero);
            break;
        case 4:
            system("cls");
            bag->show();
            break;
        case 1:
            {
            system("cls");
            easy(hero);
            break;
            }
        case 2:
            system("cls");
            bag->add_item(&poison);
            bag->show();
            break;
        case 5:
            system("cls");
            shop.show_shop(hero);
            break;
        case 6:
            exit(0);
            break;
        default:
            std::cout << "迷途的羔羊啊，请重新选择。" << std::endl;
            getchar();
            getchar();
        }
    }
}

void printWithDelay(const std::string& text, int delayMs = 50, const std::string& color = RESET) {    //字体打印
    std::cout << color;
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
    std::cout << RESET;  // 输出后重置颜色
}

void sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void printLineByLine(const std::vector<std::string>& lines, int delayMs, const SceneColorConfig& config) {     //图片打印
    for (size_t i = 0; i < lines.size(); ++i) {
        if (std::find(config.getRedLines().begin(), config.getRedLines().end(), i) 
            != config.getRedLines().end()) {
            std::cout << RED << lines[i] << RESET << std::endl;
        } else if (std::find(config.getYellowLines().begin(), config.getYellowLines().end(), i) 
                   != config.getYellowLines().end()) {
            std::cout << GOLD << lines[i] << RESET << std::endl;
        } else {
            std::cout << lines[i] << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
}
void Game::start(){
    system("chcp 65001 > nul");
    
    printLineByLine(asciiScene, 40, SceneColorConfig(std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}, std::vector<int>{}));
 
        printWithDelay(intro1, 30, CYAN); //1
    cout << "按Enter继续..." << endl;
    getchar();
    getchar();
    system("cls");
    printLineByLine(asciiHero, 40, SceneColorConfig(std::vector<int>{}, std::vector<int>{}));
    printWithDelay(intro2, 30, CYAN);//2
    std::cout << "请输入你的名字：";
    std::string name;
    cin >> name;
    getchar();
    system("cls");
    printLineByLine(asciiSword, 40, SceneColorConfig(std::vector<int>{}, std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}));
    std::string intro3 = 
    "“如此甚好，" + name + "。汝之命运，当由此展开。”\n"
    "提汝之剑，踏上征途。汝乃天命之子。\n";

    printWithDelay(intro3, 30, CYAN);//3
    printWithDelay(intro4, 30, CYAN);
    cout << "\n" << endl;
    cout << "按下Enter继续..." << endl;
    getchar();
    system("cls");
    printLineByLine(asciiLogo, 40, SceneColorConfig(std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29}, std::vector<int>{}));//logo
    sleep(1500);
    system("cls");
    Hero hero(name,100,10,10,10,10,1,30);
    menu2(&hero);
}





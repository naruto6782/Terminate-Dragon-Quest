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
    backpack *bag=hero->get_backpack();
    while(1){
        system("cls");
        std::cout<< "1.冒险" << std::endl << "2.挑战" << std::endl << "3.属性" << std::endl
        << "4.物品" << std::endl << "5.商店" << std::endl << "6.退出" << std::endl;
        std::cout << "请做出你的选择：";
        std::cin >> choice;
        getchar();
        switch(choice){ 
        case 1:
            {
            system("cls");
            if(count_challenge == 0){
                std::cout << "请选择难度：\n1.简单\n2.中等\n3.困难\n请输入你的选择：" << std::endl;
                int choose;
                cin >> choose;
                getchar();
                system("cls");
                switch(choose){
                    case 1:
                        easy(hero);
                        break;
                    case 2:
                        std::cout << "击败 梦魇蝶后 · 赛莲 解锁" << std::endl;
                        std::cout << "按Enter返回主菜单..." << std::endl;
                        getchar();
                        break;
                    case 3:
                        std::cout << "击败 焚天古龙 · 阿祖尔瓦恩 解锁" << std::endl;
                        std::cout << "按Enter返回主菜单..." << std::endl;
                        getchar();
                        break;
                    default:
                        std::cout << "迷途的羔羊啊，请重新选择。" << std::endl;
                        getchar();

                }
            break;
            } 
            if(count_challenge == 1){
                std::cout << "请选择难度：\n1.简单\n2.中等\n3.困难\n请输入你的选择：" << std::endl;
                int choose;
                cin >> choose;
                getchar();
                system("cls");
                switch(choose){
                    case 1:
                        easy(hero);
                        break;
                    case 2:
                        medium(hero);
                        break;
                    case 3:
                        std::cout << "击败 焚天古龙 · 阿祖尔瓦恩 解锁" << std::endl;
                        std::cout << "按Enter返回主菜单..." << std::endl;
                        getchar();
                        break;
                    default:
                        std::cout << "迷途的羔羊啊，请重新选择。" << std::endl;
                        getchar();
                        getchar();
                }
            break;
            } 
            if(count_challenge == 2){
                std::cout << "请选择难度：\n1.简单\n2.中等\n3.困难\n请输入你的选择：" << std::endl;
                int choose;
                cin >> choose;
                getchar();
                system("cls");
                switch(choose){
                    case 1:
                        easy(hero);
                        break;
                    case 2:
                        medium(hero);
                        break;
                    case 3:
                        hard(hero);
                        break;
                    default:
                        std::cout << "迷途的羔羊啊，请重新选择。" << std::endl;
                        getchar();
                        getchar();
                }
            break;
            } 
        }
        case 2:
            system("cls");
            bag->add_item(&poison);
            bag->show();
            break;
        case 3:
            system("cls");
            hero->show_info(hero);
            break;
        case 4:
            system("cls");
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
        }
    }
}

void printWithDelay(const std::string& text, int delayMs, const std::string& color) {    //字体打印
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





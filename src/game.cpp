#include <iostream>
#include "game.h"
#include "music.h"
#include "story.h"
#include "Hero_and_Monster.h"
#include "battle.h"
#include "equip.h"
#include "backpack.h"
#include "maze.h"
#include "challenge.h"
#include "save_and_load.h"
#include "check.h"
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>
using std::byte;
#include <vector>
#include <algorithm>


void Game::init(Game* game){
    initMusic();
    std::cout << "游戏已启动!" << std::endl;
    std::cout << "欢迎游玩Terminal Dragon Quest!\n本游戏采取手动存档方式，请在主菜单的“冒险之书”中进行存档。" << std::endl;
    std::cout << "按Enter继续..." << std::endl;
    getchar();
    system("cls");
    game->menu1(game);
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


void Game::menu1(Game* game){
    playMusic("music/start.mp3", 1000);
    std::cout << "请做出你的选择:" << std::endl << "1.新的开始" << std::endl << "2.加载游戏" << std::endl << "3.退出游戏" << std::endl;
    int choice;
    choice= getValidChoice(1, 3);
    Hero hero("",100,10,10,10,10,1,30);
    Shop shop;
    switch(choice){
        case 1:
            shop.Shop_init();
            system("cls");
            game->start(&hero, &shop);
            break;
        case 2:
            loadGame(&hero, &shop, "./save.txt");
            menu2(&hero, &shop);
            break;
        case 3:
            exit(0);
            break;
        default:
            std::cout << "迷途的羔羊啊，请重新选择。" << std::endl;
            getchar();
            getchar();
            game->menu1(game);
        };
}

void Game::menu2(Hero* hero, Shop* shop){
    stopMusic(500);
    int choice;
    Backpack *bag=hero->get_backpack();
    while(1){
        playMusic("music/bgm.mp3", 1000);
        system("cls");
        std::cout<< "1.冒险" << std::endl << "2.挑战" << std::endl << "3.属性" << std::endl
        << "4.物品" << std::endl << "5.商店" << std::endl << "6.冒险之书" << std::endl << "7.退出游戏" << std::endl;
        std::cout << "请做出你的选择：";
        bool validInput = false;
        int choice = getValidChoice(1, 7);
        unsigned int HP = hero->get_HP();
        switch(choice){ 
        case 1:
            {
            stopMusic(500);
            playMusic("music/fight.mp3", 1000);
            system("cls");
            if(count_challenge == 0){
                std::cout << "请选择难度：\n1.简单\n2.中等\n3.困难\n请输入你的选择：" << std::endl;
                int choose;
                choose=getValidChoice(1, 3);
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
                stopMusic(500);
            break;
            } 
            if(count_challenge == 1){
                std::cout << "请选择难度：\n1.简单\n2.中等\n3.困难\n请输入你的选择：" << std::endl;
                int choose;
                choose=getValidChoice(1, 3);
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
                stopMusic(500);
            break;
            } 
            if(count_challenge >= 2){
                std::cout << "请选择难度：\n1.简单\n2.中等\n3.困难\n请输入你的选择：" << std::endl;
                int choose;
                choose=getValidChoice(1, 3);
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
                stopMusic(500);
            break;
            } 
            
        }
        case 2:
            system("cls");
            if(count_easy>=1&&count_medium == 0&&count_hard == 0){
                system("cls");
                stopMusic(500);
                playMusic("music/selen.mp3", 1000);
                Selen(hero);
                stopMusic(500);
                break;
            }
            else if(count_medium >= 1&&count_hard == 0){
                system("cls");
                stopMusic(500);
                playMusic("music/fire.mp3", 1000);
                Azurvain(hero);
                stopMusic(500);
                break;
            }
            else if(count_hard >= 1){
                system("cls");
                stopMusic(500);
                playMusic("music/final.mp3", 1000);
                Nekthos(hero);
                stopMusic(500);
                break;
            }
            else{
                std::cout << "通关简单难度冒险以解锁挑战。" << std::endl;
                getchar();
                system("cls");
                break;
            }
        case 3:
            stopMusic(500);
            playMusic("music/daily.mp3", 1000);
            system("cls");
            hero->show_info(hero);
            stopMusic(500);
            break;
        case 4:
            stopMusic(500);
            playMusic("music/daily.mp3", 1000);
            system("cls");
            bag->show_backpack();
            cout << "输入任意键返回主菜单";
            stopMusic(500);
            getchar();
            break;
        case 5:
            stopMusic(500);
            playMusic("music/daily.mp3", 1000);
            system("cls");
            shop->show_shop_items(hero);
            stopMusic(500);
            break;
        case 6:
            saveGame(hero, shop, "./save.txt");
            break;
        case 7:
            stopMusic(500);
            closeMusic();
            exit(0);
            break;
        default:
            std::cout << "迷途的羔羊啊，请重新选择。" << std::endl;
            getchar();
        }
    }
}


void Game::start(Hero* hero, Shop* shop) {
    system("chcp 65001 > nul");
    
    printLineByLine(asciiScene, 40, SceneColorConfig(std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}, std::vector<int>{}));//场景
    printWithDelay(intro1, 30, CYAN); //文字
    cout << "按Enter继续..." << endl;
    getchar();
    system("cls");
    printLineByLine(asciiHero, 40, SceneColorConfig(std::vector<int>{}, std::vector<int>{}));//英雄
    printWithDelay(intro2, 30, CYAN);//文字
    std::cout << "请输入你的名字：";
    std::string name;
    cin >> name;
    getchar();
    system("cls");
    printLineByLine(asciiSword, 40, SceneColorConfig(std::vector<int>{}, std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}));//剑
    std::string intro3 = 
    "“如此甚好，" + name + "。汝之命运，当由此展开。”\n"
    "提汝之剑，踏上征途。汝乃天命之子。\n";

    printWithDelay(intro3, 30, CYAN);//文字
    printWithDelay(intro4, 30, CYAN);//文字
    cout << "\n" << endl;
    cout << "按下Enter继续..." << endl;
    getchar();
    system("cls");
    printLineByLine(asciiLogo, 40, SceneColorConfig(std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29}, std::vector<int>{}));//logo
    sleep(1500);
    system("cls");
    hero->set_name(name);//英雄的初始化
    menu2(hero, shop);
}





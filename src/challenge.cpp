#include <iostream>
#include <string>
#include "Hero_and_Monster.h"
#include "story.h"
#include "items.h"
#include "battle.h"
#include "challenge.h"
#include "count.h"
#include "story.h"
#include "game.h"
#include "equip.h"
#include "music.h"

Boss* create_selen_boss() {
    Boss* boss =  new Boss ("梦魇蝶后 · 赛莲", 200, 10, 8, 10, 500, 20);
    boss->add_skill(Skill("💀 轻语之惧", [](Hero* hero, Monster* self) {
        std::cout << "💀 梦魇蝶后的低语侵入你心灵，使你陷入眩晕！\\n";
        hero->getStatusEffect()->setStunned();
    }, 0.2));
    return boss;
    }
Boss* create_azurvain_boss() {
    Boss* boss = new Boss("焚天古龙 · 阿祖尔瓦恩", 300, 15, 15, 12, 600, 50);
    boss->add_skill(Skill("龙息喷吐", [](Hero* hero, Monster* self) {
        int dmg = 40;
        std::cout << "🔥 阿祖尔瓦恩喷出灼热龙息，对你造成 " << dmg << " 点伤害！" << std::endl;
        hero->change_HP(-dmg, 1.0);
    }, 0.4));
    boss->add_skill(Skill("怒吼震击", [](Hero* hero, Monster* self) {
        std::cout << "💥 天崩地裂！你的身体被震得麻痹，无法行动！" << std::endl;
        hero->getStatusEffect()->setStunned();
    }, 0.2));
    return boss;
}
Boss* create_nekthos_boss() {
    Boss* boss = new Boss("深渊邪龙 · 奈克托斯", 400, 20, 20, 25, 800, 200);
    boss->add_skill(Skill("虚空坍缩", [](Hero* hero, Monster* self) {
        int dmg = 60;
        std::cout << "🌌 奈克托斯召唤坍塌的虚空，对你造成 " << dmg << " 点真实伤害！" << std::endl;
        hero->change_HP(-dmg, 1.0);
    }, 0.5));
    boss->add_skill(Skill("命运剥夺", [](Hero* hero, Monster* self) {
        std::cout << "🕱 奈克托斯重写你的命运，你陷入了双重异常状态！" << std::endl;
        hero->getStatusEffect()->setPoisoned();
        hero->getStatusEffect()->setStunned();
    }, 0.3));
    boss->add_skill(Skill("🕳️  深渊之力", [](Hero* hero, Monster* self) {
        int heal = 100;
        std::cout << "🕳️  奈克托斯吸收周围的混沌之力，恢复了 " << heal << " 点生命值！\n";
        self->change_HP(heal,1.0);
    }, 0.25));
    return boss;
}

void Selen(Hero* hero){
    Boss* boss = create_selen_boss();
    Backpack *bag=hero->get_backpack();
    unsigned int HP = hero->get_HP();
    std::cout << "梦魇蝶后 · 赛莲" << std::endl;
    printLineByLine(selen,40, SceneColorConfig(std::vector<int>{}, std::vector<int>{}));
    printWithDelay(intro5, 30, CYAN);
    std::cout << "按Enter继续..." << std::endl;
    getchar();
    system("cls");
    Battle battle(hero,boss);
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
            count_challenge++;
            hero->get_equipment_backpack()->add_equipment(drop_equipment_selen());
            cout <<"🎊 按Enter继续...";
            getchar(); // 等待用户按任意键
            system("cls"); // 清屏
            printLineByLine(selen_after,40, SceneColorConfig(std::vector<int>{}, std::vector<int>{}));
            printWithDelay(intro6, 30, CYAN);
            std::cout << "按Enter继续..." << std::endl;
            getchar();
            system("cls");
            hero->reborn(1.0,HP);
            }
    
}
void Azurvain(Hero* hero){
    Boss* boss = create_azurvain_boss();
    Backpack *bag=hero->get_backpack();
    unsigned int HP = hero->get_HP();
    std::cout << "焚天古龙 · 阿祖尔瓦恩" << std::endl;
    printLineByLine(firedragon,40, SceneColorConfig(std::vector<int>{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26}, std::vector<int>{}));
    printWithDelay(intro7, 30, CYAN);
    std::cout << "按Enter继续..." << std::endl;
    getchar();
    system("cls");
    Battle battle(hero,boss);
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
            count_challenge++;
            hero->get_equipment_backpack()->add_equipment(drop_equipment_fire());
            cout <<"🎊 按Enter继续...";
            getchar(); // 等待用户按任意键
            system("cls"); // 清屏
            printLineByLine(firedragon_after,40, SceneColorConfig(std::vector<int>{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26}, std::vector<int>{}));
            printWithDelay(intro8, 30, CYAN);
            std::cout << "按Enter继续..." << std::endl;
            getchar();
            system("cls");
            hero->reborn(1.0,HP);
            }
        
}
void Nekthos(Hero* hero){
    Boss* boss = create_nekthos_boss();
    Backpack *bag=hero->get_backpack();
    unsigned int HP = hero->get_HP();
    std::cout << "深渊邪龙 · 奈克托斯" << std::endl;
    printLineByLine(necktos,40, SceneColorConfig(std::vector<int>{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26}, std::vector<int>{}));
    printWithDelay(intro9, 30, CYAN);
    std::cout << "按Enter继续..." << std::endl;
    getchar();
    system("cls");
    Battle battle(hero,boss);
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
            cout <<"🎊 按Enter继续...";
            count_challenge++;
            hero->get_equipment_backpack()->add_equipment(drop_equipment_final());
            getchar(); // 等待用户按任意键
            system("cls"); // 清屏
            printLineByLine(necktos_after,40, SceneColorConfig(std::vector<int>{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,21,32,33}, std::vector<int>{}));
            printWithDelay(intro10, 30, CYAN);
            bool validChoice = false;
            while (!validChoice) {
                std::cout << "是否要给予奈克托斯最后一击？\n1.是\n2.否\n请输入你的选择：" << std::endl;
                int end;
                std::cin >> end;
                getchar(); // 读取换行符
                switch (end) {
                    case 1:
                        system("cls");
                        stopMusic(1000);
                        playMusic("music/false_end.wav", 1000);
                        printLineByLine(false_end,40, SceneColorConfig(std::vector<int>{}, std::vector<int>{}));
                        printWithDelay(intro11, 30, CYAN);
                        std::cout << "按Enter继续..." << std::endl;
                        getchar();
                        system("cls");
                        std::cout << "感谢您游玩Terminal Dragon Quest！\n本游戏共有两个结局，剧情灵感来源于《旺达幻视》。因为是小游戏，篇幅有限，所以剧情可能看起来不尽人意，还望海涵。\n" << std::endl;
                        std::cout << "按Enter返回主菜单..." << std::endl;
                        getchar();
                        system("cls");
                        hero->reborn(1.0, HP);
                        stopMusic(1000);
                        validChoice = true;
                        break;
                
                    case 2:
                        system("cls");
                        stopMusic(1000);
                        playMusic("music/true_end.wav", 1000);
                        printLineByLine(true_end1,40, SceneColorConfig(std::vector<int>{}, std::vector<int>{}));
                        printWithDelay(intro12, 30, CYAN);
                        system("cls");
                        printLineByLine(true_end2,40, SceneColorConfig(std::vector<int>{}, std::vector<int>{}));
                        printWithDelay(intro13, 30, CYAN);
                        std::cout << "按Enter继续..." << std::endl;
                        getchar();
                        system("cls");
                        std::cout << "感谢您游玩Terminal Dragon Quest！\n本游戏共有两个结局，剧情灵感来源于《旺达幻视》。因为是小游戏，篇幅有限，所以剧情可能看起来不尽人意，还望海涵。\n" << std::endl;
                        std::cout << "按Enter返回主菜单..." << std::endl;
                        getchar();
                        system("cls");
                        hero->reborn(1.0, HP);
                        stopMusic(1000);
                        validChoice = true;
                        break;
                
                    default:
                        std::cout << "此乃命运无法到达之处，请重新选择。" << std::endl;
                        getchar(); // 暂停一下
                        break;
                }
                }
            }
}


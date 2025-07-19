#include <iostream>
#include <string>
#include "Hero_and_Monster.h"
#include "story.h"
#include "items.h"
#include "battle.h"
#include "challenge.h"


Boss* create_selen_boss() {
    Boss* boss =  new Boss ("梦魇蝶后 · 赛莲", 200, 10, 15, 20, 60, 50);
    boss->add_skill(Skill("💀 黑暗咆哮", [](Hero* hero, Monster* self) {
        std::cout << "💀 黑暗力量将你笼罩！你陷入眩晕！\n";
        hero->getStatusEffect()->setStunned();
    }, 0.2));
    return boss;
    }
Boss* create_azurvain_boss() {
    Boss* boss = new Boss("焚天古龙 · 阿祖尔瓦恩", 10, 10, 30, 10, 20, 150);
    boss->add_skill(Skill("龙息喷吐", [](Hero* hero, Monster* self) {
        int dmg = 40;
        std::cout << "🔥 龙息灼烧你造成 " << dmg << " 点伤害！" << std::endl;
        hero->change_HP(-dmg, 1.0);
    }, 0.4));
    boss->add_skill(Skill("怒吼震击", [](Hero* hero, Monster* self) {
        std::cout << "💥 你被震晕了！" << std::endl;
        hero->getStatusEffect()->setStunned();
    }, 0.2));
    return boss;
}
Boss* create_nekthos_boss() {
    Boss* boss = new Boss("深渊邪龙 · 奈克托斯", 500, 10, 40, 25, 100, 300);
    boss->add_skill(Skill("虚空坍缩", [](Hero* hero, Monster* self) {
        int dmg = 60;
        std::cout << "🌌 空间扭曲造成 " << dmg << " 点真实伤害！" << std::endl;
        hero->change_HP(-dmg, 1.0);
    }, 0.5));
    boss->add_skill(Skill("命运剥夺", [](Hero* hero, Monster* self) {
        std::cout << "🕱 命运被重写... 你陷入了双重异常状态！" << std::endl;
        hero->getStatusEffect()->setPoisoned();
        hero->getStatusEffect()->setStunned();
    }, 0.3));
    return boss;
}

void Selen(Hero* hero){
    Boss* boss = create_selen_boss();
    Backpack *bag=hero->get_backpack();
    unsigned int HP = hero->get_HP();
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
            cout <<"🎊 按Enter返回主菜单...";
            getchar(); // 等待用户按任意键
            system("cls"); // 清屏
            }
    count_challenge++;
}
void Azurvain(Hero* hero){
    Boss* boss = create_azurvain_boss();
    Backpack *bag=hero->get_backpack();
    unsigned int HP = hero->get_HP();
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
            cout <<"🎊 按Enter返回主菜单...";
            getchar(); // 等待用户按任意键
            system("cls"); // 清屏
            }
        count_challenge++;
}
void Nekthos(Hero* hero){
    Boss* boss = create_nekthos_boss();
    Backpack *bag=hero->get_backpack();
    unsigned int HP = hero->get_HP();
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
            cout <<"🎊 按Enter返回主菜单...";
            getchar(); // 等待用户按任意键
            system("cls"); // 清屏
            }
}


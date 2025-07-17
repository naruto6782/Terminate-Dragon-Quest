#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include "Hero_and_Monster.h"
#include "status.h"
using namespace std;

static mt19937_64& get_random_engine() {//用于随机数生成
    static random_device rd;  // 硬件随机源
    static mt19937_64 engine(rd()); // 使用64位梅森旋转算法
    return engine;
}

void printBar(int value, int max_value = 100, int barWidth = 30) {
    int pos = value * barWidth / max_value;
    cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "■";
        else cout << " ";
    }
    cout << "] " << value << endl;
}
//----------------Hero-Section----------------
void Hero::show_info(Hero* hero) {
    cout << "\tHero " << hero->get_name()<<'\t'<<"Level:"<<hero->get_Level()<<endl;
    
    cout << "HP:\t\t\t";
    printBar(hero->get_HP());
    
    cout << "Attack:\t\t\t";
    printBar(hero->get_Attack());
    
    cout << "Defense:\t\t";
    printBar(hero->get_Defense());
    
    cout << "Speed:\t\t\t";
    printBar(hero->get_Speed());
    
    cout << "Luck:\t\t\t";
    printBar(hero->get_Luck());
    
    cout << endl;

    hero->getStatusEffect()->print();

    cout << endl;

    std::cout << "当前装备：" << std::endl;
    std::cout << "武器: " << (weapon ? weapon->get_name() : "无") << std::endl;
    std::cout << "防具: " << (armor ? armor->get_name() : "无") << std::endl;
    std::cout << "饰品: " << (accessory ? accessory->get_name() : "无") << std::endl;
    std::cout << "按任意键返回主菜单..." << std::endl;
    getchar();
    
    system("cls");


}
    // hero->getEquipment()->equip(hero);

    // cout<< endl;

int H2M_ultimate_attack(int H_Attack, int M_Defense, int H_Speed, int M_Speed,int H_Luck, bool M_isdefense){
    //参数分别为英雄攻击力，怪物防御力，英雄速度，怪物速度，英雄幸运值，怪物是否防御
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned>(time(0)));
        seeded = true;
    }

    int delta_speed = M_Speed - H_Speed;

    // 闪避概率：基础5% + 每点速度差加1%，最多50%
    double dodge_chance = 0.05 + delta_speed * 0.01-0.005*H_Luck;
    if (dodge_chance < 0.05) dodge_chance = 0.05;
    if (dodge_chance > 0.5) dodge_chance = 0.5;

    // 0.0 到 1.0 的随机数
    static auto& engine = get_random_engine();
    uniform_real_distribution<double> dist(0.0, 1.0);
    double roll = dist(engine);

    if (roll < dodge_chance) {//闪避成功
        cout << "怪物闪避了攻击！？" << endl << endl;
        return 0;
    }
    //计算伤害
    double damage = 10*H_Attack - 2* M_Defense;
    if (damage < 0) damage = 0;//伤害不能为负
    if (M_isdefense) damage = damage * 0.5;//防御伤害减半
    cout << "你进行了攻击！ 对怪兽最终伤害: " << static_cast<int>(damage) << endl << endl;
    return static_cast<int>(damage);
}
void Hero::Attack_Monster(Hero* hero, Monster* monster){
    //先计算伤害，如果未躲避成功，再减少怪物HP
    int damage=H2M_ultimate_attack(hero->get_Attack(),monster->get_Defense(),hero->get_Speed(),monster->get_Speed(),hero->get_Luck(),monster->getStatusEffect()->defending);
    monster->change_HP(-damage,1.0);
}
//TODO 英雄选择技能

//TODO 英雄选择道具

//TODO 英雄选择逃跑

//----------------Monster-Section----------------
void Monster::show_info(Monster* monster){
    cout<<"\tMonster "<<monster->get_name()<<'\t'<<"Level:"<<monster->get_Level()<<endl;
    
    cout << "HP:\t\t\t";
    printBar(monster->get_HP());
    
    cout << "Attack:\t\t\t";
    printBar(monster->get_Attack());
    
    cout << "Defense:\t\t";
    printBar(monster->get_Defense());
    
    cout << "Speed:\t\t\t";
    printBar(monster->get_Speed());

    cout << endl;
}


int M2H_ultimate_attack(int M_Attack, int H_Defense, int H_Speed, int M_Speed,int H_Luck,bool H_isdefense) {
    //参数分别为怪物攻击力，英雄防御力，英雄速度，怪物速度，英雄幸运值，英雄是否防御
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned>(time(0)));
        seeded = true;
    }

    int delta_speed = H_Speed - M_Speed;

    // 闪避概率：基础5% + 每点速度差加1%，最多50%
    double dodge_chance = 0.05 + delta_speed * 0.01+0.005*H_Luck;
    if (dodge_chance < 0.05) dodge_chance = 0.05;
    if (dodge_chance > 0.5) dodge_chance = 0.5;

    // 0.0 到 1.0 的随机数
    static auto& engine = get_random_engine();
    uniform_real_distribution<double> dist(0.0, 1.0);
    double roll = dist(engine);

    if (roll < dodge_chance) {
        cout << "你闪避了攻击！" << endl << endl;
        return 0;
    }

    double damage = 10*M_Attack - 2* H_Defense;
    if (damage < 0) damage = 0;
    if (H_isdefense) damage = damage * 0.5;
    cout << "怪兽进行了攻击！ 对你最终伤害: " << static_cast<int>(damage) << endl << endl;
    return static_cast<int>(damage);
}

void Monster::Attack_Hero(Hero* hero, Monster* monster){
    //先计算伤害，如果未躲避成功，再减少英雄HP
    int damage=M2H_ultimate_attack(monster->get_Attack(),hero->get_Defense(),hero->get_Speed(),monster->get_Speed(),hero->get_Luck(),hero->getStatusEffect()->defending);
    hero->change_HP(-damage,1.0);

}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include "Hero_and_Monster.h"
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
        if (i < pos) cout << "#";
        else cout << " ";
    }
    cout << "] " << value << endl;
}
//----------------Hero-Section----------------
void Hero::show_info(Hero* hero) {
    cout << "\tHero " << hero->name << endl;
    
    cout << "HP:\t\t\t";
    printBar(hero->HP);
    
    cout << "Attack:\t\t\t";
    printBar(hero->Attack);
    
    cout << "Defense:\t\t";
    printBar(hero->Defense);
    
    cout << "Speed:\t\t\t";
    printBar(hero->Speed);
    
    cout << "Luck:\t\t\t";
    printBar(hero->Luck);
    
    cout << endl;
}
//TODO 英雄选择攻击

//TODO 英雄选择防御

//TODO 英雄选择技能

//TODO 英雄选择道具

//TODO 英雄选择逃跑

//----------------Monster-Section----------------
void Monster::show_info(Monster* monster){
    cout<<"\tMonster "<<monster->name<<endl;
    
    cout << "HP:\t\t\t";
    printBar(monster->HP);
    
    cout << "Attack:\t\t\t";
    printBar(monster->Attack);
    
    cout << "Defense:\t\t";
    printBar(monster->Defense);
    
    cout << "Speed:\t\t\t";
    printBar(monster->Speed);

    cout << endl;
}


int ultimate_attack(int M_Attack, int H_Defense, int H_Speed, int M_Speed,int H_Luck) {
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
        cout << "Hero dodged the ultimate attack!" << endl << endl;
        return 0;
    }

    double damage = 10*M_Attack - 2* H_Defense;
    if (damage < 0) damage = 0;

    cout << "Ultimate attack damage: " << static_cast<int>(damage) << endl << endl;
    return static_cast<int>(damage);
}

void Monster::Attack_Hero(Hero* hero, Monster* monster){
    //TODO 还和防没防御有关
    int damage=ultimate_attack(hero->get_Attack(),hero->get_Defense(),hero->get_Speed(),monster->get_Speed(),hero->get_Luck());
    hero->change_HP(-damage);
    if(damage>0){
        cout<<"Monster Attacked Hero!"<<endl;
        cout<<endl;
    }
}
//TODO 怪物选择防守
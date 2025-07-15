#ifndef HERO_AND_MONSTER_H
#define HERO_AND_MONSTER_H
#include <string>
#include "status.h"
#include "equip.h"
class Base
{
protected:
    StatusEffect* status;
    Accessory* accessory;
    std::string name;
    unsigned int HP=100;
    unsigned int Attack=10;
    unsigned int Defense=10;
    unsigned int Speed=10;
    unsigned int Level=1;   
public:
        Base(const std::string& name, unsigned int HP, unsigned int Attack, unsigned int Defense, unsigned int Speed, unsigned int Level) {
        this->name = name;
        this->HP = HP;
        this->Attack = Attack;
        this->Defense = Defense;
        this->Speed = Speed;
        this->Level = Level;
        }
        //get方法
        std::string get_name() const { return name; }
        int get_HP() const { return HP; }
        int get_Attack() const { return Attack; }
        int get_Defense() const { return Defense; }
        int get_Speed() const { return Speed; }
        int get_Level() const { return Level; }
        bool is_Alive() const { return HP > 0; }
        StatusEffect* getStatusEffect() const {return status;}
        Accessory* getAccessory() const {return accessory;}
        //改变属性值
        void change_HP(int num) { HP += num; }
        void change_Attack(int num) { Attack += num; }
        void change_Defense(int num) { Defense += num; }
        void change_Speed(int num) { Speed += num; }
        void change_Level(int num) { Level += num; }
        void setStatusEffect(StatusEffect* status) {this->status = status;}
        void setAccessory(Accessory* accessory) {this->accessory = accessory;}
};
class Monster;
class Hero: public Base
{
private:
    unsigned int Luck=0;
public:
    void show_info(Hero* hero);//展示英雄信息
    void change_Luck(int num) { Luck += num; }
    //构造函数
    Hero(const std::string& name, unsigned int HP, unsigned int Attack, unsigned int Defense, unsigned int Speed,unsigned int Level, unsigned int Luck) : Base(name, HP, Attack, Defense, Speed, Level) {
        this->Luck = Luck;
    }
    int get_Luck() const { return Luck; }
    void Attack_Monster(Hero* hero, Monster* monster,StatusEffect* hero_status_effect,StatusEffect* monster_status_effect);
};
class Monster: public Base
{
public:
    using Base::Base;
    void show_info(Monster* monster);//展示怪物信息
    void Attack_Hero(Hero* hero, Monster* monster,StatusEffect* hero_status_effect,StatusEffect* monster_status_effect);
};
#endif
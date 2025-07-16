#ifndef HERO_AND_MONSTER_H
#define HERO_AND_MONSTER_H
#include <string>
#include "status.h"
#include "equip.h"
#include "backpack.h"

class StatusEffect;
class Accessory;
class backpack;

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
        this->status=new StatusEffect();
        this->accessory=new Accessory();
        this->status->resetAll();
        }
        virtual ~Base(){
            delete accessory;
            delete status;
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
        void change_HP(int num=0, double rate=1.0) { HP += num; HP = (int)(HP * rate); }//便于修改属性值
        void change_Attack(int num=0, double rate=1.0) { Attack += num; Attack = (int)(Attack * rate); }
        void change_Defense(int num=0, double rate=1.0) { Defense += num; Defense = (int)(Defense * rate); }
        void change_Speed(int num=0, double rate=1.0) { Speed += num; Speed = (int)(Speed * rate); }
        void change_Level(int num=0) { Level += num;}
        void setStatusEffect(StatusEffect* newStatus) {
            delete this->status;
            this->status = newStatus;
        }
        void setAccessory(Accessory* newAccessory) {
            delete this->accessory;
            this->accessory = newAccessory;
        }
};
class Monster;
class Hero: public Base
{
private:
    unsigned int Luck=0;
    backpack *hero_backpack;
public:
    backpack *get_backpack(){return this->hero_backpack;}
    void show_info(Hero* hero);//展示英雄信息
    void change_Luck(int num) { Luck += num; }
    //构造函数
    Hero(const std::string& name, unsigned int HP, unsigned int Attack, unsigned int Defense, unsigned int Speed,unsigned int Level, unsigned int Luck) : Base(name, HP, Attack, Defense, Speed, Level) {
        this->Luck = Luck;
        this->hero_backpack = new backpack(); // ✅ 动态分配背包
        this->hero_backpack->init_backpack(); // ✅ 初始化
    }
    ~Hero() override {
        delete hero_backpack;
    }
    int get_Luck() const { return Luck; }
    void Attack_Monster(Hero* hero, Monster* monster);
};
class Monster: public Base
{
public:
    using Base::Base;
    void show_info(Monster* monster);//展示怪物信息
    void Attack_Hero(Hero* hero, Monster* monster);
};

#endif
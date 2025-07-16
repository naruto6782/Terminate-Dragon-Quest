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
        this->status = new StatusEffect();
        this->status->resetAll();
        }
        virtual ~Base() {
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
        //改变属性值
        void change_HP(int num) { HP += num; }
        void change_Attack(int num) { Attack += num; }
        void change_Defense(int num) { Defense += num; }
        void change_Speed(int num) { Speed += num; }
        void change_Level(int num) { Level += num; }
        void setStatusEffect(StatusEffect* status) {this->status = status;}
};
class Monster;
class Hero: public Base
{
private:
    const Equipment* weapon;
    const Equipment* armor;
    const Equipment* accessory;
    unsigned int Luck=0;
    backpack *hero_backpack;
public:
    backpack *get_backpack(){return this->hero_backpack;}
    void show_info(Hero* hero);//展示英雄信息
    void change_Luck(int num) { Luck += num; };
    void set_weapon(Equipment* new_weapon) { weapon = new_weapon; }
    void set_armor(Equipment* new_armor) { armor = new_armor; }
    void set_accessory(Equipment* new_accessory) { accessory = new_accessory; }
    void equip_Weapon(const Equipment* new_weapon) {
        int index=new_weapon->get_index();
        if (index) {
            switch (index) {
                case 1: change_Attack(10); break;
                case 2: change_Attack(20); break;
                default: break;
            }
            weapon = new_weapon;
        }
    }

    void equip_Armor(const Equipment* new_armor) {
        int index=new_armor->get_index();
        if (index) {
            switch (index) {
                case 1: change_Defense(10); break;
                case 2: change_Defense(20); break;
                default: break;
            }
            armor = new_armor;
        }
    }

    void equip_Accessory(const Equipment* new_accessory) {
        int index=new_accessory->get_index();
        if (index) {
            switch (index) {
                case 1: change_Defense(10); break;
                case 2: change_Speed(10); break;
                case 3: change_Luck(10); break;
                default: break;
            }
            accessory = new_accessory;
        }
    }
    void unequip_Weapon() {
        if (weapon->get_index()) {
            switch (weapon->get_index()) {
                case 1: change_Attack(-10); break;
                case 2: change_Attack(-20); break;
                default: break;
            }
            weapon = nullptr;
        }
    }

    void unequip_Armor() {
        if (armor->get_index()) {
            switch (armor->get_index()) {
                case 1: change_Defense(-10); break;
                case 2: change_Defense(-20); break;
                default: break;
            }
            armor = nullptr;
        }
    }

    void unequip_Accessory() {
        if (accessory->get_index()) {
            switch (accessory->get_index()) {
                case 1: change_Defense(-10); break;
                case 2: change_Speed(-10); break;
                case 3: change_Luck(-10); break;
                default: break;
            }
            accessory = nullptr;
        }
    }

    void print_Equipped() {
        std::cout << "当前装备：" << std::endl;
        std::cout << "武器: " << (weapon ? weapon->get_name() : "无") << std::endl;
        std::cout << "防具: " << (armor ? armor->get_name() : "无") << std::endl;
        std::cout << "饰品: " << (accessory ? accessory->get_name() : "无") << std::endl;
    }
    //构造函数
    Hero(const std::string& name, unsigned int HP, unsigned int Attack, unsigned int Defense, unsigned int Speed,unsigned int Level, unsigned int Luck) : Base(name, HP, Attack, Defense, Speed, Level) {
        this->Luck = Luck;
        this->weapon = nullptr;
        this->armor = nullptr;
        this->accessory = nullptr;
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
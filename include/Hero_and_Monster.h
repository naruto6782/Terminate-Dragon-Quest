#ifndef HERO_AND_MONSTER_H
#define HERO_AND_MONSTER_H
#include <string>
#include "status.h"
#include "equip.h"
#include "backpack.h"

class StatusEffect;
class Accessory;
class backpack;

extern Equipment null_weapon,null_armor,null_accessory;
class Base
{
protected:
    StatusEffect* status;
    std::string name;
    unsigned int HP=100;// 新增最大生命值
    unsigned int Attack=10;
    unsigned int Defense=10;
    unsigned int Money=10;
    unsigned int Speed=10;
    unsigned int Level=1;   
public:
        Base(const std::string& name, unsigned int HP, unsigned int Attack, unsigned int Defense, unsigned int Speed, unsigned int Money, unsigned int Level) {
        this->name = name;
        this->HP = HP;
        this->Attack = Attack;
        this->Defense = Defense;
        this->Speed = Speed;
        this->Money = Money;
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
        int get_Money() const { return Money; }
        int get_Level() const { return Level; }
        bool is_Alive() const { return HP > 0; }
        StatusEffect* getStatusEffect() const {return status;}
        //改变属性值
        void change_HP(int num1,double num2,unsigned int max_HP=1000000) {
            if(num1 >= 0){
                HP += num1; 
                HP =(int ) HP *num2; 
                if(HP > max_HP) HP = max_HP; 
            }
            if(num1 < 0){
                if(-num1>=HP){
                    HP = 0;
                } else {
                    HP += num1; 
                    HP =(int ) HP *num2; 
                }
            }
        }
        void change_Attack(int num1,double num2) { Attack += num1; Attack =(int) Attack *num2; }
        void change_Defense(int num1,double num2) { Defense += num1; Defense =(int) Defense *num2; }
        void change_Speed(int num) { Speed += num; }
        void change_Level(int num) { Level += num; }
        void change_Money(int num) { Money += num; }
        void reborn(double rate, unsigned int max_HP = 1000000) {
            this->HP=(int) rate*max_HP;
        };
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
    Backpack hero_backpack;
    Equipment_backpack equipment_backpack;
public:
    void show_info(Hero* hero);//展示英雄信息
    void change_Luck(int num) { Luck += num; };
    void equip(const Equipment* item) {
        switch (item->get_type()) {
            case EquipmentType::Weapon:
                if (weapon) weapon->remove_effect(this);
                weapon = item;
                break;
            case EquipmentType::Armor:
                if (armor) armor->remove_effect(this);
                armor = item;
                break;
            case EquipmentType::Accessory:
                if (accessory) accessory->remove_effect(this);
                accessory = item;
                break;
        }
        item->apply_effect(this);
    }
    //构造函数
    Hero(const std::string& name, unsigned int HP, unsigned int Attack, unsigned int Defense, unsigned int Speed, unsigned int Money, unsigned int Level, unsigned int Luck) : Base(name, HP, Attack, Defense, Speed, Money, Level) {
        this->Luck = Luck;
        this->weapon = &null_weapon;
        this->armor = &null_armor;
        this->accessory = &null_accessory;
    }
    Backpack* get_backpack() { return &this->hero_backpack; }
    Equipment_backpack* get_equipment_backpack() { return &this->equipment_backpack; }
    Equipment* get_weapon() const { return const_cast<Equipment*>(weapon); }
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
#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include "Hero_and_Monster.h"
#include "status.h"
class BaseItem {
    protected:
        std::string name;
        unsigned int num = 1;
        unsigned int price = 10; 
    public:
    BaseItem(const std::string& name, unsigned int num, unsigned int price) {
        this->name = name;
        this->num = num;
        this->price = price;
    }
    std::string get_name() const { return name; }
    unsigned int get_num() const { return num; }
    unsigned int get_price() const { return price; }
    virtual void use(Hero* hero) const = 0;
};
class Medicine: public BaseItem {
    public:
    Medicine(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {}
    void use(Hero* hero) const override {
        std::cout << "你使用了生命药水，恢复了10点生命值！" << std::endl;
        hero->change_HP(10);
    }
};
class IronMedicine: public BaseItem {
    public:
    IronMedicine(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {}
    void use(Hero* hero) const override {
        std::cout << "你使用了钢铁合剂，本回合增加了10点防御力！" << std::endl;
        hero->change_Defense(10);
    }
};
class AngryDrink: public BaseItem {
    public:
    AngryDrink(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {}
    void use(Hero* hero) const override {
        std::cout << "你使用了愤怒合剂，本回合增加了10攻击力！" << std::endl;
        hero->change_Attack(10);
    }
};
class Antidote: public BaseItem {    
    public:
    Antidote(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {}    
    // void use(StatusEffect* effect){
    //     std::cout << "你使用了解毒草，清除了自身的中毒效果！" << std::endl;
    //     effect->resetPoisoned();
    // }
    void use(Hero* hero) const override {
        std::cout << "你使用了解毒草，清除了自身的中毒效果！" << std::endl;
        hero->getStatusEffect()->resetPoisoned();
    }
};
class Antibiotic: public BaseItem {
    public:
    Antibiotic(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {}
    // void use(StatusEffect* effect) {
    //     std::cout << "你使用了惊惶木，清除了自身的睡眠效果！" << std::endl;
    //     effect->resetStunned();
    // }
    void use(Hero* hero) const override {
        std::cout << "你使用了惊惶木，清除了自身的睡眠效果！" << std::endl;
        hero->getStatusEffect()->resetStunned();
    }
};
class Poison: public BaseItem {
    public:
    Poison(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {}
    // void use(StatusEffect* effect) {
    //     std::cout << "你使用了淬毒镖，对方获得中毒效果！" << std::endl;
    //     effect->setPoisoned();
    // }
    void use(Hero* hero) const override {
        std::cout << "你使用了淬毒镖，对方获得中毒效果！" << std::endl;
        hero->getStatusEffect()->setPoisoned();
    }
};
class Stunned: public BaseItem {
    public:  
    Stunned(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {}
    // void use(StatusEffect* effect) {
    //     std::cout << "你使用了夜阑谣，对方获得睡眠效果！" << std::endl;
    //     effect->setStunned();
    // }
    void use(Hero* hero) const override {
        std::cout << "你使用了夜阑谣，对方获得睡眠效果！" << std::endl;
        hero->getStatusEffect()->setStunned();
    }
};
class Panacea: public BaseItem {
    public:
    Panacea(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {}
    // void use(Hero* hero, StatusEffect* effect) {
    //     std::cout << "你使用了万灵药，清除了自身的所有负面效果！" << std::endl;
    //     effect->resetAll();
    // }
    void use(Hero* hero) const override {
        std::cout << "你使用了万灵药，清除了自身的所有负面效果！" << std::endl;
        hero->getStatusEffect()->resetAll();
    }
};

#endif
#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include "status.h"
class Hero;
class Monster;
/*
index与item的对应关系：
1. 生命药水
2. 钢铁合剂
3. 愤怒合剂
4. 解毒草
5. 惊惶木
6. 淬毒镖
7. 夜阑谣
8. 万灵药
*/
class BaseItem {
    protected:
        std::string name;
        unsigned int num = 0;
        unsigned int price = 10;
        unsigned int index = 0;
    public:
    BaseItem(const std::string& name, unsigned int num, unsigned int price) {
        this->name = name;
        this->num = num;
        this->price = price;
    }
    std::string get_name() const { return name; }
    unsigned int get_num() const { return num; }
    unsigned int get_price() const { return price; }
    unsigned int get_index() const { return index; }
    void add_num() { this->num += 1; }
    void sub_num() { this->num -= 1; }
    void set_num(unsigned int num) { this->num = num; }
    virtual void use(Hero* hero, Monster* monster) const = 0;
};
class Medicine: public BaseItem {
    public:
    Medicine(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {this->index = 1;}
    void use(Hero* hero , Monster* monster) const override;
};
class IronMedicine: public BaseItem {
    public:
    IronMedicine(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {this->index = 2;}
    void use(Hero* hero, Monster* monster) const override;
};
class AngryDrink: public BaseItem {
    public:
    AngryDrink(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {this->index = 3;}
    void use(Hero* hero, Monster* monster) const override;
};
class Antidote: public BaseItem {    
    public:
    Antidote(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {this->index = 4;}
    void use(Hero* hero, Monster* monster) const override;
};
class Antibiotic: public BaseItem {
    public:
    Antibiotic(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {this->index = 5;}
    void use(Hero* hero, Monster* monster) const override;
};
class Poison: public BaseItem {
    public:
    Poison(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {this->index = 6;}
    void use(Hero* hero, Monster* monster) const override;
};
class Stunned: public BaseItem {
    public:  
    Stunned(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {this->index = 7;}
    void use(Hero* hero, Monster* monster) const override;
};
class Panacea: public BaseItem {
    public:
    Panacea(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {this->index = 8;}
    void use(Hero* hero, Monster* monster) const override;
};
class PhoenixFeather: public BaseItem {
    public:
    PhoenixFeather(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {this->index = 9;}
    void use(Hero* hero, Monster* monster) const override;
};
class NullItem: public BaseItem {
    public:
    NullItem(const std::string& name, unsigned int num, unsigned int price) : BaseItem(name, num, price) {this->index = 0;}
    void use(Hero* hero, Monster* monster) const override;
};
#endif
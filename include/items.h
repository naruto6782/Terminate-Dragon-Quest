#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include "Hero_and_Monster.h"
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
        std::cout << "你使用了血瓶，恢复了10点生命值！" << std::endl;
        hero->change_HP(10);
    }
};

#endif
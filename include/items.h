#pragma once
#include <iostream>
#include <functional>
#include "status.h"
class Hero;
class Monster;

class Item {
    private:
        std::function<void(Hero*, Monster*)> apply_func; // 使用效果
    public:
    Item(const std::string& name, unsigned int num, unsigned int price,int index = 0) : name(name), num(num), price(price), index(index) {
        if (num < 0) {
            std::cout << "物品数量不能为负，已设置为0。" << std::endl;
            this->num = 0;
        }
    }
    std::string name;
    unsigned int num = 0;
    unsigned int price = 10;
    unsigned int index = 0;
    void set_effect(std::function<void(Hero*, Monster*)> use) {
        apply_func = use;
    }
    void apply_effect(Hero* hero, Monster* monster) const {
        if (apply_func) apply_func(hero, monster);
    }
};

extern Item null_item;
extern Item medicine;
extern Item poison;
extern Item ironMedicine;
extern Item angryDrink;
extern Item antidote;
extern Item antibiotic;
extern Item stunned;
extern Item panacea;
extern Item phoenixFeather;

extern Item index_to_item(int index);
void init_items_effects();
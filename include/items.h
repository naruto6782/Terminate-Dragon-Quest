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
Item index_to_item(int index) {
    switch (index) {
        case 1:
            return medicine;
        case 2:
            return ironMedicine;
        case 3:
            return angryDrink;
        case 4:
            return antidote;
        case 5:
            return antibiotic;
        case 6:
            return poison;
        case 7:
            return stunned;
        case 8:
            return panacea;
        case 9:
            return phoenixFeather;
        default:
            return null_item; // 返回空物品
    }
}
Item null_item("Null", 0, 0, 0);
Item medicine("血瓶", 1, 100, 1);
Item poison("毒瓶", 1, 100,2);
Item ironMedicine("钢铁合剂", 1, 100, 3);
Item angryDrink("愤怒合剂", 1, 100, 4);
Item antidote("解毒草", 1, 100, 5);
Item antibiotic("惊惶木", 1, 100, 6);
Item stunned("夜阑谣", 1, 100, 7);
Item panacea("万灵药", 1, 100, 8);
Item phoenixFeather("凤凰羽翼", 1, 1000, 9);
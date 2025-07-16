#ifndef EQUIP_H
#define EQUIP_H

#include <string>
#include <iostream>

class Hero;

enum class EquipmentType {
    Weapon,
    Armor,
    Accessory
};

class Equipment {
private:
    EquipmentType type;
    std::string name;
    unsigned int num;
    unsigned int price;
    unsigned int index; // 用来区分同类不同装备

public:
    Equipment(EquipmentType type, const std::string& name, unsigned int num, unsigned int price, unsigned int index)
        : type(type), name(name), num(num), price(price), index(index) {}

    EquipmentType getType() const { return type; }
    std::string get_name() const { return name; }
    unsigned int get_num() const { return num; }
    unsigned int get_price() const { return price; }
    unsigned int get_index() const { return index; }

    // 装备行为，不再是虚函数，由 cpp 中 switch 实现
    void equip(Hero* hero) const;
};

#endif

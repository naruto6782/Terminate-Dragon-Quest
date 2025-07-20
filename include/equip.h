#pragma once
#include <string>
#include <functional>
#include <vector>
#include <random>
#include <ctime>
#include <iostream>
// 在 equip.h 中添加这些声明
class Hero;

enum class EquipmentType { Weapon, Armor, Accessory };

class Equipment {
private:
    EquipmentType type;
    std::string name;
    unsigned int num;
    unsigned int price;
    unsigned int index;
    std::function<void(Hero*)> apply_func;
    std::function<void(Hero*)> remove_func;
    int is_equipped = 0; // 0表示未装备，1表示已装备
public:
    Equipment(EquipmentType type, const std::string& name, unsigned int num, unsigned int price, unsigned int index)
        : type(type), name(name), num(num), price(price), index(index) {
            this->is_equipped=0;
        }

    void set_effect(std::function<void(Hero*)> apply, std::function<void(Hero*)> remove) {
        apply_func = apply;
        remove_func = remove;
    }

    void apply_effect(Hero* hero) const {
        if (apply_func) apply_func(hero);
    }

    void remove_effect(Hero* hero) const {
        if (remove_func) remove_func(hero);
    }
    EquipmentType get_type() const { return type; }
    std::string get_name() const { return name; }
    unsigned int get_index() const { return index; }
    unsigned int get_num() const { return num; }
    unsigned int get_price() const { return price; }
    void add_num(unsigned int num) {
        this->num += num;
        if (this->num < 0) {
            std::cout << "物品数量不能为负，已设置为0。" << std::endl;
            this->num = 0;
        }
    }
    int get_is_equipped() const { return is_equipped; }
    void change_is_equipped() {
        if(is_equipped == 0) {
            is_equipped = 1; // 装备
        } else {
            is_equipped = 0; // 卸下
        }
    }
    Equipment* clone() const {
        Equipment* copy = new Equipment(type, name, num, price, index);
        copy->set_effect(apply_func, remove_func);
        return copy;
    }
};
extern Equipment null_weapon;
extern Equipment null_armor;
extern Equipment null_accessory;

extern Equipment silver_spear;
extern Equipment storm_blade;
extern Equipment cursed_blade;
extern Equipment poisoned_blade;
extern Equipment moon_blade;
extern Equipment flower_blade;

extern Equipment defense_shield;
extern Equipment brave_shield;
extern Equipment shadow_shield;
extern Equipment soul_shield;

extern Equipment brave_amulet;
extern Equipment life_stone;
extern Equipment xiangnang;
extern Equipment universe_glow;
extern Equipment s_cape;
extern Equipment gold_necklace;
extern Equipment jinchanchan;

extern Equipment index_to_equipment(int index);

void init_equipment_effects();
std::string type_to_string(EquipmentType type);
Equipment* get_random_equipment(const std::vector<std::pair<Equipment*, double>>& drop_pool);
Equipment drop_equipment_easy();
Equipment drop_equipment_medium();
Equipment drop_equipment_hard();




#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <string>
#include <functional>
#include <vector>
#include <random>
#include <ctime>
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


public:
    Equipment(EquipmentType type, const std::string& name, unsigned int num, unsigned int price, unsigned int index)
        : type(type), name(name), num(num), price(price), index(index) {}

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
};


Equipment* get_random_equipment(const std::vector<std::pair<Equipment*, double>>& drop_pool);
void drop_equipment_easy();
void drop_equipment_medium();
void drop_equipment_hard();


#endif
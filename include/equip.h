#pragma once
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
Equipment index_to_equipment(int index) {
    switch (index) {
        case 1: return silver_spear;
        case 2: return storm_blade;
        case 3: return cursed_blade;
        case 4: return poisoned_blade;
        case 5: return moon_blade;
        case 6: return flower_blade;
        case 7: return defense_shield;
        case 8: return brave_shield;
        case 9: return shadow_shield;
        case 10: return soul_shield;
        case 11: return brave_amulet;
        case 12: return life_stone;
        case 13: return xiangnang;
        case 14: return universe_glow;
        case 15: return s_cape;
        case 16: return gold_necklace;
        case 17: return jinchanchan;
        default: return null_weapon; // 返回空武器
    }
}


Equipment* get_random_equipment(const std::vector<std::pair<Equipment*, double>>& drop_pool);
Equipment drop_equipment_easy();
Equipment drop_equipment_medium();
Equipment drop_equipment_hard();


Equipment null_weapon(EquipmentType::Weapon, "空", 0, 0, 0);
Equipment null_armor(EquipmentType::Armor, "空", 0, 0, 0);
Equipment null_accessory(EquipmentType::Accessory, "空", 0, 0, 0);
Equipment silver_spear(EquipmentType::Weapon, "秘银剑", 1, 100, 1);//加10攻击力
Equipment storm_blade(EquipmentType::Weapon, "暴风大剑", 1, 100, 2);//加30攻击力，速度降低20
Equipment cursed_blade(EquipmentType::Weapon, "诅咒之刃", 1, 100, 3);//加20攻击力，幸运降低10
Equipment poisoned_blade(EquipmentType::Weapon, "淬毒刃", 1, 100, 4);//加5攻击力，战斗时给对方附加中毒效果
Equipment moon_blade(EquipmentType::Weapon, "月影双刃", 1, 100, 5);//减5攻击力，一回合可以攻击两次
Equipment flower_blade(EquipmentType::Weapon, "花无十日红", 1, 100, 6);//加20攻击力，2倍率，每回合提升0.2倍率
Equipment defense_shield(EquipmentType::Armor, "军团圣盾", 1, 100, 1);//加10防御
Equipment brave_shield(EquipmentType::Armor, "狂战士之甲", 1, 100, 2);//加5防御，每回合加2防御
Equipment shadow_shield(EquipmentType::Armor, "影织衣", 1, 100, 3);//加5防御，加10速度，加10运气
Equipment soul_shield(EquipmentType::Armor, "镇魂重甲", 1, 100, 4);//加30防御
Equipment brave_amulet(EquipmentType::Accessory, "勇者护符", 1, 100, 1);//加10攻击10防御
Equipment life_stone(EquipmentType::Accessory, "生命宝石", 1, 100, 2);//加50最大生命值
Equipment xiangnang(EquipmentType::Accessory, "忘忧香囊", 1, 100, 3);//免疫负面效果
Equipment universe_glow(EquipmentType::Accessory, "宇宙之辉", 1, 100, 4);//每回合回复30生命
Equipment s_cape(EquipmentType::Accessory, "灵光披风", 1, 100, 5);//加10速度加10幸运
Equipment gold_necklace(EquipmentType::Accessory, "金币护符", 1, 100, 6);//每回合结束加5金币
Equipment jinchanchan(EquipmentType::Accessory, "金铲铲", 1, 100, 7);//buff全部增加

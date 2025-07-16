#include "equip.h"
#include "Hero_and_Monster.h"
#include <iostream>

// 分发到 Hero 的接口
static void equipWeapon(Hero* hero,Equipment* eq);
static void equipArmor(Hero* hero,Equipment* eq);
static void equipAccessory(Hero* hero,Equipment* eq);

// 主调度函数
void Equipment::equip(Hero* hero) const {
    switch (type) {
        case EquipmentType::Weapon:
            hero->equip_Weapon(this);
            break;
        case EquipmentType::Armor:
            hero->equip_Armor(this);
            break;
        case EquipmentType::Accessory:
            hero->equip_Accessory(this);
            break;
        default:
            std::cerr << "未知装备类型！" << std::endl;
    }
}

// 武器效果
static void equipWeapon(Hero* hero,Equipment* eq) {
    hero->unequip_Weapon();
    hero->set_weapon(eq);
    std::cout << eq->get_name() << " 已装备（武器）！" << std::endl;

    // 可根据 index 决定效果
    switch (eq->get_index()) {
        case 1: hero->change_Attack(10); break;//对称长枪（普通武器）
        case 2: hero->change_Attack(30); hero->change_Speed(-20);break;//暴风大剑（高额伤害，但是会降低速度）
        case 3: hero->change_Attack(20); hero->change_Luck(-30);break;//诅咒之刃（提升伤害的同时降低运气）
        case 4: hero->change_Attack(10); break;//（提高暴击率，目前无法使用）
        case 5: hero->change_Attack(-5); break;//月影双刃（一回合可以攻击两次）
        case 6: hero->change_Attack(10); break;//花无十日红（增加暴击率，每进行一次攻击增加5点攻击力）
        default: break;
    }
}

// 防具效果
static void equipArmor(Hero* hero, Equipment* eq) {
    hero->unequip_Armor();
    hero->set_armor(eq);
    std::cout << eq->get_name() << " 已装备（防具）！" << std::endl;

    switch (eq->get_index()) {
        case 1: hero->change_Defense(10); break;//军团圣盾（普通护甲）
        case 2: hero->change_Defense(5); hero->change_Speed(10); break;//流云铠(加少量防御，提升速度)
        case 3: hero->change_Defense(10); break;//daiding
        case 4: hero->change_Defense(10); break;//daiding
        default: break;
    }
}

// 饰品效果
static void equipAccessory(Hero* hero, Equipment* eq) {
    hero->unequip_Accessory();
    hero->set_accessory(eq);
    std::cout << eq->get_name() << " 已装备（饰品）！" << std::endl;

    switch (eq->get_index()) {
        case 1: // Amulet
            hero->change_Defense(10);break;
        case 2: // Cape
            hero->change_Speed(10);break;
        case 3: // Ring
            hero->change_Luck(10);break;
        case 4: // Necklace
            hero->change_Attack(10);break;
        case 5: // Bracelet
            hero->change_Defense(10);break;
        case 6: // Earrings
            hero->change_Attack(10);break;
        case 7: // Pendant
            hero->change_Defense(10);break;
        case 8: // Brooch
            hero->change_Luck(10);break;
        default: break;
    }
}

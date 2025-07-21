#include "equip.h"
#include "Hero_and_Monster.h"
#include <iostream>


void init_equipment_effects() {
    
    silver_spear.set_effect(//秘银剑
        [](Hero* h){ h->change_Attack(5,1.0);},
        [](Hero* h){ h->change_Attack(-5,1.0); });
    
    storm_blade.set_effect(//暴风大剑
        [](Hero* h){ h->change_Attack(20,1.0); h->change_Speed(-10); },
        [](Hero* h){ h->change_Attack(-20,1.0); h->change_Speed(10); });

    cursed_blade.set_effect(//诅咒之刃
        [](Hero* h){ h->change_Attack(15,1.0); h->change_Luck(-10); },
        [](Hero* h){ h->change_Attack(-15,1.0); h->change_Luck(10); });

    poisoned_blade.set_effect(//淬毒刃
        [](Hero* h){ h->change_Attack(5,1.0); },
        [](Hero* h){ h->change_Attack(-5,1.0); });

    moon_blade.set_effect(//月影双刃
        [](Hero* h){ h->change_Attack(-5,1.0); },
        [](Hero* h){ h->change_Attack(5,1.0); });

    flower_blade.set_effect(//花无十日红
        [](Hero* h){ h->change_Attack(10,2.0); },
        [](Hero* h){ h->change_Attack(-10,0.5); });

    defense_shield.set_effect(//军团圣盾
        [](Hero* h){ h->change_Defense(5,1.0);  },
        [](Hero* h){ h->change_Defense(-5,1.0); });
    
    brave_shield.set_effect(//狂战士之甲
        [](Hero* h){ h->change_Defense(5,1.5); h->change_HP(40,1.0);  },
        [](Hero* h){ h->change_Defense(-5,1.5); h->change_HP(-40,1.0); });

    shadow_shield.set_effect(//影织衣
        [](Hero* h){ h->change_Defense(5,1.0); h->change_Speed(10); h->change_Luck(10);  },
        [](Hero* h){ h->change_Defense(-5,1.0); h->change_Speed(-10); h->change_Luck(-10); });

    soul_shield.set_effect(//镇魂重甲
        [](Hero* h){ h->change_Defense(30,1.0); h->change_HP(30,1.0);  },
        [](Hero* h){ h->change_Defense(-30,1.0); h->change_HP(-30,1.0); });

    brave_amulet.set_effect(//勇者护符
        [](Hero* h){ h->change_Attack(5,1.0); h->change_Defense(5,1.0); },
        [](Hero* h){ h->change_Attack(-5,1.0); h->change_Defense(-5,1.0); });

    life_stone.set_effect(//生命宝石
        [](Hero* h){ h->change_HP(60,1.0); },
        [](Hero* h){ h->change_HP(-60,1.0); });

    s_cape.set_effect(//灵光披风    
        [](Hero* h){ h->change_Speed(10); h->change_Luck(10); },
        [](Hero* h){ h->change_Speed(-10); h->change_Luck(-10); });

    gold_necklace.set_effect(//金币护符
        [](Hero* h){},
        [](Hero* h){});
    
    universe_glow.set_effect(//宇宙之辉
        [](Hero* h){},
        [](Hero* h){});    

    jinchanchan.set_effect(//金铲铲
        [](Hero* h){ h->change_Attack(30,1.0); h->change_Defense(30,1.0); h->change_Speed(30); h->change_Luck(30); },
        [](Hero* h){ h->change_Attack(-30,1.0); h->change_Defense(-30,1.0); h->change_Speed(-30); h->change_Luck(-30); });

}

// 装备指针池（你可以按类型区分：武器、护甲、饰品）
std::vector<std::pair<Equipment*, double>> easy_drops = {
    {&silver_spear, 6.0},
    {&cursed_blade, 3.0},
    {&storm_blade, 1.5},
    {&defense_shield, 6.0},
    {&brave_shield, 3.0},
    {&brave_amulet, 6.0},
    {&life_stone,3.0},
    {&shadow_shield,1.5},
    {&universe_glow, 1.5},
    {&gold_necklace, 1.5},
    {&jinchanchan, 0.5}
};

std::vector<std::pair<Equipment*, double>> medium_drops = {
    {&cursed_blade, 6.0},
    {&storm_blade, 3.0},
    {&brave_shield, 6.0},
    {&shadow_shield,3.0},
    {&life_stone,6.0},
    {&s_cape,3.0},
    {&universe_glow, 3.0},
    {&gold_necklace, 3.0},
    {&jinchanchan, 0.5}
};

std::vector<std::pair<Equipment*, double>> hard_drops = {
    {&storm_blade, 6.0},
    {&shadow_shield, 6.0},
    {&soul_shield, 3.0},
    {&s_cape,6.0},
    {&universe_glow, 6.0},
    {&gold_necklace, 6.0},
    {&jinchanchan, 0.5}
};

std::vector<std::pair<Equipment*, double>> selen_drops = {
    {&poisoned_blade, 1.5}
};

std::vector<std::pair<Equipment*, double>> fire_drops = {
    {&moon_blade, 6.0}
};

std::vector<std::pair<Equipment*, double>> final_drops = {
    {&flower_blade, 6.0}
};

// 返回一个随机掉落的装备指针
Equipment* get_random_equipment(const std::vector<std::pair<Equipment*, double>>& drop_pool) {
    double total_weight = 0;
    for (auto& p : drop_pool) total_weight += p.second;

    double rand_weight = ((double)rand() / RAND_MAX) * total_weight;
    double accumulated = 0;

    for (auto& p : drop_pool) {
        accumulated += p.second;
        if (rand_weight <= accumulated)
            return p.first;
    }

    return nullptr; // fallback
}


Equipment drop_equipment_easy() {
    Equipment* drop = nullptr;
            drop = get_random_equipment(easy_drops);
    if (drop) {
        std::cout << "你获得了装备：" << drop->get_name() << std::endl;
        // hero->equip(drop);
    }
    return Equipment(*drop); // 返回装备的副本
}

Equipment drop_equipment_medium() {
    Equipment* drop = nullptr;
            drop = get_random_equipment(medium_drops);
    if (drop) {
        std::cout << "你获得了装备：" << drop->get_name() << std::endl;
        // hero->equip(drop);
    }
    return Equipment(*drop);
}

Equipment drop_equipment_hard() {
    Equipment* drop = nullptr;
            drop = get_random_equipment(hard_drops);
    if (drop) {
        std::cout << "你获得了装备：" << drop->get_name() << std::endl;
        // hero->equip(drop);
    }
    return Equipment(*drop);
}

Equipment drop_equipment_selen() {
    Equipment* drop = nullptr;
            drop = get_random_equipment(selen_drops);
    if (drop) {
        std::cout << "你获得了装备：" << drop->get_name() << std::endl;
        // hero->equip(drop);
    }
    return Equipment(*drop);
}

Equipment drop_equipment_fire() {
    Equipment* drop = nullptr;
            drop = get_random_equipment(fire_drops);
    if (drop) {
        std::cout << "你获得了装备：" << drop->get_name() << std::endl;
        // hero->equip(drop);
    }
    return Equipment(*drop);
}

Equipment drop_equipment_final() {
    Equipment* drop = nullptr;
            drop = get_random_equipment(final_drops);
    if (drop) {
        std::cout << "你获得了装备：" << drop->get_name() << std::endl;
        // hero->equip(drop);
    }
    return Equipment(*drop);
}


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
        case 13: return universe_glow;
        case 14: return s_cape;
        case 15: return gold_necklace;
        case 16: return jinchanchan;
        default: return null_weapon; // 返回空武器
    }
}
std::string type_to_string(EquipmentType type) {
    switch (type) {
        case EquipmentType::Weapon: return "Weapon";
        case EquipmentType::Armor: return "Armor";
        case EquipmentType::Accessory: return "Accessory";
        default: return "Unknown";
    }
}
Equipment null_weapon(EquipmentType::Weapon, "空", 0, 0, 0);
Equipment null_armor(EquipmentType::Armor, "空", 0, 0, 0);
Equipment null_accessory(EquipmentType::Accessory, "空", 0, 0, 0);
Equipment silver_spear(EquipmentType::Weapon, "秘银剑（攻击+5）", 1, 100, 1);//加5攻击力
Equipment storm_blade(EquipmentType::Weapon, "暴风大剑（攻击+20，速度-10）", 1, 100, 2);//加20攻击力，速度降低10
Equipment cursed_blade(EquipmentType::Weapon, "诅咒之刃（攻击+15，幸运-10）", 1, 100, 3);//加15攻击力，幸运降低10
Equipment poisoned_blade(EquipmentType::Weapon, "淬毒刃（攻击+5，战斗时给对方施加中毒效果）", 1, 100, 4);//加5攻击力，战斗时给对方附加中毒效果
Equipment moon_blade(EquipmentType::Weapon, "月影双刃（攻击-5，一回合可攻击两次）", 1, 100, 5);//减5攻击力，一回合可以攻击两次
Equipment flower_blade(EquipmentType::Weapon, "花无十日红（攻击+10，倍率×2，可造成对方最大生命值15%的伤害）", 1, 100, 6);//加10攻击力，2倍率，造成怪兽最大生命值15%的伤害
Equipment defense_shield(EquipmentType::Armor, "军团圣盾（防御+5）", 1, 100, 7);//加5防御
Equipment brave_shield(EquipmentType::Armor, "狂战士之甲（防御+5，生命+40）", 1, 100, 8);//加5防御，40生命
Equipment shadow_shield(EquipmentType::Armor, "影织衣（防御+5，速度+10，幸运+10）", 1, 100, 9);//加5防御，加10速度，加10运气
Equipment soul_shield(EquipmentType::Armor, "镇魂重甲（防御+30，生命+30）", 1, 100, 10);//加30防御，30生命
Equipment brave_amulet(EquipmentType::Accessory, "勇者护符（攻击+5，防御+5）", 1, 100, 11);//加5攻击5防御
Equipment life_stone(EquipmentType::Accessory, "生命宝石（生命+60）", 1, 100, 12);//加60最大生命值
Equipment universe_glow(EquipmentType::Accessory, "宇宙之辉（每回合结束回复30生命）", 1, 100, 13);//每回合回复20生命
Equipment s_cape(EquipmentType::Accessory, "灵光披风（速度+10，幸运+10）", 1, 100, 14);//加10速度加10幸运
Equipment gold_necklace(EquipmentType::Accessory, "金币护符（每回合结束增加10金币）", 1, 100, 15);//每回合结束加10金币
Equipment jinchanchan(EquipmentType::Accessory, "金铲铲（隐藏彩蛋装备！全属性增加！快来装备吧！）", 1, 100, 16);//buff全部增加
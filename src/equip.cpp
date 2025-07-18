#include "equip.h"
#include "Hero_and_Monster.h"
#include <iostream>

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

void init_equipment_effects() {
    
    silver_spear.set_effect(//秘银剑
        [](Hero* h){ h->change_Attack(10,1.0); },
        [](Hero* h){ h->change_Attack(-10,1.0); });
    
    storm_blade.set_effect(//暴风大剑
        [](Hero* h){ h->change_Attack(30,1.0); h->change_Speed(-20); },
        [](Hero* h){ h->change_Attack(-30,1.0); h->change_Speed(20); });

    cursed_blade.set_effect(//诅咒之刃
        [](Hero* h){ h->change_Attack(20,1.0); h->change_Luck(-10); },
        [](Hero* h){ h->change_Attack(-20,1.0); h->change_Luck(10); });

    poisoned_blade.set_effect(//淬毒刃
        [](Hero* h){ h->change_Attack(10,1.0); },
        [](Hero* h){ h->change_Attack(-10,1.0); });

    moon_blade.set_effect(//月影双刃
        [](Hero* h){ h->change_Attack(5,1.0); },
        [](Hero* h){ h->change_Attack(-5,1.0); });

    flower_blade.set_effect(//花无十日红
        [](Hero* h){ h->change_Attack(10,2.0); },
        [](Hero* h){ h->change_Attack(-10,2.0); });

    defense_shield.set_effect(//军团圣盾
        [](Hero* h){ h->change_Defense(10,1.0);  },
        [](Hero* h){ h->change_Defense(-10,1.0); });
    
    brave_shield.set_effect(//狂战士之甲
        [](Hero* h){ h->change_Defense(5,1.0);  },
        [](Hero* h){ h->change_Defense(-5,1.0); });

    shadow_shield.set_effect(//影织衣
        [](Hero* h){ h->change_Defense(5,1.0); h->change_Speed(10); h->change_Luck(10);  },
        [](Hero* h){ h->change_Defense(-5,1.0); h->change_Speed(-10); h->change_Luck(-10); });

    soul_shield.set_effect(//镇魂重甲
        [](Hero* h){ h->change_HP(100,1.0);  },
        [](Hero* h){ h->change_HP(-100,1.0); });

    brave_amulet.set_effect(//勇者护符
        [](Hero* h){ h->change_Attack(5,1.0); h->change_Defense(5,1.0); },
        [](Hero* h){ h->change_Attack(-5,1.0); h->change_Defense(-5,1.0); });

    // life_stone.set_effect(//生命宝石(待定)
    //     [](Hero* h){ h->change_HP(50,1.0,1000000); },
    //     [](Hero* h){ h->change_HP(-50,1.0,1000000); });

    xiangnang.set_effect(//忘忧香囊
        [](Hero* h){ h->getStatusEffect()->resetAll(); },
        [](Hero* h){ h->getStatusEffect()->resetAll(); });

    // universe_glow.set_effect(//宇宙之辉（待定）
    //     [](Hero* h){ h->change_HP(30,1.0,1000000); },
    //     [](Hero* h){ h->change_HP(-30,1.0,1000000); });

    s_cape.set_effect(//灵光披风    
        [](Hero* h){ h->change_Speed(10); h->change_Luck(10); },
        [](Hero* h){ h->change_Speed(-10); h->change_Luck(-10); });

    // gold_necklace.set_effect(//金币护符（待定）
    //     [](Hero* h){ h->change_Money(5); },
    //     [](Hero* h){ h->change_Money(-5); });

    jinchanchan.set_effect(//金铲铲
        [](Hero* h){ h->change_Attack(30,1.0); h->change_Defense(30,1.0); h->change_Speed(30); h->change_Luck(30); },
        [](Hero* h){ h->change_Attack(-30,1.0); h->change_Defense(-30,1.0); h->change_Speed(-30); h->change_Luck(-30); });

}



// 装备指针池（你可以按类型区分：武器、护甲、饰品）
std::vector<std::pair<Equipment*, double>> easy_drops = {
    {&silver_spear, 6.0},
    {&defense_shield, 6.0},
    {&brave_amulet, 6.0},
    {&storm_blade, 3.0},
    {&cursed_blade, 4.0},
    {&brave_shield, 3.0},
    {&life_stone,3.0},
    {&poisoned_blade, 1.5},
    {&shadow_shield,1.5},
    {&universe_glow, 1.5},
    {&jinchanchan, 0.5}
};

std::vector<std::pair<Equipment*, double>> medium_drops = {
    {&storm_blade, 6.0},
    {&cursed_blade, 6.0},
    {&brave_shield, 6.0},
    {&xiangnang, 6.0},
    {&moon_blade, 1.5},
    {&brave_shield, 3.0},
    {&s_cape,3.0},
    {&xiangnang,3.0},
    {&gold_necklace, 2.0},
    {&poisoned_blade, 1.5},
    {&shadow_shield,1.5},
    {&soul_shield, 1.0},
    {&universe_glow, 1.5},
    {&flower_blade, 1.0},
    {&jinchanchan, 0.5}
};

std::vector<std::pair<Equipment*, double>> hard_drops = {
    {&cursed_blade, 6.0},
    {&brave_shield, 6.0},
    {&moon_blade, 4.5},
    {&brave_shield, 6.0},
    {&s_cape,6.0},
    {&xiangnang,3.0},
    {&gold_necklace, 6.0},
    {&poisoned_blade, 6.0},
    {&shadow_shield,4.5},
    {&soul_shield, 3.0},
    {&flower_blade, 3.0},
    {&jinchanchan, 0.5}
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


void drop_equipment_easy() {
    Equipment* drop = nullptr;
            drop = get_random_equipment(easy_drops);
    if (drop) {
        std::cout << "你获得了装备：" << drop->get_name() << std::endl;
        // hero->equip(drop);
    }
}

void drop_equipment_medium() {
    Equipment* drop = nullptr;
            drop = get_random_equipment(medium_drops);
    if (drop) {
        std::cout << "你获得了装备：" << drop->get_name() << std::endl;
        // hero->equip(drop);
    }
}

void drop_equipment_hard() {
    Equipment* drop = nullptr;
            drop = get_random_equipment(hard_drops);
    if (drop) {
        std::cout << "你获得了装备：" << drop->get_name() << std::endl;
        // hero->equip(drop);
    }
}

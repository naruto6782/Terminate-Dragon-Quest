#include "equip.h"
#include "Hero_and_Monster.h"
#include <iostream>


void init_equipment_effects() {
    
    silver_spear.set_effect(//秘银剑
        [](Hero* h){ h->change_Attack(10,1.0);},
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

    xiangnang.set_effect(//忘忧香囊
        [](Hero* h){ h->getStatusEffect()->resetAll(); },
        [](Hero* h){ h->getStatusEffect()->resetAll(); });

    s_cape.set_effect(//灵光披风    
        [](Hero* h){ h->change_Speed(10); h->change_Luck(10); },
        [](Hero* h){ h->change_Speed(-10); h->change_Luck(-10); });

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



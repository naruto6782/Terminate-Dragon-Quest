#include "equip.h"
#include "Hero_and_Monster.h"
#include <iostream>


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

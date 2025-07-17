#include "equip.h"
#include "Hero_and_Monster.h"
#include <iostream>

Equipment null_weapon(EquipmentType::Weapon, "空", 0, 0, 0);
Equipment null_armor(EquipmentType::Armor, "空", 0, 0, 0);
Equipment null_accessory(EquipmentType::Accessory, "空", 0, 0, 0);
Equipment silver_spear(EquipmentType::Weapon, "秘银剑", 10, 100, 1);//普通武器
Equipment storm_blade(EquipmentType::Weapon, "暴风大剑", 10, 100, 2);//高额伤害，但是会降低速度
Equipment cursed_blade(EquipmentType::Weapon, "诅咒之刃", 10, 100, 3);//提升伤害的同时降低运气
Equipment poisoned_blade(EquipmentType::Weapon, "淬毒刃", 10, 100, 4);//战斗时给对方附加中毒效果
Equipment moon_blade(EquipmentType::Weapon, "月影双刃", 10, 100, 5);//一回合可以攻击两次
Equipment flower_blade(EquipmentType::Weapon, "花无十日红", 10, 100, 6);//每回合提升0.2倍率
Equipment defense_shield(EquipmentType::Armor, "军团圣盾", 10, 100, 1);//普通护甲
Equipment brave_shield(EquipmentType::Armor, "狂战士之甲", 10, 100, 2);//每回合加2防御
Equipment shadow_shield(EquipmentType::Armor, "影织衣", 10, 100, 3);//提升速度和幸运从而提高闪避几率
Equipment soul_shield(EquipmentType::Armor, "镇魂重甲", 10, 100, 4);//数值怪
Equipment brave_amulet(EquipmentType::Accessory, "勇者护符", 10, 100, 1);
Equipment life_stone(EquipmentType::Accessory, "生命宝石", 10, 100, 2);

void init_equipment_effects() {
    
    silver_spear.set_effect(
        [](Hero* h){ h->change_Attack(10,1.0); },
        [](Hero* h){ h->change_Attack(-10,1.0); });

    storm_blade.set_effect(
        [](Hero* h){ h->change_Attack(30,1.0); h->change_Speed(-20); },
        [](Hero* h){ h->change_Attack(-30,1.0); h->change_Speed(20); });

    defense_shield.set_effect(
        [](Hero* h){ h->change_Defense(10,1.0);  },
        [](Hero* h){ h->change_Defense(-10,1.0); });
    brave_shield.set_effect(
        [](Hero* h){ h->change_Attack(20,1.0); h->change_Luck(-30); },
        [](Hero* h){ h->change_Attack(-20,1.0); h->change_Luck(30); });

    brave_amulet.set_effect(
        [](Hero* h){ h->change_Attack(5,1.0); h->change_Defense(5,1.0); },
        [](Hero* h){ h->change_Attack(-5,1.0); h->change_Defense(-5,1.0); });
}


// // 主调度函数
// void Equipment::equip(Hero* hero) const {
//     switch (type) {
//         case EquipmentType::Weapon:
//             hero->equip_Weapon(this);
//             break;
//         case EquipmentType::Armor:
//             hero->equip_Armor(this);
//             break;
//         case EquipmentType::Accessory:
//             hero->equip_Accessory(this);
//             break;
//         default:
//             std::cerr << "未知装备类型！" << std::endl;
//     }
// }

// 武器效果
// static void equipWeapon(Hero* hero,Equipment* eq) {
//     hero->unequip_Weapon();
//     hero->set_weapon(eq);
//     std::cout << eq->get_name() << " 已装备！" << std::endl;

//     // 可根据 index 决定效果
//     switch (eq->get_index()) {
//         case 1: hero->change_Attack(10,1.0); break;//对称长枪（普通武器）
//         case 2: hero->change_Attack(30,1.0); hero->change_Speed(-20);break;//暴风大剑（高额伤害，但是会降低速度）
//         case 3: hero->change_Attack(20,1.0); hero->change_Luck(-30);break;//诅咒之刃（提升伤害的同时降低运气）
//         case 4: hero->change_Attack(10,1.0); break;//淬毒刃（战斗时给对方附加中毒效果）需要制作
//         case 5: hero->change_Attack(-5,1.0); break;//月影双刃（一回合可以攻击两次）需要制作
//         case 6: hero->change_Attack(10,2); break;//花无十日红（每回合提升0.2倍率）需要制作
//         default: break;
//     }
// }

// 防具效果
// static void equipArmor(Hero* hero, Equipment* eq) {
//     hero->unequip_Armor();
//     hero->set_armor(eq);
//     std::cout << eq->get_name() << " 已装备！" << std::endl;

//     switch (eq->get_index()) {
//         case 1: hero->change_Defense(10,1.0); break;//军团圣盾（普通护甲）
//         case 2: hero->change_Defense(5,1.0); break;//狂战士之甲（每回合加2防御）
//         case 3: hero->change_Defense(5,1.0); hero->change_Speed(10);hero->change_Luck(10);break;//影织衣（提升速度和幸运从而提高闪避几率）
//         case 4: hero->change_Defense(30,1.0); break;//镇魂重甲（数值高）
//         default: break;
//     }
// }

// 饰品效果
// static void equipAccessory(Hero* hero, Equipment* eq) {
//     hero->unequip_Accessory();
//     hero->set_accessory(eq);
//     std::cout << eq->get_name() << " 已装备！" << std::endl;

//     switch (eq->get_index()) {
//         case 1: //勇者护符（加攻击力和防御力）
//             hero->change_Attack(10,1.0);hero->change_Defense(10,1.0);break;
//         case 2: //灵光披风（加速度和运气）
//             hero->change_Speed(10);hero->change_Luck(10);break;
//         case 3: //生命宝石（加最大生命）
//             hero->change_HP(100,1.0);break;
//         case 4: //忘忧香囊（免疫负面效果）
//             hero->getStatusEffect()->resetAll();break;
//         case 5: //行动点装备
//             break;
//         case 6: //宇宙之辉（每回合回复30生命值）
//             break;
//         case 7: //金币护符（每回合结束加5金币）
//             hero->change_Money(0);break;
//         case 8: //凤凰羽毛
//             hero->reborn(0.3);break;
//         default: break;
//     }
// }

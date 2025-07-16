#include <iostream>
#include <string>
#include "game.h"
#include "Hero_and_Monster.h"
#include "items.h"
#include "status.h"
#include "equip.h"
using namespace std;

int main() {
    Hero hero("scene_color", 100,10,101,10,10,1);
    hero.show_info(&hero);
    Equipment equipment(EquipmentType::Weapon, "暴风大剑", 10, 100, 3);
    Equipment wwwww(EquipmentType::Armor, "流云铠甲", 10, 100, 2);
    Equipment eeeee(EquipmentType::Accessory, "1111", 10, 100, 2);
    hero.equip_Accessory(&eeeee);
    hero.equip_Weapon(&equipment);
    hero.equip_Armor(&wwwww);
    hero.show_info(&hero);
    hero.print_Equipped();
    // hero.setStatusEffect(&hero_status);
    // hero.show_info(&hero);
    // Medicine medicine("haha", 10, 100);
    // Antidote antidote("hehe", 10, 100);
    // Antibiotic antibiotic("lala", 10, 100);
    // Poison poison("hehe", 10, 100);
    // Stunned stunned("lala", 10, 100);
    // Panacea panacea("lala", 10, 100);
    // medicine.use(&hero);
    // hero.show_info(&hero);
    // poison.use(&hero);
    // stunned.use(&hero);
    // hero.show_info(&hero);
    // antibiotic.use(&hero);
    // antidote.use(&hero);
    //饰品的装载
    return 0;
}
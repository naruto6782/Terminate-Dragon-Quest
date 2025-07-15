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
    Amulet HUFU("hupu",1,100);
    hero.setAccessory(&HUFU);
    HUFU.equip(&hero);
    StatusEffect hero_status;
    hero.setStatusEffect(&hero_status);
    hero.show_info(&hero);
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
    hero.show_info(&hero);
    //饰品的装载
    return 0;
}
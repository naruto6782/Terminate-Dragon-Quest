#include <iostream>
#include <string>
#include "game.h"
#include "Hero_and_Monster.h"
#include "items.h"
#include "status.h"
#include "equip.h"
#include "battle.h"
using namespace std;

int main() {
    Hero hero("wakaka", 100,10,101,10,10,1);
    Amulet HUFU("hupu",1,100);
    hero.getStatusEffect()->resetAll();
    hero.setAccessory(&HUFU);
    Monster monster("monster",100,10,0,10,10);
    monster.getStatusEffect()->resetAll();
    monster.setAccessory(&HUFU);
    Battle battle(&hero,&monster);
    battle.show_battle();
    battle.Hero_turn();
    battle.show_battle();

    //饰品的装载
    return 0;
}
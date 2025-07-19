#include <iostream>
#include <string>
#include "game.h"
#include "Hero_and_Monster.h"
#include "items.h"
#include "status.h"
#include "equip.h"
#include "battle.h"
#include "backpack.h"
#include "maze.h"
using namespace std;
extern Equipment poisoned_blade;
int main() {
    Game game;
    init_items_effects();
    init_equipment_effects();
    Hero hero("",100,50,10,10,50000,1,30);
    hero.get_equipment_backpack()->add_equipment(poisoned_blade);
    game.menu2(&hero);
    return 0;
}
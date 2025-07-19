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
    Hero hero("haha",100,2,10,10,50,1,30);
    hero.get_equipment_backpack()->add_equipment(poisoned_blade);
    game.menu2(&hero);
    return 0;
}
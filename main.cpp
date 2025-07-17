#include <iostream>
#include <string>
#include "game.h"
#include "Hero_and_Monster.h"
#include "items.h"
#include "status.h"
#include "equip.h"
#include "battle.h"
#include "backpack.h"
using namespace std;

int main() {
    Game game;
    Hero hero("haha",100,10,10,10,200,1,30);
    game.menu2(&hero);
    return 0;
}
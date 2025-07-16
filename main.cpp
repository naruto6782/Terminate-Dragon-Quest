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
    game.init(&game);
    return 0;
}
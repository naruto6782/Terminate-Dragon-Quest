#include <iostream>
#include <string>
#include "game.h"
#include "Hero_and_Monster.h"
#include "items.h"
#include "status.h"
using namespace std;

int main() {
    Hero hero("scene_color", 100,10,101,10,10,1);
    hero.show_info(&hero);
    Medicine medicine("haha", 10, 100);
    medicine.use(&hero);
    hero.show_info(&hero);
    return 0;
}
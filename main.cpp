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
    Hero hero("wakaka", 100,10,101,10,10,1);
    Amulet HUFU("hupu",1,100);
    hero.getStatusEffect()->resetAll();
    std::cout<<"haha";
    // hero.setAccessory(&HUFU);
    // Medicine hp("药水",1,10);
    // hero.get_backpack()->add_item(&hp);
    // std::cout<<"haha";
    // hero.get_backpack()->show();

    //饰品的装载
    return 0;
}
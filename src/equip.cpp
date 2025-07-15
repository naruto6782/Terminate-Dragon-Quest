#include "equip.h"
#include "Hero_and_Monster.h"
#include <iostream>

void Amulet::equip(Hero* hero) const{
        std::cout << " 勇者护符已装备！" << std::endl;
        hero->change_Defense(10);//需要修改成所有格挡减伤提高30%
    }
void Cape::equip(Hero* hero) const{
        std::cout << " 灵光披风已装备！" << std::endl;
    }
void Ring::equip(Hero* hero) const{
        std::cout << " 幸运戒指已装备！" << std::endl;
    }

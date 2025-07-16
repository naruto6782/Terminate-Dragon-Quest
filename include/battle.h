#ifndef BATTLE_H
#define BATTLE_H
#include "Hero_and_Monster.h"
class Battle {
    private:
        Hero *hero;
        Monster *monster;
    public:
        Battle(Hero *hero, Monster *monster) {
            this->hero = hero;
            this->monster = monster;
        }
        void Hero_turn();
        void Monster_turn();
        void init_battle();
        void end_battle();
        void show_battle();
        void choose_item();
};


#endif
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
        void Battle_round();
        void process_turn();//done
        void Hero_turn();//done
        void Monster_turn();//done
        void show_battle();//done
        void choose_item();
};


#endif
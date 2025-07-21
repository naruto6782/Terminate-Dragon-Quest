#ifndef BATTLE_H
#define BATTLE_H
#include "Hero_and_Monster.h"
class Battle {
    private:
        Hero *hero;
        Monster *monster;
        int change_attack;
        int change_defense;
        int change_speed;
        int change_luck;
    public:
        Battle(Hero *hero, Monster *monster) {
            this->hero = hero;
            this->monster = monster;
            this->change_attack = 0;
            this->change_defense = 0;
            this->change_speed = 0;
            this->change_luck = 0;
        }
        int Battle_round(int HP);
        void process_turn(int choice);//done
        void Hero_turn(int monster_HP);//done
        void Monster_turn();//done
        void show_battle();//done
        int choose_item();
        void get_change(int index){
            switch (index) {
                case 1:
                    break;
                case 2:
                    this->change_defense = 10;
                    break;
                case 3:
                    this->change_attack = 10;
                    break;
                default:
                    return;
            }
            return;
        }
        void reset_change() {
            this->change_attack = 0;
            this->change_defense = 0;
            this->change_speed = 0;
            this->change_luck = 0;
        }
};


#endif
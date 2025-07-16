#include "battle.h"
#include "Hero_and_Monster.h"
#include <iostream>
#include <iomanip> 
using namespace std;
#include <iomanip>  // for std::setw

void Battle::show_battle() {
    cout << "\n================= ⚔️ Battle Begins ⚔️ =================\n";
    cout << "🏹 Hero: " << std::setw(15) << std::left << this->hero->get_name()
         << "🧟 Monster: " << this->monster->get_name() << "\n";
    cout << "-------------------------------------------------------\n";
    cout << std::setw(12) << "Attribute"
         << std::setw(12) << "Hero"
         << std::setw(12) << "Monster" << "\n";
    cout << "-------------------------------------------------------\n";
    cout << std::setw(12) << "HP"
         << std::setw(12) << this->hero->get_HP()
         << std::setw(12) << this->monster->get_HP() << "\n";
    cout << std::setw(12) << "Attack"
         << std::setw(12) << this->hero->get_Attack()
         << std::setw(12) << this->monster->get_Attack() << "\n";
    cout << std::setw(12) << "Defense"
         << std::setw(12) << this->hero->get_Defense()
         << std::setw(12) << this->monster->get_Defense() << "\n";
    cout << std::setw(12) << "Speed"
         << std::setw(12) << this->hero->get_Speed()
         << std::setw(12) << this->monster->get_Speed() << "\n";
    cout << std::setw(12) << "Luck"
         << std::setw(12) << this->hero->get_Luck()
         << std::setw(12) << "-" << "\n"; // 假设怪物没有 Luck
    cout << "-------------------------------------------------------\n";

    cout << "🧙 Hero Status Effects:     ";
    this->hero->getStatusEffect()->print();
    cout<<endl;
    cout << "👹 Monster Status Effects:  ";
    this->monster->getStatusEffect()->print();
    cout<<endl;
    cout << "=======================================================\n\n";
}

void Battle::Hero_turn(){
    cout<< "Please choose your action: "<<endl;
    cout<<"1. Attack"<<endl;
    cout<<"2. Defend"<<endl;
    cout<<"3. Use Item"<<endl;
    cout<<"Enter your choice: ";
    int choice;
    cin>>choice;
    cout<<endl;
    switch(choice){
        case 1:
            this->hero->Attack_Monster(this->hero,this->monster);
            break;
        case 2:
            this->hero->getStatusEffect()->setDefending();
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
    };
}
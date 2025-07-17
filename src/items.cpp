#include<iostream>
#include "items.h"
#include "Hero_and_Monster.h"

NullItem null_item("Null",0,0);

void Medicine::use(Hero* hero, Monster* monster) const{
    std::cout << "你使用了生命药水，恢复了10点生命值！" << std::endl<<std::endl;
    hero->change_HP(10,1.0,hero->get_max_HP());
}

void IronMedicine::use(Hero* hero, Monster* monster) const{
    std::cout << "你使用了钢铁合剂，本回合增加了10点防御力！" << std::endl<<std::endl;
    hero->change_Defense(10,1.0);
}

void AngryDrink::use(Hero* hero, Monster* monster) const{
    std::cout << "你使用了愤怒合剂，本回合增加了10攻击力！" << std::endl<<std::endl;
    hero->change_Attack(10,1.0);
}

void Antidote::use(Hero* hero, Monster* monster) const{
    std::cout << "你使用了解毒草，清除了自身的中毒效果！" << std::endl<<std::endl;
    hero->getStatusEffect()->resetPoisoned();
}

void Antibiotic::use(Hero* hero, Monster* monster) const{
    std::cout << "你使用了惊惶木，清除了自身的睡眠效果！" << std::endl<<std::endl;
    hero->getStatusEffect()->resetStunned();
}

void Poison::use(Hero* hero, Monster* monster) const{
    std::cout << "你使用了淬毒镖，对方获得中毒效果！" << std::endl<<std::endl;
    monster->getStatusEffect()->setPoisoned();
}

void Stunned::use(Hero* hero, Monster* monster) const{
    std::cout << "你使用了夜阑谣，对方获得睡眠效果！" << std::endl<<std::endl;
    monster->getStatusEffect()->setStunned();
}

void Panacea::use(Hero* hero, Monster* monster) const{
    std::cout << "你使用了万灵药，清除了自身的所有负面效果！" << std::endl<< std::endl;
    hero->getStatusEffect()->resetAll();
}

void NullItem::use(Hero* hero, Monster* monster) const{}
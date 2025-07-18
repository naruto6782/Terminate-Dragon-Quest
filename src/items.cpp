#include<iostream>
#include "items.h"
#include "Hero_and_Monster.h"

NullItem null_item("Null",0,0);
Medicine medicine("血瓶", 1, 100);
Poison poison("毒瓶", 1, 100);
IronMedicine ironMedicine("钢铁合剂", 1, 100);
AngryDrink angryDrink("愤怒合剂", 1, 100);
Antidote antidote("解毒草", 1, 100);
Antibiotic antibiotic("惊惶木", 1, 100);
Stunned stunned("夜阑谣", 1, 100);
Panacea panacea("万灵药", 1, 100);
PhoenixFeather phoenixFeather("凤凰羽翼", 1, 100);

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

void PhoenixFeather::use(Hero* hero, Monster* monster) const{
    hero->reborn(0.3);
    std::cout << "你使用了凤凰羽毛,重生成功！" << std::endl<< std::endl;
}
void NullItem::use(Hero* hero, Monster* monster) const{}
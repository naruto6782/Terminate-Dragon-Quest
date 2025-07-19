#include<iostream>
#include "items.h"
#include "Hero_and_Monster.h"

void init_items_effects() {
    
    null_item.set_effect(
        [](Hero* h, Monster* m){ std::cout << "无效物品，无法使用。" << std::endl; }
    );
    medicine.set_effect(//血瓶
        [](Hero* h, Monster* m){ h->change_HP(10,1.0); std::cout << "你使用了血瓶，回复10生命值！" << std::endl; h->get_backpack()->delete_item_by_index(1); }
    );
    poison.set_effect(//毒瓶
        [](Hero* h, Monster* m){ m->getStatusEffect()->setPoisoned(); std::cout << "你使用了毒瓶，怪物中毒！" << std::endl; h->get_backpack()->delete_item_by_index(2); }
    );
    ironMedicine.set_effect(//钢铁合剂
        [](Hero* h, Monster* m){ h->change_Defense(10,1.0); std::cout << "你使用了钢铁合剂，增加10防御！" << std::endl; h->get_backpack()->delete_item_by_index(3); }
    );
    angryDrink.set_effect(//愤怒合剂
        [](Hero* h, Monster* m){ h->change_Attack(10,1.0); std::cout << "你使用了愤怒合剂，增加10攻击！" << std::endl; h->get_backpack()->delete_item_by_index(4); }
    );
    antidote.set_effect(//解毒草
        [](Hero* h, Monster* m){ h->getStatusEffect()->resetPoisoned(); std::cout << "你使用了解毒草，解除中毒状态！" << std::endl; h->get_backpack()->delete_item_by_index(5); }
    );
    antibiotic.set_effect(//惊惶木
        [](Hero* h, Monster* m){ h->getStatusEffect()->resetStunned(); std::cout << "你使用了惊惶木，解除眩晕状态！" << std::endl; h->get_backpack()->delete_item_by_index(6); }
    );
    stunned.set_effect(//夜阑谣
        [](Hero* h, Monster* m){ m->getStatusEffect()->setStunned(); std::cout << "你使用了夜阑谣，怪物眩晕！" << std::endl; h->get_backpack()->delete_item_by_index(7); }
    );
    panacea.set_effect(//万灵药
        [](Hero* h, Monster* m){ h->getStatusEffect()->resetAll(); std::cout << "你使用了万灵药，解除所有状态效果！" << std::endl; h->get_backpack()->delete_item_by_index(8); }
    );
    phoenixFeather.set_effect(//凤凰羽翼
        [](Hero* h, Monster* m){ //h->reborn(0.3); std::cout << "你使用了凤凰羽翼，重生成功！" << std::endl; h->get_backpack()->delete_item_by_index(9);
             }
    );

}
Item index_to_item(int index) {
    switch (index) {
        case 1:
            return medicine;
        case 2:
            return ironMedicine;
        case 3:
            return angryDrink;
        case 4:
            return antidote;
        case 5:
            return antibiotic;
        case 6:
            return poison;
        case 7:
            return stunned;
        case 8:
            return panacea;
        case 9:
            return phoenixFeather;
        default:
            return null_item; // 返回空物品
    }
}
Item null_item("Null", 0, 0, 0);
Item medicine("血瓶", 1, 100, 1);
Item poison("毒瓶", 1, 100,2);
Item ironMedicine("钢铁合剂", 1, 100, 3);
Item angryDrink("愤怒合剂", 1, 100, 4);
Item antidote("解毒草", 1, 100, 5);
Item antibiotic("惊惶木", 1, 100, 6);
Item stunned("夜阑谣", 1, 100, 7);
Item panacea("万灵药", 1, 100, 8);
Item phoenixFeather("凤凰羽翼", 1, 1000, 9);
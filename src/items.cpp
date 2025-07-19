#include<iostream>
#include "items.h"
#include "Hero_and_Monster.h"

void init_equipment_effects() {
    
    null_item.set_effect(
        [](Hero* h, Monster* m){ std::cout << "无效物品，无法使用。" << std::endl; }
    );
    medicine.set_effect(//血瓶
        [](Hero* h, Monster* m){ h->change_HP(10,1.0); }
    );
    poison.set_effect(//毒瓶
        [](Hero* h, Monster* m){ m->getStatusEffect()->setPoisoned(); }
    );
    ironMedicine.set_effect(//钢铁合剂
        [](Hero* h, Monster* m){ h->change_Defense(10,1.0); }
    );
    angryDrink.set_effect(//愤怒合剂
        [](Hero* h, Monster* m){ h->change_Attack(10,1.0); }
    );
    antidote.set_effect(//解毒草
        [](Hero* h, Monster* m){ h->getStatusEffect()->resetPoisoned(); }
    );
    antibiotic.set_effect(//惊惶木
        [](Hero* h, Monster* m){ h->getStatusEffect()->resetStunned(); }
    );
    stunned.set_effect(//夜阑谣
        [](Hero* h, Monster* m){ m->getStatusEffect()->setStunned(); }
    );
    panacea.set_effect(//万灵药
        [](Hero* h, Monster* m){ h->getStatusEffect()->resetAll(); }
    );
    phoenixFeather.set_effect(//凤凰羽翼
        [](Hero* h, Monster* m){ h->reborn(0.3); std::cout << "你使用了凤凰羽翼，重生成功！" << std::endl; }
    );

}

#include "battle.h"
#include "backpack.h"
#include "Hero_and_Monster.h"
#include "items.h"
#include "challenge.h"
#include <iostream>
#include <iomanip> 
using namespace std;
#include <iomanip>  // for std::setw
#include <random>
#include <stdlib.h>

static mt19937_64& get_random_engine() {//用于随机数生成
    static random_device rd;  // 硬件随机源
    static mt19937_64 engine(rd()); // 使用64位梅森旋转算法
    return engine;
}

void Battle::show_battle() {
    cout << "\n================= ⚔️ Battle Begins ⚔️ =================\n";
    cout << "🏹 勇者: " << std::setw(15) << std::left << this->hero->get_name()
         << "🧟 怪物: " << this->monster->get_name() << "\n";
    cout << "-------------------------------------------------------\n";
    cout << std::setw(12) << "属性"
         << std::setw(12) << "勇者"
         << std::setw(12) << "怪物" << "\n";
    cout << "-------------------------------------------------------\n";
    cout << std::setw(12) << "血量"
         << std::setw(12) << this->hero->get_HP()
         << std::setw(12) << this->monster->get_HP() << "\n";
    cout << std::setw(12) << "攻击"
         << std::setw(12) << this->hero->get_Attack()
         << std::setw(12) << this->monster->get_Attack() << "\n";
    cout << std::setw(12) << "防御"
         << std::setw(12) << this->hero->get_Defense()
         << std::setw(12) << this->monster->get_Defense() << "\n";
    cout << std::setw(12) << "敏捷"
         << std::setw(12) << this->hero->get_Speed()
         << std::setw(12) << this->monster->get_Speed() << "\n";
    cout << std::setw(12) << "幸运"
         << std::setw(12) << this->hero->get_Luck()
         << std::setw(12) << "-" << "\n"; // 假设怪物没有 Luck
    cout << "-------------------------------------------------------\n";

    cout << "🧙 勇者状态效果：            ";
    this->hero->getStatusEffect()->print();
    cout<<endl;
    cout << "👹 怪物状态效果：            ";
    this->monster->getStatusEffect()->print();
    cout<<endl;
    cout << "=======================================================\n\n";
}

void Battle::Hero_turn() {
    int item_choice =-1;
    int choice=-1;
    do{
    item_choice =-1;
    show_battle();
    cout << "\n🎮 请做出你的选择：\n";
    cout << "1. ⚔️ 普通攻击\n";
    cout << "2. 🛡️ 防御\n";
    cout << "3. 💊 使用道具\n";
    cout << "👉 你的选择：";
    cin >> choice;
    getchar(); // 清除输入缓冲区的换行符
    cout << endl;
    switch (choice) {
        case 1:
            this->hero->Attack_Monster(this->hero, this->monster);
            if(this->hero->get_weapon()->get_index() == 4){
                this->monster->getStatusEffect()->setPoisoned();
            }
            break;
        case 2:
            this->hero->getStatusEffect()->setDefending();
            cout << "🛡️ 你进入了防御状态！" << endl;
            break;
        case 3:
            item_choice=this->choose_item();
            break;
        default:
            cout << "❌ 无效选择！" << endl;
            item_choice=0;
            break;
    }
    if(item_choice==0){
        cout << "-----按Enter回到选择界面-----";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
    }
    }while(item_choice==0);
}


void Battle::Monster_turn(){
     static auto& engine = get_random_engine();
     uniform_real_distribution<double> dist(0.0, 1.0);
     double roll = dist(engine);  
     double desire_to_defense=0.2;
     if (this->monster->get_HP()<20){
          desire_to_defense+=0.2;
     }
     if(roll < desire_to_defense){
          this->monster->getStatusEffect()->setDefending();
          cout<<"怪兽选择防守"<<endl;
     }
     else{
          this->monster->Attack_Hero(this->hero,this->monster);
     }
     return;
}

void Battle::process_turn(int choice){
    this->hero->getStatusEffect()->process();
    this->monster->getStatusEffect()->process();
    if(choice){
        this->hero->change_Defense(-this->change_defense,1.0);
        this->hero->change_Attack(-this->change_attack,1.0);
        reset_change();
    }
}

int Battle::choose_item() {
    Backpack* bag = this->hero->get_backpack();
    int status=bag->show_backpack();
    if(status == 0) {
        return 1; // 返回0表示背包为空
    }
    int choose;
    while (true) {
        std::cout << "请输入一个编号(输入0返回)： ";
        std::cin >> choose;

        if (std::cin.fail()) {
            std::cin.clear();  // 清除错误标志位
            std::cin.ignore(10000, '\n');  // 丢弃错误输入（直到换行）
            std::cout << "❌ 输入无效，请输入一个整数！\n";
        } else {
            std::cin.ignore(10000, '\n');  // 清空缓冲区（避免输入如 123abc 时剩余字符影响后续）
            break;  // 输入成功，退出循环
        }
    }
    if (choose == 0) {
        cout << "❌ 你取消了使用道具"<<endl<<endl;
        return 0;
    }
    int choose_index = bag->choose_to_index(choose);
    index_to_item(choose_index).apply_effect(this->hero, this->monster);
    cout << endl;
    if (choose_index == 9) {
        cout << "❌ 凤凰羽毛不能主动使用！ " << endl;
        return 0;
    }
    get_change(index_to_item(choose_index).index);
    return 1;
}

int Battle::Battle_round(int HP) {
    cout << "\n🏁 战斗开始！" << endl;
    int monster_HP = this->monster->get_HP();
    while (hero->get_HP() > 0 && monster->get_HP() > 0) {
            process_turn(1);
            int hero_poisoned = this->hero->getStatusEffect()->poisoned; 
            int hero_stunned = this->hero->getStatusEffect()->stunned;
            if (hero->get_HP() <= 0) break;
            if(hero_poisoned>0){
                this->hero->change_HP(-10*hero_poisoned,1.0);
                cout << "你中了毒，受到伤害！" << endl << endl;
            }
            if (hero->get_HP() <= 0) break;
            if(hero_stunned){
                cout << "你被眩晕了，无法行动！" << endl << endl;
            } else {
                Hero_turn();
            }

            process_turn(0);
            int monster_stunned = this->monster->getStatusEffect()->stunned;
            int monster_poisoned = this->monster->getStatusEffect()->poisoned;
            if (monster->get_HP() <= 0) break;
            if(monster_poisoned>0){
                this->monster->change_HP(-10*monster_poisoned,1.0);
                cout << "怪物中了毒，受到伤害！" << endl << endl;
            }
            if (monster->get_HP() <= 0) break;
            if(monster_stunned){
                cout << "怪物被眩晕了，无法行动！" << endl << endl;
            } else {
                if (auto* boss_ptr = dynamic_cast<Boss*>(this->monster)) {
                boss_ptr->use_skill_or_attack(this->hero);
                } 
                else {
                Monster_turn();
                }
            }
        // 状态处理
        // 清屏（可选，终端清理效果）
        cout << "\n-----🔄 回合结束，按Enter继续...------";
        getchar(); // 等待用户按回车
        system("cls"); // 清屏
    }

    // 战斗结束判定
    cout << "\n🏁 战斗结束！  \n";
    if (hero->get_HP() <= 0) {
        cout << "💀 英雄战败了！" << endl<<endl;
        return 0;
    } else {
        int money = monster->get_Money();
        hero -> change_Money(money);
        this->monster->reborn(1.0, monster_HP);
        cout << "🎉 英雄胜利！获得了" << monster->get_Money() << "金钱" << endl<<endl;
        return 1;
        
    }
    
}

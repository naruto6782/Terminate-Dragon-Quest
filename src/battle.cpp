#include "battle.h"
#include "backpack.h"
#include "Hero_and_Monster.h"
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
        cout << "-----按任意键继续-----";
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

void Battle::process_turn(){
     this->hero->getStatusEffect()->process();
     this->monster->getStatusEffect()->process();
}

int Battle::choose_item() {
    backpack* bag = this->hero->get_backpack();
    //TO COPY
    cout << "\n🎒 你背包中的道具如下：\n";
    cout << "=======================================================\n";
    cout << std::setw(5) << "编号" 
         << std::setw(20) << "道具名"
         << std::setw(10) << "数量" << "\n";
    cout << "-------------------------------------------------------\n";

    for (int i = 0; i < MAX_ITEMS; ++i) {
        BaseItem* item = bag->choose_item(i);
        if (item->get_index() != 0) {
            cout << std::setw(5) << i+1
                 << std::setw(20) << item->get_name()
                 << std::setw(10) << item->get_num() << "\n";
        }
    }
    cout << "=======================================================\n";

    cout << "\n🔢 请输入你要使用的道具编号（0取消）：";
    int choose;
    cin >> choose;
    getchar(); // 清除输入缓冲区的换行符
    choose--;
    cout << endl;
    if (choose == -1) {
        cout << "❌ 你取消了使用道具"<<endl<<endl;
        return 0;
    }

    BaseItem* item_choosed = bag->choose_item(choose);
    if (item_choosed->get_index() == 0) {
        cout << "⚠️ 输入无效，没有这个编号的道具。" << endl<<endl;
        return 0;
    }

    item_choosed->use(this->hero, this->monster);
    bag->delete_item(choose);  // 使用后删除一个数量
    return 1;
}

void Battle::Battle_round() {
    cout << "\n🏁 战斗开始！" << endl;
    this->hero->set_max_HP(this->hero->get_HP());
    while (hero->get_HP() > 0 && monster->get_HP() > 0) {

        bool hero_goes_first = hero->get_Speed() >= monster->get_Speed();

        // 行动阶段
        if (hero_goes_first) {
            Hero_turn();
            process_turn();
            if (monster->get_HP() <= 0) break;
            Monster_turn();
            process_turn();
        } else {
            Monster_turn();
            if (hero->get_HP() <= 0) break;
            Hero_turn();
        }

        // 状态处理
       

        // 清屏（可选，终端清理效果）
        cout << "\n-----🔄 回合结束，按回车继续...------";
        getchar(); // 等待用户按回车
        system("cls"); // 清屏
    }

    // 战斗结束判定
    cout << "\n🏁 战斗结束！  ";
    this->hero->set_max_HP(1000000);
    if (hero->get_HP() <= 0) {
        cout << "💀 英雄战败了！" << endl<<endl;
        cout << "💔 按任意键返回主菜单...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        return;
    } else if (monster->get_HP() <= 0) {
        int money = monster->get_Money();
        hero -> change_Money(money);
        cout << "🎉 英雄胜利！" << endl<<endl;
        cout <<"🎊 按任意键继续...";
        getchar(); // 等待用户按任意键
        system("cls"); // 清屏
        return;
        
    }
    
}

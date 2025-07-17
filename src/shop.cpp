#include<iostream>
#include "shop.h"
#include <iomanip>
void Shop::show_shop(Hero* hero) {
    int choice=-1;
    do{
    std::cout << "欢迎来到商店！以下是可供购买的物品：" << std::endl;
    std::cout << "==================== 商店物品 ====================\n";
    std::cout << std::left
          << std::setw(6) << "编号"
          << std::setw(18) << "名称"
          << std::setw(8) << "数量"
          << std::setw(10) << "价格"
          << "\n";
    std::cout << "--------------------------------------------------\n";

    for (int i = 0; i < Max_shop_item_num; i++) {
        if (item[i]->get_index() != 0) {
            std::cout << std::left
                  << std::setw(6) << i + 1
                  << std::setw(24) << item[i]->get_name()
                  << std::setw(10) << item[i]->get_num()
                  << std::setw(10) << (std::to_string(item[i]->get_price()) + "金币")
                  << "\n";
    }
    }

    std::cout << "==================================================\n";
    std::cout << "请输入你想购买的物品编号（0退出）: "<< std::endl;
    while (true) {
        std::cout << "请输入一个编号：";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();  // 清除错误标志位
            std::cin.ignore(10000, '\n');  // 丢弃错误输入（直到换行）
            std::cout << "❌ 输入无效，请输入一个整数！\n";
        } else {
            std::cin.ignore(10000, '\n');  // 清空缓冲区（避免输入如 123abc 时剩余字符影响后续）
            break;  // 输入成功，退出循环
        }
    }
    choice--;
    if (choice < -1 || choice > Max_shop_item_num - 1|| choice + 1 > this->total_items) {
        std::cout << "无效的选择或物品编号。" << std::endl<< std::endl;
        std::cout << "请重新选择。" << std::endl<< std::endl;
        std::cout << "按任意键返回商店菜单..." << std::endl<< std::endl;
        getchar();
        system("cls");
        continue;
    }
    else if (choice >= 0 ) {
        buy_item(hero,choice);
        std::cout << "按任意键返回商店菜单..." << std::endl;
        getchar();
        system("cls");
        continue;
    }
    }while(choice != -1);
    std::cout << "感谢您的光临！" << std::endl;
    std::cout << "按任意键返回主菜单..." << std::endl;
    getchar();
    system("cls");
    return;
}
void Shop::buy_item(Hero *hero,int choice) {
    if (hero->get_Money() < item[choice]->get_price()) {
        std::cout << "金币不足，无法购买该物品。" << std::endl<<std::endl;
        return;
    }
    hero->change_Money(-item[choice]->get_price());
    backpack *bag = hero->get_backpack();
    bag->add_item(bag->get_item(item[choice]->get_index()));
    item[choice]->sub_num();
    fresh_shop();
    std::cout << "你购买了 " << item[choice]->get_name() << " x1" << std::endl;
    std::cout << "剩余金币: " << hero->get_Money() << std::endl;
    std::cout << "商店物品数量已更新。" << std::endl;
    return;
}
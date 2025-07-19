#include "backpack.h"
#include "Hero_and_Monster.h"
void Equipment_backpack::change_equipment(int choice, Hero* hero) {
    choice--; // 转换为0基索引
    if (choice < 0 || choice >= equipment_items.size()) {
        std::cout << "❌ 无效的选择！" << std::endl;
        return;
    }

    Equipment& new_equipment = equipment_items[choice];

    if (new_equipment.get_is_equipped() == 1) {
        std::cout << "⚠️ 该装备已装备，无法再次装备！" << std::endl;
        return;
    }

    // 获取新装备的类型
    EquipmentType new_type = new_equipment.get_type();

    // 遍历背包，卸下同类型的已装备装备
    for (auto& eq : equipment_items) {
        if (eq.get_type() == new_type && eq.get_is_equipped() == 1) {
            eq.change_is_equipped(); // 设置为未装备
            break; // 假设每种类型最多只能装备一件，找到就退出
        }
    }

    // 装备新装备
    hero->equip(new_equipment.clone()); // 使用克隆以避免修改原始装备
    new_equipment.change_is_equipped(); // 设置为已装备
}
void Shop::show_shop_items(Hero* hero) {
        while (true) {
            std::cout << "\n🛒 商店商品列表：\n";
            int index_of_shop = 1;
            for (auto& item : items) {
                std::cout << "  " << index_of_shop << ". " << item.name 
                        << " x" << item.num 
                        << " 💰价格: " << item.price << "\n";
                ++index_of_shop;
            }
            std::cout << "  0. 退出商店\n";
            std::cout <<"当前金币: " << hero->get_Money() << "\n";
            std::cout << "请选择要购买的物品（输入数字）：";

            int choice;
            std::cin >> choice;
            getchar(); // 清除输入缓冲区

            if (choice == 0) {
                std::cout << "👋 欢迎下次光临！\n";
                return;
            }

            sell_item(choice, hero);

            int next_choice;
            while (true) {
                std::cout << "📌 是否继续购物？\n";
                std::cout << "  1. 继续购买\n";
                std::cout << "  2. 退出商店\n";
                std::cout << "请选择：";
                std::cin >> next_choice;
                getchar();
                if (next_choice == 1) {
                    system("cls"); // 清屏
                    break; // 继续循环展示商品
                } else if (next_choice == 2) {
                    std::cout << "👋 欢迎下次光临！\n";
                    return;
                } else {
                    std::cout << "❌ 无效输入，请重新输入！\n";
                }
            }
        }
    }
void Shop::sell_item(int choice, Hero* hero) {
        choice--;
        if (choice < 0 || choice >= items.size()) {
            std::cout << "❌ 无效选择！" << std::endl;
            return; // 返回默认空物品
        }
        Item item = items[choice];
        if(hero->get_Money() < item.price) {
            std::cout << "❌ 金币不足，无法购买！" << std::endl;
            return; // 返回默认空物品
        }
         // 扣除金币
        item.num = 1; // 玩家只能买1个，或你自定义
        hero->change_Money(-item.price);
        hero->get_backpack()->add_or_stack(item);
        items[choice].num--;
        remove_zero();
        return;
    }




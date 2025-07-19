#pragma once
#define MAX_ITEMS 15
#include "items.h"
#include "equip.h"
#include <iomanip> 
#include <string>

class Backpack {
protected:
    std::vector<Item> items;

public:
    //用栈式存储物品
    void add_or_stack(Item new_item) {
        for (auto& item : items) {
            if (item.name == new_item.name) {
                item.num += new_item.num;
                return;
            }
        }
        items.emplace_back(new_item.name, new_item.num, new_item.price, new_item.index);
    }
    //删除数量为0的物品
    void remove_zero() {
        items.erase(
            std::remove_if(items.begin(), items.end(), [](const Item& item) {
                return item.num <= 0;
            }),
            items.end()
        );
    }
    void show_backpack() {
        std::cout << "你的背包：\n";
        int index_of_backpack = 1;
        for (auto& item : items) {
            std::cout << "  " << index_of_backpack << ". " << item.name << " x" << item.num << "\n";
            ++index_of_backpack;
        }
    }
    void delete_item(int choice) {
        choice--; // 转换为0基索引
        if (choice < 0 || choice >= items.size()) {
            std::cout << "❌ 无效的选择！" << std::endl;
            return;
        }
        items[choice].num--;
        remove_zero(); // 删除数量为0的物品
    }
    int choose_to_index(int choice) {
        choice--; // 转换为0基索引
        if (choice < 0 || choice >= items.size()) {
            std::cout << "❌ 无效的选择！" << std::endl;
            return -1; // 返回-1表示无效选择
        }
        return items[choice].index;// 返回有效索引
    }
};
class Shop : public Backpack {
public:
    Shop(){
        add_or_stack(Item("生命药水", 10, 50, 1));
        add_or_stack(Item("钢铁合剂", 5, 100, 2));
        add_or_stack(Item("愤怒合剂", 3, 150, 3));
        add_or_stack(Item("解毒草", 8, 30, 4));
        add_or_stack(Item("惊惶木", 6, 80, 5));
        add_or_stack(Item("淬毒镖", 4, 120, 6));
        add_or_stack(Item("夜阑谣", 2, 200, 7));
        add_or_stack(Item("万灵药", 1, 500, 8));
        add_or_stack(Item("凤凰羽翼", 1, 1000, 9));
    }
    void show_shop_items() {
        std::cout << "🛒 商店商品列表：\n";
        int index_of_shop = 1;
        for (auto& item : items) {
            std::cout << "  " << index_of_shop << ". " << item.name << " x" << item.num << "\n";
            ++index_of_shop;
        } // 复用
    }

    // 玩家购买物品
    Item sell_item(int choice) {
        choice--;
        if (choice < 0 || choice >= items.size()) {
            std::cout << "❌ 无效选择！" << std::endl;
            return Item("Null", 0, 0, 0); // 返回默认空物品
        }
        Item item = items[choice];
        item.num = 1; // 玩家只能买1个，或你自定义
        items[choice].num--;
        remove_zero();
        return item;
    }

    void restock(Item item) {
        add_or_stack(item);
    }
};
class Equipment_backpack{
private:
    std::vector<Equipment> equipment_items;
public:
    void add_equipment(const Equipment& equipment) {
        for (auto& item : equipment_items) {
            if (item.get_name() == equipment.get_name()) {
                item.add_num(1);
                return;
            }
        }
        equipment_items.push_back(equipment);
    }
    void show_equipment() {
        std::cout << "你的装备：\n";
        int index_of_equipment = 1;
        for (const auto& equipment : equipment_items) {
            std::cout << "  " << index_of_equipment << ". " << equipment.get_name() 
                      << " (类型: " << static_cast<int>(equipment.get_type()) 
                      << ", 数量: " << equipment.get_num() << ")\n";
            ++index_of_equipment;
        }
    }
    void erase_zero() {
        equipment_items.erase(
            std::remove_if(equipment_items.begin(), equipment_items.end(), [](const Equipment& equipment) {
                return equipment.get_num() <= 0;
            }),
            equipment_items.end()
        );
    }
    void delete_equipment(int choice) {
        choice--; // 转换为0基索引
        if (choice < 0 || choice >= equipment_items.size()) {
            std::cout << "❌ 无效的选择！" << std::endl;
            return;
        }
        equipment_items[choice].add_num(-1);
        erase_zero(); // 删除数量为0的装备
    }

};
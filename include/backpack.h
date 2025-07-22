#pragma once
#define MAX_ITEMS 15
#include "items.h"
#include "equip.h"
#include <iomanip> 
#include <string>
#include <algorithm>
#include "check.h"

class Hero;

class Backpack {
protected:
    std::vector<Item> items;

public:
    //用栈式存储物品
    const std::vector<Item>& get_items() {
        return items;
    }

    void add_or_stack(Item new_item) {
        for (auto& item : items) {
            if (item.index == new_item.index) {
                item.num += new_item.num;
                return;
            }
        }
        items.emplace_back(new_item.name, new_item.num, new_item.price, new_item.index);
    }

    void add_or_stack(const std::string& name, unsigned int num, unsigned int price, int index = 0) {
        for (auto& item : items) {
            if (item.index == index) {
                item.num += num;
                return;
            }
        }
        items.emplace_back(name, num, price, index);
    }

    void clear() {
        items.clear();
    }
    int check_index(int index){
        for (auto& item : items) {
            if (item.index == index) {
                
                return 1;
            }
        }
        return 0;
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
    int show_backpack() {
        if (items.empty()) {
            std::cout << "你的背包是空的。\n";
            return 0;
        }
        std::cout << "你的背包：\n";
        int index_of_backpack = 1;
        for (auto& item : items) {
            std::cout << "  " << index_of_backpack << ". " << item.name << " x" << item.num <<"\n";
            ++index_of_backpack;
        }
        return 1; // 返回1表示背包不为空
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
    int check_item_num(int index) {
        for (auto& item : items) {
            if (item.index == index) {
                if(item.num > 0){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
        return 0;
    };
    void delete_item_by_index(int index) {
        for (auto& item : items) {
            if (item.index == index) {
                item.num--;
                remove_zero(); // 删除数量为0的物品
                return;
            }
        }
        std::cout << "❌ 未找到索引为 " << index << " 的物品！" << std::endl;
    }
};
class Shop : public Backpack {
public:
    Shop(){clear();}
    void Shop_init(){
        clear();
        add_or_stack(Item("生命药水", 10, 50, 1));
        add_or_stack(Item("毒瓶", 4, 120, 2));
        add_or_stack(Item("钢铁合剂", 5, 100, 3));
        add_or_stack(Item("愤怒合剂", 3, 150, 4));
        add_or_stack(Item("解毒草", 8, 30, 5));
        add_or_stack(Item("惊惶木", 6, 80, 6));
        add_or_stack(Item("夜阑谣", 2, 200, 7));
        add_or_stack(Item("万灵药", 1, 500, 8));
        add_or_stack(Item("凤凰羽翼", 1, 1000, 9));
    }
    void show_shop_items(Hero* hero);
    void clear() {
        items.clear();
    }
    int get_item_num(int index) {
        for (const auto& item : items) {
            if (item.index == index) {
                return item.num;
            }
        }
        return 0; // 如果没有找到，返回0
    }
    // 玩家购买物品
    void sell_item(int choice, Hero* hero);

    void restock(Item item) {
        add_or_stack(item);
    }
};
class Equipment_backpack{
private:
    std::vector<Equipment> equipment_items;
public:
    const std::vector<Equipment>& get_equipment_items() const {
        return equipment_items;
    }
    void add_equipment(const Equipment& equipment) {
            for (auto& item : equipment_items) {
                if (item.get_name() == equipment.get_name()) {
                    item.add_num(1);
                    return;
                }
            }
            equipment_items.push_back(equipment);
        }
    void add_equipment(std::string name, unsigned int num, unsigned int price, EquipmentType type, unsigned int index) {
        for (auto& item : equipment_items) {
            if (item.get_name() == name) {
                item.add_num(num);
                return;
            }
        }
        equipment_items.emplace_back(type, name, num, price, index);
    }
    void show_equipment(Hero* hero) {
        std::cout << "你的装备：\n";
        int index_of_equipment = 1;
        for (const auto& equipment : equipment_items) {
            std::cout << "  " << index_of_equipment << ". " << equipment.get_name() 
                    << " (类型: " << type_to_string(equipment.get_type()) 
                    << ", 数量: " << equipment.get_num() << ")";
            if (equipment.get_is_equipped() == 1) {
                std::cout << " ✅ 已装备";
            }
            std::cout << "\n";
            ++index_of_equipment;
        }

        std::string input;
        int choice = -1;
        std::cout << "\n是否要更换装备？输入编号（0取消）：";
        choice=getValidChoice(0, index_of_equipment - 1);

        change_equipment(choice, hero);
    }

    void clear() {
        equipment_items.clear();
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
    void set_is_equipped_by_index(int index) {
        for (auto& equipment : equipment_items) {
            if (equipment.get_index() == index) {
                if (!equipment.get_is_equipped()) {
                    equipment.change_is_equipped(); // 装备
                return;
            }
        }
        }
    }
    void change_equipment(int choice, Hero* hero);
};

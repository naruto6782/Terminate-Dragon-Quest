#ifndef BACKPACK_H
#define BACKPACK_H

#define MAX_ITEMS 15
#include "items.h"
extern NullItem null_item;

class backpack {
private:
    BaseItem* items[MAX_ITEMS];

public:
    void init_backpack() {
        for (int i = 0; i < MAX_ITEMS; i++) {
            items[i] = &null_item;
        }
    }

    // 检查是否还有空位
    int Check_valid() {
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (items[i]->get_index() == 0) {
                return 1; // 有空位
            }
        }
        return 0; // 满了
    }

    void fresh_backpack() {
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (items[i]->get_num() < 1) {
                items[i] = &null_item;
            }
        }
    }

    void add_item(BaseItem* item) {
        if (!Check_valid()) {
            //TODO 弹出提示框
            std::cout << "Too many items!" << std::endl;
            return;
        }

        // 查找相同类型的物品
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (items[i]->get_index() == item->get_index()) {
                items[i]->add_num();
                return;
            }
        }

        // 找到空位，插入新物品
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (items[i]->get_index() == 0) {
                items[i] = item;
                return;
            }
        }
    }

    void delete_item(BaseItem* item) {
        int found = 0;

        for (int i = 0; i < MAX_ITEMS; i++) {
            if (items[i]->get_index() == item->get_index()) {
                found = 1;
                items[i]->sub_num();
                if (items[i]->get_num() < 1) {
                    // 移除并将后面的物品前移
                    for (int j = i; j < MAX_ITEMS - 1; j++) {
                        items[j] = items[j + 1];
                    }
                    items[MAX_ITEMS - 1] = &null_item;
                }
                break;
            }
        }

        if (!found) {
            std::cout << "No such item in your backpack" << std::endl;
        }
    }

    void show() {
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (items[i]->get_index() != 0) {
                std::cout << items[i]->get_name() << std::endl;
                std::cout << "数量: " << items[i]->get_num() << std::endl;
                std::cout << "---------------------------------------------" << std::endl;
            }
        }
    }

    int if_can_be_used(BaseItem* item) {
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (items[i]->get_index() == item->get_index()) {
                return 1;
            }
        }
        return 0;
    }

    BaseItem* choose_item(int choose) {
        if (choose < 0 || choose >= MAX_ITEMS) {
            return &null_item;
        }
        return items[choose];
    }
};

#endif
#ifndef BACKPACK_H
#define BACKPACK_H

#define MAX_ITEMS 15
#include "items.h"
#include <string>
extern NullItem null_item;

class backpack {
private:
    BaseItem* items[MAX_ITEMS];

    int prompt_remove_item() {


        int option;
        while(1){
        system("cls");
        std::cout << "背包已满，你想：\n";
        std::cout << "1. 删除已有物品\n";
        std::cout << "2. 丢弃将要添加的物品\n";
        std::cout << "请输入数字选择：";
        std::cin >> option;
        if (option == 1) 
        {   
            std::cout << "当前背包物品如下：\n";
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (items[i]->get_index() != 0) {
                    std::cout << i + 1<< ": " << items[i]->get_name() << " x" << items[i]->get_num() << std::endl;
                }
            }
            std::cout << "请输入要删除的物品编号：";
            int idx;
            std::cin >> idx;
            idx--;
            std::string name=items[idx]->get_name();
            if (delete_item(idx)) {
                std::cout << "已删除：" << name << std::endl;
            } else {
                std::cout << "输入错误，取消添加物品。\n";
            }
            return 1;
        } 
        else if(option==2)
        {
            std::cout << "你选择了丢弃要添加的物品。\n";
            return 0;
        }
        std::cout << "错误输入，请重新选择";
        getchar();
        }
    }

public:
    void init_backpack() {
        for (int i = 0; i < MAX_ITEMS; i++) {
            items[i] = &null_item;
        }
    }

    // 检查是否还有空位
    int Check_valid() {
        int sum=0;
        for (int i = 0; i < MAX_ITEMS; i++) {
            if (items[i]->get_index() == 0) {
                continue;
            }
            else{
                sum+=items[i]->get_num();
            }
        }
        if(sum<=MAX_ITEMS-1){
            return 1;
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
        int choice;
        if (!Check_valid()) {
            //TODO 弹出提示框
            choice=prompt_remove_item();//1 代表删除原物品，0代表放弃
        }
        // 查找相同类型的物品
        if(choice==0){
            return;
        }
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

    int delete_item(int index) {
        if(items[index]->get_index()==0){
            return 0;
        }
        items[index]->sub_num();
        if(items[index]->get_num()==0){
            for(int j=index+1;j<MAX_ITEMS;j++){
                items[j-1]=items[j];
            }
            items[MAX_ITEMS-1]=&null_item;
            return 1;
        }
        return 1;
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

    BaseItem* choose_item(int choose) {
        if (choose < 0 || choose >= MAX_ITEMS) {
            return &null_item;
        }
        return items[choose];
    }
};

#endif
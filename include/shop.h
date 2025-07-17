#ifndef SHOP_H
#define SHOP_H
#include "items.h"
#include "backpack.h"
#include "Hero_and_Monster.h"
#define Max_shop_item_num 10 //商店物品数量
extern NullItem null_item;
class Shop{
    private:
        BaseItem* item[Max_shop_item_num];
        int total_items = 0; // 商店物品总数
    public:
        Shop() {
            item[0] = new Medicine("血瓶", 10, 100);
            item[1] = new IronMedicine("钢铁合剂", 10, 100);
            item[2] = new AngryDrink("愤怒合剂", 10, 100);
            item[3] = new Antidote("解毒草", 10, 100);
            item[4] = new Antibiotic("惊惶木", 10, 100);
            item[5] = new Poison("淬毒镖", 10, 100);
            item[6] = new Stunned("夜阑谣", 10, 100);
            item[7] = new Panacea("万灵药", 10, 100);
            total_items = 8; // 初始化商店物品数量
            for(int i=8;i<Max_shop_item_num;i++){
                item[i]=&null_item;
            }
        }
        void show_shop(Hero* hero);
        void buy_item(Hero *hero,int choice);
        void fresh_shop() {
            int index=-1;
            for (int i = 0; i < Max_shop_item_num; i++) {
                if (item[i]->get_num() < 1) {
                    item[i] = &null_item;
                    index=i;
                    break;
                }
            }
            if(index == -1) return; // 没有空位
            for(int i = index + 1; i < Max_shop_item_num; i++) {
                if (item[i]->get_index() != 0) {
                    item[index] = item[i];
                    item[i] = &null_item;
                    index++;
                }
            }
            return;
        }
};
#endif
#ifndef BACKPACK_H
#define BACKPACK_H
#define MAX_ITEMS 15
#include "items.h"
NullItem null_item;
class backpack
{
    private:
        int current_index=0;
        BaseItem* items[MAX_ITEMS];
    public:
        void init_backpack(){
            for(int i=0;i<MAX_ITEMS;i++){
                items[i]=&null_item;
            }
        }
        int Check_valid(){
            int sum=0;
            for(int i=0;i<MAX_ITEMS;i++){
                sum+=items[i]->get_num();
            }
            if (sum>15){
                return 0;
            }
            return 1;
        };
        void fresh_backpack(){
            for(int i=0;i<MAX_ITEMS;i++){
                if (items[i]->get_num()<1){
                    items[i]=&null_item;
                }
            }
        }
        void add_item(BaseItem* item){
            for(int i=0;i<MAX_ITEMS;i++){
                if(items[i]->get_index()==item->get_index()){
                        items[i]->add_num();
                        return;
                }
            }
            //没有找到相同的物品，添加到背包
            items[current_index]=item;
            current_index=(current_index+1)%MAX_ITEMS;
            return;
        }
        void delete_item(BaseItem* item){
            //todo 实现删除物品功能
        }
};
#endif
#ifndef BACKPACK_H
#define BACKPACK_H
#define MAX_ITEMS 15
#include "items.h"
extern NullItem null_item;
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
            if (sum>14){
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
            if(Check_valid()==0){
                std::cout<<"too_much items"<<std::endl;
                return;
            }
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
            int found=0;
            int flag=0;
            int del_index=-1;
            for(int i=0;i<MAX_ITEMS;i++){
                
                if(items[i]->get_index()==item->get_index()){
                    found=1;
                    if(items[i]->get_num()>=2){
                        items[i]->sub_num();
                    }
                    else if(items[i]->get_num()==1){
                        items[i]->sub_num();
                        items[i]= &null_item;
                        flag=1;
                        del_index=i;
                    }
                }
            }
            if(found==0){
                std::cout<<"no such an items in your backpack";
                return;
            }
            if(flag==1){
                current_index--;
                for(int i=del_index+1;i<MAX_ITEMS;i++){
                    items[i-1]=items[i];
                }
                    items[MAX_ITEMS-1]=&null_item;

            }
                return;
        }
        void show(){
            for(int i=0;i<current_index;i++){
                std::cout<<items[i]->get_name()<<std::endl;
                std::cout<<items[i]->get_num()<<std::endl;
                std::cout<<"---------------------------------------------";
            }
        }
};
#endif
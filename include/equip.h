#ifndef EQUIP_H
#define EQUIP_H
#include <iostream>

class Hero;  // ⭐ 添加前向声明，避免循环引用



class Accessory {
    protected:
        std::string name;
        unsigned int num = 1;
        unsigned int price = 10; 
    public:
    Accessory(const std::string& name, unsigned int num, unsigned int price) {
        this->name = name;
        this->num = num;
        this->price = price;
    }
    std::string get_name() const { return name; }
    unsigned int get_num() const { return num; }
    unsigned int get_price() const { return price; }
    virtual void equip(Hero* hero) const = 0;

};
class Amulet: public Accessory {
    public:
    Amulet(const std::string& name, unsigned int num, unsigned int price) : Accessory(name, num, price) {}
    void equip(Hero* hero) const override;
    // {
    //     std::cout << " 勇者护符已装备！" << std::endl;
    //     hero->change_Defense(10);//需要修改成所有格挡减伤提高30%
    // }
};//勇者护符
class Cape: public Accessory {
    public:
    Cape(const std::string& name, unsigned int num, unsigned int price) : Accessory(name, num, price) {}
    void equip(Hero* hero) const override;
    // {
    //     std::cout << " 灵光披风已装备！" << std::endl;
    //     hero->change_Speed(10);
    // }
};//灵光披风
class Ring: public Accessory {
    public:
    Ring(const std::string& name, unsigned int num, unsigned int price) : Accessory(name, num, price) {}
    void equip(Hero* hero) const override;
    // {    
    //     std::cout << " 幸运戒指已装备！" << std::endl;
    //     hero->change_Luck(10);
    // }
};//幸运戒指









#endif
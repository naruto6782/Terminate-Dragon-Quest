//用于记录每个回合的状态
#ifndef STATUS_H
#define STATUS_H
#include <iostream>
using namespace std;
class StatusEffect {
public:
    int poisoned = 0;   // 中毒
    bool defending = false;  // 防御中
    int stunned = 0;    // 困倦 / 眩晕

    void process() {
        if(poisoned>0){
            poisoned--;
        }
        if(stunned>0){
            stunned--;
        }
    }

    void resetDefending() {
        defending = false;
    }
    void setDefending() {
        defending = true;
    }
    void setStunned() {
        stunned = 3;
    }
    void setPoisoned() {
        poisoned = 3;
    }
    
    void print() const {
        std::cout << "[Status] ";
        if (poisoned) std::cout << "Poisoned ";
        if (defending) std::cout << "Defending ";
        if (stunned) std::cout << "Stunned ";
        if (!poisoned && !defending && !stunned) std::cout << "Normal";
        std::cout << "\n";
    }

};


#endif
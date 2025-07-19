#ifndef CHALLENGE_H
#define CHALLENGE_H
#include <string>
#include <functional>
#include <vector>
#include "Hero_and_Monster.h"



extern int count_easy;
extern int count_medium;
extern int count_hard;
extern int count_challenge;


Boss* create_selen_boss();





void Selen(Hero* hero);
void Azurvain(Hero* hero);
void Nekthos(Hero* hero);



#endif
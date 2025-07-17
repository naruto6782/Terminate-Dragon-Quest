#pragma once
#include "Hero_and_Monster.h"

Monster monsters[3][3] = {
    {
        Monster("Slime", 30, 5, 3, 2, 5, 3),
        Monster("Bat", 35, 6, 4, 3, 6, 4),
        Monster("Rat", 40, 7, 3, 4, 8, 5)
    },
    {
        Monster("Goblin", 70, 12, 6, 5, 15, 10),
        Monster("Wolf", 80, 14, 8, 6, 18, 12),
        Monster("Orc", 90, 16, 5, 8, 20, 15)
    },
    {
        Monster("Dark Knight", 150, 25, 10, 12, 35, 25),
        Monster("Demon", 180, 28, 12, 14, 40, 30),
        Monster("Dragon", 250, 35, 15, 20, 60, 50)
    }
};
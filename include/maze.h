#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Hero_and_Monster.h"
#define round 6 // 迷宫行数
#define event 8 // 每行事件数

extern int easy_maze[round][event];
extern int middle_maze[round][event];
extern int difficult_maze[round][event];

int* select_random_maze(int maze[][event]);
void easy(Hero *hero);
void middle();
void difficult();
#endif

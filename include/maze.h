#ifndef MAZE_H
#define MAZE_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Hero_and_Monster.h"
#define ROUNDS 6 // 迷宫行数
#define EVENTS 8 // 每行事件数

extern int easy_maze[ROUNDS][EVENTS];
extern int middle_maze[ROUNDS][EVENTS];
extern int hard_maze[ROUNDS][EVENTS];

int* select_random_maze(int maze[][EVENTS]);
void easy(Hero *hero);
void medium(Hero *hero);
void hard(Hero *hero);


#endif

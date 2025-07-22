// check.h

#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <csignal>  // 用于信号处理

// 声明全局变量
extern volatile sig_atomic_t stop_program;

// 声明信号处理函数
void handle_sigint(int sig);

// 声明其他函数
bool isValidInteger(const std::string& str);
int getValidChoice(int min, int max);
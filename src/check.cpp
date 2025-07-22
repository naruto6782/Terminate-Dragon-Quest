// check.cpp

#include "check.h"

// 定义全局变量
volatile sig_atomic_t stop_program = 0;

// 信号处理函数
void handle_sigint(int sig) {
    std::cout << "\n程序已收到中断信号，退出中...\n";
    stop_program = 1;
}

bool isValidInteger(const std::string& str) {
    if (str.empty()) return false;

    // 如果有负号，跳过它
    size_t start = 0;
    if (str[0] == '-') {
        start = 1;
    }

    // 检查每个字符是否是数字
    for (size_t i = start; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

// 获取有效的整数输入，范围在 min 和 max 之间
int getValidChoice(int min, int max) {
    std::string input;
    int choice;
    bool validInput = false;

    signal(SIGINT, handle_sigint);  // 注册信号处理函数

    while (!validInput) {
        std::getline(std::cin, input); // 获取整个输入字符串

        // 如果检测到 Ctrl+C 中断
        if (stop_program) {
            std::cout << "程序被中断，退出...\n";
            exit(0);  // 返回特殊值表示中断
        }

        // 检查输入是否为数字并在范围内
        if (isValidInteger(input)) {
            choice = std::stoi(input);  // 将合法的字符串转换为整数
            if (choice >= min && choice <= max) {
                validInput = true;  // 输入有效，跳出循环
            } else {
                std::cout << "迷途的羔羊啊，请重新选择。" << std::endl;
            }
        } else {
            std::cout << "迷途的羔羊啊，请重新选择。" << std::endl;
        }
    }

    return choice;
}
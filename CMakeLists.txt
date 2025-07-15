cmake_minimum_required(VERSION 3.10)
project(TDQ)

set(CMAKE_CXX_STANDARD 17)



# 包含头文件目录
include_directories(include)

# 添加静态库（默认是 STATIC）
add_library(Game_lib src/game.cpp src/Hero_and_Monster.cpp)

# 主程序
add_executable(main main.cpp)

# 链接
target_link_libraries(main Game_lib)

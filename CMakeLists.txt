cmake_minimum_required(VERSION 3.10)
project(TDQ)

set(CMAKE_CXX_STANDARD 17)

# 强制静态链接 libstdc++ 和 libgcc
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

# 包含头文件目录
include_directories(include)

# 添加静态库（默认是 STATIC）
add_library(Game_lib src/game.cpp src/Hero_and_Monster.cpp src/equip.cpp src/battle.cpp src/items.cpp src/maze.cpp src/count.cpp src/story.cpp src/backpack.cpp)

# 主程序
add_executable(main main.cpp)

# 链接
target_link_libraries(main Game_lib)

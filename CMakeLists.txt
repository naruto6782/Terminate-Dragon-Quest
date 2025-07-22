cmake_minimum_required(VERSION 3.10)
project(TDQ)

set(CMAKE_CXX_STANDARD 17)

# 强制静态链接 libstdc++ 和 libgcc
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

# 添加头文件目录（如果你手动安装了 SDL2，记得加上）
include_directories(include)
include_directories("C:/msys64/mingw64/include/SDL2")

# 添加库文件目录（改成你 SDL2 安装的位置）
link_directories("C:/msys64/mingw64/lib")

# 添加静态库
add_library(Game_lib 
    src/game.cpp src/Hero_and_Monster.cpp src/equip.cpp
    src/battle.cpp src/items.cpp src/maze.cpp
    src/count.cpp src/story.cpp src/backpack.cpp
    src/challenge.cpp src/music.cpp src/check.cpp
)

# 设置 main.exe 的输出路径为项目根目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# 主程序
add_executable(main main.cpp)

# 链接 SDL2、SDL2_mixer 和你自己的库
target_link_libraries(main Game_lib 
    SDL2 SDL2main SDL2_mixer
)

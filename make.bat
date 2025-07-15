@echo off
echo [1/4] 切换到 build 目录...
cd build

echo [2/4] 运行 CMake 生成 Makefiles...
cmake .. -G "MinGW Makefiles"
if errorlevel 1 (
    echo CMake 生成失败，退出。
    exit /b 1
)

echo [3/4] 开始构建项目...
cmake --build .
if errorlevel 1 (
    echo 构建失败，退出。
    exit /b 1
)

echo [4/4] 返回上级目录...
cd ..

echo 全部完成！
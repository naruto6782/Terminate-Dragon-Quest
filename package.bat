@echo off
setlocal

:: 设置目标输出目录
set DIST_DIR=dist

:: 清理旧目录
if exist %DIST_DIR% (
    echo 正在清理旧的 dist 目录...
    rmdir /s /q %DIST_DIR%
)

:: 创建新目录
mkdir %DIST_DIR%
mkdir %DIST_DIR%\music

:: 复制可执行文件
copy /y main.exe %DIST_DIR%\

:: 复制资源文件
xcopy /s /y music\* %DIST_DIR%\music\

:: 复制存档文件（可选）
if exist save.txt (
    copy /y save.txt %DIST_DIR%\
)

:: 复制 DLL 依赖（按实际路径修改）
copy /y C:\msys64\mingw64\bin\SDL2.dll %DIST_DIR%\
copy /y C:\msys64\mingw64\bin\SDL2_mixer.dll %DIST_DIR%\
copy /y C:\msys64\mingw64\bin\libstdc++-6.dll %DIST_DIR%\
copy /y C:\msys64\mingw64\bin\libgcc_s_seh-1.dll %DIST_DIR%\

echo.
echo Done. Output directory: %DIST_DIR%
pause

@echo off
chcp 65001 > nul
setlocal enabledelayedexpansion

:: 设置路径
set DIST=dist
set BIN=C:\msys64\mingw64\bin

:: DLL 列表
set DLLS=SDL2.dll SDL2_mixer.dll mpg123.dll FLAC.dll libogg-0.dll libvorbis-0.dll libvorbisfile-3.dll libgcc_s_seh-1.dll libstdc++-6.dll

:: 删除旧 dist 文件夹
if exist %DIST% (
    echo 正在删除旧 dist 文件夹...
    rmdir /s /q %DIST%
)

:: 创建 dist 和资源目录
mkdir %DIST%
mkdir %DIST%\music

:: 拷贝主程序
if exist main.exe (
    copy /y main.exe %DIST%\
) else (
    echo [错误] 没有找到 main.exe！
    pause
    exit /b
)

:: 拷贝资源文件夹
xcopy /y /s "music\*" "%DIST%\music\" > nul

:: 拷贝存档
if exist save.txt (
    copy /y save.txt %DIST%\ > nul
)

:: 拷贝所有 DLL
echo 正在拷贝 DLL 文件...
for %%f in (%DLLS%) do (
    if exist "%BIN%\%%f" (
        copy /y "%BIN%\%%f" "%DIST%\" > nul
        echo [成功] 已拷贝 %%f
    ) else (
        echo [缺失] 没有找到 %%f
    )
)

echo.
echo ✅ 打包完成！请查看 dist 文件夹。
pause

@echo off
mkdir dist
copy build\main.exe dist\
copy C:\msys64\mingw64\bin\SDL2.dll dist\
copy C:\msys64\mingw64\bin\SDL2_mixer.dll dist\
copy C:\msys64\mingw64\bin\libstdc++-6.dll dist\
copy C:\msys64\mingw64\bin\libgcc_s_seh-1.dll dist\
copy C:\msys64\mingw64\bin\libwinpthread-1.dll dist\
xcopy music dist\music /E /I /Y
copy save.txt dist\
echo 打包完成！请分发 dist 文件夹。
pause

@echo off
REM 设置 PowerShell 的输出编码为 UTF-8，并运行 test.exe

powershell -NoLogo -NoProfile -Command ^
 "$OutputEncoding = [Console]::OutputEncoding = [System.Text.UTF8Encoding]::new(); .\test.exe"
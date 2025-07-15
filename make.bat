@echo off
echo ================================
echo == Build Process Started
echo ================================

:: Delete old build folder (optional - comment out if not needed)
if exist build (
    echo Found old build folder. Deleting...
    rd /s /q build
)

:: Create a new build directory
echo Creating build directory...
mkdir build
cd build

:: Run CMake to generate Makefiles
echo Running CMake...
cmake .. -G "MinGW Makefiles"
if errorlevel 1 (
    echo ❌ CMake configuration failed. Exiting.
    pause
    exit /b 1
)

:: Build the project
echo Building the project...
cmake --build .
if errorlevel 1 (
    echo ❌ Build failed. Exiting.
    pause
    exit /b 1
)

:: Go back to the root directory
cd ..
echo ✅ Build completed successfully!
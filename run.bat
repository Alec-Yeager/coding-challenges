@echo off

setlocal enabledelayedexpansion
set SCRIPT_DIR=%~dp0
if "%SCRIPT_DIR:~-1%"=="\" set SCRIPT_DIR=%SCRIPT_DIR:~0,-1%
set BUILD_DIR=%SCRIPT_DIR%\build

set TARGET=%1
cmake -G Ninja -DTARGET=%TARGET% -B "%BUILD_DIR%"
cmake --build "%BUILD_DIR%"

if %errorlevel% equ 0 (
    echo Running %TARGET%...
    "%SCRIPT_DIR%\build\build\%TARGET%.exe" < "%SCRIPT_DIR%\input\%TARGET%.txt"
) else (
    echo Build failed. Skipping run.
)
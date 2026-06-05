@echo off
color 0A
echo ===================================================
echo [AAA GAME DEV] - Running Pre-Commit Local Checks
echo ===================================================

echo.
echo [1/2] Checking Unity C# Scripts Integrity...
findstr /S /C:"<<<<<<< HEAD" *.cs >nul
if %ERRORLEVEL% equ 0 (
    color 0C
    echo [ERROR] Unresolved Git merge conflicts found in C# files!
    pause
    exit /b 1
)
echo [SUCCESS] C# Scripts are clean.

echo.
echo [2/2] Checking Unreal C++ Scripts...
cppcheck --enable=warning,performance --error-exitcode=1 --force --suppress=missingIncludeSystem --suppress=missingInclude --suppressions-list=.cppcheck-suppressions.txt .
if %ERRORLEVEL% neq 0 (
    color 0C
    echo [ERROR] C++ Memory or Syntax check failed!
    pause
    exit /b %ERRORLEVEL%
)
echo [SUCCESS] C++ Scripts are clean.

echo.
echo ===================================================
echo ALL CHECKS PASSED. You are ready to commit!
echo ===================================================
pause
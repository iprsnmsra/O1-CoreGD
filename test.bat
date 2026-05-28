@echo off
color 0A
echo ===================================================
echo [AAA GAME DEV] - Running Pre-Commit Local Checks
echo ===================================================

echo.
echo [1/2] Checking Unity C# Scripts...
dotnet format whitespace --verify-no-changes
if %ERRORLEVEL% neq 0 (
    color 0C
    echo [ERROR] C# syntax or formatting check failed! Fix your .cs files.
    pause
    exit /b %ERRORLEVEL%
)
echo [SUCCESS] C# Scripts are clean.

echo.
echo [2/2] Checking Unreal C++ Scripts...
REM Requires cppcheck to be installed on Windows and added to PATH
cppcheck --enable=warning,performance,portability --error-exitcode=1 --force .
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
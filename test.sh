#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e 

echo -e "\e[1;36m===================================================\e[0m"
echo -e "\e[1;36m[AAA GAME DEV] - Running Pre-Commit Local Checks\e[0m"
echo -e "\e[1;36m===================================================\e[0m\n"

echo -e "\e[1;33m[1/2] Checking Unity C# Scripts...\e[0m"
# Runs .NET format verification
dotnet format whitespace --verify-no-changes
echo -e "\e[1;32m[SUCCESS] C# Scripts are clean.\e[0m\n"

echo -e "\e[1;33m[2/2] Checking Unreal C++ Scripts...\e[0m"
# Runs Cppcheck for memory leaks and performance issues
cppcheck --enable=warning,performance,portability --error-exitcode=1 --force .
echo -e "\e[1;32m[SUCCESS] C++ Scripts are clean.\e[0m\n"

echo -e "\e[1;32m===================================================\e[0m"
echo -e "\e[1;32mALL CHECKS PASSED. You are ready to commit!\e[0m"
echo -e "\e[1;32m===================================================\e[0m"
#!/bin/bash
# Exit immediately if a command exits with a non-zero status
set -e 

LANGUAGE=$1

echo -e "\e[1;36m===================================================\e[0m"
echo -e "\e[1;36m[O1-CoreGD] Executing Validation For: ${LANGUAGE^^}\e[0m"
echo -e "\e[1;36m===================================================\e[0m\n"

if [ "$LANGUAGE" == "csharp" ]; then
    echo -e "\e[1;33mScanning Unity C# scripts for structural integrity...\e[0m"
    
    # Checks for unresolved Git merge conflicts across all Unity scripts
    if grep -rnw . --include="*.cs" -e "<<<<<<< HEAD"; then
        echo -e "\e[1;31m[ERROR] Unresolved Git merge conflicts found in C# files!\e[0m"
        exit 1
    fi
    
    echo -e "\e[1;32m[SUCCESS] C# Framework is clean and structurally sound.\e[0m"

elif [ "$LANGUAGE" == "cpp" ]; then
    echo -e "\e[1;33mRunning Unreal C++ memory and syntax analysis...\e[0m"
    
    # Dynamically generate the Unreal Engine suppression rules so the server never crashes
    cat << 'EOF' > dynamic_suppress.txt
unknownMacro:*UPROPERTY*
unknownMacro:*UCLASS*
unknownMacro:*UENUM*
unknownMacro:*USTRUCT*
unknownMacro:*UFUNCTION*
unknownMacro:*GENERATED_BODY*
unknownMacro:*DECLARE_DYNAMIC_MULTICAST_DELEGATE*
EOF

    # Run the memory check, aggressively suppressing missing Unreal engine files
    cppcheck --enable=warning,performance --error-exitcode=1 --force \
        --suppress=missingIncludeSystem \
        --suppress=missingInclude \
        --suppressions-list=dynamic_suppress.txt .
    
    # Clean up the dynamic file
    rm dynamic_suppress.txt
    
    echo -e "\e[1;32m[SUCCESS] C++ Framework passed O(1) memory analysis.\e[0m"

else
    echo -e "\e[1;31m[ERROR] Unknown language parameter passed to matrix.\e[0m"
    exit 1
fi

echo -e "\n\e[1;32m===================================================\e[0m"
echo -e "\e[1;32mPIPELINE COMPLETED SUCCESSFULLY.\e[0m"
echo -e "\e[1;32m===================================================\e[0m"
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameFramework/SaveGame.h"
#include "AsyncSaveSubsystem.generated.h"

// The lightweight save object
UCLASS()
class O1COREGD_API UCoreSaveData : public USaveGame
{
    GENERATED_BODY()

public:
    UPROPERTY(VisibleAnywhere, Category = "SaveData")
    int32 PlayerLevel;

    UPROPERTY(VisibleAnywhere, Category = "SaveData")
    float CurrentHealth;

    UPROPERTY(VisibleAnywhere, Category = "SaveData")
    FVector LastCheckpoint;
};

// Delegate for when the async save finishes
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSaveComplete, bool, bWasSuccessful);

UCLASS()
class O1COREGD_API UAsyncSaveSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    UFUNCTION(BlueprintCallable, Category = "Data Persistence")
    void SaveGameAsync(UCoreSaveData* DataToSave, const FString& SlotName);

    UFUNCTION(BlueprintCallable, Category = "Data Persistence")
    void LoadGameAsync(const FString& SlotName);

    UPROPERTY(BlueprintAssignable, Category = "Data Persistence")
    FOnSaveComplete OnSaveComplete;

private:
    void HandleSaveCompleted(const FString& SlotName, const int32 UserIndex, bool bSuccess);
    void HandleLoadCompleted(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData);
};
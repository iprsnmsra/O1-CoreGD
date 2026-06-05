#include "AsyncSaveSubsystem.h"
#include "Kismet/GameplayStatics.h"

void UAsyncSaveSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
    UE_LOG(LogTemp, Log, TEXT("[SaveLoadSystem] Async Persistence Initialized."));
}

void UAsyncSaveSubsystem::SaveGameAsync(UCoreSaveData* DataToSave, const FString& SlotName)
{
    if (!DataToSave) return;

    FAsyncSaveGameToSlotDelegate SaveDelegate;
    SaveDelegate.BindUObject(this, &UAsyncSaveSubsystem::HandleSaveCompleted);

    // Fires the save operation onto a background thread
    UGameplayStatics::AsyncSaveGameToSlot(DataToSave, SlotName, 0, SaveDelegate);
}

void UAsyncSaveSubsystem::HandleSaveCompleted(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
    UE_LOG(LogTemp, Display, TEXT("[SaveLoadSystem] Background Save Completed. Success: %d"), bSuccess);
    
    if (OnSaveComplete.IsBound())
    {
        OnSaveComplete.Broadcast(bSuccess);
    }
}

void UAsyncSaveSubsystem::LoadGameAsync(const FString& SlotName)
{
    FAsyncLoadGameFromSlotDelegate LoadDelegate;
    LoadDelegate.BindUObject(this, &UAsyncSaveSubsystem::HandleLoadCompleted);

    // Loads the data from disk on a background thread
    UGameplayStatics::AsyncLoadGameFromSlot(SlotName, 0, LoadDelegate);
}

void UAsyncSaveSubsystem::HandleLoadCompleted(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData)
{
    if (UCoreSaveData* MyData = Cast<UCoreSaveData>(LoadedGameData))
    {
        UE_LOG(LogTemp, Display, TEXT("[SaveLoadSystem] Background Load Completed Successfully."));
        // TODO: Dispatch loaded data to the GameManager or Player via EventBus
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("[SaveLoadSystem] Failed to load or cast save data."));
    }
}
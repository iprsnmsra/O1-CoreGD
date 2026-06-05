#include "CoreGameInstance.h"
#include "Kismet/GameplayStatics.h"
// #include "GlobalEventManager.h" // Integrating with Module 003

void UCoreGameInstance::Init()
{
    Super::Init();
    CurrentState = EGameState::BootSequence;
    UE_LOG(LogTemp, Warning, TEXT("[CoreGameInstance] Master Systems Initialized."));
}

void UCoreGameInstance::ChangeState(EGameState NewState)
{
    if (CurrentState == NewState) return;

    EGameState PreviousState = CurrentState;
    CurrentState = NewState;

    HandleStateInternal(CurrentState);

    // TODO: Broadcast via UGlobalEventManager (Module 003)
    // if (UGlobalEventManager* EventManager = GetSubsystem<UGlobalEventManager>())
    // {
    //     EventManager->BroadcastStateChanged(PreviousState, CurrentState);
    // }

    UE_LOG(LogTemp, Display, TEXT("[GameManager] State Switched: %d -> %d"), (uint8)PreviousState, (uint8)CurrentState);
}

void UCoreGameInstance::HandleStateInternal(EGameState State)
{
    switch (State)
    {
        case EGameState::Paused:
            UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.0f);
            break;
        case EGameState::Gameplay:
            UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);
            break;
        // Additional native state handling here
    }
}
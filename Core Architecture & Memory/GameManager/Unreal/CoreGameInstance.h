#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CoreGameInstance.generated.h"

// O(1) Integer-based Enum for maximum speed
UENUM(BlueprintType)
enum class EGameState : uint8
{
    BootSequence = 0,
    MainMenu,
    Loading,
    Gameplay,
    Cinematic,
    Paused,
    GameOver
};

UCLASS()
class O1COREGD_API UCoreGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    virtual void Init() override;

    UFUNCTION(BlueprintCallable, Category = "State Management")
    void ChangeState(EGameState NewState);

    UFUNCTION(BlueprintPure, Category = "State Management")
    EGameState GetCurrentState() const { return CurrentState; }

private:
    EGameState CurrentState;

    void HandleStateInternal(EGameState State);
};
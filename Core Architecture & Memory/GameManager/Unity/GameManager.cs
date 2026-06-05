using UnityEngine;
using System;

/// <summary>
/// The absolute macro-state of the entire application.
/// </summary>
public enum GameState
{
    BootSequence = 0,
    MainMenu = 1,
    Loading = 2,
    Gameplay = 3,
    Cinematic = 4,
    Paused = 5,
    GameOver = 6
}

// Struct for our EventBus (Module 003 integration)
public struct GameStateChangedEvent
{
    public GameState PreviousState;
    public GameState NewState;
}

/// <summary>
/// Singleton Master State Machine. O(1) complexity, Zero-Allocation.
/// </summary>
public class GameManager : MonoBehaviour
{
    // The strict singleton instance
    public static GameManager Instance { get; private set; }

    public GameState CurrentState { get; private set; }

    private void Awake()
    {
        // Enforce Singleton Pattern
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        
        Instance = this;
        DontDestroyOnLoad(gameObject); // Persist across all levels
        
        CurrentState = GameState.BootSequence;
    }

    /// <summary>
    /// The ONLY way to change the game state. 
    /// </summary>
    public void ChangeState(GameState newState)
    {
        if (CurrentState == newState) return; // Prevent redundant firing

        GameState previous = CurrentState;
        CurrentState = newState;

        // Apply global logic based on state
        HandleStateInternal(newState);

        // Broadcast to all other systems instantly via EventBus
        EventBus<GameStateChangedEvent>.Raise(new GameStateChangedEvent 
        { 
            PreviousState = previous, 
            NewState = CurrentState 
        });

        Debug.Log($"[GameManager] State Switched: {previous} -> {CurrentState}");
    }

    private void HandleStateInternal(GameState state)
    {
        switch (state)
        {
            case GameState.Paused:
                Time.timeScale = 0f; // Instantly freeze physics/ticks
                break;
            case GameState.Gameplay:
                Time.timeScale = 1f;
                break;
            case GameState.Cinematic:
                // Specific lock-downs for narrative moments
                break;
        }
    }
}
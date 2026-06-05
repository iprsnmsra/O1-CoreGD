# 🎮 Module 001: GameManager (Master State Machine)

**The Problem**
In amateur codebases, the player script checks `if (!isPaused)`, the enemy AI checks `if (playerIsAlive)`, and the UI checks `if (inMenu)`. This creates a chaotic web of booleans spread across 50 different files. When a new state is added (like a mid-game cinematic), the developer has to hunt down and update every single script, inevitably breaking the game.

**Uses**
Controlling the absolute macro-flow of the application: Booting, Main Menu, Loading, Gameplay, Paused, Cinematic, and Game Over.

**Importance**
A centralized, deterministic Finite State Machine (FSM) guarantees that the game can only ever be in *one* state at a time. By broadcasting state changes through the Event Bus (Module 003), individual scripts simply listen for the change and disable themselves. The CPU never wastes cycles checking booleans; it acts purely on state-change events.

> *"State is the root of all complexity. Control the state, control the game."*

**🤫 Secret Game Dev Tip**
Never use strings (e.g., `"Playing"`, `"Paused"`) to define your game states. String comparisons allocate memory and take variable time depending on the length of the word. Always use `Enums` (which are just integers under the hood) for O(1), instant, zero-allocation state comparisons.
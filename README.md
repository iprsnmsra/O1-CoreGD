# ⚡ O1-CoreGD: High-Performance, Zero-Allocation AAA Game Architecture

[![AAA Game Dev CI Pipeline](https://github.com/iprsnmsra/O1-CoreGD/actions/workflows/ci_pipeline.yml/badge.svg)](https://github.com/iprsnmsra/O1-CoreGD/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Welcome to the absolute bleeding edge of game performance engineering. **O1-CoreGD** is an elite, production-ready systems framework for **Unreal Engine 5 (C++)** and **Unity (C#)**. Modern engine defaults—such as garbage collection sweeps, reflection lookups, and dynamic heap allocations—introduce microscopic stutters (>0ms frame spikes) that break immersion in fast-paced or massively populated game worlds.

This architecture strips engine execution down to the bare metal. By utilizing compile-time generic injection, static pre-warmed memory allocations, and mathematical ray-casting, every system in this framework executes with $O(1)$ constant-time complexity and absolute zero runtime allocation.

> *"Amateurs worry about adding features. Professionals worry about memory and frame time."*

---

## 🗺️ Architectural Ecosystem

The repository follows a strict, modular directory hierarchy. Core architectural logic remains identical across both implementations, separated cleanly by sub-engine environments.

```text
O1-CoreGD/
├── .github/workflows/              # CI/CD Automated Pipelines
├── 00_Core/                        # Memory, State, and Event Management
├── 01_Input_Camera/                # Controllers, Splines, and FOV Math
├── 02_Locomotion/                  # Kinematics and Physics-Bypassing Movement
├── 03_Combat_Health/               # Projectiles, Raycasting, and Damage Nodes
├── 04_World_Physics/               # Custom Gravity and Vector Fields
├── 05_AI_Navigation/               # Time-sliced Pathfinding and State Machines
├── 06_Animation_IK/                # Procedural Recoil and Bone Manipulation
├── 07_UI_Audio/                    # O(1) Data-Binding and Spatial Sound
├── 08_Level_Visuals/               # Object-Pooled VFX and Streaming
├── 09_Editor_Tools/                # Build Automation and Analytics
├── test.bat                        # Windows Pre-commit Evaluation
├── test.sh                         # Unix Pre-commit Evaluation
└── LICENSE                         # MIT License
```

---

## 📜 The Master Syllabus: 150-Module Roadmap

This repository is currently under active development. Below is the complete architectural roadmap.
*Checked boxes (`[x]`) indicate completed and optimized modules with both C++ and C# implementations.*

### 00. Core Architecture & Memory
- [ ] 001. GameManager: Master state machine
- [x] 002. ObjectPooler: Zero-allocation memory pools
- [x] 003. EventManager: Generic Pub-Sub event bus
- [ ] 004. SaveLoadSystem: Async JSON/Binary serialization
- [ ] 005. SettingsManager: Config parser
- [ ] 006. TimeManager: Chrono-control delta scaling
- [ ] 007. DependencyInjector: Decoupling architectures
- [ ] 008. SceneBootstrapper: Level load initialization
- [ ] 009. PerformanceMonitor: On-screen telemetry
- [ ] 010. StateDictionary: Global variable caching

### 01. Input & Camera Systems
- [ ] 011. InputHandler: Cross-platform bypass
- [ ] 012. RebindManager: Dynamic key binding
- [ ] 013. AnalogDeadzone: Math-based drift cancellation
- [ ] 014. InputBuffer: Action queuing
- [ ] 015. ContextualPrompts: O(1) interaction triggers
- [ ] 016. HapticController: Rumble feedback
- [ ] 017. Camera_TPP: Third-person occlusion math
- [ ] 018. Camera_FPP: First-person head-bob
- [ ] 019. CameraShake: Perlin-noise rotational trauma
- [ ] 020. CinematicSpline: Bezier-curve tracking

### 02. Locomotion (Basic & Advanced)
- [ ] 021. MovementBase: Kinematic character wrapper
- [ ] 022. GroundDetection: Shape-casting math
- [ ] 023. WalkRunSprint: Velocity state-machine
- [ ] 024. JumpLogic: Apex-modifiers and coyote-time
- [ ] 025. CrouchSlide: Momentum-based physics
- [ ] 026. WallRun: Normal-vector gravity shifts
- [ ] 027. LedgeGrab: Edge detection and snapping
- [ ] 028. GrapplingHook: Pendulum physics math
- [ ] 029. DashEvade: I-frame impulse generation
- [ ] 030. ZeroGravity: 6DOF rotational momentum

### 03. Combat, Weaponry & Health
- [ ] 031. WeaponInventory: Fast-array slotting
- [ ] 032. HitscanGun: Infinite-velocity math traces
- [x] 033. ProjectileSystem: Math-driven ray-sweeping
- [ ] 034. MeleeSystem: Frame-perfect hitbox math
- [ ] 035. RecoilPattern: 2D array spray patterns
- [ ] 036. AmmoManager: Localized stack buffers
- [ ] 037. HealthBase: Invulnerability frame logic
- [ ] 038. DamageReceiver: Location-based multipliers
- [ ] 039. ShieldSystem: Regenerative barriers
- [ ] 040. FallDamage: Velocity-to-damage conversion

### 04. World Physics & Mechanics
- [ ] 041. CustomGravity: Directional modifiers
- [ ] 042. DestructibleProp: Health-to-fracture logic
- [ ] 043. BuoyancyVolume: Fluid displacement
- [ ] 044. TetherRope: Verlet integration cables
- [ ] 045. WindZone: Vector-field force
- [ ] 046. MagneticPull: Inverse-square attraction
- [ ] 047. TimeScaleManager: Localized slow-mo
- [ ] 048. BouncePad: Trajectory prediction
- [ ] 049. RagdollController: Kinematic blending
- [ ] 050. KinematicPusher: Moving platform math

### 05. AI, Navigation & Animation
- [ ] 051. AStarPathGrid: Custom NavMesh bypass
- [ ] 052. State_Patrol: Waypoint loops
- [ ] 053. State_Chase: Dynamic targeting
- [ ] 054. LineOfSight: Raycast vision cones
- [ ] 055. FlockingBehavior: Boids algorithm
- [ ] 056. AnimStateDriver: Variable syncing
- [ ] 057. FootIK: Raycast terrain alignment
- [ ] 058. WeaponRecoilAnim: Procedural displacement
- [ ] 059. ProceduralBreathing: Sine-wave expansion
- [ ] 060. RagdollRecovery: Get-up matching

### 06. UI, Audio, and Level Management
- [ ] 061. HUD_Manager: Overlay controller
- [ ] 062. FloatingDamage: Screen-space text pooling
- [ ] 063. DragDropInventory: Slot-array UI
- [ ] 064. DialogueBox: Branching nodes
- [ ] 065. SpatialAudio: 3D falloff attenuation
- [ ] 066. WeaponSoundPool: Pitch-shifted pools
- [ ] 067. SceneLoaderAsync: Background chunking
- [ ] 068. CheckpointSystem: State serialization
- [ ] 069. DayNightCycle: Skybox blending
- [ ] 070. LootDropGen: Weighted probability tables

### 07. Visuals, Media & Tools
- [ ] 071. PostProcessBlender: Volume transitions
- [ ] 072. DecalSpawner: Splatter pooling
- [ ] 073. ParticlePooler: Zero-instantiation VFX
- [ ] 074. OutlineHighlight: Shader logic
- [ ] 075. BuildAutomation: One-click pipelines
- [ ] 076. CSVToData: Spreadsheet to assets
- [ ] 077. DebugConsole: In-game command prompt
- [ ] 078. CrashLogger: Call-stack dumping
- [ ] 079. MemoryProfiler: Asset weight tracking
- [ ] 080. Localizer: Multi-language string tables

*(Modules 81-150 scaling expansions will map out dynamically as foundational pillars are established).*

---

## 🔬 Deep Dive: Active Core Modules

### [002] Object Pooler
* **Problem:** Calling `Instantiate()` or `SpawnActor()` requests memory blocks from the heap. This causes fragmentation and triggers the Garbage Collector, killing frame rates.
* **Solution:** Pre-allocates a fixed array during initialization. Uses a high-speed integer array pointer (`headIndex`) to push and pop objects from memory.
* **Performance:** 0ms latency, $O(1)$ retrieval, zero runtime allocation.

### [003] Global Event Bus
* **Problem:** Traditional event systems pass data via string-hashing dictionary lookups, causing runtime heap allocations and heavy memory bloat.
* **Solution:** Uses compile-time generic injection. Every event struct creates an isolated native delegate stream upon compilation.
* **Performance:** Struct-based parameters pass directly on the execution Stack, completely skipping the Garbage Collector.

### [033] High-Performance Projectiles
* **Problem:** Traditional rigidbodies at high velocities suffer from "tunneling," phasing completely through walls between physical tick frames.
* **Solution:** Bypasses engine physical simulation entirely. The projectile maps translation linearly via delta calculations: `P_new = P_old + (V * DeltaTime)`. It traces a line segment between frames to process impact instantly.
* **Performance:** Bypasses physical component hierarchies, permitting thousands of concurrent projectiles with 0ms physics lag.

---

## ⚙️ Continuous Integration (CI/CD)

This repository utilizes automated static code analysis gates to verify formatting integrity and catch architectural leaks prior to compilation.

* **C# Validation:** Leverages native `dotnet format` engines to scan whitespace, styling syntax rules, and generic compliance.
* **C++ Validation:** Employs explicit `cppcheck` analysis pipelines to intercept wild pointers, uninitialized variables, and structural layout vulnerabilities.

To evaluate modifications locally prior to execution, run the validation binaries directly from the repository root:

```bash
# Windows Ecosystem
.\test.bat

# Unix/POSIX Ecosystem
chmod +x test.sh && ./test.sh
```

---

## 🚀 Integration Protocol

1.  **Clone the Architecture:** Clone `O1-CoreGD` directly into your main project directory.
2.  **Define Environment Structures:** Incorporate structural event definitions within the specified module directories.
3.  **Validate Subsystems:** Ensure all customized modules pass the automated validation parameters locally before pushing modifications.

---
**Developed and Maintained by:** [iprsnmsra](https://github.com/iprsnmsra)  
**License:** Distributed freely under the MIT Architectural Authorization Protocol.

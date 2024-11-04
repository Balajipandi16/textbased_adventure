Here's a sample GitHub documentation (README.md) for your interactive text-based adventure game project. This includes installation instructions, usage, features, and an overview of the code structure.

---

# Text-Based Adventure Game

An interactive, text-based adventure game built in C++ that allows players to experience dynamic story progression, combat, and a save/load feature. This game is designed to be immersive, with modular gameplay mechanics and unpredictable story paths.

## Features

- **Dynamic Story Progression**: Players make choices that affect the storyline, leading to unique outcomes.
- **Combat System**: Fight various enemies with randomized stats.
- **Save/Load Game**: Save progress to a file and load it anytime to resume gameplay.
- **Modular Gameplay**: Easily extend or modify gameplay elements, such as adding new encounters or combat scenarios.

## Tech Stack

- **C++**: Core programming language.
- **Object-Oriented Programming**: Classes for modular design (e.g., `Player`, `Enemy`, `Game`).
- **File I/O**: Save and load game state to/from a file.
- **Dynamic Memory Allocation**: For managing memory dynamically.

---

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Game Overview](#game-overview)
- [Classes](#classes)
- [Save and Load System](#save-and-load-system)


---

## Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Balajipandi16/TextBasedAdventureGame.git
   ```
   
2. **Navigate to the Project Directory**:
   ```bash
   cd TextBasedAdventureGame
   ```

3. **Compile the Game**:
   Use any C++ compiler. For example, with `g++`:
   ```bash
   g++ main.cpp -o adventure_game
   ```

4. **Run the Game**:
   ```bash
   ./adventure_game
   ```

---

## Usage

Upon launching, enter your character's name and start your adventure by making choices. You’ll encounter enemies, engage in combat, and have the option to save or load your game progress.

### Example Commands

- **Choice Prompt**:
    ```
    1. Go left
    2. Go right
    3. Save Game
    4. Load Game
    ```

- **Combat Prompt**:
    ```
    1. Attack
    2. Run
    ```
-**output**
  ```Welcome to the Adventure Game!
Enter your name: balaji
Hello, balaji!

You encounter a fork in the road.
1. Go left
2. Go right
3. Save Game
4. Load Game
Choose an action: 1
A wild Goblin appears!
1. Attack
2. Run
Choose an action: 1
You hit the Goblin for 15 damage.
The Goblin hits you for 16 damage.
1. Attack
2. Run
Choose an action: 2
You ran away safely.

You encounter a fork in the road.
1. Go left
2. Go right
3. Save Game
4. Load Game
Choose an action:
```
---

## Game Overview

- **Encounters**: Encounter different scenarios at forks in the road.
- **Combat**: Randomized combat where you can choose to attack or run.
- **Random Events**: Enemies have varying attack power due to randomization, increasing unpredictability.

---

## Classes

### 1. `Player`

Represents the player character with attributes and actions:
- **Attributes**: `name`, `health`, `attackPower`.
- **Methods**:
  - `takeDamage(int amount)`: Reduces player health.
  - `isAlive()`: Checks if the player is alive.

### 2. `Enemy`

Represents an enemy encountered by the player:
- **Attributes**: `type`, `health`, `attackPower`.
- **Methods**:
  - `takeDamage(int amount)`: Reduces enemy health.
  - `isAlive()`: Checks if the enemy is alive.

### 3. `Game`

Controls the main gameplay loop, encounters, and file I/O for saving/loading:
- **Methods**:
  - `start()`: Starts the game.
  - `encounter()`: Handles player encounters.
  - `combat()`: Engages the player with an enemy.
  - `saveGame()`: Saves the player's state to `savegame.txt`.
  - `loadGame()`: Loads the player's state from `savegame.txt`.

---

## Save and Load System

The save and load system uses file I/O to write and read the player’s game state:

- **Saving**:
  - The `saveGame()` method writes `name`, `health`, and `attackPower` to `savegame.txt`.
- **Loading**:
  - The `loadGame()` method reads the player's state from `savegame.txt` to resume gameplay.

To use this feature, select `Save Game` or `Load Game` when prompted during gameplay.

---


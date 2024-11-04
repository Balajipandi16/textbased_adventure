#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

class Player {
public:
    std::string name;
    int health;
    int attackPower;

    Player(std::string name, int health, int attackPower) 
        : name(name), health(health), attackPower(attackPower) {}

    void takeDamage(int amount) {
        health -= amount;
    }

    bool isAlive() const {
        return health > 0;
    }
};

class Enemy {
public:
    std::string type;
    int health;
    int attackPower;

    Enemy(std::string type, int health, int attackPower) 
        : type(type), health(health), attackPower(attackPower) {}

    void takeDamage(int amount) {
        health -= amount;
    }

    bool isAlive() const {
        return health > 0;
    }
};

class Game {
private:
    Player *player;
    bool gameRunning;

public:
    Game() : gameRunning(true) {
        player = new Player("Hero", 100, 15);
    }

    ~Game() {
        delete player;
    }

    void start() {
        std::cout << "Welcome to the Adventure Game!\n";
        std::cout << "Enter your name: ";
        std::cin >> player->name;
        std::cout << "Hello, " << player->name << "!\n";

        while (gameRunning && player->isAlive()) {
            encounter();
        }

        if (player->isAlive()) {
            std::cout << "Congratulations, you survived the adventure!\n";
        } else {
            std::cout << "Game Over. You have perished.\n";
        }
    }

    void encounter() {
        int choice;
        std::cout << "\nYou encounter a fork in the road.\n";
        std::cout << "1. Go left\n2. Go right\n3. Save Game\n4. Load Game\n";
        std::cout << "Choose an action: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                combat();
                break;
            case 2:
                combat();
                break;
            case 3:
                saveGame();
                break;
            case 4:
                loadGame();
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    void combat() {
        Enemy enemy("Goblin", 50, 10 + rand() % 10);
        std::cout << "A wild " << enemy.type << " appears!\n";

        while (player->isAlive() && enemy.isAlive()) {
            int action;
            std::cout << "1. Attack\n2. Run\n";
            std::cout << "Choose an action: ";
            std::cin >> action;

            if (action == 1) {
                enemy.takeDamage(player->attackPower);
                std::cout << "You hit the " << enemy.type << " for " << player->attackPower << " damage.\n";
                if (enemy.isAlive()) {
                    player->takeDamage(enemy.attackPower);
                    std::cout << "The " << enemy.type << " hits you for " << enemy.attackPower << " damage.\n";
                } else {
                    std::cout << "You defeated the " << enemy.type << "!\n";
                }
            } else if (action == 2) {
                std::cout << "You ran away safely.\n";
                break;
            } else {
                std::cout << "Invalid choice. Try again.\n";
            }
        }
    }

    void saveGame() {
        std::ofstream saveFile("savegame.txt");
        if (saveFile.is_open()) {
            saveFile << player->name << '\n';
            saveFile << player->health << '\n';
            saveFile << player->attackPower << '\n';
            saveFile.close();
            std::cout << "Game saved successfully.\n";
        } else {
            std::cout << "Error saving game.\n";
        }
    }

    void loadGame() {
        std::ifstream loadFile("savegame.txt");
        if (loadFile.is_open()) {
            loadFile >> player->name;
            loadFile >> player->health;
            loadFile >> player->attackPower;
            loadFile.close();
            std::cout << "Game loaded successfully.\n";
        } else {
            std::cout << "Error loading game. File not found.\n";
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    Game game;
    game.start();
    return 0;
}

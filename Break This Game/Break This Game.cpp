// Break This Game.cpp : Defines the entry point for the application.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <unordered_map>

class CheatsManager {
public:
    void enableInvincibility() {
        invincibilityEnabled = true;
        std::cout << "Invincibility enabled!\n";
    }

    void disableInvincibility() {
        invincibilityEnabled = false;
        std::cout << "Invincibility disabled!\n";
    }

    void teleport(float x, float y) {
        playerPosition.x = x;
        playerPosition.y = y;
        std::cout << "Teleported to (" << x << ", " << y << ")!\n";
    }

    bool isInvincible() const {
        return invincibilityEnabled;
    }

    sf::Vector2f getPlayerPosition() const {
        return playerPosition;
    }

private:
    bool invincibilityEnabled = false;
    sf::Vector2f playerPosition{ 0, 0 }; // Initial player position
};

class Console {
public:
    Console(CheatsManager& cheatsManager) : cheatsManager(cheatsManager), isActive(false) {}

    void toggle() {
        isActive = !isActive;
        if (isActive) {
            input.clear(); // Clear input when activated
        }
    }

    void addCommand(const std::string& command) {
        commands.push_back(command);
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if (cmd == "help") {
            std::cout << "Available commands:\n";
            std::cout << "  help - Show this help message\n";
            std::cout << "  exit - Exit the game\n";
            std::cout << "  invincibility - Enable/disable invincibility\n";
            std::cout << "  teleport <x> <y> - Teleport to specified coordinates\n";
            // Add more commands here as needed
        }
        else if (cmd == "exit") {
            exitGame = true; // Flag to exit the game loop
        }
        else if (cmd == "invincibility") {
            if (cheatsManager.isInvincible()) {
                cheatsManager.disableInvincibility();
            }
            else {
                cheatsManager.enableInvincibility();
            }
        }
        else if (cmd == "teleport") {
            float x, y;
            if (iss >> x >> y) {
                cheatsManager.teleport(x, y);
            }
            else {
                std::cout << "Usage: teleport <x> <y>\n";
            }
        }
        else {
            std::cout << "Unknown command: " << command << "\n";
        }
    }

    bool shouldExit() const { return exitGame; }

    void render(sf::RenderWindow& window) {
        if (isActive) {
            // Render console overlay or text here (optional)
        }
    }

    void handleInput(const std::string& input) {
        if (isActive) {
            addCommand(input);
        }
    }

    void clear() {
        input.clear();
    }

private:
    CheatsManager& cheatsManager; // Reference to CheatsManager
    bool isActive;
    bool exitGame = false;
    std::string input;
    std::vector<std::string> commands;
};

class NPC {
public:
    NPC(const std::string& name, const std::vector<std::string>& dialogues)
        : name(name), dialogues(dialogues), currentDialogueIndex(0) {}

    void interact() {
        if (currentDialogueIndex < dialogues.size()) {
            std::cout << name << ": " << dialogues[currentDialogueIndex] << "\n";
            currentDialogueIndex++;
        }
        else {
            std::cout << name << ": I've got nothing else to say.\n";
        }
    }

private:
    std::string name;
    std::vector<std::string> dialogues;
    size_t currentDialogueIndex;
};

class Game {
public:
    Game() {
        window.create(sf::VideoMode(800, 600), "Break This Game");
        initializeNPCs();
    }

    void run() {
        while (window.isOpen()) {
            processEvents();
            if (console.shouldExit()) {
                window.close(); // Close the window if exit command is received
            }
            update();
            render();
        }
    }

private:
    sf::RenderWindow window;
    CheatsManager cheatsManager; // Cheats manager instance
    Console console{ cheatsManager }; // Console instance with cheats manager
    std::vector<std::shared_ptr<NPC>> npcs; // Vector to hold NPCs

    void initializeNPCs() {
        // Create NPCs with misleading hints
        npcs.push_back(std::make_shared<NPC>("Old Man", std::vector<std::string>{
            "Have you tried looking in the shadows?",
                "There's a secret in the ground beneath you.",
                "Maybe if you enter the code 12345, you'll find something.",
                "I wouldn't trust the signs on the walls."}));

        npcs.push_back(std::make_shared<NPC>("Mysterious Stranger", std::vector<std::string>{
            "The true treasure lies within your reach, if only you dare to touch it.",
                "Hacks? They're just enhancements, my friend.",
                "Sometimes the answer is right in front of you... if you can find it."}));
    }

    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::F1) { // Toggle console with F1
                    console.toggle();
                }
                else if (event.key.code == sf::Keyboard::E) { // Interact with NPC with E
                    interactWithNPC();
                }
            }
            else if (event.type == sf::Event::TextEntered) {
                if (console.isActive() && event.text.unicode < 128) {
                    if (event.text.unicode == 13) { // Enter key
                        console.handleInput(console.getInput()); // Process input command
                        console.clear(); // Clear input after processing
                    }
                    else if (event.text.unicode == 8) { // Backspace key
                        console.backspace(); // Remove last character from input
                    }
                    else {
                        console.addChar(static_cast<char>(event.text.unicode)); // Add character to input
                    }
                }
            }
        }
    }

    void interactWithNPC() {
        // Simple interaction logic with the first NPC for demonstration
        if (!npcs.empty()) {
            npcs[0]->interact(); // Interact with the first NPC in the list
        }
    }

    void update() {
        // Update game logic here, check for invincibility status if needed
        if (cheatsManager.isInvincible()) {
            // Logic for when player is invincible
        }
    }

    void render() {
        window.clear(); // Clear the window with black color
        // Render your game objects here
        console.render(window); // Render the console overlay if active
        window.display(); // Display the rendered frame
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}
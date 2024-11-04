#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Console {
public:
    Console() : isActive(false) {}

    void toggle() {
        isActive = !isActive;
        if (isActive) {
            input.clear(); // Clear input when activated
        }
    }

    void addCommand(const std::string& command) {
        commands.push_back(command);
        if (command == "help") {
            std::cout << "Available commands:\n";
            std::cout << "  help - Show this help message\n";
            std::cout << "  exit - Exit the game\n";
            // Add more commands here as needed
        } else if (command == "exit") {
            exitGame = true; // Flag to exit the game loop
        } else {
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
    bool isActive;
    bool exitGame = false;
    std::string input;
    std::vector<std::string> commands;
};

class Game {
public:
    Game() {
        window.create(sf::VideoMode(800, 600), "Break This Game");
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
    Console console;

    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::F1) { // Toggle console with F1
                    console.toggle();
                }
            } else if (event.type == sf::Event::TextEntered) {
                if (console.isActive() && event.text.unicode < 128) {
                    if (event.text.unicode == 13) { // Enter key
                        console.handleInput(console.getInput()); // Process input command
                        console.clear(); // Clear input after processing
                    } else if (event.text.unicode == 8) { // Backspace key
                        console.backspace(); // Remove last character from input
                    } else {
                        console.addChar(static_cast<char>(event.text.unicode)); // Add character to input
                    }
                }
            }
        }
    }

    void update() {
        // Update game logic here
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
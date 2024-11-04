#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game {
public:
    Game() {
        window.create(sf::VideoMode(800, 600), "Break This Game");
    }

    void run() {
        while (window.isOpen()) {
            processEvents();
            update();
            render();
        }
    }

private:
    sf::RenderWindow window;

    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    void update() {
        // Update game logic here
    }

    void render() {
        window.clear(); // Clear the window with black color
        // Render your game objects here
        window.display(); // Display the rendered frame
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}
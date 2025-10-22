#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(500, 500), "Chess Pattern Below Main Diagonal");

    const int n = 10;
    const int cellSize = 50;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setOutlineThickness(1);
                cell.setOutlineColor(sf::Color::Black);

                if (i > j && (i - j) % 2 == 1) {
                    cell.setFillColor(sf::Color::Green);
                }
                else {
                    cell.setFillColor(sf::Color::White);
                }

                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}
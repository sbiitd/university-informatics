#include <SFML/Graphics.hpp>
#include <functional> 
#include <cmath> 
#include <string>
#include <sstream>
#include <iomanip>

void drawGraph(sf::RenderWindow& window, std::function<float(float)> func, float xMin, float xMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray graph(sf::LineStrip);

    for (float x = xMin; x <= xMax; x += 0.1f) {
        float y = func(x);
        float screenX = 400.0f + x * scaleX;
        float screenY = 300.0f - y * scaleY;
        graph.append(sf::Vertex(sf::Vector2f(screenX, screenY), color));
    }

    window.draw(graph);
}

void drawVerticalLine(sf::RenderWindow& window, float xConstant, float yMin, float yMax, float scaleX, float scaleY, sf::Color color) {
    sf::VertexArray line(sf::Lines, 2);
    float screenX = 400.0f + xConstant * scaleX;
    float screenY1 = 300.0f - yMin * scaleY;
    float screenY2 = 300.0f - yMax * scaleY;
    line[0] = sf::Vertex(sf::Vector2f(screenX, screenY1), color);
    line[1] = sf::Vertex(sf::Vector2f(screenX, screenY2), color);
    window.draw(line);
}

std::string formatFloat(float value, int precision = 2) {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(precision) << value;
    return stream.str();
}

std::string determineArea(float x, float y) {
    const float epsilon = 0.05f;

    if (std::abs(y - x) < epsilon) {
        return "Boundary: y = x";
    }
    if (std::abs(x - 3.0f) < epsilon) {
        return "Boundary: x = 3";
    }

    if (x < 3.0f) {
        if (y < x) {
            return "Area 1: x < 3, y < x";
        }
        else {
            return "Area 3: x < 3, y > x";
        }
    }
    else {
        if (y > x) {
            return "Area 2: x > 3, y > x";
        }
        else {
            return "Area 4: x > 3, y < x";
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Graphs: y = x and x = 3");

    sf::CircleShape userPoint(5.0f);
    userPoint.setFillColor(sf::Color::Red);
    userPoint.setOrigin(userPoint.getRadius(), userPoint.getRadius());
    bool userPointExists = false;

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
            return -1;
        }
    }

    sf::Text coordinatesText;
    coordinatesText.setFont(font);
    coordinatesText.setCharacterSize(18);
    coordinatesText.setFillColor(sf::Color::Black);
    coordinatesText.setPosition(10.0f, 10.0f);

    sf::Text areaText;
    areaText.setFont(font);
    areaText.setCharacterSize(18);
    areaText.setFillColor(sf::Color::Blue);
    areaText.setPosition(10.0f, 35.0f);

    sf::VertexArray xAxis(sf::Lines, 2);
    xAxis[0].position = sf::Vector2f(50.0f, 300.0f);
    xAxis[0].color = sf::Color::Black;
    xAxis[1].position = sf::Vector2f(750.0f, 300.0f);
    xAxis[1].color = sf::Color::Black;

    sf::VertexArray yAxis(sf::Lines, 2);
    yAxis[0].position = sf::Vector2f(400.0f, 50.0f);
    yAxis[0].color = sf::Color::Black;
    yAxis[1].position = sf::Vector2f(400.0f, 550.0f);
    yAxis[1].color = sf::Color::Black;

    sf::VertexArray grid(sf::Lines);
    for (int i = -10; i <= 10; i++) {
        if (i != 0) {
            float x = 400.0f + static_cast<float>(i) * 30.0f;
            grid.append(sf::Vertex(sf::Vector2f(x, 50.0f), sf::Color(200, 200, 200)));
            grid.append(sf::Vertex(sf::Vector2f(x, 550.0f), sf::Color(200, 200, 200)));
        }

        if (i != 0) {
            float y = 300.0f - static_cast<float>(i) * 30.0f;
            grid.append(sf::Vertex(sf::Vector2f(50.0f, y), sf::Color(200, 200, 200)));
            grid.append(sf::Vertex(sf::Vector2f(750.0f, y), sf::Color(200, 200, 200)));
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    float mathX = (static_cast<float>(mousePos.x) - 400.0f) / 30.0f;
                    float mathY = -(static_cast<float>(mousePos.y) - 300.0f) / 30.0f;

                    userPoint.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                    userPointExists = true;

                    std::string area = determineArea(mathX, mathY);

                    coordinatesText.setString("Coordinates: x=" + formatFloat(mathX) + ", y=" + formatFloat(mathY));
                    areaText.setString(area);
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(grid);
        window.draw(xAxis);
        window.draw(yAxis);
        drawGraph(window, [](float x) { return x; }, -10.0f, 10.0f, 30.0f, 30.0f, sf::Color::Red);
        drawVerticalLine(window, 3.0f, -10.0f, 10.0f, 30.0f, 30.0f, sf::Color::Blue);

        if (userPointExists) {
            window.draw(userPoint);
            window.draw(coordinatesText);
            window.draw(areaText);
        }

        window.display();
    }

    return 0;
}
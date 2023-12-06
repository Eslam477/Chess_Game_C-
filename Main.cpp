#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Chessboard");
    sf::RectangleShape square(sf::Vector2f(50.f, 50.f));

    bool isWhite = true;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            square.setPosition(i * 50.f, j * 50.f);

            if (isWhite)
                square.setFillColor(sf::Color::White);
            else
                square.setFillColor(sf::Color::Green);

            isWhite = !isWhite;

            window.draw(square);
        }

        isWhite = !isWhite;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.display();
    }

    return 0;
}
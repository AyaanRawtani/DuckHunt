#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::VideoMode videoMode = sf::VideoMode(800, 600);

    sf::RenderWindow window(videoMode, "SFML Window");



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Blue);

        window.display();
    }

    return 0;
}
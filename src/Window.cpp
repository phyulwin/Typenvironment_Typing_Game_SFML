//
// Created by Kelly Lwin on 1/14/2023.
//

#include "Window.h"

Window::Window() {
    sf::RenderWindow window(sf::VideoMode(500, 500, 32), "Test");
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::Green);
    circle.setRadius(250.f);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

        }
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }
}

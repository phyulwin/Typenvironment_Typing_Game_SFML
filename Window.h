//
// Created by Kelly Lwin on 1/14/2023.
//

#ifndef SFML_TEMPLATE_WINDOW_H
#define SFML_TEMPLATE_WINDOW_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Window {
private:
    const sf::Vector2f windowSizes = {1400, 1201};
    static const unsigned int charSize= 50;
public:
    Window();
};


#endif //SFML_TEMPLATE_WINDOW_H

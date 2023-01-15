//
// Created by Kelly Lwin on 1/14/2023.
//

#ifndef SFML_TEMPLATE_MOUSEEVENTS_H
#define SFML_TEMPLATE_MOUSEEVENTS_H
#include <iostream>
#include <SFML\Graphics.hpp>

class MouseEvents {
public:
    template<class T>
    static bool isHovered(const T& obj, const sf::RenderWindow& window);
    template<class T>
    static bool isClicked(const T& obj, const sf::RenderWindow& window);
};

#include "MouseEvents.cpp"
#endif //SFML_TEMPLATE_MOUSEEVENTS_H

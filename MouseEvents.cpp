//
// Created by Kelly Lwin on 1/14/2023.
//
#ifndef SFML_TEMPLATE_MOUSEEVENTS_CPP
#define SFML_TEMPLATE_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template<class T>
bool MouseEvents::isHovered(const T & obj, const sf::RenderWindow & window){
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return obj.getGlobalBounds().contains(mpos);
}

template<class T>
bool MouseEvents::isClicked(const T & obj, const sf::RenderWindow & window){
    return isHovered(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

#endif //SFML_TEMPLATE_MOUSEEVENTS_CPP
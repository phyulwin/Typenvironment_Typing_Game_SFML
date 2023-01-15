//
// Created by Kelly Lwin on 1/14/2023.
//

#ifndef SFML_TEMPLATE_MENU_H
#define SFML_TEMPLATE_MENU_H
#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>

//#include "Window.h"
#include "Object.h"

#include "MouseEvents.h"
#include "Type.h"

//Main Menu or starting screen
//includes game theme graphics
class Menu: public sf::Sprite {
private:
    //window resolutions
    const sf::Vector2f windowSizes = {1200, 950}; //using 3:2 resolution
    static const unsigned int charSize_title= 80; //font size (title)
    static const unsigned int charSize= 50; //default size

    //overall assets
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Texture buttonTexture;
    sf::Sprite startButton;
    sf::Font gamefont;

    //start screen assets
    std::string gameTitleString = "Game\nTitle";
    sf::Text gameTitle;

    //items in stack to display on window
    std::stack<sf::Sprite> startScreenItems;
    std::stack<sf::Text> startScreenTexts;
public:
    Menu();
    void setupGraphicsStartScreen();
    static void setupBackground(sf::Texture& backgroundTexture, sf::Sprite& background);
    void setupGameTitle();
    void setupStartButton();

    static void moveObject(Object& object);
};


#endif //SFML_TEMPLATE_MENU_H

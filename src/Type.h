//
// Created by Kelly Lwin on 1/14/2023.
//

#ifndef SFML_TEMPLATE_TYPE_H
#define SFML_TEMPLATE_TYPE_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Objects.h"
//this is the game play window
//inherited by menu
class Type : public Objects {
private:
    //draw three buttons on game screen
    sf::Texture buttonBackground;
    const sf::Vector2f BUTTON_SCALE = {1.5, 1.5};
    static const unsigned int charSize= 20; //default size

    sf::Sprite fishCountButton;
    sf::Sprite trashCountButton;
    sf::Sprite timerButton;

    sf::Text fishCountText;
    sf::Text trashCountText;
    sf::Text timerText;

    //count how many fish are killed
    //count how many trash are missed
    int fishKilled = 0;
    int trashMissed = 0;

    sf::Font buttonFont;
public:
    Type();
    void startTypingGame(sf::RenderWindow& window, sf::Event& event, sf::Sprite& background);

    void setUpGraphics();
    void setButtonPositions();
    void setTextPositions();

    void drawButtons(sf::RenderWindow& window);
    void drawButtonTexts(sf::RenderWindow& window);

    void updateButtonText();
    void setButtonTextFont();
    void setButtonTextColor();
    void setCharSize();
};


#endif //SFML_TEMPLATE_TYPE_H

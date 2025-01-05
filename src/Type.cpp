//
// Created by Kelly Lwin on 1/14/2023.
//

#include "Type.h"

Type::Type() {
    std::cout << "game starts" << std::endl;
    setUpGraphics();

}

void Type::setUpGraphics() {
    buttonBackground.loadFromFile("Assets/Images/buttonbackground.png");
    fishCountButton.setTexture(buttonBackground);
    trashCountButton.setTexture(buttonBackground);
    timerButton.setTexture(buttonBackground);

    //set Button Scale
    fishCountButton.setScale(BUTTON_SCALE);
    trashCountButton.setScale(BUTTON_SCALE);
    timerButton.setScale(BUTTON_SCALE);

    //set Button positions
    setButtonPositions();
    //set Text positions
    updateButtonText(); //same as setString
    setButtonTextFont();
    setButtonTextColor();
    setTextPositions();
    setCharSize();
}

void Type::setButtonPositions() {
    fishCountButton.setPosition({450, 50});
    trashCountButton.setPosition({450, fishCountButton.getPosition().y+125});
    timerButton.setPosition({450, trashCountButton.getPosition().y+125});
}

void Type::setTextPositions() {
    //set text relative to button pos
    fishCountText.setPosition({fishCountButton.getPosition().x+20, fishCountButton.getPosition().y+40});
    trashCountText.setPosition({trashCountButton.getPosition().x+20, trashCountButton.getPosition().y+40});
    timerText.setPosition({timerButton.getPosition().x+20, timerButton.getPosition().y+40});
}

void Type::drawButtons(sf::RenderWindow &window) {
    window.draw(this->fishCountButton);
    window.draw(this->trashCountButton);
    window.draw(this->timerButton);
}

void Type::drawButtonTexts(sf::RenderWindow &window) {
    window.draw(this->fishCountText);
    window.draw(this->trashCountText);
    window.draw(this->timerText);
}

void Type::startTypingGame(sf::RenderWindow &window, sf::Event& event, sf::Sprite& background) {
    while(window.isOpen())
    {
        //sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(background);
        drawButtons(window);
        drawButtonTexts(window);
        //update button text
        updateButtonText();
        window.display();
    }
    std::cout << "Buttons are drawn" << std::endl;
}

void Type::updateButtonText() {
    fishCountText.setString("FISH KILLED ("+std::to_string(fishKilled)+"/3)");
    trashCountText.setString("TRASH MISSED ("+std::to_string(trashMissed)+"/5)");
    timerText.setString("Time: ");
}

void Type::setButtonTextFont() {
    buttonFont.loadFromFile("Assets/Fonts/massnormalfont.ttf");
    fishCountText.setFont(buttonFont);
    trashCountText.setFont(buttonFont);
    timerText.setFont(buttonFont);
}

void Type::setButtonTextColor() {
    fishCountText.setFillColor(sf::Color::Black);
    trashCountText.setFillColor(sf::Color::Black);
    timerText.setFillColor(sf::Color::Black);
}

void Type::setCharSize() {
    fishCountText.setCharacterSize(charSize);
    trashCountText.setCharacterSize(charSize);
    timerText.setCharacterSize(charSize);
}

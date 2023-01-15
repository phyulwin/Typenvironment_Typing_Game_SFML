//
// Created by Kelly Lwin on 1/14/2023.
//

#include "Menu.h"

Menu::Menu() {
    setupGraphicsStartScreen();

    sf::RenderWindow window(sf::VideoMode(windowSizes.x, windowSizes.y, 32), "Game Title");
    window.setFramerateLimit(60);

    //test - draw one sample object
    Object waterbottle(PLASTIC_BOTTLE);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            //call event listener
            if(MouseEvents::isClicked(startButton, window)) {
                startScreenTexts.pop();
                startScreenItems.pop();
                //start game

                Type startTyping;
                startTyping.startTypingGame(window, event, background);
            }
        }
        window.clear(sf::Color::Black);
//        window.draw(background);

        if(!startScreenTexts.empty() && !startScreenItems.empty()) {
            window.draw(background);
            window.draw(gameTitle);
            window.draw(startButton);
        } else {
            //this is the game screen
            window.draw(waterbottle);
        }
        window.display();
    } //window is not open at this point
}

void Menu::setupGraphicsStartScreen() {
    //set up background graphics
    setupBackground(this->backgroundTexture, this->background);
    //set up game title
    setupGameTitle();
    setupStartButton();

    startScreenTexts.push(gameTitle);
    startScreenItems.push(startButton);
}

void Menu::setupBackground(sf::Texture& backgroundTexture, sf::Sprite& background) {
    //set up background graphics
    backgroundTexture.loadFromFile("Assets/Images/backgroundImage.jpg");
    backgroundTexture.setRepeated(1);
    background.setTexture(backgroundTexture);
    background.setScale({0.23, 0.23});
    background.setPosition({0, 0});
//    background.setOrigin({20, 0});
}

void Menu::setupGameTitle() {
    gamefont.loadFromFile("Assets/Fonts/massnormalfont.ttf");

    gameTitle.setString(gameTitleString);
    gameTitle.setFont(gamefont);
    gameTitle.setFillColor(sf::Color::White);
    gameTitle.setPosition({windowSizes.x/3, windowSizes.y-300});
    gameTitle.setCharacterSize(charSize_title);
}

void Menu::setupStartButton() {
    buttonTexture.loadFromFile("Assets/Images/samplebutton.png");
    startButton.setTexture(buttonTexture);
    startButton.setScale({0.5, 0.5});
    startButton.setPosition({windowSizes.x/3, windowSizes.y-500});
}

void Menu::moveObject(Object &object) {
    float newX = object.getPosition().x + 30;
    object.setPosition({newX, object.getPosition().y});
}

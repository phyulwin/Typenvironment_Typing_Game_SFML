//
// Created by Kelly Lwin on 1/14/2023.
//

#include "Object.h"

Object::Object() {
    //create game objects
    //Objects objects
}

Object::Object(objectsEnum objectEnum) : objectEnum(objectEnum) {
    //set texture
    loadObjTexture();
    //set random word from wordbank for word
    setObjWord();
    //test
    std::cout << wordString << std::endl;
}

void Object::loadObjTexture() {
    switch(this->objectEnum) {
        case 0:
            objTexture.loadFromFile("Assets/Images/waterbottle.png");
            break;
        case 1:
            objTexture.loadFromFile("Assets/Images/plasticbag1.png");
            break;
        case 2:
            objTexture.loadFromFile("Assets/Images/plasticbag2.png");
            break;
        case 3:
            objTexture.loadFromFile("Assets/Images/sodacan.png");
            break;
        case 4:
            objTexture.loadFromFile("Assets/Images/fish.png");
            isFish = true;
            break;
        //default is fish image
        default:
            objTexture.loadFromFile("Assets/Images/fish.png");
            isFish = true;
            break;
    }
    this->obj.setTexture(objTexture);
    this->obj.setScale(OBJ_SCALE);
    this->obj.setPosition({100, row1.y});
}

void Object::setObjWord() {
    //load font
    wordFont.loadFromFile("Assets/Fonts/massnormalfont.ttf");

    setRandomWord(wordString);

    word.setString(wordString);
    word.setFont(wordFont);
    word.setFillColor(sf::Color::White);
    //word.setPosition({50, 50});
    word.setPosition(obj.getPosition());
    word.setCharacterSize(20);
}

void Object::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->obj);
    target.draw(this->word);
}

void Object::setRandomWord(std::string &wordString) {
    Word objWord = wordbank.getWord();
    wordString = objWord.getString();
    std::cout << wordString << std::endl;
}

void Object::moveObject(Object &object, sf::Vector2f& velocity) {
    object.move(velocity);
}

void Object::changeVelocity(sf::Vector2f &velocity, const sf::Vector2f& newVelocity) {
    velocity = newVelocity;
}

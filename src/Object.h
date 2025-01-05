//
// Created by Kelly Lwin on 1/14/2023.
//

#ifndef SFML_TEMPLATE_OBJECT_H
#define SFML_TEMPLATE_OBJECT_H
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Wordbank.h"
#include "objectEnum.h"

//these are individual objects floating in the water
class Object: public sf::Sprite, public Wordbank {
private:
    Wordbank wordbank;
    //WINDOW OVERALL GRAPHICS
    //window resolutions to calculate object position
    const sf::Vector2f windowSizes = {1200, 950}; //using 3:2 resolution
    //there are three rows for objects to float in the river
    sf::Vector2f row1 = {1200, windowSizes.y-100};

    //OBJECT GRAPHICS
    const sf::Vector2f OBJ_SCALE = {0.7, 0.7};

    sf::Sprite obj; //object is a sprite type
    sf::Texture objTexture; //object image or texture
//    Word word; //word on object _ to be drawn relatively to obj position
    std::string wordString = "";
    sf::Text word;
    sf::Font wordFont;

    //set these two depending on the png image/texture
    objectsEnum objectEnum; //object type
    bool isFish = false; //check if the object is a fish or trash

    //object movement
    sf::Vector2f velocity = {0, 0};
public:
    Object();
    //use states
    Object(objectsEnum objectEnum);

    //setters
    void loadObjTexture();//load objectImage
    void setObjWord(); //this is independent of object type (fish or not)
    void setRandomWord(std::string& wordString); //get random word from wordbank and set the text on object

    static void moveObject(Object& object, sf::Vector2f& velocity);
    static void changeVelocity(sf::Vector2f& velocity, const sf::Vector2f& newVelocity);
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFML_TEMPLATE_OBJECT_H

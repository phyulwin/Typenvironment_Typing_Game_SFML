//
// Created by Kelly Lwin on 1/14/2023.
//

#ifndef SFML_TEMPLATE_WORD_H
#define SFML_TEMPLATE_WORD_H
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Word: sf::Drawable {
private:
    std::string word;
    static const unsigned int charSize= 50; //default size
public:
    sf::Text wordText;

    Word();
    Word(const std::string& word);
    friend std::ostream& operator<<(std::ostream& out, const Word& word);
    std::string getString() const;
    void setString(const std::string word);
    void setWordTextPos(sf::Vector2f position);

private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //SFML_TEMPLATE_WORD_H

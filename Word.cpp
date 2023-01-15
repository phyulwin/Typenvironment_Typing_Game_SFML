//
// Created by Kelly Lwin on 1/14/2023.
//

#include "Word.h"
Word::Word() {
    //default constructor
    this->wordText.setCharacterSize(charSize);
    this->wordText.setFillColor(sf::Color::White);
}

Word::Word(const std::string &word)
        : word(word) {
}

std::ostream &operator<<(std::ostream &out, const Word &word) {
    out << word.word;
    return out;
}

std::string Word::getString() const {
    return this->word;
}

void Word::setString(const std::string word) {
    this->word = word;
}

void Word::setWordTextPos(sf::Vector2f position) {
    this->wordText.setPosition(position);
}

void Word::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->wordText);
}

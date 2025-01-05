//
// Created by Kelly Lwin on 1/14/2023.
//

#include "Wordbank.h"
void Wordbank::loadFromFile(const std::string filename) {
    std::ifstream fin;
    std::string next;
    fin.open(filename);
    if(fin.fail()) {
        exit(30);
    }
    while(getline(fin, next)) {
        words.push(next);
    }
    fin.close();
}

Wordbank::Wordbank() {
    //default word bank
    loadFromFile("easywords.txt");
}

Wordbank::Wordbank(const std::string filename) {
    loadFromFile(filename);
}

void Wordbank::addWord(const std::string &word) {
    words.push(Word(word));
}

void Wordbank::addWord(const Word &word) {
    words.push(Word(word));
}

Word Wordbank::getWord() {
    if(!hasWords()) {
        std::cout << "There are no words in the wordbank." << std::endl;
    }
    Word temp = words.top();
    words.pop();
    return temp;
}

Word Wordbank::getRandomWord() {
    int enumValue = rand() % wordStrings.size();
    if(!hasWords()) {
        std::cout << "There are no words in the wordbank." << std::endl;
    }
    Word temp = wordStrings.at(enumValue);
    return temp;
}

void Wordbank::remove() {
    words.pop();
}

bool Wordbank::hasWords() const {
    return !words.empty();
}
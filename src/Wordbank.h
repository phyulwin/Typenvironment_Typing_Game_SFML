//
// Created by Kelly Lwin on 1/14/2023.
//

#ifndef SFML_TEMPLATE_WORDBANK_H
#define SFML_TEMPLATE_WORDBANK_H
#include <iostream>

#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <stack>
#include <vector>

#include <fstream>
#include <string>

#include "Word.h"

class Wordbank {
private:
    std::stack<Word> words;
    std::vector<Word> wordStrings;
public:
    Wordbank();
    Wordbank(const std::string filename);
    void loadFromFile(const std::string filename);
    void addWord(const std::string& word);
    void addWord(const Word& word);
    Word getWord();
    Word getRandomWord();
    void remove();
    bool hasWords() const;
};


#endif //SFML_TEMPLATE_WORDBANK_H

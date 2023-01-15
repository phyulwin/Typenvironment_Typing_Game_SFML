//
// Created by Kelly Lwin on 1/14/2023.
//

#include "Game.h"

Game::Game() {
    srand(time(NULL));
    //load words into wordbank
    //check time and load words
//    Wordbank wordbank("easywords.txt");
//    std::cout << "words loaded" << std::endl;

    Menu(); //loads interactive game screen
}

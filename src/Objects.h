//
// Created by Kelly Lwin on 1/14/2023.
//

#ifndef SFML_TEMPLATE_OBJECTS_H
#define SFML_TEMPLATE_OBJECTS_H
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <stack>

#include "Object.h"

class Objects {
private:
    std::stack<Object> objects;
//    bool isVisible; //check if the object is visible on screen
public:
    Objects();
};


#endif //SFML_TEMPLATE_OBJECTS_H

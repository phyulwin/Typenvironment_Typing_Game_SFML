//
// Created by Kelly Lwin on 1/14/2023.
//

#include "Objects.h"

Objects::Objects() {
    //create random 20 objects and push into stack
    int enumValue = rand() % 4;
    for(int i=0; i<20; i++) {
        objects.push(Object(static_cast<objectsEnum>(enumValue)));
    }
}



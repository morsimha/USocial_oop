//
// Created by morsimha on 8/5/2023.
//

#include "Photo.h"
#include <iostream>

Photo::Photo() : Media() {

}

Photo::~Photo() {

}

void Photo::display() {
    std::cout << "Displaying photo from: " << filePath << std::endl;
}


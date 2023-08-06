//
// Created by morsimha on 8/5/2023.
//

#include "Photo.h"
#include <iostream>

Photo::Photo() : Media() {

}

Photo::~Photo() {

}
// Photo's display function
void Photo::display() {
    std::cout << "  Displaying an image... " << path << std::endl;
}
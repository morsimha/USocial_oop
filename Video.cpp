//
// Created by morsimha on 8/5/2023.
//

#include <iostream>
#include "Media.h"
#include "Video.h"


Video::Video() : Media() {
}

Video::~Video() {
}

// Video's display function

void Video::display() {
    std::cout << "  playing a Video.. " << std::endl;
}
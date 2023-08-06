//
// Created by morsimha on 8/5/2023.
//

#include "Media.h"
#include <string>
#include <iostream>
#include "Audio.h"

Audio::Audio() : Media() {
}

Audio::~Audio() {
}

// Audio's display function
void Audio::display() {
    std::cout << "  Playing some Audio.." << std::endl;
}

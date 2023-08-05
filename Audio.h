//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_AUDIO_H
#define MAMAN_11_AUDIO_H

#include <iostream>
#include "Media.h"

class Audio : public Media {
    double duration;

public:
    Audio(const std::string &file, double d) : Media(file), duration(d) {}
    void display() const override {
        std::cout << "Audio: " << filename << " with duration: " << duration << " seconds\n";
    }
};
#endif //MAMAN_11_AUDIO_H

//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_VIDEO_H
#define MAMAN_11_VIDEO_H

#include <iostream>
#include "Media.h"

class Video : public Media {
public:
    Video(const std::string &file) : Media(file) {}
    void display() const override {
        std::cout << "Playing video: " << filename << "\n";
    }
};

#endif //MAMAN_11_VIDEO_H

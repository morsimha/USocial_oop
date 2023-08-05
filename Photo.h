//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_PHOTO_H
#define MAMAN_11_PHOTO_H

#include <iostream>
#include "Media.h"

class Photo : public Media {
    int width;
    int height;

public:
    Photo(const std::string &file, int w, int h) : Media(file), width(w), height(h) {}
    void display() const override {
        std::cout << "Image: " << filename << " with dimensions: " << width << "x" << height << "\n";
    }
};


#endif //MAMAN_11_PHOTO_H

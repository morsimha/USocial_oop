//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_POST_H
#define MAMAN_11_POST_H

#include <iostream>
#include "Media.h"

class Post {
    std::string text;
    Media* media;

public:
    Post(const std::string& t, Media* m = nullptr) : text(t), media(m) {}
    void display() const {
        std::cout << "Post: " << text << "\n";
        if (media) media->display();
    }
};

#endif //MAMAN_11_POST_H

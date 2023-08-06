//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_POST_H
#define MAMAN_11_POST_H
#include <string>
#include "Media.h"

class Post {
private:
    std::string text;
    Media* media;

public:
    Post(std::string text);
    Post(std::string text, Media* media);
    ~Post();

    std::string getText();
    Media* getMedia();
};

#endif //MAMAN_11_POST_H

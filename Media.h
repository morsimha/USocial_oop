//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_MEDIA_H
#define MAMAN_11_MEDIA_H

// Abstract class for media objects
class Media {
public:
    Media(const std::string &file) : filename(file) {}
    virtual void display() const = 0;

    std::string filename;
};

#endif //MAMAN_11_MEDIA_H



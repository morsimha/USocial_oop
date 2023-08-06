//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_MEDIA_H
#define MAMAN_11_MEDIA_H

#include <string>

class Media {
protected:
    std::string path; // Where the media file's at

public:
    Media(); // Default empty constructor
    virtual void display() = 0; // Display function, to be defined in a derived class
    std::string getFilePath();
};

#endif //MAMAN_11_MEDIA_H



//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_MEDIA_H
#define MAMAN_11_MEDIA_H

#include <string>

class Media {
protected:
    std::string filePath;

public:
    Media(); // Default empty constructor
    virtual void display() = 0; // Pure virtual function
    std::string getFilePath();
};

#endif //MAMAN_11_MEDIA_H



//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_VIDEO_H
#define MAMAN_11_VIDEO_H

#include "Media.h"

class Video : public Media {
public:
    Video();
    virtual ~Video();
    void display() override;
};


#endif //MAMAN_11_VIDEO_H

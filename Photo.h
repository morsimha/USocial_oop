//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_PHOTO_H
#define MAMAN_11_PHOTO_H

#include "Media.h"

class Photo : public Media {
public:
    Photo();
    virtual ~Photo();
    void display() override;
};


#endif //MAMAN_11_PHOTO_H

//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_AUDIO_H
#define MAMAN_11_AUDIO_H

#include "Media.h"

class Audio : public Media {
public:
    Audio();
    virtual ~Audio();
    void display() override;
};
#endif //MAMAN_11_AUDIO_H

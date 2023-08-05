//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_MESSAGE_H
#define MAMAN_11_MESSAGE_H

#include <string>

class Message {
private:
    std::string text;

public:
    Message(std::string text);
    std::string getText();
};

#endif //MAMAN_11_MESSAGE_H

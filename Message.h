//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_MESSAGE_H
#define MAMAN_11_MESSAGE_H

#include <string>

class Message {
private:
    std::string text;
    std::string senderName;

public:
    Message(std::string text);
    Message(std::string text, std::string senderName);
    std::string getText();
    std::string getSenderName();
};

#endif //MAMAN_11_MESSAGE_H

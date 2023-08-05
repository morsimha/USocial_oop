//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_MESSAGE_H
#define MAMAN_11_MESSAGE_H

#include <iostream>

class Message {
    std::string text;

public:
    Message(const std::string& t) : text(t) {}
    void display() const {
        std::cout << "Message: " << text << "\n";
    }
};

#endif //MAMAN_11_MESSAGE_H

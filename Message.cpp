//
// Created by morsimha on 8/5/2023.
//

#include "Message.h"

Message::Message(std::string text): text(text){};
Message::Message(std::string text, std::string senderName) : text(text), senderName(senderName) {} // Modify the constructor

std::string Message::getText() {
    return text;
}

std::string Message::getSenderName() { // Implement the new method
    return senderName;
}
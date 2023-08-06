//
// Created by morsimha on 8/5/2023.
//

#include "Message.h"
// two constructors for a Message. One takes just the text of the message,
// and the other also includes the sender's name.
Message::Message(std::string text): text(text){};
Message::Message(std::string text, std::string senderName) : text(text), senderName(senderName) {}

std::string Message::getText() {
    return text;
}

std::string Message::getSenderName() {
    return senderName;
}
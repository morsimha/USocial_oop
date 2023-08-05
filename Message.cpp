//
// Created by morsimha on 8/5/2023.
//

#include "Message.h"

Message::Message(std::string text) : text(text) {}

std::string Message::getText() {
    return text;
}
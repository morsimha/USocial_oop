//
// Created by morsimha on 8/5/2023.
//

#include "BusinessUser.h"
#include <iostream>
#include "User.h"

BusinessUser::BusinessUser()
{
}

BusinessUser::~BusinessUser()
{
}
void BusinessUser::sendMessage(User *user, Message *message)
{
    SendMessage(user, message); // using our own SendMessage method
}

void BusinessUser::SendMessage(User *user, Message *message)
{
    try {
        user->receiveMessage(message); // Try to send the message
    }

    catch (const std::runtime_error& e) {
        std::cerr << "Error in sendMessage: " << e.what() << std::endl;
    }
}
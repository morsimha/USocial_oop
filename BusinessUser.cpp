//
// Created by morsimha on 8/5/2023.
//

#include "BusinessUser.h"
#include <iostream>
#include "User.h"

BusinessUser::BusinessUser()
{
    // You can initialize specific attributes for a business user here, if needed
}

BusinessUser::~BusinessUser()
{
    // Perform any cleanup specific to business users here, if needed
}
void BusinessUser::sendMessage(User *user, Message *message)
{
    SendMessage(user, message);
}

void BusinessUser::SendMessage(User *user, Message *message)
{
    try {
        user->receiveMessage(message);
    }

    catch (const std::runtime_error& e) {
        std::cerr << "Error in sendMessage: " << e.what() << std::endl;
    }
}
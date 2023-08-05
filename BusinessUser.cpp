//
// Created by morsimha on 8/5/2023.
//

#include "BusinessUser.h"

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
    // Implement specific behavior for sending a message from a business user
    // For example, you might want to log the message, add special formatting, etc.

    // Call the base class implementation (or replace with custom logic)
    User::sendMessage(user, message);
}
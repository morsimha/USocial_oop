//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_BUSINESSUSER_H
#define MAMAN_11_BUSINESSUSER_H

#include "User.h"

class BusinessUser : public User
{
public:
    BusinessUser();
    virtual ~BusinessUser();

    // Overriding the sendMessage method
    void sendMessage(User *user, Message *message) override;
    void SendMessage(User *user, Message *message);
};

#endif // MAMAN_11_BUSINESSUSER_H

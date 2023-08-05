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

    // Override the sendMessage method specific to BusinessUser
    void sendMessage(User *user, Message *message) override;
};

#endif // MAMAN_11_BUSINESSUSER_H

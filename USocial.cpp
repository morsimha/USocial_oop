//
// Created by morsimha on 8/5/2023.
//
#include "USocial.h"
#include "BusinessUser.h"
#include "User.h"

class User;
// registering a new user. If they're a business user, creating a BusinessUser object, otherwise just a regular User object.

User *USocial::registerUser(const std::string name, bool isBusiness)
{
    User *newUser = isBusiness ? new BusinessUser() : new User();
    newUser -> name = name;
    newUser -> us = this;
    unsigned long id = users.size()+1;
    users[id] = newUser;
    return newUser;
}

// when we need to remove a user from our system. find them in our users map and then erase them.
void USocial::removeUser(User *userToRemove)
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if (it->second == userToRemove)
        {
            delete it->second;
            users.erase(it);
            break;
        }
    }
}

//find a user by its id, if not found return null
User *USocial::getUserById(unsigned long id)
{
    auto it = users.find(id); // Find user by id
    if (it != users.end())
    {
        return it->second; // If found, return the user
    }
    return nullptr; // If not found, return nullptr
}
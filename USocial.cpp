//
// Created by morsimha on 8/5/2023.
//
#include "USocial.h"
#include "BusinessUser.h" // Make sure to include this if BusinessUser is defined in a separate header
#include "User.h"

class User;
User *USocial::registerUser(const std::string name, bool isBusiness)
{
    User *newUser = isBusiness ? new BusinessUser() : new User();
    newUser -> name = name;
    newUser -> us = this;
    unsigned long id = users.size()+1; // This could be replaced with a more robust ID generation logic
    users[id] = newUser;
    return newUser;
}

void USocial::removeUser(User *userToRemove)
{
    for (auto it = users.begin(); it != users.end(); ++it)
    {
        if (it->second == userToRemove)
        {
            delete it->second; // Free memory for the user
            users.erase(it);   // Remove the user from the map
            break;             // Exit the loop as the iterator is now invalid
        }
    }
}

User *USocial::getUserById(unsigned long id)
{
    auto it = users.find(id); // Find user by id
    if (it != users.end())
    {
        return it->second; // If found, return the user
    }
    return nullptr; // If not found, return nullptr
}
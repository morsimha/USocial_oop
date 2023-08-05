//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_USOCIAL_H
#define MAMAN_11_USOCIAL_H

#include <string>
#include <map>

class User; // Forward declaration of User

class USocial
{
    friend class User;

private:
    std::map<unsigned long, User *> users;

public:
    User *registerUser(std::string name, bool isBussiness = false);
    void removeUser(User *user);
    User *getUserById(unsigned long id);
};

#endif //MAMAN_11_USOCIAL_H

//
// Created by morsimha on 8/5/2023.
//

#ifndef MAMAN_11_USER_H
#define MAMAN_11_USER_H

#include "USocial.h"
#include "Post.h"
#include "Message.h"
#include <string>
#include <list>

class USocial; // Forward declaration

class User
{
    friend class USocial;
protected:
    static unsigned long idCounter; // Declare static member
    USocial *us;
    unsigned long id;
    std::string name;
    std::list<unsigned long> friends;
    std::list<Post *> posts;
    std::list<Message *> receivedMsgs; // Corrected typo
    User();
    virtual ~User();

public:
    unsigned long getId();
    std::string getName();
    void addFriend(User *);
    void removeFriend(User *user);
    void post(std::string postContent); // Use std::string
    void post(std::string, Media *); // Use std::string
    std::list<Post *> getPosts();
    void viewFriendsPosts();
    void receiveMessage(Message *); // Corrected function name
    virtual void sendMessage(User *, Message *);
    void viewReceivedMessages();
}; // Added semicolon

#endif //MAMAN_11_USER_H



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

class USocial;

class User
{  // USocial has access to User's private and protected members
    friend class USocial;
protected:
    static unsigned long idCounter;
    USocial *us;
    unsigned long id;
    std::string name;
    std::list<unsigned long> friends;
    std::list<Post *> posts;
    std::list<Message *> receivedMsgs;
    User();
    virtual ~User();

public:
    unsigned long getId();
    std::string getName();
    void addFriend(User *);
    void removeFriend(User *user);
    void post(std::string postContent);
    void post(std::string, Media *);
    std::list<Post *> getPosts();
    void viewFriendsPosts();
    void receiveMessage(Message *);
    virtual void sendMessage(User *, Message *);
    void viewReceivedMessages();
};

#endif //MAMAN_11_USER_H



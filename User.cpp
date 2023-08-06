//
// Created by morsimha on 8/5/2023.
//

#include <iostream>
#include "User.h"
#include "algorithm"
// initializing static member
unsigned long User::idCounter = 0;

User::User()
{
    id = ++idCounter;
    name = "";
    us = nullptr;
}

User::~User()
{   //deleting all posts and messages
    for (auto &post : posts)
    {
        delete post;
    }

    for (auto &message : receivedMsgs)
    {
        delete message;
    }

}

unsigned long User::getId()
{
    return id;
}

std::string User::getName()
{
    return name;
}

void User::addFriend(User *user)
{
    friends.push_back(user->getId());
}

void User::removeFriend(User *user)
{
    friends.remove(user->getId());
}
// storing the new post
void User::post(std::string postContent)
{
    Post *newPost = new Post(postContent);
    posts.push_back(newPost);
}

void User::post(std::string content, Media *media)
{
    Post *newPost = new Post(content, media);
    posts.push_back(newPost);
}

std::list<Post *> User::getPosts()
{
    return posts;
}
void User::viewFriendsPosts()
{// storing the new post
    try {
        for (auto it = friends.begin(); it != friends.end(); ++it)
        {
            User *friendUser = us->getUserById(*it);
            if (friendUser == nullptr) throw std::runtime_error("Friend user not found.");
            for (auto post : friendUser->getPosts())
            {
                std::cout << "Post from " << friendUser->getName() << ": " << post->getText() << std::endl;
                if(post-> getMedia() != nullptr){
                    post->getMedia()->display();
                }
            }
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Error viewing friends' posts: " << e.what() << '\n';
    }
}


void User::receiveMessage(Message *message)
{
    if (message == nullptr) throw std::invalid_argument("Message cannot be null.");
    receivedMsgs.push_back(message);
}

void User::sendMessage(User *user, Message *message)
{
    // sending message to a friend
    try {
        auto it = std::find(friends.begin(), friends.end(), user->getId());
        if (it != friends.end()) {
            user->receiveMessage(message);
        }
        else {
            throw std::runtime_error("Cannot send message: User is not a friend");
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error in sendMessage: " << e.what() << std::endl;
    }
}

void User::viewReceivedMessages()
{
    // displaying each received message
    try {
        for (auto message : receivedMsgs)
        {
            if (message == nullptr) throw std::runtime_error("Received null message.");
            std::cout << "From " << message->getSenderName() << ": " << message->getText() << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Error viewing received messages: " << e.what() << '\n';
    }
}
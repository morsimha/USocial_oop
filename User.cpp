//
// Created by morsimha on 8/5/2023.
//

#include <iostream>
#include "User.h"

unsigned long User::idCounter = 0; // Definition of static member

User::User()
{
    id = ++idCounter;
    name = "";
    us = nullptr;
}

User::~User()
{
    for (auto &post : posts)
    {
        delete post;
    }

    for (auto &message : receivedMsgs)
    {
        delete message;
    }
    // us is
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

void User::post(std::string postContent)
{
    Post *newPost = new Post(postContent);
    posts.push_back(newPost); // Added this line to store the new post.
}

void User::post(std::string content, Media *media)
{
    Post *newPost = new Post(content, media);
    posts.push_back(newPost); // Added this line to store the new post with media.
}

std::list<Post *> User::getPosts()
{
    return posts;
}

void User::viewFriendsPosts()
{
    for (auto it = friends.begin(); it != friends.end(); ++it)
    {
        // Assuming a function to get the user by ID, then display their posts.
        User *friendUser = us->getUserById(*it);
        for (auto post : friendUser->getPosts())
        {
            post->getMedia()->display(); // Assuming a display function in Post class.
        }
    }
}

void User::receiveMessage(Message *message) // Corrected typo 'recieve' to 'receive'.
{
    receivedMsgs.push_back(message); // Added to store received message.
}

void User::sendMessage(User *user, Message *message)
{
    user->receiveMessage(message); // Assuming the user should receive the message.
}

void User::viewReceivedMessages()
{
    for (auto message : receivedMsgs)
    {
        std::cout << message->getText() << std::endl;
    }
}


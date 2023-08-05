#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept> // For exception handling
#include "Media.h"
#include "Photo.h"
#include "Audio.h"
#include "Video.h"
#include "Post.h"
#include "Message.h"



// Forward declaration

class User; // Forward declaration

class User {
protected:
    std::string name;
    std::vector<User*> friends;
    std::vector<Post*> posts;
    std::vector<Message*> messages;

    friend class US; // Declare USocial as a friend of User


public:
    User(const std::string& n) : name(n) {}
    void addPost(Post* post) { posts.push_back(post); }
    virtual void sendMessage(User* recipient, const std::string& text);
    void receiveMessage(Message* msg) { messages.push_back(msg); } // Public method to add a message
    void addFriend(User* user) {
        // Check if the user is already a friend
        if (std::find(friends.begin(), friends.end(), user) != friends.end()) {
            throw std::runtime_error("User is already a friend.");
        }
        friends.push_back(user);
    }

    void printFriends() {
        auto printFriendName = [](User* friendUser) {
            std::cout << friendUser->name << "\n";
        };

        std::cout << "Friends of " << name << ":\n";
        std::for_each(friends.begin(), friends.end(), printFriendName);
    }
};

void User::sendMessage(User *recipient, const std::string &text) {

}

class USocial {
    std::vector<User*> users;
    friend class user; // Declare USocial as a friend of User


public:
    USocial() { std::cout << "USocial social network initialized.\n"; }
    void registerUser(User* user) { users.push_back(user); }
};


class BusinessUser : public User {
public:
    BusinessUser(const std::string& n) : User(n) {}
    void sendMessage(User* recipient, const std::string& text) override;
};


void BusinessUser::sendMessage(User* recipient, const std::string& text) {
    Message* msg = new Message(text);
    recipient->receiveMessage(msg); // Use the public method
}

// Example usage
int main() {
    USocial usocial;
    auto alice = new User("Alice"); // Using auto for type inference
    auto bob = new User("Bob");
    auto company = new BusinessUser("Company");

    usocial.registerUser(alice);
    usocial.registerUser(bob);
    usocial.registerUser(company);

    alice->addFriend(bob); // Alice and Bob are friends

    Media* media1 = new Photo("photo.jpg", 800, 600);
    Post* post1 = new Post("Alice's post with photo", media1);
    alice->addPost(post1);

    try {
        company->sendMessage(bob, "Promotion message to Bob");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    auto arik = new User("Arik");
    auto bibi = new User("Bibi");

    arik->addFriend(bibi);
    arik->printFriends();

    post1->display(); // Display Alice's post

    // Don't forget to free allocated memory
    delete post1;
    delete media1;
    delete alice;
    delete bob;
    delete company;


//    USocial us;
//    User *u1 = us.registerUser("Liron");
//    User *u2 = us.registerUser("Yahav");
//    User *u3 = us.registerUser("Shachaf");
//    User *u4 = us.registerUser("Tsur", true);
//    User *u5 = us.registerUser("Elit");
//    u1->post("Hello world!");
//    u2->post("I'm having a great time here :)", new Audio());
//    u3->post("This is awesome!", new Photo());
//    u5->addFriend(u1);
//    u5->addFriend(u2);
//    u5->viewFriendsPosts(); // should see only u1, u2 s' posts
//    u4->sendMessage(u5, new Message("Buy Falafel!"));
//    u5->viewReceivedMessages();
//    try
//    {
//        u3->sendMessage(u5, new Message("All your base are belong to us"));
//    }
//    catch (const std::exception &e)
//    {
//        std::cout << "error: " << e.what() << std::endl;
//    }
//    u5->viewReceivedMessages();
//    u3->addFriend(u5);
//    u3->sendMessage(u5, new Message("All your base are belong to us"));
//    u5->viewReceivedMessages()


    return 0;
}

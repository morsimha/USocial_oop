#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


// Abstract class for media objects
class Media {
public:
    Media(const std::string &file) : filename(file) {}
    virtual void display() const = 0;

protected:
    std::string filename;
};

class Photo : public Media {
    int width;
    int height;

public:
    Photo(const std::string &file, int w, int h) : Media(file), width(w), height(h) {}
    void display() const override {
        std::cout << "Displaying photo: " << filename << " with dimensions: " << width << "x" << height << "\n";
    }
};

class Audio : public Media {
    double duration;

public:
    Audio(const std::string &file, double d) : Media(file), duration(d) {}
    void display() const override {
        std::cout << "Playing audio: " << filename << " with duration: " << duration << " seconds\n";
    }
};

class Video : public Media {
public:
    Video(const std::string &file) : Media(file) {}
    void display() const override {
        std::cout << "Playing video: " << filename << "\n";
    }
};

class Post {
    std::string text;
    Media* media;

public:
    Post(const std::string& t, Media* m = nullptr) : text(t), media(m) {}
    void display() const {
        std::cout << "Post: " << text << "\n";
        if (media) media->display();
    }
};

class Message {
    std::string text;

public:
    Message(const std::string& t) : text(t) {}
    void display() const {
        std::cout << "Message: " << text << "\n";
    }
};

class User; // Forward declaration

class User {
protected:
    std::string name;
    std::vector<User*> friends;
    std::vector<Post*> posts;
    std::vector<Message*> messages;

public:
    User(const std::string& n) : name(n) {}

    void addFriend(User* user) { friends.push_back(user); }
    void addPost(Post* post) { posts.push_back(post); }
    virtual void sendMessage(User* recipient, const std::string& text);
    void receiveMessage(Message* msg) { messages.push_back(msg); } // Public method to add a message

};

class US {
    std::vector<User*> users;

public:
    US() { std::cout << "USocial social network initialized.\n"; }
    void addUser(User* user) { users.push_back(user); }
   // void addMediaToUser(User* user, Media* media) { user->addMedia(media); }
    // Additional functionalities
};

class BusinessUser : public User {
public:
    BusinessUser(const std::string& n) : User(n) {}
    void sendMessage(User* recipient, const std::string& text) override;
    // Other functionalities specific to business users
};

void User::sendMessage(User* recipient, const std::string& text) {
    if (std::find(friends.begin(), friends.end(), recipient) != friends.end()) {
        Message* msg = new Message(text);
        recipient->receiveMessage(msg); // Use the public method
    }
}

void BusinessUser::sendMessage(User* recipient, const std::string& text) {
    Message* msg = new Message(text);
    recipient->receiveMessage(msg); // Use the public method
}

// Example usage
int main() {
    US usocial;
    User* alice = new User("Alice");
    User* bob = new User("Bob");
    BusinessUser* company = new BusinessUser("Company");

    usocial.addUser(alice);
    usocial.addUser(bob);
    usocial.addUser(company);

    alice->addFriend(bob); // Alice and Bob are friends

    Media* media1 = new Photo("photo.jpg", 800, 600);
    Post* post1 = new Post("Alice's post with photo", media1);
    alice->addPost(post1);

    company->sendMessage(bob, "Promotion message to Bob");

    post1->display(); // Display Alice's post

    // Don't forget to free allocated memory
    delete post1;
    delete media1;
    delete alice;
    delete bob;
    delete company;

    return 0;
}




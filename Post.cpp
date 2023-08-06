//
// Created by morsimha on 8/5/2023.
//

#include "Post.h"

Post::Post(std::string text) : text(text), media(nullptr) {} // constructor for a post without media

Post::Post(std::string text, Media* media) : text(text), media(media) {} // constructor for a post with media

Post::~Post() {
    delete media;
}
// returns the text and media of the post
std::string Post::getText() {
    return text;
}

Media* Post::getMedia() {
    return media;
}

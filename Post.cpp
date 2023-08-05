//
// Created by morsimha on 8/5/2023.
//

#include "Post.h"

Post::Post(std::string text) : text(text), media(nullptr) {}

Post::Post(std::string text, Media* media) : text(text), media(media) {}

// Add this destructor definition.
Post::~Post() {
    delete media;
}

std::string Post::getText() {
    return text;
}

Media* Post::getMedia() {
    return media;
}
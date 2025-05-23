# USocial - Social Media Platform

## Overview
USocial is a C++ implementation of a social media platform that allows users to interact with each other through posts, messages, and media sharing. The system supports both regular and business users, with different messaging capabilities.

## Class Structure

### Core Components
- **USocial**: The main platform class that manages user registration and user lookup
- **User**: Base class for all users with standard social media functionality
- **BusinessUser**: Extended user class with enhanced messaging capabilities
- **Message**: Represents messages exchanged between users
- **Post**: Content posted by users, can include media attachments

### Media Hierarchy
- **Media**: Abstract base class for all media types
  - **Photo**: For image content
  - **Audio**: For audio content
  - **Video**: For video content

## Features

### User Management
- Register regular and business users
- Remove users from the platform
- Look up users by ID

### Social Interactions
- Add and remove friends
- View friends' posts
- Exchange messages (with friend restriction for regular users)
- Create posts with or without media attachments

### Media Support
The platform supports different types of media content:
- Photos: Images that can be displayed
- Audio: Sound files that can be played
- Video: Video content that can be played

## Implementation Details

### Class Relationships
- **Inheritance**:
  - `BusinessUser` inherits from `User` to gain enhanced messaging abilities
  - `Photo`, `Audio`, and `Video` inherit from the abstract `Media` class
  
- **Composition**:
  - `Post` contains `Media` objects
  - `User` maintains lists of `Post` and `Message` objects

### Memory Management
- The system handles resource cleanup via appropriate destructors
- Utilizes dynamic memory for media objects and posts

### Exception Handling
- Robust error handling for message sending, friend operations, and content viewing
- Protections against null pointers and invalid operations

## Usage Example
The system's functionality is demonstrated in the `main.cpp` file, which shows:
- User registration (both regular and business users)
- Creating posts with different media types
- Managing friend relationships
- Sending and receiving messages with permissions
- Error handling for restricted operations

## Building the Project
This project uses standard C++ and can be compiled with any C++11 compatible compiler.

```bash
# Example compilation with g++
g++ -std=c++11 *.cpp -o USocial
```

## Design Patterns
- **Factory Pattern**: Used in `USocial` for creating different types of users
- **Strategy Pattern**: Different media types implement the display strategy differently

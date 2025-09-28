#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "User.h"
#include "Message.h"

class Database
{
    std::vector<User> _users;
    std::vector<Message> _messages;

    struct UserStatus {
        bool isBanned = false;
        bool isDisconnected = false;
    };
    std::unordered_map<int, UserStatus> _userStatuses; // ключ — userId
    std::unordered_map<std::string, int> _usersMapByName;

public:
    Database();

    int addUser(std::string username, std::string password);
    int checkPassword(std::string username, std::string password);

    void addChatMessage(std::string sender, std::string);
    bool addPrivateMessage(std::string sender, std::string target, std::string message);

    std::vector<std::string> getChatMessages();
    std::vector<Message> getPrivateMessage(int userID = -1);
    std::vector<Message> getAllMessages();

    std::vector<User> getAllUsers() const;

    // Методы управления статусами
    void banUser(int userId);
    void disconnectUser(int userId);
    struct UserStatus getUserStatus(int userId);
};

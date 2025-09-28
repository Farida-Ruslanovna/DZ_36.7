#include "Database.h"

Database::Database() : _users(), _messages()
{
    // Инициализация по необходимости
}

int Database::addUser(std::string username, std::string password)
{
    // Реализация добавления пользователя
    // ...
    // После добавления:
    int newUserId = /* ваш код получения ID */;
    _users.emplace_back(newUserId, username, password);
    _usersMapByName[username] = newUserId;
    _userStatuses[newUserId] = UserStatus{};
    return newUserId;
}

int Database::checkPassword(std::string username, std::string password)
{
    // Проверка пароля
    // ...
    return -1; // если не найден или неверный пароль
}

// Другие методы...

void Database::banUser(int userId)
{
    auto it = _usersMapByName.find(getUserName(userId));
    if (it != _usersMapByName.end()) {
        _userStatuses[it->second].isBanned = true;
    }
}

void Database::disconnectUser(int userId)
{
    auto it = _usersMapByName.find(getUserName(userId));
    if (it != _usersMapByName.end()) {
        _userStatuses[it->second].isDisconnected = true;
    }
}

struct Database::UserStatus Database::getUserStatus(int userId)
{
    auto it = _usersMapByName.find(getUserName(userId));
    if (it != _usersMapByName.end())
        return _userStatuses[it->second];
    return UserStatus{};
}

std::vector<Message> Database::getAllMessages()
{
    return _messages;
}

std::vector<User> Database::getAllUsers() const
{
    return _users;
}
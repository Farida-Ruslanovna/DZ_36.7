#include "Database.h"

Database::Database() : _users(), _messages()
{
    // Инициализация по необходимости
}

int Database::addUser(std::string username, std::string password)
{
    // Проверяем, есть ли уже такой пользователь
    if (_usersMapByName.find(username) != _usersMapByName.end()) {
        // Пользователь с таким именем уже существует
        return -1; 
    }

    // Генерируем новый ID пользователя
    int newUserId = _users.empty() ? 1 : _users.back().id + 1;

    // Добавляем пользователя в список
    _users.emplace_back(newUserId, username, password);
    _usersMapByName[username] = newUserId;
    _userStatuses[newUserId] = UserStatus{};

    return newUserId;
}

int Database::checkPassword(std::string username, std::string password)
{
    auto it = _usersMapByName.find(username);
    if (it != _usersMapByName.end()) {
        int userId = it->second;

        // Находим пользователя по ID
        auto userIt = std::find_if(_users.begin(), _users.end(),
            [&](const User& user) { return user.id == userId; });

        if (userIt != _users.end()) {
            if (userIt->password == password) {
                return userId; // Успешная авторизация
            } else {
                return -2; // Неверный пароль
            }
        }
    }
    return -1; // Пользователь не найден
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

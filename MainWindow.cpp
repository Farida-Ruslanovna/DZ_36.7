#include "MainWindow.h"
#include <QMessageBox>

// Обновленная функция загрузки пользователей
void MainWindow::loadUsers()
{
    userList->clear();
    auto users = database.getAllUsers();

    for (const auto& user : users)
    {
        int userId = user.getUserID();
        auto status = database.getUserStatus(userId);

        QString displayText = QString("%1 (ID:%2)").arg(QString::fromStdString(user.getuserName())).arg(userId);
        if (status.isBanned)
            displayText += " [Заблокирован]";
        if (status.isDisconnected)
            displayText += " [Отключен]";
        userList->addItem(displayText);
    }
}

// Обновленная функция загрузки сообщений
void MainWindow::loadMessages()
{
    messageTable->clearContents();
    auto messages = database.getAllMessages();

    messageTable->setRowCount((int)messages.size());
    for (int i = 0; i < (int)messages.size(); ++i)
    {
        QString msgText = QString::fromStdString(messages[i].getText());
        QString sender = QString::fromStdString(messages[i].getSender());
        QString displayMsg = "<" + sender + ">: " + msgText;
        QTableWidgetItem* item = new QTableWidgetItem(displayMsg);
        messageTable->setItem(i, 0, item);
    }
}

// Обработчик бана пользователя
void MainWindow::onBanButtonClicked()
{
    auto item = userList->currentItem();
    if (!item)
    {
        QMessageBox::warning(this, "Внимание", "Выберите пользователя для бана");
        return;
    }

    QString text = item->text();
    int idStart = text.lastIndexOf("ID:") + 3;
    int idEnd = text.lastIndexOf(")");
    int userId = text.mid(idStart, idEnd - idStart).toInt();

    // Баним пользователя
    database.banUser(userId);
    loadUsers();
    loadMessages();
}

// Обработчик отключения пользователя
void MainWindow::onDisconnectButtonClicked()
{
    auto item = userList->currentItem();
    if (!item)
    {
        QMessageBox::warning(this, "Внимание", "Выберите пользователя для отключения");
        return;
    }

    QString text = item->text();
    int idStart = text.lastIndexOf("ID:") + 3;
    int idEnd = text.lastIndexOf(")");
    int userId = text.mid(idStart, idEnd - idStart).toInt();

    // Отключаем пользователя
    database.disconnectUser(userId);
    loadUsers();
    loadMessages();
}
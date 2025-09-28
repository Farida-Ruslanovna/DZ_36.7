#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void loadUsers();
    void loadMessages();
    void onBanButtonClicked();
    void onDisconnectButtonClicked();

private:
    Database database;

    QListWidget* userList;
    QTableWidget* messageTable;
    QPushButton* banButton;
    QPushButton* disconnectButton;

    void setupUI();
};
#endif
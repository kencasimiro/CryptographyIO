#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    databaseManager::instance();            // an instance of the database - database should be open

    loginWindow login;

    login.show();               // shoes login window

    return a.exec();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "databaseManager.h"
#include "loginWindow.h"
#include "addLogin.h"
#include "deleteLogin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_LOGOUT_clicked();        // logout

    void on_pushButton_ADD_clicked();           // add login

    void on_pushButton_DELETE_clicked();        // delete login

    void on_pushButton_EDIT_clicked();          // edit login

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

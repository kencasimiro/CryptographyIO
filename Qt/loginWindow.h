#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

#include "loginManager.h"
#include "mainwindow.h"
#include "forgotUsername.h"

namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = 0);
    ~loginWindow();

private slots:
    void on_pushButton_submit_clicked();            // submit button

    void on_pushButton_FORGOTUNAME_clicked();       // forgot username

    void on_pushButton_FORGOTPASS_clicked();        // forgot password

private:
    Ui::loginWindow *ui;
};

#endif // LOGINWINDOW_H

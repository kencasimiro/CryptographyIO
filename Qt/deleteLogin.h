#ifndef DELETELOGIN_H
#define DELETELOGIN_H

#include <QDialog>

#include "login.h"
#include "loginManager.h"
#include "mainwindow.h"

/**
 *@author Kenneth Casimiro
 *@date May 2018
 */

namespace Ui {
class deleteLogin;
}

class deleteLogin : public QDialog
{
    Q_OBJECT

public:
    explicit deleteLogin(QWidget *parent = 0);
    ~deleteLogin();

private slots:
    void on_pushButton_BACK_clicked();

    void on_pushButton_SUBMIT_clicked();

private:
    Ui::deleteLogin *ui;
};

#endif // DELETELOGIN_H

#ifndef ADDLOGIN_H
#define ADDLOGIN_H

#include <QDialog>
#include <qcryptographichash.h>         // used for hashing (SHA256)

#include "login.h"
#include "loginManager.h"
#include "mainwindow.h"

/**
 *@author Kenneth Casimiro
 *@date May 2018
 */

namespace Ui {
class addLogin;
}

class addLogin : public QDialog
{
    Q_OBJECT

public:
    explicit addLogin(QWidget *parent = 0);
    ~addLogin();

private slots:
    void on_pushButton_BACK_clicked();          // back

    void on_pushButton_SUBMIT_clicked();        // submit

private:
    Ui::addLogin *ui;
};

#endif // ADDLOGIN_H

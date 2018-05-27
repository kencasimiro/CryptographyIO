#ifndef FORGOTPASSWORD_H
#define FORGOTPASSWORD_H

#include <QDialog>

#include "loginWindow.h"

/**
 *@author Kenneth Casimiro
 *@date May 2018
 */

namespace Ui {
class forgotPassword;
}

class forgotPassword : public QDialog
{
    Q_OBJECT

public:
    explicit forgotPassword(QWidget *parent = 0);
    ~forgotPassword();

private slots:
    void on_pushButton_BACK_clicked();

    void on_pushButton_SUBMIT_clicked();

private:
    Ui::forgotPassword *ui;
};

#endif // FORGOTPASSWORD_H

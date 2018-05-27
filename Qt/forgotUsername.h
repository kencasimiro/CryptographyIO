#ifndef FORGOTUSERNAME_H
#define FORGOTUSERNAME_H

#include <QDialog>

#include "loginWindow.h"

/**
 *@author Kenneth Casimiro
 *@date May 2018
 */

namespace Ui {
class forgotUsername;
}

class forgotUsername : public QDialog
{
    Q_OBJECT

public:
    explicit forgotUsername(QWidget *parent = 0);
    ~forgotUsername();

private slots:
    void on_pushButton_BACK_clicked();      // back button

    void on_pushButton_SUBMIT_clicked();

private:
    Ui::forgotUsername *ui;
};

#endif // FORGOTUSERNAME_H

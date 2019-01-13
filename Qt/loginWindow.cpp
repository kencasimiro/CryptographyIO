#include "loginWindow.h"
#include "ui_loginWindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
    ui->lineEdit_Password->setEchoMode(QLineEdit::Password);    // causes the lineEdit to show as asteriks to hide passwords entry
}

loginWindow::~loginWindow()
{
    delete ui;
}

// authenticate the login information
void loginWindow::on_pushButton_submit_clicked()
{
    QString username = ui->lineEdit_Username->text();       // user input - username
    QString password = ui->lineEdit_Password->text();       // user input - password

    qDebug() << "User entered username: " << ui->lineEdit_Username->text();
    qDebug() << "User entered password: " << ui->lineEdit_Password->text();

    login temp;

    temp = loginManager::instance().authenticate(username, password);   // checks if its authentic

    if(temp != NULL_USER)
    {
        qDebug() << "Authentication successful!";                                                             // successful message in console
        QMessageBox::information(this,QObject::tr("System Message"),tr("Login successful!"),QMessageBox::Ok); // success message in running program
        MainWindow* mainwin = new MainWindow(this);
        this->close();                                                                                        // closes current window
        mainwin->show();                                                                                      // directs to main menu window
    }
    else
    {
        qDebug() << "Authentication failed!";                                                             // fail message in console
        QMessageBox::information(this,QObject::tr("System Message"),tr("Login failed!"),QMessageBox::Ok); // fail message in running program
        ui->lineEdit_Username->clear();                                                                   // clear user input - username
        ui->lineEdit_Password->clear();                                                                   // clear user input - password
    }
}

void loginWindow::on_pushButton_FORGOTUNAME_clicked()
{
    forgotUsername* forgotUname = new forgotUsername(this);
    this->close();                                                                                        // closes current window
    forgotUname->show();                                                                                  // directs to forgot username window
}

void loginWindow::on_pushButton_FORGOTPASS_clicked()
{
    forgotPassword* forgotPword = new forgotPassword(this);
    this->close();                                                                                        // closes current window
    forgotPword->show();                                                                                  // durects to forgot password
}

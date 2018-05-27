#include "forgotPassword.h"
#include "ui_forgotPassword.h"
#include "randomString.h"           // random generated string function

forgotPassword::forgotPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forgotPassword)
{
    ui->setupUi(this);
}

forgotPassword::~forgotPassword()
{
    delete ui;
}

void forgotPassword::on_pushButton_BACK_clicked()
{
    loginWindow* logWin = new loginWindow(this);
    this->close();                                  // closes current window
    logWin->show();                                 // directs to new login window
}

void forgotPassword::on_pushButton_SUBMIT_clicked()
{
    QString email = ui->lineEdit_EMAIL->text();
    QString username = ui->lineEdit_USERNAME->text();
    QString idNum = ui->lineEdit_ID->text();
        int id = idNum.toInt();                      // converts id number from string to int
    QString password = ui->lineEdit_PASSWORD->text();


    if(email.isEmpty() || username.isEmpty() || idNum.isEmpty())
    {
        QMessageBox::information(this,QObject::tr("System Message"),tr("Error: Please fill in all information."),QMessageBox::Ok); // message if failed
    }
    else
    {
        QSqlQuery query;
        query.prepare("SELECT id, email, username FROM LoginInfo WHERE id = :id AND email = :email AND username = :username");   // selects data from sql database
        query.bindValue(":id", id);         // gets user input of id to use in sql
        query.bindValue(":email", email);   // gets user input of email to use in sql
        query.bindValue(":username", username);

        if(query.exec())
        {
            query.next();
            QString dbID = query.value(0).toString();           // stores data of id num
            QString dbEmail = query.value(1).toString();        // stores data of email
            QString dbUsername = query.value(2).toString();     // stores data of username

            if(dbID == idNum && email == dbEmail && dbUsername == username)   // checks if the id's and email match
            {
                QMessageBox::information(this,QObject::tr("System Message"),tr("Password has been changed!"),QMessageBox::Ok); // message if failed
                qDebug() << "Information matches!";

                QString salt = GetRandomString();                           // calls GetRandomString to generate a random 12 character string

                qDebug() << password << " <---- BEFORE SALT - forgotPassword";               // error-check in console for password
                qDebug() << salt     << " <---- AFTER random string - forgotPassword";       // error-check in console for random generated string (salt)

                password = password + salt;                                 // combines the password and salt

                qDebug() << password << " <---- AFTER SALT - forgotPassword";                // error-check in console for the password+salt

                QByteArray hash = QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Sha256);     // cmputes the hash of the password+salt with the SHA256 algorithm

                hash = hash.toHex();            // converts the hash to hex for ASCII (string)

                qDebug() << hash << " <----- HASH - forgotPassword";                         // error check in console for generated hash

                QSqlQuery update;
                update.prepare("UPDATE LoginInfo SET password = :hash, salt = :salt WHERE id = :id AND email = :email AND username = :username");   // updates password with matched information
                update.bindValue(":id", id);                // id number
                update.bindValue(":email", email);          // email
                update.bindValue(":username", username);    // username
                update.bindValue(":hash", hash);            // hashes password
                update.bindValue(":salt", salt);            // random generated string (salt)

                if(update.exec())
                {
                    qDebug() << "Password has been changed!";               // message for success
                }
                else
                {
                    qDebug() << "Password did not change: FAILED!";         // message for failure
                }
            }
            else
            {
                QMessageBox::information(this,QObject::tr("System Message"),tr("Information does not match!"),QMessageBox::Ok); // message if failed
                qDebug() << "Information does not match!";
            }
        }
    }

    ui->lineEdit_EMAIL->clear();
    ui->lineEdit_USERNAME->clear();
    ui->lineEdit_ID->clear();
    ui->lineEdit_PASSWORD->clear();
}

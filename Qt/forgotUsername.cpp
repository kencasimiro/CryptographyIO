#include "forgotUsername.h"
#include "ui_forgotUsername.h"

forgotUsername::forgotUsername(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forgotUsername)
{
    ui->setupUi(this);
}

forgotUsername::~forgotUsername()
{
    delete ui;
}

void forgotUsername::on_pushButton_BACK_clicked()
{
    loginWindow* logWin = new loginWindow(this);
    this->close();                                  // closes current window
    logWin->show();                                 // directs to new login window
}

void forgotUsername::on_pushButton_SUBMIT_clicked()
{
    QString email = ui->lineEdit_EMAIL->text();         // gets user input - email address
    QString idNum = ui->lineEdit_ID->text();            // gets user input - id number
        int id    = idNum.toInt();                      // converts id number from string to int


        if(email.isEmpty() || idNum.isEmpty())      // checks if line edits are empt
        {
            QMessageBox::information(this,QObject::tr("System Message"),tr("Error: Please fill in all information."),QMessageBox::Ok); // message if failed
        }
        else
        {
            QSqlQuery query;
            query.prepare("SELECT id, email, username FROM LoginInfo WHERE id = :id AND email = :email");   // selects data from sql database
            query.bindValue(":id", id);         // gets user input of id to use in sql
            query.bindValue(":email", email);   // gets user input of email to use in sql

            if(query.exec())
            {
                query.next();
                QString dbID = query.value(0).toString();           // stores data of id num
                QString dbEmail = query.value(1).toString();        // stores data of email
                QString dbUsername = query.value(2).toString();     // stores data of username

                if(dbID == idNum && email == dbEmail)   // checks if the id's and email match
                {
                    QMessageBox::information(this,QObject::tr("Username: "),dbUsername,QMessageBox::Ok);        // outputs the username, does not output the Username:
                    qDebug() << "Username has been recovered!";
                }
                else
                {
                    QMessageBox::information(this,QObject::tr("System Message"),tr("Error! ID and or email is not in our database."),QMessageBox::Ok); // message if failed
                    qDebug() << "Username was not recovered! ID and or Email did not match any record from the database";
                }
            }
            else
            {
                QMessageBox::information(this,QObject::tr("System Message"),tr("Error! ID and or email is not in our database."),QMessageBox::Ok); // message if failed
                qDebug() << "Search query has failed!";
            }
        }
}

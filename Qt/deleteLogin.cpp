#include "deleteLogin.h"
#include "ui_deleteLogin.h"

deleteLogin::deleteLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteLogin)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("SELECT * FROM LoginInfo");       // selects all from loginInfo table in SQLite
    query.exec();                                   // executes the prepare

    ui->tableWidget->setColumnCount(5);                                                                                 // determines column size to 5
    ui->tableWidget->setRowCount(query.size());                                                                         // determine row size
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);                                      // make the table expanding
    ui->tableWidget->setHorizontalHeaderLabels(QString("Account ID;Email Address;Username;Password;Salt").split(";"));   // label the headers

    // reads in from the database and display the data
    int i=0;
    while(query.next()) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));      // ID
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));      // Email Address
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));      // Username
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));      // Password
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));      // Salt
        i++;
    }
}

deleteLogin::~deleteLogin()
{
    delete ui;
}

// Closes current window
// Directs to main menu window
void deleteLogin::on_pushButton_BACK_clicked()
{
    MainWindow* mainwin = new MainWindow(this);
    this->close();
    mainwin->show();
}

// On submitl it takes the user input id number and checks in the database to be deleted
void deleteLogin::on_pushButton_SUBMIT_clicked()
{
    QString loginID = ui->lineEdit_ID->text();                  // user input id number
    int testID;
    testID = loginID.toInt();                                   // convert string to int

    bool n;

    n = loginManager::instance().deleteLoginAccount(testID);    // executes delete login account function

    if(n == true)
    {
        QMessageBox::information(this,QObject::tr("System Message"),tr("Login account has been deleted!"),QMessageBox::Ok);     // true message is successful
    }
    else
    {
        QMessageBox::information(this,QObject::tr("System Message"),tr("Login account deletion has failed!"),QMessageBox::Ok);  // false message if failed
    }

    ui->tableWidget->clearContents();           // clears table widget
    ui->tableWidget->setRowCount(0);            // set row count to 0

    QSqlQuery query;
    query.prepare("SELECT * FROM LoginInfo");   // selects all from loginInfo table
    query.exec();                               // executes the prepare

    ui->tableWidget->setColumnCount(5);                                                                                     // sets column count to 5
    ui->tableWidget->setRowCount(query.size());                                                                             // set row count
    ui->tableWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);                                          // make table expandable
    ui->tableWidget->setHorizontalHeaderLabels(QString("Account ID;Email Address;Username;Password;Salt").split(";"));      // label headers

    int i=0;
    while(query.next()) {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(query.value(0).toString()));  // Account ID
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(query.value(1).toString()));  // Email Address
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(query.value(2).toString()));  // Username
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(query.value(3).toString()));  // Password
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(query.value(4).toString()));  // Salt
        i++;
    }

    ui->lineEdit_ID->clear();   // Clears the table
}

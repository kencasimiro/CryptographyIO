#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Closes current window
// Directs to login window
void MainWindow::on_pushButton_LOGOUT_clicked()
{
    loginWindow* logWin = new loginWindow(this);
    this->close();
    logWin->show();
}

// Closes current window
// Directs to add login window
void MainWindow::on_pushButton_ADD_clicked()
{
    addLogin* addWin = new addLogin(this);
    this->close();
    addWin->show();
}

// Closes current window
// Directs to delete login window
void MainWindow::on_pushButton_DELETE_clicked()
{
    deleteLogin* deleteWin = new deleteLogin(this);
    this->close();
    deleteWin->show();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("学生管理系统V1.0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(UserAccount.IsAdministrator(ui->lineEdit->text(),ui->lineEdit_2->text()))
    {
        this->w.show();
        this->hide();
    }
    else
    {
        QMessageBox::warning(this,tr("错误"),tr("当前密码或账号错误"),
                                           QMessageBox::Yes);
    }
}

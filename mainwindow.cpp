#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Opera_studens1.Init_SQlite();//初始化数据库
    setWindowTitle("学生管理系统V1.0");

}

MainWindow::~MainWindow()
{
    delete ui;
}

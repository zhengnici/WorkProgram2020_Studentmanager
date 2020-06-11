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




void MainWindow::on_pushButton_6_clicked(bool checked)
{
    if(checked)
        ;

    string stud_inform_id=ui->lineEdit->text().toStdString();
    string stud_inform_name=ui->lineEdit_2->text().toStdString();
    string stud_inform_loca=ui->comboBox->currentText().toStdString();
    stud_inform_loca+=ui->comboBox_2->currentText().toStdString()+"省";
    stud_inform_loca+=ui->comboBox_3->currentText().toStdString()+"市";
    stud_inform_loca+=ui->lineEdit_7->text().toStdString();  //获取完整的地址信息

    Opera_studens1.InserAsID(stud_inform_id,stud_inform_name,stud_inform_loca);//插入读取的信息

    student stu_test=Opera_studens1.SearchAsID(stud_inform_id);
    qDebug()<<(QString::fromStdString(stu_test.StudentID));
    qDebug()<<(QString::fromStdString(stu_test.Name));
    qDebug()<<(QString::fromStdString(stu_test.NativePlace[0]));
    qDebug()<<(QString::fromStdString(stu_test.NativePlace[1]));
    qDebug()<<(QString::fromStdString(stu_test.NativePlace[2]));
    qDebug()<<(QString::fromStdString(stu_test.NativePlace[3]));

}

void MainWindow::on_pushButton_3_clicked(bool checked)
{
    if(checked)
        ;
    w1.show();
    this->hide();
}

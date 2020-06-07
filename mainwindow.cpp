#include "mainwindow.h"
#include "ui_mainwindow.h"


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



void MainWindow::on_pushButton_7_clicked()
{
    string stud_inform_id=ui->lineEdit->text().toStdString();
    string stud_inform_name=ui->lineEdit_2->text().toStdString();
    string stud_inform_loca=ui->comboBox->currentText().toStdString();
    stud_inform_loca+=ui->comboBox_2->currentText().toStdString()+"省";
    stud_inform_loca+=ui->comboBox_3->currentText().toStdString()+"市";
    stud_inform_loca+=ui->lineEdit_7->text().toStdString();  //获取完整的地址信息

    Opera_studens1.InserAsID(stud_inform_id,stud_inform_name,stud_inform_loca);
    student stu_test=Opera_studens1.SearchAsID(stud_inform_id);
   ui->label_8->setText(QString::fromStdString(stu_test.StudentID));
   ui->label_9->setText(QString::fromStdString(stu_test.Name));
   ui->label_10->setText(QString::fromStdString(stu_test.NativePlace[0]));

}

void MainWindow::on_pushButton_7_clicked(bool checked)
{
    if(checked==1)
    {

    }
}

#include "addstudentwindw.h"
#include "ui_addstudentwindw.h"
#include <qdebug.h>

void AddStudentWindw::setuser_login(QString name_in, int power_in)
{
    w2.loginuser.name=name_in.toStdString();
    w2.loginuser.power=power_in;
}

AddStudentWindw::AddStudentWindw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudentWindw)
{
    ui->setupUi(this);
    Opera_studens1.Init_SQlite();//初始化数据库
    QObject::connect(&w1,SIGNAL(InqureToAdd()),this,SLOT(toAddWindowSlot()));//连接w1的切换信号，数据添加窗口的显示
    QObject::connect(&w1,SIGNAL(InqureToUser()),this,SLOT(toUerInformWindowSlot()));//用户信息窗口显示
    QObject::connect(&w2,SIGNAL(UserToInqure()),this,SLOT(toInqureWindowSlot()));//显示数据查询界面
    QObject::connect(&w2,SIGNAL(UserToAdd()),this,SLOT(toAddWindowSlot()));//显示数据添加界面
    QObject::connect(&w3,SIGNAL(ObjPath(QString)),this,SLOT(Import(QString)));
    setWindowTitle("学生管理系统V1.0");
}

AddStudentWindw::~AddStudentWindw()
{
    delete ui;
}

void AddStudentWindw::on_pushButton_6_clicked()
{

    string stud_inform_id=ui->lineEdit->text().toStdString();
    string stud_inform_name=ui->lineEdit_2->text().toStdString();
    string stud_inform_loca=ui->comboBox->currentText().toStdString();
    stud_inform_loca+=ui->comboBox_2->currentText().toStdString()+"省";
    stud_inform_loca+=ui->comboBox_3->currentText().toStdString()+"市";
    stud_inform_loca+=ui->lineEdit_7->text().toStdString();  //获取完整的地址信息

    Opera_studens1.InserAsID(stud_inform_id,stud_inform_name,stud_inform_loca);//插入读取的信息


    student stu_test=Opera_studens1.SearchAsID(stud_inform_id);
    Opera_studens1.InserAsID_SQlite(stu_test);//插入到数据库

    qDebug()<<(QString::fromStdString(stu_test.StudentID));
    qDebug()<<(QString::fromStdString(stu_test.Name));
    qDebug()<<(QString::fromStdString(stu_test.NativePlace[0]));
    qDebug()<<(QString::fromStdString(stu_test.NativePlace[1]));
    qDebug()<<(QString::fromStdString(stu_test.NativePlace[2]));
    qDebug()<<(QString::fromStdString(stu_test.NativePlace[3]));
}

//显示数据查询界面的函数
void AddStudentWindw::on_pushButton_3_clicked()
{
   toInqureWindowSlot();
}

void AddStudentWindw::on_pushButton_2_clicked()
{
    toUerInformWindowSlot();
}
void AddStudentWindw::toAddWindowSlot()
{
    this->show();
    w1.hide();
    w2.hide();
}

void AddStudentWindw::toUerInformWindowSlot()
{
   w2.show();
   this->hide();
   w1.hide();
}

void AddStudentWindw::toInqureWindowSlot()
{
    w1.show();
    this->hide();
    w2.hide();
}

void AddStudentWindw::Import(QString path_in)
{
    qDebug()<<path_in;
}




void AddStudentWindw::on_pushButton_5_clicked()
{
    w3.show();
}

void AddStudentWindw::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->comboBox_2->clear();
    ui->comboBox_2->addItems(maploca.province.value(arg1));
}

void AddStudentWindw::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    ui->comboBox_3->clear();
    ui->comboBox_3->addItems(maploca.city.value(arg1));
}

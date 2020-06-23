#include "addstudentwindw.h"
#include "ui_addstudentwindw.h"
#include <qdebug.h>

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
    QObject::connect(&w3,SIGNAL(ObjPath(QString)),this,SLOT(Import(QString)));//从另外窗口获得CSV文件的地址
    setWindowTitle("学生管理系统V1.0");
}


AddStudentWindw::~AddStudentWindw()
{
    delete ui;
}

//储存用户信息
void AddStudentWindw::setuser_login(QString name_in, int power_in)
{
    w2.loginuser.name=name_in.toStdString();
    w2.loginuser.power=power_in;
}

//数据批量导入
void AddStudentWindw::ImportFormCSV(QString path_in)
{
    if(path_in.indexOf(".csv")<0)
    {
        QMessageBox::information(NULL, "错误", "未选择正确文件只支持CSV格式文件");
        return ;
    }

    QFile csvFile(path_in);
    if(csvFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&csvFile);
        while (!stream.atEnd())
        {
            QString readtext = stream.readLine();
            Opera_studens1.ImportFromCSV_SQlite(readtext);//插入到数据库
        }
    }
    else
    {
         QMessageBox::information(NULL, "错误", "未能打开该文件");
    }
}


//数据导入函数
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

}

//显示数据查询界面槽函数
void AddStudentWindw::on_pushButton_3_clicked()
{
   toInqureWindowSlot();
}

//显示用户信息槽函数
void AddStudentWindw::on_pushButton_2_clicked()
{
    toUerInformWindowSlot();
}

//显示数据导入界面
void AddStudentWindw::toAddWindowSlot()
{
    this->show();
    w1.hide();
    w2.hide();
}

//显示用户信息界面
void AddStudentWindw::toUerInformWindowSlot()
{
   w2.show();
   this->hide();
   w1.hide();
}

//显示数据查询界面
void AddStudentWindw::toInqureWindowSlot()
{
    w1.show();
    this->hide();
    w2.hide();
}

//批量导入处理槽函数
void AddStudentWindw::Import(QString path_in)
{
    ImportFormCSV(path_in);
}

//打开文件选择界面
void AddStudentWindw::on_pushButton_5_clicked()
{
    w3.show();
}

void AddStudentWindw::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->comboBox_2->clear();
    ui->comboBox_2->addItems(maploca.province.value(arg1));//通过字典实现联动
}

void AddStudentWindw::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    ui->comboBox_3->clear();
    ui->comboBox_3->addItems(maploca.city.value(arg1));//通过字典实现联动
}

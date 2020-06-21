#include "uerinformwindow.h"
#include "ui_uerinformwindow.h"

UerInformWindow::UerInformWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UerInformWindow)
{
    ui->setupUi(this);

}

UerInformWindow::~UerInformWindow()
{
    delete ui;
}

void UerInformWindow::DispUerInfor()
{
    ui->label_3->setText(QString::fromStdString(loginuser.name));
    switch (loginuser.power)
    {
       case -1:ui->label_4->setText("未定义");
       case 0:ui->label_4->setText("管理员");

    }
}

void UerInformWindow::on_pushButton_4_clicked()
{
    emit UserToAdd();//显示数据导入界面
}

void UerInformWindow::on_pushButton_3_clicked()
{
    emit UserToInqure();//显示数据查询界面
}

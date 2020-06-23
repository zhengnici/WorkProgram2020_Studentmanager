#ifndef ADDSTUDENTWINDW_H
#define ADDSTUDENTWINDW_H

#include "studentqt.h"
#include "inqurewindow.h"
#include "uerinformwindow.h"
#include "filebrowser.h"
#include "maplocation.h"
#include <QMainWindow>
#include <string>
#include <QStringListModel>
#include <QDialog>
#include <QMessageBox>
#include <QFile>


namespace Ui {
class AddStudentWindw;
}

class AddStudentWindw : public QDialog
{
    Q_OBJECT
public:     //user class and function
    void setuser_login(QString name_in,int power_in);
private:
    void ImportFormCSV(QString path_in);
public:
    explicit AddStudentWindw(QWidget *parent = nullptr);
    ~AddStudentWindw();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void toAddWindowSlot();//显示数据添加窗口的槽函数
    void toUerInformWindowSlot();//显示用户信息窗口槽函数
    void toInqureWindowSlot();//显示数据查询窗口槽函数
    void Import(QString);

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::AddStudentWindw *ui;
    inqureWindow w1;//数据查询窗口
    UerInformWindow w2;//个人信息显示窗口
    FileBrowser w3;//文件浏览窗口
    studentQT Opera_studens1;//学生成员变量0
    MapLocation maploca;//国家-省，省-市字典
};




#endif // ADDSTUDENTWINDW_H

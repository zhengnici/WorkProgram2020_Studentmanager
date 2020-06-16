#ifndef ADDSTUDENTWINDW_H
#define ADDSTUDENTWINDW_H

#include "studentqt.h"
#include "inqurewindow.h"
#include <QMainWindow>
#include <string>
#include <QStringListModel>
#include <QDialog>

namespace Ui {
class AddStudentWindw;
}

class AddStudentWindw : public QDialog
{
    Q_OBJECT
public:     //user class and function


public:
    explicit AddStudentWindw(QWidget *parent = nullptr);
    ~AddStudentWindw();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void toAddWindowSlot();//显示数据添加窗口的槽函数

private:
    Ui::AddStudentWindw *ui;
    inqureWindow w1;//自定的数据查询窗口
    studentQT Opera_studens1;//学生成员变量
};




#endif // ADDSTUDENTWINDW_H

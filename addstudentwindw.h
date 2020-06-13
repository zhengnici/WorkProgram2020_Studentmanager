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
    studentQT Opera_studens1;//学生成员变量

public:
    explicit AddStudentWindw(QWidget *parent = nullptr);
    ~AddStudentWindw();

private slots:
    void on_pushButton_6_clicked(bool checked);

    void on_pushButton_3_clicked(bool checked);

private:
    Ui::AddStudentWindw *ui;
    inqureWindow w1;//自定窗口
};




#endif // ADDSTUDENTWINDW_H

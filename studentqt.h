#ifndef STUDENTQT_H
#define STUDENTQT_H
#include "student.h"
#include <QDebug>
#include <qdebug.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>
#include <QMessageBox>
using namespace std;

class studentQT: public list_student
{
public:

public:
    studentQT();
    bool Init_SQlite(void);//学生待存取的数据库的初始化，使用sqlite数据库
    bool InserAsID_SQlite(student stude);//按照学号插入学生
    int SerchAsID_SQlite(QString id);//按照ID找到该学生，可能有多人，返回在类的成员里面,返回值数量
    int SerchAsProvi_SQlite(QString Prov);//按照省份查找学生可能有多人，返回在类的成员里面,返回值数量
};

#endif // STUDENTQT_H

#ifndef SQLITEOPERAT_H
#define SQLITEOPERAT_H
#include <QDebug>
#include <qdebug.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>
#include <QMessageBox>
#include <string>
using namespace  std;
//SQlite操作函数
//对数据库的总体操作，应用操作在“studentqt”类里面

void mysqlittest(void)
{
    //建立并打开数据库
       QSqlDatabase database;
       database = QSqlDatabase::addDatabase("QSQLITE");
       database.setDatabaseName("MyDataBase.db");
       if (!database.open())
       {
           qDebug() << "Error: Failed to connect database." << database.lastError();
       }
       else
       {
           qDebug() << "Succeed to connect database." ;
       }

       //创建表格
       QSqlQuery sql_query;
       if(!sql_query.exec("create table student(id int primary key, name text, age int)"))
       {
           qDebug() << "Error: Fail to create table."<< sql_query.lastError();
       }
       else
       {
           qDebug() << "Table created!";
       }

       //插入数据
       if(!sql_query.exec("INSERT INTO student VALUES(1, \"Wang\", 23)"))
       {
           qDebug() << sql_query.lastError();
       }
       else
       {
           qDebug() << "inserted Wang!";
       }
       if(!sql_query.exec("INSERT INTO student VALUES(2, \"Li\", 23)"))
       {
           qDebug() << sql_query.lastError();
       }
       else
       {
           qDebug() << "inserted Li!";
       }

       //修改数据
       sql_query.exec("update student set name = \"QT\" where id = 1");
       if(!sql_query.exec())
       {
           qDebug() << sql_query.lastError();
       }
       else
       {
           qDebug() << "updated!";
       }

       //查询数据
       sql_query.exec("select * from student");
       if(!sql_query.exec())
       {
           qDebug()<<sql_query.lastError();
       }
       else
       {
           while(sql_query.next())
           {
               int id = sql_query.value(0).toInt();
               QString name = sql_query.value(1).toString();
               int age = sql_query.value(2).toInt();
               qDebug()<<QString("id:%1    name:%2    age:%3").arg(id).arg(name).arg(age);
           }
       }

       //删除数据
       sql_query.exec("delete from student where id = 1");
       if(!sql_query.exec())
       {
           qDebug()<<sql_query.lastError();
       }
       else
       {
           qDebug()<<"deleted!";
       }

       //删除表格
       sql_query.exec("drop table student");
       if(sql_query.exec())
       {
           qDebug() << sql_query.lastError();
       }
       else
       {
           qDebug() << "table cleared";
       }

       //关闭数据库
       database.close();
}

//创建SQlite数据库
//参数:路径
//返回值：创建成功与否
bool MakeDataBase(QString base_naem)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QApplication::applicationDirPath()+"/"+base_naem+".db");    //如果本目录下没有该文件,则会在本目录下生成,否则连接该文件
     if (!db.open()) {
            QMessageBox::warning(0, QObject::tr("Database Error"),
                                 db.lastError().text());
            return false;
     }
     return true;
}

bool DeleteTable(QString base_name)
{
    QSqlQuery query;
    query.exec("DROP TABLE "+base_name);    //删除名为students的表
    return(true);
}

#endif // SQLITEOPERAT_H

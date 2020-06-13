#include "studentqt.h"
#include "sqliteOperat.h"


studentQT::studentQT()
{

}

bool studentQT::Init_SQlite(void)
{

    //MakeDataBase("StudentDataBase");
    QSqlDatabase db;
    QSqlQuery sql_query;
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QApplication::applicationDirPath()+"/StudentDataBase.db");    //如果本目录下没有该文件,则会在本目录下生成,否则连接该文件
    sql_query=QSqlQuery(db);//连接数据库

     if (!db.open()) {
            QMessageBox::warning(0, QObject::tr("Database Error"),
                                 db.lastError().text());
            qDebug()<<"zlb database not open";
            return false;
     }

    sql_query.exec("CREATE TABLE students ("  //创建名为"students"表
                       "id INTEGER PRIMARY KEY AUTOINCREMENT, "//学号
                       "nation VARCHAR(40) NOT NULL, "//国家
                       "province VARCHAR(40) NOT NULL, "//省份
                       "city VARCHAR(40) NOT NULL, "//市
                       "loaction VARCHAR(40) NOT NULL, "//具体地址
                       "name VARCHAR(40) NOT NULL)");//姓名
    return(true);
}

bool studentQT::InserAsID_SQlite(student stude)
{
    QSqlQuery sql_query;

    sql_query.prepare("INSERT INTO students (id, nation,province,city,loaction,name) "
                  "VALUES (:id, :nation,:province,:city,:loaction,:name)");//为每一列添加绑定值

    QString obj;
    obj=QString::fromStdString(stude.StudentID);
    sql_query.bindValue(":id", obj);      //向绑定值里加入学号
    obj=QString::fromStdString(stude.NativePlace[0]);
    sql_query.bindValue(":nation", obj);      //国家
    obj=QString::fromStdString(stude.NativePlace[1]);
    sql_query.bindValue(":province", obj );   //省份
    obj=QString::fromStdString(stude.NativePlace[2]);
    sql_query.bindValue(":city", obj );       //城市
    obj=QString::fromStdString(stude.NativePlace[3]);
    sql_query.bindValue(":loaction",obj );    //具体地址
    obj=QString::fromStdString(stude.Name);
    sql_query.bindValue(":name",obj );        //姓名
    sql_query.exec();          //加入库中


  return(true);
}


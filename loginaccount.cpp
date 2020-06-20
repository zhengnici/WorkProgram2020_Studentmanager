#include "loginaccount.h"



LoginAccount::LoginAccount()
{
     InitAccountDataBase();
}

bool LoginAccount::InitAccountDataBase()
{
    db=new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE","initacontect"));
    db->setDatabaseName(QApplication::applicationDirPath()+"/AccoutDataBase.db");    //如果本目录下没有该文件,则会在本目录下生成,否则连接该文件
    if (!db->open())
    {
        QMessageBox::warning(0, QObject::tr("AccteDatabase Error"),
                             db->lastError().text());
        qDebug()<<"accoutn database not open";
        return false;
    }
    else
    {
        QSqlQuery sql_query(*db);//连接数据库
        sql_query.exec("CREATE TABLE admin ("  //创建名为"admin"表
                       "name VARCHAR(40) NOT NULL,"//用户名
                       "pass VARCHAR(40) NOT NULL)");//密码
        sql_query.exec("SELECT * FROM admin  WHERE name = 'admin';");
        sql_query.next();
        QString haveuser=sql_query.value("pass").toString();
        if(haveuser.isEmpty())
        {
                sql_query.exec("INSERT INTO admin (name, pass) "
                               "VALUES ('admin','admin')");
        }

        return(true);
    }
}

bool LoginAccount::IsAdministrator(QString name, QString pass)
{
   if(db->open())
   {
       QSqlQuery sql_query(*db);//连接数据库
       sql_query.exec("SELECT * FROM admin  WHERE name = '"+name+"';");
       sql_query.next();//执行
       QString objpass = sql_query.value("pass").toString();//读取该用户的密码
       qDebug()<<objpass;
       if(objpass==pass&&(!pass.isEmpty()))//比较
           return(true);
       else
           return(false);
   }
   else
   {
       QMessageBox::warning(0, QObject::tr("AccteDatabase Open Error"),
                            db->lastError().text());
       return(false);
   }
}

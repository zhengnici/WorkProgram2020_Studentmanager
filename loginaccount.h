#ifndef LOGINACCOUNT_H
#define LOGINACCOUNT_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>

class LoginAccount
{
private:
    QSqlDatabase *db;
    bool InitAccountDataBase();
public:
    LoginAccount();
    bool IsAdministrator(QString name,QString pass);
};

#endif // LOGINACCOUNT_H

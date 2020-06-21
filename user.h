#ifndef USER_H
#define USER_H
#include <QString>
#include <string>
using namespace std;
//登录用户类
class user
{
public:
    string name;
    int    power;//用户权限0表示最高
public:
    user();
};

#endif // USER_H

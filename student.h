#ifndef STUDEN_H
#define STUDEN_H
#include <iostream>
#include <string>
#include <list>
#define DEBUG_Stdu
#define CNW 3  //中文字长，GB：2，UTF8：3
using namespace std;

class student
{
public:
    string StudentID;    //学号
    string Name;        //姓名
    string NativePlace[4]; //籍贯 0:国家 1:省份 2:市区 3:具体地址
public:
    student(void);
    int SetAll(string id, string name, string locat);//设置整个学生类locat:形式xx国xx省xx市xxxx
#ifdef DEBUG_Stdu
    void Dis(void);//显示本结点控制台测试用
#endif
};


class list_student
{
public:
    list<student> head; //相当于头节点
public:
    list_student(void)
    {
        student *ph = new student();
        head.push_back(*ph);//添加头节点

    }
public:
    student SearchAsStudent(student obj);
    student SearchAsID(string obj);
    student SearchAsName(string obj);
#ifdef DEBUG_Stdu
    void DisAll(void);//显示所有结点
#endif
    int InserAsID(string id,string name,string loca);//按照学号从小到大，省份字典从小到大(undo)，姓名大小写(undo)
};


#endif // STUDEN_H

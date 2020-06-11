#include "student.h"

student::student(void)
{
    this->StudentID = "学号";
    this->Name = "姓名";

    this->NativePlace[0] = "国家";
    this->NativePlace[1] = "省份";
    this->NativePlace[2] = "市";
    this->NativePlace[3] = "具体地址";
}

int student::SetAll(string id, string name, string locat)
{
    string palce[3];
    this->StudentID = id;
    this->Name = name;
    int i1 = locat.find_first_of("国")+2, i2 = locat.find("省")+2, i3 = locat.find("市")+2;
    palce[0] = locat.substr(0, 2);
    this->NativePlace[0] = locat.substr(0, i1);//汉字两个字节
    this->NativePlace[1] = locat.substr(i1, i2-i1);
    this->NativePlace[2] = locat.substr(i2, i3-i2);
    this->NativePlace[3] = locat.substr(i3, locat.size()-i3);
    return(1);
}

#ifdef DEBUG_Stdu
void student::Dis(void)
{
    cout << this->StudentID << " ";
    cout << this->Name << " ";
    for (int i = 0; i < 4; i++)
    {
        cout << this->NativePlace[i] << " ";
    }
    cout << endl;
}
#endif

student list_student::SearchAsStudent(student obj)
{
    static list<student>::iterator it = head.begin();//由此可以查询多个对象

    for (; (it != head.end()); it++)
    {
        if((it->Name == obj.Name) && (it->Name == obj.Name))
            return(*it);
    }

    return(*head.begin());
}

student list_student::SearchAsID(string obj)
{
    list<student>::iterator it = head.begin();//如果声明为静态可以查询多个对象

    for (; (it!=head.end()); it++)
    {
        if((it->StudentID == obj))
            return(*it);
    }
    return(*head.begin());
}

student list_student::SearchAsName(string obj)
{
    list<student>::iterator it = head.begin();
    for (; (it != head.end()); it++)
    {
        if ((it->Name== obj))
            return(*it);
    }
    return(*head.begin());
}


#ifdef DEBUG_Stdu
void list_student::DisAll(void)
{
    list<student>::iterator it = head.begin();

    for (; (it != head.end()); it++)
    {
        it->Dis();
    }
}
#endif

int list_student::InserAsID(string id, string name, string loca)
{
    list<student>::iterator it = head.begin();
    it++;//跳过头结点
    for (; (it != head.end()); it++)
    {
        if ((it->StudentID >= id))
        {
            break;
        }

    }
    student stduin;
    stduin.SetAll(id, name, loca);
    this->head.insert(it, stduin);
    return(1);
}

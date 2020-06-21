#include "maplocation.h"

MapLocation::MapLocation()
{
    InitProvince();
    InitCity();
}

void MapLocation::InitProvince()
{
    province["中国"]={"四川","湖北","重庆"};
    province["苏联"]={"西伯利亚","卢比扬卡"};
    //QList<QString> China;
    //China.push_back("四川");
    //China.push_back("湖北");
    //China.push_back("重庆");
    //province.insert("中国",China);
}

void MapLocation::InitCity()
{
    city["四川"]={"成都","绵阳","雅安"};
    city["湖北"]={"武汉","武昌"};
    city["重庆"]={"重庆"};
    //QList<QString> SiChuan;
    //SiChuan.push_back("成都");
    //SiChuan.push_back("绵阳");
    //SiChuan.push_back("雅安");
    //city.insert("四川",SiChuan);
}


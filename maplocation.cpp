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
}

void MapLocation::InitCity()
{
    city["四川"]={"成都","绵阳","雅安"};
    city["湖北"]={"武汉","武昌"};
    city["重庆"]={"重庆"};
}


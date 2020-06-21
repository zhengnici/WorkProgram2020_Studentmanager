#ifndef MAPLOCATION_H
#define MAPLOCATION_H
#include <QMap>
#include <QStringList>
#include <QList>
using namespace std;
//地区字典
class MapLocation
{
public:
    QMap<QString,QList<QString>> province;//国家到省
    QMap<QString,QList<QString>> city;//省到市
public:
    MapLocation();
private:
    void InitProvince();
    void InitCity();
};

#endif // MAPLOCATION_H

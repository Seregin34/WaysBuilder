#include "getwaytest.h"

getWayTest::getWayTest(QObject *parent) : QObject(parent)
{

}

getWayTest::~getWayTest()
{

}

void getWayTest::oneWay()
{
    QList<WaysMap::Coordinate> res;
    QList< QPair <WaysMap::Coordinate, WaysMap::Coordinate> > obstaclesList;
    QPair <WaysMap::Coordinate, WaysMap::Coordinate> cord;
    cord.first = WaysMap::Coordinate(3,5);
    cord.second = WaysMap::Coordinate(3,6);
    obstaclesList.append(cord);
    WaysMap w(WaysMap::Coordinate(4,5),WaysMap::Coordinate(2,5), obstaclesList);
    res.append(WaysMap::Coordinate(4,5));
    res.append(WaysMap::Coordinate(4,4));
    res.append(WaysMap::Coordinate(3,4));
    res.append(WaysMap::Coordinate(2,4));
    res.append(WaysMap::Coordinate(2,5));
    QVERIFY2 (res == w.getWay(), "ERROR");
}

void getWayTest::someWay()
{
    QList<WaysMap::Coordinate> res;
    QList< QPair <WaysMap::Coordinate, WaysMap::Coordinate> > obstaclesList;
    WaysMap w(WaysMap::Coordinate(1,3),WaysMap::Coordinate(3,4), obstaclesList);
    res.append(WaysMap::Coordinate(1,3));
    res.append(WaysMap::Coordinate(2,3));
    res.append(WaysMap::Coordinate(3,3));
    res.append(WaysMap::Coordinate(3,4));
    QVERIFY2 (res == w.getWay(), "ERROR");
}



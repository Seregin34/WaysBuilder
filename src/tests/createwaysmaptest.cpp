#include "createwaysmaptest.h"

createWaysMapTest::createWaysMapTest(QObject *parent) : QObject(parent)
{

}

createWaysMapTest::~createWaysMapTest()
{

}

void createWaysMapTest::empty()
{
    QList< QPair <WaysMap::Coordinate, WaysMap::Coordinate> > obstaclesList;
    WaysMap w(WaysMap::Coordinate(1,2),WaysMap::Coordinate(2,1), obstaclesList);
    QVERIFY2 (w.map.contains(w.end) && w.map.value(w.end).din == 3, "ERROR");
}

void createWaysMapTest::dontEmpty()
{
    QList< QPair <WaysMap::Coordinate, WaysMap::Coordinate> > obstaclesList;
    QPair <WaysMap::Coordinate, WaysMap::Coordinate> cord;
    cord.first = WaysMap::Coordinate(3,5);
    cord.second = WaysMap::Coordinate(3,6);
    obstaclesList.append(cord);
    WaysMap w(WaysMap::Coordinate(4,5),WaysMap::Coordinate(2,5), obstaclesList);
    QVERIFY2 (w.map.contains(w.end) && w.map.value(w.end).din == 5, "ERROR");
}


#include "isobstaclestest.h"

/*!
 * \brief findBorderCoordinate - Найти координаты границ поля
 * \param obstacles - Список препятствий
 */
//void findBorderCoordinate(QList<QPair<Coordinate, Coordinate> > &obstacles);

isObstaclesTest::isObstaclesTest(QObject *parent) : QObject(parent)
{

}

isObstaclesTest::~isObstaclesTest()
{

}

void isObstaclesTest::test_data()
{
    ObstaclesList *data = new ObstaclesList;
    QPair<WaysMap::Coordinate, WaysMap::Coordinate> cord;
    cord.first = WaysMap::Coordinate(0,0);
    cord.second = WaysMap::Coordinate(0,0);
    data->append(cord);
    QTest::addColumn<void*> ("list");
    QTest::addColumn<int> ("maxX");
    QTest::addColumn<int> ("maxY");
    QTest::addColumn<int> ("minX");
    QTest::addColumn<int> ("minY");
    QTest::newRow("empty list start == end") <<  (void*)data << 1 << 1 << -1 << -1;
    data = new ObstaclesList;

    cord.first = WaysMap::Coordinate(0,0);
    cord.second = WaysMap::Coordinate(1,1);
    data->append(cord);
    QTest::newRow("empty list start != end") <<  (void*)data << 2 << 2 << -1 << -1;
    data = new ObstaclesList;

    cord.first = WaysMap::Coordinate(0,0);
    cord.second = WaysMap::Coordinate(2,0);
    data->append(cord);
    cord.first = WaysMap::Coordinate(1,-1);
    cord.second = WaysMap::Coordinate(1,1);
    data->append(cord);
    QTest::newRow("one obstacle") <<  (void*)data << 3 << 2 << -2 << -1;
    data = new ObstaclesList;

    cord.first = WaysMap::Coordinate(0,0);
    cord.second = WaysMap::Coordinate(4,0);
    data->append(cord);
    cord.first = WaysMap::Coordinate(1,-1);
    cord.second = WaysMap::Coordinate(1,1);
    data->append(cord);
    cord.first = WaysMap::Coordinate(1,-1);
    cord.second = WaysMap::Coordinate(3,1);
    data->append(cord);
    QTest::newRow("some obstacles") <<  (void*)data << 5 << 2 << -2 << -1;

}

void isObstaclesTest::test()
{
    ObstaclesList *d;
    QFETCH(void*, list);
    QFETCH(int, maxX);
    QFETCH(int, maxY);
    QFETCH(int, minX);
    QFETCH(int, minY);
    d = (ObstaclesList*)list;
    WaysMap m;
    m.findBorderCoordinate(*d);
    delete d;
    QVERIFY2 (maxX == m.maxX, "invalid maxX");
    QVERIFY2 (maxY == m.maxY, "invalid maxY");
    QVERIFY2 (minX == m.minX, "invalid minX");
    QVERIFY2 (minY == m.minY, "invalid minY");
}


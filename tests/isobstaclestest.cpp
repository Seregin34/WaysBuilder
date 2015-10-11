#include "isobstaclestest.h"

isObstaclesTest::isObstaclesTest(QObject *parent) : QObject(parent)
{

}

isObstaclesTest::~isObstaclesTest()
{

}

void isObstaclesTest::initTestCase()
{
    QPair<WaysMap::Coordinate, WaysMap::Coordinate> cord;
    cord.first =  WaysMap::Coordinate(1,1);
    cord.second = WaysMap::Coordinate(4,4);
    w.obstacles.append(cord);
    cord.first =  WaysMap::Coordinate(-2,1);
    cord.second = WaysMap::Coordinate(-1,2);
    w.obstacles.append(cord);
    cord.first =  WaysMap::Coordinate(-4,-4);
    cord.second = WaysMap::Coordinate(-1,-1);
    w.obstacles.append(cord);
    cord.first =  WaysMap::Coordinate(1,-2);
    cord.second = WaysMap::Coordinate(2,-1);
    w.obstacles.append(cord);
}

void isObstaclesTest::test_data()
{
    QTest::addColumn<int> ("x");
    QTest::addColumn<int> ("y");
    QTest::addColumn<bool> ("res");
    QTest::newRow("in Obstacle") << 3 << 2 << true;
    QTest::newRow("isn't Obstacle") << 0 << 0 << false;
    QTest::newRow("on border Obstacle") << -1 << -2 << true;
    QTest::newRow("on border Obstacle") << 1 << -2 << true;
}

void isObstaclesTest::test()
{
    QFETCH(int, x);
    QFETCH(int, y);
    QFETCH(bool, res);
    QVERIFY2(w.isObstacles(x, y) == res, "invalin ans");
}

#ifndef ISOBSTACLESTEST_H
#define ISOBSTACLESTEST_H

#include <QObject>
#include <QTest>
#include <waysmap.h>

class isObstaclesTest : public QObject
{
    Q_OBJECT
public:
    explicit isObstaclesTest(QObject *parent = 0);
    ~isObstaclesTest();
    typedef QList<QPair<WaysMap::Coordinate, WaysMap::Coordinate> > ObstaclesList;
signals:

private Q_SLOTS:
    void test_data();
    void test();
};

#endif // ISOBSTACLESTEST_H

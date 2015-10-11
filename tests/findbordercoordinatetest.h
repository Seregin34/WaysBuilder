#include <QObject>
#include <QTest>
#include <waysmap.h>

class findBorderCoordinateTest : public QObject
{
    Q_OBJECT
public:
    explicit findBorderCoordinateTest(QObject *parent = 0);
    ~findBorderCoordinateTest();
    typedef QList<QPair<WaysMap::Coordinate, WaysMap::Coordinate> > ObstaclesList;
signals:

private Q_SLOTS:
    void test_data();
    void test();
};


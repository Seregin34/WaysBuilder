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

signals:

private Q_SLOTS:
    void initTestCase();
    void test_data();
    void test();
private:
    WaysMap w;
};

#endif // ISOBSTACLESTEST_H

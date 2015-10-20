#ifndef GETWAYTEST_H
#define GETWAYTEST_H

#include <QObject>
#include <QTest>
#include <waysmap.h>

class getWayTest : public QObject
{
    Q_OBJECT
public:
    explicit getWayTest(QObject *parent = 0);
    ~getWayTest();

signals:

private Q_SLOTS:
    void oneWay();
    void someWay();
};

#endif // GETWAYTEST_H

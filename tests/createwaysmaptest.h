#ifndef CREATEWAYSMAPTEST_H
#define CREATEWAYSMAPTEST_H

#include <QObject>
#include <QTest>
#include <waysmap.h>

class createWaysMapTest : public QObject
{
    Q_OBJECT
public:
    explicit createWaysMapTest(QObject *parent = 0);
    ~createWaysMapTest();

signals:

private Q_SLOTS:
    void empty();
    void dontEmpty();
};

#endif // CREATEWAYSMAPTEST_H

#include <QCoreApplication>
#include <QDebug>
#include <tests/findbordercoordinatetest.h>
#include <tests/isobstaclestest.h>
#include <tests/createwaysmaptest.h>
#include <tests/getwaytest.h>
#include <inout.h>

#include <QRegExp>
#include <QString>

void testing(){
    QTest::qExec(new getWayTest);
    QTest::qExec(new createWaysMapTest);
    QTest::qExec(new findBorderCoordinateTest);
    QTest::qExec(new isObstaclesTest);
}

int main(int argc, char *vargv[])
{
//    if (argc == 1){
//        testing();
//    }
//    else if (argc == 3){
    if (true){
        char argv[20][80] = {
            "adds",
            "incord.txt",
            "inobstr.txt"
        };

        WaysMap::Coordinate start, end;
        switch (readStartEnd(argv[1], start, end)) {
        case 1:
            qDebug() << "can't open file:" << argv[1];
            break;
        case 2:
            qDebug() << "invalid input format in file:" << argv[1];
            break;
        }
        QList<QPair<WaysMap::Coordinate, WaysMap::Coordinate> > list;
        switch (readCoordinates(argv[2], list)) {
        case 1:
            qDebug() << "can't open file:" << argv[2];
            break;
        case 2:
            qDebug() << "invalid input format in file:" << argv[2] << "on string" << list.length();
            break;
        case 3:
            qDebug() << "invalid input data in file:" << argv[2] << "on string" << list.length();
            break;
        }
        WaysMap w(start, end, list);
        QList<WaysMap::Coordinate> res = w.getWay();
        if (res.isEmpty()){
            outln("out.txt", QString("Can not build the way"));
            qDebug() << "Can not build the way";
            return 0;
        }
        out("out.txt", res);
    }
    else {
        qDebug() << "invalid arg count!";
        return 0;
    }
    return 0;
}

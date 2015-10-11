#include <QCoreApplication>
#include <QDebug>
#include <tests/isobstaclestest.h>
void testing(){
    QTest::qExec(new isObstaclesTest);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    testing();

    return a.exec();
}

#include "inout.h"
#include <QDebug>

int readStartEnd(QString file, WaysMap::Coordinate &start, WaysMap::Coordinate &end)
{
    QRegExp s("\\(-?\\d+;-?\\d+\\),\\(-?\\d+;-?\\d+\\)");
    QFile f(file);
    if (!f.open(QIODevice::ReadOnly)){
        return 1; // Не удалось открыть файл
    }
    QString data = f.readAll();
    f.close();
    if (data.contains('\n') || !s.exactMatch(data)){
        return 2; // Входные данные не соответствуют заданному формату
    }
    int b = data.indexOf(";");
    start.x = data.mid(1, b - 1).toInt();
    start.y = data.mid(b+1, data.indexOf(")", b) - b - 1).toInt();
    b = data.indexOf(")", b);
    end.x = data.mid(b+3, data.indexOf(";", b) - b - 3).toInt();
    b = data.indexOf(";", b);
    end.y = data.mid(b+1, data.indexOf(")", b) - b - 1).toInt();
    return 0;
}


int readCoordinates(QString file, QList<QPair<WaysMap::Coordinate, WaysMap::Coordinate> > &list)
{
    QRegExp s("\\(-?\\d+;-?\\d+\\),\\(-?\\d+;-?\\d+\\)");
    QFile f(file);
    if (!f.open(QIODevice::ReadOnly)){
        return 1; // Не удалось открыть файл
    }
    QString data = f.readAll();
    f.close();
    QStringList dataList;
    if (data.contains("\r\n")){
        dataList = data.split("\r\n");
    }
    else if (data.isEmpty()){
        return 0;
    }
    else {
        dataList = data.split("\n");
    }
    QPair<WaysMap::Coordinate, WaysMap::Coordinate> stringData;
    for (QStringList::iterator i = dataList.begin(); i !=dataList.end(); ++i){

        if (!s.exactMatch(*i)){
            return 2;
        }
        int b = i->indexOf(";");
        stringData.first.x = i->mid(1, b - 1).toInt();
        stringData.first.y = i->mid(b+1, i->indexOf(")", b) - b - 1).toInt();
        b = i->indexOf(")", b);
        stringData.second.x = i->mid(b+3, i->indexOf(";", b) - b - 3).toInt();
        b = data.indexOf(";", b);
        stringData.second.y = i->mid(b+1, i->indexOf(")", b) - b - 1).toInt();

        if (stringData.first.x > stringData.second.x || stringData.first.y > stringData.second.y){
            return 3;
        }
        list.append(stringData);
    }
    return 0;
}


bool out(QString file, QList<WaysMap::Coordinate> &cl)
{
    QFile f(file);
    if (!f.open(QIODevice::WriteOnly)){
        return false; // Не удалось открыть файл
    }
    QString data;
    for (QList<WaysMap::Coordinate>::iterator i = cl.begin(); i != cl.end(); ++i){
        data += "("+ QString::number(i->x) + ";" + QString::number(i->y) + ")\r\n";
    }
    f.write(data.toLocal8Bit());
    f.close();
    return true;

}

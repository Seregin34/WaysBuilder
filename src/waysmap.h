#ifndef WAYSMAP_H
#define WAYSMAP_H

#include <QMap>
#include <QList>
#pragma once

class WaysMap
{
public:
    /*!
     * \brief The Coordinate struct - Структура описывающая позицию координат
     */
    struct Coordinate{
        int x;
        int y;
        Coordinate(int X, int Y) { x = X; y = Y; }
        Coordinate() { x = 0; y = 0; }
        bool operator ==(const Coordinate &other) const {return (x == other.x && y == other.y);}
        bool operator !=(const Coordinate &other) const {return !(*this == other);}
        bool operator <(const Coordinate &other)  const {return ((x < other.x) || (x == other.x && y < other.y));}
    };
    /*!
     * \brief The Vertex struct - вершина графа
     */
    struct Vertex{
        QList <Coordinate> children;
        int din;
    };
    /*!
     * \brief WaysMap - Конструктор карты путей
     * \param start - Начальная точка
     * \param end - Конечная точка
     * \param obstaclesList - Список препятствий
     */
    WaysMap(Coordinate start, Coordinate end, QList<QPair<Coordinate, Coordinate> > &obstaclesList) ;
    /*!
     * \brief getWay - Получить кратчайший путь
     * \return - Путь.
     */
    QList<Coordinate> getWay();

    QMap<Coordinate, Vertex> map;
    int maxX;
    int maxY;
    int minX;
    int minY;
    Coordinate start;
    Coordinate end;

    QList <QPair< WaysMap::Coordinate, WaysMap::Coordinate> > obstacles;

    /*!
     * \brief findBorderCoordinate - Найти координаты границ поля
     * \param obstacles - Список препятствий
     */
    void findBorderCoordinate(QList<QPair<Coordinate, Coordinate> > &obstacles);
    void createWaysMap(int startIn = 1);
    bool onBorder(int x, int y);
    bool isObstacles(int x, int y);
    Coordinate getNextStep(Coordinate &c);
    WaysMap(){}
};

#endif // WAYSMAP_H

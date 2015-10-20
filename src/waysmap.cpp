#include "waysmap.h"

WaysMap::WaysMap(WaysMap::Coordinate start, WaysMap::Coordinate end, QList< QPair <WaysMap::Coordinate, WaysMap::Coordinate> > &obstaclesList)
{
    WaysMap::Vertex v;
    v.din = 1;
    this->start = start;
    this->end = end;
    QPair<WaysMap::Coordinate, WaysMap::Coordinate> last;
    last.first = start;
    last.second = end;
    this->obstacles = obstaclesList;
    this->obstacles.append(last);
    findBorderCoordinate(this->obstacles);
    this->obstacles.removeLast();
    this->map.insert(start, v);
    createWaysMap();
}

void WaysMap::findBorderCoordinate(QList<QPair<WaysMap::Coordinate, WaysMap::Coordinate> > &obstacles)
{
    maxX = obstacles.first().first.x;
    maxY = obstacles.first().first.y;
    minX = obstacles.first().first.x;
    minY = obstacles.first().first.y;

    for (QList<QPair<WaysMap::Coordinate, WaysMap::Coordinate> >::iterator i = obstacles.begin(); i != obstacles.end(); ++i){
        if (maxX < i->first.x)
            maxX = i->first.x;
        else if (minX > i->first.x)
            minX = i->first.x;

        if (maxX < i->second.x)
            maxX = i->second.x;
        else if (minX > i->second.x)
            minX = i->second.x;

        if (maxY < i->first.y)
            maxY = i->first.y;
        else if (minX > i->first.y)
            minX = i->first.y;

        if (maxY < i->second.y)
            maxY = i->second.y;
        else if (minY > i->second.y)
            minY = i->second.y;
    }
    maxX++;
    maxY++;
    minX--;
    minY--;
}

void WaysMap::createWaysMap(int startIn)
{
    WaysMap::Vertex add;
    add.din = startIn + 1;

    QList<WaysMap::Coordinate> addCord;
    for (QMap<WaysMap::Coordinate, WaysMap::Vertex>::iterator i = map.begin(); i != map.end(); ++i){
        if (i.value().din == startIn){
            if (i.value().children.isEmpty()){
                if (onBorder(i.key().x, i.key().y + 1) && !isObstacles(i.key().x, i.key().y + 1))
                    i.value().children.append(WaysMap::Coordinate(i.key().x, i.key().y + 1));
                if (onBorder(i.key().x, i.key().y - 1) && !isObstacles(i.key().x, i.key().y - 1))
                    i.value().children.append(WaysMap::Coordinate(i.key().x, i.key().y - 1));
                if (onBorder(i.key().x + 1, i.key().y) && !isObstacles(i.key().x + 1, i.key().y))
                    i.value().children.append(WaysMap::Coordinate(i.key().x + 1, i.key().y));
                if (onBorder(i.key().x - 1, i.key().y) && !isObstacles(i.key().x - 1, i.key().y))
                    i.value().children.append(WaysMap::Coordinate(i.key().x - 1, i.key().y));
            }
            for (QList<WaysMap::Coordinate>::iterator li = i.value().children.begin(); li != i.value().children.end(); ++li){
                if (!map.contains(*li)){
                    addCord.append(*li);
                }
            }
        }
    }
    for (int i = 0; i < addCord.count(); ++i){
        map.insert(addCord[i], add);
    }
    if (!addCord.contains(end) || addCord.isEmpty()){
        createWaysMap(startIn + 1);
    }
    else if (!addCord.isEmpty()){
        if (onBorder(end.x, end.y + 1))
            add.children.append(WaysMap::Coordinate(end.x, end.y + 1));
        if (onBorder(end.x, end.y - 1))
            add.children.append(WaysMap::Coordinate(end.x, end.y - 1));
        if (onBorder(end.x + 1, end.y))
            add.children.append(WaysMap::Coordinate(end.x + 1, end.y));
        if (onBorder(end.x - 1, end.y))
            add.children.append(WaysMap::Coordinate(end.x - 1, end.y));
        map.insert(end, add);
    }
}

WaysMap::Coordinate WaysMap::getNextStep(WaysMap::Coordinate &c)
{
    if (map.value(map.value(c).children[0]).din == map.value(c).din - 1)
        return map.value(c).children[0];
    if (map.value(map.value(c).children[1]).din == map.value(c).din - 1)
        return map.value(c).children[1];
    if (map.value(map.value(c).children[2]).din == map.value(c).din - 1)
        return map.value(c).children[2];
    return map.value(c).children[3];
}

QList<WaysMap::Coordinate> WaysMap::getWay()
{
    QList<WaysMap::Coordinate> way;
    if (map.contains(end)){
    	way.append(end);

    	while (way.first() != start){
        	way.push_front(getNextStep(way.first()));
    	}
	}
    return way;
}

bool WaysMap::onBorder(int x, int y)
{
    return (maxX >= x && minX <= x && maxY >= y && minY <= y);
}

bool WaysMap::isObstacles(int x, int y)
{
    for (QList <QPair< WaysMap::Coordinate, WaysMap::Coordinate> >::iterator i = obstacles.begin();
         i != obstacles.end(); ++i){
        if (i->second.x >= x && i->first.x <= x && i->second.y >= y && i->first.y <= y)
            return true;
    }
    return false;
}


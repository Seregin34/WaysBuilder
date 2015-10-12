#include <waysmap.h>
#include <QFile>
#include <QString>
#include <QRegExp>
#include <QStringList>
/*!
 * \brief readStartEnd - Считывает координаты начала и конца из файла с заданным именемм
 * \param file - Имя файла
 * \param start - Начало
 * \param end - Конец
 * \return - 0 в случии успешного считывания
 */
int readStartEnd(QString file, WaysMap::Coordinate &start, WaysMap::Coordinate &end);
/*!
 * \brief readCoordinates - Считываетс списо координат
 * \param file - Имя файла
 * \param list - Список координат к считыванию
 * \return - 0 в случае успешного счтиывания
 */
int readCoordinates(QString file, QList<QPair<WaysMap::Coordinate, WaysMap::Coordinate> > &list);
/*!
 * \brief out - Вывесли список координат
 * \param file - Имя файла
 * \param cl - список
 * \return успешность
 */
bool out(QString file, QList<WaysMap::Coordinate> &cl);

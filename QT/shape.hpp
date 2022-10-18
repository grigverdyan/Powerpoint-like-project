#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <QString>
#include <QVector>
#include <QIterator>

#include "properties.hpp"

class Shape
{
public:
    virtual ~Shape();
    virtual QVector<Point *>& getPoints() = 0;

protected:
    Shape();

protected:
    QString type;
    QString color;
    QVector<Point *> m_pointsVector;
    int m_pointsCount;
    int id;
};

#endif // SHAPE_HPP

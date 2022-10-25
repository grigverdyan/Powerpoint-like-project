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
    QString _type;
    QString _color;
    QVector<Point *> _pointsVector;
    int _pointsCount;
    int _id;
};

#endif // SHAPE_HPP

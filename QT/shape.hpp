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
    virtual std::vector<Point *>& getPoints() = 0;

protected:
    Shape();

protected:
    QString color;
    QVector<Point *> m_pointsVector;
    int m_pointsCount;
};

#endif // SHAPE_HPP

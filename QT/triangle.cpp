#include "triangle.hpp"

Triangle::Triangle()
{
    _type = "triangle";
}

Triangle::~Triangle()
{
    for (auto it = _pointsVector.begin(); it != _pointsVector.end(); ++it)
        delete *it;
}

QVector<Point *>& Triangle::getPoints()
{
    return _pointsVector;
}

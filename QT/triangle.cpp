#include "triangle.hpp"

Triangle::Triangle()
{
    type = "triangle";
}

Triangle::~Triangle()
{
    for (auto it = m_pointsVector.begin(); it != m_pointsVector.end(); ++it)
        delete *it;
}

QVector<Point *>& Triangle::getPoints()
{
    return m_pointsVector;
}

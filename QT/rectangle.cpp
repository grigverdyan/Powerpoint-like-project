#include "rectangle.hpp"

Rectangle::Rectangle()
{
    type = "rectangle";
}

Rectangle::~Rectangle()
{
    for (auto it = m_pointsVector.begin(); it != m_pointsVector.end(); ++it)
        delete *it;
}

QVector<Point *>& Rectangle::getPoints()
{
    return m_pointsVector;
}

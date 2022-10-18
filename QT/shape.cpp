#include "shape.hpp"

Shape::Shape()
{
    type = "empty";
    color = "empty";
    m_pointsVector.push_back(nullptr);
    m_pointsCount = 0;
    id  = 0;
}

Shape::~Shape()
{
    for (auto it = m_pointsVector.begin(); it != m_pointsVector.end(); ++it)
        delete *it;
}

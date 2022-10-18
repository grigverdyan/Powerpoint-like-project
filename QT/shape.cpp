#include "shape.hpp"

Shape::Shape()
{
    m_pointsVector.push_back(nullptr);
    m_pointsCount = 0;
}

Shape::~Shape()
{
    for (auto it = m_pointsVector.begin(); it != m_pointsVector.end(); ++it)
        delete *it;
}

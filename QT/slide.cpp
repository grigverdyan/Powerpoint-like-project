#include "slide.hpp"

Slide::Slide()
{
    m_shapesVector.push_back(nullptr);
    m_shapesCount = 0;
}

Slide::~Slide()
{
    for (auto it = m_shapesVector.begin(); it != m_shapesVector.end(); ++it)
        delete *it;
}

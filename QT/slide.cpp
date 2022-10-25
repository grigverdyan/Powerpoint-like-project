#include "slide.hpp"

Slide::Slide()
{
    _shapesVector.push_back(nullptr);
    _shapesCount = 0;
}

Slide::~Slide()
{
    for (auto it = _shapesVector.begin(); it != _shapesVector.end(); ++it)
        delete *it;
}

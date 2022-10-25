#include "shape.hpp"

Shape::Shape()
{
    _type = "empty";
    _color = "empty";
    _pointsVector.push_back(nullptr);
    _pointsCount = 0;
    _id  = 0;
}

Shape::~Shape()
{
    for (auto it = _pointsVector.begin(); it != _pointsVector.end(); ++it)
        delete *it;
}

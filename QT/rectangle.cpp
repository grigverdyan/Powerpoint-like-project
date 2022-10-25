#include "rectangle.hpp"

Rectangle::Rectangle(unsigned int width, unsigned int length)
    : Shape(), _width{width}, _length{length}
{
    ++_id;
    _type = "rectangle";
}

Rectangle::~Rectangle()
{
    for (auto it = _pointsVector.begin(); it != _pointsVector.end(); ++it)
        delete *it;
}

QVector<Point *>& Rectangle::getPoints()
{
    return _pointsVector;
}

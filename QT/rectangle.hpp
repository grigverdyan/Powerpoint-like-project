#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(unsigned int width, unsigned int length);
    virtual ~Rectangle();
    QVector<Point *>& getPoints() override;

private:
    unsigned int _width;
    unsigned int _length;
};

#endif // RECTANGLE_HPP

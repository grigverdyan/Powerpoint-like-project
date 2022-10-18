#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle();
    virtual ~Rectangle();
    QVector<Point *>& getPoints() override;

private:

};

#endif // RECTANGLE_HPP

#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle : public Shape
{
public:
    Triangle();
    virtual ~Triangle();
    QVector<Point *>& getPoints() override;

private:

};

#endif // TRIANGLE_HPP

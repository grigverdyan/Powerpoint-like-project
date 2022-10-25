#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <QVector>
#include <QIterator>

#include "shape.hpp"

class Slide
{
public:
    Slide();
    virtual ~Slide();

private:
    QVector<Shape *> _shapesVector;
    int _shapesCount;
};

#endif // SLIDE_HPP

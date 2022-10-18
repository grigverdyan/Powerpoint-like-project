#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <QVector>
#include <QIterator>

//#include "shape.hpp"

class Slide
{
public:
    Slide();
    virtual ~Slide();

private:
    QVector<int *> m_shapesVector;
    int m_shapesCount;
};

#endif // SLIDE_HPP

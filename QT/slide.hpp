#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <vector>
#include <iterator>

//#include "shape.hpp"

class Slide
{
public:
    Slide();
    virtual ~Slide();

private:
    std::vector<int *> m_shapesVector;
    int m_shapesCount;
};

#endif // SLIDE_HPP

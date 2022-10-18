#ifndef SLIDESMANAGER_HPP
#define SLIDESMANAGER_HPP

#include <vector>
#include <iterator>

#include "slide.hpp"

class SlidesManager
{
public:
    SlidesManager();
    virtual ~SlidesManager();

    // Member functions
    void addSlideInSlideManager();

private:
    std::vector<Slide *> m_slidesVector;
    int m_slidesCount;
};

#endif // SLIDESMANAGER_HPP

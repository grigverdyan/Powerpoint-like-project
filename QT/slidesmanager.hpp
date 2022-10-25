#ifndef SLIDESMANAGER_HPP
#define SLIDESMANAGER_HPP

#include <QVector>
#include <QIterator>

#include "slide.hpp"

class SlidesManager
{
public:
    SlidesManager();
    virtual ~SlidesManager();

    // Member functions
    void addSlideInSlideManager();

private:
    QVector<Slide *> _slidesVector;
    unsigned int _slidesCount;
};

#endif // SLIDESMANAGER_HPP

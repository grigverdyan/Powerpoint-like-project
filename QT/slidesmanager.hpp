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
    QVector<Slide *> m_slidesVector;
    int m_slidesCount;
};

#endif // SLIDESMANAGER_HPP

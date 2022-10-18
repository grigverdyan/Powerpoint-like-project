#ifndef SLIDESMANAGER_HPP
#define SLIDESMANAGER_HPP

#include <vector>
#include <iterator>

class SlidesManager
{
public:
    SlidesManager();
    virtual ~SlidesManager();

private:
    std::vector<Slide *> m_slidesVector;
    int m_slidesCount;
};

#endif // SLIDESMANAGER_HPP

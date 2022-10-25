#include "slidesmanager.hpp"

SlidesManager::SlidesManager()
{
    _slidesVector.push_back(nullptr);
    _slidesCount = 0;
}

SlidesManager::~SlidesManager()
{
    for (auto it = _slidesVector.begin(); it != _slidesVector.end(); ++it)
        delete *it;
}

void SlidesManager::addSlideInSlideManager()
{
    _slidesVector.push_back(new Slide());
    ++_slidesCount;
}

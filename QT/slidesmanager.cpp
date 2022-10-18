#include "slidesmanager.hpp"

SlidesManager::SlidesManager()
{
    m_slidesVector.push_back(nullptr);
    m_slidesCount = 0;
}

SlidesManager::~SlidesManager()
{
    for (auto it = m_slidesVector.begin(); it != m_slidesVector.end(); ++it)
        delete *it;
}

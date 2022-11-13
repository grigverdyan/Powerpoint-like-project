#include "shape.h"

Shape::Shape(std::vector<QPoint> points)
    : points_{std::move(points)}
{}


void    Shape::addPoint(QPoint& point)
{
    points_.push_back(point);
}
void    Shape::drawShape()
{
    for (int i = 0; i < points_.size(); i += 2)
    {
        auto    point1 = points_[i];
        auto    point2 = points_[i + 1];

        QLine   line{point1, point2};
    }
}

#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint>
#include <vector>
#include <QLine>

class Shape
{
public:
    Shape() = delete;
    ~Shape() = default;
    Shape(std::vector<QPoint> points);

public:
    void        drawShape();
    void        addPoint(QPoint& point);

private:
    std::vector<QPoint>     points_{};
};

#endif // SHAPE_H

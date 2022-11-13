#ifndef SLIDE_H
#define SLIDE_H

#include <QWidget>
#include <QPainter>
#include <vector>

#include "shape.h"

class Slide : public QWidget
{
    Q_OBJECT

public:
    Slide() = default;
    ~Slide() = default;

public:
    void    addShape(Shape shape);
    void    selectSlide();
    void    deselectSlide();

protected:
    void    mouseReleaseEvent(QMouseEvent* event) override;
    void    paintEvent(QPaintEvent* event) override;

private:
    bool                selected_;
    std::vector<Shape>  shapes_{};
};

#endif // SLIDE_H

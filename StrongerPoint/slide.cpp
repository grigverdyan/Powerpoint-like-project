#include "slide.h"
#include "qevent.h"

void    Slide::selectSlide()
{
    selected_ = true;
}

void    Slide::deselectSlide()
{
    selected_ = false;
}

void    Slide::addShape(Shape shape)
{
    shapes_.push_back(shape);
}

void Slide::mouseReleaseEvent(QMouseEvent* event) {
    auto pos = event->position();
    Shape shape{{QPoint(pos.x(), pos.y())}};
}

void Slide::paintEvent(QPaintEvent* event) {
    for (auto & shape: shapes_) {
        shape.drawShape();
    }
}

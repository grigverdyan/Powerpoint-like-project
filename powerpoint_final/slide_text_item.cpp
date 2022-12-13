#include "slide_text_item.h"

SlideTextItem::SlideTextItem(QGraphicsItem* parent)
    : QGraphicsTextItem(parent) {

    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

QVariant SlideTextItem::itemChange(GraphicsItemChange change, const QVariant& value) {
    if (change == QGraphicsItem::ItemSelectedHasChanged) {
        emit selectedChange(this);
    }
    return value;
}

void SlideTextItem::focusOutEvent(QFocusEvent* event) {
    setTextInteractionFlags(Qt::NoTextInteraction);
    emit lostFocus(this);
    QGraphicsTextItem::focusOutEvent(event);
}

void SlideTextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {
    if (textInteractionFlags() == Qt::NoTextInteraction) {
        setTextInteractionFlags(Qt::TextEditorInteraction);
    }
    QGraphicsTextItem::mouseDoubleClickEvent(event);
}

int SlideTextItem::type() const {
    return Type;
}

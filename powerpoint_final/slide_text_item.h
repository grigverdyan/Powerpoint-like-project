#ifndef SLIDE_TEXT_ITEM_H
#define SLIDE_TEXT_ITEM_H

#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

class SlideTextItem : public QGraphicsTextItem
{
    Q_OBJECT

public:
    enum {
        Type = UserType + 3
    };

public:
    SlideTextItem(QGraphicsItem* = nullptr);
    ~SlideTextItem() = default;
    SlideTextItem(const SlideTextItem&) = delete;
    SlideTextItem& operator=(const SlideTextItem&) = delete;
    SlideTextItem(const SlideTextItem&&) = delete;
    SlideTextItem& operator=(const SlideTextItem&&) = delete;

public:
    int type() const override;

public: signals:
    void lostFocus(SlideTextItem*);
    void selectedChange(QGraphicsItem*);

protected:
    QVariant    itemChange(GraphicsItemChange, const QVariant&) override;

    void        focusOutEvent(QFocusEvent*) override;
    void        mouseDoubleClickEvent(QGraphicsSceneMouseEvent*) override;

};

#endif // SLIDE_TEXT_ITEM_H

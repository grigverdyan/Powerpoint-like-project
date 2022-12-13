#ifndef SLIDE_H
#define SLIDE_H

#include "slide_item.h"
#include "slide_text_item.h"

#include <QGraphicsScene>
#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <QPointF>
#include <QGraphicsLineItem>
#include <QFont>
#include <QGraphicsTextItem>


class Slide : public QGraphicsScene
{
    Q_OBJECT
public:
    enum Mode {
        InsertItem, InsertText, MoveItem
    };

public:
    explicit Slide(QMenu*, QObject* = nullptr);
    ~Slide() = default;
    Slide(const Slide&) = delete;
    Slide& operator=(const Slide&) = delete;
    Slide(const Slide&&) = delete;
    Slide& operator=(const Slide&&) = delete;

public:
    QFont font() const { return _font; }
    QColor textColor() const { return _textColor; }
    QColor itemColor() const { return _itemColor; }

    void setTextColor(const QColor&);
    void setItemColor(const QColor&);
    void setFont(const QFont&);

public slots:
    void setMode(Slide::Mode);
    void setItemType(SlideItem::SliderType );
    void editorLostFocus(SlideTextItem *);

signals:
    void itemInserted(SlideItem*);
    void textInserted(QGraphicsTextItem*);
    void itemSelected(QGraphicsItem*);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;

private:
    bool isItemChange(int) const;

    SlideItem::SliderType  _itemType;
    QMenu*                  _itemMenu;
    Mode                    _mode;
    bool                    _leftButtonDown;
    QPointF                 _startPoint;
    QFont                   _font;
    SlideTextItem*         _textItem;
    QColor                  _textColor;
    QColor                  _itemColor;

};

#endif // SLIDE_H

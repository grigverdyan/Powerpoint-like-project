#ifndef SLIDE_ITEM_H
#define SLIDE_ITEM_H

#include <QGraphicsPixmapItem>
#include <QList>
#include <QPixmap>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPolygonF>

class SlideItem : public QGraphicsPolygonItem
{
public:
    enum {
        Type = UserType + 15
    };

    enum SliderType {
        Step, Conditional, StartEnd, Io
    };

public:
    SlideItem(SliderType, QMenu*, QGraphicsItem* parent = nullptr);
    ~SlideItem() = default;
    SlideItem(const SlideItem&) = delete;
    SlideItem& operator=(const SlideItem&) = delete;
    SlideItem(const SlideItem&&) = delete;
    SlideItem& operator=(const SlideItem&&) = delete;

public:
    SliderType  getDiagramType() const;
    QPolygonF   getPolygon() const;

    QPixmap     image() const;
    int         type() const override;

protected:
    void        contextMenuEvent(QGraphicsSceneContextMenuEvent*) override;
    QVariant    itemChange(GraphicsItemChange, const QVariant&) override;

private:
    SliderType  _diagramType;
    QPolygonF   _polygon;
    QMenu*      _contextMenu;
};

#endif // SLIDE_ITEM_H

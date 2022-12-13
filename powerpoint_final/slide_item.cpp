#include "slide_item.h"
#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QMenu>
#include <QPainter>

SlideItem::SlideItem(SliderType diagramType, QMenu* contextMenu, QGraphicsItem* parent)
    : QGraphicsPolygonItem(parent), _diagramType(diagramType)
    , _contextMenu(contextMenu) {

    QPainterPath path;
    switch (_diagramType)
    {
        case StartEnd:
            path.moveTo(200, 50);
            path.arcTo(150, 0, 50, 50, 0, 90);
            path.arcTo(50, 0, 50, 50, 90, 90);
            path.arcTo(50, 50, 50, 50, 180, 90);
            path.arcTo(150, 50, 50, 50, 270, 90);
            path.lineTo(200, 25);
            _polygon = path.toFillPolygon();
            break;
        case Conditional:
            _polygon << QPointF(-100, 0) << QPointF(0, 100)
                     << QPointF(100, 0)  << QPointF(0, -100)
                     << QPointF(-100, 0);
            break;
        case Step:
            _polygon << QPointF(-100, -100) << QPointF(100, -100)
                     << QPointF(100, 100)   << QPointF(-100, 100)
                     << QPointF(-100, -100);
            break;
        default:
            _polygon << QPointF(-120, -80) << QPointF(-70, 80)
                     << QPointF(120, 80)   << QPointF(70, -80)
                     << QPointF(-120, -80);
            break;
    }

    setPolygon(_polygon);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges, true);
}

SlideItem::SliderType  SlideItem::getDiagramType() const {
    return _diagramType;
}

QPolygonF SlideItem::getPolygon() const {
    return _polygon;
}

int SlideItem::type() const {
    return Type;
}

QPixmap SlideItem::image() const {
    QPixmap pixmap(250, 250);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(QPen(Qt::black, 8));
    painter.translate(125, 125);
    painter.drawPolyline(_polygon);

    return pixmap;
}

void SlideItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event) {
    scene()->clearSelection();
    setSelected(true);
    _contextMenu->exec(event->screenPos());
}

QVariant SlideItem::itemChange(GraphicsItemChange change, const QVariant &value) {
    (void) change;
    return value;
}

#include "slide.h"
#include <QGraphicsSceneMouseEvent>
#include <QTextCursor>

Slide::Slide(QMenu *itemMenu, QObject *parent)
    : QGraphicsScene(parent) {
    itemMenu = itemMenu;
    _mode = MoveItem;
    _itemType = SlideItem::Step;
    _textItem = nullptr;
    _itemColor = Qt::white;
    _textColor = Qt::black;
}

void Slide::setTextColor(const QColor &color) {
    _textColor = color;
    if (isItemChange(SlideTextItem::Type)) {
        SlideTextItem *item = qgraphicsitem_cast<SlideTextItem *>(selectedItems().first());
        item->setDefaultTextColor(_textColor);
    }
}


void Slide::setItemColor(const QColor &color) {
    _itemColor = color;
    if (isItemChange(SlideItem::Type)) {
        SlideItem *item = qgraphicsitem_cast<SlideItem *>(selectedItems().first());
        item->setBrush(_itemColor);
    }
}

void Slide::setFont(const QFont &font) {
    _font = font;

    if (isItemChange(SlideTextItem::Type)) {
        QGraphicsTextItem *item = qgraphicsitem_cast<SlideTextItem *>(selectedItems().first());
        if (item) {
            item->setFont(_font);
        }
    }
}

void Slide::setMode(Mode mode) {
    _mode = mode;
}

void Slide::setItemType(SlideItem::SliderType type) {
    _itemType = type;
}

void Slide::editorLostFocus(SlideTextItem *item) {
    QTextCursor cursor = item->textCursor();
    cursor.clearSelection();
    item->setTextCursor(cursor);

    if (item->toPlainText().isEmpty()) {
        removeItem(item);
        item->deleteLater();
    }
}

void Slide::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    if (mouseEvent->button() != Qt::LeftButton)
        return;

    SlideItem *item;
    switch (_mode) {
        case InsertItem:
            item = new SlideItem(_itemType, _itemMenu);
            item->setBrush(_itemColor);
            addItem(item);
            item->setPos(mouseEvent->scenePos());
            emit itemInserted(item);
            break;
        case InsertText:
            _textItem = new SlideTextItem();
            _textItem->setFont(_font);
            _textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
            _textItem->setZValue(1000.0);
            connect(_textItem, &SlideTextItem::lostFocus,
                    this, &Slide::editorLostFocus);
            connect(_textItem, &SlideTextItem::selectedChange,
                    this, &Slide::itemSelected);
            addItem(_textItem);
            _textItem->setDefaultTextColor(_textColor);
            _textItem->setPos(mouseEvent->scenePos());
            emit textInserted(_textItem);

    default:
        ;
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void Slide::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) {
     if (_mode == MoveItem) {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }
}

void Slide::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) {

    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

bool Slide::isItemChange(int type) const {
    const QList<QGraphicsItem *> items = selectedItems();
    const auto cb = [type](const QGraphicsItem *item) { return item->type() == type; };
    return std::find_if(items.begin(), items.end(), cb) != items.end();
}

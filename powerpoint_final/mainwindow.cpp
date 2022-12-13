#include "slide_item.h"
#include "slide.h"
#include "slide_text_item.h"
#include "mainwindow.h"

#include <QtWidgets>

const int InsertTextButton = 10;

MainWindow::MainWindow() {
        createActions();
        createToolBox();
        createMenus();

        _scene = new Slide(_itemMenu, this);
        _scene->setSceneRect(QRectF(0, 0, 5000, 5000));
        connect(_scene, &Slide::itemInserted,
                this, &MainWindow::itemInserted);
        connect(_scene, &Slide::textInserted,
                this, &MainWindow::textInserted);
        connect(_scene, &Slide::itemSelected,
                this, &MainWindow::itemSelected);
        createToolbars();

        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(_toolBox);
        _view = new QGraphicsView(_scene);
        layout->addWidget(_view);

        QWidget *widget = new QWidget;
        widget->setLayout(layout);

        setCentralWidget(widget);
        setWindowTitle(tr("PowerPoint"));
        setUnifiedTitleAndToolBarOnMac(true);

}

void MainWindow::buttonGroupClicked(QAbstractButton* button) {
    const QList<QAbstractButton *> buttons = _buttonGroup->buttons();
    for (QAbstractButton *myButton : buttons)
    {
        if (myButton != button) {
            button->setChecked(false);
        }
    }
    const int id = _buttonGroup->id(button);
    if (id == InsertTextButton) {
        _scene->setMode(Slide::InsertText);
    } else {
        _scene->setItemType(SlideItem::SliderType(id));
        _scene->setMode(Slide::InsertItem);
    }
}

void MainWindow::deleteItem() {
    QList<QGraphicsItem *> selectedItems = _scene->selectedItems();
    for (QGraphicsItem *item : qAsConst(selectedItems))
    {
        delete item;
    }

    selectedItems = _scene->selectedItems();
    for (QGraphicsItem *item : qAsConst(selectedItems))
    {
         if (item->type() == SlideItem::Type) {
             _scene->removeItem(item);
         }
         delete item;
     }
}

void MainWindow::pointerGroupClicked() {
    _scene->setMode(Slide::Mode(_pointerTypeGroup->checkedId()));
}

void MainWindow::itemInserted(SlideItem *item) {
    _pointerTypeGroup->button(int(Slide::MoveItem))->setChecked(true);
    _scene->setMode(Slide::Mode(_pointerTypeGroup->checkedId()));
    _buttonGroup->button(int(item->getDiagramType()))->setChecked(false);
}

void MainWindow::textInserted(QGraphicsTextItem *) {
    _buttonGroup->button(InsertTextButton)->setChecked(false);
    _scene->setMode(Slide::Mode(_pointerTypeGroup->checkedId()));
}

void MainWindow::currentFontChanged(const QFont &) {
    handleFontChange();
}

void MainWindow::fontSizeChanged(const QString &) {
    handleFontChange();
}

void MainWindow::sceneScaleChanged(const QString &scale) {
    double newScale = scale.left(scale.indexOf(tr("%"))).toDouble() / 100.0;
    QTransform oldMatrix = _view->transform();
    _view->resetTransform();
    _view->translate(oldMatrix.dx(), oldMatrix.dy());
    _view->scale(newScale, newScale);
}

void MainWindow::textColorChanged() {
    _textAction = qobject_cast<QAction *>(sender());
    _fontColorToolButton->setIcon(createColorToolButtonIcon(":/images/textpointer.png", qvariant_cast<QColor>(_textAction->data())));
    textButtonTriggered();
}

void MainWindow::itemColorChanged() {
    _fillAction = qobject_cast<QAction *>(sender());
    _fillColorToolButton->setIcon(createColorToolButtonIcon(":/images/floodfill.png", qvariant_cast<QColor>(_fillAction->data())));
    fillButtonTriggered();
}

void MainWindow::textButtonTriggered() {
    _scene->setTextColor(qvariant_cast<QColor>(_textAction->data()));
}

void MainWindow::fillButtonTriggered() {
    _scene->setItemColor(qvariant_cast<QColor>(_fillAction->data()));
}

void MainWindow::handleFontChange() {
    QFont font = _fontCombo->currentFont();
    font.setPointSize(_fontSizeCombo->currentText().toInt());
    font.setWeight(_boldAction->isChecked() ? QFont::Bold : QFont::Normal);
    font.setItalic(_italicAction->isChecked());
    font.setUnderline(_underlineAction->isChecked());

    _scene->setFont(font);
}

void MainWindow::itemSelected(QGraphicsItem* item) {
    SlideTextItem* textItem =
    qgraphicsitem_cast<SlideTextItem *>(item);

    QFont font = textItem->font();
    _fontCombo->setCurrentFont(font);
    _fontSizeCombo->setEditText(QString().setNum(font.pointSize()));
    _boldAction->setChecked(font.weight() == QFont::Bold);
    _italicAction->setChecked(font.italic());
    _underlineAction->setChecked(font.underline());
}

void MainWindow::about() {
    QMessageBox::about(this, tr("Slide"), tr("About Slide") );
}

void MainWindow::createToolBox() {
    _buttonGroup = new QButtonGroup(this);
    _buttonGroup->setExclusive(false);
    connect(_buttonGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            this, &MainWindow::buttonGroupClicked);
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createCellWidget(tr("Diagonal"), SlideItem::Conditional), 0, 0);
    layout->addWidget(createCellWidget(tr("Rectangle"), SlideItem::Step),0, 1);
    layout->addWidget(createCellWidget(tr("Tetragon"), SlideItem::Io), 1, 0);

    QToolButton *textButton = new QToolButton;
    textButton->setCheckable(true);
    _buttonGroup->addButton(textButton, InsertTextButton);
    textButton->setIcon(QIcon(QPixmap(":/images/textpointer.png")));
    textButton->setIconSize(QSize(50, 50));
    QGridLayout *textLayout = new QGridLayout;
    textLayout->addWidget(textButton, 0, 0, Qt::AlignHCenter);
    textLayout->addWidget(new QLabel(tr("Text")), 1, 0, Qt::AlignCenter);
    QWidget *textWidget = new QWidget;
    textWidget->setLayout(textLayout);
    layout->addWidget(textWidget, 1, 1);

    layout->setRowStretch(3, 10);
    layout->setColumnStretch(2, 10);

    QWidget* itemWidget = new QWidget;
    itemWidget->setLayout(layout);
    _toolBox = new QToolBox;
    _toolBox->setSizePolicy(QSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored));
    _toolBox->setMinimumWidth(itemWidget->sizeHint().width());
    _toolBox->addItem(itemWidget, tr("Shapes"));
}

void MainWindow::createActions() {
    _deleteAction = new QAction(QIcon(":/images/delete.png"), tr("&Delete"), this);
    _deleteAction->setShortcut(tr("Delete"));
    _deleteAction->setStatusTip(tr("Delete item from diagram"));
    connect(_deleteAction, &QAction::triggered, this, &MainWindow::deleteItem);

    _exitAction = new QAction(tr("E&xit"), this);
    _exitAction->setShortcuts(QKeySequence::Quit);
    _exitAction->setStatusTip(tr("Quit Scenediagram example"));
    connect(_exitAction, &QAction::triggered, this, &QWidget::close);

    _boldAction = new QAction(tr("Bold"), this);
    _boldAction->setCheckable(true);
    QPixmap pixmap(":/images/bold.png");
    _boldAction->setIcon(QIcon(pixmap));
    _boldAction->setShortcut(tr("Ctrl+B"));
    connect(_boldAction, &QAction::triggered, this, &MainWindow::handleFontChange);

    _italicAction = new QAction(QIcon(":/images/italic.png"), tr("Italic"), this);
    _italicAction->setCheckable(true);
    _italicAction->setShortcut(tr("Ctrl+I"));
    connect(_italicAction, &QAction::triggered, this, &MainWindow::handleFontChange);

    _underlineAction = new QAction(QIcon(":/images/underline.png"), tr("Underline"), this);
    _underlineAction->setCheckable(true);
    _underlineAction->setShortcut(tr("Ctrl+U"));
    connect(_underlineAction, &QAction::triggered, this, &MainWindow::handleFontChange);

    _aboutAction = new QAction(tr("&About"), this);
    _aboutAction->setShortcut(tr("F1"));
    connect(_aboutAction, &QAction::triggered, this, &MainWindow::about);
}

void MainWindow::createMenus() {
    _fileMenu = menuBar()->addMenu(tr("&File"));
    _fileMenu->addAction(_exitAction);

    _itemMenu = menuBar()->addMenu(tr("&Item"));
    _itemMenu->addAction(_deleteAction);
    _itemMenu->addSeparator();


    _aboutMenu = menuBar()->addMenu(tr("&Help"));
    _aboutMenu->addAction(_aboutAction);
}

void MainWindow::createToolbars() {
    _editToolbar = addToolBar(tr("Edit"));
    _editToolbar->addAction(_deleteAction);


    _fontCombo = new QFontComboBox();
    connect(_fontCombo, &QFontComboBox::currentFontChanged,
            this, &MainWindow::currentFontChanged);

    _fontSizeCombo = new QComboBox;
    _fontSizeCombo->setEditable(true);
    for (int i = 8; i < 30; i +=2)
        _fontSizeCombo->addItem(QString().setNum(i));
    QIntValidator *validator = new QIntValidator(2, 64, this);
    _fontSizeCombo->setValidator(validator);
    connect(_fontSizeCombo, &QComboBox::currentTextChanged,
            this, &MainWindow::fontSizeChanged);

    _fontColorToolButton = new QToolButton;
    _fontColorToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    _fontColorToolButton->setMenu(createColorMenu(SLOT(textColorChanged()), Qt::black));
    _textAction = _fontColorToolButton->menu()->defaultAction();
    _fontColorToolButton->setIcon(createColorToolButtonIcon(":/images/textpointer.png", Qt::black));
    _fontColorToolButton->setAutoFillBackground(true);
    connect(_fontColorToolButton, &QAbstractButton::clicked,
            this, &MainWindow::textButtonTriggered);

    _fillColorToolButton = new QToolButton;
    _fillColorToolButton->setPopupMode(QToolButton::MenuButtonPopup);
    _fillColorToolButton->setMenu(createColorMenu(SLOT(itemColorChanged()), Qt::white));
    _fillAction = _fillColorToolButton->menu()->defaultAction();
    _fillColorToolButton->setIcon(createColorToolButtonIcon(
                                     ":/images/floodfill.png", Qt::white));
    connect(_fillColorToolButton, &QAbstractButton::clicked,
            this, &MainWindow::fillButtonTriggered);

    _textToolbar = addToolBar(tr("Font"));
    _textToolbar->addWidget(_fontCombo);
    _textToolbar->addWidget(_fontSizeCombo);
    _textToolbar->addAction(_boldAction);
    _textToolbar->addAction(_italicAction);
    _textToolbar->addAction(_underlineAction);

    _colorToolbar = addToolBar(tr("Color"));
    _colorToolbar->addWidget(_fontColorToolButton);
    _colorToolbar->addWidget(_fillColorToolButton);


    QToolButton *pointerButton = new QToolButton;
    pointerButton->setCheckable(true);
    pointerButton->setChecked(true);
    pointerButton->setIcon(QIcon(":/images/pointer.png"));

    _pointerTypeGroup = new QButtonGroup(this);
    _pointerTypeGroup->addButton(pointerButton, int(Slide::MoveItem));

    connect(_pointerTypeGroup, QOverload<QAbstractButton *>::of(&QButtonGroup::buttonClicked),
            this, &MainWindow::pointerGroupClicked);

    _sceneScaleCombo = new QComboBox;
    QStringList scales;
    scales << tr("50%") << tr("75%") << tr("100%") << tr("125%") << tr("150%");
    _sceneScaleCombo->addItems(scales);
    _sceneScaleCombo->setCurrentIndex(2);
    connect(_sceneScaleCombo, &QComboBox::currentTextChanged,
            this, &MainWindow::sceneScaleChanged);
}

QWidget *MainWindow::createCellWidget(const QString& text, SlideItem::SliderType type) {

    SlideItem item(type, _itemMenu);
    QIcon icon(item.image());

    QToolButton *button = new QToolButton;
    button->setIcon(icon);
    button->setIconSize(QSize(50, 50));
    button->setCheckable(true);
    _buttonGroup->addButton(button, int(type));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(button, 0, 0, Qt::AlignHCenter);
    layout->addWidget(new QLabel(text), 1, 0, Qt::AlignCenter);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    return widget;
}

QMenu *MainWindow::createColorMenu(const char* slot, QColor defaultColor) {
    QList<QColor> colors;
    colors << Qt::black << Qt::white << Qt::red << Qt::blue << Qt::yellow;
    QStringList names;
    names << tr("black") << tr("white") << tr("red") << tr("blue")
          << tr("yellow");

    QMenu *colorMenu = new QMenu(this);
    for (int i = 0; i < colors.count(); ++i) {
        QAction *action = new QAction(names.at(i), this);
        action->setData(colors.at(i));
        action->setIcon(createColorIcon(colors.at(i)));
        connect(action, SIGNAL(triggered()), this, slot);
        colorMenu->addAction(action);
        if (colors.at(i) == defaultColor)
            colorMenu->setDefaultAction(action);
    }
    return colorMenu;
}

QIcon MainWindow::createColorToolButtonIcon(const QString& imageFile, QColor color) {
    QPixmap pixmap(50, 80);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    QPixmap image(imageFile);
    QRect target(4, 0, 42, 43);
    QRect source(0, 0, 42, 43);
    painter.fillRect(QRect(0, 60, 50, 80), color);
    painter.drawPixmap(target, image, source);

    return QIcon(pixmap);
}

QIcon MainWindow::createColorIcon(QColor color) {
    QPixmap pixmap(20, 20);
    QPainter painter(&pixmap);
    painter.setPen(Qt::NoPen);
    painter.fillRect(QRect(0, 0, 20, 20), color);

    return QIcon(pixmap);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "slide_item.h"

#include <QMainWindow>
#include <QActionGroup>
#include <QLabel>
#include <QToolBar>
#include <QGraphicsScene>
#include <QToolBox>
#include <QToolButton>
#include <QComboBox>
#include <QFontComboBox>
#include <QButtonGroup>

class Slide;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   MainWindow();
   ~MainWindow() = default;
   MainWindow(const MainWindow&) = delete;
   MainWindow& operator=(const MainWindow&) = delete;
   MainWindow(const MainWindow&&) = delete;
   MainWindow& operator=(const MainWindow&&) = delete;

private slots:
    void buttonGroupClicked(QAbstractButton*);

    void deleteItem();

    void pointerGroupClicked();

    void itemInserted(SlideItem*);
    void textInserted(QGraphicsTextItem*);

    void currentFontChanged(const QFont&);
    void fontSizeChanged(const QString&);
    void sceneScaleChanged(const QString&);
    void textColorChanged();
    void itemColorChanged();

    void textButtonTriggered();
    void fillButtonTriggered();

    void handleFontChange();
    void itemSelected(QGraphicsItem*);
    void about();

private:
    QWidget*    createCellWidget(const QString&, SlideItem::SliderType);
    QMenu*      createColorMenu(const char*, QColor);
    QIcon       createColorToolButtonIcon(const QString&, QColor);
    QIcon       createColorIcon(QColor);

private:
    void createToolBox();
    void createActions();
    void createMenus();
    void createToolbars();

private:
    Slide*              _scene;

    QGraphicsView*      _view;

    QAction*            _exitAction;
    QAction*            _addAction;
    QAction*            _deleteAction;
    QAction*            _aboutAction;
    QAction*            _boldAction;
    QAction*            _underlineAction;
    QAction*            _italicAction;
    QAction*            _textAction;
    QAction*            _fillAction;

    QMenu*              _fileMenu;
    QMenu*              _itemMenu;
    QMenu*              _aboutMenu;

    QToolBar*           _textToolbar;
    QToolBar*           _editToolbar;
    QToolBar*           _colorToolbar;

    QComboBox*          _sceneScaleCombo;
    QComboBox*          _itemColorCombo;
    QComboBox*          _textColorCombo;
    QComboBox*          _fontSizeCombo;

    QFontComboBox*      _fontCombo;

    QToolBox*           _toolBox;

    QButtonGroup*       _buttonGroup;
    QButtonGroup*       _pointerTypeGroup;

    QToolButton*        _fontColorToolButton;
    QToolButton*        _fillColorToolButton;
};


#endif // MAINWINDOW_H

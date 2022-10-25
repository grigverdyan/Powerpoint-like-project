#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QVector>
#include <QIterator>

#include "slidesmanager.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private slots:
    // Main Window actions
    void on_actionNew_triggered();
    void on_actionRectangle_triggered();
    void on_toolButton_next_clicked();
    void on_toolButton_prev_clicked();
    void slide_button_clicked(QPushButton*);

    // Member functions
    void setup();
    void addSlide(const QString&);
    void setButtonSize(QPushButton *button, int width, int height);

private:
    // Main Window attributes
    Ui::MainWindow *ui;
    QVBoxLayout *_scrollLayout;
    QVector<QPushButton *> _slidesButtons;
    int _slidesButtonsCount;

    // Slides managment attributes
    SlidesManager *_slidesManager;
    int _currentSlide;
};

#endif // MAINWINDOW_HPP

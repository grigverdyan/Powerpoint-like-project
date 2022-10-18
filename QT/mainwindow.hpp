#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <vector>
#include <iterator>

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
    void button_clicked(QPushButton*);

    // Member functions
    void setup();
    void addSlide(const QString&);
    void setButtonSize(QPushButton *button, int width, int height);

private:
    // Main Window attributes
    Ui::MainWindow *ui;
    QVBoxLayout *m_scrollLayout;
    std::vector<QPushButton *> m_slidesButtons;
    int m_slidesButtonsCount;

    // Slides managment attributes
    SlidesManager *m_slidesManager;
};

#endif // MAINWINDOW_HPP

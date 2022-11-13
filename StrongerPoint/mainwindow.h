#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QLineEdit>
#include <QDebug>

#include "slide.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget         centralWidget_;

    QVBoxLayout     mainLayout_;
    QHBoxLayout     toolbarLayout_;
    QHBoxLayout     envLayout_;
    QVBoxLayout     slidesLayout_;
    QVBoxLayout     workLayout_;

    QLineEdit       commandBar_;

    Slide           slide_;
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "properties.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), slide_()
{
    this->setFixedSize((int)Properties::MainHWin, (int)Properties::MainVWin);


    workLayout_.addWidget(&slide_);
    workLayout_.addWidget(&commandBar_);

    mainLayout_.addLayout(&toolbarLayout_);
    mainLayout_.addLayout(&envLayout_);
    envLayout_.addLayout(&slidesLayout_);
    envLayout_.addLayout(&workLayout_);

    setCentralWidget(&centralWidget_);
    centralWidget_.setLayout(&mainLayout_);
    connect(&commandBar_, &QLineEdit::editingFinished,
            [this]()
    {
        QString input = commandBar_.text();
        input_.setInput(input);
        qDebug() << commandBar_.text();
        commandBar_.clear();
    });
}

MainWindow::~MainWindow()
{}


#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), slide_()
{
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
       qDebug() << commandBar_.text();
       commandBar_.clear();
    });
}

MainWindow::~MainWindow()
{}


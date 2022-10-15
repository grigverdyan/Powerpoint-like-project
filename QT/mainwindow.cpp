#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000,600);
    ui->stackedWidget->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{

}

void MainWindow::on_actionRectangle_triggered()
{
    QPainter painter(this);
    painter.setBrush(Qt::DiagCrossPattern);

    QPen pen;

    pen.setColor(Qt::green);
    pen.setWidth(5);

    painter.setPen(pen);
    painter.drawRect(QRect(80,120,200,100));
}

void MainWindow::on_firstSlide_clicked()
{
    m_current_slide = 0;
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButton_next_clicked()
{
    if (m_current_slide < ui->stackedWidget->count() - 1)
        ui->stackedWidget->setCurrentIndex(++m_current_slide);
}


void MainWindow::on_toolButton_prev_clicked()
{
    if (m_current_slide > 0)
        ui->stackedWidget->setCurrentIndex(--m_current_slide);
}



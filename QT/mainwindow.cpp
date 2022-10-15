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

    QPushButton *button = new QPushButton("1");
    button->setSizeIncrement(130,100);
    button->setMinimumSize(130, 100);
    lay->addWidget(button);
    ui->scrollAreaWidgetContents->setLayout(lay);
    connect(button, &QPushButton::clicked, this, std::bind(&MainWindow::button_clicked, this, button));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    QPushButton *button = new QPushButton(QString::number(++temp));
    //QPushButton *button = new QPushButton(QString::number(ui->stackedWidget->count()));
    button->setSizeIncrement(130,100);
    button->setMinimumSize(130, 100);
    lay->addWidget(button);
    ui->scrollAreaWidgetContents->setLayout(lay);

    connect(button, &QPushButton::clicked, this, std::bind(&MainWindow::button_clicked, this, button));
    //stackwidget add new page
}

void MainWindow::button_clicked(QPushButton *button)
{
    qDebug() << "button " << button->text() << " clicked";
    ui->stackedWidget->setCurrentIndex(button->text().toInt() - 1);
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


/*connect(button, &QPushButton::clicked, [=]() {
            qDebug() << "button " << button->text() << " clicked";
        });*/



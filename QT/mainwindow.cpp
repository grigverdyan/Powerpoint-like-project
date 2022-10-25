#include "mainwindow.hpp"
#include "properties.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // set main window size
    ui->setupUi(this);
    this->setFixedSize(windowSizeHorizontal, windowSizeVerticale);

    setup();
    ui->slidesStackedWidget->setCurrentIndex(0);

    // Make first slide
    addSlide("1");
    _scrollLayout->addWidget(_slidesButtons[1]);
    ui->scrollAreaWidgetContents->setLayout(_scrollLayout);
    connect(_slidesButtons[1], &QPushButton::clicked, this, std::bind(&MainWindow::slide_button_clicked, this, _slidesButtons[1]));
}

MainWindow::~MainWindow()
{
    for (auto it = _slidesButtons.begin(); it != _slidesButtons.end(); ++it)
        delete *it;

    delete ui;
}

void MainWindow::setup()
{
    _scrollLayout = new QVBoxLayout(this);
    _slidesButtons.push_back(nullptr);
    _slidesButtonsCount = 0;
    _currentSlide = 0;
}

void MainWindow::addSlide(const QString& slideNumber)
{
    _slidesButtons.push_back(new QPushButton(slideNumber));
    ++_slidesButtonsCount;
    setButtonSize(_slidesButtons[_slidesButtonsCount], slideWidth, slideHeight);
    connect(_slidesButtons[_slidesButtonsCount], &QPushButton::clicked, this, std::bind(&MainWindow::slide_button_clicked, this, _slidesButtons[_slidesButtonsCount]));
    _slidesManager->addSlideInSlideManager();
}

void MainWindow::setButtonSize(QPushButton *button, int width, int height)
{
    button->setSizeIncrement(width, height);
    button->setMinimumSize(width, height);
}

void MainWindow::on_actionNew_triggered()
{
    // make new slide
    addSlide(QString::number(_slidesButtonsCount + 1));

    // update scroll bar
    _scrollLayout->addWidget(_slidesButtons[_slidesButtonsCount]);
    ui->scrollAreaWidgetContents->setLayout(_scrollLayout);
    connect(_slidesButtons[_slidesButtonsCount], &QPushButton::clicked, this, std::bind(&MainWindow::slide_button_clicked, this, _slidesButtons[_slidesButtonsCount]));

    // add new slide to stacked widget
    //      Implement later
    //ui->slidesStackedWidget->addWidget(m_slidesManager.getSlidesVector()[m_slidesButtonsCount].getWidget());
    _currentSlide = _slidesButtonsCount;
}

void MainWindow::slide_button_clicked(QPushButton *button)
{
    ui->slidesStackedWidget->setCurrentIndex(button->text().toInt() - 1);
    _currentSlide = button->text().toInt();
}

void MainWindow::on_toolButton_next_clicked()
{
    if (_currentSlide < ui->slidesStackedWidget->count() - 1)
        ui->slidesStackedWidget->setCurrentIndex(++_currentSlide);
}

void MainWindow::on_toolButton_prev_clicked()
{
    if (_currentSlide > 0)
        ui->slidesStackedWidget->setCurrentIndex(--_currentSlide);
}

/* * * * * must modify
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
*/

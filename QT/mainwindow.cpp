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
    m_scrollLayout->addWidget(m_slidesButtons[1]);
    ui->scrollAreaWidgetContents->setLayout(m_scrollLayout);
    connect(m_slidesButtons[1], &QPushButton::clicked, this, std::bind(&MainWindow::button_clicked, this, m_slidesButtons[1]));
}

MainWindow::~MainWindow()
{
    for (auto it = m_slidesButtons.begin(); it != m_slidesButtons.end(); ++it)
        delete *it;

    delete ui;
}

void MainWindow::setup()
{
    m_scrollLayout = new QVBoxLayout(this);
    m_slidesButtons.push_back(nullptr);
    m_slidesButtonsCount = 0;
}

void MainWindow::addSlide(const QString& slideNumber)
{
    m_slidesButtons.push_back(new QPushButton(slideNumber));
    ++m_slidesButtonsCount;
    setButtonSize(m_slidesButtons[m_slidesButtonsCount], slideWidth, slideHeight);

    //           Implement later
    //m_slidesManager->addSlideInManager();
}

void MainWindow::setButtonSize(QPushButton *button, int width, int height)
{
    button->setSizeIncrement(width, height);
    button->setMinimumSize(width, height);
}

void MainWindow::on_actionNew_triggered()
{
    // make new slide
    addSlide(QString::number(m_slidesButtonsCount + 1));

    // update scroll bar
    m_scrollLayout->addWidget(m_slidesButtons[m_slidesButtonsCount]);
    ui->scrollAreaWidgetContents->setLayout(m_scrollLayout);
    connect(m_slidesButtons[m_slidesButtonsCount], &QPushButton::clicked, this, std::bind(&MainWindow::button_clicked, this, m_slidesButtons[m_slidesButtonsCount]));

    // add new slide to stacked widget
    ui->slidesStackedWidget->addWidget(m_slidesManager.getSlidesVector()[m_slidesButtonsCount].getWidget());
}

void MainWindow::button_clicked(QPushButton *button)
{
    //qDebug() << "button " << button->text() << " clicked";
    ui->stackedWidget->setCurrentIndex(button->text().toInt() - 1);
    m_current_slide = button->text().toInt() - 1;
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



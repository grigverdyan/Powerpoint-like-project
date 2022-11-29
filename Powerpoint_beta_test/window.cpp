#include "window.h"
#include <QApplication>
#include <QLabel>
#include <QGridLayout>
#include <QDebug>

Window::Window(QWidget *parent)
    : QMainWindow(parent)
{


    _lineReaderName = new QLabel("Console", this);
   // _lineReaderName->setAlignment(Qt::AlignRight | Qt::AlignCenter | Qt::AlignBottom);
    _lineReaderName->setGeometry(30,30,50,50);
    _lineReader = new QLineEdit(this);
    //_lineReader->setGeometry(20, 900, 100, 100);
    QGridLayout *grid = new QGridLayout();
    grid->addWidget(_lineReaderName, 10, 0);
    grid->addWidget(_lineReader, 10, 1);
    setLayout(grid);



     //connect(_lineReader, &Window::keyPressEvent, this, &Window::OnPushInput);
//    _input = _lineReader->displayText();
//    qDebug() << "Line: " << _input;
    //_lineReader->show();
}

void    Window::OnPushInput()
{
    _input = _lineReader->displayText();
    qDebug() << "Line: " << _input;
    emit PushInput();
}

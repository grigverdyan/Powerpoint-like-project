#include "console_input.h"

ConsoleInput::ConsoleInput(QString& input)
    : input_{input}
{}

void    ConsoleInput::setInput(QString& input)
{
    input_ = input;
}

void    ConsoleInput::parseInput()
{
    input_ = input_.toLower();
    qDebug() << input_;
}

#ifndef CONSOLEINPUT_H
#define CONSOLEINPUT_H

#include <QString>
#include <QDebug>

class ConsoleInput
{
public:
    ConsoleInput() = default;
    ~ConsoleInput() = default;
    ConsoleInput(QString& input);

public:
    void    parseInput();
    void    setInput(QString& input);
protected:
        QString     input_{};
};

#endif // CONSOLEINPUT_H

#ifndef WINDOW_H
#define WINDOW_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);

signals:
    void    PushInput();

public slots:
    void    OnPushInput();
private:
    QLabel* _lineReaderName;
    QLineEdit* _lineReader;
    QString _input;

};

#endif // WINDOW_H

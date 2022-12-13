#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.setGeometry(300, 300, 800, 700);
    mainWindow.show();

    return app.exec();
}

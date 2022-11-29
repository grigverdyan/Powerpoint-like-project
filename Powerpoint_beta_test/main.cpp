#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window win;
    win.resize(1080, 720);
    win.setWindowTitle(QApplication::translate("toplevel", "Powerpoint"));
    win.show();
    win.OnPushInput();
    return app.exec();
}

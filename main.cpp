#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget *widget = Widget::get();
    widget->show();

    return a.exec();
}

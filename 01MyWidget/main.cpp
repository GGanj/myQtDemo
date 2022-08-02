#include "mywidget.h"

#include <QApplication>

// argc  command line paramaters count, argv paramaters array
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myWidget w;
    w.show();

    // inter message loop
    return a.exec();
}

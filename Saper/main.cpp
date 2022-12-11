#include "Saper.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Saper w;
    w.show();
    return a.exec();
}

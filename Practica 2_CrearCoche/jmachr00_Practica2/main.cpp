#include "vehiculo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    vehiculo w;
    w.show();

    return a.exec();
}

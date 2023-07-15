#include "OrderApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OrderApp w;
    w.show();
    return a.exec();
}

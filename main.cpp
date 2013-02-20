#include <QtGui/QApplication>
#include <QInputDialog>
#include "mainwindow.h"
#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QInputDialog options;
    options.exec();
    quint16 port = options.textValue().toShort();
    MainWindow w;
    Server server(&w, port);
    w.show();
    w.resize(480,320);
    
    return a.exec();
}

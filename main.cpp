#include <QtGui/QApplication>
#include <QInputDialog>
#include "mainwindow.h"
#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QInputDialog options;
    options.setLabelText("Enter port for listening:");
    options.exec();
    quint16 port = options.textValue().toShort();
    MainWindow w;
    Server server(&w, port);
    w.show();
    w.resize(480,320);
    w.setWindowTitle(w.windowTitle() + " (listen port: " + options.textValue() + ")");
    
    return a.exec();
}

//#include <QtGui/QApplication>
#include <QtGui>
#include <QApplication>
#include <QInputDialog>
#include "mainwindow.h"
#include "server.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Get the port we will listen on
    QInputDialog options;
    options.setLabelText("Enter port for listening:");
    options.setTextValue("12349");
    options.exec();
    quint16 port = options.textValue().toShort();

    MainWindow *window = new MainWindow();
    Server *server = new Server(port);

    window->connect(server, SIGNAL(messageRecieved(QString,QString)),
                    window, SLOT(displayNewMessage(QString,QString)));

    window->show();
    window->resize(480,320);
    window->setWindowTitle(window->windowTitle() + " (listen port: " + options.textValue() + ")");
    
    return a.exec();
}

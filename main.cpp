//#include <QtGui/QApplication>
#include <QtGui>
#include <QApplication>
#include <QInputDialog>
#include "mainwindow.h"
#include "server.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Get the port we will listen on
    QInputDialog options;
    options.setLabelText("Enter port for listening:");
    options.setTextValue("12349");
    options.exec();

    MainWindow window;
    Server server(options.textValue());
    Client client;

    window.connect(&server, SIGNAL(messageRecieved(QString,QString)),
                    &window, SLOT(displayNewMessage(QString,QString)));

    window.connect(&window, SIGNAL(connectToChanged(QString,QString)),
                   &client, SLOT(connectTo(QString,QString)));

    window.connect(&window, SIGNAL(sendMessage(QString)),
                   &client, SLOT(startTransfer(QString)));

    window.show();
    window.resize(480,320);
    window.setWindowTitle(window.windowTitle() + " (listen port: " + options.textValue() + ")");
    
    return a.exec();
}

#include <QString>
#include "server.h"
#include <iostream>
using namespace std;

Server::Server(MainWindow *win, quint16 port, QObject *parent): QObject(parent)
{
    window = win;
    connect(&server, SIGNAL(newConnection()),
    this, SLOT(acceptConnection()));

    server.listen(QHostAddress::Any, port);
}

Server::~Server()
{
    server.close();
}

void Server::acceptConnection()
{
    client = server.nextPendingConnection();
    connect(client, SIGNAL(readyRead()),
      this, SLOT(startRead()));
}

void Server::startRead()
{
    QString *msg;
    QString *sender;

    char buffer[1024] = {0};
    client->read(buffer, client->bytesAvailable());

    msg = new QString(buffer);
    sender = new QString(client->peerAddress().toString());

    window->displayNewMessage(msg, sender);
    client->close();
}

#include <QString>
#include "server.h"
#include <iostream>

Server::Server(QString port, QObject *parent): QObject(parent)
{
    connect(&server, SIGNAL(newConnection()),
    this, SLOT(acceptConnection()));

    server.listen(QHostAddress::Any, port.toShort());
    std::cout << "Listen on port: " << port.toStdString() << std::endl;
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
    std::cout << "Starting reading..." << std::endl;

    char buffer[1024] = {0};
    client->read(buffer, client->bytesAvailable());

    QString msg(buffer);
    QString sender(client->peerAddress().toString());

    emit messageRecieved(msg, sender);

    //client->close();
}

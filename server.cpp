#include <QString>
#include "server.h"
#include <iostream>

using namespace std;

Server::Server(quint16 port, QObject *parent): QObject(parent)
{
    connect(&server, SIGNAL(newConnection()),
    this, SLOT(acceptConnection()));

    server.listen(QHostAddress::Any, port);
    std::cout << "Listen on port: " << port << std::endl;
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

    client->close();
}

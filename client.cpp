#include <QHostAddress>
#include <QString>
#include <QTcpSocket>
#include <QByteArray>
#include <iostream>

#include "client.h"

Client::Client(QString msg, QObject* parent): QObject(parent)
{
    message = msg;
    connect(&socket, SIGNAL(connected()),
        this, SLOT(startTransfer()));
}

Client::~Client()
{
}

void Client::start(QString address, quint16 port)
{
    std::cout << "Connceting to " << address.toStdString() << std::endl;
    QHostAddress addr(address);
    socket.connectToHost(addr, port);
}

bool Client::isOpen()
{
    return socket.isOpen();
}

void Client::startTransfer()
{
    std::cout << "Starting transfer..." << std::endl;
    QByteArray messageArray;
    messageArray.append(message);

    socket.write(messageArray);
    socket.close();
}

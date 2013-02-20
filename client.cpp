#include <QHostAddress>
#include <QString>
#include <QTcpSocket>
#include <QByteArray>

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
    QHostAddress addr(address);
    socket.connectToHost(addr, port);
}

bool Client::isOpen()
{
    return socket.isOpen();
}

void Client::startTransfer()
{
    QByteArray messageArray;
    messageArray.append(message);

    socket.write(messageArray);
    socket.close();
}

#ifndef CLIENT_H
#define CLIENT_H

// client.h
#include <QObject>
#include <QTcpSocket>
class QTcpSocket;
class QString;

class Client: public QObject
{
Q_OBJECT
public:
    Client(QString message, QObject *parent = 0);
    ~Client();
    void start(QString address, quint16 port);
    bool isOpen();
public slots:
    void startTransfer();
private:
    QTcpSocket socket;
    QString message;
};


#endif // CLIENT_H

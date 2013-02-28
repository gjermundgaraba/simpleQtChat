#ifndef CLIENT_H
#define CLIENT_H


#include <QObject>
#include <QTcpSocket>

class QTcpSocket;
class QString;

class Client: public QObject
{
Q_OBJECT
public:
    Client(QObject *parent = 0);
    ~Client();
public slots:
    void startTransfer(QString message);
    void connectTo(QString address, QString port);
private:
    QTcpSocket socket;
};


#endif // CLIENT_H

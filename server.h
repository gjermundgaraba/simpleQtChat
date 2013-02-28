#ifndef SERVER_H
#define SERVER_H


#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server: public QObject
{
Q_OBJECT
public:
      Server(QString port, QObject * parent = 0);
      ~Server();
public slots:
      void acceptConnection();
      void startRead();
signals:
      void messageRecieved(QString, QString);
private:
      QTcpServer server;
      QTcpSocket *client;
};


#endif

#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include "mainwindow.h"

class Server: public QObject
{
Q_OBJECT
public:
      Server(MainWindow *win, quint16 port, QObject * parent = 0);
      ~Server();
public slots:
      void acceptConnection();
      void startRead();
private:
      QTcpServer server;
      QTcpSocket *client;
      MainWindow *window;
};

#endif

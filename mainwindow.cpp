#include "mainwindow.h"
#include "client.h"

#include <QTextEdit>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <QBoxLayout>

MainWindow::MainWindow()
{
    socket = NULL;
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *testLayout = new QHBoxLayout();
    chatBox = new QTextEdit();
    chatBox->setReadOnly(true);
    input = new QLineEdit();
    submitButton = new QPushButton("Send...");
    connect(submitButton, SIGNAL(clicked()),
            this, SLOT(sendMessage()));
    ipField = new QLineEdit("IP Address");
    portField = new QLineEdit("Port number");

    setWindowTitle("Qt Peer-To-Peer Chat");

    testLayout->addWidget(ipField);
    testLayout->addWidget(portField);

    mainLayout->addLayout(testLayout);
    mainLayout->addWidget(chatBox);
    mainLayout->addWidget(input);
    mainLayout->addWidget(submitButton);

    setLayout(mainLayout);
}

void MainWindow::sendMessage()
{
    QString address(ipField->text());
    quint16 port = portField->text().toShort();
    QString message(input->text());
    if (socket == NULL || !socket->isOpen())
    {
        delete socket;
        socket = new Client(message);
        socket->start(address, port);
        chatBox->append("Me: " + message);
    }
}

void MainWindow::displayNewMessage(QString* message, QString* sender) {
    QString msg("<b>" + *sender + "</b> ");
    msg.append(message);
    chatBox->append(msg);
}

MainWindow::~MainWindow()
{

}

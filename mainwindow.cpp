#include "mainwindow.h"
#include "client.h"

#include <QTextEdit>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <QBoxLayout>

MainWindow::MainWindow()
{
    chatBox = new QTextEdit();
    chatBox->setReadOnly(true);

    input = new QLineEdit();
    connect(input, SIGNAL(returnPressed()), this, SLOT(sendMessage()));

    submitButton = new QPushButton("Send...");
    connect(submitButton, SIGNAL(clicked()),
            this, SLOT(sendMessage()));

    ipField = new QLineEdit("127.0.0.1");
    connect(ipField, SIGNAL(textChanged(QString)), this, SLOT(connectionChange()));

    portField = new QLineEdit("12349");
    connect(portField, SIGNAL(textChanged(QString)), this, SLOT(connectionChange()));

    setWindowTitle("simpleQtChat");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *testLayout = new QHBoxLayout();

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
    QString message(input->text());
    emit sendMessage(message);
    chatBox->append("Me: " + message);
}

void MainWindow::displayNewMessage(QString message, QString sender) {
    QString msg("<b>" + sender + ":</b> ");
    msg.append(message);
    chatBox->append(msg);
}

void MainWindow::connectionChange() {
    emit connectToChanged(ipField->text(), portField->text());
}

MainWindow::~MainWindow()
{

}

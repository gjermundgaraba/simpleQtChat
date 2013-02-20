#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QTextEdit;
class QString;
class QLineEdit;
class QPushButton;
class Client;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();

    void displayNewMessage(QString*);
private slots:
    void sendMessage();
private:
    QTextEdit *chatBox;
    QLineEdit *input;
    QPushButton *submitButton;

    QLineEdit *ipField;
    QLineEdit *portField;

    Client *socket;
};

#endif // MAINWINDOW_H

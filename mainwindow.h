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
signals:
    void sendMessage(QString message);
    void connectToChanged(QString address, QString port);
private slots:
    void sendMessage();
    void displayNewMessage(QString message, QString sender);
    void connectionChange();
private:
    QTextEdit *chatBox;
    QLineEdit *input;
    QPushButton *submitButton;

    // This will be better later, for now its just easier this way:
    QLineEdit *ipField;
    QLineEdit *portField;
};


#endif // MAINWINDOW_H

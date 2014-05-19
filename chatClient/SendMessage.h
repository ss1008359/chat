#ifndef THSEND_H
#define THSEND_H

#include <QThread>
#include "ClientSocket.h"
#include "ChatException.h"
#include <QLineEdit>
#include <QString>

class SendMessage: public QThread {
Q_OBJECT
public:
    QLineEdit *info;
    ClientSocket cli;
    QString name;
public:
    void init() throw (ChatException);
public slots:
    void toSend();
};

#endif // THSEND_H

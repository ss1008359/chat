#ifndef THSEND_H
#define THSEND_H

#include <QThread>
#include "ClientSocket.h"
#include "ChatException.h"
#include "ConnectData.h"
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
    void toMsgName();
    void toMsgUser();
    void toMsgPort();
public slots:
    void toMsgChat();
private:
    void toSend(int msgTpye);
};

#endif // THSEND_H

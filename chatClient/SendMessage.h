#ifndef THSEND_H
#define THSEND_H

#include <QThread>
#include "ClientSocket.h"
#include "ChatException.h"
#include "ConnectData.h"
#include "LoginData.h"
#include <QLineEdit>
#include <QString>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class SendMessage: public QThread {
Q_OBJECT
public:
    QLineEdit *info;
    ClientSocket cli;
    QString name;
private:
    loginData data;
public:
    void init() throw (ChatException);
    void toMsgOppositeUser(loginData*);
    void toMsgName();
    void toMsgUser();
    void toMsgPort();
public slots:
    void toMsgChat();
private:
    void toSend(int msgTpye);
};

#endif // THSEND_H

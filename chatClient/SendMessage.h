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
    struct sockaddr_in ownaddr;
private:
    struct sockaddr_in oppositeaddr;
    struct sockaddr_in realaddr;
    bool result;
    loginData data;
public:
    void init() throw (ChatException);
    void toMsgUser();
    void toMsgName();
    void toMsgPort();
    void toMsgRequestUser(loginData*);
    void toMsgResponseUser(bool, struct sockaddr_in, struct sockaddr_in);
    void toMsgOppositeUser(loginData*);
public slots:
    void toMsgChat();
private:
    void toSend(int msgTpye);
};

#endif // THSEND_H

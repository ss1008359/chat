#ifndef THRECV_H
#define THRECV_H

#include <QThread>
#include "ClientSocket.h"
#include "ChatException.h"
#include "ConnectData.h"
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class ThRecv: public QThread {
Q_OBJECT
public:
    ClientSocket cli;
    struct sockaddr_in localAddr;
    struct sockaddr_in ownAddr;
    void init() throw (ChatException);
    void run();
public: signals:
    void sigInfo(const QString &);
    void request(struct sockaddr_in*);
    void response(struct sockaddr_in*);
};

#endif // THRECV_H

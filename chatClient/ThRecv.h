#ifndef THRECV_H
#define THRECV_H

#include <QThread>
#include "ClientSocket.h"
#include "ChatException.h"
#include "ConnectData.h"

class ThRecv: public QThread {
Q_OBJECT
public:
    ClientSocket cli;
    struct sockaddr_in localAddr;
    void init() throw (ChatException);
    void run();
public: signals:
    void sigInfo(const QString &);
};

#endif // THRECV_H

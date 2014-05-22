#ifndef THPRIVATERECV_H
#define THPRIVATERECV_H

#include <QThread>
#include "ChatException.h"
#include "PrivateConnectData.h"
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>

class ThPrivateRecv: public QThread {
Q_OBJECT
public:
    int fd;
    void init() throw (ChatException);
    void run();
public: signals:
    void sigInfo(const QString &);
};

#endif // THPRIVATERECV_H

#ifndef PRIVATECLIENTSOCKET_H
#define PRIVATECLIENTSOCKET_H

#include "ChatException.h"
#include <QObject>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class PrivateClientSocket : public QObject {
Q_OBJECT
public:
    int fd;
    struct sockaddr_in addr;

    void initSocket() throw (ChatException);	//客户端初始化
};

#endif // PRIVATECLIENTSOCKET_H

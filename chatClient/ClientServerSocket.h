#ifndef CLIENTSERVERSOCKET_H
#define CLIENTSERVERSOCKET_H

#include "ChatException.h"
#include <QObject>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class ClientServerSocket : public QObject {
Q_OBJECT
public:
    int fd;
    struct sockaddr_in addr;

    void initSocket() throw (ChatException);	//服务器初始化
    int accept() throw (ChatException);		//接收客户连接
};

#endif // CLIENTSERVERSOCKET_H

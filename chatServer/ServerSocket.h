#ifndef SERVER_SOCKET_H
#define SERVER_SCOKET_H

#include "ChatException.h"
#include <QObject>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class ServerSocket : public QObject {
Q_OBJECT
public:
	int fd;
	char ip[30];
	int port;
	
	void initSocket() throw (ChatException);	//服务器初始化
    int accept(struct sockaddr_in*, int*) throw (ChatException);		//接收客户连接
};

#endif

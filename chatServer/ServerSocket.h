#ifndef SERVER_SOCKET_H
#define SERVER_SCOKET_H

#include "ChatException.h"
#include <QObject>

class ServerSocket : public QObject {
Q_OBJECT
public:
	int fd;
	char ip[30];
	int port;
	
	void initSocket() throw (ChatException);	//服务器初始化
	int accept() throw (ChatException);		//接收客户连接
};

#endif

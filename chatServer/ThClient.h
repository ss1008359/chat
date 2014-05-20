#ifndef TH_CLIENT_H
#define TH_CLIENT_H

#include <QThread>
#include <QString>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "ConnectData.h"

class ThClient : public QThread {
Q_OBJECT
public:
	int fd;
    struct sockaddr_in addr;
    int length;
    char name[256];
public:
	void run();		//接收客户收据然后广播
public: signals:
	void sigInfo(const QString&);
};
#endif

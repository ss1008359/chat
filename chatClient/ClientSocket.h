#ifndef CHAT_SOCKET_H
#define CHAT_SOCKET_H

#include "ChatException.h"
#include <QObject>

class ClientSocket : public QObject {
Q_OBJECT
public:
    int fd;
    char ip[30];
    int port;

    void initSocket() throw (ChatException);	//客户端初始化
};

#endif // CHATSOCKET_H

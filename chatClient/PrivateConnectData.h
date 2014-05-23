#ifndef PRIVATECONNECTDATA_H
#define PRIVATECONNECTDATA_H

#include <QString>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

//私聊网络协议
#define MSG_PRIVATE_CHAT                0
#define MSG_PRIVATE_ECHO               1

typedef struct msg_private_data {
    int msgType;
    char msgChat[2048];
}msgPrivateData;

#endif // PRIVATECONNECTDATA_H

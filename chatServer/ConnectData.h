#ifndef CONNECTDATA_H
#define CONNECTDATA_H

#include <QString>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

//聊天网络协议
#define MSG_SHOW_USER                      0
#define MSG_SHOW_CHAT                      1
#define MSG_SHOW_NAME                     2
#define MSG_SHOW_LOCALADDR          3

typedef struct msg_data {
    int msgType;
    char msgChat[2048];
    char msgName[256];
    struct sockaddr_in localAddr;
}msgData;

#endif // CONNECTDATA_H

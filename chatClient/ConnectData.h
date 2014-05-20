#ifndef CONNECTDATA_H
#define CONNECTDATA_H

#include <QString>

//聊天网络协议
#define MSG_SHOW_USER       0
#define MSG_SHOW_CHAT       1
#define MSG_SHOW_NAME      2

typedef struct msg_data {
    int msgType;
    char msgChat[2048];
    char msgName[256];
}msgData;

#endif // CONNECTDATA_H

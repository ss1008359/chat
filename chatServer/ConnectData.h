#ifndef CONNECTDATA_H
#define CONNECTDATA_H

#include <QString>

//聊天网络协议
#define MSG_SHOW_USER   0
#define MSG_SHOW_CHAT   1

typedef struct msg_data {
    int msgType;
    char msgChat[2048];
}msgData;

#endif // CONNECTDATA_H
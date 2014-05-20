#include <QDateTime>
#include "ClientWindow.h"
#include "SendMessage.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>
//#include <QString>
//#include <iostream>

using namespace std;

void SendMessage::init() throw(ChatException)
{
    //client = cli;
    /*
    sprintf(client.ip, "%s", "192.168.1.116");
    client.port = 8888;
    try {
        client.initSocket();
    }
    catch(ChatException e) {
        throw e;
    }
    */
}

void SendMessage::toMsgChat()
{
    toSend(MSG_SHOW_CHAT);
}

void SendMessage::toSend(int msgType)	//发送信息
{
    msgData msg;
    memset(&msg, 0, sizeof(msg));
    switch(msgType) {
        //发送聊天消息
        case MSG_SHOW_CHAT: {
            msg.msgType = msgType;
            //获取系统现在的时间
            QDateTime time = QDateTime::currentDateTime();
            //将文本框内容存入到字符串中
            QString allstr = name + "("
                    + time.toString("yyyy-MM-dd hh:mm:ss ddd") + "):\n" + info->text();
            //    const char  *c_str = allstr.toLocal8Bit();
            const char *buf = allstr.toLocal8Bit();
            memcpy(msg.msgChat, buf, sizeof(msg.msgChat));
            info->clear();
            info->setFocus();
            //    printf("%s", c_str);
        }
            break;

        //显示在线用户
        case MSG_SHOW_USER: {
            msg.msgType = msgType;
        }
            break;

        default:
            break;
    }

    send(cli.fd, &msg, sizeof(msg), 0);

}

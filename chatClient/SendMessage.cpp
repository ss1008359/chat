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

void SendMessage::toMsgUser()
{
    toSend(MSG_SHOW_USER);
}

void SendMessage::toMsgName()
{
    toSend(MSG_SHOW_NAME);
}

void SendMessage::toMsgChat()
{
    toSend(MSG_SHOW_CHAT);
}

void SendMessage::toMsgPort()
{
    toSend(MSG_SHOW_LOCALADDR);
}

void SendMessage::toMsgRequestUser(loginData* data)
{
    this->data.ip = data->ip;
    this->data.port = data->port;
    toSend(MSG_SHOW_REQUESTUSER);
}

void SendMessage::toMsgResponseUser(bool re, struct sockaddr_in opposite, struct sockaddr_in real)
{
//    printf("sendresponse");
    result = re;
    oppositeaddr = opposite;
    realaddr = real;
    toSend(MSG_SHOW_RESPONSEUSER);
}

void SendMessage::toMsgOppositeUser(loginData* data)
{
    this->data.ip = data->ip;
    this->data.port = data->port;
    toSend(MSG_SHOW_PRIVATESERVER);
}

void SendMessage::toSend(int msgType)	//发送信息
{
    msgData msg;
    memset(&msg, 0, sizeof(msg));
//    printf("msg.msgType = %d\n", msgType);
    switch(msgType) {

        //显示在线用户
        case MSG_SHOW_USER: {
            msg.msgType = msgType;
        }
            break;

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

        //将网名传给服务器
        case MSG_SHOW_NAME: {
            msg.msgType = msgType;
            const char *bufName = name.toLocal8Bit();
            memcpy(msg.msgName, bufName, sizeof(msg.msgName));
        }
            break;

        //获得本机端口号
        case MSG_SHOW_LOCALADDR: {
            msg.msgType = msgType;
        }
            break;

        //P2P模式私聊请求连接
        case MSG_SHOW_REQUESTUSER: {
            msg.localAddr = ownaddr;
            msg.oppositeAddr.sin_family = AF_INET;
            msg.oppositeAddr.sin_port = htons(data.port);
            const char *cip = data.ip.toLocal8Bit();
            char ip[30];
            memset(ip, 0, sizeof(ip));
            sprintf(ip, "%s", cip);
            msg.oppositeAddr.sin_addr.s_addr = inet_addr(ip);
            msg.msgType = msgType;
        }
            break;

        //P2P模式私聊回应请求
        case MSG_SHOW_RESPONSEUSER: {
            msg.msgType =msgType;
            msg.oppositeAddr = oppositeaddr;
            if (result) {
                msg.result = result;
                msg.realAddr = realaddr;
            }
            else {
                msg.result = result;
            }
        }
            break;

        //通过服务器给某一用户发送私聊
        case MSG_SHOW_PRIVATESERVER: {
            msg.oppositeAddr.sin_family = AF_INET;
            msg.oppositeAddr.sin_port = htons(data.port);
            const char *cip = data.ip.toLocal8Bit();
            char ip[30];
            memset(ip, 0, sizeof(ip));
            sprintf(ip, "%s", cip);
            msg.oppositeAddr.sin_addr.s_addr = inet_addr(ip);
            msg.msgType = msgType;
            //获取系统现在的时间
            QDateTime time = QDateTime::currentDateTime();
            //将文本框内容存入到字符串中
            QString allstr = "*********************\n" + name + "("
                    + time.toString("yyyy-MM-dd hh:mm:ss ddd") + "):\n" + info->text()
                    + "\n" + "*********************";
            //    const char  *c_str = allstr.toLocal8Bit();
            const char *buf = allstr.toLocal8Bit();
            memcpy(msg.msgChat, buf, sizeof(msg.msgChat));
            info->clear();
            info->setFocus();
        }
            break;

        default:
            break;
    }

    send(cli.fd, &msg, sizeof(msg), 0);

}

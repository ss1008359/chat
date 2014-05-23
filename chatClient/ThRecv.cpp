#include "ThRecv.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sys/socket.h>

using namespace std;

void ThRecv::init() throw(ChatException)
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

void ThRecv::run()
{
    msgData msg;
    memset(&msg, 0, sizeof(msg));
    int r = 0;
    bool stop = false;
    while (!stop) {
        try {
            r = recv(cli.fd, &msg, sizeof(msg), 0);
            if (r < 0) {
                throw ChatException("recv错误");
                //stop = true;
            }
            else if (r == 0) {
                throw ChatException("对端socket已经正常关闭");
                //stop = true;
            }
            else {
                switch(msg.msgType) {
                    case MSG_SHOW_USER:
                        break;

                    case MSG_SHOW_CHAT: {
                        char buf[2048];
                        memset(buf, 0, sizeof(buf));
                        memcpy(buf, msg.msgChat, sizeof(buf) - 1);
                        emit sigInfo(tr(buf));
                    }
                        break;

                    case MSG_SHOW_NAME:
                        break;

                    case MSG_SHOW_LOCALADDR: {
                        localAddr = msg.localAddr;
//                        printf("localport=%d", ntohs(localAddr.sin_port));
                    }
                        break;

                    case MSG_SHOW_REQUESTUSER: {
                        ownAddr = msg.oppositeAddr;
                        emit request(&msg.localAddr);
                    }
                        break;

                    case MSG_SHOW_RESPONSEUSER: {
//                    printf("recvresponse\n");
//                    printf("port = %d\n", ntohs(msg.realAddr.sin_port));
                        if (msg.result) {
//                            char ad[20];
//                            char numPort[20];
//                            memset(ad, 0, sizeof(ad));
//                            memset(numPort, 0, sizeof(numPort));
//                            inet_ntop(AF_INET, &msg.realAddr.sin_addr, ad, sizeof(ad));
//                            printf("ip = %s", ad);
//                            int port = ntohs(msg.realAddr.sin_port);
//                            sprintf(numPort, "%d", port);
//                            QString name = msg.msgName;
//                            QString realStr = name + "(" + ad + ":" + numPort + ")";
//                            string s = realStr.toStdString();
//                            const char *str = s.c_str();
//                            emit sigInfo(tr(str));
                            emit response(&msg.realAddr);
                        }
                        else {
                            emit sigInfo(tr("对方拒绝私聊"));
                        }
                    }
                        break;

                    case MSG_SHOW_PRIVATESERVER: {
                        char buf[2048];
                        memset(buf, 0, sizeof(buf));
                        memcpy(buf, msg.msgChat, sizeof(buf) - 1);
                        emit sigInfo(tr(buf));
                    }
                        break;
                    default:
                        break;
                }
            }
        }
        catch(ChatException e) {
            //发送信号
            emit sigInfo(tr(e.what()));
            stop = true;
        }
    }
}

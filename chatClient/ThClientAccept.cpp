#include "ThClientAccept.h"

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "ThClientAccept.h"
//#include "ThClient.h"

using namespace std;

void ThClientAccept::init() throw(ChatException)
{/*
    const char *ip = strip.toLocal8Bit();
    sprintf(server.ip, "%s", ip);
    //sprintf(server.ip, "%s", "192.168.1.102");
    server.port = 8888;*/
    try {
        server.initSocket();
    }
    catch(ChatException e) {
        throw e;
    }
}

void ThClientAccept::run()	//在线程中接收客户连接
{/*
    bool stop = false;
    while (!stop) {
        try {
            struct sockaddr_in addr;
            int length = sizeof(addr);
            memset(&addr, 0, sizeof(addr));
            int fd = server.accept(&addr, &length);
            //发送信号
            emit sigInfo(tr("有人连接"));
            //建立子线程监听对应的客户
            ThClient *th = new ThClient;
            th->fd = fd;
            th->addr = addr;
            th->length = length;

//            char ad[20];
//            memset(&ad, 0, sizeof(ad));
//            inet_ntop(AF_INET, &th->addr.sin_addr, ad, sizeof(ad));
//            emit sigInfo(tr(ad));

            ServerWindows::allUsers.push_back(th);
            connect(th, SIGNAL(sigInfo(const QString&)),
                this->info, SLOT(append(const QString&)));
            th->start();
        }
        catch(ChatException e) {
            //发送信号
            emit sigInfo(tr("服务器崩溃"));
            stop = true;
        }
    }*/
}

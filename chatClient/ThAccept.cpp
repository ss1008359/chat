#include "ThAccept.h"
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

void ThAccept::init() throw(ChatException)
{
    try {
        server.initSocket();
    }
    catch(ChatException e) {
        throw e;
    }
}

void ThAccept::run()	//在线程中接收客户连接
{
    bool stop = false;
    while (!stop) {
        try {
            int fd = server.accept();
            privateSendMessage.edtmsg = edtmsg;
            //privateSendMessage.edtinfo = edtinfo;
            privateSendMessage.name = strName;
            privateSendMessage.fd = fd;
            thPrivateRecv.init();
            thPrivateRecv.fd = fd;
            connect(&thPrivateRecv, SIGNAL(sigInfo(const QString&)),
                    edtinfo, SLOT(append(const QString&)));
            connect(&privateSendMessage, SIGNAL(sigInfo(const QString&)),
                    edtinfo, SLOT(append(const QString&)));
            thPrivateRecv.start();
            emit sigInfo(tr("接受信息线程启动"));
            emit sigInfo("=============================");
        }
        catch(ChatException e) {
            //发送信号
            emit sigInfo(tr("服务器崩溃"));
            stop = true;
        }
    }
}

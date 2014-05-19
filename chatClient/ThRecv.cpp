#include "ThRecv.h"
#include <cstdio>
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
    char buf[256];
    int r = 0;
    bool stop = false;
    while (!stop) {
        try {
            r = recv(cli.fd, buf, 255, 0);
            if (r < 0) {
                throw ChatException("recv错误");
                //stop = true;
            }
            else if (r == 0) {
                throw ChatException("对端socket已经正常关闭");
                //stop = true;
            }
            else {
                buf[r] = 0;
                emit sigInfo(tr(buf));
            }
        }
        catch(ChatException e) {
            //发送信号
            emit sigInfo(tr(e.what()));
            stop = true;
        }
    }
}

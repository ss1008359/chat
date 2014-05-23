#include "ThPrivateRecv.h"

void ThPrivateRecv::init() throw(ChatException)
{

}

void ThPrivateRecv::run()
{
    msgPrivateData msg;
    memset(&msg, 0, sizeof(msg));
    int r = 0;
    bool stop = false;
    while (!stop) {
        try {
            r = recv(fd, &msg, sizeof(msg), 0);
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

                    case MSG_PRIVATE_CHAT: {
                        char buf[2048];
                        memset(buf, 0, sizeof(buf));
                        memcpy(buf, msg.msgChat, sizeof(buf) - 1);
                        emit sigInfo(tr(buf));
                        msg.msgType = MSG_PRIVATE_ECHO;
                        send(fd, &msg, sizeof(msg), 0);
                    }
                        break;

                    case MSG_PRIVATE_ECHO: {
                        char buf[2048];
                        memset(buf, 0, sizeof(buf));
                        memcpy(buf, msg.msgChat, sizeof(buf) - 1);
                        emit sigInfo(tr(buf));
                    }
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

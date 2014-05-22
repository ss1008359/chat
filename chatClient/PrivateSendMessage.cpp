#include "PrivateSendMessage.h"
#include <QDateTime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/socket.h>

void PrivateSendMessage::init() throw(ChatException)
{

}

void PrivateSendMessage::toMsgChat()
{
    toSend(MSG_PRIVATE_CHAT);
}

void PrivateSendMessage::toSend(int msgType)
{
    msgPrivateData msg;
    memset(&msg, 0, sizeof(msg));

    switch(msgType) {
        case MSG_PRIVATE_CHAT: {
            msg.msgType = msgType;
            //获取系统现在的时间
            QDateTime time = QDateTime::currentDateTime();
            //将文本框内容存入到字符串中
            QString allstr = name + "("
                    + time.toString("yyyy-MM-dd hh:mm:ss ddd") + "):\n" + edtmsg->text();
            //    const char  *c_str = allstr.toLocal8Bit();
            const char *buf = allstr.toLocal8Bit();
            emit sigInfo(tr(buf));
            memcpy(msg.msgChat, buf, sizeof(msg.msgChat));
            edtmsg->clear();
            edtmsg->setFocus();
        }
            break;

        default:
            break;
    }

    send(fd, &msg, sizeof(msg), 0);
}

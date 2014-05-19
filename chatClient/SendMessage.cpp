#include <QDateTime>
#include "ClientWindow.h"
#include "SendMessage.h"
#include <cstdio>
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

void SendMessage::toSend()	//发送信息
{
    //获取系统现在的时间
    QDateTime time = QDateTime::currentDateTime();
    //将文本框内容存入到字符串中
    QString allstr = name + "("
            + time.toString("yyyy-MM-dd hh:mm:ss ddd") + "):\n" + info->text();
    const char  *c_str = allstr.toLocal8Bit();
    send(cli.fd, c_str, strlen(c_str), 0);
    info->clear();
    info->setFocus();

//    printf("%s", c_str);
}

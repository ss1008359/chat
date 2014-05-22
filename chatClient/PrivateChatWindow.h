#ifndef PRIVATECHATWINDOW_H
#define PRIVATECHATWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QKeyEvent>
#include <QString>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdio>
#include "PrivateConnectData.h"
#include "PrivateSendMessage.h"
#include "ThPrivateRecv.h"
#include "PrivateClientSocket.h"
#include "LoginData.h"

class PrivateChatWindow : public QMainWindow
{
Q_OBJECT
private:
    QWidget *center;
    QTextEdit *edtinfo;
    QLineEdit *edtmsg;
    QPushButton *btnsend;
    QHBoxLayout *hlay;
    QVBoxLayout *vlay;
    //菜单栏
    QMenuBar *bar;
    QMenu *chatMenu;
    QAction *actStart;
    QAction *actShowOnlineUser;
    QAction *actPrivateChat;
    QAction *actExit;

    //接受登录信息
    QString strName;

    PrivateClientSocket client;
    PrivateSendMessage  privateSendMessage;
    ThPrivateRecv thPrivateRecv;
public:
    struct sockaddr_in realaddr;
public:
    PrivateChatWindow(QWidget *p=NULL);
    void initClient();
    void setName(QString&);
    void keyPressEvent( QKeyEvent * e );
//    QString getName(void);
public slots:
//    void onStart();
//    void onShowUesr();
//    void onPrivateChat();
//    void onExit();
//    void setMessage(loginData*);
};

#endif // PRIVATECHATWINDOW_H

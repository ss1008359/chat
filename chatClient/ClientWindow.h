#ifndef CLIENT_WINDOW_H
#define CLIENT_WINDOW_H

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
#include "SendMessage.h"
#include "ThRecv.h"
#include "ClientSocket.h"
#include "LoginData.h"
#include "ConnectData.h"
#include "ThPrivateChat.h"
#include "PrivateChatWindow.h"
#include "IpAddress.h"
#include "PrivateIpAddress.h"
#include "ClientServerSocket.h"
#include "ThClientAccept.h"
#include "LoginData.h"

class ClientWindow : public QMainWindow
{
Q_OBJECT
private:
    QWidget *center;
    QTextEdit *edtinfo;
	QLineEdit *edtmsg;
	QPushButton *btnsend;
    QPushButton *btnprivatesend;
	QHBoxLayout *hlay;
	QVBoxLayout *vlay;
    //菜单栏
    QMenuBar *bar;
    QMenu *chatMenu;
    QAction *actStart;
    QAction *actShowOnlineUser;
    QAction *actPrivateChat;
    QAction *actClientServer;
    QAction *actExit;

    //接受登录信息
    QString strName;
    QString strIp;

    struct sockaddr_in localAddr;

    loginData data;
    ClientSocket client;
    SendMessage  sendMessage;
    ThRecv thRecv;
    ThClientAccept thClientAccept;
//    ThPrivateChat thPrivateChat;
    IpAddressWidget *ipaw;
    PrivateIpAddressWidget *pipaw;
    PrivateChatWindow *prw;
public:
	ClientWindow(QWidget *p=NULL);
    void keyPressEvent( QKeyEvent * e );
    QString getName(void);
public slots:
    void oppositeUser();
    void onStart();
    void onShowUesr();
    void onPrivateChat();
    void onClientServer();
    void onExit();
    void setMessage(loginData*);
};

#endif

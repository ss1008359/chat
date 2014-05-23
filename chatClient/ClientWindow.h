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
#include "PrivateChatWindow.h"
#include "PrivateServerWindow.h"
#include "IpAddress.h"
#include "PrivateIpAddress.h"
#include "ClientServerSocket.h"
#include "LoginData.h"
#include "JudgeDialog.h"

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
    QAction *actRealIp;
    QAction *actExit;

    //接受登录信息
    QString strName;
    QString strIp;

    struct sockaddr_in localAddr;

    loginData data;
    ClientSocket client;
    SendMessage  sendMessage;
    ThRecv thRecv;
    JudgeDialog *jd;
    IpAddressWidget *ipaw;
    PrivateIpAddressWidget *getrealip;
    PrivateIpAddressWidget *pipaw;
    PrivateChatWindow *prw;
    PrivateServerWindow *psw;
public:
	ClientWindow(QWidget *p=NULL);
    void keyPressEvent( QKeyEvent * e );
    QString getName(void);
public slots:
    void oppositeUser();
    void onStart();
    void onShowUesr();
    void onPrivateChat(struct sockaddr_in*);
    void onRealIp();
    void onExit();
    void setMessage(loginData*);
    void bulidServer(struct sockaddr_in*);
};

#endif

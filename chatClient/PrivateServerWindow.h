#ifndef PRIVATESERVERWINDOW_H
#define PRIVATESERVERWINDOW_H

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
#include <Qt>
#include <QMessageBox>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstdio>
#include "ChatException.h"
#include "PrivateSendMessage.h"
#include "ThPrivateRecv.h"
#include "ThAccept.h"

class PrivateServerWindow : public QMainWindow
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

public:
    //接受登录信息
    QString strName;
    struct sockaddr_in ownAddr;
//    QString strIp;
    static int port;

    bool result;
    int fd;
    ThAccept thAccept;
    ThPrivateRecv thPrivateRecv;
public:
    PrivateServerWindow(QWidget *p=NULL);
    void buildServer();
    void keyPressEvent( QKeyEvent * e );
public slots:
    void getResult(bool);
//    void onStart();
//    void onShowUesr();
//    void onPrivateChat();
//    void onExit();
//    void setMessage(loginData*);
};

#endif // PRIVATESERVERWINDOW_H

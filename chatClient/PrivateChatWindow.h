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
    QString strIp;
    int port;

//    ClientSocket client;
//    SendMessage  sendMessage;
//    ThRecv thRecv;
public:
    PrivateChatWindow(QWidget *p=NULL);
    void setName(QString&);
//    void keyPressEvent( QKeyEvent * e );
//    QString getName(void);
public slots:
//    void onStart();
//    void onShowUesr();
//    void onPrivateChat();
//    void onExit();
    void setMessage(loginData*);
};

#endif // PRIVATECHATWINDOW_H

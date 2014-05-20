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

class ClientWindow : public QMainWindow
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
    QAction *actExit;

    //接受登录信息
    QString strName;
    QString strIp;

    ClientSocket client;
    SendMessage  sendMessage;
    ThRecv thRecv;
public:
	ClientWindow(QWidget *p=NULL);
    void keyPressEvent( QKeyEvent * e );
    QString getName(void);
public slots:
    void onStart();
    void onExit();
    void setMessage(loginData*);

};
#endif

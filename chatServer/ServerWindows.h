#ifndef SERVER_WINDOWS_H
#define SERVER_WINDOWS_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QTextCodec>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QStatusBar>
#include <QLabel>
#include "ThAccept.h"
#include <list>
#include "ThClient.h"

using namespace std;

class ServerWindows : public QMainWindow {
Q_OBJECT
public:
	static list<ThClient*> allUsers;
private:
	QTextEdit *info;
	//菜单栏
	QMenuBar *bar;
	QMenu *serverMenu;
	QAction *actStart;
	QAction *actExit;
	//状态栏
	QStatusBar *status;
	QLabel *lbltip;
	QLabel *lblresult;
	QLabel *lbltime;

    ThAccept thAccept;
public:
	ServerWindows(QWidget *parent = NULL);
public slots:
	void onStart();
	void onExit();
};

#endif

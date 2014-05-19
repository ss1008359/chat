#include "ServerWindows.h"
#include <QColor>
#include <QMessageBox>
#include <QCoreApplication>
#include "ChatException.h"

list<ThClient*> ServerWindows::allUsers;

void ServerWindows::onStart()
{
//	QMessageBox::information(this, tr("提示"), tr("响应"));
    if(thAccept.info != info) {
        try {
            thAccept.init();
            thAccept.info = info;
            info->setTextColor(QColor(0, 255, 0));
            info->append(tr("服务器启动成功!"));
            connect(&thAccept, SIGNAL(sigInfo(const QString&)),
                    info, SLOT(append(const QString&)));
            thAccept.start();
            info->append(tr("服务器接收线程启动"));
        }
        catch (ChatException e) {
            info->setTextColor(QColor(255, 0, 0));
            info->append(tr(e.what()));
        }
    }
    else {
        info->append(tr("服务器已启动"));
    }
}

void ServerWindows::onExit()
{
	this->close();
}
ServerWindows::ServerWindows(QWidget *parent)
{	
	//初始化界面
	this->resize(800, 600);
    this->move((1366-800)/2, (768-600)/2);
	this->setWindowTitle(tr("聊天服务器"));
	//初始化文本框
	info = new QTextEdit;
	info->setTextColor(QColor(255, 0, 0));
    info->append(tr("欢迎使用服务器程序"));
	info->append(tr("================"));
	info->setTextColor(QColor(0, 0, 0));
	info->setFontPointSize(20);
	info->append(tr("字体怎样？"));
    info->setReadOnly(true);
	this->setCentralWidget(info);
	//初始化菜单
	bar = new QMenuBar(this);
	serverMenu = new QMenu(tr("服务器"), bar);
	actStart = new QAction(tr("启动"), serverMenu);
	actExit = new QAction(tr("结束"), serverMenu);

	serverMenu->addAction(actStart);
	serverMenu->addSeparator();
	serverMenu->addAction(actExit);
	
	bar->addMenu(serverMenu);
	this->setMenuBar(bar);
	//初始化状态栏
	status = new QStatusBar(this);
	lbltip = new QLabel(tr("提示"), status);
	lblresult = new QLabel(tr("操作结果显示"), status);
    lbltime = new QLabel("2014-5-2", status);
	status->addPermanentWidget(lbltip, 300);
	status->addPermanentWidget(lblresult, 500);
	status->addPermanentWidget(lbltime, 0);
    this->setStatusBar(status);

	connect(actStart, SIGNAL(triggered()),
			this, SLOT(onStart()));
	connect(actExit, SIGNAL(triggered()),
			this, SLOT(onExit()));
    //this->setVisible(true);
}

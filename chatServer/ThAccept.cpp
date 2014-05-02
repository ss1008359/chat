#include "ThAccept.h"
#include <cstdio>
#include "ThClient.h"
#include "ServerWindows.h"

using namespace std;

void ThAccept::init() throw(ChatException)
{
	sprintf(server.ip, "%s", "192.168.1.116");
	server.port = 8888;
	try {
		server.initSocket();
	}
	catch(ChatException e) {
		throw e;
	}
}

void ThAccept::run()	//在线程中接收客户连接
{
	while (true) {
		try {
			int fd = server.accept();
			//发送信号
			emit sigInfo(tr("有人连接"));
			//建立子线程监听对应的客户
			ThClient *th = new ThClient;
			th->fd = fd;
			ServerWindows::allUsers.push_back(th);
			connect(th, SIGNAL(sigInfo(const QString&)),
				this->info, SLOT(append(const QString&)));
			th->start();
		}
		catch(ChatException e) {
			//发送信号
			emit sigInfo(tr("服务器崩溃"));
		}
	}
}

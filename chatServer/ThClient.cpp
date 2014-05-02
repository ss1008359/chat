#include "ThClient.h"
#include <unistd.h>
#include <sys/socket.h>
#include <cstring>
#include <list>
#include "ServerWindows.h"

using namespace std;

void ThClient::run()
{
	char buf[1024];
	int r;

	while (true) {
		r = recv(fd, buf, sizeof(buf)-1, 0);
		if (r <= 0) {
			emit sigInfo(tr("客户退出"));
			ServerWindows::allUsers.remove(this);
			close(fd);
			break;
		}
		buf[r] = '\0';
		//发送消息，把接收数据显示到服务器主窗体
		emit sigInfo(tr(buf));
		//广播
		list<ThClient*>::iterator iter = 
				ServerWindows::allUsers.begin();
		while (iter != ServerWindows::allUsers.end()) {
			send((*iter)->fd, buf, strlen(buf), 0);
			++iter;
		}
	}
}

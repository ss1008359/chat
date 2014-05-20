#include "ThClient.h"
#include <unistd.h>
#include <sys/socket.h>
#include <cstring>
#include <cstdlib>
#include <list>
#include <QString>
#include "ServerWindows.h"

using namespace std;

void ThClient::run()
{
	int r;
    msgData msg;

	while (true) {
        memset(&msg, 0, sizeof(msg));
        r = recv(fd, &msg, sizeof(msg), 0);
		if (r <= 0) {
			emit sigInfo(tr("客户退出"));
			ServerWindows::allUsers.remove(this);
			close(fd);
			break;
		}
        switch(msg.msgType) {

            case MSG_SHOW_USER: {
                msgData msgOlineUser;
                memset(&msgOlineUser, 0, sizeof(msgOlineUser));
                msgOlineUser.msgType = msg.msgType;
                QString alluser;
                list<ThClient*>::iterator iter =
                        ServerWindows::allUsers.begin();
                while (iter != ServerWindows::allUsers.end()) {
                    char ad[20];
                    memset(ad, 0, sizeof(ad));
                   // addr = (*iter)->addr;
                    inet_ntop(AF_INET, &(*iter)->addr.sin_addr, ad, sizeof(ad));
                    alluser += (*iter)->name;
                    alluser += "(";
                    alluser += ad;
                    alluser += ")\n";
                    ++iter;
                }
                const char *all = alluser.toLocal8Bit();
                memcpy(&msgOlineUser.msgChat, all, sizeof(msgOlineUser.msgChat));
                send(fd, &msgOlineUser, sizeof(msgOlineUser), 0);
            }
                break;

            case MSG_SHOW_CHAT: {
                //发送消息，把接收数据显示到服务器主窗体
                char buf[2048];
                memset(buf, 0, sizeof(buf));
                memcpy(buf, msg.msgChat, sizeof(buf) - 1);
                emit sigInfo(tr(buf));
                //广播
                list<ThClient*>::iterator iter =
                        ServerWindows::allUsers.begin();
                while (iter != ServerWindows::allUsers.end()) {
                    send((*iter)->fd, &msg, sizeof(msg), 0);
                    ++iter;
                }
            }
                break;

            case MSG_SHOW_NAME: {
                list<ThClient*>::iterator iter =
                        ServerWindows::allUsers.begin();
                while (iter != ServerWindows::allUsers.end()) {
                    if (fd == (*iter)->fd) {
                        memcpy((*iter)->name, msg.msgName, sizeof((*iter)->name));
                        //(*iter)->name = msg.msgName;
                    }
                    ++iter;
                }
            }
                break;

            default:
                break;
        }
	}
}

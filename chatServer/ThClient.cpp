#include "ThClient.h"
#include <unistd.h>
#include <sys/socket.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <list>
#include <string>
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
                msgOlineUser.msgType = MSG_SHOW_CHAT;
                QString alluser;
                list<ThClient*>::iterator iter =
                        ServerWindows::allUsers.begin();
                while (iter != ServerWindows::allUsers.end()) {
                    char ad[20];
                    char numPort[20];
                    memset(ad, 0, sizeof(ad));
                    memset(numPort, 0, sizeof(numPort));
//                    addr = (*iter)->addr;
                    inet_ntop(AF_INET, &(*iter)->addr.sin_addr, ad, sizeof(ad));
                    int port = ntohs((*iter)->addr.sin_port);
//                    printf("prot = %d", port);
                    sprintf(numPort, "%d", port);
//                    printf("numPort = %s", numPort);
                    alluser += (*iter)->name + "(" + ad + ":" + numPort + ")" + "\n";
//                    alluser += (*iter)->name;
//                    alluser += "(";
//                    alluser += ad;
//                    alluser += ")\n";
                    ++iter;
                }
//                const char *all = alluser.toLocal8Bit();
                string s = alluser.toStdString();
                const char *all = s.c_str();
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
                        //memcpy((*iter)->name, msg.msgName, sizeof((*iter)->name));
                        (*iter)->name = msg.msgName;
                    }
                    ++iter;
                }
            }
                break;

            case MSG_SHOW_LOCALADDR: {
                list<ThClient*>::iterator iter =
                        ServerWindows::allUsers.begin();
                while (iter != ServerWindows::allUsers.end()) {
                    if (fd == (*iter)->fd) {
                        msg.localAddr = (*iter)->addr;
//                        printf("localport=%d", ntohs(msg.localAddr.sin_port));
//                        printf("iterport=%d", ntohs((*iter)->addr.sin_port));
                        break;
                    }
                    ++iter;
                }

                send(fd, &msg, sizeof(msg), 0);
            }
                break;

            case MSG_SHOW_PRIVATESERVER: {
                //发送消息，把接收数据显示到服务器主窗体
                char buf[2048];
                memset(buf, 0, sizeof(buf));
                memcpy(buf, msg.msgChat, sizeof(buf) - 1);
                emit sigInfo(tr(buf));

                //发送给特定用户
                int cfd = 0;
                list<ThClient*>::iterator iter =
                        ServerWindows::allUsers.begin();
                while (iter != ServerWindows::allUsers.end()) {
                        if (msg.oppositeAddr.sin_port == (*iter)->addr.sin_port) {
                            cfd = (*iter)->fd;
                            break;
                        }
                    ++iter;
                }

                send(fd, &msg, sizeof(msg), 0);
                send(cfd, &msg, sizeof(msg), 0);
            }
                break;

            default:
                break;
        }
	}
}

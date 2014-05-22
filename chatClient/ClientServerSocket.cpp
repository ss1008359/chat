#include "ClientServerSocket.h"
#include <cstdio>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void ClientServerSocket::initSocket() throw (ChatException)
{
    //建立socket
    fd = socket(AF_INET, SOCK_STREAM, 0);
    int r;
    if (fd == -1) {
        throw ChatException("socket错误");
    }
    //绑定ip地址
    r = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    printf("bind = %d", r);
    if (r == -1) {
        close(fd);
        throw ChatException("bind错误");
    }
    //监听
    r = listen(fd, 1);
    if (r == -1) {
        close(fd);
        throw ChatException("listen错误");
    }

}

int ClientServerSocket::accept() throw (ChatException)
{
    //接收客户连接
    int cfd;
    //struct sockaddr_in ad;
    printf("ffd = %d", fd);
    cfd = ::accept(fd, NULL, 0);
    printf("fd = %d", cfd);
    if (cfd == -1) {
        throw ChatException("accept错误");
    }

    return cfd;
}

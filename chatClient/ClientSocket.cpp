#include "ClientSocket.h"
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void ClientSocket::initSocket() throw (ChatException)
{
    //建立socket
    fd = socket(AF_INET, SOCK_STREAM, 0);
    int r;
    if (fd == -1) {
        throw ChatException("socket错误");
    }
    //建立connect
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);

    r = ::connect(fd, (struct sockaddr*)&addr, sizeof(addr));
    if(r==-1) {
        close(fd);
        throw ChatException("connect错误");
    }
}

#include "PrivateClientSocket.h"

void PrivateClientSocket::initSocket() throw (ChatException)
{
    //建立socket
    fd = socket(AF_INET, SOCK_STREAM, 0);
    int r;
    if (fd == -1) {
        throw ChatException("socket错误");
    }
    //建立connect
    r = ::connect(fd, (struct sockaddr*)&addr, sizeof(addr));
    if(r==-1) {
        close(fd);
        throw ChatException("connect错误");
    }
}

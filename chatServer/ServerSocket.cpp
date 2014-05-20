#include "ServerSocket.h"
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

void ServerSocket::initSocket() throw (ChatException)
{
	//建立socket
	fd = socket(AF_INET, SOCK_STREAM, 0);
	int r;
	if (fd == -1) {
		throw ChatException("socket错误");
	}
	//绑定ip地址
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
	r = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
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

int ServerSocket::accept() throw (ChatException)
{
	//接收客户连接
	int cfd;
	cfd = ::accept(fd, NULL, 0);
	if (cfd == -1) {
		throw ChatException("accept错误");
	}

	return cfd;
}

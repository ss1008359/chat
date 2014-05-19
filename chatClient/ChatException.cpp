#include "ChatException.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

ChatException::ChatException()
{
    memset(msg, 0, sizeof(msg));
    sprintf(msg, "聊天异常");
}

ChatException::ChatException(const char *data)
{
    memset(msg, 0, sizeof(msg));
    sprintf(msg, "聊天异常:%s", data);
}

const char* ChatException::what() const throw()
{
    return msg;
}

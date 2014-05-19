#ifndef CHAT_EXCEPTION_H
#define CHAT_EXCEPTION_H

#include <exception>

using namespace std;

class ChatException : public exception {
private:
    char msg[50];

public:
    ChatException();
    ChatException(const char*);
    const char* what() const throw();
};

#endif

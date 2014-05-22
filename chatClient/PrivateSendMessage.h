#ifndef PRIVATESENDMESSAGE_H
#define PRIVATESENDMESSAGE_H

#include <QThread>
#include "ChatException.h"
#include "PrivateConnectData.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QString>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

class PrivateSendMessage: public QThread {
Q_OBJECT
public:
    QLineEdit *edtmsg;
    QTextEdit *edtinfo;
    QString name;
    int fd;
public:
    void init() throw (ChatException);
public: signals:
    void sigInfo(const QString &);
public slots:
    void toMsgChat();
private:
    void toSend(int msgType);
};

#endif // PRIVATESENDMESSAGE_H

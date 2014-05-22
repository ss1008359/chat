#ifndef THACCEPT_H
#define THACCEPT_H

#include <QThread>
#include "ClientServerSocket.h"
#include "PrivateSendMessage.h"
#include "ThPrivateRecv.h"
#include "ChatException.h"
#include <QTextEdit>
#include <QString>

class ThAccept : public QThread {
Q_OBJECT
public:
    QTextEdit *edtinfo;
    QLineEdit *edtmsg;
    QString strName;
//    QString strip;
//private:
    ClientServerSocket server;
    PrivateSendMessage privateSendMessage;
    ThPrivateRecv thPrivateRecv;
public:
    void init() throw (ChatException);
    void run();
public: signals:
    void sigInfo(const QString &);
};

#endif // THACCEPT_H

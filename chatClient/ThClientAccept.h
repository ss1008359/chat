#ifndef THCLIENTACCEPT_H
#define THCLIENTACCEPT_H

#include <QThread>
#include "ClientServerSocket.h"
#include "ChatException.h"
#include <QTextEdit>
#include <QString>

class ThClientAccept : public QThread {
Q_OBJECT
public:
    QTextEdit *info;
    QString strip;
//private:
    ClientServerSocket server;
public:
    void init() throw (ChatException);
    void run();
public: signals:
    void sigInfo(const QString &);
};

#endif // THCLIENTACCEPT_H

#ifndef TH_ACCEPT_H
#define TH_ACCEPT_H

#include <QThread>
#include "ServerSocket.h"
#include "ChatException.h"
#include <QTextEdit>
#include <QString>

class ThAccept : public QThread {
Q_OBJECT
public:
	QTextEdit *info;
    QString strip;
//private:
	ServerSocket server;
public:
	void init() throw (ChatException);
    void run();
public: signals:
	void sigInfo(const QString &);
};

#endif

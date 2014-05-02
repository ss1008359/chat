#ifndef TH_CLIENT_H
#define TH_CLIENT_H

#include <QThread>

class ThClient : public QThread {
Q_OBJECT
public:
	int fd;
public:
	void run();		//接收客户收据然后广播
public: signals:
	void sigInfo(const QString&);
};
#endif

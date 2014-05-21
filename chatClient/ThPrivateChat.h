#ifndef THPRIVATECHAT_H
#define THPRIVATECHAT_H

#include <QThread>
//#include "ClientSocket.h"
//#include "ChatException.h"
//#include "ConnectData.h"

class ThPrivateChat: public QThread {
Q_OBJECT
public:
//    ClientSocket cli;
//    void init() throw (ChatException);
    void run();
//public: signals:
//    void sigInfo(const QString &);
};

#endif // THPRIVATECHAT_H

#ifndef LOGINDATA_H
#define LOGINDATA_H

#include <QString>

//保存登录时的必要信息
typedef struct login_data {
    QString name;
    QString ip;
    int port;
}loginData;

#endif // LOGINDATA_H

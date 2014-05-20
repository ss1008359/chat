#ifndef LOGINDLALOG_H
#define LOGINDLALOG_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QString>
#include "LoginData.h"

class LoginDialog: public QDialog {
Q_OBJECT
public:
    LoginDialog(QWidget *p=NULL);
    QString getIpAddressString();
    void setSeparator(const QString &separator);
signals:
    void strMessage(loginData*);
protected:
    bool eventFilter(QObject *object, QEvent *event);
private:
    QSpinBox *m_SpinBox[4];
    QLabel *m_Label[3];
    QString m_Separator;        //四个数字之间的分隔符

    QLabel *lblname;
    QLabel *lblip;
//    QLabel *lbluser;
//    QLabel *lblpass;
    QLineEdit *letname;
//    QLineEdit *letuser;
//    QLineEdit *letpass;
    QPushButton *btnok;
    QPushButton *btncancel;
   // QString str;

    loginData data;
public slots:
    void loginok();
    void logincancel();
};

#endif // LOGINDLALOG_H

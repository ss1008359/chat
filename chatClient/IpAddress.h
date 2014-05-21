#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <QWidget>
#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "LoginData.h"

class IpAddressWidget : public QDialog
{
    Q_OBJECT
private:
    QSpinBox *m_SpinBox[4];
    QLabel *m_Label[4];
    QLineEdit *m_LineEdit;
    QString m_Separator;        //四个数字之间的分隔符
    QPushButton *btnok;
    loginData data;
protected:
    bool eventFilter(QObject *object, QEvent *event);
public:
    IpAddressWidget(QWidget *parent = 0);
    ~IpAddressWidget();
    QString getIpAddressString();
    void setSeparator(const QString &separator);
signals:
    void strMessage(loginData*);
public slots:
    void okButton();
};

#endif // IPADDRESS_H

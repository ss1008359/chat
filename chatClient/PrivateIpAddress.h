#ifndef PRIVATEIPADDRESS_H
#define PRIVATEIPADDRESS_H

#include <QWidget>
#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "LoginData.h"

class PrivateIpAddressWidget : public QDialog
{
    Q_OBJECT
public:
    loginData data;
private:
    QSpinBox *m_SpinBox[4];
    QLabel *m_Label[4];
    QLineEdit *m_LineEdit;
    QString m_Separator;        //四个数字之间的分隔符
    QPushButton *btnok;
protected:
    bool eventFilter(QObject *object, QEvent *event);
public:
    PrivateIpAddressWidget(QWidget *parent = 0);
    ~PrivateIpAddressWidget();
    QString getIpAddressString();
    void setSeparator(const QString &separator);
public slots:
    void okButton();
};

#endif // PRIVATEIPADDRESS_H
